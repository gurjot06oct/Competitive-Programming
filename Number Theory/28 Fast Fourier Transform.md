# Fast Fourier Transform (FFT)

In this article, we will discuss an algorithm that allows us to multiply two polynomials of length $ n $ in $ O(n \log n) $ time, which is significantly faster than the trivial multiplication algorithm that takes $ O(n^2) $ time. Multiplying two long numbers can be reduced to multiplying polynomials, so this method also enables the multiplication of two long numbers in $ O(n \log n) $ time, where $ n $ is the number of digits in the numbers.

The Fast Fourier Transform (FFT) algorithm was published by Cooley and Tukey in 1965, though it had been discovered repeatedly before but its importance wasn't recognized until the advent of modern computers. Some researchers attribute the discovery to Runge and König in 1924, but Gauss developed such a method as early as 1805 without publishing it.

The FFT algorithm presented here runs in $ O(n \log n) $ time, making it suitable for multiplying polynomials of size $ 10^5 $ with small coefficients, or multiplying two numbers of size $ 10^6 $. For numbers beyond $ 10^6 $ bits, the precision of floating point numbers may not be sufficient for accurate results. However, more complex variations can handle arbitrary large polynomial/integer multiplications, such as the algorithm developed by Schönhage and Strasser in 1971, which runs in $ O(n \log n \log \log n) $, and the true $ O(n \log n) $ algorithm by Harvey and van der Hoeven published in 2019.

## Discrete Fourier Transform (DFT)

Consider a polynomial of degree $ n - 1 $:

 $ A(x) = a*0 + a_1 x + \dots + a*{n-1} x^{n-1} $

Assume $ n $ (the number of coefficients) is a power of 2. If $ n $ is not a power of 2, we add the necessary terms with coefficients set to 0.

The theory of complex numbers tells us that the equation $ x^n = 1 $ has $ n $ complex solutions, called the $ n $-th roots of unity, given by:

 $ \omega\_{n, k} = e^{\frac{2 k \pi i}{n}} \quad \text{for } k = 0, \dots, n-1 $

These roots have interesting properties, such as the principal $ n $-th root $ \omega*n = \omega*{n, 1} = e^{\frac{2 \pi i}{n}} $, which can be used to describe all other $ n $-th roots:

 $ \omega\_{n, k} = (\omega_n)^k $

The Discrete Fourier Transform (DFT) of the polynomial $ A(x) $ (or the vector of coefficients $ (a*0, a_1, \dots, a*{n-1}) $) is defined as the values of the polynomial at the points $ x = \omega\_{n, k} $:

 $ \text{DFT}(a*0, a_1, \dots, a*{n-1}) = (y*0, y_1, \dots, y*{n-1}) = (A(\omega*{n, 0}), A(\omega*{n, 1}), \dots, A(\omega\_{n, n-1})) = (A(\omega_n^0), A(\omega_n^1), \dots, A(\omega_n^{n-1})) $

Similarly, the inverse Discrete Fourier Transform (IDFT) is defined as the inverse process, restoring the coefficients from the values at the $ n $-th roots of unity:

 $ \text{InverseDFT}(y*0, y_1, \dots, y*{n-1}) = (a*0, a_1, \dots, a*{n-1}) $

Thus, the DFT computes the values of the polynomial at the $ n $-th roots, and the inverse DFT can restore the coefficients using those values.

## Application of the DFT: Fast Multiplication of Polynomials

Let there be two polynomials $ A $ and $ B $. We compute the DFT for each of them: $ \text{DFT}(A) $ and $ \text{DFT}(B) $.

To multiply these polynomials, we simply multiply their values at each point:

 $ (A \cdot B)(x) = A(x) \cdot B(x) $

This means that if we multiply the vectors $ \text{DFT}(A) $ and $ \text{DFT}(B) $ element-wise, we obtain the DFT of the product polynomial:

 $ \text{DFT}(A \cdot B) = \text{DFT}(A) \cdot \text{DFT}(B) $

Finally, applying the inverse DFT, we obtain the coefficients of the product polynomial:

 $ A \cdot B = \text{InverseDFT}(\text{DFT}(A) \cdot \text{DFT}(B)) $

