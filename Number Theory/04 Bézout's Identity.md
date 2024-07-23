# Bézout's Identity (Bézout's Lemma)

**Bézout's Identity** (also known as Bézout's Lemma) states that for any two integers $a$$and $b$, if $d$$is their greatest common divisor (GCD), then there exist integers $x$$and $y$$such that:
$$ax + by = d $

In other words, the GCD of $a$$and $b$$can be expressed as a linear combination of $a$$and $b$.

## Solutions of Bézout's Identity

The **Extended Euclidean Algorithm** is an enhancement of the basic Euclidean algorithm. While the Euclidean algorithm efficiently finds the greatest common divisor (GCD) of two integers $a$$and $b$, the Extended Euclidean Algorithm not only computes the GCD but also finds integers $x$$and $y$$such that:

$$ax + by = \text{GCD}(a, b) $

## Steps of the Extended Euclidean Algorithm

1. **Initialization:** Start with two integers $a$$and $b$, where $a \geq b \geq 0$.

2. **Base Case:** If $b = 0$, then$$\text{GCD}(a, 0) = a$$and we can set $x = 1, y = 0$.

3. **Recursive Step:** If $b \neq 0$:

- Apply the Euclidean algorithm to $b$$and $a \mod b$$to find $d = \text{GCD}(b, a \mod b)$$and integers $x'$$and $y'$$such that$$bx' + (a \mod b)y' = d $.

4. **Update $x$$and $y$:**

- From the base of the recursive step, update $x$$and $y$$using the relations derived from the recursive step:
 $$x = y', \quad y = x' - \left\lfloor \frac{a}{b} \right\rfloor \cdot y' $

5. **Repeat:** Repeat the process until $b = 0$. The integers $x$$and $y$$obtained at this point satisfy$$ax + by = \text{GCD}(a, b) $.

## Example

Let's find the GCD of $a = 56$$and $b = 15$$using the Extended Euclidean Algorithm to find $x$$and $y$.

1. **Run the Euclidean Algorithm** to find the gcd:

   $
   \begin{aligned}
   &56 = 15 \cdot 3 + 11 \\
   &15 = 11 \cdot 1 + 4 \\
   &11 = 4 \cdot 2 + 3 \\
   &4 = 3 \cdot 1 + 1 \\
   &3 = 1 \cdot 3 + 0
   \end{aligned}
   $

   So, $\text{gcd}(56, 15) = 1$.

2. **Back Substitution:**

   - Start with the equation just before the remainder became zero:

     $
     1 = 4 - 3 \cdot 1
     $

   - Substitute $3$$from the previous equation:

     $
     3 = 11 - 4 \cdot 2
     $

   - Substituting back, we get:

     $
     1 = 4 - (11 - 4 \cdot 2) \cdot 1
     $

     Simplifying this:

     $
     1 = 4 - 11 + 4 \cdot 2
     $

     $
     1 = 4 \cdot 3 - 11
     $

   - Substitute $4$$from the previous equation:

     $
     4 = 15 - 11 \cdot 1
     $

   - Substituting back, we get:

     $
     1 = (15 - 11) \cdot 3 - 11
     $

     Simplifying this:

     $
     1 = 15 \cdot 3 - 11 \cdot 4
     $

   - Substitute $11$$from the previous equation:

     $
     11 = 56 - 15 \cdot 3
     $

   - Substituting back, we get:

     $
     1 = 15 \cdot 3 - (56 - 15 \cdot 3) \cdot 4
     $

     Simplifying this:

     $
     1 = 15 \cdot 3 - 56 \cdot 4 + 15 \cdot 12
     $

     Combining like terms:

     $
     1 = 15 \cdot 15 - 56 \cdot 4
     $

   So, we have found $x = 15$$and $y = -4$$such that $56(-4) + 15(15) = 1$.

   In summary:

   $
   56 \cdot (-4) + 15 \cdot 15 = 1
   $

   Thus, the coefficients are $x = 15$$and $y = -4$.

## Pseudocode

