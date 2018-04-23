#include <mainGui.h>

mainGui::mainGui(const QString& qs, QWidget* p): QWidget(p), griglia(new QHBoxLayout), add(new QPushButton(qs)), remove(new QPushButton("rimuovi funzione")), enter(new QPushButton("calcola")), cancel(new QPushButton("cancella grafico")), vLay(new QVBoxLayout()), hLay(new QHBoxLayout()), hFunLay(new QVBoxLayout()), mainLayout(new QVBoxLayout(this)),errorLabel(new QLabel("mi dispiace ma non puoi aggiungere più di 3 funzioni :(, daje accontentati")), graficoElementi(new grafico()), funEGrafico(new QHBoxLayout), label0(new QLabel()),label1(new QLabel()),label2(new QLabel()){
    add->setFixedSize(140,40);
    remove->setFixedSize(140,40);
    enter->setFixedSize(140,40);
    remove->setDisabled(true);
    cancel->setDisabled(true);
    cancel->setFixedSize(140,40);
    //add->setStyleSheet("border-image:url(:/Users/micky/Documents/Kalk/add.png);");
    setStyleSheet("QLineEdit { border-style: outset; border-width: 0.5px; border-color: grey; border-radius: 8px; }");
    hLay->addWidget(add);
    hLay->addWidget(remove);
    hLay->addWidget(enter);
    hLay->addWidget(cancel);
    hFunLay->addWidget(label0);
    hFunLay->addWidget(label1);
    hFunLay->addWidget(label2);
    QFrame* myFrame = new QFrame();
    myFrame->setFrameShape(QFrame::HLine);
    vLay->addWidget(myFrame);
    QLineEdit* qle = new QLineEdit();
    qle->setPlaceholderText("inserisci la funzione");
    vec.push_back(qle);
    hFunLay->addWidget(qle);
    QFont font("Arial", 25);
    qle->setFixedSize(300,60);
    qle->setFont(font);
    funEGrafico->addLayout(hFunLay);
    griglia->addLayout(funEGrafico);
    //--------------- PROVE GRAFICO----------------

            funEGrafico->addWidget(graficoElementi);

    //---------------------------------------------
    QObject::connect(add, SIGNAL(clicked(bool)), this, SLOT(push_qle()));//QObject::connect(m.b, SIGNAL(clicked(bool)), &m, SLOT(push_qle()));
    QObject::connect(remove, SIGNAL(clicked(bool)), this, SLOT(remove_qle()));
    QObject::connect(enter, SIGNAL(clicked(bool)), this, SLOT(returnedInput()));
    QObject::connect(cancel, SIGNAL(clicked(bool)), graficoElementi->scene, SLOT(clear()));
    mainLayout->addLayout(hLay);
    mainLayout->addLayout(griglia);
    mainLayout->addLayout(vLay);
    setLayout(mainLayout);
}

void mainGui::clearInput(){
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

    cancel->setDisabled(false);

    clearInput();

    for(unsigned int i = 0; i <vec.size(); i++){
        QString input = vec[i]->text();
        if(!input.isEmpty()){
            QString* entry = new QString(vec[i]->text());
            returnInput.push_back(entry);
        }
    }

    retta r0,r1,r2;

     if(returnInput.size() > 0){
        r0.pars_rect(returnInput[0]->toStdString());
        vector<razionale> vCoord0 = r0.printCoord();
        graficoElementi->scene->addLine(vCoord0[0],vCoord0[1],vCoord0[2],vCoord0[3]);
     }

    if(returnInput.size() > 1){
        r1.pars_rect(returnInput[1]->toStdString());
        vector<razionale> vCoord1 = r1.printCoord();
        graficoElementi->scene->addLine(vCoord1[0],vCoord1[1],vCoord1[2],vCoord1[3]);
    }

    if(returnInput.size() > 2){
        r2.pars_rect(returnInput[2]->toStdString());
        vector<razionale> vCoord2 = r2.printCoord();
        graficoElementi->scene->addLine(vCoord2[0],vCoord2[1],vCoord2[2],vCoord2[3]);
    }

    QFont font("Arial", 25);
    if(returnInput.size()>0){
        label0->setText(*returnInput[0]);
        label0->setFont(font);
    }
    else label0->clear();

    if((returnInput.size()>1)){
        label1->setText(*returnInput[1]);
        label1->setFont(font);
    }
    else label1->clear();

    if((returnInput.size()>2)){
        label2->setText(*returnInput[2]);
        label2->setFont(font);
    }
    else label2->clear();
}
