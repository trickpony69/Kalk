#ifndef IMPOSTAZIONI_H
#define IMPOSTAZIONI_H

#include <QWidget>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVector>
#include <QLabel>
#include <QRadioButton>

class impostazioni : public QWidget{
    Q_OBJECT
private:
    static QVector<QLabel*> clone(QVector<QLabel*>);
public:
    explicit impostazioni(QWidget *parent = nullptr);

    QVector<QRadioButton*> cambioColori0;
    QVector<QRadioButton*> cambioColori1;
    QVector<QRadioButton*> cambioColori2;
    QVector<QColor> colori;
    QHBoxLayout* titolo;
    QHBoxLayout* settaggi;
    QVBoxLayout* primoSettaggio;
    QVBoxLayout* secondoSettaggio;
    QVBoxLayout* terzoSettaggio;
    QVBoxLayout* mainlayout;
signals:

public slots:
};

#endif // IMPOSTAZIONI_H
