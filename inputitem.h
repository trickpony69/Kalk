#ifndef INPUTITEM_H
#define INPUTITEM_H

#include<string>
#include <iostream>
#include<typeinfo>
using std::istream;
using std::cin;
using std::string;

class inputitem
{
    friend istream& operator>>(istream&,inputitem*);
public:
    virtual ~inputitem() =0 ;
    static inputitem* pars_start(string);
    virtual void isFigura() const =0;
    static inputitem* iniz_input( string );
};

#endif // INPUTITEM_H
