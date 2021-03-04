#include "mainwindow.h"

#include <QDebug>
#include <QListWidgetItem>
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
  //查找是否已有
  auto fileName{ui->editFileName->text()};
  auto matchList{ui->listWidget->findItems(fileName, Qt::MatchExactly)};
  if (matchList.count()) {  //如果找到
    qDebug() << fileName << ":已存在";
    return;
  }

  auto link{ui->editLink->text()};
  auto item{new QListWidgetItem{fileName}};
  item->setData(Qt::UserRole, link);
  ui->listWidget->addItem(item);
  ui->editLink->clear();
  ui->editFileName->clear();
}

void MainWindow::on_btnStart_clicked() {
  auto count{ui->listWidget->count()};

  auto gloTPool{QThreadPool::globalInstance()};
  for (auto i{0}; i != count; ++i) {
    auto item{ui->listWidget->item(i)};              //获得当前item
    auto link{item->data(Qt::UserRole).toString()};  //获得link
    auto downClass{new DownloadLink{link, i, item->text()}};
    gloTPool->start(downClass);
  }
}

void MainWindow::on_btnClear_clicked() { ui->listWidget->clear(); }
