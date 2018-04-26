#include "impostazioni.h"

impostazioni::impostazioni(QWidget *parent) : QWidget(parent){
    show();
    resize(200,200);
    titolo = new QHBoxLayout();
    settaggi = new QHBoxLayout();
    primoSettaggio = new QVBoxLayout;
    secondoSettaggio = new QVBoxLayout;
    terzoSettaggio = new QVBoxLayout;
    layout = new QVBoxLayout();
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
    labelColori1.push_back(colore10);
    labelColori1.push_back(colore11);
    labelColori1.push_back(colore12);
    labelColori2.push_back(colore20);
    labelColori2.push_back(colore21);
    labelColori2.push_back(colore22);
    titolo->addWidget(scritta);
    layout->addLayout(titolo);
    settaggi->addLayout(primoSettaggio);
    settaggi->addLayout(secondoSettaggio);
    settaggi->addLayout(terzoSettaggio);
    layout->addLayout(settaggi);
    setLayout(layout);
    primoSettaggio->addWidget(slot0);
    for(unsigned int i=0; i<3; i++){
        primoSettaggio->addWidget(labelColori0[i]);
        cambioColori.push_back(new(QRadioButton));
        primoSettaggio->addWidget(cambioColori[i]);
    }
    secondoSettaggio->addWidget(slot1);
    for(unsigned int i=3,k=0; i<6,k<3; i++,k++){
        secondoSettaggio->addWidget(labelColori1[k]);
        cambioColori.push_back(new(QRadioButton));
        secondoSettaggio->addWidget(cambioColori[i]);
    }
    terzoSettaggio->addWidget(slot2);
    for(unsigned int i=6,k=0; i<9,k<3; i++,k++){
        terzoSettaggio->addWidget(labelColori2[k]);
        cambioColori.push_back(new(QRadioButton));
        terzoSettaggio->addWidget(cambioColori[i]);
    }
}

