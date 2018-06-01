#ifndef IMPOSTAZIONI_H
#define IMPOSTAZIONI_H

#include <QSettings>
#include <mainGui.h>

class impostazioni : public QWidget{
    Q_OBJECT
    friend class finestra;
private:
    QVBoxLayout* mainlayout;
    //----------prima configurazione------
    QVector<QButtonGroup*> buttonGroup;
    QVector<QVector<QRadioButton*>> vectorChangeColor;
    QVector<QColor> colori;
    QHBoxLayout* titoloImpostazione0;
    QHBoxLayout* settaggi;
    //----------seconda configurazione------
    QHBoxLayout* titoloImpostazione1;
    QHBoxLayout* impostazione1;
    QLineEdit* min;
    QLineEdit* max;
    //----------------------------------------
    void saveSettings();
public:
    explicit impostazioni(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *);
};

#endif // IMPOSTAZIONI_H
