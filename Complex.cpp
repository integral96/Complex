#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;

Complex::Complex(): Re(0), Im(0)
{
    counts++;
    //cout<<counts<<endl;
}
Complex::Complex(const double &re, const double &im):  Re(re), Im(im)
{
    counts++;
    //cout<<counts<<endl;
}
const Complex & Complex::powr(int i)
{
    double mod = pow(sqrt(Re*Re+Im*Im), i);
    double arg = atan2(Im, Re);
    Re = mod*cos(i*arg);
    Im = mod*sin(i*arg);
    return *this;
}
const Complex & Complex::operator = (const Complex &z)
{
    Re = z.Re;
    Im = z.Im;
    return *this;
}
bool Complex::operator >= (const Complex &z)
{

    return (Re >= z.Re) && (Im >= z.Im);
}
const Complex & Complex::operator + (const Complex &z)
{
    Re = z.Re + Re;
    Im = z.Im + Im;
    return *this;
}
const Complex & Complex::operator += (const Complex &z)
{
    Re += z.Re;
    Im += z.Im ;
    return *this;
}
const Complex & Complex::operator - (const Complex &z)
{
    Re = Re - z.Re;
    Im = Im - z.Im;
    return *this;
}
const Complex & Complex::operator * (const Complex &z)
{
    Re = Re * z.Re - Im * z.Im;
    Im = Re * z.Im + Im * Re;
    return *this;
}
const Complex & Complex::operator *= (const Complex &z)
{
    Re *= Re * z.Re - Im * z.Im;
    Im *= Re * z.Im + Im * Re;
    return *this;
}
const Complex & Complex::operator * (double b)
{
    Re = b * Re;
    Im = b * Im;
    return *this;
}
const Complex & Complex::operator / (double b)
{
    Re = Re/b;
    Im = Im/b;
    return *this;
}
ostream& operator<< (ostream& os, const Complex &z)
{
    if(z.Im>0)os << z.Re <<"+"<<z.Im<<"i";
    else if (z.Im==0) os << z.Re;
    else os << z.Re <<z.Im<<"i";
    return os;
}
const Complex & Complex::Conjugate()
{
    Re = Re;
    Im = -Im;
    return *this;
}
Complex::~Complex()
{
    counts--;
    //cout<<counts<<endl;
}
