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
#include "myqline.h"

class mainGui: public QWidget{
    friend class finestra;
    Q_OBJECT
private:
    //QWidget* parent;
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

public slots: //private o public slots ?
    void push_qle();
    void remove_qle();
    void drawAndReturn();
    void clearEntry();
    void intersezione();
    void saveResult();
    void showResult();
};

#endif // MIACLASSE_H
