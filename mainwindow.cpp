#include <QPixmap>

#include "lib/frame.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    animationTarget = new Animation(ui->label_2,ui->timeLabel_2,ui->horizontalSlider_2);
    animationSource = new Animation();
}

MainWindow::~MainWindow()
{
    delete animationSource;
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
        delete animationSource;
        animationSource = new Animation(fileName,ui->label,ui->timeLabel,ui->horizontalSlider);
        QMessageBox::warning(this, "file",
                             QString("Number of frames: %1.").arg(animationSource->framesCount()));
        ui->horizontalSlider->setMaximum(animationSource->framesCount() - 2);
        animationSource->Draw();

        ui->timeLabel->setText(QString("%1 : %2").arg(QString::number(ui->horizontalSlider->value() + 1),
                                                      QString::number(animationSource->framesCount() - 1)));
    }
}




void MainWindow::on_horizontalSlider_valueChanged(int value)
{

}



void MainWindow::on_frameRemoveButton_clicked()
{
    animationSource->deleteFrame(ui->horizontalSlider_2->value());
    ui->horizontalSlider_2->setMaximum(animationSource->framesCount() - 2);
    ui->timeLabel_2->setText(QString("%1 : %2").arg(QString::number(ui->horizontalSlider_2->value()),
                                                    QString::number(animationSource->framesCount() - 1)));
    animationSource->Draw(ui->horizontalSlider_2->value());

}

void MainWindow::on_actionSave_As_triggered()
{

}

void MainWindow::on_delayBox_valueChanged(int arg1)
{
    animationSource->setFrameDelay(ui->horizontalSlider->value(), arg1);
}

void MainWindow::on_frameAddButton_clicked()
{
animationTarget->addFrame(animationSource->getFrame(ui->horizontalSlider->value()));
}
