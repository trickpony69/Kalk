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

class mainGui: public QWidget{

Q_OBJECT

public:
    QPushButton* add;
    QPushButton* remove;
    QLabel* errorLabel;
    QVBoxLayout *mainLayout;
    QVBoxLayout* vLay;
    QHBoxLayout* hLay;
    QVBoxLayout* hFunLay;
    QVector<QLineEdit*> vec;
    QVector<QPushButton*> vecButton;
    mainGui(const QString& ="aggiungi funzione", QWidget* =0); //miaclasse(const QString& ="+",QWidget* = 0);
    virtual ~mainGui(){};

public slots:
    void push_qle();
    void remove_qle();
};

#endif // MIACLASSE_H
