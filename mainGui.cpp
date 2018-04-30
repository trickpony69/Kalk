#include <mainGui.h>

mainGui::mainGui(const QString& qs, QWidget* p): QWidget(p), griglia(new QHBoxLayout), add(new QPushButton(qs)), remove(new QPushButton("rimuovi funzione")), enter(new QPushButton("   calcola")), cancel(new QPushButton("resetta input")), vLay(new QVBoxLayout()), hLay(new QHBoxLayout()), hFunLay(new QVBoxLayout()), mainLayout(new QVBoxLayout(this)),errorLabel(new QLabel("mi dispiace ma non puoi aggiungere più di 3 funzioni :(, daje accontentati")), graficoElementi(new grafico()), funEGrafico(new QHBoxLayout), label0(new QLabel()),label1(new QLabel()),label2(new QLabel()){
    remove->setDisabled(true);
    cancel->setDisabled(true);
    QSize iconSize(40,40);
    add->setIcon(QPixmap(":/icon/add.png"));
    add->setIconSize(iconSize);
    add->setFixedSize(175,60);
    remove->setIcon(QPixmap(":icon/delete.png"));
    remove->setIconSize(iconSize);
    remove->setFixedSize(175,60);
    enter->setIcon(QPixmap(":icon/apply.png"));
    enter->setIconSize(iconSize);
    enter->setFixedSize(175,60);
    cancel->setIcon(QPixmap(":icon/reset.png"));
    cancel->setIconSize(iconSize);
    cancel->setFixedSize(175,60);
    QFont font("Arial", 25);
    label0->setFont(font);
    label1->setFont(font);
    label2->setFont(font);
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
    qle->setFixedSize(300,60);
    qle->setFont(font);
    funEGrafico->addLayout(hFunLay);
    griglia->addLayout(funEGrafico);

    //---------------GRAFICO----------------

            funEGrafico->addWidget(graficoElementi);

    //---------------------------------------------
    QObject::connect(add, SIGNAL(clicked(bool)), this, SLOT(push_qle()));
    QObject::connect(remove, SIGNAL(clicked(bool)), this, SLOT(remove_qle()));
    QObject::connect(enter, SIGNAL(clicked(bool)), this, SLOT(returnedInput()));
    QObject::connect(cancel, SIGNAL(clicked(bool)), graficoElementi, SLOT(pulisci()));
    QObject::connect(cancel, SIGNAL(clicked(bool)), this, SLOT(clearEntry()));
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
    graficoElementi->clearGraphs(); //non sono sicuro serva

    for(unsigned int i = 0; i <vec.size(); i++){
        QString input = vec[i]->text();
        if(!input.isEmpty()){
            QString* entry = new QString(vec[i]->text());
            returnInput.push_back(entry);
        }
    }

    retta r0,r1,r2;
    punto p0,p1,p2;
    razionale min(-30,1);
    razionale max(30,1);



     if(returnInput.size() > 0){
        try{
             graficoElementi->addGraph();
             r0.pars_rect(returnInput[0]->toStdString());
        }
        catch(int){
             qDebug("primo slot: input corretto ");
             vector<punto> vCoord0 = print_rect(r0,min,max);
             QVector<double> x(60), y(60); // initialize with entries 0..100
             for (unsigned int i=0; i<vCoord0.size(); i++){
                 x[i] = vCoord0[i].getX();
                 y[i] = vCoord0[i].getY();
             }

             loadColor("primoSlot",0);

             graficoElementi->graph(0)->setData(x, y);
             graficoElementi->replot();
             label0->setText(*returnInput[0]);
        }
        catch(input_error){
            try{
                p0.pars_point(returnInput[0]->toStdString());
            }
            catch(int){
                 //vector<punto> vCoord0Point =
                 QVector<double> x, y; // initialize with entries 0..100
                 //for (unsigned int i=0; i<vCoord0Point.size(); i++){
                     x[0] = p0.getX();
                     y[0] = p0.getY();
                 //}

                 loadColor("primoSlot",0);

                 graficoElementi->graph(0)->setData(x,y);
                 graficoElementi->replot();
                 label0->setText(*returnInput[0]);
            }

            catch(input_error){
                qDebug("primo slot: errore input");
                label0->setText("errore input");
            }
         }
     }
     if(returnInput.size() > 1){
        try{
            graficoElementi->addGraph();
            r1.pars_rect(returnInput[1]->toStdString());
        }
        catch(int){
            vector<punto> vCoord0 = print_rect(r1,min,max);
            QVector<double> x(60), y(60); // initialize with entries 0..100
            for (unsigned int i=0; i<vCoord0.size(); i++){
                x[i] = vCoord0[i].getX();
                y[i] = vCoord0[i].getY();
            }

            loadColor("secondoSlot",1);

            graficoElementi->graph(1)->setData(x, y);
            graficoElementi->replot();
            label1->setText(*returnInput[1]);
        }

        catch(input_error){
             qDebug("secondo slot: errore input");
             label1->setText("errore input");

        }

    }
    if(returnInput.size() > 2){
        try{
            graficoElementi->addGraph();
            r2.pars_rect(returnInput[2]->toStdString());
        }
        catch(int){
            vector<punto> vCoord0 = print_rect(r2,min,max);
            QVector<double> x(60), y(60); // initialize with entries 0..100
            for (unsigned int i=0; i<vCoord0.size(); i++){
                x[i] = vCoord0[i].getX();
                y[i] = vCoord0[i].getY();
            }

            loadColor("terzoSlot",2);

            graficoElementi->graph(2)->setData(x, y);
            graficoElementi->replot();
            label2->setText(*returnInput[2]);
        }
        catch(input_error){
            qDebug("terzo slot: errore input");
            label2->setText("errore input");
        }
      }
}

void mainGui::clearEntry(){
    for(unsigned int i=0; i<vec.size(); i++)
        vec[i]->clear();
    label0->clear();
    label1->clear();
    label2->clear();
}

//per ora distanza standard tra i punti : 1 cm (modificabile ??)
vector<punto> mainGui::print_rect(retta& r , razionale& min , razionale& max){
    vector<punto> pt;
    razionale start = min;
    if(r.GetB() == 0){
        for(; start < max ; start = start + razionale(1,1)){
            punto p(razionale(-1,1)*razionale(r.GetC(),r.GetA()),start);
            pt.push_back(p);
        }
    }
    else{
        for(; start < max ; start = start + razionale(1,1)){
            pt.push_back(r.printCoord_x(start));
        }
    }
    return pt;
}

void mainGui::loadColor(QString slot,int index){
    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioColore");

    if(settings.value(slot).toInt() == 0)
        graficoElementi->graph(index)->setPen(QPen(Qt::blue));
    else if(settings.value(slot).toInt() == 1)
        graficoElementi->graph(index)->setPen((QPen(Qt::red)));
    else if(settings.value(slot).toInt() == 2)
        graficoElementi->graph(index)->setPen((QPen(Qt::green)));
    settings.endGroup();
    qDebug("colori caricati");

}

