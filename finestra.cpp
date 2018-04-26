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
    QAction* opzioni = new QAction("opzioni",this);
    tb->addAction("aiuto");
    tb->addAction(opzioni);
    tb->setFloatable(false);
    tb->setMovable(false);
    addToolBar(tb);
    resize(700,500);
    connect(opzioni,SIGNAL(triggered()),this,SLOT(showOption()));
}

void finestra::showOption(){

    QWidget* finestraOpzioni = new impostazioni();
}
