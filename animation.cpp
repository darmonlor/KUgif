#include "animation.h"

Animation::Animation(QString fileName, QObject *parent) : QObject(parent)
{
    QImageReader reader(fileName);
    for (int i=0;i<=reader.imageCount();i++)
    {
        reader.jumpToImage(i);
        //framesFrom.append(reader->read());
        Animation::frames.append(new Frame(this));
        Animation::frames[i]->FrameFill(reader.read(),reader.nextImageDelay());
    }
}

QImage Animation::getFrame(int position)
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

void Animation::setFrameDelay(int position, int delay)
{
    Animation::frames[position]->SetDelay(delay);
}

void Animation::deleteFrame(int position)
{
    Animation::frames.remove(position);
}
