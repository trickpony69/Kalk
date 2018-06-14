#ifndef ECCEZIONI_H
#define ECCEZIONI_H

#include <string>
using std::string;



class eccezioni {
private:
    string error;
protected:
    eccezioni(string a): error(a) {}
public:
    string to_string_error() const;
};

class input_error : public eccezioni{
public :
    input_error(string a = "Errore input." ) : eccezioni(a) {}
};

class not_implicit : public eccezioni{
public :
    not_implicit(string a = "Retta non nella forma prevista." ) : eccezioni(a) {}
};

class irregular_pol : public eccezioni {
public :
    irregular_pol(string a = "Poligono non regolare."):eccezioni(a) {}
};

class num_lati : public eccezioni{
public :
    num_lati(string a = "Numero punti non gestibile.\n Rappresenta un punto alla volta."):eccezioni(a) {}
};



#endif // ECCEZIONI_H
