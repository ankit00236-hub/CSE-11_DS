#include<iostream>
using namespace std;
struct dis{
    int km;
    int m;
};
int main()
{
    dis d1, d2, sum;
    cout << "Enter first distance (km m): ";
    cin >> d1.km >> d1.m;
    cout << "Enter second distance (km m): ";
    cin >> d2.km >> d2.m;
    sum.km = d1.km + d2.km;
    sum.m = d1.m + d2.m;
    if(sum.m >= 1000) {
        sum.km += sum.m / 1000;
        sum.m = sum.m % 1000;
    }
    cout << "Sum of distances: " << sum.km << " km " << sum.m << " m" << endl;
    return 0;
}