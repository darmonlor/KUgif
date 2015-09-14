#ifndef FRAME_H
#define FRAME_H
#include <QObject>
#include <QImage>
#include <QLabel>


class Frame
{
private:
    int delay;
    QImage image;

public:
    explicit Frame();
    void FrameFill(QImage image, int delay);
    void SetFrame(QImage image);
    void SetDelay(int delay);
    QImage GetImage();
    int GetDelay();
};

#endif // FRAME_H
