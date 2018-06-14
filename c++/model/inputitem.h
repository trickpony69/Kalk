#ifndef INPUTITEM_H
#define INPUTITEM_H

#include <string>
#include <iostream>
#include <typeinfo>
#include <vector>
using std::istream;
using std::string;
using std::vector;

class punto;

class inputitem
{
    friend istream& operator>>(istream&,inputitem*);
public:
    virtual ~inputitem() =0 ;
    static inputitem* pars_start(string);
    static inputitem* iniz_input( string );
    virtual vector<punto> intersect(inputitem*) const =0;
    virtual double distance(inputitem*) const =0 ;
};

#endif // INPUTITEM_H