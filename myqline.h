#ifndef MYQLINE_H
#define MYQLINE_H

#include <QDrag>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QLineEdit>
#include <QMimeData>
#include <QList>
#include <QUrl>
#include <QFileInfo>
#include <QByteArray>

class myQline : public QLineEdit{
public:
    myQline(QWidget * =0);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // MYQLINE_H
