
#include <iostream>
#include <cmath>

#define MAX_N 30
#define X 0.5
#define M_PI 3.141592
#define M_E 2.71


using namespace std;

inline double poper_transf(double poper, int k, const double x) {
    poper = pow(-1,k)*poper * (2 * k - 1) * x * x / (k * (2 * k + 1));
    return poper;
}


double zavd1(double x = X) {
    double poper = x;
    double sum = poper;
    for (int i = 1; i <= MAX_N; i++) {
        poper = poper_transf(poper, i, x);
        sum += poper;
    }
    return sum;
}


template <int N>
inline double zavd2(double poper, const double x)
{
    return poper + zavd2<N+1>(poper_transf(poper, N, x), x);
}

template<>
inline double zavd2<MAX_N>(double prev, const double x_2) {

    return prev + poper_transf(prev, MAX_N, x_2);
}

double zavd2(double x = X, int n = MAX_N) {

    return zavd2<1>(x, x);
}



int main(int, char**)
{
    cout << "Value of S(x=.5, n=30): zavd1 - " << zavd1() << "; zavd2 - " << zavd2() << "\n\n";

}