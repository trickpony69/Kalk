#include "graphicelement.h"
#include "view/rettagraph.h"
#include "view/puntograph.h"
#include "view/poligongraph.h"

graphicElement* graphicElement::parsGraphicEl(inputitem* in){

    if(retta* ret = dynamic_cast<retta*>(in)){
        QSettings settings("Kalk","configKalk");

        settings.beginGroup("cambioRange");

        razionale min(-30,1);
        razionale max(30,1);

        if(settings.value("min").toInt())
            min=razionale(settings.value("min").toInt(),1);
        if(settings.value("max").toInt())
            max=razionale(settings.value("max").toInt(),1);

        settings.endGroup();

        vector<punto> range = ret->print_rect(min,max);
        return new rettaGraph(range[0],range[1]);
    }
    else if(punto* pt = dynamic_cast<punto*>(in)){

        return new puntoGraph(pt);
    }
    else if(poligono* pol = dynamic_cast<poligono*>(in)){

        return new poligonGraph(pol);
    }

}

