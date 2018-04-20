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
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QVector>
#include <QGraphicsItem>
#include <grafico.h>
#include <retta.h>
#include <QDebug>

class mainGui: public QWidget{

    friend class finestra;
    Q_OBJECT
private:
    QPushButton* add;
    QPushButton* remove;
    QPushButton* enter;
    QVector<QLineEdit*> vec;
    QLabel* errorLabel;
    QVector<QString*> returnInput;
    QVBoxLayout *mainLayout;
    QVBoxLayout* vLay;
    QVBoxLayout* hFunLay;  
    QHBoxLayout* hLay;
    grafico* graficoElementi;
    QLabel* label0;
    QLabel* label1;
    QLabel* label2;
    void clear();
public:
    mainGui(const QString& ="aggiungi funzione", QWidget* =0);//miaclasse(const QString& ="+",QWidget* = 0);
    virtual ~mainGui(){}

public slots: //private o public slots ?
    void push_qle();
    void remove_qle();
    void returnedInput();

};

#endif // MIACLASSE_H
