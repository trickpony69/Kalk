#include "impostazioni.h"

impostazioni::impostazioni(QWidget *parent) : QWidget(parent){
    //setFixedSize(300,300);
    resize(200,200);
    setWindowTitle("Impostazioni");
    titoloImpostazione0 = new QHBoxLayout();
    titoloImpostazione1 = new QHBoxLayout();
    settaggi = new QHBoxLayout();
    primoSettaggio = new QVBoxLayout;
    secondoSettaggio = new QVBoxLayout;
    terzoSettaggio = new QVBoxLayout;
    mainlayout = new QVBoxLayout();
    QLabel* scritta0 = new QLabel("Scegli i colori del grafico");
    QLabel* scritta1 = new QLabel("Cambia il range del grafico");
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
    QLabel* colore02 = new QLabel("verde");
    QLabel* colore10 = new QLabel("blu");
    QLabel* colore11 = new QLabel("rosso");
    QLabel* colore12 = new QLabel("verde");
    QLabel* colore20 = new QLabel("blu");
    QLabel* colore21 = new QLabel("rosso");
    QLabel* colore22 = new QLabel("verde");
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
    titoloImpostazione0->addWidget(scritta0);
    titoloImpostazione1->addWidget(scritta1);
    mainlayout->addLayout(titoloImpostazione0);
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
        gruppo0.addButton(cambioColori0[i]);

    }
    secondoSettaggio->addWidget(slot1);
    for(unsigned int i=0; i<3; i++){
        secondoSettaggio->addWidget(labelColori1[i]);
        cambioColori1.push_back(new QRadioButton);
        secondoSettaggio->addWidget(cambioColori1[i]);
        gruppo1.addButton(cambioColori1[i]);

    }
    terzoSettaggio->addWidget(slot2);
    for(unsigned int i=0; i<3; i++){
        terzoSettaggio->addWidget(labelColori2[i]);
        cambioColori2.push_back(new QRadioButton);
        terzoSettaggio->addWidget(cambioColori2[i]);
        gruppo2.addButton(cambioColori2[i]);
    }

    mainlayout->addLayout(titoloImpostazione1);

    gruppo0.setExclusive(true);
    gruppo1.setExclusive(true);
    gruppo2.setExclusive(true);
    cambioColori0[0]->setChecked(true);
    cambioColori1[1]->setChecked(true);
    cambioColori2[2]->setChecked(true);

    loadSettings();

    //connect(cambioColori0[0],SIGNAL(clicked()),this,SLOT(setText()));
    //connect(cambioColori0[1],SIGNAL(clicked()),this,SLOT(setText_2()));
    //connect(cambioColori0[2],SIGNAL(clicked()),this,SLOT(setText_2()));

}

QVector<QLabel*> impostazioni::clone(QVector<QLabel*> v1){
    QVector<QLabel*> vett;
    for(unsigned int i=0; i<v1.size(); i++){
        auto contenuto = new QLabel(v1[i]);
        vett.push_back(contenuto);
    }
    return vett;
}

void impostazioni::closeEvent(QCloseEvent *event){
    saveSettings();
}

void impostazioni::saveSettings(){

    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioColore");
    for(unsigned int i=0; i<cambioColori0.size(); i++){
        if(cambioColori0[i]->isChecked())
            settings.setValue("primoSlot",i);
    }
    for(unsigned int i=0; i<cambioColori0.size(); i++){
        if(cambioColori1[i]->isChecked())
            settings.setValue("secondoSlot",i);
    }
    for(unsigned int i=0; i<cambioColori0.size(); i++){
        if(cambioColori2[i]->isChecked())
            settings.setValue("terzoSlot",i);
    }
    settings.endGroup();
    qDebug("impostazioni salvate");
}

void impostazioni::loadSettings(){
    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioColore");
    int ind0 = settings.value("primoSlot").toInt();
    cambioColori0[ind0]->setChecked(true);
    int ind1 = settings.value("secondoSlot").toInt();
    cambioColori1[ind1]->setChecked(true);
    int ind2 = settings.value("terzoSlot").toInt();
    cambioColori2[ind2]->setChecked(true);
    settings.endGroup();
    qDebug("impostazioni caricate");

}
