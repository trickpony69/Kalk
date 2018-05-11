#include <mainGui.h>

mainGui::mainGui(const QString& qs, QWidget* p): QWidget(p), griglia(new QHBoxLayout), add(new QPushButton(qs)), remove(new QPushButton("rimuovi funzione")), enter(new QPushButton("        disegna")), cancel(new QPushButton("resetta input")),save(new QPushButton()),showSavedResult(new QPushButton(this)),savedResultWindow(new QListWidget()),hLay(new QHBoxLayout()), hFunLay(new QVBoxLayout()), mainLayout(new QVBoxLayout(this)),errorLabel(new QLabel("mi dispiace ma non puoi aggiungere più di 3 funzioni :(, daje accontentati")), graficoElementi(new grafico()), funEGrafico(new QHBoxLayout){
    remove->setDisabled(true);
    cancel->setDisabled(true);
    QSize iconSize(35,35);
    add->setIcon(QPixmap(":/icon/add.png"));
    add->setIconSize(iconSize);
    add->setFixedSize(175,55);
    remove->setIcon(QPixmap(":icon/delete.png"));
    remove->setIconSize(iconSize);
    remove->setFixedSize(175,55);
    enter->setIcon(QPixmap(":icon/draw.png"));
    enter->setIconSize(iconSize);
    enter->setFixedSize(175,55);
    cancel->setIcon(QPixmap(":icon/reset.png"));
    cancel->setIconSize(iconSize);
    cancel->setFixedSize(175,55);
    save->setFixedSize(45,45);
    save->setIcon(QPixmap(":icon/save.png"));
    save->setIconSize(iconSize);
    save->setToolTip("salva il risultato");
    showSavedResult->setFixedSize(45,45);
    showSavedResult->setIcon(QPixmap(":icon/pasted.png"));
    showSavedResult->setIconSize(iconSize);
    showSavedResult->setToolTip("mostra/nascondi i risultati");
    savedResultWindow->setDragEnabled(true);
    QFont font("Arial", 25);
    for(unsigned int i=0; i<3; i++){
        vectorLabel.push_back(new QLabel());
        vectorLabel[i]->setFont(font);
        hFunLay->addWidget(vectorLabel[i]);
    }
    setStyleSheet("QLineEdit { border-style: outset; border-width: 0.5px; border-color: grey; border-radius: 8px; }");
    hLay->addWidget(add);
    hLay->addWidget(remove);
    hLay->addWidget(enter);
    hLay->addWidget(cancel);
    QFrame* myFrame0 = new QFrame();
    myFrame0->setFrameShape(QFrame::HLine);
    QFrame* myFrame1 = new QFrame();
    myFrame1->setFrameShape(QFrame::HLine);
    QVBoxLayout* separatorLayoutUp = new QVBoxLayout();
    QVBoxLayout* separatorLayoutDown = new QVBoxLayout();
    separatorLayoutUp->addWidget(myFrame0);
    separatorLayoutDown->addWidget(myFrame1);
    QLineEdit* qle = new QLineEdit();
    qle->setPlaceholderText("inserisci la funzione");
    qle->setAcceptDrops(true);
    vec.push_back(qle);
    display = new QLineEdit();
    display->setDisabled(true);
    display->setPlaceholderText("seleziona una funzione nella barra laterale");
    display->setFixedSize(350,40);
    display->setStyleSheet("color: white;"
                           "background-color: RGB(53, 50, 47);"
                           "border-radius: 10px;");
    layoutDisplay = new QHBoxLayout();
    layoutDisplay->addWidget(display);
    layoutDisplay->addWidget(save);
    layoutDisplay->addWidget(showSavedResult);
    hFunLay->addWidget(qle);
    qle->setFixedSize(300,60);
    qle->setFont(font);
    funEGrafico->addLayout(hFunLay);
    griglia->addLayout(funEGrafico);
    QListWidget *datiSalvati = new QListWidget();
    datiSalvati->setDragEnabled(true);
    datiSalvati->setDropIndicatorShown(true);
    //---------------GRAFICO----------------

            funEGrafico->addWidget(graficoElementi);

    //---------------------------------------------
    QObject::connect(add, SIGNAL(clicked(bool)), this, SLOT(push_qle()));
    QObject::connect(remove, SIGNAL(clicked(bool)), this, SLOT(remove_qle()));
    QObject::connect(enter, SIGNAL(clicked(bool)), this, SLOT(returnedInput()));
    QObject::connect(cancel, SIGNAL(clicked(bool)), graficoElementi, SLOT(pulisci()));
    QObject::connect(cancel, SIGNAL(clicked(bool)), this, SLOT(clearEntry()));
    QObject::connect(save, SIGNAL(clicked(bool)), this, SLOT(saveResult()));
    QObject::connect(showSavedResult, SIGNAL(clicked(bool)), this, SLOT(showResult()));
    mainLayout->addLayout(layoutDisplay);
    mainLayout->addLayout(separatorLayoutUp);
    mainLayout->addLayout(griglia);
    mainLayout->addLayout(separatorLayoutDown);
    mainLayout->addLayout(hLay);
    mainLayout->addWidget(savedResultWindow);
    savedResultWindow->hide();
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
        //vLay->addWidget(errorLabel);
        //errorLabel->setVisible(true);
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
        if(graficoElementi->graph(vec.size()-1))
            graficoElementi->graph(vec.size()-1)->data()->clear();
        graficoElementi->replot();
        delete vec[vec.size()-1];
        vec.remove((vec.size())-1);
    }
    if(vec.isEmpty())
        qDebug("vec vuoto");

    if(vec.size() <= 2)
        //errorLabel->setVisible(false);

    if(vec.size() < 1)
        enter->setDisabled(false);

    if(vec.size() <= 2)
        add->setDisabled(false);

    if(vec.size() == 0)
        remove->setDisabled(true);
}

