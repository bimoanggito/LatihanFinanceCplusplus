#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>
#include <stdio.h>

using namespace std;

extern "C"{
    //Natural Log Base
    #define LN_BASE 2.718281828459
}

class Finance
{
    public:
        double p_2_f (double i, int n);
        double f_2_p (double i, int n);
        double f_2_a (double i, int n);
        double p_2_a (double i, int n);
        double a_2_f (double i, int n);
        double a_2_p (double i, int n);
        double p_2_f_c (double i, int n);
        double f_2_p_c (double r, int n);
        double f_2_a_c (double r, int n);
        double p_2_a_c (double r, int n);
        double a_2_f_c (double r, int n);
        double a_2_p_c (double r, int n);
};

inline double Finance::p_2_f(double i, int n){
    return (pow(1+i, n) );
}

inline double Finance::f_2_p(double i, int n){
    return (1.0 / p_2_f(i, n) );
}

inline double Finance::f_2_a(double i, int n){
    return (1.0 / a_2_f(i, n) );
}

inline double Finance::p_2_a(double i, int n){
    return ( p_2_f(i, n) / a_2_f(i, n) );
}

inline double Finance::a_2_f(double i, int n){
    return ( p_2_f(i, n) - 1.0 / i );
}

inline double Finance::a_2_p(double i, int n){
    return ( a_2_f(i, n) / p_2_f(i, n) );
}

inline double Finance::p_2_f_c (double r, int n){
    return (pow(LN_BASE, r * n) );
}

inline double Finance::f_2_p_c(double r, int n){
    return ( 1.0 / p_2_f_c(r,n) );
}

inline double Finance::f_2_a_c(double r, int n){
    return ( 1.0 / a_2_f_c(r,n) );
}

inline double Finance::p_2_a_c(double r, int n){
    return ( p_2_f_c(r,n) / a_2_f_c(r,n) );
}

inline double Finance::a_2_f_c(double r, int n){
    return ( (p_2_f_c(r,n)- 1.0) / (pow(LN_BASE, r) - 1.0) );
}

inline double Finance::a_2_p_c(double r, int n){
    return ( a_2_f_c(r,n) / p_2_f_c(r,n) );
}

int main()
{
    Finance findat;
    double hasil;
    double pv;
    double fv;
    double i;
    double a;
    int n;
    system("CLS");
    cout<<endl<<"Tanpa anuity"<<endl;
    pv = 10000.00; // Present Value(Nilai Sekarang)
    fv = 0;        // ? Future Value(Nilai Kemudian)
    i = 0.08;      // Tingkat Bunga 8%
    n = 5;         // Periode 5 Tahun
    hasil = findat.p_2_f (i,n);
    fv = pv * hasil;
    cout<<endl<<"Future Value = Present Value * FVIF";
    cout<<endl<<"Present Value : "<<pv;
    cout<<endl<<"Tingkat Bunga(i) : "<<i*100<<" %";
    cout<<endl<<"Periode(n) : "<<n;
    cout<<endl<<"FVIF(i, n) : "<<hasil;
    cout<<endl<<"Future Value : "<<fv;
    cout<<endl;

    pv = 0;                // Present Value(Nilai Sekarang)
    fv = 15000.00;         // ? Future Value(Nilai Kemudian)
    i = 0.08;              // Tingkat Bunga 8%
    n = 5;                 // Periode 5 Tahun
    hasil = findat.f_2_p (i,n);
    pv = fv * hasil;
    cout<<endl<<"Present Value = Future Value * PVIF";
    cout<<endl<<"Future Value : "<<fv;
    cout<<endl<<"Tingkat Bunga(i) : "<<i*100<<" %";
    cout<<endl<<"Periode(n) : "<<n;
    cout<<endl<<"PVIF(i, n) : "<<hasil;
    cout<<endl<<"Present Value : "<<pv;
    cout<<endl;
    getche();

    cout<<endl<<"Dengan anuity"<<endl;
    a = 10000;     // Annuity
    fv = 0;        // ? Future Value(Nilai Kemudian)
    i = 0.08;      // Tingkat Bunga 8%
    n = 3;         // Periode 5 Tahun
    hasil = findat.a_2_f (i,n);
    fv = a * hasil;
    cout<<endl<<"Future Value Annuity = Annuity * FVIFA";
    cout<<endl<<"Annuity : "<<a;
    cout<<endl<<"Tingkat Bunga(i) : "<<i*100<<" %";
    cout<<endl<<"Periode(n) : "<<n;
    cout<<endl<<"FVIFA(i, n) : "<<hasil;
    cout<<endl<<"Future Value Annuity : "<<fv;
    cout<<endl;

    a = 10000;     // Annuity
    fv = 0;        // ? Future Value(Nilai Kemudian)
    i = 0.08;      // Tingkat Bunga 8%
    n = 3;         // Periode 5 Tahun
    hasil = findat.a_2_p (i,n);
    fv = a * hasil;
    cout<<endl<<"Present Value Annuity = Annuity * PVIFA";
    cout<<endl<<"Annuity : "<<a;
    cout<<endl<<"Tingkat Bunga(i) : "<<i*100<<" %";
    cout<<endl<<"Periode(n) : "<<n;
    cout<<endl<<"PVIFA(i, n) : "<<hasil;
    cout<<endl<<"Present Value Annuity : "<<fv;
    cout<<endl;
}
