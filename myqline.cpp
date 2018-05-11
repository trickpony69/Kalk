#include "myqline.h"

myQline::myQline(QWidget* p): QLineEdit(p){}

void myQline::dragEnterEvent(QDragEnterEvent *e){
    if(e->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")){
        e->acceptProposedAction();
    }
}

void myQline::dropEvent(QDropEvent *e){
    QByteArray encoded = e->mimeData()->data("application/x-qabstractitemmodeldatalist");
    QDataStream strm(&encoded, QIODevice::ReadOnly);
    while(!strm.atEnd()){
        int row, col;
        QMap<int,  QVariant> data;
        strm >> row >> col >> data;
        this->setText(data[0].toString());
    }
}
