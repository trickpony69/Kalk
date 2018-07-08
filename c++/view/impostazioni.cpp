#include "impostazioni.h"

impostazioni::impostazioni(QWidget *parent) : QWidget(parent),mainlayout(new QVBoxLayout(this)),titoloImpostazione0(new QHBoxLayout),settaggi(new QHBoxLayout()),titoloImpostazione1(new QHBoxLayout()),
   impostazione1(new QHBoxLayout()),min(new QLineEdit()),max(new QLineEdit()){

    setFixedSize(430,300);
    setWindowTitle("Impostazioni");    
    QLabel* scritta = new QLabel("Le impostazioni verranno salvate alla chiusura di questa finestra \n"
                                 "                       Ridisegna per vedere i cambiamenti");
    QLabel* scritta0 = new QLabel("                              Scegli i colori del grafico");
    QLabel* scritta1 = new QLabel("                              Cambia il range del grafico");
    QVector<QVector<QLabel*>> vectorColors(3);
    for(int i=0; i<3;++i){
        vectorColors[i].push_back(new QLabel("blu"));
        vectorColors[i].push_back(new QLabel("rosso"));
        vectorColors[i].push_back(new QLabel("verde"));
        buttonGroup.push_back(new QButtonGroup(this));
    }

    mainlayout->addWidget(scritta);
    titoloImpostazione0->addWidget(scritta0);
    titoloImpostazione1->addWidget(scritta1);
    mainlayout->addLayout(titoloImpostazione0);

    QVector<QVBoxLayout*> vectorSettings;
    setLayout(mainlayout);

    for(int i=0; i<3;++i){  //max slot = 3
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

    impostazione1->addWidget(min);
    impostazione1->addWidget(max);
    min->setFixedWidth(50);
    max->setFixedWidth(50);
    min->setPlaceholderText("min");
    max->setPlaceholderText("max");
    mainlayout->addLayout(impostazione1);

    setAttribute(Qt::WA_DeleteOnClose);

}

void impostazioni::closeEvent(QCloseEvent *event){
    saveSettings();
    event->accept();
}

void impostazioni::saveSettings(){

    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioColore");

    for(int k=0; k<3; k++){
        for(int i=0; i<vectorChangeColor.size(); i++){
            if(vectorChangeColor[k][i]->isChecked()){
                settings.setValue(QString::number(k),i);
            }
        }
    }

    settings.endGroup();

    settings.beginGroup("cambioRange");

    settings.setValue("min",min->text());
    settings.setValue("max",max->text());

    settings.endGroup();
}


