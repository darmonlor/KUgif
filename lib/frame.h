#ifndef FRAME_H
#define FRAME_H
#include <QObject>
#include <QImage>
#include <QLabel>

class Frame : public QObject
{
    Q_OBJECT
private:
    int delay;
    QImage image;

public:
    explicit Frame(QObject *parent = 0);
    void FrameFill(QImage image, int delay);
    void SetFrame(QImage image);
    void SetDelay(int delay);
    QImage GetImage();
    int GetDelay();

signals:

public slots:
};

#endif // FRAME_H
