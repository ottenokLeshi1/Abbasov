#include <iostream>
#include <cmath>

using namespace std;

double funcDer1(double x){
    return (1 - 2/(x*x));
}

double funcDer2(double x){
    return (4/(x*x*x));
}

double func(double x){
    return (x + 2/x);
}

int main()
{

    double a, eps;
    double c = 1000000;

    double minX, minF;

    cout <<"Write first x0"<< endl;
    cin >> a;
    eps = 0.5;

    while (abs(funcDer1(c)) > eps){
        c = a - funcDer1(a)/funcDer2(a);
        a = c;
        cout << "c = " << c << "   funcDec = " << funcDer1(c) << endl;
    }
    minX = c;
    minF = func(minX);

    cout << "minX = " << minX << "    minF = " << minF << endl;
    return 0;
}
