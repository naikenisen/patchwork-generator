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
#include <QPlainTextEdit>
#include <QGraphicsProxyWidget>
#include <QDebug>

// class PatchworkView : contains scene, a pointer to QGraphicsScene
PatchworkView::PatchworkView(QWidget *parent,
                             QPlainTextEdit *titleEdit,
                             QPlainTextEdit *subtitleEdit)

    : QGraphicsView(parent), scene(new QGraphicsScene(this)),
      margin(10), maxWidth(1000), titleEdit(titleEdit), subtitleEdit(subtitleEdit)
{
    setAcceptDrops(true);
    setScene(scene);
}

// Handle drag enter event to accept URLs
void PatchworkView::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

// Handle drop event to add images
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

void PatchworkView::drawTitle(QPainter &painter)
{
    // Get scene bounding rect
    QRectF bounds = scene->itemsBoundingRect();

    // Calculate position below the scene
    int x = bounds.left() + 10;
    int y = bounds.bottom() + 30;

    // Draw title
    QFont titleFont("Arial", 18, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(Qt::black);
    painter.drawText(x, y, titleEdit->toPlainText());

    // Draw subtitle below title
    QFont subtitleFont("Arial", 14, QFont::Normal);
    painter.setFont(subtitleFont);
    painter.drawText(x, y + 200, subtitleEdit->toPlainText());
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
    drawTitle(painter);
}

void PatchworkView::exportPNG()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export PNG", "", "*.png");
    if (fileName.isEmpty())
        return;

    QRectF bounds = scene->itemsBoundingRect();

    // If scene is blank, add a placeholder rectangle
    if (scene->items().isEmpty())
    {
        QRectF placeholderRect(0, 0, 300, 300);
        scene->addRect(placeholderRect, QPen(Qt::gray), QBrush(Qt::lightGray));
        bounds = placeholderRect;
    }

    // Ensure minimum size of 300x300 px
    int minSize = 300;
    QSize imageSize(qMax(int(bounds.width()), minSize), qMax(int(bounds.height()), minSize));

    QImage image(imageSize, QImage::Format_ARGB32);
    image.setDotsPerMeterX(300 * 1000 / 25.4);
    image.setDotsPerMeterY(300 * 1000 / 25.4);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);

    // Scale scene to fit image size
    double scaleX = double(imageSize.width()) / bounds.width();
    double scaleY = double(imageSize.height()) / bounds.height();
    painter.scale(scaleX, scaleY);

    scene->render(&painter);
    drawTitle(painter);

    bool saved = image.save(fileName);
    qDebug() << "Export PNG:" << fileName << "Saved:" << saved << "Size:" << imageSize;
}
