#ifndef CANVASVIEW_H
#define CANVASVIEW_H

#include <QTimer>
#include <QWidget>
#include <priorityqueue.h>

class CanvasView : public QWidget {
  Q_OBJECT
 public:
  explicit CanvasView(QWidget* parent = 0);
  void setQueue(PriorityQueue<int>* queue);

 signals:

 public slots:

  // QWidget interface
 protected:
  void paintEvent(QPaintEvent* event);
  QPainter* painter;
  PriorityQueue<int>* queue;
  QFont font;
  QFontMetrics fm;

  void drawItem(QList<QString>* items,
                int itemPos,
                float left,
                float right,
                float top,
                float r);
};

#endif  // CANVASVIEW_H
