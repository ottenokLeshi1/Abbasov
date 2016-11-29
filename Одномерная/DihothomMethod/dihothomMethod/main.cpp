#include <iostream>

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
    cout <<"Write deltha"<< endl;
    cin >> deltha;

    while(true){
    c = (a+b)/2 - deltha/2;
    d = (a+b)/2 + deltha/2;
    fc = func(c);
    countf++;
    fd = func(d);
    countf++;
    if (fc <= fd){
        b = d;
    } else {
        a = c;
    }
    if (((b - a)/2) < eps) break;
    }
    cout << endl << "MinF = " << func((a+b)/2) << endl;
    cout << "Minx = " << (a+b)/2 << endl;
    cout << "Count of function calculating "<< countf << endl;
}
