#include <assert.h>

#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <valarray>
#include <vector>

// Trick to allow type promotion below
// Makes complex work nice with integers
template <typename T>
struct identity_t { typedef T type; };

/// Make working with std::complex<> numbers suck less... allow promotion.
#define COMPLEX_OPS(OP)                                                                    \
    template <typename _Tp>                                                                \
    std::complex<_Tp>                                                                      \
    operator OP(std::complex<_Tp> lhs, const typename identity_t<_Tp>::type& rhs) {        \
        return lhs OP rhs;                                                                 \
    }                                                                                      \
    template <typename _Tp>                                                                \
    std::complex<_Tp>                                                                      \
    operator OP(const typename identity_t<_Tp>::type& lhs, const std::complex<_Tp>& rhs) { \
        return lhs OP rhs;                                                                 \
    }
COMPLEX_OPS(+)
COMPLEX_OPS(-)
COMPLEX_OPS(*)
COMPLEX_OPS(/)
#undef COMPLEX_OPS

#define _USE_MATH_DEFINES

using namespace std;
using namespace std::complex_literals;

typedef complex<double> Complex;
typedef std::valarray<Complex> CArray;

void fft(CArray& a) {
    auto N = a.size();
    if (N <= 1) return;

    CArray even = a[slice(0, N / 2, 2)];
    CArray odd = a[slice(1, N / 2, 2)];

    fft(even);
    fft(odd);

    for (int k = 0; k < N / 2; k++) {
        Complex t = polar(1.0, -2.0 * M_PI * k / N) * odd[k];
        a[k] = even[k] + t;
        a[k + N / 2] = even[k] - t;
    }
}

void ifft(CArray& a) {
    a = a.apply(std::conj);
    fft(a);
    a = a.apply(std::conj);
    a /= a.size();
}

CArray polymul(CArray& a, CArray& b) {
    fft(a);
    fft(b);
    CArray c = a * b;
    ifft(c);
    return c;
}

const long long lb = 50002;

void testCase() {
    int n;
    cin >> n;
    vector<long long> av(2000010);
    vector<long long> in(n);
    int zeroes = 0;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        zeroes += (in[i] == 0);
        in[i] += lb;
        av[in[i]]++;
    }
    n = pow(2, ceil(log(av.size()) / log(2)));
    CArray a(n);
    for (int i = 0; i < av.size(); i++) {
        a[i] = Complex(av[i]);
    }
    CArray b(n);
    for (int i = 0; i < av.size(); i++) {
        b[i] = Complex(av[i]);
    }

    fft(a);
    fft(b);
    CArray c = a * b;
    ifft(c);
    for (auto v : in) {
        c[v * 2] -= 1;
    }
    long long sum = 0;
    for (auto v : in) {
        sum += c[v + lb].real();
    }
    sum -= 2 * zeroes * (in.size() - 1);
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    testCase();
    return 0;
}
