#include "grafico.h"

grafico::grafico() : scene(new QGraphicsScene()){
    QVector <QPointF> points;
    // Fill in points with n number of points
//    for(int i = 0; i< 100; i++)
//       points.append(QPointF(i*5, i*5));
    // Create a view, put a scene in it and add tiny circles
    // in the scene
    //view = new QGraphicsView();
    setAlignment(Qt::AlignBottom|Qt::AlignLeft);
    setDragMode(QGraphicsView::ScrollHandDrag);
    scale(20, 20);
    //scale(qreal(5), qreal(5));
    //centerOn(0,0);
    setScene(scene);
    //if(view->isTransformed())
    //    qDebug("transformaaa")
    //scene->addRect(0, 0, 300, 100);
    //scene->addRect(50, 0, 300, 200);
//    for(int i = 0; i< points.size(); i++)
//        scene->addEllipse(points[i].x(), points[i].y(), 1, 1);
    //---------------------------------------
}
