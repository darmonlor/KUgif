#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include "frame.h"

class Animation
{
private:
    QVector<Frame *> frames ;

public:
    explicit Animation(QString fileName);
    explicit Animation();

    QImage getFrameImage(int position);
    void Draw(QLabel *label, int position = 0);
    int framesCount();
    int getFrameDelay(int position);
    Frame* getFrame(int position);
    void setFrameDelay(int position, int delay);
    void deleteFrame(int position);
    void addFrame(int position, Frame frame);


    // QObject interface
protected:

};

#endif // ANIMATION_H
