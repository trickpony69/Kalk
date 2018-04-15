#include "finestra.h"

finestra::finestra(QWidget *parent) : QMainWindow(parent),widgetCentrale(new mainGui){
    setWindowTitle("mok");
    setCentralWidget(widgetCentrale);

    auto dummy1 = new QWidget(this);
    dummy1->setFixedHeight(40);
    //dummy1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPixmap newpix(":/zoomIn.png");
    QPixmap openpix("open.png");
    QPixmap quitpix("quit.png");
    auto tb = new QToolBar();
    tb->addWidget(dummy1);
    tb->addAction(QIcon(newpix),"zoom in");
    tb->addAction(QIcon(openpix),"zomm out");
    tb->addAction("aiuto");
    tb->setFloatable(false);
    tb->setMovable(false);
    addToolBar(tb);

    resize(600,400);
}
