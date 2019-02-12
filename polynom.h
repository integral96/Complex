#ifndef POLYNOM_H
#define POLYNOM_H


class Polynom //: virtual public Complex
{
private:
    double *arg;
    static Complex xc;
    static double xd;
    static int Pn;
public:
    Polynom();
    Polynom(double, int);
    Polynom(const Complex &, int);
    const Polynom & operator = (const Polynom &);
    const Polynom & operator + (const Polynom &);
    const Polynom & operator - (const Polynom &);
    double operator()(double tmp);
    const Polynom &operator,(int k);
virtual ~Polynom();

protected:

};

#endif // POLYNOM_H
