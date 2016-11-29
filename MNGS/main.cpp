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

double funcDer1(double alpha, double x1, double fx, double y1, double fy){
    return func((x1 - alpha*fx), (y1 - alpha*fy));
}

double secantMin(double alpha, double x2, double y2 ){
    double x0, x1, eps;

    x0 = -5;
    x1 = 2;
    eps = 0.00001;

    //alpha = funcDer1(alpha, x2, funcX(x2, y2), y2, funcY(x2, y2));
    while (abs(funcDer1(alpha, x2, funcX(x2, y2), y2, funcY(x2, y2))) - eps > 0.000001 ){
        alpha = x1 - (x1 - x0)*funcDer1(x1, x2, funcX(x2, y2), y2, funcY(x2, y2))/(funcDer1(x1, x2, funcX(x2, y2), y2, funcY(x2, y2)) - funcDer1(x0, x2, funcX(x2, y2), y2, funcY(x2, y2)));
        x0 = x1;
        x1 = alpha;
        cout << x0 << "  " << x1 << "  " << alpha << endl;
    }

    return alpha;
}
int main(){
    double x, y, x0, y0;
    double alpha;
    x0 = 1; y0 = 1;
    x =1; y = 1;

    while(norm(x,y) > 0.05){
        x0 = x;
        y0 = y;
        alpha = secantMin(alpha, x0, y0);

        x = x0 - funcX(x0, y0)*alpha;
        y = y0 - funcY(x0, y0)*alpha;
    }

    cout << x << "  " << y << "  " << func(x,y) << endl;
    //cout << k << "   " << t <<"   " << x << "   " << y  << "  " << funcX(x,y)<< endl;
}
