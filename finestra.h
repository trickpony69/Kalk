#ifndef FINESTRA_H
#define FINESTRA_H

#include <mainGui.h>
#include <QAction>
#include "impostazioni.h"
#include <QMessageBox>

class finestra : public QMainWindow{
    Q_OBJECT
private:
    mainGui* widgetCentrale;
    impostazioni* finestraOpzioni;
    void setColorBlue(int);
    void setColorRed(int);
    void setColorGreen(int);
    void loadSettings();
    void closeEvent(QCloseEvent*);
public:    
    explicit finestra(QWidget *parent = NULL);//explicit o no ?
private slots:
    void showOption();
};

#endif // FINESTRA_H
