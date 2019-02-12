#include <iostream>
#include <iomanip>
#include <fstream>
#include "Complex.h"
#include "MVector.h"
#include "mexponenta.h"

//#include "polynom.h"
using namespace std;

template<typename Q> void MyQSort(Q *item, int left, int right)
{
    int i, j;
    Q x, y;
    i = left;
    j = right;
    x = item[(left+right)/2];
    do
    {
        while ((item[i]<x)&&(i<right)) i++;
        while ((x<item[j])&&(j>left)) j--;
        if(i<=j)
        {
            y=item[i];
            item[i]=item[j];
            item[j]=y;
            i++; j--;
        }
    }while (i<=j);
    if(left<j) MyQSort(item, left, j);
    if(i<right) MyQSort(item, i, right);
}
template <class X> void swapargs(X &a, X &b)
{
    X tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout<<"inside template swap\n";
}
template <class X> void swapargs(Complex &a, Complex &b)
{
    X tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout<<"inside Complex template swap\n";
}
template <class T1, class T2>
void myFunc(T1 &x, T2 &y)
{
    cout << x << " " << y <<endl;
}
void Xhandler(int test) throw(int, Complex, MVector)
{
    Complex cb;
    MVector vb;
    if(test==0) throw test;
    if(test==1) throw cb;
    if(test==2) throw vb;
}
int main()
{
    cout<<"Enter dimention array: ";
    int Nsize;
    cin>>Nsize;

    ////////////////////Вызываем базовый класс и ловим наследующий

    MVector V5(Nsize);
    double *pt = new double [Nsize];
    for(int i=0;i<Nsize;++i) pt[i] = (double)(rand()%109-37)/10;
    for(int i=0;i<Nsize;++i) cout << pt[i]<<"; ";
    cout << endl;
    MyQSort(pt, 0, Nsize);
    for(int i=0;i<Nsize;++i) cout << pt[i]<<"; ";
    cout << endl;
    delete [] pt;
    ////////////////////////////
    MExponenta<double> Pexp(.254, 5);

    //cout.setf(ios::scientific );
    cout <<"Taylor series for exp(x) =";
    Pexp.Show();
    cout<<endl;
    cout <<"Summa Taylor series for exp(x) =";
    cout<<Pexp.ExpSeries(1.);
    cout<<endl;
    /////////////////////////////
    Complex Z1(.2, .5);
    cout.setf(ios::scientific);
    cout<<"Complex series "<<setprecision(2)<<Z1.powr(8);
    cout.unsetf(ios::scientific);
    cout<<endl;
///////////////////////ряд экспоненты от комплексного числа.
    MExponenta<Complex> Comp(Z1,5);
    cout<<endl;
    cout <<"Summa Taylor series for exp(Z) =";
    cout<<Comp.ExpSeries(Z1);
    cout<<endl;
    ////////////////////////////////
    MVector deryved;
    try
    {
        Xhandler(2);
        throw deryved;
    }
    catch(int i) {cout<<"INT exception caught: "<<endl;}
    catch(MVector vb) {cout<<"In MVector class exception caught: "<<endl;}
    catch(Complex cb) {cout<<"In Complex class exception caught: "<<endl;}
//    /////////////////////////////////////////////Block Complex vector
///////////Заполняем масив комплексных чисел
    Complex *Zarr = new Complex[Nsize];
    for(int i =0; i<Nsize;++i)
    {
        Zarr[i].Re =(double)(rand()%101-37)/10;
        Zarr[i].Im =(double)(rand()%101-37)/20;
    }

    for(int i =0; i<Nsize;++i) cout << Zarr[i]<<"; ";
        cout << endl;


        MVector V3(Zarr, Nsize);
        MVector V4(Zarr, Nsize);
        cout << "vector complex number = "<<V3 << endl;
        //////////////////////////////
        Complex Ac(.2,2.5), Bc(2.2,.5);
        swapargs(Ac, Bc);
        cout<<"After exchange: "<<Ac<<"; "<<Bc<<endl;
        myFunc(Bc, V4);
        cout << "vector complex number = "<<V4 << endl;
        myFunc(Bc, V4);



    cout <<"Done!"<< endl;

     /////////////////////////////
    return 0;
}
