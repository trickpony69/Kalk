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
        myQle->setFont(QFont("Arial", 15));

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
        if(graficoElementi->graph()){
            graficoElementi->graph()->data()->clear();
            if(dynamic_cast<inputitem*>(inputElemento[inputElemento.size()-1]))
                graficoElementi->deletePol(funVec.size()-1);
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
            QString entry(funVec[i]->text());
            returnToParse.push_back(entry);
        }
    }

    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioRange");

    razionale min(-30,1);
    razionale max(30,1);

    if(settings.value("min").toInt())
        min=razionale(settings.value("min").toInt(),1);
    if(settings.value("max").toInt())
        max=razionale(settings.value("max").toInt(),1);

    settings.endGroup();

    for(int k=0; k < returnToParse.size(); k++){
        inputitem* inp;
        QString slotString("(Slot:"+QString::number(k)+") ");
        try{
             graficoElementi->addGraph();
             inp = inputitem::iniz_input(returnToParse[k].toStdString());
             if(retta* pol = dynamic_cast<retta*>(inp)){
                //--------------inizio refactor----------------------
                 auto pointRetta = pol->print_rect(min,max);
                 rettaGraph rettaRappr(graficoElementi,pointRetta[0],pointRetta[1]);
                 rettaRappr.drawing(k);

                 inputElemento.push_back(pol);
             }
             else if(punto* pun = dynamic_cast<punto*>(inp)){

                puntoGraph puntoRappr(graficoElementi,pun);
                puntoRappr.drawing(k);

                inputElemento.push_back(pun); //serve ancora ??

                //---------------------------------------------------
             }
             else if(poligono* pol = dynamic_cast<poligono*>(inp)){

                 vector<punto*> vCoord0 = pol->getpoint(); //copia profonda del vector

                 int p = 0 ;

                 for(unsigned int i=0; i<vCoord0.size(); i++)
                    graficoElementi->writeSegmenti(k,new QCPItemLine(graficoElementi));

                 for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
                     for(unsigned int j = i + 1; j<vCoord0.size(); j++){
                        if(vCoord0[j]->distanceTwoPoints(*vCoord0[i]) == pol->lato() || vCoord0.size() == 3){
                            graficoElementi->readSegmenti(k,p)->start->setCoords(QPointF(vCoord0[i]->getX(),vCoord0[i]->getY()));
                            graficoElementi->readSegmenti(k,p)->end->setCoords(QPointF(vCoord0[j]->getX(),vCoord0[j]->getY()));
                            ++p;
                        }
                     }
                 }

                 for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
                     delete vCoord0[i];  //aggiunto nel remake, nessuno si occupava del garbage di VCoord0 mi pare
                 }

                graficoElementi->replot();

                inputElemento.push_back(pol);
            }

         if(k==0)
            loadColor("primoSlot",k);
         else if(k==1)
            loadColor("secondoSlot",k);
         else if(k==2)
            loadColor("terzoSlot",k);

         graficoElementi->replot();
         vectorLabel[k]->clear();
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

    if(settings.value(slot).toInt() == 0){
        graficoElementi->graph(index)->setPen(QPen(Qt::blue));
        for(int i=0; i<graficoElementi->getSize(index); i++){
            graficoElementi->readSegmenti(index,i)->setPen((QPen(Qt::blue)));
        }
    }

    else if(settings.value(slot).toInt() == 1){
        graficoElementi->graph(index)->setPen((QPen(Qt::red)));
        for(int i=0; i<graficoElementi->getSize(index); i++){
            graficoElementi->readSegmenti(index,i)->setPen((QPen(Qt::red)));
        }
    }
    else if(settings.value(slot).toInt() == 2){
        graficoElementi->graph(index)->setPen((QPen(Qt::green)));
        for(int i=0; i<graficoElementi->getSize(index); i++){
            graficoElementi->readSegmenti(index,i)->setPen((QPen(Qt::green)));
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

//------------------Funzionalità barra laterale------------------

void mainGui::intersezione(){
    if(inputElemento.size() > 1){
        vector<punto> inter = inputElemento[0]->intersect(inputElemento[1]);

        if( inter.size() > 0 ){
            QString c = '('+QString::fromStdString(inter[0].toString())+')';
            for(unsigned int i = 1 ; i < inter.size() ; ++i){
                c = c+'('+QString::fromStdString(inter[i].toString())+')';
            }
            display->setText(c);

        }
        else display->setText("Non si intersecano");
    }
    else display->setText("Non sono stati inseriti due elementi");

}

void mainGui::rect2Points(){
    if(inputElemento.size() == 2){
        if(punto* punto0 = dynamic_cast<punto*>(inputElemento[0])){
            if(punto* punto1 = dynamic_cast<punto*>(inputElemento[1])){
                retta risultato = risultato.rettaFromTwoPoints(*punto0,*punto1);
                display->setText(QString::fromStdString(risultato.toString()));
            }
        }
    }
    else display->setText("Non sono stati inseriti due punti");

}


void mainGui::dist2item(){
    if(inputElemento.size() >= 2){
        double dist = inputElemento[0]->distance(inputElemento[1]);
        display->setText(QString::number(dist));
    }
    else display->setText("Non sono stati inseitri due elementi");
}

void mainGui::area(){
    if(inputElemento.size() > 0){
        if(poligono* pol = dynamic_cast<poligono*>(inputElemento[0]))
        {
            double a = pol->area();
            display->setText(QString::number(a));
        }
        else display->setText("Non è stato inserito un poligono");
    }
    else display->setText("Non sono stati inseriti elementi");
}

void mainGui::perimetro(){
    if(inputElemento.size() > 0){
        if(poligono* pol = dynamic_cast<poligono*>(inputElemento[0]))
        {
            double p = pol->perimetro();
            display->setText(QString::number(p));
        }
        else display->setText("Non è stato inserito un poligono");
    }
    else display->setText("Non sono stati inseriti elementi");
}

void mainGui::paralsrettapunt() {
    if(inputElemento.size() > 1 )
    {
        punto * p;
        retta* ret = dynamic_cast<retta*>(inputElemento[0]);
        if(ret){
             p = dynamic_cast<punto*>(inputElemento[1]);
        }
        else{
            ret = dynamic_cast<retta*>(inputElemento[1]);
            p = dynamic_cast<punto*>(inputElemento[0]);
        }
        if(ret && p){
            retta par = ret->RettaParallela(*p);
            display->setText(QString::fromStdString(par.toString()));
        }
        else display->setText("Non sono stati inseriti retta e punto");
    }
    else display->setText("Non sono stati inseriti elementi");
}

void mainGui::perppuntoretta() {
    if(inputElemento.size() > 1 )
    {
        punto * p;
        retta* ret = dynamic_cast<retta*>(inputElemento[0]);
        if(ret){
             p = dynamic_cast<punto*>(inputElemento[1]);
        }
        else{
            ret = dynamic_cast<retta*>(inputElemento[1]);
            p = dynamic_cast<punto*>(inputElemento[0]);
        }
        if(ret && p){
            retta perp = ret->RettaPerpendicolare(*p);
            display->setText(QString::fromStdString(perp.toString()));
        }
        else display->setText("Non sono stati inseriti retta e punto");

    }
    else display->setText("Non sono stati inseriti retta e punto");
}

