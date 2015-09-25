#include <QImageReader>
#include <QtDebug>
#include "frame.h"
#include "animation.h"
#include <QSlider>
#include <QLabel>

Animation::Animation(QString fileName, QLabel *label, QLabel *positionLabel, QSlider *slider,
                     QObject *parent) : QObject( parent)
{
    Animation::slider = slider;
    Animation::label = label;
    Animation::positionLabel = positionLabel;
    connect(Animation::slider, SIGNAL(valueChanged(int)), this, SLOT(moved(int)));
    qDebug() << fileName;
    QImageReader reader(fileName);
    for (int i = 0; i <= reader.imageCount() - 1; i++) {
        reader.jumpToImage(i);
        int delay = reader.nextImageDelay();
        Animation::frames.append(new Frame(reader.read(), delay));
    }
    Animation::pos=0;
    qDebug()<<"initialized position: "<<pos;

}

Animation::Animation(QLabel *label, QLabel *positionLabel, QSlider *slider,
                     QObject *parent) : QObject( parent)
{
    Animation::slider = slider;
    Animation::label = label;
    Animation::positionLabel = positionLabel;
    connect(Animation::slider, SIGNAL(valueChanged(int)), this, SLOT(moved(int)));
    Animation::pos=0;
}

Animation::Animation(QObject *parent) : QObject( parent)
{

}

QImage Animation::getFrameImage(int position)
{


    return Animation::frames[position]->GetImage();
}

void Animation::Draw(int position)
{
    Animation::label->setPixmap(QPixmap::fromImage(frames[position]->GetImage()));
    qDebug() << "Drawing: " << position;
}

void Animation::nextFrame()
{
    qDebug()<<"framecount: "<<frames.count();
    qDebug()<<"position: "<<pos;

    if (pos < frames.count()-1) {
        ++pos;
        Animation::slider->setValue(pos);
    }
    Animation::moved(pos);
}
int Animation::framesCount()
{
    return Animation::frames.count();
}

int Animation::getFrameDelay(int position)
{
    return Animation::frames[position]->GetDelay();
}

Frame *Animation::getFrame(int position)
{
    return Animation::frames[position];
}

void Animation::setFrameDelay(int position, int delay)
{
    Animation::frames[position]->SetDelay(delay);
}

void Animation::deleteFrame(int position)
{
    Animation::frames.removeAt(position);
}

void Animation::addFrame(Frame *frame, int position)
{
    Animation::frames.insert(position, frame);
}

void Animation::addFrame(Frame *frame)
{
    if (Animation::framesCount() == 0) {
        qDebug() << "Inserting" << (Animation::slider->value());
        Animation::frames.insert(Animation::slider->value(), frame);
//        Animation::moved(Animation::slider->value());
    } else {
        qDebug() << "Inserting" << Animation::slider->value() + 1;
        Animation::frames.insert(Animation::slider->value() + 1, frame);
//        Animation::moved(Animation::slider->value() + 1);
    }
    Animation::nextFrame();
    qDebug() << "Added frame, new framenumber: " << Animation::framesCount();


}

void Animation::moved(int position)
{
//    qDebug()<<"position var: "<<position<<" slider: "<<slider->value()<<"name: "<<slider->objectName();
    qDebug() << "Settingup counter: " << framesCount();
//ui->delayBox->setValue(animationSource->getFrameDelay(value));
    Animation::positionLabel->setText(QString("%1 : %2").arg(QString::number(position + 1),
                                                             QString::number(framesCount())));
    Animation::slider->setMaximum(Animation::framesCount() - 1);
    Animation::slider->setValue(position);
    Draw(position);
    pos = position;

}

int Animation::getPos() const
{
    return pos;
}
