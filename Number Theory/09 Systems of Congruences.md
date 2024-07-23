# Systems of Congruences

## Chinese Remainder Theorem

The Chinese Remainder Theorem (CRT) is a powerful tool in number theory that provides a method to solve systems of simultaneous congruences with pairwise coprime moduli. It guarantees the existence and uniqueness of solutions within a certain range.

## Statement of the Chinese Remainder Theorem

Suppose we have a system of simultaneous congruences:

$ x \equiv a_1 \pmod{m_1} $

$ x \equiv a_2 \pmod{m_2} $

$ \vdots $

$ x \equiv a_k \pmod{m_k} $

where $ m_1, m_2, \ldots, m_k $ are pairwise coprime (i.e., $\gcd(m_i, m_j) = 1$ for all $i \neq j$).

Then there exists a unique solution $x$ modulo $M = m_1 m_2 \cdots m_k$. That is, there exists an integer $x$ such that:

$ x \equiv a_i \pmod{m_i} $

for all $i$, and this solution is unique modulo $M$.

## Proof Outline

1. **Existence**: To construct the solution, we use the fact that the moduli are pairwise coprime. Define $ M = m_1 m_2 \cdots m_k $.

   For each $i$, let $ M_i = \frac{M}{m_i} $. Since $ m_i $ is coprime with $ M_i $, there exists an integer $ y_i $ such that:
   $ M_i y_i \equiv 1 \pmod{m_i} $

   These $ y_i $ are the modular inverses of $ M_i $ modulo $ m_i $.

   Define:

   $
   x = \sum_{i=1}^k a_i M_i y_i
   $

   This $ x $ satisfies the system of congruences. For each $ i $:

   $ x \equiv a_i M_i y_i \pmod{m_i} $

   $ x \equiv a_i (1) \pmod{m_i} $

   $ x \equiv a_i \pmod{m_i} $

2. **Uniqueness**: Suppose $ x $ and $ x' $ are two solutions to the system. Then:
   $ x \equiv x' \pmod{m_i} $

   for all $i$. This implies:
   $ x \equiv x' \pmod{M} $

   Therefore, $ x $ is unique modulo $M$.

## Example

Consider the following system of congruences:

$ x \equiv 2 \pmod{3} $

$ x \equiv 3 \pmod{5} $

$ x \equiv 2 \pmod{7} $

We apply the Chinese Remainder Theorem to find $ x $.

1. Calculate $ M = 3 \times 5 \times 7 = 105 $.

2. For each modulus $ m_i $:

   - $ M_1 = \frac{105}{3} = 35 $
   - $ M_2 = \frac{105}{5} = 21 $
   - $ M_3 = \frac{105}{7} = 15 $

3. Find the modular inverses:

   - $ 35y_1 \equiv 1 \pmod{3} $

     - $ 35 \equiv 2 \pmod{3} $, and the inverse of $ 2 \pmod{3} $ is $ 2 $, so $ y_1 = 2 $.

   - $ 21y_2 \equiv 1 \pmod{5} $

     - $ 21 \equiv 1 \pmod{5} $, so $ y_2 = 1 $.

   - $ 15y_3 \equiv 1 \pmod{7} $

     - $ 15 \equiv 1 \pmod{7} $, so $ y_3 = 1 $.

4. Construct the solution:
   $ x = a_1 M_1 y_1 + a_2 M_2 y_2 + a_3 M_3 y_3 $

   $ x = 2 \times 35 \times 2 + 3 \times 21 \times 1 + 2 \times 15 \times 1 $

   $ x = 140 + 63 + 30 $

   $ x = 233 $

5. Find $ x $ modulo $ M $:
   $ x \equiv 233 \pmod{105} $

   $ x \equiv 23 \pmod{105} $

Thus, the solution to the system is:
$ x \equiv 23 \pmod{105} $

This $ x $ satisfies all the given congruences, demonstrating the power and utility of the Chinese Remainder Theorem.

## Sieving Method for the Chinese Remainder Theorem

The Chinese Remainder Theorem (CRT) helps solve systems of simultaneous congruences. The sieving method can make finding solutions faster by narrowing down potential values step by step. Here’s how it works:

### Step-by-Step Process

1. **Initial Setup:**

   - Assume you have a system of congruences:
     $
     x \equiv a_1 \mod n_1 \\
     x \equiv a_2 \mod n_2 \\
     \vdots \\
     x \equiv a_k \mod n_k
     $
   - Assume $0 \leq a_i < n_i$ for each $i$.

2. **Form the First Progression:**

   - Start with the first congruence $x \equiv a_1 \mod n_1$.
   - The possible values for $x$ are:
     $
     a_1, a_1 + n_1, a_1 + 2n_1, \ldots
     $
     This is an arithmetic progression where each term is $a_1 + kn_1$ for integer $k$.

