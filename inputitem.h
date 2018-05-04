#ifndef INPUTITEM_H
#define INPUTITEM_H

#include<string>


class inputitem
{
public:
    virtual ~inputitem() =0 ;
    //restituisce puntatore a retta/punto
    inputitem* pars() const ;
};

#endif // INPUTITEM_H