This element-wise product can be computed in $ O(n) $ time. Therefore, if we can compute the DFT and the inverse DFT in $ O(n \log n) $, we can compute the product of two polynomials (and consequently two long numbers) with the same time complexity.

To ensure the polynomials have the same degree, we can pad them with coefficients of 0. Additionally, since the product of two polynomials results in a polynomial of degree $ 2(n - 1) $, we need to pad the polynomials to double their degree before applying the FFT.

Here's a clear and concise explanation of the FFT and its application in polynomial multiplication, suitable for competitive programming and other computational tasks involving large polynomials or numbers.

## Fast Fourier Transform (FFT)

The Fast Fourier Transform (FFT) is an efficient method for computing the Discrete Fourier Transform (DFT) in $O(n \log n) $ time. The basic idea of FFT is to apply the divide-and-conquer strategy: we divide the coefficient vector of the polynomial into two smaller vectors, recursively compute the DFT for each of them, and combine the results to compute the DFT of the complete polynomial.

Consider a polynomial $A(x) $ of degree $n - 1$, where $n $ is a power of $2 $ and $n > 1$:

 $ A(x) = a*0 + a_1 x + \dots + a*{n-1} x^{n-1} $

We divide this polynomial into two smaller polynomials: one containing the coefficients of the even-indexed terms and the other containing the coefficients of the odd-indexed terms:

$
\begin{aligned}
A_0(x) &= a_0 + a_2 x + \dots + a_{n-2} x^{\frac{n}{2}-1} \\
A_1(x) &= a_1 + a_3 x + \dots + a_{n-1} x^{\frac{n}{2}-1}
\end{aligned}
$

It is straightforward to see that:

 $ A(x) = A_0(x^2) + x A_1(x^2) $

The polynomials $A_0 $ and $A_1 $ have half as many coefficients as the polynomial $A$. If we can compute the $\text{DFT}(A) $ in linear time using $\text{DFT}(A_0) $ and $\text{DFT}(A_1)$, we get the recurrence:

 $ T*{\text{DFT}}(n) = 2 T*{\text{DFT}}\left(\frac{n}{2}\right) + O(n) $

Applying the master theorem, this results in:

 $ T\_{\text{DFT}}(n) = O(n \log n) $

Now, let's see how we can accomplish this.

Suppose we have computed the vectors $\left(y_k^0\right)_{k=0}^{n/2-1} = \text{DFT}(A_0) $ and $\left(y_k^1\right)_{k=0}^{n/2-1} = \text{DFT}(A_1)$. We need to find an expression for $\left(y_k\right)_{k=0}^{n-1} = \text{DFT}(A)$.

For the first $\frac{n}{2} $ values, we can use the previously noted equation $A(x) = A_0(x^2) + x A_1(x^2)$:

 $ y_k = y_k^0 + \omega_n^k y_k^1, \quad k = 0 \dots \frac{n}{2} - 1 $

For the second $\frac{n}{2} $ values, we need a slightly different expression:

$
\begin{aligned}
y_{k+n/2} &= A(\omega_n^{k+n/2}) \\
           &= A_0(\omega_n^{2k+n}) + \omega_n^{k+n/2} A_1(\omega_n^{2k+n}) \\
           &= A_0(\omega_n^{2k} \omega_n^n) + \omega_n^k \omega_n^{n/2} A_1(\omega_n^{2k} \omega_n^n) \\
           &= A_0(\omega_n^{2k}) - \omega_n^k A_1(\omega_n^{2k}) \\
           &= y_k^0 - \omega_n^k y_k^1
\end{aligned}
$

Here, we used the identities $\omega_n^n = 1 $ and $\omega_n^{n/2} = -1$.

Thus, we get the desired formulas for computing the whole vector $(y_k)$:

$
\begin{aligned}
y_k &= y_k^0 + \omega_n^k y_k^1, &\quad k = 0 \dots \frac{n}{2} - 1 \\
y_{k+n/2} &= y_k^0 - \omega_n^k y_k^1, &\quad k = 0 \dots \frac{n}{2} - 1
\end{aligned}
$

This pattern $(a + b) $ and $(a - b) $ is sometimes called a butterfly.

