#include "retta.h"
// includere un entry point dove partire

int main(){

    punto p1(2,4);
    punto p2(5,6);
    retta r1(2,3,0);
    retta r2(2,5,5);
    retta rp = retta::rettaFromTwoPoints(p1,p2); //da un errore strano
    cout<<"p1"<<p1<<"p2"<<p2;
    cout<<"r1 "<<r1;
    cout<<"r2 "<<r2;
    cout<<"la distanza tra p1 e r1 e' "<<retta::distancePuntoRetta(p1,r1)<<std::endl;//stesso errore di rettaFromTwoPoints
    cout<<"la retta tra p1 e p2 e' "<<rp;
    cout<<"la distanza tra p1 e p2 e' "<<punto::distanceTwoPoints(p1,p2)<<std::endl;
    if(retta::isParallels(r1,r2)){
        std::cout<<"la distanza tra r1 e r2 e' "<<r1.distanceRettaRetta(r2)<<std::endl;
    }else std::cout<<"Le rette sono incidenti nel punto : "/*<<r1.incidentRettaRetta(r2)*/<<std::endl;

    cout<<std::endl;
    razionale rz1(7,4),rz2(5,8);

    cout<<"stampo due razionali "<<std::endl<<rz1<<rz2<<"li moltiplico "<<razionale(7,4)*razionale(5,8)<<"e li converto a double "<<(rz1*rz2).converti()<<std::endl;
}

/*primi test gui grafica
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Horizontal layout with 3 buttons
    QHBoxLayout *hLayout = new QHBoxLayout;
    QPushButton *b1 = new QPushButton("A");
    QPushButton *b2 = new QPushButton("B");
    QPushButton *b3 = new QPushButton("C");
    hLayout->addWidget(b1);
    hLayout->addWidget(b2);
    hLayout->addWidget(b3);

//    // Vertical layout with 3 buttons
//    QVBoxLayout *vLayout = new QVBoxLayout;
//    QPushButton *b4 = new QPushButton("D");
//    QPushButton *b5 = new QPushButton("E");
//    QPushButton *b6 = new QPushButton("F");
//    vLayout->addWidget(b4);
//    vLayout->addWidget(b5);
//    vLayout->addWidget(b6);

//    // Outer Layer
    QVBoxLayout *mainLayout = new QVBoxLayout;

//    // Add the previous two inner layouts
    mainLayout->addLayout(hLayout);
//    mainLayout->addLayout(vLayout);

    // Create a widget
    QWidget *w = new QWidget();

    // Set the outer layout as a main layout of the widget
    w->setLayout(mainLayout);

    // Window title
    w->setWindowTitle("layouts");

    // Display
    w->show();

    // Event loop
    return app.exec();
}*/
