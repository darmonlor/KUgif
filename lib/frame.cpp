
#include "frame.h"

Frame::Frame()
{

}

Frame::Frame(QImage image, int delay)
{
    Frame::image = image;
    Frame::delay = delay;

}

void Frame::SetFrame(QImage image)
{

}
void Frame::SetDelay(int delay)
{
    Frame::delay = delay;
}

QImage Frame::GetImage()
{
    return Frame::image;
}

int Frame::GetDelay()
{
    return Frame::delay;
}


