#pragma once

#include <QRunnable>
#include <QString>

class DownloadLink : public QRunnable {
 public:
  DownloadLink(const QString& link, int idx, const QString& fileName);

  // QRunnable interface
 public:
  void run() override;

 private:
  QString link_;      // link
  int idx_;           // List中的索引
  QString fileName_;  //文件名
};
