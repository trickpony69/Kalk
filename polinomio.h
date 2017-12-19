#ifndef POLINOMIO_H
#define POLINOMIO_H


class polinomio{

private:
    double a;
    double b;
    double c;

public:
    polinomio(): a(0), b(0), c(0);
    polinomio(double d=0, double e=0, double f=0): a(d), b(e), f(c) {}
    virtual ~polinomio();
    virtual discriminante()
};

#endif // POLINOMIO_H