Thus, we have learned how to compute the DFT in $O(n \log n) $ time using the FFT algorithm.

### Inverse FFT (IFFT)

Given a vector $(y_0, y_1, \dots, y_{n-1})$, which represents the values of a polynomial $A $ of degree $n - 1 $ at the points $x = \omega_n^k$, we want to restore the coefficients $(a_0, a_1, \dots, a_{n-1}) $ of the polynomial. This problem, known as interpolation, can be simplified significantly because the points are at the roots of unity, allowing us to use a method similar to the direct FFT.

We can express the DFT in matrix form:

$
\begin{pmatrix}
\omega_n^0 & \omega_n^0 & \omega_n^0 & \omega_n^0 & \cdots & \omega_n^0 \\
\omega_n^0 & \omega_n^1 & \omega_n^2 & \omega_n^3 & \cdots & \omega_n^{n-1} \\
\omega_n^0 & \omega_n^2 & \omega_n^4 & \omega_n^6 & \cdots & \omega_n^{2(n-1)} \\
\omega_n^0 & \omega_n^3 & \omega_n^6 & \omega_n^9 & \cdots & \omega_n^{3(n-1)} \\
\vdots & \vdots & \vdots & \vdots & \ddots & \vdots \\
\omega_n^0 & \omega_n^{n-1} & \omega_n^{2(n-1)} & \omega_n^{3(n-1)} & \cdots & \omega_n^{(n-1)(n-1)}
\end{pmatrix}
\begin{pmatrix}
a_0 \\
a_1 \\
a_2 \\
a_3 \\
\vdots \\
a_{n-1}
\end{pmatrix}
=
\begin{pmatrix}
y_0 \\
y_1 \\
y_2 \\
y_3 \\
\vdots \\
y_{n-1}
\end{pmatrix}
$

This matrix is known as the Vandermonde matrix.

To compute the vector $(a_0, a_1, \dots, a_{n-1})$, we multiply the vector $(y_0, y_1, \dots, y_{n-1}) $ by the inverse of the Vandermonde matrix:

$
\begin{pmatrix}
a_0 \\
a_1 \\
a_2 \\
a_3 \\
\vdots \\
a_{n-1}
\end{pmatrix}
=
\begin{pmatrix}
\omega_n^0 & \omega_n^0 & \omega_n^0 & \omega_n^0 & \cdots & \omega_n^0 \\
\omega_n^0 & \omega_n^1 & \omega_n^2 & \omega_n^3 & \cdots & \omega_n^{n-1} \\
\omega_n^0 & \omega_n^2 & \omega_n^4 & \omega_n^6 & \cdots & \omega_n^{2(n-1)} \\
\omega_n^0 & \omega_n^3 & \omega_n^6 & \omega_n^9 & \cdots & \omega_n^{3(n-1)} \\
\vdots & \vdots & \vdots & \vdots & \ddots & \vdots \\
\omega_n^0 & \omega_n^{n-1} & \omega_n^{2(n-1)} & \omega_n^{3(n-1)} & \cdots & \omega_n^{(n-1)(n-1)}
\end{pmatrix}^{-1}
\begin{pmatrix}
y_0 \\
y_1 \\
y_2 \\
y_3 \\
\vdots \\
y_{n-1}
\end{pmatrix}
$

The inverse of the matrix has the following form:

$
\frac{1}{n}
\begin{pmatrix}
\omega_n^0 & \omega_n^0 & \omega_n^0 & \omega_n^0 & \cdots & \omega_n^0 \\
\omega_n^0 & \omega_n^{-1} & \omega_n^{-2} & \omega_n^{-3} & \cdots & \omega_n^{-(n-1)} \\
\omega_n^0 & \omega_n^{-2} & \omega_n^{-4} & \omega_n^{-6} & \cdots & \omega_n^{-2(n-1)} \\
\omega_n^0 & \omega_n^{-3} & \omega_n^{-6} & \omega_n^{-9} & \cdots & \omega_n^{-3(n-1)} \\
\vdots & \vdots & \vdots & \vdots & \ddots & \vdots \\
\omega_n^0 & \omega_n^{-(n-1)} & \omega_n^{-2(n-1)} & \omega_n^{-3(n-1)} & \cdots & \omega_n^{-(n-1)(n-1)}
\end{pmatrix}
$

