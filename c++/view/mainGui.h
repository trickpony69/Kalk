#ifndef MIACLASSE_H
#define MIACLASSE_H

#include "view/grafico.h"
#include "view/myqline.h"
#include "view/graphicelement.h"
#include "model/eccezioni.h"

class mainGui: public QWidget{
    friend class barraFunzionalita;
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
private slots:
    void push_qle();
    void remove_qle();
    void drawAndReturn();
    void clearEntry();
    void saveResult();
    void showResult();
};

#endif // MIACLASSE_H
