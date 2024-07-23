# Fibonacci Numbers

## The Fibonacci Sequence

The Fibonacci sequence is defined as follows:

$F_0 = 0, \, F_1 = 1, \, F_n = F_{n-1} + F_{n-2}$

The first elements of the sequence (OEIS A000045) are:

$0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \ldots$

## Properties

Fibonacci numbers possess many interesting properties. Here are a few of them:

### Cassini's Identity

$F_{n-1} F_{n+1} - F_n^2 = (-1)^n$

### The "Addition" Rule

$F_{n+k} = F_k F_{n+1} + F_{k-1} F_n$

Applying the previous identity to the case $ k = n $, we get:

$F_{2n} = F_n (F_{n+1} + F_{n-1})$

From this, we can prove by induction that for any positive integer $ k $, $ F\_{nk} $ is a multiple of $ F_n $.

The inverse is also true: if $ F_m $ is a multiple of $ F_n $, then $ m $ is a multiple of $ n $.

### GCD Identity

$GCD(F_m, F_n) = F_{GCD(m, n)}$

Fibonacci numbers are the worst possible inputs for the Euclidean algorithm (see Lame's theorem in the Euclidean algorithm).

## Fibonacci Coding

We can use the sequence to encode positive integers into binary code words. According to Zeckendorf's theorem, any natural number $ n $ can be uniquely represented as a sum of Fibonacci numbers:

$N = F_{k_1} + F_{k_2} + \ldots + F_{k_r}$

such that $ k_1 \ge k_2 + 2, \, k_2 \ge k_3 + 2, \, \ldots, \, k_r \ge 2 $ (i.e., the representation cannot use two consecutive Fibonacci numbers).

Any number can be uniquely encoded in Fibonacci coding. We can describe this representation with binary codes $ d*0 d_1 d_2 \ldots d_s 1 $, where $ d_i $ is $ 1 $ if $ F*{i+2} $ is used in the representation. The code will be appended by a $ 1 $ to indicate the end of the code word. This is the only occurrence where two consecutive 1-bits appear.

### Examples

$
\begin{aligned}
1 &= 1 &=& F_2 &=& (11)_F \\
2 &= 2 &=& F_3 &=& (011)_F \\
6 &= 5 + 1 &=& F_5 + F_2 &=& (10011)_F \\
8 &= 8 &=& F_6 &=& (000011)_F \\
9 &= 8 + 1 &=& F_6 + F_2 &=& (100011)_F \\
19 &= 13 + 5 + 1 &=& F_7 + F_5 + F_2 &=& (1001011)_F \\
\end{aligned}
$

### Encoding Algorithm

1. Iterate through the Fibonacci numbers from the largest to the smallest until you find one less than or equal to $ n $.
2. Suppose this number was $ F_i $. Subtract $ F_i $ from $ n $ and put a $ 1 $ in the $ i-2 $ position of the code word (indexing from 0 from the leftmost to the rightmost bit).
3. Repeat until there is no remainder.
4. Add a final $ 1 $ to the codeword to indicate its end.

### Decoding Algorithm

To decode a code word, first remove the final $ 1 $. Then, if the $ i $-th bit is set (indexing from 0 from the leftmost to the rightmost bit), sum $ F\_{i+2} $ to the number.

## Formulas for the $ n^{\text{th}} $ Fibonacci Number

### Closed-form Expression

There is a formula known as "Binet's formula," even though it was already known by Moivre:

$
F_n = \frac{\left(\frac{1 + \sqrt{5}}{2}\right)^n - \left(\frac{1 - \sqrt{5}}{2}\right)^n}{\sqrt{5}}
$

This formula is easy to prove by induction, but it can be deduced with the help of the concept of generating functions or by solving a functional equation.

You can immediately notice that the second term's absolute value is always less than $ 1 $, and it also decreases very rapidly (exponentially). Hence the value of the first term alone is "almost" $ F_n $. This can be written strictly as:

$
F_n = \left[\frac{\left(\frac{1 + \sqrt{5}}{2}\right)^n}{\sqrt{5}}\right]
$

where the square brackets denote rounding to the nearest integer.

These formulas require very high accuracy when working with fractional numbers and are of little use in practical calculations.

### Fibonacci in Linear Time

The $ n $-th Fibonacci number can be easily found in $ O(n) $ by computing the numbers one by one up to $ n $. However, there are also faster ways.

We can start from an iterative approach, taking advantage of the formula $ F*n = F*{n-1} + F\_{n-2} $. We will precalculate those values in an array, taking into account the base cases for $ F_0 $ and $ F_1 $.

```cpp
int fib(int n) {
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    return a;
}
```

In this way, we obtain a linear solution, $ O(n) $ time, saving all the values prior to $ n $ in the sequence.

## Matrix Form Approach

### Matrix Relation

The matrix relation for Fibonacci numbers is given by:

$ \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} ^ n = \begin{pmatrix} F*{n+1} & F*{n} \\ F*{n} & F*{n-1} \end{pmatrix} $

