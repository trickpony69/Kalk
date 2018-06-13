#ifndef ECCEZIONI_H
#define ECCEZIONI_H

#include <exception>
using namespace std;

class input_error : public exception{
public :
    input_error() {};
};

class den_error : public exception{};

class num_error : public exception{};

class irregular_pol : public exception {};

class not_implicit : public exception {};

class num_lati : public exception{};

class two_point : public exception{};


#endif // ECCEZIONI_H
