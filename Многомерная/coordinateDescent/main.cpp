#include <iostream>
#include <cmath>

using namespace std;

double func(double x, double y){
    return (x*x*x*x + y*y*y*y + x*x + y*y + x*x*y*y);
}

double funcX(double x, double y){
    return (4*x*x*x+2*x+2*x*y*y);
}

double funcY(double x, double y){
    return (4*y*y*y+2*y+2*y*x*x);
}

double norm(double x, double y){
    return sqrt(funcX(x, y)*funcX(x, y) + funcY(x, y)*funcY(x, y));
}

int main()
{
    double x, y, x0, y0;
    double alpha = 0.05;
    double eps = 0.05;
    x0 = 1; y0 = 1;
    x =1; y = 1;
    while(norm(x,y) > 0.05){
        x = x0 - alpha*funcX(x0, y0);
        y = y0 - alpha*funcY(x0, y0);
        x0 = x;
        y0 = y;
        cout << x << "   " << y  << "  " << funcX(x,y)<< endl;
    }
    cout << x << "  " << y << "  " << norm(x,y) << endl;
}
