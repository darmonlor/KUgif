#include "animationsource.h"
#include <QtDebug>
#include <QImageReader>
int AnimationSource::count=0;
int AnimationSource::active=0;

AnimationSource::AnimationSource(QString fileName, QLabel *label, QLabel *positionLabel,
                                 QSlider *slider, QObject *parent)
{
    AnimationSource::active=AnimationSource::count;
    AnimationSource::sourceID=count;
    AnimationSource::count+=1;
    qDebug()<<AnimationSource::count;
    AnimationSource::setParent(parent);
    AnimationSource::slider = slider;
    AnimationSource::label = label;
    AnimationSource::positionLabel = positionLabel;
    connect(AnimationSource::slider, SIGNAL(valueChanged(int)), this, SLOT(redraw(int)));
    qDebug() << fileName;
    QImageReader reader(fileName);
    for (int i = 0; i <= reader.imageCount()-1; i++) {
        reader.jumpToImage(i);
        AnimationSource::frames.append(new Frame());
        int delay = reader.nextImageDelay();
        AnimationSource::frames[i]->FrameFill(reader.read(), delay);
    }
}

AnimationSource::AnimationSource(QLabel *label, QLabel *positionLabel, QSlider *slider,
                                 QObject *parent)
{
    AnimationSource::count+=1;
    AnimationSource::setParent(parent);
    AnimationSource::slider = slider;
    AnimationSource::label = label;
    AnimationSource::positionLabel = positionLabel;
    connect(AnimationSource::slider, SIGNAL(valueChanged(int)), this, SLOT(redraw(int)));
}

AnimationSource::AnimationSource(QObject *parent)
{
    AnimationSource::setParent(parent);
}

void AnimationSource::activeChanged(int newActive)
{
    qDebug()<<newActive;
    if (newActive==AnimationSource::sourceID){
        connect(AnimationSource::slider, SIGNAL(valueChanged(int)), this, SLOT(redraw(int)));
        AnimationSource::redraw(0);

        qDebug()<<"connected: "<<AnimationSource::sourceID;
    } else {
        disconnect(AnimationSource::slider, SIGNAL(valueChanged(int)), this, SLOT(redraw(int)));
        qDebug()<<"disconnected: "<<AnimationSource::sourceID;
    }
}
