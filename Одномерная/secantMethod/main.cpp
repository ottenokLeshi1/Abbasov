#include <iostream>
#include <cmath>

using namespace std;

double funcDer1(double x){
    return (2*(x));
}

int main()
{

    double x0, x1, x2, eps;

    double minX, minF;
    x0 = 0.5;
    x1 = 1.5;
    eps = 0.5;
    //x2 = x1;
    //cout << funcDer1(x0) << "  " <<  funcDer1(x1)<< endl;
    while (abs(funcDer1(x2)) > eps){
        x2 = x1 - ((x1 - x0)/(funcDer1(x1) - funcDer1(x0)))*funcDer1(x1);
        x0 = x1;
        x1 = x2;
        //cout << x0 << "  " << x1 << "  " << x2 << endl;
    }
    minX = x2;

    cout << x2 << endl;
    //cout << "minX = " << minX << "    minF = " << minF << endl;
    return 0;
}
