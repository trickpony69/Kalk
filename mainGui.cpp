#include <mainGui.h>

mainGui::mainGui(const QString& qs, QWidget* p): QWidget(p), add(new QPushButton(qs, this)), remove(new QPushButton("rimuovi funzione", this)), enter(new QPushButton("calcola",this)), vLay(new QVBoxLayout(this)), hLay(new QHBoxLayout(this)), hFunLay(new QVBoxLayout()), mainLayout(new QVBoxLayout(this)),errorLabel(new QLabel("mi dispiace ma non puoi aggiungere più di 3 funzioni :(, daje accontentati")), graficoElementi(new grafico()),label(NULL){
    add->setFixedSize(140,60);
    remove->setFixedSize(140,60);
    enter->setFixedSize(140,60);
    /*--------------- PROVE GRAFICO----------------

                  Fatta classe graficoElementi

    ---------------------------------------------*/
    enter->setDisabled(true);
    remove->setDisabled(true);
    hLay->addWidget(add);
    hLay->addWidget(remove);
    hLay->addWidget(enter);
    hFunLay->addWidget(graficoElementi);
    QFrame* myFrame = new QFrame();
    myFrame->setFrameShape(QFrame::HLine);
    vLay->addWidget(myFrame);
    QObject::connect(add, SIGNAL(clicked(bool)), this, SLOT(push_qle()));//QObject::connect(m.b, SIGNAL(clicked(bool)), &m, SLOT(push_qle()));
    QObject::connect(remove, SIGNAL(clicked(bool)), this, SLOT(remove_qle()));
    QObject::connect(enter, SIGNAL(clicked(bool)), this, SLOT(returnedInput()));
    mainLayout->addLayout(hLay);
    mainLayout->addLayout(vLay);
    mainLayout->addLayout(hFunLay);
    setLayout(mainLayout);
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
        vLay->addWidget(errorLabel);
        errorLabel->setVisible(true);
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
    }

    if(vec.size() <= 2)
        errorLabel->setVisible(false);

    if(vec.size() < 1)
        enter->setDisabled(false);

    if(vec.size() <= 2)
        add->setDisabled(false);

    if(vec.size() == 1)
        remove->setDisabled(true);
}

void mainGui::returnedInput(){
    if(label) {vLay->removeWidget(label); delete label;}
    for(unsigned int i = 0; i < vec.size(); i++){
        QString* entry = new QString(vec[i]->displayText());
        returnInput.push_back(entry);
        retta r;
        r.pars_rect(entry->toStdString());
        std::cout<<r;
        label = new QLabel(*entry);
        vLay->addWidget(label);
    }

}

