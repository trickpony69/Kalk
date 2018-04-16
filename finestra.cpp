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
    QAction* zoomIn = new QAction("zoom in");
    QAction* zoomOut = new QAction("zoom out");
    tb->addAction(zoomIn);
    tb->addAction(zoomOut);
    tb->addAction("aiuto");
    tb->setFloatable(false);
    tb->setMovable(false);
    addToolBar(tb);
    resize(600,400);
    QObject::connect(zoomIn, SIGNAL(triggered()), this, SLOT(zoomIn()));
    QObject::connect(zoomOut, SIGNAL(triggered()), this, SLOT(zoomOut()));
}

void finestra::zoomIn(){
     widgetCentrale->view->scale(qreal(1.2), qreal(1.2));
}

void finestra::zoomOut(){
     widgetCentrale->view->scale(qreal(0.8), qreal(0.8));
}
