#include "finestra.h"

finestra::finestra(QWidget *parent) : QMainWindow(parent),widgetCentrale(new mainGui()),finestraBenvenuto(new wizard()){
    setWindowTitle("Kalk");
    setCentralWidget(widgetCentrale);
    QWidget* spaziatore1 = new QWidget(this);
    spaziatore1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QToolBar* tb = new QToolBar(this);
    barraFunzionalita* tbL = new barraFunzionalita(this,widgetCentrale);
    QAction* opzioni = new QAction("Opzioni",this);

    opzioni->setIcon(QIcon(":/icon/config.png"));

    tb->addWidget(spaziatore1);
    tb->addAction(opzioni);
    tb->setFloatable(false);
    tb->setMovable(false);

    addToolBar(Qt::LeftToolBarArea, tbL);
    addToolBar(tb);
    resize(700,500);
    finestraBenvenuto->show();
    finestraBenvenuto->resize(660,600);

    connect(opzioni,SIGNAL(triggered()),this,SLOT(showOption()));
}

void finestra::showOption(){
    finestraOpzioni = new impostazioni;
    loadSettings();
    finestraOpzioni->show();
}

void finestra::loadSettings(){
    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioColore");

    for(int i=0; i<3; i++)
        finestraOpzioni->vectorChangeColor[i][settings.value(QString::number(i)).toInt()]->setChecked(true);

    settings.endGroup();

    settings.beginGroup("cambioRange");
    finestraOpzioni->min->setText(settings.value("min").toString());
    finestraOpzioni->max->setText(settings.value("max").toString());
    settings.endGroup();

}

void finestra::closeEvent (QCloseEvent *event){
    QMessageBox::StandardButton exitBtn = QMessageBox::question(this,"",tr("Vuoi veramente uscire ?"),QMessageBox::No | QMessageBox::Yes);
    if (exitBtn != QMessageBox::Yes)
        event->ignore();
    else{
        event->accept();
        if(finestraOpzioni!=nullptr)
            delete finestraOpzioni;
        if(finestraBenvenuto!=nullptr)
            delete finestraBenvenuto;
    }
}