Thus, we obtain the formula:

$
a_k = \frac{1}{n} \sum_{j=0}^{n-1} y_j \omega_n^{-k j}
$

Comparing this to the formula for $y_k$:

$
y_k = \sum_{j=0}^{n-1} a_j \omega_n^{k j},
$

we see that these problems are very similar. Therefore, the coefficients $a_k $ can be found using the same divide-and-conquer algorithm as the direct FFT, but with $\omega_n^k $ replaced by $\omega_n^{-k}$, and by dividing the resulting coefficients by $n$.

Thus, the computation of the inverse DFT (IFFT) is almost the same as the calculation of the direct DFT, and it can also be performed in $O(n \log n) $ time.

## Implementation

Here's an improved implementation of the FFT and the inverse FFT in C++. We use the `complex` type from the C++ Standard Library to store complex numbers.

```cpp
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; ++i) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; ++i)
        result[i] = round(fa[i].real());
    return result;
}

void normalize(vector<int>& result) {
    int carry = 0;
    for (int i = 0; i < result.size(); ++i) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};

    vector<int> result = multiply(a, b);
    normalize(result);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

### Explanation

1. **FFT Function**:

   - The function `fft` takes a vector of complex numbers `a` and a boolean `invert`.
   - If `invert` is true, it computes the inverse FFT.
   - The vector `a` is split into two smaller vectors, `a0` and `a1`, containing the even and odd indexed elements, respectively.
   - The FFT is recursively applied to these smaller vectors.
   - The values are then combined using the FFT formulas, and if `invert` is true, the results are divided by 2.

2. **Polynomial Multiplication**:

   - The `multiply` function takes two vectors of integers `a` and `b`, representing the coefficients of two polynomials.
   - It converts these vectors to vectors of complex numbers and resizes them to the next power of two.
   - The FFT is applied to both vectors.
   - The element-wise product of the transformed vectors is computed.
   - The inverse FFT is applied to the product to get the coefficients of the resulting polynomial.
   - The real parts of the complex numbers are rounded to the nearest integer to get the final coefficients.

3. **Normalization**:
   - The `normalize` function handles carry operations for the resulting vector, ensuring each digit is between 0 and 9.

This implementation provides a clear and efficient way to compute the FFT and inverse FFT, and to use them for polynomial multiplication. It ensures accuracy by handling carry operations properly and rounding the results.

## Improved Implementation: In-Place Computation

To increase efficiency, we switch from a recursive to an iterative implementation of FFT. This allows us to perform calculations "in-place" without the need for additional memory. Here's the code for the iterative FFT with in-place computation:

```cpp
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;
using cd = complex<double>;
const double PI = acos(-1);

// Iterative in-place FFT function
void fft(vector<cd>& a, bool invert) {
    int n = a.size();

    // Bit-reversal permutation
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;

        if (i < j) swap(a[i], a[j]);
    }

    // Iterative FFT
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd& x : a)
            x /= n;
    }
}

// Function to multiply two polynomials
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; ++i)
        result[i] = round(fa[i].real());
    return result;
}

// Function to normalize the result
void normalize(vector<int>& result) {
    int carry = 0;
    for (int i = 0; i < result.size(); ++i) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};

    vector<int> result = multiply(a, b);
    normalize(result);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

### Explanation

1. **Bit-Reversal Permutation**:

   - This step reorders the elements of the vector according to their bit-reversed indices, enabling us to perform the FFT in-place.
   - The `bit-reversal permutation` ensures that elements that will interact during the FFT are close to each other in the array.

2. **Iterative FFT**:

   - Instead of recursively splitting the array, we iteratively combine smaller sub-arrays into larger ones.
   - For each length `len`, we compute the FFT for blocks of size `len`.
   - The `wlen` variable represents the complex root of unity used in the butterfly operations.
   - The butterfly operations combine pairs of elements in the array, gradually building up the FFT results.

