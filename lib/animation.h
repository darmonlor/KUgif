#ifndef ANIMATION_H
#define ANIMATION_H
#include <QSlider>
#include <QObject>

#include "frame.h"

class Animation: public QObject
{
    Q_OBJECT
private:
    QVector<Frame *> frames ;
    QSlider* slider;
    QLabel* label;
    QLabel* positionLabel;
    int pos;
public:
    explicit Animation(QString fileName,QLabel *label,QLabel *positionLabel, QSlider *slider,QObject *parent = 0);
    explicit Animation(QLabel *label,QLabel *positionLabel, QSlider *slider,QObject *parent=0);
    explicit Animation(QObject *parent=0);


    QImage getFrameImage(int position);
    void Draw(int position = 0);
    int framesCount();
    int getFrameDelay(int position);
    Frame* getFrame(int position);
    void setFrameDelay(int position, int delay);
    void deleteFrame(int position);
    void addFrame(Frame *frame, int position);
    void addFrame(Frame *frame);

public slots:
    void redraw(int position);
    // QObject interface
protected:

};

#endif // ANIMATION_H
