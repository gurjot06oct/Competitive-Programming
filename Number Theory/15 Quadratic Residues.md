# Quadratic Congruences and Their Residues

Quadratic congruences are equations of the form $ ax^2 + bx + c \equiv 0 \pmod{n} $, where $a$, $b$, $c$, and $n $ are integers and $n \geq 2$. Solving such congruences involves finding integer solutions $x $ that satisfy the given equation modulo $n$.

## Key Concepts

1. **Quadratic Residue**:

   - An integer $a $ is called a quadratic residue modulo $n $ if there exists an integer $x $ such that $x^2 \equiv a \pmod{n}$.
   - If no such $x $ exists, then $a $ is a quadratic non-residue modulo $n$.

2. **Euler's Criterion**:

   - Euler's Criterion is used to determine whether an integer $ a $ is a quadratic residue modulo a prime $ p $.
   - When considering $ x^2 \equiv a \pmod{2} $, the sole solution is $ x \equiv a \pmod{2} $.

   **Euler's Criterion Statement:**
   For an integer $ a $ and an odd prime $ p $:

   $
   a^{\frac{p-1}{2}} \equiv \begin{cases}
   1 \pmod{p} & \text{if } a \text{ is a quadratic residue modulo } p \\
   -1 \pmod{p} & \text{if } a \text{ is not a quadratic residue modulo } p
   \end{cases}
   $

   **Example:**
   Determine whether 3 is a quadratic residue modulo 7.

   1. Compute $ 3^{\frac{7-1}{2}} = 3^3 \pmod{7} $.
   2. Calculate $ 3^3 = 27 \equiv 6 \pmod{7} $, and 6 is equivalent to -1 modulo 7.
   3. Therefore, 3 is not a quadratic residue modulo 7.

3. **Legendre Symbol**:

   - For an odd prime $p$, the Legendre symbol $\left( \frac{a}{p} \right) $ is defined as:

     $
     \left( \frac{a}{p} \right) =
     \begin{cases}
     1 & \text{if } a \text{ is a quadratic residue modulo } p \text{ and } a \not\equiv 0 \pmod{p} \\
     -1 & \text{if } a \text{ is a quadratic non-residue modulo } p \\
     0 & \text{if } a \equiv 0 \pmod{p}
     \end{cases}
     $

   - It helps in determining whether a number is a quadratic residue modulo $p$.

4. **Quadratic Reciprocity**:
   - This theorem provides a criterion for determining the solvability of quadratic congruences. It states:
     $
     \left( \frac{p}{q} \right) \left( \frac{q}{p} \right) = (-1)^{\frac{(p-1)(q-1)}{4}}
     $
     for distinct odd primes $p $ and $q$.

## Solving Quadratic Congruences

The problem is to find the square root of a number $ n $ under modulo $ p $, where $ p $ is a prime number. This means finding $ x $ such that:

 $ x^2 \equiv n \pmod{p} $

The Shanks-Tonelli algorithm provides a way to solve this problem for any prime $ p $.

### Algorithm Steps

1. **Check if a square root exists:**
   Calculate $ n^{\frac{p-1}{2}} \mod p $. If the result is $ p-1 $, then the square root does not exist. This is based on Euler's criterion, which states that $ n $ has a square root modulo $ p $ if and only if $ n^{\frac{p-1}{2}} \equiv 1 \pmod{p} $.

2. **Express $ p-1 $ as $ s \times 2^e $:**
   Write $ p-1 $ in the form $ s \times 2^e $ where $ s $ is an odd number. This can be done by repeatedly dividing $ p-1 $ by 2 until an odd number is obtained.

3. **Find a quadratic non-residue $ q $:**
   Find a number $ q $ such that $ q^{\frac{p-1}{2}} \equiv -1 \pmod{p} $. This $ q $ is known as a quadratic non-residue modulo $ p $.

4. **Initialize variables:**
   Set:

   $
   \begin{aligned}
   x & = n^{\frac{s+1}{2}} \mod p \\
   b & = n^s \mod p \\
   g & = q^s \mod p \\
   r & = e
   \end{aligned}
   $

5. **Iteratively update variables:**
   Loop until $ b \equiv 1 \pmod{p} $:

   - Find the smallest integer $ m $ such that $ b^{2^m} \equiv 1 \pmod{p} $.
   - Update:

     $
     \begin{aligned}
     x & = x \cdot g^{2^{r-m-1}} \mod p \\
     b & = b \cdot g^{2^{r-m}} \mod p \\
     g & = g^{2^{r-m}} \mod p \\
     r & = m
     \end{aligned}
     $

6. **Return the result:**
   The value of $ x $ is the square root of $ n $ modulo $ p $.

### Pseudocode

```pseudocode
function modularSquareRoot(n, p):
    // Step 1: Check if a square root exists
    if (pow(n, (p - 1) / 2, p) == p - 1):
        return "Square root doesn't exist"

    // Step 2: Express p-1 as (s * 2^e)
    e = 0
    s = p - 1
    while (s % 2 == 0):
        s = s / 2
        e = e + 1

    // Step 3: Find a quadratic non-residue q
    q = 2
    while (pow(q, (p - 1) / 2, p) == 1):
        q = q + 1

    // Step 4: Initialize variables
    x = pow(n, (s + 1) / 2, p)
    b = pow(n, s, p)
    g = pow(q, s, p)
    r = e

    // Step 5: Loop until b == 1
    while (b != 1):
        m = 0
        t = b
        while (t != 1):
            t = pow(t, 2, p)
            m = m + 1

        x = (x * pow(g, 2^(r - m - 1), p)) % p
        b = (b * pow(g, 2^(r - m), p)) % p
        g = pow(g, 2^(r - m), p)
        r = m

    // Step 6: Return the result
    return x
```

This pseudocode outlines the steps to find the square root of $ n $ under modulo $ p $ using the Shanks-Tonelli algorithm.
