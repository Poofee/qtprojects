#include "widget.h"

#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QToolButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QDebug>
#include <QTabWidget>
#include <QPushButton>

widget::widget(QWidget *parent) : QDialog(parent)
{
    QTabWidget* tab_material = new QTabWidget(this);
    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(tab_material);
    tab_material->addTab(new QWidget(this),QString(tr("Basic Material")));
    tab_material->addTab(createMagMaterialWidget(),QString(tr("Magnetic Material")));
    tab_material->addTab(new QWidget(this),QString(tr("Heat Material")));
    QHBoxLayout* hbox = new QHBoxLayout;
    QPushButton* pb_OK = new QPushButton();
    pb_OK->setText(tr("OK"));
    QPushButton* pb_Cancel = new QPushButton();
    pb_Cancel->setText(tr("Cancle"));
    hbox->addStretch();
    hbox->addWidget(pb_OK);
    hbox->addWidget(pb_Cancel);
    vbox->addLayout(hbox);

    setLayout(vbox);
}

QWidget *widget::createMagMaterialWidget()
{
    QWidget* w = new QWidget(this);

    QVBoxLayout* mainlayout = new QVBoxLayout;

    /** Name & B-H curve **/
    QFormLayout* formlayout = new QFormLayout;
    QLineEdit* edit_name = new QLineEdit(w);
    QComboBox* combo_bhtype = new QComboBox(w);
    combo_bhtype->addItem(tr("Linear B-H relationship"));
    combo_bhtype->addItem(tr("Nonlinear B-H curve"));

    formlayout->addRow(tr("Name"),edit_name);
    formlayout->addRow(tr("B-H curve"),combo_bhtype);
    formlayout->setLabelAlignment(Qt::AlignLeft);

    mainlayout->addLayout(formlayout);

    /** Linear Material Properties **/
    QGroupBox* gbox_linear = new QGroupBox(w);
    QHBoxLayout* hbox_linear = new QHBoxLayout;
    QLineEdit* edit_ux = new QLineEdit(w);
    QLineEdit* edit_uy = new QLineEdit(w);
    QLineEdit* edit_hx = new QLineEdit(w);
    QLineEdit* edit_hy = new QLineEdit(w);
    QFormLayout* formlayout_linear1 = new QFormLayout;
    formlayout_linear1->addRow(tr("Relative ux:"),edit_ux);
    formlayout_linear1->addRow(tr("Relative hx:"),edit_hx);
    QFormLayout* formlayout_linear2 = new QFormLayout;
    formlayout_linear2->addRow(tr("Relative uy:"),edit_uy);
    formlayout_linear2->addRow(tr("Relative hy:"),edit_hy);
    hbox_linear->addLayout(formlayout_linear1);
    hbox_linear->addLayout(formlayout_linear2);
    gbox_linear->setLayout(hbox_linear);
    gbox_linear->setTitle(tr("Linear Material Properties"));

    mainlayout->addWidget(gbox_linear);

    /**  Nonlinear Material Properties **/
    QGroupBox* gbox_nonl = new QGroupBox(w);
    gbox_nonl->setTitle(tr("Nonlinear Material Properties"));
    hbox_linear = new QHBoxLayout;
    QToolButton* bt_bhcurve = new QToolButton(w);
    bt_bhcurve->setText(tr("B-H Curve"));
    QHBoxLayout* hbox1 = new QHBoxLayout;
    hbox1->addWidget(bt_bhcurve);
    formlayout_linear1 = new QFormLayout;
    edit_hx = new QLineEdit(w);
    formlayout_linear1->addRow(tr("hmax"),edit_hx);
    hbox_linear->addStretch();
    hbox_linear->addLayout(hbox1);
    hbox_linear->addStretch();
    hbox_linear->addLayout(formlayout_linear1);
    hbox_linear->addStretch();
    gbox_nonl->setLayout(hbox_linear);

    mainlayout->addWidget(gbox_nonl);

    QGroupBox* gbox_corer = new QGroupBox(w);
    gbox_corer->setTitle(tr("Coercivity"));
    QFormLayout* form_coer = new QFormLayout;
    QLineEdit* edit_coer = new QLineEdit(w);
    form_coer->addRow(tr("J,MA"),edit_coer);
    gbox_corer->setLayout(form_coer);

    QGroupBox* gbox_conduct = new QGroupBox(w);
    gbox_conduct->setTitle(tr("Electrical Conductivity"));
    QFormLayout* form_conduct = new QFormLayout;
    QLineEdit* edit_conduct = new QLineEdit(w);
    form_conduct->addRow(tr("J,MA"),edit_conduct);
    gbox_conduct->setLayout(form_conduct);

    QHBoxLayout* coer_conduct = new QHBoxLayout;
    coer_conduct->addWidget(gbox_corer);
    coer_conduct->addWidget(gbox_conduct);

    mainlayout->addLayout(coer_conduct);

    QGroupBox* gbox_source = new QGroupBox(w);
    gbox_source->setTitle(tr("Source Current Density"));
    QFormLayout* form_current = new QFormLayout;
    QLineEdit* edit_current = new QLineEdit(w);
    form_current->addRow(tr("J,MA"),edit_current);
    gbox_source->setLayout(form_current);

    mainlayout->addWidget(gbox_source);

    w->setLayout(mainlayout);

    connect(combo_bhtype,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),w,[gbox_linear,gbox_nonl](int index){
        if(index == 0){
            gbox_linear->setEnabled(true);
            gbox_nonl->setEnabled(false);
        }
        if(index == 1){
            gbox_linear->setEnabled(false);
            gbox_nonl->setEnabled(true);
        }
    });
    combo_bhtype->setCurrentIndex(1);
    combo_bhtype->setCurrentIndex(0);

    return w;
}
