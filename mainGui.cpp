#include <mainGui.h>

mainGui::mainGui(const QString& qs, QWidget* p): QWidget(p), b(new QPushButton(qs, this)), vLay(new QVBoxLayout(this)), hLay(new QHBoxLayout(this)), mainLayout(new QVBoxLayout(this)){
    vLay->addWidget(b);
    b->setFixedSize(140,60);
    QObject::connect(b, SIGNAL(clicked(bool)), this, SLOT(push_qle()));//QObject::connect(m.b, SIGNAL(clicked(bool)), &m, SLOT(push_qle()));
    mainLayout->addLayout(vLay);
    mainLayout->addLayout(hLay);
    setLayout(mainLayout);
    this->setWindowTitle("mok");
    this->show();
    resize(700,300);
}

void mainGui::push_qle(){
    if(vec.size() < 3){
        QLineEdit* qle = new QLineEdit(this);
        qle->setPlaceholderText("inserisci la funzione");
        vec.push_back(qle);
        hLay->addWidget(qle);
    }
    else{
        b->setDisabled(true);
        QLabel* errorLabel = new QLabel("mi dispiace ma non puoi piu'aggiungere funzioni :(, daje accontentati");
        vLay->addWidget(errorLabel);
    }
}
