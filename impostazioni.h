#ifndef IMPOSTAZIONI_H
#define IMPOSTAZIONI_H

#include <QWidget>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVector>
#include <QLabel>
#include <QRadioButton>
#include <QGroupBox>
#include <QButtonGroup>
#include <QSettings>
#include <mainGui.h>

class impostazioni : public QWidget{
    Q_OBJECT
    friend class finestra;
private:
    //----------prima configurazione------
    QGroupBox *contenitorone;//si può usare ??
    QButtonGroup gruppo0;
    QButtonGroup gruppo1;
    QButtonGroup gruppo2;
    QVector<QRadioButton*> cambioColori0;
    QVector<QRadioButton*> cambioColori1;
    QVector<QRadioButton*> cambioColori2;
    QVector<QColor> colori;
    QHBoxLayout* titoloImpostazione0;
    QHBoxLayout* settaggi;
    QVBoxLayout* primoSettaggio;
    QVBoxLayout* secondoSettaggio;
    QVBoxLayout* terzoSettaggio;
    QVBoxLayout* mainlayout;
    //----------seconda configurazione------
    QHBoxLayout* titoloImpostazione1;


    //----------------------------------------
    void saveSettings();
public:
    explicit impostazioni(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *);
};

#endif // IMPOSTAZIONI_H