3. **Test the Next Modulus:**

   - Take each value from the first progression and test it against the second congruence $x \equiv a_2 \mod n_2$.
   - Find the smallest value $x_2$ that satisfies both $x \equiv a_1 \mod n_1$ and $x \equiv a_2 \mod n_2$.

4. **Form the New Progression:**

   - Now $x_2$ becomes the base of a new arithmetic progression:
     $
     x_2, x_2 + n_1n_2, x_2 + 2n_1n_2, \ldots
     $
   - Each term is $x_2 + kn_1n_2$ for integer $k$.

5. **Repeat for All Moduli:**

   - Repeat the process with each new modulus $n_3, n_4, \ldots, n_k$.
   - Each step reduces the number of possible values for $x$ until you find the one that satisfies all the congruences.

### Example

To illustrate, consider you have these congruences:

$
x \equiv 4 \mod 5 \\
x \equiv 3 \mod 4 \\
x \equiv 1 \mod 3
$

1. **Start with $x \equiv 4 \mod 5$:**

   - Possible values: 4, 9, 14, 19, 24, 29, ...

2. **Test these values modulo 4 (next modulus):**

   - $4 \mod 4 = 0$ (not 3, so skip)
   - $9 \mod 4 = 1$ (not 3, so skip)
   - $14 \mod 4 = 2$ (not 3, so skip)
   - $19 \mod 4 = 3$ (satisfies $x \equiv 3 \mod 4$)
   - So, 19 is the smallest value that satisfies both $x \equiv 4 \mod 5$ and $x \equiv 3 \mod 4$.

3. **Form the new progression with 19:**

   - Possible values: 19, 39, 59, 79, ...

4. **Test these values modulo 3 (next modulus):**

   - $19 \mod 3 = 1$ (satisfies $x \equiv 1 \mod 3$)
   - So, 19 is the solution that satisfies all three congruences.

### Practical Considerations

- **Efficiency:** This method is efficient for hand calculations with a small number of moduli.
- **Complexity:** It becomes less practical with larger sets of moduli because the time complexity is exponential.
- **Computer Use:** For larger problems, more systematic and computational methods are used instead.

### Note

The system of congruences addressed by the Chinese Remainder Theorem (CRT) can be reformulated as a system of linear Diophantine equations. These equations can be expressed as:

$
\begin{aligned}
x &= a_1 + x_1 n_1 \\
&\vdots \\
x &= a_k + x_k n_k
\end{aligned}
$

where $x$ and $x_i$ are the unknown integers.

## Method of Successive Substitution

This method involves solving problems of simultaneous congruences by using the definition of the congruence equation.

### Example One

Consider the set of simultaneous congruences:

$ x \equiv 3 \pmod{4} $

$ x \equiv 5 \pmod{6} $

To solve these, we proceed as follows:

1. **Express $ x $ in terms of one congruence:**

   Since $ x \equiv 3 \pmod{4} $, we can write $ x = 3 + 4j $ for some integer $ j $.

2. **Substitute into the other congruence:**

   Substitute $ x = 3 + 4j $ into the second congruence:

   $ 3 + 4j \equiv 5 \pmod{6} $

3. **Simplify the equation:**

   Subtract 3 from both sides:

   $ 4j \equiv 2 \pmod{6} $

4. **Divide by the greatest common divisor (gcd):**

   The gcd of 4, 2, and 6 is 2. Divide the equation by 2:

   $ 2j \equiv 1 \pmod{3} $

5. **Find the modular inverse:**

   The modular inverse of 2 mod 3 is 2. Multiply both sides by this inverse:

   $ j \equiv 2 \times 1 \pmod{3} $

   $ j \equiv 2 \pmod{3} $

6. **Express $ j $ in terms of an integer $ k $:**

   Since $ j \equiv 2 \pmod{3} $, we can write $ j = 2 + 3k $ for some integer $ k $.

7. **Substitute back to find $ x $:**

   Substitute $ j = 2 + 3k $ into $ x = 3 + 4j $:
   $ x = 3 + 4(2 + 3k) $

   $ x = 11 + 12k $

   Therefore, the solution is:
   $ x \equiv 11 \pmod{12} $

### Example Two (An Easier Method)

Consider the system of congruences:

$ x \equiv 1 \pmod{2} $

$ x \equiv 2 \pmod{3} $

$ x \equiv 3 \pmod{5} $

$ x \equiv 4 \pmod{11} $

Follow these steps to solve the system:

1. **Rewrite the first congruence:**

   $ x = 2a + 1 $

2. **Substitute into the second congruence:**

   $ 2a + 1 \equiv 2 \pmod{3} $

   $ 2a \equiv 1 \pmod{3} $

   $ a \equiv 2 \pmod{3} $

   So, $ a = 3b + 2 $.

