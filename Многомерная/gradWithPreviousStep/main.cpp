#include <iostream>
#include <cmath>

using namespace std;

double func(double x, double y){
    return (x*x*x*x + y*y*y*y + x*x + y*y + x*x*y*y);
}

double funcX(double x, double y){
    return (4*x*x*x + 2*x + 2*x*y*y);
}

double funcY(double x, double y){
    return (4*y*y*y + 2*y + 2*y*x*x);
}

double norm(double x, double y){
    return sqrt(funcX(x, y)*funcX(x, y) + funcY(x, y)*funcY(x, y));
}

int main(){
    double x, y, x0, y0;
    double k = 4;
    x0 = 1; y0 = 1;
    x =1; y = 1;

    x = x0 - funcX(x0, y0)/k;
    y = y0 - funcY(x0, y0)/k;
    while(norm(x,y) > 0.05){
        x0 = x;
        y0 = y;
        k = k + 1;
        x = x0 - funcX(x0, y0)/k;
        y = y0 - funcY(x0, y0)/k;
        //cout << k << "   " << 1/k<<"   " << x << "   " << y  << "  " << funcX(x,y)<< endl;
    }
    cout << x << "  " << y << "  " << func(x,y) << endl;
    //cout << k << "   " << t <<"   " << x << "   " << y  << "  " << funcX(x,y)<< endl;
}
