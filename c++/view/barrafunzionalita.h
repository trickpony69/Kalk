#ifndef BARRAFUNZIONALITA_H
#define BARRAFUNZIONALITA_H

#include <QToolBar>
#include <QAction>
#include <view/finestra.h>

class barraFunzionalita : public QToolBar{
    Q_OBJECT
public:
    barraFunzionalita(QWidget* = NULL,mainGui* = NULL);
private:
    mainGui* gui;
    QAction* spaziatoreTab;
    QAction* inter;
    QAction* rect2Punti;
    QAction* dist2elem;
    QAction* areaGener;
    QAction* perimetroGener;
    QAction* perp;
    QAction* paral;
private slots:
    void intersezione();
    void rect2Points();
    void dist2item();
    void area();
    void perimetro();
    void paralsrettapunt();
    void perpuntoretta();
};

#endif // BARRAFUNZIONALITA_H