void mainGui::returnedInput(){

    returnInput.clear();
    display->clear();
    inputElemento.clear();

    cancel->setDisabled(false);

    clearInput();
    graficoElementi->clearGraphs();

    for(unsigned int i = 0; i <vec.size(); i++){
        QString input = vec[i]->text();
        if(!input.isEmpty()){
            QString* entry = new QString(vec[i]->text());
            returnInput.push_back(entry);
        }
    }

    razionale min(-30,1);
    razionale max(30,1);

     for(unsigned int k=0; k < returnInput.size(); k++){
        inputitem* inp;
        try{
             graficoElementi->addGraph();
             inp = inputitem::iniz_input(returnInput[k]->toStdString());
             if(retta* pol = dynamic_cast<retta*>(inp)){
                 vector<punto> vCoord0 = pol->print_rect(min,max);
                 QVector<double> x(60), y(60);
                 for (unsigned int i=0; i<vCoord0.size(); i++){
                     x[i] = vCoord0[i].getX();
                     y[i] = vCoord0[i].getY();
                 }

                 if(k==0)
                    loadColor("primoSlot",k);
                 else if(k==1)
                    loadColor("secondoSlot",k);
                 else if(k==2)
                    loadColor("terzoSlot",k);

                 graficoElementi->graph(k)->setData(x,y);
                 graficoElementi->replot();
                 vectorLabel[k]->setText(*returnInput[k]);
                 inputElemento.push_back(pol);
             }
             else if(punto* pun = dynamic_cast<punto*>(inp)){

                 QVector<double> x, y;

                 x.append(pun->xToDouble());
                 y.append(pun->yToDouble());

                 if(k==0)
                    loadColor("primoSlot",k);
                 else if(k==1)
                    loadColor("secondoSlot",k);
                 else if(k==2)
                    loadColor("terzoSlot",k);

                 graficoElementi->graph(k)->setData(x,y);
                 graficoElementi->graph(k)->setLineStyle(QCPGraph::lsNone);
                 graficoElementi->graph(k)->setScatterStyle(QCPScatterStyle::ssDisc);
                 graficoElementi->replot();
                 vectorLabel[k]->setText(*returnInput[k]);
                 inputElemento.push_back(pun);
             }
        }
        catch(input_error){vectorLabel[k]->setText("errore input");}
        catch(irregular_pol){vectorLabel[k]->setText("errore input");}
     }
}

void mainGui::clearEntry(){
    for(unsigned int i=0; i<vec.size(); i++){
        vec[i]->clear();
        vectorLabel[i]->clear();
    }

    display->clear();

}

void mainGui::intersezione(){
    if(inputElemento.size() > 1){

        retta* r1;
        retta* r2;
        r1 = dynamic_cast<retta*>(inputElemento[0]);
        r2 = dynamic_cast<retta*>(inputElemento[1]);
        if(r1,r2){
            punto inters = retta::Intersect(*r1,*r2);
            display->setText("le rette si intersecano nel punto: ("+inters.toString()+')');
        }
        else{display->setText("in uno dei due slot non c'e' una retta");}
    }
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

void mainGui::saveResult(){
    QListWidgetItem* itemList =new QListWidgetItem("prova");

    savedResultWindow->insertItem(0,itemList);
}

void mainGui::showResult(){
    if(savedResultWindow->isHidden())
        savedResultWindow->show();
    else savedResultWindow->hide();

}
