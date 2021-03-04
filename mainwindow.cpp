#include "mainwindow.h"

#include <QDebug>
#include <QStringList>
#include <QThreadPool>

#include "./ui_mainwindow.h"
#include "downloadlink.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_btnAdd_clicked() {
  auto link{ui->lineEdit->text()};
  ui->listWidget->addItem(link);
  ui->lineEdit->clear();
}

void MainWindow::on_btnStart_clicked() {
  auto count{ui->listWidget->count()};

  auto gloTPool{QThreadPool::globalInstance()};
  for (auto i{0}; i != count; ++i) {
    auto item{ui->listWidget->item(i)};
    auto link{item->text()};
    auto downClass{new DownloadLink{link, QString::number(i)}};
    gloTPool->start(downClass);
  }
}

void MainWindow::on_btnClear_clicked() { ui->listWidget->clear(); }
