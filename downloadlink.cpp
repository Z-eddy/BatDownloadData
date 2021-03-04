#pragma execution_character_set("utf-8")
#include "downloadlink.h"

#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QObject>
#include <QProcess>
#include <QStringList>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ends;
using std::string;

DownloadLink::DownloadLink(const QString& link, int idx,
                           const QString& fileName)
    : link_(link), idx_(idx), fileName_(fileName) {}

void DownloadLink::run() {
  if (link_.isEmpty() || fileName_.isEmpty()) {
    qDebug() << "链接/文件名为空！";
    return;
  }

  qDebug() << "index:" + fileName_ + ".mp4 :start";

  string order{"ffmpeg -i \""};
  order += link_.toStdString().c_str();
  order += "\" -c copy \"";
  order += std::to_string(idx_);
  order += ".mp4\"\n";

  system(order.c_str());
  system("exit\n");

  auto ok{QFile::rename(QString::number(idx_) + ".mp4", fileName_ + ".mp4")};
  if (!ok) {
    qDebug() << fileName_ + "重命名失败";
  } else {
    qDebug() << "index:" + fileName_ + ".mp4 :down";
  }
}
