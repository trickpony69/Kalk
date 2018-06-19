#ifndef MYQLINE_H
#define MYQLINE_H

#include <QDrag>
#include <QDragEnterEvent>
#include <QLineEdit>
#include <QMimeData>

class myQline : public QLineEdit{
public:
    myQline(QWidget * =0);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // MYQLINE_H
