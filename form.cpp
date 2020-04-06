#include "form.hpp"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    parent->setEnabled(false);
    setWindowModality(Qt::ApplicationModal);
    show();
}

Form::~Form()
{
    auto w = qobject_cast<QWidget*>(parent());
    if(w)
        w->setEnabled(true);
    delete ui;
}

void Form::closeEvent(QCloseEvent* event)
{
    this->deleteLater();
    QWidget::closeEvent(event);
}
