#ifndef GRAFICO_H
#define GRAFICO_H
#include <QGraphicsView>
#include <QGraphicsScene>


class grafico : public QGraphicsView{
    Q_OBJECT
public:
    explicit grafico();
    QGraphicsScene* scene;
signals:

public slots:
};

#endif // GRAFICO_H
