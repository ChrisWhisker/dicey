#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Roller roller;
    QString input = ui->lineEdit->text();
    QString result = roller.roll(input);
    ui->textEdit->setText(result);
}
