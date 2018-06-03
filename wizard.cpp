#include "wizard.h"

wizard::wizard(){
    QWizardPage* welcome = new QWizardPage;
    QVBoxLayout* mainLayout=new QVBoxLayout;
    QLabel* label = new QLabel("Ciao ! Sono il tuo Kalkulon.\n"
                                "Alla tua destra vedrai tre slot, con i primi due puoi usare le funzioni che troverai nella barra di sinistra mentre con l'ultimo puoi soltanto disegnare.\n"
                                "In Alto a destra troverai le impostazioni dove potrai cambiare il colore degli slot e settare il range del grafico.\n"
                                "Con l'icona 'mostra/nascondi risultati' potrai vedere i tuoi risultati salvati dal display e potrai riusarli con un semplice drag and drop su uno slot a tua scelta.\n"
                                "Puoi disegnare:\n\nrette (in forma implicita)\n\npunti(in forma: (x;y))\n\npoligoni regolari fino a 4 lati (in forma: (x;y)+...(xn;yn) con 1<=n<=4)");
    label->setWordWrap(true);
    mainLayout->addWidget(label);
    welcome->setLayout(mainLayout);
    setWindowTitle("Benvenuto");
    addPage(welcome);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_DeleteOnClose);
}

wizard::~wizard(){
    qDebug("wizard distrutto");
}
