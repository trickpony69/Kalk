#include "retta.h"
#include "razionale.h"
#include <QApplication>
#include <finestra.h>
#include "eccezioni.h"
#include "quadrato.h"
#include "triangolo.h"
#include "pentagono.h"
#include "inputitem.h"
#include <typeinfo>

using std::cout;
using std::endl;


//int main(){

//      //input elemento

//      string st;
//      std::cout<<"dai:"<<std::endl;
//      std::getline(cin, st);

//      inputitem* p = inputitem::iniz_input(st);

//      p->isFigura();

//      if(poligono* pol = dynamic_cast<poligono*>(p)){
//        cout<<pol<<endl;
//        if( pol->lato() != 0 ) cout<<"lato : "<<pol->lato()<<endl;
//        else cout<<"triangolo non regolare";
//        cout<<"perimetro: "<<pol->perimetro()<<endl;
//        cout<<"area: "<<pol->area()<<endl;
//      }


//}



//      if(poligono* pol = dynamic_cast<poligono*>(p)){
//          cout<<pol->perimetro()<<endl;
//      }

      /*if(dynamic_cast<quadrato*>(p)){
          cout<<"quadrato: ";
      }
      else if(dynamic_cast<pentagono*>(p)){
          cout<<"pentagono: ";
      }
      else if(dynamic_cast<triangolo*>(p)){
          cout<<"triangolo: ";
      }
      cout<<"triangolo: ";*/


//}
//    punto p1(-2,3);
//    punto p2(1,-5);
//    retta r1(-7,3,2);
//    retta r2(8,-4,-6);
//    retta rp = retta::rettaFromTwoPoints(p1,p2); //da un errore strano
//    cout<<"p1"<<p1<<"p2"<<p2;
//    cout<<"r1 "<<r1;
//    cout<<"r2 "<<r2;
//    cout<<"la distanza tra p1 e r1 e' "<<retta::distancePuntoRetta(p1,r1)<<std::endl;//stesso errore di rettaFromTwoPoints
//    cout<<"la retta tra p1 e p2 e' "<<rp<<std::endl;
//    cout<<"la distanza tra p1 e p2 e' "<<punto::distanceTwoPoints(p1,p2)<<std::endl;
//    if(retta::isParallels(r1,r2)){
//        std::cout<<"la distanza tra r1 e r2 e' "<<r1.distanceRettaRetta(r2)<<std::endl;
//    }else{
//        std::cout<<"Le rette"<<r1<<" "<<r2;
//        if(retta::isPerpendicolari(r1,r2))
//            std::cout<<"sono PERPENDICOLARI nel punto";
//        else
//            std::cout<<"sono incidenti nel punto";
//        cout<<r1.Intersect(r1,r2)<<std::endl;
//    }
//    punto p3(0,-3);
//    razionale a(1,3);
//    retta r3(a,-1,1);
//    cout<<"retta passante per "<<p3<<" e perpendicolare a "<<r3<<" : "<<retta::RettaPerpendicolare(r3,p3)<<std::endl;
//    cout<<"retta passante per "<<p3<<" e parallela a "<<r3<<" : "<<retta::RettaParallella(r3,p3)<<std::endl;

//    cout<<std::endl;
//    razionale rz1(7,4),rz2(5,8);

//    cout<<"stampo due razionali "<<std::endl<<rz1<<std::endl<<rz2<<std::endl<<"li moltiplico "<<razionale(7,4)*razionale(5,8)<<"e li converto a double "<<(rz1*rz2).converti()<<std::endl;
//    cout<<" prova con costruttore "<<razionale(-10,-4)<<std::endl;
//}

//gui grafica
int main(int argc, char *argv[]){

    QApplication app(argc, argv);
    finestra Kalk;

    QWizard finestraBenvenuto;
    QWizardPage* welcome = new QWizardPage;
    QVBoxLayout* mainLayout=new QVBoxLayout;
    QLabel* label = new QLabel("Ciao ! Sono il tuo Kalkulon."
                                "Alla tua destra vedrai due tre slot, con i primi due puoi usare le funzioni che troverai sulla tua destra mentre con l'ultima puoi solo disegnare. "
                                "in Alto a destra troverai le impostazioni."
                                " Con l'icona Paste potrai vedere i tuoi risultati salvati dal display e potrai riusarli con un semplice drag and drop sullo slot che deciderai");
    label->setWordWrap(true);
    mainLayout->addWidget(label);
    welcome->setLayout(mainLayout);
    finestraBenvenuto.setWindowTitle("Benvenuto");
    finestraBenvenuto.addPage(welcome);

    Kalk.show();
    finestraBenvenuto.show();
    return app.exec();
}
