#include "impostazioni.h"

impostazioni::impostazioni(QWidget *parent) : QWidget(parent){
    setFixedSize(430,300);
    setWindowTitle("Impostazioni");
    titoloImpostazione0 = new QHBoxLayout();
    titoloImpostazione1 = new QHBoxLayout();
    settaggi = new QHBoxLayout();
    mainlayout = new QVBoxLayout();
    QLabel* scritta = new QLabel("Le impostazioni verranno salvate alla chiusura di questa finestra",this);
    QLabel* scritta0 = new QLabel("                              Scegli i colori del grafico",this);
    QLabel* scritta1 = new QLabel("                              Cambia il range del grafico",this);

    QVector<QVector<QLabel*>> vectorColors(3);
    for(int i=0; i<3;++i){
        vectorColors[i].push_back(new QLabel("blu",this));
        vectorColors[i].push_back(new QLabel("rosso",this));
        vectorColors[i].push_back(new QLabel("verde",this));
        buttonGroup.push_back(new QButtonGroup());
    }

    mainlayout->addWidget(scritta);
    titoloImpostazione0->addWidget(scritta0);
    titoloImpostazione1->addWidget(scritta1);
    mainlayout->addLayout(titoloImpostazione0);

    QVector<QVBoxLayout*> vectorSettings;
    setLayout(mainlayout);

    for(int i=0; i<3;++i){
        vectorSettings.push_back(new QVBoxLayout());
        vectorSettings[i]->addWidget(new QLabel(QString("SLOT "+ QString::number(i))));
        vectorChangeColor.push_back(QVector<QRadioButton*>());
        for(int j=0; j<3;++j){
            vectorSettings[i]->addWidget(vectorColors[i][j]);
            vectorChangeColor[i].push_back(new QRadioButton());
            vectorSettings[i]->addWidget(vectorChangeColor[i][j]);
            buttonGroup[i]->addButton(vectorChangeColor[i][j]);
        }
        buttonGroup[i]->setExclusive(true);
        vectorChangeColor[i][0]->setChecked(true);
        settaggi->addLayout(vectorSettings[i]);
    }

    mainlayout->addLayout(settaggi);
    mainlayout->addLayout(titoloImpostazione1);

    impostazione1 = new QHBoxLayout(this);
    min = new QLineEdit(this);
    max = new QLineEdit(this);
    impostazione1->addWidget(min);
    impostazione1->addWidget(max);
    min->setFixedWidth(50);
    max->setFixedWidth(50);
    min->setPlaceholderText("min");
    max->setPlaceholderText("max");
    mainlayout->addLayout(impostazione1);
}

void impostazioni::closeEvent(QCloseEvent *event){
    saveSettings();
    event->accept();
}

void impostazioni::saveSettings(){

    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioColore");

    for(int i=0; i<vectorChangeColor.size(); i++)
        if(vectorChangeColor[0][i]->isChecked())
            settings.setValue("primoSlot",i);
    for(int i=0; i<vectorChangeColor.size(); i++)
        if(vectorChangeColor[1][i]->isChecked())
            settings.setValue("secondoSlot",i);
    for(int i=0; i<vectorChangeColor.size(); i++)
        if(vectorChangeColor[2][i]->isChecked())
            settings.setValue("terzoSlot",i);

    settings.endGroup();

    settings.beginGroup("cambioRange");

    settings.setValue("min",min->text());
    settings.setValue("max",max->text());

    settings.endGroup();

    qDebug("impostazioni salvate");
}


