#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QDialog>

#include "form.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonForm, &QPushButton::clicked, this, &MainWindow::createForm);
    connect(ui->buttonQDialog, &QPushButton::clicked, this, &MainWindow::createDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createForm()
{
    new Form(this);
}

void MainWindow::createDialog()
{

    auto w = new QDialog(this);
    w->setModal(true);
    setEnabled(false);
    w->setWindowModality(Qt::ApplicationModal);
    connect(w, &QDialog::finished, [this, w](int){
        this->setEnabled(true);
        w->deleteLater();
    });
    w->show();
}

