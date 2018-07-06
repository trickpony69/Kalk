#ifndef RETTAGRAPH_H
#define RETTAGRAPH_H

#include "view/graficelement.h"
#include "model/punto.h"

class rettaGraph : public graficElement{
public:
    rettaGraph(punto,punto);
    virtual void drawing(grafico*,unsigned);
private:
    punto min,max;
protected:
    virtual void draw(grafico*,unsigned);

};

#endif // RETTAGRAPH_H
