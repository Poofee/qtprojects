#include "widget.h"
#include "mytab.h"

#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch(1);

    MyTab *tab1 = new MyTab(nullptr,QString(":/icon/mode_Design.png"),QString("Editttttt"));
    MyTab *tab2 = new MyTab(nullptr,QString(":/icon/mode_design_mask.png"),QString("Edit"));
    MyTab *tab3 = new MyTab(nullptr,QString(":/icon/mode_Edit.png"),QString("Edit"));
    MyTab *tab4 = new MyTab(nullptr,QString(":/icon/settingscategory_core.png"),QString("Edit"));
    MyTab *tab5 = new MyTab(nullptr,QString(":/icon/settingscategory_design.png"),QString("Edit"));

    hbox->addWidget(tab1);
    hbox->addWidget(tab2);
    hbox->addWidget(tab3);
    hbox->addWidget(tab4);
    hbox->addWidget(tab5);

    hbox->addStretch(1);

    setLayout(hbox);


}

Widget::~Widget()
{

}
