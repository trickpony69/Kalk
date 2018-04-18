#include "finestra.h"

finestra::finestra(QWidget *parent) : QMainWindow(parent),widgetCentrale(new mainGui){
    setWindowTitle("mok");
    setCentralWidget(widgetCentrale);
    QWidget* spaziatore1 = new QWidget(this);
    //auto spaziatore2 = new QWidget(this);
    spaziatore1->setFixedHeight(30);
    //spaziatore1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //spaziatore2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QToolBar* tb = new QToolBar();
    tb->addWidget(spaziatore1);
    //tb->addWidget(spaziatore2)
    QAction* zoomIn = new QAction("zoom in",this);
    QAction* zoomOut = new QAction("zoom out",this);
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
     widgetCentrale->graficoElementi->scale(qreal(1.2), qreal(1.2));
}

void finestra::zoomOut(){
     widgetCentrale->graficoElementi->scale(qreal(0.8), qreal(0.8));
}
