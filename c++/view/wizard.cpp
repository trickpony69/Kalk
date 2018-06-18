#include "wizard.h"

wizard::wizard(){
    QWizardPage* welcome = new QWizardPage;
    QVBoxLayout* mainLayout=new QVBoxLayout;
    QLabel* label = new QLabel("GUIDA UTILIZZO KALK \n"
                                ""
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

                               "La barra sfondo nero e testo bianco contiene il risultato dell'operazione che può essere salvato tramite l'icona alla sua destra (floppy). "
                               "L'icona a destra del floppy mostra tutti i risultati salvati, possono essere rappresentati con un semplice drag and drop su uno slot a tua scelta \n\n"

                               "L'icona alto a destra serve per accedere alle impostazioni che permettono di cambiare i colori del grafico e di modificare il range di disegno delle rette. \n\n"
                               "INPUT: si possono inserire rette rigorosamente in questa forma 'ax + by + c = 0' (implicita), punti nella forma (x;y) , quadrati e triangoli mettendo in sequenza i punti , es. (x1;y1)(x2;y2) ecc.. \n"
                               "I coefficenti delle rette e i valori dei punti possono essere interi, razionali(es. 3/4 oppure 5/8) o double (es. 3.67 e non 3,67). \n"

                               "ATTENZIONE: Gli slot vanno riempiti in ordine crescente."

                               "\n\nEsempio utilizzo: \n-Scrivere nello slot: 3x+7/5y-7=0\n-Premere 'Disegna'\n-Inserire un nuovo slot con 'Aggiungi'\n-Scrivere nel secondo slot: 5/7x-y\n-Premere 'Disegna' "
                               "e successivamente 'intersezione'(icona alto a sinistra).");

    label->setWordWrap(true);
    mainLayout->addWidget(label);
    welcome->setLayout(mainLayout);
    setWindowTitle("Benvenuto");
    addPage(welcome);
    setFixedSize(770,780);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_DeleteOnClose);
    setOption(QWizard::NoBackButtonOnStartPage);
}

wizard::~wizard(){
    qDebug("wizard distrutto");
}