3. **Multiplication of Polynomials**:

   - The `multiply` function converts the input vectors to vectors of complex numbers and resizes them to the next power of two.
   - After applying the FFT to both vectors, it performs element-wise multiplication of the transformed vectors.
   - The inverse FFT is applied to the product, and the real parts of the complex numbers are rounded to get the final coefficients.

4. **Normalization**:
   - The `normalize` function handles carry operations, ensuring each digit is between 0 and 9.
   - This step is crucial when dealing with the result of polynomial multiplication, as it ensures the final digits are correctly formed.

This implementation improves efficiency by performing the FFT in-place and avoiding the need for additional memory allocation, making it more suitable for larger input sizes.

### Number Theoretic Transform

We still aim to multiply two polynomials in $ O(n \log n) $ time, but now we want the coefficients to be computed modulo some prime number $ p $. While we could use the standard DFT and then apply the modulo operator, this approach can lead to rounding errors, especially with large numbers. The Number Theoretic Transform (NTT) only works with integers, ensuring accurate results.

The discrete Fourier transform relies on complex numbers and $ n $-th roots of unity. To efficiently compute it, we use properties of these roots, like the existence of a generator root that can produce all other roots through exponentiation.

These properties also hold for $ n $-th roots of unity in modular arithmetic. An $ n $-th root of unity in a finite field is a number $ w_n $ that satisfies:

 $ w_n^n \equiv 1 \pmod{p} $
 $ w_n^k \not\equiv 1 \pmod{p}, \quad 1 \le k < n $

The other $ n-1 $ roots can be obtained as powers of $ w_n $.

To use NTT in the FFT algorithm, we need a root to exist for some $ n $, a power of $ 2 $, and for all smaller powers. We use an important property:

 $ (w_n^2)^m = w_n^n \equiv 1 \pmod{p}, \quad \text{with } m = \frac{n}{2} $
 $ (w_n^2)^k \not\equiv 1 \pmod{p}, \quad 1 \le k < m $

Thus, if $ w_n $ is an $ n $-th root of unity, then $ w_n^2 $ is a $ \frac{n}{2} $-th root of unity. This ensures the existence of roots for all smaller powers of two.

For the inverse DFT, we need the inverse $ w_n^{-1} $ of $ w_n $, which always exists for a prime modulus.

The properties of complex roots are thus available in modular arithmetic, provided we have a large enough modulus $ p $ where an $ n $-th root of unity exists.

For example, we can take $ p = 7340033 $ and $ w\_{2^{20}} = 5 $. If this modulus is insufficient, we need to find a different pair. Modules of the form $ p = c \cdot 2^k + 1 $ (with $ p $ prime) always have the $ 2^k $-th root of unity. $ g^c $ is such a root, where $ g $ is a primitive root of $ p $.

Here's the implementation of NTT:

```cpp
#include <iostream>
#include <vector>
#include <cmath>

const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

int inverse(int a, int p) {
    int res = 1, n = p - 2;
    while (n) {
        if (n & 1) res = (1LL * res * a) % p;
        a = (1LL * a * a) % p;
        n >>= 1;
    }
    return res;
}

void fft(std::vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            std::swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

int main() {
    std::vector<int> a = {1, 2, 3, 4}; // Example input
    fft(a, false); // Perform NTT
    fft(a, true);  // Perform inverse NTT
    for (int x : a) std::cout << x << ' '; // Output the result
    return 0;
}
```

### Multiplication with Arbitrary Modulus

When the modulus $ M $ is not suitable for NTT, one option is to perform multiple NTTs with different primes of the form $ c \cdot 2^k + 1 $, then use the Chinese Remainder Theorem (CRT) to combine the results.

Another option is to split the polynomials $ A(x) $ and $ B(x) $ into smaller parts:

 $ A(x) = A_1(x) + A_2(x) \cdot C $
 $ B(x) = B_1(x) + B_2(x) \cdot C $

where $ C \approx \sqrt{M} $.

Then,

 $ A(x) \cdot B(x) = A_1(x) \cdot B_1(x) + \left(A_1(x) \cdot B_2(x) + A_2(x) \cdot B_1(x)\right) \cdot C + \left(A_2(x) \cdot B_2(x)\right) \cdot C^2 $

