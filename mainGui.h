#ifndef MIACLASSE_H
#define MIACLASSE_H

#include "grafico.h"
#include "poligono.h"
#include "myqline.h"
#include "wizard.h"

class mainGui: public QWidget{
    friend class finestra;
    Q_OBJECT
private:
    QHBoxLayout* griglia;
    QHBoxLayout* hLay;
    QHBoxLayout* funEGrafico;
    QVBoxLayout* hFunLay;
    QVBoxLayout *mainLayout;
    QHBoxLayout* layoutDisplay;
    QPushButton* add;
    QPushButton* remove;
    QPushButton* enter;
    QPushButton* cancel;
    QPushButton* save;
    QPushButton* showSavedResult;
    QListWidget* savedResultWindow;
    QVector<QLineEdit*> funVec;
    QVector<QLabel*> vectorLabel;
    QVector<QString> returnToParse;
    QVector<inputitem*> inputElemento;
    grafico* graficoElementi;
    QLineEdit* display;
    void loadSettings();
    void loadColor(QString,int);
    void clearInput();
public:
    mainGui(QWidget* =0);
    virtual ~mainGui(){}
    // i due razionali passati per riferimento sono rideriti al range di stampa delle coordinate
    static vector<punto> print_rect(retta&,razionale&,razionale&);

private slots: //private o public slots ?
    void push_qle();
    void remove_qle();
    void drawAndReturn();
    void clearEntry();
    void intersezione();
    void saveResult();
    void showResult();
protected slots:
    void rect2Points();
    void dist2item();
    void area();
    void perimetro();
    void paralsrettapunt();
    void perppuntoretta();

};

#endif // MIACLASSE_H
