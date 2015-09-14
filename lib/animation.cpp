#include <QImageReader>
#include <QtDebug>

#include "animation.h"

Animation::Animation(QString fileName)
{
    qDebug() << fileName;
    QImageReader reader(fileName);
    for (int i = 0; i <= reader.imageCount(); i++) {
        reader.jumpToImage(i);
        Animation::frames.append(new Frame());
        int delay = reader.nextImageDelay();
        Animation::frames[i]->FrameFill(reader.read(), delay);
    }
}

Animation::Animation()
{

}

QImage Animation::getFrameImage(int position)
{

    return Animation::frames[position]->GetImage();
}

void Animation::Draw(QLabel *label, int position)
{
    label->setPixmap(QPixmap::fromImage(frames[position]->GetImage()));
}

int Animation::framesCount()
{
    return Animation::frames.count();
}

int Animation::getFrameDelay(int position)
{
    return Animation::frames[position]->GetDelay();
}

Frame* Animation::getFrame(int position)
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

void Animation::addFrame(int position, Frame frame)
{
    Animation::frames.append(new Frame());
}
