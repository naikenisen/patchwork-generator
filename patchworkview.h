#ifndef PATCHWORKVIEW_H
#define PATCHWORKVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QVector>

class PatchworkView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PatchworkView(QWidget *parent = nullptr);

public slots:
    void exportPDF();
    void exportPNG();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    QGraphicsScene *scene;
    QVector<QPixmap> images;
    int margin;
    int maxWidth;
    void arrangePatchwork();
};

#endif // PATCHWORKVIEW_H
