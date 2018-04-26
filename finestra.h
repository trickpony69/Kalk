#ifndef FINESTRA_H
#define FINESTRA_H

#include <mainGui.h>
#include <QAction>
#include "impostazioni.h"

class finestra : public QMainWindow{
    Q_OBJECT
private:
    mainGui* widgetCentrale;
public:
    explicit finestra(QWidget *parent = NULL);//explicit o no ?
public slots:
    void showOption();
};

#endif // FINESTRA_H
