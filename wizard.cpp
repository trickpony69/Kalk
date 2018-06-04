#include "wizard.h"

wizard::wizard(){
    QWizardPage* welcome = new QWizardPage;
    QVBoxLayout* mainLayout=new QVBoxLayout;
    QLabel* label = new QLabel("GUIDA UTILIZZO KALK \n"
                                "La finestra presenta uno slot di inserimento dati, un grafico che sarà utilizzato per disegnare le funzioni inserite, quattro tasti a piè di pagina che rappresentano "
                                "le funzioni principali, a sinistra una barra laterale che rappresenta le operazioni che possono essere applicate ai dati inseriti.\n"
                                "I bottoni in fondo alla pagina hanno le seguenti funzioni:\n"
                                "'Aggiungi' inserisce uno slot di inserimento (max 3 slot) \n"
                                "NB: I primi due slot sono utilizzati per le funzioni su cui sono applicati i calcoli, mentre il terzo e ultimo è sfruttato per la verifica del risultato. \n"
                                "'Rimuovi' elimina l'ultimo slot inserito. Se lo slot era non vuoto verrà eliminato dal grafico il dato inserito. \n"
                                "'Disegna' rappresenta nel grafico le funzioni inserite negli slot. \n"
                                "'Resetta input' azzera tutti gli slot e il grafico. \n\n"
                                "La barra laterale di sinistra contiene ordinatamente le seguenti operazioni: \n"
                                "- Intersezione tra due elementi qualsiasi; \n"
                                "- Retta passante per due punti; \n"
                                "- Distanza tra due elementi qualsiasi; \n"
                                "- Perimetro di un poligono; \n"
                                "- Area di un poligono; \n"
                                "- Retta perpendicolare a un altra e passante per un punto; \n"
                                "- Retta parallela a un altra e passante per un punto. \n\n"

                               "La barra sfondo nero e testo bianco conterrà il risultato dell'operazione il quale può essere salvato tramite l'icona alla sua destra (floppy). "
                               "L'icona a destra del floppy mostra tutti i risultati salvati i quali possono essere rappresentati con un semplice drag and drop su uno slot a tua scelta \n\n"

                               "L'icona alto a destra serve per accedere alle impostazioni che permettono di cambiare i colori del grafico e di modificare il range di disegno delle rette. \n\n"
                               "INPUT: puoi inserire rette rigorosamente in questa forma 'ax + by + c = 0' (implicita), punti nella forma (x;y) , quadrati e triangoli mettendo in sequenza i punti , es. (x1;y1)(x2;y2) ecc.. \n");

                               /*"Alla tua destra vedrai tre slot, con i primi due puoi usare le funzioni che troverai nella barra di sinistra mentre con l'ultimo puoi soltanto disegnare.\n"
                                "In Alto a destra troverai le impostAzioni dove potrai cambiare il colore degli slot e settare il range del grafico.\n"
                                "Con l'icona 'mostra/nascondi risultati' potrai vedere i tuoi risultati salvati dal display e potrai riusarli con un semplice drag and drop su uno slot a tua scelta.\n"
                                "Puoi disegnare:\n\nrette (in forma implicita)\n\npunti(in forma: (x;y))\n\npoligoni regolari fino a 4 lati (in forma: (x;y)+...(xn;yn) con 1<=n<=4)");*/
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
