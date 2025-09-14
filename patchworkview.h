#ifndef PATCHWORKVIEW_H
#define PATCHWORKVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QVector>
#include <QPlainTextEdit>
class PatchworkView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PatchworkView(QWidget *parent = nullptr, QPlainTextEdit *titleEdit = nullptr, QPlainTextEdit *subtitleEdit = nullptr);

private:
    QPlainTextEdit *titleEdit;
    QPlainTextEdit *subtitleEdit;

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
    void drawTitle(QPainter &painter);
};

#endif // PATCHWORKVIEW_H
