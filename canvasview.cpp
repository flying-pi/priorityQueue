#include "canvasview.h"

#include <QPainter>
#include <QDebug>

CanvasView::CanvasView(QWidget* parent)
    : QWidget(parent), font("times", 14), fm(font) {
  queue = nullptr;
}

void CanvasView::setQueue(PriorityQueue<int>* queue) {
  this->queue = queue;
}

void CanvasView::paintEvent(QPaintEvent* event) {
  painter = new QPainter(this);
  QBrush br;

  br.setColor(Qt::darkYellow);
  br.setStyle(Qt::SolidPattern);
  painter->setBrush(br);
  painter->setPen(QPen(Qt::black, 3));

  QList<QString> list;
  float maxWidth = -1;
  int buf = 0;
  for (int i = 0; i < queue->getSize(); i++) {
    list.append(QString::number(queue->at(i)));
    buf = fm.width(list.last());
    if (buf > maxWidth)
      maxWidth = buf;
  }
  drawItem(&list, 1, maxWidth, list.size() * maxWidth * 3, maxWidth * 0.5,
           maxWidth * 1.25);
}

void CanvasView::drawItem(QList<QString>* items,
                          int itemPos,
                          float left,
                          float right,
                          float top,
                          float r) {
  if (itemPos > items->size())
    return;
  if (itemPos * 2 <= items->size()) {
    painter->drawLine((left + right) / 2, top + r,
                      (left + ((right - left) / 2) + left) / 2, top + 5 * r);
    drawItem(items, itemPos * 2, left, left + ((right - left) / 2), top + 4 * r,
             r);
  }
  if (itemPos * 2 + 1 <= items->size()) {
    painter->drawLine((left + right) / 2, top + r,
                      (left + ((right - left) / 2) + right) / 2, top + 5 * r);
    drawItem(items, itemPos * 2 + 1, left + ((right - left) / 2), right,
             top + 4 * r, r);
  }

  QPointF center((left + right) / 2, top + r);
  painter->drawEllipse(center, r, r);
  center.setX(center.x() - (int)(fm.width(items->at(itemPos - 1)) / 2.0));
  center.setY(center.y() + fm.ascent() / 2.0);
  painter->drawText(center, items->at(itemPos - 1));
}
