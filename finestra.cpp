#include "finestra.h"

finestra::finestra(QWidget *parent) : QMainWindow(parent),widgetCentrale(new mainGui(this)),finestraOpzioni(new impostazioni()){
    setWindowTitle("Kalk");
    setCentralWidget(widgetCentrale);
    QWidget* spaziatore1 = new QWidget(this);
    spaziatore1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QToolBar* tb = new QToolBar(this);
    QToolBar* tbL = new QToolBar(this);
    QAction* spaziatoreTab = new QAction("",this);
    QAction* opzioni = new QAction("opzioni",this);
    QAction* inter = new QAction("intersezione",this);
    QAction* rect2Points = new QAction("retta passante tra due punti",this);
    QAction* dist2item = new QAction("distanza tra due elementi",this);

    spaziatoreTab->setDisabled(true);

    opzioni->setIcon(QIcon(":/icon/config.png"));
    inter->setIcon(QIcon(":/icon/intersect.png"));
    rect2Points->setIcon(QIcon(":/icon/rect2Points.png"));
    dist2item->setIcon(QIcon(":/icon/dist2Rect.png"));

    tb->addWidget(spaziatore1);
    tb->addAction(opzioni);
    tb->setFloatable(false);
    tb->setMovable(false);

    tbL->addAction(spaziatoreTab);
    tbL->addAction(inter);
    tbL->addAction(rect2Points);
    tbL->addAction(dist2item);
    tbL->setFloatable(false);
    tbL->setMovable(false);

    addToolBar(Qt::LeftToolBarArea, tbL);
    addToolBar(tb);
    resize(700,500);
    loadSettings();

    connect(opzioni,SIGNAL(triggered()),this,SLOT(showOption()));
    connect(inter,SIGNAL(triggered()),widgetCentrale,SLOT(intersezione()));
    connect(rect2Points,SIGNAL(triggered()),widgetCentrale,SLOT(rect2Points()));
    connect(dist2item,SIGNAL(triggered()),widgetCentrale,SLOT(dist2item()));
}

void finestra::showOption(){
    finestraOpzioni->show();
}

void finestra::loadSettings(){
    QSettings settings("Kalk","configKalk");
    settings.beginGroup("cambioColore");
    int ind0 = settings.value("primoSlot").toInt();
    finestraOpzioni->vectorChangeColor[0][ind0]->setChecked(true);
    int ind1 = settings.value("secondoSlot").toInt();
    finestraOpzioni->vectorChangeColor[1][ind1]->setChecked(true);
    int ind2 = settings.value("terzoSlot").toInt();
    finestraOpzioni->vectorChangeColor[2][ind2]->setChecked(true);
    settings.endGroup();

    settings.beginGroup("cambioRange");
    finestraOpzioni->min->setText(settings.value("min").toString());
    finestraOpzioni->max->setText(settings.value("max").toString());
    settings.endGroup();

    qDebug("impostazioni caricate");
}

void finestra::closeEvent (QCloseEvent *event){
    QMessageBox::StandardButton exitBtn = QMessageBox::question( this,"",tr("Vuoi veramente uscire ?"),QMessageBox::No | QMessageBox::Yes);
    if (exitBtn != QMessageBox::Yes)
        event->ignore();
    else{
        event->accept();
        if(finestraOpzioni)
            delete finestraOpzioni;
    }
}
