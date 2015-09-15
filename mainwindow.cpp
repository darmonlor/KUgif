#include <QPixmap>

#include "lib/frame.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    animationTarget = new Animation(ui->label_2,ui->timeLabel_2,ui->horizontalSlider_2);
}

MainWindow::~MainWindow()
{
    delete animationTarget;
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                            QStandardPaths::standardLocations(QStandardPaths::HomeLocation).last(),
                                            tr("Image Files (*.apng *.gif)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        activeSource=new AnimationSource(fileName,ui->label,ui->timeLabel,ui->horizontalSlider);
        animationSource.append(activeSource);
        ui->horizontalSlider->setMaximum(activeSource->framesCount() - 2);
        activeSource->Draw();
        connect(ui->sourceList,SIGNAL(currentRowChanged(int)),activeSource,SLOT(activeChanged(int)));
        ui->timeLabel->setText(QString("%1 : %2").arg(QString::number(ui->horizontalSlider->value() + 1),
                                                      QString::number(activeSource->framesCount() - 1)));
        new QListWidgetItem(fileName, ui->sourceList);
    }

}




void MainWindow::on_horizontalSlider_valueChanged(int value)
{

}



void MainWindow::on_frameRemoveButton_clicked()
{
    activeSource->deleteFrame(ui->horizontalSlider_2->value());
    ui->horizontalSlider_2->setMaximum(activeSource->framesCount() - 2);
    ui->timeLabel_2->setText(QString("%1 : %2").arg(QString::number(ui->horizontalSlider_2->value()),
                                                    QString::number(activeSource->framesCount() - 1)));
    activeSource->Draw(ui->horizontalSlider_2->value());

}

void MainWindow::on_actionSave_As_triggered()
{

}

void MainWindow::on_delayBox_valueChanged(int arg1)
{
    activeSource->setFrameDelay(ui->horizontalSlider->value(), arg1);
}

void MainWindow::on_frameAddButton_clicked()
{
qDebug()<<"Adding frame: "<<ui->horizontalSlider->value();
animationTarget->addFrame(activeSource->getFrame(ui->horizontalSlider->value()));
animationTarget->redraw(0);
}

void MainWindow::on_sourceList_currentRowChanged(int currentRow)
{
activeSource=animationSource[currentRow];
}
