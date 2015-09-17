#ifndef ANIMATION_H
#define ANIMATION_H

#include<QObject>
class QLabel;
class QSlider;
class Frame;


class Animation: public QObject
{
    Q_OBJECT
private:

public:

    explicit Animation(QString fileName, QLabel *label, QLabel *positionLabel, QSlider *slider,
                       QObject *parent = 0);
    explicit Animation(QLabel *label, QLabel *positionLabel, QSlider *slider, QObject *parent = 0);
    explicit Animation(QObject *parent = 0);


    QImage getFrameImage(int position);
    int framesCount();
    int getFrameDelay(int position);
    Frame *getFrame(int position);
    void setFrameDelay(int position, int delay);
    void deleteFrame(int position);
    void addFrame(Frame *frame, int position);
    void addFrame(Frame *frame);
    void Draw(int position = 0);
    void nextFrame();

    int getPos() const;

public slots:
    void moved(int position);

    // QObject interface
protected:

    QList<Frame *> frames ;
    QSlider *slider;
    QLabel *label;
    QLabel *positionLabel;
    int pos;

};

#endif // ANIMATION_H