- **Recursive**

  ```
    function extendedEuclidean(a, b)
        if b == 0
            return (a, 1, 0)
        else
            (gcd, x1, y1) = extendedEuclidean(b, a % b)
            x = y1
            y = x1 - (a // b) * y1
            return (gcd, x, y)
  ```

- **Iterative**

  ```
  function extendedEuclidean(a, b)
      x0 = 1, x1 = 0
      y0 = 0, y1 = 1
      while b != 0
          q = a // b
          (a, b) = (b, a % b)
          (x0, x1) = (x1, x0 - q * x1)
          (y0, y1) = (y1, y0 - q * y1)
      return (a, x0, y0)
  ```

## Matrix Method for Finding Integers x and y in Bézout's Identity

The integers$$x$$and$$y$$can also be determined using an equivalent matrix method. The sequence of equations from Euclid's algorithm:

$
a = q_0 b + r_0 \\
b = q_1 r_0 + r_1 \\
\vdots \\
r_{N-2} = q_N r_{N-1} + 0
$

can be expressed as a product of$$2 \times 2$$quotient matrices multiplying a two-dimensional remainder vector:

$
\begin{pmatrix} a \\ b \end{pmatrix} =
\begin{pmatrix} q_0 & 1 \\ 1 & 0 \end{pmatrix}
\begin{pmatrix} b \\ r_0 \end{pmatrix} =
\begin{pmatrix} q_0 & 1 \\ 1 & 0 \end{pmatrix}
\begin{pmatrix} q_1 & 1 \\ 1 & 0 \end{pmatrix}
\begin{pmatrix} r_0 \\ r_1 \end{pmatrix} =
\cdots =
\prod_{i=0}^{N} \begin{pmatrix} q_i & 1 \\ 1 & 0 \end{pmatrix}
\begin{pmatrix} r_{N-1} \\ 0 \end{pmatrix}.
$

Let$$\mathbf{M}$$represent the product of all the quotient matrices:

$
\mathbf{M} = \begin{pmatrix} m_{11} & m_{12} \\ m_{21} & m_{22} \end{pmatrix} =
\prod_{i=0}^{N} \begin{pmatrix} q_i & 1 \\ 1 & 0 \end{pmatrix} =
\begin{pmatrix} q_0 & 1 \\ 1 & 0 \end{pmatrix}
\begin{pmatrix} q_1 & 1 \\ 1 & 0 \end{pmatrix} \cdots
\begin{pmatrix} q_N & 1 \\ 1 & 0 \end{pmatrix}.
$

This simplifies Euclid's algorithm to the form:

$
\begin{pmatrix} a \\ b \end{pmatrix} =
\mathbf{M} \begin{pmatrix} r_{N-1} \\ 0 \end{pmatrix} =
\mathbf{M} \begin{pmatrix} g \\ 0 \end{pmatrix}.
$

To express$$g$$as a linear sum of$$a$$and$$b $, both sides of this equation can be multiplied by the inverse of the matrix$$\mathbf{M} $. The determinant of$$\mathbf{M}$$equals$$(-1)^{N+1} $, as it is the product of the determinants of the quotient matrices, each of which is negative one. Since the determinant of$$\mathbf{M}$$is never zero, the vector of the final remainders can be solved using the inverse of$$\mathbf{M} $:

$
\begin{pmatrix} g \\ 0 \end{pmatrix} =
\mathbf{M}^{-1} \begin{pmatrix} a \\ b \end{pmatrix} =
(-1)^{N+1} \begin{pmatrix} m_{22} & -m_{12} \\ -m_{21} & m_{11} \end{pmatrix}
\begin{pmatrix} a \\ b \end{pmatrix}.
$

The top equation gives:

$
g = (-1)^{N+1} (m_{22} a - m_{12} b),
$

thus the two integers of Bézout's identity are$$x = (-1)^{N+1} m*{22}$$and$$y = (-1)^{N+1} m*{12} $. The matrix method is as efficient as the equivalent recursion, with two multiplications and two additions per step of the Euclidean algorithm.
