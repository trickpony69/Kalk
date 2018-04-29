#ifndef FINESTRA_H
#define FINESTRA_H

#include <mainGui.h>
#include <QAction>
#include "impostazioni.h"

class finestra : public QMainWindow{
    Q_OBJECT
private:
    mainGui* widgetCentrale;
    impostazioni* finestraOpzioni;
    void setColorBlue(int);
    void setColorRed(int);
    void setColorGreen(int);
    void loadSettings();
public:    
    explicit finestra(QWidget *parent = NULL);//explicit o no ?
public slots:
    void showOption();
    void setColorBlueFirstSlot();
    void setColorBlueSecondSlot();
    void setColorBlueThirdSlot();
    void setColorRedFirstSlot();
    void setColorRedSecondSlot();
    void setColorRedThirdSlot();
    void setColorGreenFirstSlot();
    void setColorGreenSecondSlot();
    void setColorGreenThirdSlot();
};

#endif // FINESTRA_H
