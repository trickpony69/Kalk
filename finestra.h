#ifndef FINESTRA_H
#define FINESTRA_H

#include <mainGui.h>
#include <QAction>
#include "impostazioni.h"
#include <QMessageBox>
#include "wizard.h"

class finestra : public QMainWindow{
    Q_OBJECT
private:
    mainGui* widgetCentrale;
    QPointer<impostazioni> finestraOpzioni;
    QPointer<wizard> finestraBenvenuto;
    void loadSettings();
    void closeEvent(QCloseEvent*);
public:    
    explicit finestra(QWidget *parent = NULL);//explicit o no ?
    ~finestra();
private slots:
    void showOption();
};

#endif // FINESTRA_H
