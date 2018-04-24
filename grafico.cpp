#include "grafico.h"

grafico::grafico(){
//    scene->setSceneRect(-180, -90, 360, 180);
//    setDragMode(QGraphicsView::ScrollHandDrag);
//    setRenderHint(QPainter::Antialiasing);
//    scale(20, -20);
//    setScene(scene);

//    //AsseX
//    QPointF inizioPuntoX(-300,0);
//    QPainterPath asseX(inizioPuntoX);
//    asseX.lineTo(300,0);
//    scene->addPath(asseX);

//    //AsseY
//    QPointF inizioPuntoY(0,-300);
//    QPainterPath asseY(inizioPuntoY);
//    asseY.lineTo(0,300);
//    scene->addPath(asseY);

    //---------------------------------
    // generate some data:
    /*QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    addGraph();
    graph(0)->setData(x, y);
    // give the axes some labels:
    xAxis->setLabel("x");
    yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    xAxis->setRange(-1, 1);
    yAxis->setRange(0, 1);
    replot();*/
    // The following plot setup is mostly taken from the plot demos:
      addGraph();
      graph()->setPen(QPen(Qt::blue));
      graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
      addGraph();
      graph()->setPen(QPen(Qt::red));
      axisRect()->setupFullAxesBox(true);
      setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

