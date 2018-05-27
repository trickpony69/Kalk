#ifndef IMPOSTAZIONI_H
#define IMPOSTAZIONI_H

#include <QSettings>
#include <mainGui.h>

class impostazioni : public QWidget{
    Q_OBJECT
    friend class finestra;
private:
    //----------prima configurazione------
    QVector<QButtonGroup*> buttonGroup;
    QVector<QVector<QRadioButton*>> vectorChangeColor;
    QVector<QColor> colori;
    QHBoxLayout* titoloImpostazione0;
    QHBoxLayout* settaggi;
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
