#ifndef MEXPONENTA_H
#define MEXPONENTA_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Complex.h"

using namespace std;

double fact(int N)
{
    if(N<0) return 0;
    if(N==0) return 1;
    else return N*fact(N-1);
}
//double powr()
template <class MExp>
class MExponenta
{
private:
    int iter;
    MExp *pexp;
    //MExp *pwr;
public:
    MExponenta():pexp(nullptr), iter(0) {}
    MExponenta(const MExp &pr, int len):iter(len)
    {
        pexp = new MExp[iter];
        MExp tmp = pr;

        while (!len)
        {
            tmp *= pr;
        }
            for(int i = 0; i<iter; ++i)
            {
                pexp[i]=/*pow(pr, i)*/tmp/fact(i);
            }



    }
    MExp ExpSeries(const MExp & pr)
    {
        MExp s;
        for(int i = 0; i<iter; ++i)
        {
            s += pexp[i];
        }
        s +=pr;
        return s;
    }
    void Show()
    {
        for(int i = 0; i<iter; ++i)
    {
        if(pexp[i]>=0) cout << pexp[i] <<"+";
        else if (i==iter-1) cout << pexp[i];
    }
//    return this;
    }
//friend ostream& operator << (ostream& os, const MExp &pr)
//{
//    for(int i = 0; i<pr.iter; ++i)
//    {
//        if(pr.pexp[i]>=0) os << pr.pexp[i] <<"+";
//        else /*if (pr.pexp[i]<0)*/ os << pr.pexp[i];
//    }
//    return os;
//}
virtual ~MExponenta()
{
    delete [] pexp;
//    delete [] pwr;
}

    protected:

    private:
};

#endif // MEXPONENTA_H
