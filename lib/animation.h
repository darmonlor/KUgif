#ifndef ANIMATION_H
#define ANIMATION_H
#include <QObject>
#include "frame.h"
#include <QImageReader>

class Animation : public QObject
{
    Q_OBJECT
private:
    QVector<Frame*> frames ;

public:
    explicit Animation(QString fileName, QObject *parent = 0);
    explicit Animation(QObject *parent = 0);

    QImage getFrame(int position);
    void Draw(QLabel *label, int position = 0);
    int framesCount();
    int getFrameDelay(int position);
    void setFrameDelay(int position, int delay);
    void deleteFrame(int position);


signals:

public slots:
};

#endif // ANIMATION_H
