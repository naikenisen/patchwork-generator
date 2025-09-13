#include "patchworkview.h"
#include <QGraphicsPixmapItem>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QImage>
#include <QUrl>
#include <QtMath>

PatchworkView::PatchworkView(QWidget *parent)
    : QGraphicsView(parent), scene(new QGraphicsScene(this)), margin(10), maxWidth(1000)
{
    setAcceptDrops(true);
    setScene(scene);
}

void PatchworkView::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void PatchworkView::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    for (const QUrl &url : urls)
    {
        QPixmap pix(url.toLocalFile());
        if (!pix.isNull())
            images.append(pix);
    }
    arrangePatchwork();
}

void PatchworkView::arrangePatchwork()
{
    scene->clear();
    int x = 0, y = 0, rowHeight = 0;
    for (const QPixmap &pix : images)
    {
        QGraphicsPixmapItem *item = scene->addPixmap(pix);
        item->setPos(x, y);
        x += pix.width() + margin;
        rowHeight = qMax(rowHeight, pix.height());
        if (x > maxWidth)
        {
            x = 0;
            y += rowHeight + margin;
            rowHeight = 0;
        }
    }
}

void PatchworkView::exportPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    QPainter painter(&printer);
    scene->render(&painter);
}

void PatchworkView::exportPNG()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export PNG", "", "*.png");
    if (fileName.isEmpty())
        return;
    QRectF bounds = scene->itemsBoundingRect();
    QImage image(bounds.size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    scene->render(&painter);
    image.save(fileName);
}
