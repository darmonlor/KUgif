#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QStandardPaths::standardLocations(QStandardPaths::HomeLocation).last() , tr("Image Files (*.apng *.gif)"));
    delete animation;
    animation = new Animation(fileName,this);
    QMessageBox::warning(this,"file", QString("My magic number is %1. That's all!").arg(animation->framesCount()));
    ui->horizontalSlider->setMaximum(animation->framesCount()-2);
    ui->horizontalSlider_2->setMaximum(animation->framesCount()-2);
    animation->Draw(ui->label);
    animation->Draw(ui->label_2);

    ui->timeLabel->setText(QString("%1 : %2").arg(QString::number(ui->horizontalSlider->value()+1),QString::number(animation->framesCount()-1)));
    ui->timeLabel_2->setText(QString("%1 : %2").arg(QString::number(ui->horizontalSlider->value()+1),QString::number(animation->framesCount()-1)));

}




void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    animation->Draw(ui->label, value);
    ui->delayBox->setValue(animation->getFrameDelay(value));
    ui->timeLabel->setText(QString("%1 : %2").arg(QString::number(value+1),QString::number(animation->framesCount()-1)));
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    animation->Draw(ui->label_2,value);
    ui->timeLabel_2->setText(QString("%1 : %2").arg(QString::number(value+1),QString::number(animation->framesCount()-1)));
}

void MainWindow::on_frameRemoveButton_clicked()
{
    animation->deleteFrame(ui->horizontalSlider_2->value());
    ui->horizontalSlider_2->setMaximum(animation->framesCount()-2);
    ui->timeLabel_2->setText(QString("%1 : %2").arg(QString::number(ui->horizontalSlider_2->value()),QString::number(animation->framesCount()-1)));
    animation->Draw(ui->label_2,ui->horizontalSlider_2->value());

}

void MainWindow::on_actionSave_As_triggered()
{

}

void MainWindow::on_delayBox_valueChanged(int arg1)
{
    animation->setFrameDelay(ui->horizontalSlider->value(),arg1);
}
