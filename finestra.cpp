#include "finestra.h"

finestra::finestra(QWidget *parent) : QMainWindow(parent),widgetCentrale(new mainGui){
    setWindowTitle("mok");
    setCentralWidget(widgetCentrale);

}
