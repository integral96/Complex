#ifndef COMPLEX_H
#define COMPLEX_H
using namespace std;

class Complex
{
private:
    double phi;
    int counts = 0;
public:
    double Re;
    double Im;
    Complex();
    Complex(const double &re, const double &im);
    const Complex & Conjugate();
    const Complex & powr(int i);
    const Complex & operator = (const Complex &);
    bool operator >= (const Complex &);
    const Complex & operator + (const Complex &);
    const Complex & operator += (const Complex &);
    const Complex & operator - (const Complex &);
    const Complex & operator * (const Complex &);
    const Complex & operator *= (const Complex &);
    const Complex & operator * (double);
    const Complex & operator / (double);
    friend ostream& operator<< (ostream& os, const Complex &z);
    virtual ~Complex();

protected:

};

#endif // COMPLEX_H
