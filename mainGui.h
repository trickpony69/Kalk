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

class mainGui: public QWidget{

Q_OBJECT

public:

    virtual ~mainGui() {}
    QPushButton* b;
    QVBoxLayout *mainLayout;
    QVBoxLayout* vLay;
    QHBoxLayout* hLay;
    QVector<QLineEdit*> vec;
    //miaclasse(const QString& ="+",QWidget* = 0);

    mainGui(const QString& qs ="+", QWidget* p =0): QWidget(p), b(new QPushButton(qs, this)), vLay(new QVBoxLayout(this)), hLay(new QHBoxLayout(this)), mainLayout(new QVBoxLayout(this)){
        b->setCheckable(false);
        vLay->addWidget(b);
        QObject::connect(b, SIGNAL(clicked(bool)), this, SLOT(push_qle()));//QObject::connect(m.b, SIGNAL(clicked(bool)), &m, SLOT(push_qle()));
        mainLayout->addLayout(vLay);
        mainLayout->addLayout(hLay);
        setLayout(mainLayout);
        this->setWindowTitle("mok");
        this->show();
    }


public slots:

    void push_qle(){
        if(vec.size() < 3){
            QIcon icon("icon.ico");
            QLineEdit* qle = new QLineEdit(this);
            qle->setPlaceholderText("inserisci la funzione");
            vec.push_back(qle);
            hLay->addWidget(qle);

        }
    }
};

#endif // MIACLASSE_H
