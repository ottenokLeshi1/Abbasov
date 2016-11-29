#include <iostream>
#include <math.h>

using namespace std;

double func(double x){
    return (x+2/x);
}
int main()
{
    double a, b, c, d;
    double eps;
    double deltha;
    double x;
    double fc, fd;
    double minf = 10000000, minx = 10000000;
    int countf = 0;

    cout <<"Write a and b"<< endl;
    cin >> a >> b;
    cout <<"Write eps"<< endl;
    cin >> eps;
    c = (3 - sqrt(5))*(b - a)/2 + a;
    d = (sqrt(5) - 1)*(b - a)/2 + a;
    fc = func(c);
    countf++;
    fd = func(d);
    countf++;
    while(true){
    if (fc <= fd){
        b = d;
        d = c;
        c = (3 - sqrt(5))*(b - a)/2 + a;
        fd = fc;
        fc = func(c);
        countf++;
    } else {
        a = c;
        c = d;
        d = (sqrt(5) - 1)*(b - a)/2 + a;
        fc = fd;
        fd = func(d);
        countf++;
    }
    if (((b - a)/2) < eps) break;
    }
    cout << endl << "MinF = " << func((a+b)/2) << endl;
    cout << "Minx = " << (a+b)/2 << endl;
    cout << "Count of function calculating "<< countf << endl;
}
