#ifndef MIACLASSE_H
#define MIACLASSE_H

#include <QWidget>
#include <QVector>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QMainWindow>
#include <QToolBar>
#include <QVector>
#include <QGraphicsItem>
#include <grafico.h>
#include <retta.h>
#include <QDebug>
#include <QGridLayout>
#include <QPainterPath>
#include <vector>
#include "qcustomplot.h"
#include <string>
#include <poligono.h>
#include "retta.h"
#include <iostream>
#include "inputitem.h"

class mainGui: public QWidget{
    friend class finestra;
    Q_OBJECT
private:
    QHBoxLayout* griglia;
    QHBoxLayout* funzionalita;
    QVBoxLayout* vLay;
    QHBoxLayout* hLay;
    QHBoxLayout* funEGrafico;
    QVBoxLayout* hFunLay;
    QVBoxLayout *mainLayout;
    QPushButton* add;
    QPushButton* remove;
    QPushButton* enter;
    QPushButton* cancel;
    QVector<QLineEdit*> vec;
    QLabel* errorLabel;
    QLabel* labelInters ;
    QVector<QString*> returnInput;
    grafico* graficoElementi;
    QLabel* label0;
    QLabel* label1;
    QLabel* label2;
    QVector<retta> inputRetta;
    QVector<punto> inputPunto;
    QVector<poligono*> inputPoligono;
    QVector<inputitem*> inputElemento;
    void clearInput();
    void loadSettings();
    void loadColor(QString,int);
public:
    mainGui(const QString& ="aggiungi funzione", QWidget* =0);//miaclasse(const QString& ="+",QWidget* = 0);
    virtual ~mainGui(){}
    // i due razionali passati per riferimento sono rideriti al range di stampa delle coordinate
    static vector<punto> print_rect(retta&,razionale&,razionale&);

public slots: //private o public slots ?
    void push_qle();
    void remove_qle();
    void returnedInput();
    void clearEntry();
    void intersezione();
};

#endif // MIACLASSE_H
