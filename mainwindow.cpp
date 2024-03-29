#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roller.h"
#include "QScrollBar"

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
    QString input = ui->diceInput->text();
    QString subtotalStr;
    QString result = roller.roll(input, subtotalStr);
    ui->subtotalOut->setText(subtotalStr);
    // Scroll to bottom of result panel
    ui->subtotalOut->verticalScrollBar()->setValue(ui->subtotalOut->verticalScrollBar()->maximum());
    ui->resultOut->setText(result);
}