This allows us to compute $ F_n $ in $ O(\log n) $ time using matrix exponentiation.

### Pseduocode

### Matrix Struct Definition

```plaintext
struct Matrix:
    int[][] mat

Matrix multiply(Matrix a, Matrix b):
    // Multiplies two matrices a and b
    c = new Matrix()
    for i from 0 to 1:
        for j from 0 to 1:
            c.mat[i][j] = 0
            for k from 0 to 1:
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j]
    return c

Matrix matPow(Matrix base, int n):
    // Computes base^n using matrix exponentiation
    ans = identity matrix
    while n > 0:
        if n is odd:
            ans = multiply(ans, base)
        base = multiply(base, base)
        n = n / 2
    return ans
```

### Fibonacci Function Using Matrix Exponentiation

```plaintext
Fibonacci(n):
    if n == 0:
        return 0
    base = Matrix({{1, 1}, {1, 0}})
    result = matPow(base, n - 1)
    return result.mat[0][0]
```

## Fast Doubling Method

### Expansion and Equations

By expanding the matrix expression for $ n = 2 \cdot k $:

$ \begin{pmatrix} F*{2k+1} & F*{2k} \\ F*{2k} & F*{2k-1} \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^{2k} = \begin{pmatrix} F*{k+1} & F*{k} \\ F*{k} & F*{k-1} \end{pmatrix} ^2 $

We derive the simpler equations:

$
\begin{aligned}
F_{2k+1} &= F_{k+1}^2 + F_{k}^2 \\
F_{2k} &= F_k(F_{k+1} + F_{k-1}) = F_k (2F_{k+1} - F_{k})
\end{aligned}
$

### Fast Doubling Function

```
FibonacciFast(n):
    if n == 0:
        return 0, 1
    if n == 1:
        return 1, 1
    halfFib1, halfFib2 = FibonacciFast(n / 2)
    fib1 = halfFib1 * (2 * halfFib2 - halfFib1)
    fib2 = halfFib1 * halfFib1 + halfFib2 * halfFib2
    if n is odd:
        return fib1, fib1 + fib2
    else:
        return fib1, fib2
```

## Periodicity Modulo $ p $

### Proof of Periodicity

1. **Fibonacci Sequence**:
   The Fibonacci sequence is defined as:

   $
   F_0 = 0, \quad F_1 = 1, \quad \text{and} \quad F_n = F_{n-1} + F_{n-2} \quad \text{for} \quad n \geq 2
   $

2. **Modulo Operation**:
   The Fibonacci sequence modulo $ p $ is obtained by taking each Fibonacci number and reducing it modulo $ p $:

   $
   F_n \mod p
   $

3. **Periodicity**:
   We want to prove that the Fibonacci sequence modulo $ p $ is periodic, meaning it repeats after a certain number of terms. This repeating length is called the Pisano period.

### Proof by Contradiction Using the Pigeonhole Principle

1. **Assumption**:
   Consider the sequence of Fibonacci numbers modulo $ p $. Since each Fibonacci number modulo $ p $ can take on values from $ 0 $ to $ p-1 $, there are $ p $ possible values for each Fibonacci number modulo $ p $.

2. **Pairs of Consecutive Numbers**:
   Look at the pairs of consecutive Fibonacci numbers modulo $ p $. Each pair $(F_n, F_{n+1}) \mod p$ can take on at most $ p^2 $ different values (since there are $ p $ possibilities for each number in the pair).

3. **Length of Sequence**:
   If we consider $ p^2 + 1 $ pairs of consecutive Fibonacci numbers, by the pigeonhole principle, at least two of these pairs must be identical because there are only $ p^2 $ possible pairs but $ p^2 + 1 $ pairs in our list.

4. **Conclusion**:
   If two pairs are identical, say $(F_i, F_{i+1}) \equiv (F_j, F_{j+1}) \mod p$ for some $ i \neq j $, then the sequence must repeat starting from $ (F*i, F*{i+1}) $. This proves that the Fibonacci sequence modulo $ p $ is periodic.

### Pseudocode

```
function FibonacciPeriodicity(p):
    fib1 = 0
    fib2 = 1
    for i from 2 to p * p + 1:
        fib1, fib2 = fib2, (fib1 + fib2) % p
        if fib1 == 0 and fib2 == 1:
            return i - 1
    return -1  # Not found
```

### Example

Suppose $ p = 5 $:

- The Fibonacci sequence modulo 5 is: $ 0, 1, 1, 2, 3, 0, 3, 3, 1, 4, 0, 4, 4, 3, 2, 0, 2, 2, 4, 1, 0, 1, \ldots $
- The period length (Pisano period) for $ p = 5 $ is 20.

By running the pseudocode, the function will identify the periodicity as 20, thus confirming the theoretical result.

This structured approach provides a clear understanding of the periodicity of Fibonacci numbers modulo $ p $ and a practical method to compute the Pisano period.
