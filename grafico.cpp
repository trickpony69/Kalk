#include "grafico.h"

grafico::grafico() : scene(new QGraphicsScene()){
    scene->setSceneRect(-180, -90, 360, 180);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setRenderHint(QPainter::Antialiasing);
    scale(20, -20);
    setScene(scene);

    //AsseX
    QPointF inizioPuntoX(-300,0);
    QPainterPath asseX(inizioPuntoX);
    asseX.lineTo(300,0);
    scene->addPath(asseX);

    //AsseY
    QPointF inizioPuntoY(0,-300);
    QPainterPath asseY(inizioPuntoY);
    asseY.lineTo(0,300);
    scene->addPath(asseY);
}
