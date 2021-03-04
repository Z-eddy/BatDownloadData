#ifndef DOWNLOADLINK_H
#define DOWNLOADLINK_H

#include <QRunnable>
#include <QString>

class DownloadLink : public QRunnable {
 public:
  DownloadLink(const QString& link, const QString& fileName);

  // QRunnable interface
 public:
  void run() override;

 private:
  QString link_;
  QString fileName_;
};

#endif  // DOWNLOADLINK_H
