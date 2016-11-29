#include <iostream>
#include <cmath>

using namespace std;

double funcDer(double x){
    return (2*x);
}

double func(double x){
    return x*x;
}


//k1 * x + a = k2 * x + b

int main()
{

    double a, b, c;
    double eps;
    double minX, minF;

    cout <<"Write a and b"<< endl;
    cin >> a >> b;
    //cout <<"Write eps"<< endl;
    //cin >> eps;
    eps = 0.5;
    while (abs(b-a) > eps){
        c = (func(a) - func(b) - funcDer(a) * a + funcDer(b) * b)/(funcDer(b) - funcDer(a));
        if (funcDer(c) > 0){
            b = c;
        }
        if(funcDer(c) < 0){
            a = c;
        }
        if (funcDer(c) == 0){
            break;
        }
    }
    minX = c;
    minF = func(minX);
    cout << "minX = " << minX << "    minF = " << minF << endl;
    return 0;
}
