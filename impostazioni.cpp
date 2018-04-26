#include "impostazioni.h"

impostazioni::impostazioni(QWidget *parent) : QWidget(parent){
    show();
    resize(200,200);
    titolo = new QHBoxLayout();
    primoSettaggio = new QVBoxLayout;
    layout = new QVBoxLayout();
    QLabel* scritta = new QLabel("Scegli i colori per il grafico");
    QLabel* slot1 = new QLabel("Primo slot");

    titolo->addWidget(scritta);
    layout->addLayout(titolo);
    layout->addLayout(primoSettaggio);
    setLayout(layout);
    primoSettaggio->addWidget(slot1);
    for(unsigned int i=0; i<3; i++){
        primoSettaggio->addWidget(new QLabel("Colore"));
        cambioColori.push_back(new(QRadioButton));
        primoSettaggio->addWidget(cambioColori[i]);
   }
}