The polynomials $ A_1(x), A_2(x), B_1(x), B_2(x) $ have coefficients smaller than $ \sqrt{M} $, so the coefficients of their products are manageable with standard floating point types. This method involves computing products of polynomials with smaller coefficients using the regular FFT and then restoring the original product using modular addition and multiplication in $ O(n) $ time.

## Applications

### All Possible Sums

Given two arrays $ a[] $ and $ b[] $, we need to find all possible sums $ a[i] + b[j] $ and count their occurrences.

For example, with $ a = [1, 2, 3] $ and $ b = [2, 4] $:

- The sum 3 appears 1 time,
- The sum 4 appears 1 time,
- The sum 5 appears 2 times,
- The sum 6 appears 1 time,
- The sum 7 appears 1 time.

To solve this, we represent arrays $ a $ and $ b $ as polynomials $ A(x) $ and $ B(x) $, where each element acts as an exponent and its count as the coefficient:

 $ A(x) = 1 \cdot x^1 + 1 \cdot x^2 + 1 \cdot x^3 $
 $ B(x) = 1 \cdot x^2 + 1 \cdot x^4 $

Multiplying these two polynomials gives us $ C(x) $:

 $ C(x) = (1 \cdot x^1 + 1 \cdot x^2 + 1 \cdot x^3) \cdot (1 \cdot x^2 + 1 \cdot x^4) = 1 \cdot x^3 + 1 \cdot x^4 + 2 \cdot x^5 + 1 \cdot x^6 + 1 \cdot x^7 $

Here, the exponents of $ C(x) $ represent possible sums, and the coefficients represent their counts.

#### All Possible Scalar Products

Given two arrays $ a[] $ and $ b[] $, compute the products $ a $ with every cyclic shift of $ b $.

Construct two new arrays of size $ 2n $: reverse $ a $ and append $ n $ zeros, and append $ b $ to itself. By multiplying these two arrays as polynomials, the coefficients $ c[k] $ of the product $ c $ give:

 $ c[k] = \sum\_{i+j=k} a[i] b[j] $

Since $ a[i] = 0 $ for $ i \geq n $:

 $ c[k] = \sum\_{i=0}^{n-1} a[i] b[k-i] $

This sum represents the scalar product of the vector $ a $ with the $ (k - (n - 1)) $-th cyclic left shift of $ b $.

### Two Stripes

Given two Boolean stripes $ a $ and $ b $, find all ways to attach $ a $ to $ b $ such that no $ 1 $ of $ a $ is next to a $ 1 $ of $ b $.

This problem reduces to finding if the scalar product of $ a $ and a cyclic shift of $ b $ is $ 0 $.

### String Matching

Given two strings, a text $ T $ and a pattern $ P $, compute all occurrences of $ P $ in $ T $.

Represent $ T[i] $ and $ P[i] $ as numbers between $ 0 $ and $ 25 $ corresponding to the 26 letters of the alphabet:

 $ A(x) = \cos(\alpha_0) + i \sin(\alpha_0) + \cos(\alpha_1) + i \sin(\alpha_1) + \dots $
 $ B(x) = \cos(\beta_0) - i \sin(\beta_0) + \cos(\beta_1) - i \sin(\beta_1) + \dots $

The $ (m-1+i) $-th coefficient of $ C(x) = A(x) \cdot B(x) $ indicates if $ P $ appears in $ T $ at position $ i $:

 $ c*{m-1+i} = \sum*{j=0}^{m-1} \left( \cos(\alpha*{i+j}) + i \sin(\alpha*{i+j}) \right) \cdot \left( \cos(\beta_j) - i \sin(\beta_j) \right) $

If $ T[i+j] = P[j] $, then $ \alpha*{i+j} = \beta_j $, and $ c*{m-1+i} = m $. Otherwise, $ c\_{m-1+i} \neq m $.

#### String Matching with Wildcards

An extension where $ P $ can contain wildcard character $ _ $, matching any letter. Adjust $ B(x) $ to $ 0 $ if $ P[m-i-1] = _ $. The number of wildcards $ x $ adjusts the match criteria to $ c\_{m-1+i} = m - x $.
