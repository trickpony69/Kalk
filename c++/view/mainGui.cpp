#include <view/mainGui.h>

mainGui::mainGui(QWidget* p): QWidget(p), griglia(new QHBoxLayout()), add(new QPushButton("Aggiungi")), remove(new QPushButton("Rimuovi funzione")),
    enter(new QPushButton("        Disegna")), cancel(new QPushButton("Resetta input")),save(new QPushButton()),showSavedResult(new QPushButton()),
    savedResultWindow(new QListWidget()),hLay(new QHBoxLayout()), hFunLay(new QVBoxLayout()),graficoElementi(new grafico()), funEGrafico(new QHBoxLayout()){

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* superLayout = new QHBoxLayout();
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
    save->setStyleSheet("border: none;");
    save->setIconSize(iconSize);
    save->setToolTip("Salva il risultato");
    showSavedResult->setFixedSize(45,45);
    showSavedResult->setIcon(QPixmap(":icon/pasted.png"));
    showSavedResult->setIconSize(iconSize);
    showSavedResult->setStyleSheet("border: none;");
    showSavedResult->setToolTip("Mostra/nascondi i risultati");
    savedResultWindow->setDragEnabled(true);
    savedResultWindow->setFixedSize(150,300);
    QFont font("Verdana", 15);
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
    myQline* qle = new myQline();
    qle->setPlaceholderText("Slot "+QString::number(funVec.size()));
    qle->setAcceptDrops(true);
    funVec.push_back(qle);
    display = new QLineEdit(this);
    display->setDisabled(true);
    display->setText("      Seleziona una funzione nella barra laterale");
    display->setFixedSize(360,60);
    display->setStyleSheet("color: white;"
                           "background-color: RGB(53, 50, 47);"
                           "border-radius: 10px;");
    layoutDisplay = new QHBoxLayout();
    layoutDisplay->addWidget(display);
    layoutDisplay->addWidget(save);
    layoutDisplay->addWidget(showSavedResult);
    hFunLay->addWidget(qle);
    qle->setFixedSize(300,40);
    qle->setFont(font);
    funEGrafico->addLayout(hFunLay);
    griglia->addLayout(funEGrafico);
    //---------------GRAFICO----------------

            funEGrafico->addWidget(graficoElementi);

    //---------------------------------------------
    QObject::connect(add, SIGNAL(clicked(bool)), this, SLOT(push_qle()));
    QObject::connect(remove, SIGNAL(clicked(bool)), this, SLOT(remove_qle()));
    QObject::connect(enter, SIGNAL(clicked(bool)), this, SLOT(drawAndReturn()));
    QObject::connect(cancel, SIGNAL(clicked(bool)), this, SLOT(clearEntry()));
    QObject::connect(save, SIGNAL(clicked(bool)), this, SLOT(saveResult()));
    QObject::connect(showSavedResult, SIGNAL(clicked(bool)), this, SLOT(showResult()));

    mainLayout->addLayout(layoutDisplay);
    mainLayout->addLayout(separatorLayoutUp);
    mainLayout->addLayout(griglia);
    mainLayout->addLayout(separatorLayoutDown);
    mainLayout->addLayout(hLay);
    QHBoxLayout* layoutPasted = new QHBoxLayout();
    layoutPasted->addWidget(savedResultWindow);
    superLayout->addLayout(mainLayout);
    superLayout->addLayout(layoutPasted);
    savedResultWindow->hide();
    setLayout(superLayout);
}

void mainGui::push_qle(){

    if(funVec.size() <= 2){
        myQline* myQle = new myQline();
        myQle->setPlaceholderText("Slot "+QString::number(funVec.size()));
        funVec.push_back(myQle);
        hFunLay->addWidget(myQle);
        myQle->setFixedSize(300,40);
        myQle->setFont(QFont("Verdana",15));

        if(funVec.size() <= 1)
            remove->setDisabled(true);
        else remove->setDisabled(false);
        if(!funVec.size())
            enter->setDisabled(true);
        else enter->setDisabled(false);
    }
    else
        add->setDisabled(true);

    if(funVec.size()==3)
        funVec[2]->setPlaceholderText("Slot solo per disegno");
}

