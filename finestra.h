#ifndef FINESTRA_H
#define FINESTRA_H

#include <mainGui.h>
#include <QAction>
class finestra : public QMainWindow{
    Q_OBJECT
private:
    mainGui* widgetCentrale;
public:
    explicit finestra(QWidget *parent = nullptr);//explicit o no ?
public slots:
    void zoomIn();
    void zoomOut();
};

#endif // FINESTRA_H
