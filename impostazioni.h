#ifndef IMPOSTAZIONI_H
#define IMPOSTAZIONI_H

#include <QWidget>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVector>
#include <QLabel>
class impostazioni : public QWidget{
    Q_OBJECT
public:
    explicit impostazioni(QWidget *parent = nullptr);
    QVector<QRadioButton*> cambioColori;
    QVector<QColor> colori;
    QHBoxLayout* titolo;
    QHBoxLayout* settaggi;
    QVBoxLayout* primoSettaggio;
    QVBoxLayout* secondoSettaggio;
    QVBoxLayout* terzoSettaggio;
    QVBoxLayout* layout;
signals:

public slots:
};

#endif // IMPOSTAZIONI_H
