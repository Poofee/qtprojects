#include "treeviewmodel.h"

#include <QDateTime>
#include <QSize>
#include <QFont>
#include <QColor>
#include <QBrush>

TreeViewModel::TreeViewModel(QObject *parent)
    : QAbstractItemModel (parent)
{
    m_flash_index.clear();
}

int TreeViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_flash_index.count();
}

int TreeViewModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 3;
}

/*!
 \brief 获取role的数据,设置role的数据

 \param index
 \param role
 \return QVariant
*/
QVariant TreeViewModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    int row = index.row();
    int column = index.column();
    FlashIndexData index_data = m_flash_index.at(row);

    switch (role) {
    case Qt::DisplayRole:
        if(column == UNIX_TIME_COLUMN)
            return QDateTime::fromTime_t(index_data.unix_time).toString("yyyy-MM-dd hh:mm:ss");
        else if(column == FLASH_ADDR_COLUMN)
            return index_data.addr;
        return "";
//        break;
    case Qt::CheckStateRole:
        if(column == CHECK_BOX_COLUMN)
            return index_data.is_be_checked ? Qt::Checked : Qt::Unchecked;
        break;
    case Qt::TextAlignmentRole:
        if(column == CHECK_BOX_COLUMN)
            return QVariant(Qt::AlignLeft|Qt::AlignVCenter);
        else
            return Qt::AlignCenter;
//        break;
    case Qt::TextColorRole:
        return QColor(Qt::black);
//        break;
    case Qt::SizeHintRole:
        return QSize(100,30);
//        break;
    case Qt::FontRole:
        return QFont("SimSun", 11);
//        break;
    default:
        break;
    }
    return QVariant();
}

/*!
 \brief 可编辑，只提供可选不可选的编辑,不提供对数据源的编辑

 \param index
 \param value
 \param role
 \return bool
*/
bool TreeViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;
    int column = index.column();
    FlashIndexData index_data = m_flash_index.at(index.row());
    switch (role) {
    case Qt::UserRole:  //根据表头的复选框选择
    case Qt::UserRole+1:    //根据鼠标点击
        if(column == CHECK_BOX_COLUMN)
        {
            index_data.is_be_checked = (((Qt::CheckState)value.toInt()) == Qt::Checked);
            m_flash_index.replace(index.row(),index_data);

            emit dataChanged(index,index);

            if(role == Qt::UserRole+1)  //点击鼠标，更新表头复选框状态
                onStateChanged();

            return true;
        }
        break;
    default:
        return false;
//        break;
    }
    return false;
}

/*!
 \brief 使Item显示复选框

 \param index
 \return Qt::ItemFlags
*/
Qt::ItemFlags TreeViewModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return QAbstractItemModel::flags(index);

    Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemNeverHasChildren;
    if (index.column() == CHECK_BOX_COLUMN)
        flags |= Qt::ItemIsUserCheckable;
    return flags;
}

/*!
 \brief 设置（row,column）的index

 \param row
 \param column
 \param parent
 \return QModelIndex
*/
QModelIndex TreeViewModel::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || column < 0 || column >= columnCount(parent))
        return QModelIndex();

    return createIndex(row,column);
}

/*!
 \brief 只有一层树形结构，parent为空

 \param index
 \return QModelIndex
*/
QModelIndex TreeViewModel::parent(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}

/*!
 \brief 返回表头的一些数据

 \param section
 \param orientation
 \param role
 \return QVariant
*/
QVariant TreeViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        if(section == CHECK_BOX_COLUMN)
        {
            return QString("Select all");
        }else if(section == UNIX_TIME_COLUMN)
        {
            return QString("Time");
        }else if(section == FLASH_ADDR_COLUMN)
        {
            return QString("Address");
        }
        return "";
//        break;
    case Qt::FontRole:
        return QFont("SimSun", 12);
//        break;
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
//        break;
    case Qt::TextColorRole:
        return QColor(Qt::black);
//        break;
    case Qt::SizeHintRole:
        return QSize(100,40);
//        break;
    case Qt::BackgroundRole:
        return QBrush(Qt::black);
//        break;
    default:
        break;
    }
    return QVariant();
}

void TreeViewModel::slot_stateChanged(Qt::CheckState state)
{
   for(int i = 0;i < rowCount();++i)
   {
       setData(index(i,CHECK_BOX_COLUMN),state,Qt::UserRole);
   }
}

void TreeViewModel::onStateChanged()
{
    int select_total = 0;
    for(int i = 0;i < rowCount();++i)
    {
        if(m_flash_index.at(i).is_be_checked)
            ++select_total;
    }

    if(select_total == 0)
    {
        emit stateChanged(Qt::Unchecked);
    }else if(select_total < rowCount())
    {
        emit stateChanged(Qt::PartiallyChecked);
    }else
    {
        emit stateChanged(Qt::Checked);
    }
}

void TreeViewModel::setFlashData(QList<FlashIndexData> &flash_data)
{
    m_flash_index = flash_data;

    beginResetModel();
    endResetModel();

    emit stateChanged(Qt::Unchecked);
}

void TreeViewModel::clear()
{
    m_flash_index.clear();
    beginResetModel();
    endResetModel();

    emit stateChanged(Qt::Unchecked);
}

void TreeViewModel::getSelectedFlashData(QMap<quint32, quint16> &selected_list)
{
    selected_list.clear();
    for(int i = 0;i < rowCount();++i)
    {
        if(m_flash_index.at(i).is_be_checked)
        {
            selected_list.insert(m_flash_index.at(i).unix_time,m_flash_index.at(i).addr);
        }
    }
}
