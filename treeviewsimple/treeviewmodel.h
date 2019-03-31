#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H

#include <QAbstractItemModel>

struct FlashIndexData{
    FlashIndexData():is_be_checked(false){
    }
    bool is_be_checked;
    quint32 unix_time;
    quint16 addr;
};

class TreeViewModel:public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit TreeViewModel(QObject *parent=nullptr);
    void setFlashData(QList<FlashIndexData> &flash_data);
    void clear();
    void getSelectedFlashData(QMap<quint32,quint16> &selected_list);

    virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags(const QModelIndex & index) const;

    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &index) const;

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
signals:
    void stateChanged(Qt::CheckState state);
private slots:
    void slot_stateChanged(Qt::CheckState state);
private:
    QList<FlashIndexData> m_flash_index;    //flash 索引

    void onStateChanged();

    enum{
        CHECK_BOX_COLUMN = 0,
        UNIX_TIME_COLUMN,
        FLASH_ADDR_COLUMN
    };
};
#endif // TREEVIEWMODEL_H
