#include "finestra.h"

finestra::finestra(QWidget *parent) : finestraBenvenuto(new wizard),QMainWindow(parent),widgetCentrale(new mainGui()){
    setWindowTitle("Kalk");
    setCentralWidget(widgetCentrale);
    QWidget* spaziatore1 = new QWidget(this);
    spaziatore1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QToolBar* tb = new QToolBar(this);
    QToolBar* tbL = new QToolBar(this);
    QAction* spaziatoreTab = new QAction("",this);
    QAction* opzioni = new QAction("Opzioni",this);
    QAction* inter = new QAction("Intersezione",this);
    QAction* rect2Points = new QAction("Retta passante tra due punti",this);
    QAction* dist2item = new QAction("Distanza tra due elementi",this);
    QAction* area = new QAction("Area",this);
    QAction* perimetro = new QAction("Perimetro",this);
    QAction* perp = new QAction("Retta perpendicolare dato punto e retta",this);
    QAction* paral = new QAction("Retta parallela dato punto e retta",this);

    spaziatoreTab->setDisabled(true);

    opzioni->setIcon(QIcon(":/icon/config.png"));
    inter->setIcon(QIcon(":/icon/intersect.png"));
    rect2Points->setIcon(QIcon(":/icon/rect2Points.png"));
    dist2item->setIcon(QIcon(":/icon/dist2Rect.png"));
    area->setIcon(QIcon(":/icon/area.png"));
    perimetro->setIcon(QIcon(":/icon/perimeter.png"));
    perp->setIcon(QIcon(":/icon/perpendicular.png"));
    paral->setIcon(QIcon(":/icon/parallels.png"));

    tb->addWidget(spaziatore1);
    tb->addAction(opzioni);
    tb->setFloatable(false);
    tb->setMovable(false);

    tbL->addAction(spaziatoreTab);
    tbL->addAction(inter);
    tbL->addAction(rect2Points);
    tbL->addAction(dist2item);
    tbL->addAction(perimetro);
    tbL->addAction(area);
    tbL->addAction(perp);
    tbL->addAction(paral);
    tbL->setFloatable(false);
    tbL->setMovable(false);

    addToolBar(Qt::LeftToolBarArea, tbL);
    addToolBar(tb);
    resize(700,500);
    finestraBenvenuto->show();
    finestraBenvenuto->resize(660,400);

    connect(opzioni,SIGNAL(triggered()),this,SLOT(showOption()));
    connect(inter,SIGNAL(triggered()),widgetCentrale,SLOT(intersezione()));
    connect(rect2Points,SIGNAL(triggered()),widgetCentrale,SLOT(rect2Points()));
    connect(dist2item,SIGNAL(triggered()),widgetCentrale,SLOT(dist2item()));
    connect(area,SIGNAL(triggered()),widgetCentrale,SLOT(area()));
    connect(perimetro,SIGNAL(triggered()),widgetCentrale,SLOT(perimetro()));
    connect(paral,SIGNAL(triggered()),widgetCentrale,SLOT(paralsrettapunt()));
    connect(perp,SIGNAL(triggered()),widgetCentrale,SLOT(perppuntoretta()));


}

finestra::~finestra(){
    qDebug("Kalk distrutta");
}

void finestra::showOption(){
    finestraOpzioni = new impostazioni;
    loadSettings();
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
        if(finestraOpzioni!=nullptr)
            delete finestraOpzioni;
        if(finestraBenvenuto!=nullptr)
            delete finestraBenvenuto;
    }
}
