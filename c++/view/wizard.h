#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class wizard : public QWizard{
public:
    wizard(QWidget* = 0,Qt::WindowFlags = 0);
};

#endif // WIZARD_H
