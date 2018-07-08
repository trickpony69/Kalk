#include "barrafunzionalita.h"

barraFunzionalita::barraFunzionalita(QWidget* parent,mainGui* g): QToolBar(parent), gui(g),spaziatoreTab(new QAction("",this)), inter(new QAction("Intersezione",this)),
    rect2Punti(new QAction("Retta passante tra due punti",this)),dist2elem(new QAction("Distanza tra due elementi",this)),
    areaGener (new QAction("Area",this)),perimetroGener( new QAction("Perimetro",this)),
    perp (new QAction("Retta perpendicolare dato punto e retta",this)),
    paral(new QAction("Retta parallela dato punto e retta",this)){

    spaziatoreTab->setDisabled(true);

    inter->setIcon(QIcon(":/icon/intersect.png"));
    rect2Punti->setIcon(QIcon(":/icon/rect2Points.png"));
    dist2elem->setIcon(QIcon(":/icon/dist2Rect.png"));
    areaGener->setIcon(QIcon(":/icon/area.png"));
    perimetroGener->setIcon(QIcon(":/icon/perimeter.png"));
    perp->setIcon(QIcon(":/icon/perpendicular.png"));
    paral->setIcon(QIcon(":/icon/parallels.png"));

    addAction(spaziatoreTab);
    addAction(inter);
    addAction(rect2Punti);
    addAction(dist2elem);
    addAction(perimetroGener);
    addAction(areaGener);
    addAction(perp);
    addAction(paral);

    setFloatable(false);
    setMovable(false);

    connect(inter,SIGNAL(triggered()),this,SLOT(intersezione()));
    connect(rect2Punti,SIGNAL(triggered()),this,SLOT(rect2Points()));
    connect(dist2elem,SIGNAL(triggered()),this,SLOT(dist2item()));
    connect(areaGener,SIGNAL(triggered()),this,SLOT(area()));
    connect(perimetroGener,SIGNAL(triggered()),this,SLOT(perimetro()));
    connect(paral,SIGNAL(triggered()),this,SLOT(paralsrettapunt()));
    connect(perp,SIGNAL(triggered()),this,SLOT(perpuntoretta()));
}

//--------------------------Funzionalità barra laterale--------------------------
//---questi slot fanno uso del modello perchè non ritornano soluzioni grafiche---
void barraFunzionalita::intersezione(){
    if(gui->inputElemento.size() > 1){
        vector<punto> inter = gui->inputElemento[0]->intersect(gui->inputElemento[1]);

        if( inter.size() > 0 ){
            QString c = '('+QString::fromStdString(inter[0].toString())+')';
            for(unsigned int i = 1 ; i < inter.size() ; ++i){
                c = c+'('+QString::fromStdString(inter[i].toString())+')';
            }
            gui->display->setText(c);

        }
        else gui->display->setText("Non si intersecano");
    }
    else gui->display->setText("Non sono stati inseriti due elementi");

}

void barraFunzionalita::rect2Points(){
    if(gui->inputElemento.size() == 2){
        if(punto* punto0 = dynamic_cast<punto*>(gui->inputElemento[0])){
            if(punto* punto1 = dynamic_cast<punto*>(gui->inputElemento[1])){
                retta risultato = risultato.rettaFromTwoPoints(*punto0,*punto1);
                gui->display->setText(QString::fromStdString(risultato.toString()));
            }
        }
    }
    else gui->display->setText("Non sono stati inseriti due punti");

}


void barraFunzionalita::dist2item(){
    if(gui->inputElemento.size() >= 2){
        double dist = gui->inputElemento[0]->distance(gui->inputElemento[1]);
        gui->display->setText(QString::number(dist));
    }
    else gui->display->setText("Non sono stati inseriti due elementi");
}

void barraFunzionalita::area(){
    if(gui->inputElemento.size() > 0){
        if(poligono* pol = dynamic_cast<poligono*>(gui->inputElemento[0]))
        {
            double a = pol->area();
            gui->display->setText(QString::number(a));
        }
        else gui->display->setText("Non è stato inserito un poligono");
    }
    else gui->display->setText("Non sono stati inseriti elementi");
}

void barraFunzionalita::perimetro(){
    if(gui->inputElemento.size() > 0){
        if(poligono* pol = dynamic_cast<poligono*>(gui->inputElemento[0]))
        {
            double p = pol->perimetro();
            gui->display->setText(QString::number(p));
        }
        else gui->display->setText("Non è stato inserito un poligono");
    }
    else gui->display->setText("Non sono stati inseriti elementi");
}

void barraFunzionalita::paralsrettapunt() {
    if(gui->inputElemento.size() > 1 )
    {
        punto * p;
        retta* ret = dynamic_cast<retta*>(gui->inputElemento[0]);
        if(ret){
             p = dynamic_cast<punto*>(gui->inputElemento[1]);
        }
        else{
            ret = dynamic_cast<retta*>(gui->inputElemento[1]);
            p = dynamic_cast<punto*>(gui->inputElemento[0]);
        }
        if(ret && p){
            retta par = ret->RettaParallela(*p);
            gui->display->setText(QString::fromStdString(par.toString()));
        }
        else gui->display->setText("Non sono stati inseriti retta e punto");
    }
    else gui->display->setText("Non sono stati inseriti elementi");
}

void barraFunzionalita::perpuntoretta() {
    if(gui->inputElemento.size() > 1 )
    {
        punto * p;
        retta* ret = dynamic_cast<retta*>(gui->inputElemento[0]);
        if(ret){
             p = dynamic_cast<punto*>(gui->inputElemento[1]);
        }
        else{
            ret = dynamic_cast<retta*>(gui->inputElemento[1]);
            p = dynamic_cast<punto*>(gui->inputElemento[0]);
        }
        if(ret && p){
            retta perp = ret->RettaPerpendicolare(*p);
            gui->display->setText(QString::fromStdString(perp.toString()));
        }
        else gui->display->setText("Non sono stati inseriti retta e punto");

    }
    else gui->display->setText("Non sono stati inseriti retta e punto");
}


