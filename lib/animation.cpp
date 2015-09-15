#include <QImageReader>
#include <QtDebug>

#include "animation.h"

Animation::Animation(QString fileName, QLabel *label, QLabel *positionLabel, QSlider *slider,
                     QObject *parent) : QObject( parent)
{
    Animation::slider = slider;
    Animation::label = label;
    Animation::positionLabel = positionLabel;
    connect(Animation::slider, SIGNAL(valueChanged(int)), this, SLOT(redraw(int)));
    qDebug() << fileName;
    QImageReader reader(fileName);
    for (int i = 0; i <= reader.imageCount()-1; i++) {
        reader.jumpToImage(i);
        Animation::frames.append(new Frame());
        int delay = reader.nextImageDelay();
        Animation::frames[i]->FrameFill(reader.read(), delay);
    }
}

Animation::Animation(QLabel *label, QLabel *positionLabel, QSlider *slider,
                     QObject *parent) : QObject( parent)
{
    Animation::slider = slider;
    Animation::label = label;
    Animation::positionLabel = positionLabel;
    connect(Animation::slider, SIGNAL(valueChanged(int)), this, SLOT(redraw(int)));
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
    qDebug()<<"Drawing: "<<position;
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
    Animation::frames.remove(position);
}

void Animation::addFrame(Frame *frame, int position)
{
    Animation::frames.append(frame);
}

void Animation::addFrame(Frame *frame)
{
    Animation::frames.append(frame);
}

void Animation::redraw(int position)
{
    qDebug() << "scroll" << position;
    Draw(position);
//ui->delayBox->setValue(animationSource->getFrameDelay(value));
    Animation::positionLabel->setText(QString("%1 : %2").arg(QString::number(position + 1),
                                                             QString::number(framesCount() - 1)));
    Animation::slider->setValue(position);
    Animation::slider->setMaximum(Animation::framesCount()-1);
}
