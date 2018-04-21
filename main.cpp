#include "retta.h"
#include "razionale.h"
//#include <QApplication>
//#include <finestra.h>

// includere un entry point dove partire

int main(){
    razionale r(3,2);
      retta prova(r,-2,1);
      cout<<prova<<std::endl;
      vector<razionale> vr = prova.printCoord();
      for(int i=0;i<4;++i){
          cout<<vr[i]<<" ";
      }

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
}

//test gui grafica
/*int main(int argc, char* argv[]){

    QApplication app(argc, argv);

    finestra finestrone;

    finestrone.show();
    app.setAttribute(Qt::AA_DontShowIconsInMenus, false);
    return app.exec();
}*/
