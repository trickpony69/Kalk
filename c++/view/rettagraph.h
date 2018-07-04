#ifndef RETTAGRAPH_H
#define RETTAGRAPH_H

#include "view/graficelement.h"
#include "model/punto.h"

class rettaGraph : public graficElement{
public:
    rettaGraph(grafico*,punto,punto);
    virtual void drawing(unsigned);
private:
    punto min,max;
protected:
    virtual void draw(unsigned);

};

#endif // RETTAGRAPH_H
