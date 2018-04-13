#ifndef MIACLASSE_H
#define MIACLASSE_H

#include <iostream>
#include <QWidget>
#include <QVector>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QFileIconProvider>

class mainGui: public QWidget{

Q_OBJECT

public:
    QPushButton* b;
    QVBoxLayout *mainLayout;
    QVBoxLayout* vLay;
    QHBoxLayout* hLay;
    QVector<QLineEdit*> vec;
    mainGui(const QString& ="aggiungi funzione", QWidget* =0); //miaclasse(const QString& ="+",QWidget* = 0);
    virtual ~mainGui(){};

public slots:
    void push_qle();
};

#endif // MIACLASSE_H
