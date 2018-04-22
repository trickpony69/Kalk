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

class mainGui: public QWidget{

    friend class finestra;
    Q_OBJECT
private:
    QHBoxLayout* griglia;
    QVBoxLayout* vLay;
    QHBoxLayout* hLay;
    QHBoxLayout* funEGrafico;
    QVBoxLayout* hFunLay;
    QVBoxLayout *mainLayout;
    QPushButton* add;
    QPushButton* remove;
    QPushButton* enter;
    QVector<QLineEdit*> vec;
    QLabel* errorLabel;
    QVector<QString*> returnInput;
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
