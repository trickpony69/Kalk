#include <mainGui.h>

mainGui::mainGui(const QString& qs, QWidget* p): QWidget(p), add(new QPushButton(qs)), remove(new QPushButton("rimuovi funzione")), enter(new QPushButton("calcola")), vLay(new QVBoxLayout()), hLay(new QHBoxLayout()), hFunLay(new QVBoxLayout()), mainLayout(new QVBoxLayout(this)),errorLabel(new QLabel("mi dispiace ma non puoi aggiungere più di 3 funzioni :(, daje accontentati")), graficoElementi(new grafico()),label0(new QLabel()),label1(new QLabel()),label2(new QLabel()){
    add->setFixedSize(140,40);
    remove->setFixedSize(140,40);
    enter->setFixedSize(140,40);
    /*--------------- PROVE GRAFICO----------------

                  Fatta classe graficoElementi

    ---------------------------------------------*/
    enter->setDisabled(true);
    remove->setDisabled(true);
    hLay->addWidget(add);
    hLay->addWidget(remove);
    hLay->addWidget(enter);
    hFunLay->addWidget(graficoElementi);
    vLay->addWidget(label0);
    vLay->addWidget(label1);
    vLay->addWidget(label2);
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

void mainGui::clear(){
    if(returnInput.size()!=0)
        qDebug("non lo è ");

    for(int i = 0; i<returnInput.size(); i++)
        delete returnInput[i];

    returnInput.clear();

    if(returnInput.size()==0)
        qDebug("vuoto");
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
    if(!vec.isEmpty()){
        hFunLay->removeWidget(vec[vec.size()-1]);
        delete vec[vec.size()-1];
        vec.remove((vec.size())-1);
    }
    if(vec.isEmpty())
        qDebug("vec vuoto");

    if(vec.size() <= 2)
        errorLabel->setVisible(false);

    if(vec.size() < 1)
        enter->setDisabled(false);

    if(vec.size() <= 2)
        add->setDisabled(false);

    if(vec.size() == 0)
        remove->setDisabled(true);
}

void mainGui::returnedInput(){

    clear();

    for(unsigned int i = 0; i <vec.size(); i++){
        QString* entry = new QString(vec[i]->text());
        returnInput.push_back(entry);
        //retta r;
        //r.pars_rect(entry->toStdString());
        //std::cout<<r;
    }
    QFont font("Arial", 25);
    if(returnInput.size()>0){
        label0->setText(*returnInput[0]);
        label0->setFont(font);
    }
    if((returnInput.size()>1)){
        label1->setText(*returnInput[1]);
        label1->setFont(font);
    }

    if((returnInput.size()>2)){
        label2->setText(*returnInput[2]);
        label2->setFont(font);
    }


}

