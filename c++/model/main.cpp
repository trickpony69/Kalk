#include "retta.h"
#include "razionale.h"
#include <QApplication>
#include <view/finestra.h>
#include "eccezioni.h"
#include "quadrato.h"
#include "triangolo.h"
#include "inputitem.h"
#include <typeinfo>

using std::cout;
using std::endl;


int main(int argc, char *argv[]){

    QApplication app(argc, argv);
    finestra Kalk;


    Kalk.show();

    return app.exec();
}
