#include "finestra.h"

finestra::finestra(QWidget *parent) : QMainWindow(parent),widgetCentrale(new mainGui){
    setWindowTitle("mok");
    setCentralWidget(widgetCentrale);
    finestraOpzioni = new impostazioni();
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
    loadSettings();
    connect(opzioni,SIGNAL(triggered()),this,SLOT(showOption()));
    connect(finestraOpzioni->cambioColori0[0],SIGNAL(clicked()),this,SLOT(setColorBlueFirstSlot()));
    connect(finestraOpzioni->cambioColori0[1],SIGNAL(clicked()),this,SLOT(setColorRedFirstSlot()));
    connect(finestraOpzioni->cambioColori0[2],SIGNAL(clicked()),this,SLOT(setColorGreenFirstSlot()));
    connect(finestraOpzioni->cambioColori1[0],SIGNAL(clicked()),this,SLOT(setColorBlueSecondSlot()));
    connect(finestraOpzioni->cambioColori1[1],SIGNAL(clicked()),this,SLOT(setColorRedSecondSlot()));
    connect(finestraOpzioni->cambioColori1[2],SIGNAL(clicked()),this,SLOT(setColorGreenSecondSlot()));
    connect(finestraOpzioni->cambioColori2[0],SIGNAL(clicked()),this,SLOT(setColorBlueThirdSlot()));
    connect(finestraOpzioni->cambioColori2[1],SIGNAL(clicked()),this,SLOT(setColorRedSecondSlot()));
    connect(finestraOpzioni->cambioColori2[2],SIGNAL(clicked()),this,SLOT(setColorGreenThirdSlot()));
}

void finestra::showOption(){
    finestraOpzioni->show();
}

void finestra::setColorBlueFirstSlot(){
    setColorBlue(0);
}
void finestra::setColorBlueSecondSlot(){
    setColorBlue(1);
}
void finestra::setColorBlueThirdSlot(){
    setColorBlue(2);
}
void finestra::setColorRedFirstSlot(){
    setColorRed(0);
}
void finestra::setColorRedSecondSlot(){
    setColorRed(1);
}
void finestra::setColorRedThirdSlot(){
    setColorRed(2);
}
void finestra::setColorGreenFirstSlot(){
    setColorGreen(0);
}
void finestra::setColorGreenSecondSlot(){
    setColorGreen(1);
}
void finestra::setColorGreenThirdSlot(){
    setColorGreen(2);
}

void finestra::setColorBlue(int slot){
    if(widgetCentrale->graficoElementi->graphCount()>slot)
        widgetCentrale->graficoElementi->graph(slot)->setPen(QPen(Qt::blue));

        widgetCentrale->graficoElementi->replot();
}
void finestra::setColorRed(int slot){
    if(widgetCentrale->graficoElementi->graphCount()>slot)
        widgetCentrale->graficoElementi->graph(slot)->setPen(QPen(Qt::red));

        widgetCentrale->graficoElementi->replot();
}
void finestra::setColorGreen(int slot){
    if(widgetCentrale->graficoElementi->graphCount()>slot)
        widgetCentrale->graficoElementi->graph(slot)->setPen(QPen(Qt::green));

        widgetCentrale->graficoElementi->replot();
}

void finestra::loadSettings(){
    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioColore");
    int ind0 = settings.value("primoSlot").toInt();
    finestraOpzioni->cambioColori0[ind0]->setChecked(true);
    int ind1 = settings.value("secondoSlot").toInt();
    finestraOpzioni->cambioColori1[ind1]->setChecked(true);
    int ind2 = settings.value("terzoSlot").toInt();
    finestraOpzioni->cambioColori2[ind2]->setChecked(true);
    settings.endGroup();
    qDebug("impostazioni caricate");
}
