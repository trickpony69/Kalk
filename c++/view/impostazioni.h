#ifndef IMPOSTAZIONI_H
#define IMPOSTAZIONI_H

#include <QSettings>
#include <view/mainGui.h>

class impostazioni : public QWidget{
    Q_OBJECT
    friend class finestra;
private:
    QVBoxLayout* mainlayout;
    //----------impostazione 0------
    QVector<QButtonGroup*> buttonGroup;
    QVector<QVector<QRadioButton*>> vectorChangeColor;
    QVector<QColor> colori;
    QHBoxLayout* titoloImpostazione0;
    QHBoxLayout* settaggi;
    //----------impostazione 1------
    QHBoxLayout* titoloImpostazione1;
    QHBoxLayout* impostazione1;
    QLineEdit* min;
    QLineEdit* max;
    //----------------------------------------
    void saveSettings();
public:
    explicit impostazioni(QWidget *parent = nullptr);
    ~impostazioni();
    void closeEvent(QCloseEvent*);

};

#endif // IMPOSTAZIONI_H
