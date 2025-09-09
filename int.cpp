#include <iostream>
#include <cmath>
#include <functional>

double integrate(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        result += f(a + i * h);
    }
    result *= h;
    return result;
}

int main() {
    // Example function: f(x) = x^2
    auto f = [](double x) { return x * x*x; };
    double a = 0.0;  
    double b = 1.0;  
    int n = 100;     

    double integral = integrate(f, a, b, n);
    std::cout << "The integral of x^3 from " << a << " to " << b << " is approximately: " << integral << std::endl;

    scanf (*/h);

    return 0;
}