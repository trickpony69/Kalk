#include "impostazioni.h"

impostazioni::impostazioni(QWidget *parent) : QWidget(parent){
    show();
    resize(200,200);
    titolo = new QHBoxLayout();
    settaggi = new QHBoxLayout();
    primoSettaggio = new QVBoxLayout;
    secondoSettaggio = new QVBoxLayout;
    terzoSettaggio = new QVBoxLayout;
    mainlayout = new QVBoxLayout();
    QLabel* scritta = new QLabel("Scegli i colori per il grafico");
    colori.push_back(Qt::blue);
    colori.push_back(Qt::red);
    colori.push_back(Qt::green);
    QLabel* slot0 = new QLabel("Primo slot");
    QLabel* slot1 = new QLabel("Secondo slot");
    QLabel* slot2 = new QLabel("Terzo slot");
    QVector<QLabel*> labelColori0;
    QVector<QLabel*> labelColori1;
    QVector<QLabel*> labelColori2;
    QLabel* colore00 = new QLabel("blu");
    QLabel* colore01 = new QLabel("rosso");
    QLabel* colore02 = new QLabel("vedre");
    QLabel* colore10 = new QLabel("blu");
    QLabel* colore11 = new QLabel("rosso");
    QLabel* colore12 = new QLabel("vedre");
    QLabel* colore20 = new QLabel("blu");
    QLabel* colore21 = new QLabel("rosso");
    QLabel* colore22 = new QLabel("vedre");
    labelColori0.push_back(colore00);
    labelColori0.push_back(colore01);
    labelColori0.push_back(colore02);
    //labelColori1 = clone(labelColori0);//non funziona, forse non si può clonare un QRadioButton
    labelColori1.push_back(colore10);
    labelColori1.push_back(colore11);
    labelColori1.push_back(colore12);
    labelColori2.push_back(colore20);
    labelColori2.push_back(colore21);
    labelColori2.push_back(colore22);
    titolo->addWidget(scritta);
    mainlayout->addLayout(titolo);
    settaggi->addLayout(primoSettaggio);
    settaggi->addLayout(secondoSettaggio);
    settaggi->addLayout(terzoSettaggio);
    mainlayout->addLayout(settaggi);
    setLayout(mainlayout);
    primoSettaggio->addWidget(slot0);
    for(unsigned int i=0; i<3; i++){
        primoSettaggio->addWidget(labelColori0[i]);
        cambioColori0.push_back(new QRadioButton);
        primoSettaggio->addWidget(cambioColori0[i]);
    }
    secondoSettaggio->addWidget(slot1);
    for(unsigned int i=0; i<3; i++){
        secondoSettaggio->addWidget(labelColori1[i]);
        cambioColori1.push_back(new QRadioButton);
        secondoSettaggio->addWidget(cambioColori1[i]);
    }
    terzoSettaggio->addWidget(slot2);
    for(unsigned int i=0; i<3; i++){
        terzoSettaggio->addWidget(labelColori2[i]);
        cambioColori2.push_back(new QRadioButton);
        terzoSettaggio->addWidget(cambioColori2[i]);
    }
    //cambioColori0[0]->setAutoExclusive(false);
    //cambioColori0[1]->setAutoExclusive(false);
    //cambioColori0[2]->setAutoExclusive(false);
    //cambioColori1[0]->setAutoExclusive(false);
    //cambioColori1[1]->setAutoExclusive(false);
    //cambioColori1[2]->setAutoExclusive(false);
    //cambioColori2[0]->setAutoExclusive(false);

}

QVector<QLabel*> impostazioni::clone(QVector<QLabel*> v1){
    QVector<QLabel*> vett;
    for(unsigned int i=0; i<v1.size(); i++){
        auto contenuto = new QLabel(v1[i]);
        vett.push_back(contenuto);
    }
}
