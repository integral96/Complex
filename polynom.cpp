//#include <iostream>
//#include <cmath>
////#include "Complex.h"
//#include "polynom.h"
//using namespace std;
//int Polynom::Pn = 6;
//
//Polynom::Polynom():arg(nullptr)
//{
//}
//double Polynom::operator()(double tmp){
//    double s = 0;
//    for(int i=0;i<=Pn;++i) s+=arg[i]*pow(tmp,i);
//    return s;
//}
//const Polynom &Polynom::operator,(int k){
//    Polynom tmp ;
//    for(int i=0;i<=Pn;++i) tmp.arg[i] = arg[i];
//    switch(k){
//        case 0: break;
//        case 1: for(int i=0;i<Pn;++i) tmp.arg[i] = tmp.arg[i+1]*(i+1);
//                tmp.arg[Pn] = 0;
//                break;
//        default: tmp = (tmp,1,k-1);
//    }
//    return tmp;
//}
//Polynom Polynom::operator + (Polynom obj){
//    Polynom tmp;
//    for(int i=0;i<=n;++i) tmp.a[i] = a[i]+obj.a[i];
//    return tmp;
//}
//Polynom Polynom::operator - (Polynom obj){
//    Polynom tmp;
//    for(int i=0;i<=n;++i) tmp.a[i] = a[i]-obj.a[i];
//    return tmp;
//}
//Polynom Polynom::operator * (double b){
//    Polynom tmp;
//    for(int i=0;i<=n;++i) tmp.a[i] = a[i]*b;
//    return tmp;
//}
//Polynom Polynom::operator / (double b){
//    Polynom tmp;
//    for(int i=0;i<=n;++i) tmp.a[i] = a[i]/b;
//    return tmp;
//}
//void Polynom::show(Polynom obj){
//    for(int i=0;i<=n;++i) cout<<"X"<<"("<<i+1<<")"<<"+"<<obj.a[i]<<"";
//    cout<<endl;
//}
//Polynom::Polynom()
//{
//    for(int i=0;i<=n;++i) a[i] = rand()%109-57;
//}
//
//Polynom::~Polynom()
//{
////    for(int i=0;i<=n;++i) cout<<"Bye "<< a[i]<<" ";
////    cout<<endl;
//}
//
//Polynom::~Polynom()
//{
//    //dtor
//}
