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
    input_error(a = "Errore input."): eccezioni(a) {}
};

class not_implicit : public eccezioni{
    not_implicit(a = "Retta non nella forma prevista.") : eccezioni(a) {}
};

class irregular_pol : public eccezioni {
    irregular_pol(a = "Poligono non regolare."):eccezioni(a) {}
};

class num_lati : public eccezioni{
    num_lati(a = "Numero punti non gestibile.\n Rappresenta un punto alla volta."):eccezioni(a) {}
};



#endif // ECCEZIONI_H
