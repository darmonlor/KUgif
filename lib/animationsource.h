#ifndef ANIMATIONSOURCE_H
#define ANIMATIONSOURCE_H
#include "animation.h"
#include <QObject>

class AnimationSource : public Animation
{
    Q_OBJECT
public:
    explicit AnimationSource(QString fileName, QLabel *label, QLabel *positionLabel, QSlider *slider,
                       QObject *parent = 0);
    explicit AnimationSource(QLabel *label, QLabel *positionLabel, QSlider *slider, QObject *parent = 0);
    explicit AnimationSource(QObject *parent = 0);
private:
    int sourceID;
    static int active;
    static int count;
signals:
public slots:
    void activeChanged(int newActive);
};

#endif // ANIMATIONSOURCE_H
