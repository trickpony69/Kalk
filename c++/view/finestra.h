#ifndef FINESTRA_H
#define FINESTRA_H

#include "view/impostazioni.h"
#include "view/mainGui.h"
#include <view/barrafunzionalita.h>

class finestra : public QMainWindow{
    Q_OBJECT
private:
    mainGui* widgetCentrale;
    QPointer<impostazioni> finestraOpzioni;
    QPointer<wizard> finestraBenvenuto;
    void loadSettings();
    void closeEvent(QCloseEvent*);
public:    
    explicit finestra(QWidget* parent = NULL);
private slots:
    void showOption();
};

#endif // FINESTRA_H
