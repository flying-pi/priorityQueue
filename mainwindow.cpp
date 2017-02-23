#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  timer.setInterval(250);
  connect(&timer, SIGNAL(timeout()), this, SLOT(timerTick()));
  timer.start();

  ui->setupUi(this);
  ui->canvasView->setQueue(&queue);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_addItem_clicked() {
  queue.add(ui->nums->text().toInt());
  ui->nums->setText("");
}

void MainWindow::timerTick() {
  ui->canvasView->repaint();
  ui->queueString->setText(queueToString());
}

QString MainWindow::queueToString() {
  QString result = "";
  for (int i = 0; i < queue.getSize(); i++)
    result += " " + QString::number(queue.at(i));
  return result;
}
