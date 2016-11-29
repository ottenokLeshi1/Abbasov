#include <iostream>

using namespace std;

double func(double x){
    return (x+2/x);
}
int main()
{
    double a, b;
    double eps;
    double x;
    double f;
    double minf = 10000000, minx = 10000000;
    int k;
    int countf = 0;
    cout <<"Write a and b"<< endl;
    cin >> a >> b;
    cout <<"Write eps"<< endl;
    cin >> eps;

    k = (int)(b - a)/eps;

    for (int i = 0; i <= k; i++){
    x = a +eps*i;
    f = func(x);
    countf++;
    if (f < minf){
    minx = x;
    minf = func(x);
        }
    }
    cout << "MinF = " << minf << endl;
    cout << "Minx = " << minx << endl;
    cout << "Count of function calculating "<< countf;
}
