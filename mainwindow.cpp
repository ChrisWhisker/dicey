#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reader.h"

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
    Reader reader;
    // reader.roll()
    QString x = ui->lineEdit->text();
    const char* cStyleString = x.toUtf8().constData();
    int result = reader.roll(cStyleString);
    ui->textEdit->setText(QString::number(result));
}
