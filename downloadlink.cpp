#pragma execution_character_set("utf-8")
#include "downloadlink.h"

#include <QDebug>
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

DownloadLink::DownloadLink(const QString& link, const QString& fileName)
    : link_(link), fileName_(fileName) {}

void DownloadLink::run() {
  if (link_.isEmpty() || fileName_.isEmpty()) {
    qDebug() << "链接/文件名为空！";
    return;
  }

  qDebug() << "index:" + fileName_ + ".mp4 :start";

  string order{"ffmpeg -i \""};
  order += link_.toStdString().c_str();
  order += "\" -c copy \"";
  order += fileName_.toStdString().c_str();
  order += ".mp4\"\n";

  system(order.c_str());
  system("exit\n");

  qDebug() << "index:" + fileName_ + ".mp4 :down";
}
