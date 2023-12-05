#include "mainwindow.h"
#include "QVBoxLayout"
#include "ollamaManager.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ollamaMngr = new ollamaManager();

    auto layoutMain = new QVBoxLayout;

    layoutMain->addWidget(ollamaMngr);

    setLayout(layoutMain);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnTest_clicked()
{
    ollamaMngr->test();
}
