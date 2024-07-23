# Roots of Unity

Roots of unity are complex numbers that, when raised to a certain positive integer power$$n $, result in 1. They play a crucial role in various fields of mathematics, including polynomial equations, Fourier transforms, and group theory.

## Definition

An$$n $-th root of unity is a complex number$$\omega$$such that:

$$\omega^n = 1 $

There are$$n$$distinct$$n $-th roots of unity, given by:

$$\omega_k = e^{2\pi i k / n} $

for$$k = 0, 1, 2, \ldots, n-1 $.

## Basic Properties

1. **Periodicity**:$$\omega_n^n = 1 $
  $$\omega_n^k = \omega_n^{k \mod n} $
   This property shows that the sequence of powers of a root of unity repeats every$$n$$steps.

2. **Sum**: The sum of all$$n $-th roots of unity is zero.
  $$\sum\_{k=0}^{n-1} \omega_k = 0 $
3. **Multiplicative Inverse**: The inverse of an$$n $-th root of unity$$\omega_k$$is its complex conjugate$$\omega_{-k} $.
  $$\omega*k \cdot \omega*{-k} = 1 $
4. **Symmetry**: The roots of unity are symmetrically distributed on the unit circle in the complex plane.

## Finding Roots of Unity

To find the$$n $-th roots of unity, we use the exponential form:

$$\omega_k = e^{2\pi i k / n} = \cos\left(\frac{2\pi k}{n}\right) + i \sin\left(\frac{2\pi k}{n}\right) $

for$$k = 0, 1, 2, \ldots, n-1 $.

# Examples

## 4th Roots of Unity

For$$n = 4 $:

$$\omega_0 = e^{2\pi i \cdot 0 / 4} = 1 $
$$\omega_1 = e^{2\pi i \cdot 1 / 4} = i $
$$\omega_2 = e^{2\pi i \cdot 2 / 4} = -1 $
$$\omega_3 = e^{2\pi i \cdot 3 / 4} = -i $

These roots are$$1, i, -1,$$and$$-i $.

# Pseudocode to Find Roots of Unity

Here's a simple pseudocode to find the$$n $-th roots of unity:

```cpp
function findRootsOfUnity(n):
    roots = []
    for k = 0 to n-1:
        angle = 2 * PI * k / n
        root = cos(angle) + i * sin(angle)
        roots.append(root)
    return roots
```

# Key Points

- **Evenly Spaced**: Roots of unity are evenly spaced around the unit circle.
- **Symmetry**: They exhibit symmetry about the real axis.
- **Applications**: Used in solving polynomial equations, Fourier transforms, and cyclic groups.

# Example in C++

Here's an example of finding and printing the$$n $-th roots of unity in C++:

```cpp
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

vector<cd> findRootsOfUnity(int n) {
    vector<cd> roots(n);
    for (int k = 0; k < n; ++k) {
        double angle = 2 * PI * k / n;
        roots[k] = polar(1.0, angle);
    }
    return roots;
}

int main() {
    int n = 4;  // Example for 4th roots of unity
    vector<cd> roots = findRootsOfUnity(n);
    for (auto &root : roots) {
        cout << root << endl;
    }
    return 0;
}
```

This C++ code calculates and prints the$$n $-th roots of unity. For$$n = 4 $, it will output$$1, i, -1,$$and$$-i $.