3. **Substitute $ a $ back:**

   $ x = 2(3b + 2) + 1 $

   $ x = 6b + 5 $

4. **Substitute into the third congruence:**

   $ 6b + 5 \equiv 3 \pmod{5} $

   $ 6b \equiv -2 \pmod{5} $

   $ b \equiv 3 \pmod{5} $

   So, $ b = 5c + 3 $.

5. **Substitute $ b $ back:**

   $ x = 6(5c + 3) + 5 $

   $ x = 30c + 23 $

6. **Substitute into the fourth congruence:**

   $ 30c + 23 \equiv 4 \pmod{11} $

   $ 30c \equiv -19 \pmod{11} $

   $ c \equiv 10 \pmod{11} $

   So, $ c = 11d + 10 $.

7. **Substitute $ c $ back:**

   $ x = 30(11d + 10) + 23 $

   $ x = 330d + 323 $

Therefore, the solution is:
$ x \equiv 323 \pmod{330} $

## Checking the Solution

To verify, compute $ 323 $ modulo each original modulus:

$ 323 \equiv 1 \pmod{2} $

$ 323 \equiv 2 \pmod{3} $

$ 323 \equiv 3 \pmod{5} $

$ 323 \equiv 4 \pmod{11} $

## General Algorithm

1. Write the first equation in its equivalent form.
2. Substitute it into the next equation.
3. Simplify, using the modular multiplicative inverse if necessary.
4. Continue until the last equation.
5. Back substitute, then simplify.
6. Rewrite in the congruence form.

If the moduli (plural form of `modulus`) are coprime, the Chinese Remainder Theorem provides a direct formula to obtain the solution.

## Garner's Algorithm

### Introduction

Garner's Algorithm is a method for reconstructing a large integer from its remainders modulo a set of pairwise coprime integers. This is a consequence of the Chinese Remainder Theorem, which allows representing a large number using an array of smaller integers.

For example, let $ p $ be the product of the first 1000 primes. A number $ a $ less than $ p $ can be represented as an array $ a_1, a_2, \ldots, a_k $ where $ a_i \equiv a \pmod{p_i} $.

The challenge is to reconstruct $ a $ from $ a_1, a_2, \ldots, a_k $. Garner's Algorithm provides a systematic way to do this.

### Mixed Radix Representation

Garner's Algorithm uses the concept of mixed radix representation. A number $ a $ can be represented as:
$ a = x*1 + x_2 p_1 + x_3 p_1 p_2 + \ldots + x_k p_1 p_2 \cdots p*{k-1} $
where $ x_i \in [0, p_i) $.

In this representation:

- $ p_i $ are the prime bases.
- $ x_i $ are the digits in the mixed radix system.

### Computing the Digits with Garner's Algorithm

The goal is to compute the digits $ x_1, x_2, \ldots, x_k $ efficiently. Here’s how Garner’s Algorithm works step-by-step:

1. **Initialization**:

   - Define $ r*{ij} $ as the modular inverse of $ p_i $ modulo $ p_j $:
     $ r*{ij} = (p_i)^{-1} \pmod{p_j} $
     This can be computed using the Extended Euclidean Algorithm.

2. **Calculation**:

   - Start with $ x_1 $:
     $ x_1 \equiv a_1 \pmod{p_1} $
   - For each subsequent $ x*i $, use the previous digits and modular inverses to compute:
     $ x_2 \equiv (a_2 - x_1) \cdot r*{12} \pmod{p*2} $
     $ x_3 \equiv ((a_3 - x_1) \cdot r*{13} - x*2) \cdot r*{23} \pmod{p_3} $
     - Continue this pattern for all $ x_i $.

3. **Pattern and Pseudocode**:

   - The general pattern is:
     $ x*i \equiv (a_i - \text{linear combination of previous } x_j) \cdot r*{j[i]} \pmod{p_i} $
   - This can be implemented in pseudocode as follows:

```java
for (int i = 0; i < k; ++i) {
    x[i] = a[i];
    for (int j = 0; j < i; ++j) {
        x[i] = (r[j][i] * (x[i] - x[j])) % p[i];
        if (x[i] < 0) {
            x[i] += p[i];
        }
    }
}
```

4. **Reconstructing the Number**:
   - Once the digits $ x*i $ are calculated, the number $ a $ can be reconstructed using:
     $ a = x_1 + x_2 \cdot p_1 + x_3 \cdot p_1 \cdot p_2 + \ldots + x_k \cdot p_1 p_2 \cdots p*{k-1} $

### Example

Suppose we have three primes $ p_1 = 3 $, $ p_2 = 5 $, and $ p_3 = 7 $, and a number $ a $ such that:
$ a \equiv 2 \pmod{3} $
$ a \equiv 3 \pmod{5} $
$ a \equiv 2 \pmod{7} $

We want to find $ a $.

