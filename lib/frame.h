#ifndef FRAME_H
#define FRAME_H
#include <QObject>
#include <QImage>
class QImage;

class Frame
{
private:
    int delay;
    QImage image;

public:
    explicit Frame();
    explicit Frame(QImage image, int delay);
    void SetFrame(QImage image);
    void SetDelay(int delay);
    QImage GetImage();
    int GetDelay();
};

#endif // FRAME_H
