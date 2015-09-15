#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QImageReader>
#include "lib/animation.h"
#include "lib/animationsource.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();


    void on_horizontalSlider_valueChanged(int value);

    void on_frameRemoveButton_clicked();

    void on_actionSave_As_triggered();

    void on_delayBox_valueChanged(int arg1);

    void on_frameAddButton_clicked();

    void on_sourceList_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;
    QVector<AnimationSource*>animationSource;
    AnimationSource* activeSource;
    Animation *animationTarget;


};

#endif // MAINWINDOW_H
