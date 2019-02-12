#include <iostream>
#include <cmath>
#include "Complex.h"
#include "MVector.h"
using namespace std;
//int MVector::MAX = 3;
MVector::MVector():myvector(nullptr),Revector(nullptr),Imvector(nullptr), MAX(0)
{

}
MVector::MVector(int N): Revector(nullptr),Imvector(nullptr),MAX(N)
{
    myvector = new double[MAX];
    for(int i=0; i<MAX; ++i) myvector[i] = (double)(rand()%109-37)/10;
}
MVector::MVector(const Complex *vm, int N):myvector(nullptr),MAX(N)
{
    Complex *comarr = new Complex[MAX];
    for(int i=0; i<MAX; ++i) comarr[i].Re = vm[i].Re;
    for(int i=0; i<MAX; ++i) comarr[i].Im = vm[i].Im;
    Revector = new double[MAX];
    Imvector = new double[MAX];
    for(int i=0; i<MAX; ++i) Revector[i] = comarr[i].Re;
    for(int i=0; i<MAX; ++i) Imvector[i] = comarr[i].Im ;
delete [] comarr;
}
const MVector & MVector::operator = (const MVector &mv)
{
    myvector = mv.myvector;
    return *this;
}
const MVector & MVector::operator + (const MVector &mv)
{
    for(int i=0; i<MAX; ++i) myvector[i] = myvector[i]+mv.myvector[i];
    return *this;
}
const MVector & MVector::operator += (const MVector &mv)
{
    for(int i=0; i<MAX; ++i) myvector[i] += mv.myvector[i];
    return *this;
}
const MVector & MVector::operator - (const MVector &mv)
{
    for(int i=0; i<MAX; ++i) myvector[i] = myvector[i]-mv.myvector[i];
    return *this;
}
double MVector::operator * (const MVector &mv)
{
    double tmp=0;
    for(int i=0; i<MAX; ++i) tmp += myvector[i]*mv.myvector[i];
    return tmp;
}
const MVector & MVector::operator *= (const MVector &mv)
{
    for(int i=0; i<MAX; ++i) myvector[i] *= mv.myvector[i];
    return *this;
}
double MVector::operator [] (int N)
{
    return myvector[N];
}
//bool MVector::operator >= (const MVector &mv)
//{
//    for(int i=0; i<MAX; ++i) return (mv.myvector[i]>=myvector[i]);
//}
double MVector::length()
{
    double tmp =0, len=0;
    for(int i=0; i<MAX; ++i) tmp += pow(myvector[i],2);
    len = sqrt(tmp);
    return len;
}
ostream& operator<< (ostream& os, const MVector &v)
{
    if(v.myvector != nullptr )
    {
    for(int i=0; i<v.MAX; ++i)
    {
        if(i==0) os <<"{"<< v.myvector[i] <<", ";
        else if(i==v.MAX-1) os << v.myvector[i]<<"}\n";
        else os << v.myvector[i]<<", ";
    }
    }
    else if((v.Revector!=nullptr) && (v.Imvector!=nullptr) )
    {
    for(int i=0; i<v.MAX; ++i)
    {
        if(i==0 && v.Imvector[i]>0) os <<"{"<< v.Revector[i] <<"+"<<v.Imvector[i]<<"i, ";
        else if(i==0 && v.Imvector[i]<0) os <<"{"<< v.Revector[i] <<v.Imvector[i]<<"i, ";
        else if(i==v.MAX-1 && v.Imvector[i]>0) os << v.Revector[i]<<"+"<<v.Imvector[i]<<"i}\n";
        else if(i==v.MAX-1 && v.Imvector[i]<0) os << v.Revector[i]<<v.Imvector[i]<<"i}\n";
        else if(v.Imvector[i]<0)os << v.Revector[i]<<v.Imvector[i]<<"i, ";
        else os << v.Revector[i]<<"+"<<v.Imvector[i]<<"i, ";
    }
    }
    else os <<"Empty vector\n";
    return os;
}
MVector::~MVector()
{
    delete [] Revector;
    delete [] Imvector;
    delete [] myvector;

}
