#ifndef MIACLASSE_H
#define MIACLASSE_H


#include "view/grafico.h"
#include "model/poligono.h"
#include "view/myqline.h"
#include "view/wizard.h"
#include "view/graphicelement.h"
#include "view/puntograph.h"
#include "view/rettagraph.h"
#include "view/poligongraph.h"

class mainGui: public QWidget{
    friend class finestra;
    Q_OBJECT
private:
    QHBoxLayout* griglia;
    QPushButton* add;
    QPushButton* remove;
    QPushButton* enter;
    QPushButton* cancel;
    QPushButton* save;
    QPushButton* showSavedResult;
    QListWidget* savedResultWindow;
    QHBoxLayout* hLay;
    QVBoxLayout* hFunLay;
    QHBoxLayout* layoutDisplay;
    QVector<QLineEdit*> funVec;
    QVector<QLabel*> vectorLabel;
    QVector<QString> returnToParse;
    QVector<inputitem*> inputElemento;
    grafico* graficoElementi;
    QHBoxLayout* funEGrafico;
    QLineEdit* display;
    void loadColor(QString,int);
    void clearInput();
public:
    mainGui(QWidget* =0);
    ~mainGui();

private slots: //private o public slots ?
    void push_qle();
    void remove_qle();
    void drawAndReturn();
    void clearEntry();
    void intersezione();
    void saveResult();
    void showResult();
    void rect2Points();
    void dist2item();
    void area();
    void perimetro();
    void paralsrettapunt();
    void perppuntoretta();

};

#endif // MIACLASSE_H
