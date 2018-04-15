#ifndef FINESTRA_H
#define FINESTRA_H

#include <mainGui.h>

class finestra : public QMainWindow{
    Q_OBJECT
private:
    mainGui* widgetCentrale;
public:
    explicit finestra(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // FINESTRA_H
