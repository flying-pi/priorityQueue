#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <priorityqueue.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void on_addItem_clicked();
  void timerTick();

 private:
  Ui::MainWindow* ui;
  PriorityQueue<int> queue;
  QString queueToString();
  QTimer timer;
};

#endif  // MAINWINDOW_H