1. **Initialization**:

   - $ r\_{12} = 3^{-1} \pmod{5} = 2 $ (since $ 3 \cdot 2 \equiv 1 \pmod{5} $)
   - $ r\_{13} = 3^{-1} \pmod{7} = 5 $
   - $ r\_{23} = 5^{-1} \pmod{7} = 3 $

2. **Calculation**:

   - $ x_1 = 2 $
   - $ x*2 = (3 - x_1) \cdot r*{12} \pmod{5} = (3 - 2) \cdot 2 \pmod{5} = 2 $
   - $
     \begin{aligned}
     x_3 &= ((2 - x_1) \cdot r_{13} - x_2) \cdot r_{23} \pmod{7} \\
     &= ((2 - 2) \cdot 5 - 2) \cdot 3 \pmod{7} \\
     &= (-2 \cdot 3) \pmod{7} = -6 \pmod{7} \\
     &= 1
     \end{aligned}
     $

3. **Reconstructing the Number**:

   - $ a = x_1 + x_2 \cdot p_1 + x_3 \cdot p_1 \cdot p_2 $
   - $ a = 2 + 2 \cdot 3 + 1 \cdot 3 \cdot 5 = 2 + 6 + 15 = 23 $

Thus, $ a = 23 $ is the number that satisfies all the given congruences.

## Implementation in Pseudocode

### Initialization

1. **Initialize Primes and Modular Inverses:**

```pseudocode
CONST SZ = 100
ARRAY pr[SIZE]  // array to store primes
ARRAY r[SIZE][SIZE]  // 2D array to store modular inverses

FUNCTION init():
    x = 1000000000
    i = 0
    WHILE i < SZ:
        IF isPrime(x):
            pr[i] = x
            i = i + 1
        x = x + 1

    FOR i FROM 0 TO SZ - 1:
        FOR j FROM i + 1 TO SZ - 1:
            r[i][j] = modInverse(pr[i], pr[j])

FUNCTION isPrime(x):
    RETURN true if x is a prime number, false otherwise

FUNCTION modInverse(a, m):
    RETURN inverse of a modulo m
```

### Number Class

2. **Define the Number Class:**

```pseudocode
CLASS Number:
    ARRAY a[SIZE]

    CONSTRUCTOR Number():
        // Initialize the array a with zeros
        FOR i FROM 0 TO SIZE - 1:
            a[i] = 0

    CONSTRUCTOR Number(n):
        // Initialize the array a with the remainders of n
        FOR i FROM 0 TO SIZE - 1:
            a[i] = n MOD pr[i]

    CONSTRUCTOR Number(bigN):
        // Initialize the array a with the remainders of bigN
        FOR i FROM 0 TO SIZE - 1:
            a[i] = bigN MOD pr[i]

    FUNCTION add(Number n):
        Number result = new Number()
        FOR i FROM 0 TO SIZE - 1:
            result.a[i] = (a[i] + n.a[i]) MOD pr[i]
        RETURN result

    FUNCTION subtract(Number n):
        Number result = new Number()
        FOR i FROM 0 TO SIZE - 1:
            result.a[i] = (a[i] - n.a[i] + pr[i]) MOD pr[i]
        RETURN result

    FUNCTION multiply(Number n):
        Number result = new Number()
        FOR i FROM 0 TO SIZE - 1:
            result.a[i] = (a[i] * n.a[i]) MOD pr[i]
        RETURN result

    FUNCTION bigIntegerValue(can_be_negative):
        BigInteger result = 0
        BigInteger mult = 1
        ARRAY x[SIZE]
        FOR i FROM 0 TO SIZE - 1:
            x[i] = a[i]
            FOR j FROM 0 TO i - 1:
                cur = (x[i] - x[j]) * r[j][i]
                x[i] = (cur MOD pr[i] + pr[i]) MOD pr[i]
            result = result + (mult * x[i])
            mult = mult * pr[i]

        IF can_be_negative AND result >= (mult / 2):
            result = result - mult

        RETURN result
```

### Explanation of Pseudocode

- **Initialization (init):**

  - Initialize the `pr` array with 100 primes starting from 1,000,000,000.
  - Initialize the `r` array with modular inverses using a helper function `modInverse`.

- **Number Class:**

  - `Number()` constructor initializes the array `a` with zeros.
  - `Number(n)` constructor initializes the array `a` with remainders of `n` modulo each prime in `pr`.
  - `Number(bigN)` constructor initializes the array `a` with remainders of `bigN` modulo each prime in `pr`.
  - `add(Number n)` adds two `Number` objects and returns the result.
  - `subtract(Number n)` subtracts one `Number` object from another and returns the result.
  - `multiply(Number n)` multiplies two `Number` objects and returns the result.
  - `bigIntegerValue(can_be_negative)` converts the mixed radix representation back to a single integer.
