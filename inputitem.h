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
};

#endif // INPUTITEM_H