void mainGui::remove_qle(){
    if(funVec.size()-1>=1){
        hFunLay->removeWidget(funVec[funVec.size()-1]);
        if(graficoElementi->graph() && inputElemento.size()!=0){
            graficoElementi->graph()->data()->clear();
            graficoElementi->deletePol(funVec.size()-1);
            delete inputElemento[inputElemento.size()-1];
            inputElemento.remove(inputElemento.size()-1);
        }
        graficoElementi->replot();
        vectorLabel[funVec.size()-1]->clear();
        delete funVec[funVec.size()-1];
        funVec.remove(funVec.size()-1);
    }

    if(funVec.size() < 1)
        enter->setDisabled(false);

    if(funVec.size() <= 2)
        add->setDisabled(false);

    if(funVec.size() == 1)
        remove->setDisabled(true);
}

void mainGui::clearEntry(){

    clearInput();
    for(int i =0; i<funVec.size();i++)
        funVec[i]->clear();
    for(int i =0; i<vectorLabel.size();i++)
        vectorLabel[i]->clear();
}

void mainGui::clearInput(){
    returnToParse.clear();
    for(int i=0; i<inputElemento.size(); i++){
        delete inputElemento[i];
        inputElemento.remove(i);
        i--;
    }
    graficoElementi->pulisci();
    display->setText("      seleziona una funzione nella barra laterale");
}

void mainGui::drawAndReturn(){

    clearInput();

    cancel->setDisabled(false);

    for(int i = 0; i <funVec.size(); i++){
        QString input = funVec[i]->text();
        if(!input.isEmpty()){
            returnToParse.push_back(input);
        }
    }

    for(int k=0; k < returnToParse.size(); k++){
        inputitem* inp = NULL;
        graphicElement* elGraph = NULL;
        QString slotString("(Slot:"+QString::number(k)+") ");
        try{
             graficoElementi->addGraph();

             inp = inputitem::iniz_input(returnToParse[k].toStdString());
             elGraph = graphicElement::parsGraphicEl(inp);
             elGraph->drawing(graficoElementi,k);

             inputElemento.push_back(inp);

             for(int i=0; i<3; i++)
                 if(k==i)
                     loadColor(QString::number(i),k);

         graficoElementi->replot();
         vectorLabel[k]->clear();
         delete elGraph;
        }

        catch(input_error e){vectorLabel[k]->setText(slotString+QString::fromStdString(e.to_string_error()));}
        catch(irregular_pol e){vectorLabel[k]->setText(slotString+QString::fromStdString(e.to_string_error()));}
        catch(not_implicit e){vectorLabel[k]->setText(slotString+QString::fromStdString(e.to_string_error()));}
        catch(num_lati e){vectorLabel[k]->setText(slotString+QString::fromStdString(e.to_string_error()));}
        catch(...){vectorLabel[k]->setText(slotString+"Errore input.");}
    }
}

void mainGui::loadColor(QString slot,int index){
    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioColore");

    QMap<int,QPen> mappaColori;
    mappaColori.insert(0,QPen(Qt::blue));
    mappaColori.insert(1,QPen(Qt::red));
    mappaColori.insert(2,QPen(Qt::green));

    for(int k=0; k<3; k++){
        if(settings.value(slot).toInt() == k){
            graficoElementi->graph(index)->setPen(mappaColori[k]);
            for(int i=0; i<graficoElementi->getSize(index); i++){
                graficoElementi->readSegmenti(index,i)->setPen(mappaColori[k]);
            }
        }
    }
    settings.endGroup();
}

void mainGui::saveResult(){
    QListWidgetItem* itemList1 =new QListWidgetItem(display->displayText(),savedResultWindow);
    savedResultWindow->insertItem(0,itemList1);
}

void mainGui::showResult(){
    if(savedResultWindow->isHidden())
        savedResultWindow->show();
    else{
        savedResultWindow->hide();
    }
}

mainGui::~mainGui(){
    for(int i=0; i<inputElemento.size(); i++){
        delete inputElemento[i];   
    }
    graficoElementi->pulisci();
}
