#include <mainGui.h>

mainGui::mainGui(const QString& qs, QWidget* p): QWidget(p), add(new QPushButton(qs, this)), remove(new QPushButton("rimuovi funzione", this)), enter(new QPushButton("calcola",this)), vLay(new QVBoxLayout(this)), hLay(new QHBoxLayout(this)), hFunLay(new QVBoxLayout()), mainLayout(new QVBoxLayout(this)),errorLabel(new QLabel("mi dispiace ma non puoi aggiungere più di 3 funzioni :(, daje accontentati")){
    add->setFixedSize(140,60);
    remove->setFixedSize(140,60);
    enter->setFixedSize(140,60);
    enter->setDisabled(true);
    remove->setDisabled(true);
    hLay->addWidget(add);
    hLay->addWidget(remove);
    hLay->addWidget(enter);
    QObject::connect(add, SIGNAL(clicked(bool)), this, SLOT(push_qle()));//QObject::connect(m.b, SIGNAL(clicked(bool)), &m, SLOT(push_qle()));
    QObject::connect(remove, SIGNAL(clicked(bool)), this, SLOT(remove_qle()));
    QObject::connect(enter, SIGNAL(clicked(bool)), this, SLOT(returnedInput()));
    mainLayout->addLayout(vLay);
    mainLayout->addLayout(hLay);
    mainLayout->addLayout(hFunLay);
    setLayout(mainLayout);
    this->setWindowTitle("mok");
    this->show();
    resize(700,300);
}

void mainGui::push_qle(){
    if(vec.size() <= 2){
        QLineEdit* qle = new QLineEdit(this);
        qle->setPlaceholderText("inserisci la funzione");
        vec.push_back(qle);
        hFunLay->addWidget(qle);
        QFont font("Arial", 25);
        qle->setFixedSize(300,60);
        qle->setFont(font);
    }
    else{
        add->setDisabled(true);
        hLay->addWidget(errorLabel);
    }

    if(vec.size() <= 1)
        remove->setDisabled(true);
    else remove->setDisabled(false);

    if(vec.size() < 1)
        enter->setDisabled(true);
    else enter->setDisabled(false);
}

void mainGui::remove_qle(){
    if(vec.size() > 1){
        hFunLay->removeWidget(vec[vec.size()-1]);
        delete vec[vec.size()-1];
        vec.remove((vec.size())-1);

        /*if(vec.size() < 2){
            hLay->removeWidget(errorLabel);
            qDebug("toglie il messaggio d'errore");
        }*/
    }
    if(vec.size() < 1)
        enter->setDisabled(false);

    if(vec.size() <= 2)
        add->setDisabled(false);

    if(vec.size() == 1)
        remove->setDisabled(true);
}

void mainGui::returnedInput(){
    for(unsigned int i = 0; i < vec.size(); i++){
        QString* entry = new QString(vec[i]->displayText());
        returnInput.push_back(entry);
    }
    for(unsigned int i = 0; i < returnInput.size(); i++)
        qDebug(returnInput[i]->toLatin1());
}
