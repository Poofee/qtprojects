#ifndef FANCYTABWIDGET_H
#define FANCYTABWIDGET_H

#include <QIcon>
#include <QWidget>


class QPainter;
class QStackedLayout;

class FancyTab : public QObject
{
    Q_OBJECT
public:
    FancyTab(QWidget *tabbar)
        :m_tabbar(tabbar)
    {

    }

    QIcon icon;
    QString text;
    bool enabled = true;

private:
    QWidget *m_tabbar;
};

class FancyTabBar : public QWidget
{
    Q_OBJECT

public:
    FancyTabBar(QWidget *parent = nullptr);
protected:
    //event
//    bool event(QEvent * e) override;

    void paintEvent(QPaintEvent *e) override;
    void paintTab(QPainter *painter, int index) const;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void enterEvent(QEvent *e) override;
    void leaveEvent(QEvent *e) override;
public:
    bool validIndex(int index) const {return index >= 0 && index <= m_tabs.count();}

    void setTabEnabled(int index, bool enable);
    bool isTabEnabled(int index) const;

    void setIconsOnly(bool iconOnly);

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    //tab operation
    void insertTab(int index, const QIcon &icon, const QString &label)
    {
        FancyTab *tab = new FancyTab(this);
        tab->icon = icon;
        tab->text = label;

        m_tabs.insert(index,tab);

        if(m_currentIndex >= index)
            ++m_currentIndex;

        m_currentIndex = index;
        emit currentChanged(index);
        updateGeometry();
    }
    void removeTab(int index)
    {
        FancyTab *tab = m_tabs.takeAt(index);
        delete tab;

        updateGeometry();
    }

    void setCurrentIndex(int index){
        if(isTabEnabled(index) && index != m_currentIndex){
            m_currentIndex = index;
            emit currentChanged(m_currentIndex);
        }
    }
    int currentIndex() const{ return m_currentIndex;}
    int count() const {return m_tabs.count();}

    QRect tabRect(int index) const;

signals:
    void currentChanged(int index);
public:
    QList<FancyTab *> m_tabs;

private:

    bool m_iconsOnly = true;
    int m_currentIndex = -1;
    QSize tabSizeHint(bool minimum = false) const;
};

class FancyTabWidget : public QWidget
{
    Q_OBJECT
public:
    FancyTabWidget(QWidget *parent = nullptr);

    void insertTab(int index, QWidget *tab, const QIcon &icon, const QString &label);
    void removeTab(int index);

//    void paintEvent(QPaintEvent *event) override;

    int currentIndex() const;

    void setTabEnabled(int index, bool enable);
    bool isTabEnabled(int index) const;

    void setIconsOnly(bool iconsOnly);

signals:
    void currentAboutToShow(int index);
    void currentChanged(int index);

public slots:
    void setCurrentIndex(int index);

private:
    void showWidget(int index);

private:
    FancyTabBar *m_tabbar;
    QStackedLayout *m_pages;

};

#endif // FANCYTABWIDGET_H
