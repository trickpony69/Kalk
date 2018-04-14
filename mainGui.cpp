#include <mainGui.h>

mainGui::mainGui(const QString& qs, QWidget* p): QWidget(p), add(new QPushButton(qs, this)), remove(new QPushButton("rimuovi funzione", this)), vLay(new QVBoxLayout(this)), hLay(new QHBoxLayout(this)), hFunLay(new QVBoxLayout()), mainLayout(new QVBoxLayout(this)),vecButton(0), errorLabel(new QLabel("mi dispiace ma non puoi più di 3 aggiungere funzioni :(, daje accontentati")){
    hLay->addWidget(add);
    hLay->addWidget(remove);
    add->setFixedSize(140,60);
    remove->setFixedSize(140,60);
    QObject::connect(add, SIGNAL(clicked(bool)), this, SLOT(push_qle()));//QObject::connect(m.b, SIGNAL(clicked(bool)), &m, SLOT(push_qle()));
    QObject::connect(remove, SIGNAL(clicked(bool)), this, SLOT(remove_qle()));
    mainLayout->addLayout(vLay);
    mainLayout->addLayout(hLay);
    mainLayout->addLayout(hFunLay);
    setLayout(mainLayout);
    this->setWindowTitle("mok");
    this->show();
    resize(700,300);
}

void mainGui::push_qle(){
    if(vec.size() < 3){
        QLineEdit* qle = new QLineEdit(this);
        qle->setPlaceholderText("inserisci la funzione");
        vec.push_back(qle);
        hFunLay->addWidget(qle);

        QPushButton* b = new QPushButton("conferma");
        vecButton.push_back(b);
        hFunLay->addWidget(b);
    }
    else{
        add->setDisabled(true);
        hLay->addWidget(errorLabel);
    }

    if(vec.size() == 1)
        remove->setDisabled(true);
    else remove->setDisabled(false);
}

void mainGui::remove_qle(){
    if(vec.size() > 1){
        hFunLay->removeWidget(vec[vec.size()-1]);
        hFunLay->removeWidget(vecButton[vecButton.size()-1]);
        vec.removeLast();
        vecButton.removeLast();
        if(vec.size() < 3)
            add->setDisabled(false);

        if(vec.size() == 1)
            remove->setDisabled(true);
        else remove->setDisabled(false);

        /*if(vec.size() < 2){
            hLay->removeWidget(errorLabel);
            qDebug("toglie il messaggio d'errore");
        }*/
    }
}
