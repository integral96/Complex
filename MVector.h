#ifndef MVECTOR_H
#define MVECTOR_H


class MVector : virtual public Complex
{
private:
    double *myvector;
    double *Revector;
    double *Imvector;
    //Complex *compl;
public:
    int MAX;
    MVector();
    MVector(int );
    MVector(const Complex *, int);
    double length();
    const MVector & operator = (const MVector &);
    const MVector & operator + (const MVector &);
    const MVector & operator - (const MVector &);
    const MVector & operator += (const MVector &);
    const MVector & operator *= (const MVector &);
    bool operator >= (const MVector &);
    double operator [] (int );
    double operator * (const MVector &);
    friend ostream& operator<< (ostream& os, const MVector &v);
virtual ~MVector();

protected:

};

#endif // MVECTOR_H
