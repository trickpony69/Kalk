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
#include <QMainWindow>
#include <QToolBar>
#include <QIcon>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QVector>
#include <QGraphicsItem>
#include <QAction>

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
    QGraphicsScene* scene;
    QGraphicsView* view;
    QHBoxLayout* hLay;
public:
    mainGui(const QString& ="aggiungi funzione", QWidget* =0);//miaclasse(const QString& ="+",QWidget* = 0);
    virtual ~mainGui(){}

public slots: //private o public slots ?
    void push_qle();
    void remove_qle();
    void returnedInput();
};

#endif // MIACLASSE_H
