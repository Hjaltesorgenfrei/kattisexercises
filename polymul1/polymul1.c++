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

void testCase() {
    int n1, n2;
    cin >> n1;
    n1++;
    vector<int> av(n1);
    for (int i = 0; i < n1; i++) {
        cin >> av[i];
    }
    cin >> n2;
    n2++;
    vector<int> bv(n2);
    for (int i = 0; i < n2; i++) {
        cin >> bv[i];
    }

    int n = pow(2, ceil(log(n1 + n2 - 1) / log(2)));
    CArray a(n);
    for (int i = 0; i < n1; i++) {
        a[i] = Complex(av[i]);
    }
    CArray b(n);
    for (int i = 0; i < n2; i++) {
        b[i] = Complex(bv[i]);
    }

    auto c = polymul(a, b);
    cout << n1 + n2 - 2 << "\n";
    for (int i = 0; i < n1 + n2 - 1; i++) {
        cout << (int)round(c[i].real()) << ((i + 1 < n1 + n2 - 1) ? " " : "");
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cases;
    cin >> cases;
    while (cases--) {
        testCase();
    }
    return 0;
}
