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

class irregular_pol : public exception {}


#endif // ECCEZIONI_H
