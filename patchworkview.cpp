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
#include <QDebug> // Add at the top if not present
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QDrag>
#include <QImageReader>


// Drag event ==> echange de place d'image 
class DraggablePixmapItem : public QGraphicsPixmapItem
{
public:
    DraggablePixmapItem(const QPixmap &pixmap, int index, QVector<QPixmap> *images)
        : QGraphicsPixmapItem(pixmap), imagesVector(images), imageIndex(index)
    {
        setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
        setAcceptDrops(true);
    }

    void setIndex(int index) { imageIndex = index; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            QDrag *drag = new QDrag(event->widget());
            QMimeData *mime = new QMimeData;

            QByteArray data;
            QDataStream stream(&data, QIODevice::WriteOnly);
            stream << (quintptr)this; // encode pointer
            mime->setData("application/x-item", data);

            drag->setMimeData(mime);
            drag->setPixmap(pixmap());
            drag->exec(Qt::MoveAction);
        }
        QGraphicsPixmapItem::mousePressEvent(event);
    }

    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override {
        if (event->mimeData()->hasFormat("application/x-item"))
            event->acceptProposedAction();
    }

    void dropEvent(QGraphicsSceneDragDropEvent *event) override {
        if (!event->mimeData()->hasFormat("application/x-item"))
            return;

        QByteArray data = event->mimeData()->data("application/x-item");
        QDataStream stream(&data, QIODevice::ReadOnly);
        quintptr ptr;
        stream >> ptr;
        auto *other = reinterpret_cast<DraggablePixmapItem*>(ptr);

        if (other && other != this) {
            // swap pixmaps
            QPixmap tmp = pixmap();
            setPixmap(other->pixmap());
            other->setPixmap(tmp);

            // update QVector to reflect new order
            QPixmap tmpPix = (*imagesVector)[imageIndex];
            (*imagesVector)[imageIndex] = (*imagesVector)[other->imageIndex];
            (*imagesVector)[other->imageIndex] = tmpPix;

            int tmpIndex = imageIndex;
            imageIndex = other->imageIndex;
            other->imageIndex = tmpIndex;
        }

        event->acceptProposedAction();
    }

private:
    QVector<QPixmap> *imagesVector;
    int imageIndex;
};


PatchworkView::PatchworkView(QWidget *parent)
    : QGraphicsView(parent), scene(new QGraphicsScene(this)), margin(10), maxWidth(1000)
{
    setAcceptDrops(true);
    setScene(scene);
}

void PatchworkView::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "dragEnterEvent called";
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void PatchworkView::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void PatchworkView::dropEvent(QDropEvent *event)
{
    qDebug() << "Supported formats:" << QImageReader::supportedImageFormats();
    QList<QUrl> urls = event->mimeData()->urls();
    for (const QUrl &url : urls)
    {
        QString filePath = url.toLocalFile();
        qDebug() << "Dropped URL:" << url << "File path:" << filePath;
        QImage img(filePath);
        if (!img.isNull()) {
            images.append(QPixmap::fromImage(img));
        } else {
            qDebug() << "Failed to load image with QImage from:" << filePath;
        }
    }
    arrangePatchwork();
}

void PatchworkView::arrangePatchwork()
{
    scene->clear();

    int x = 0, y = 0;
    int row = 0, col = 0;
    int currentRowHeight = 0;

    for (int i = 0; i < images.size(); ++i)
    {
        const QPixmap &pix = images[i];
        DraggablePixmapItem *item = new DraggablePixmapItem(pix, i, &images);
        scene->addItem(item);

        // Si l'image suivante dépasse la largeur max, on passe à la ligne suivante
        if (x + pix.width() > maxWidth && col > 0) {
            x = 0;
            y += currentRowHeight + margin;
            row++;
            col = 0;
            currentRowHeight = 0;
        }

        item->setPos(x, y);

        x += pix.width() + margin;
        col++;
        if (pix.height() > currentRowHeight)
            currentRowHeight = pix.height();
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
