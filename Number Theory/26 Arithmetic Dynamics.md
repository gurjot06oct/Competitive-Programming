# Arithmetic Dynamics

## Digit Sum

In mathematics, the digit sum of a natural number in a given base is the sum of all its digits. For example, the digit sum of the decimal number 9045 is $9 + 0 + 4 + 5 = 18$.

### Definition

Let $n$ be a natural number. The digit sum for base $b > 1$, denoted $F_b: \mathbb{N} \rightarrow \mathbb{N}$, is defined as follows:

$
F_b(n) = \sum_{i=0}^{k} d_i
$

where $k = \lfloor \log_b n \rfloor$ is one less than the number of digits in the number in base $b$, and

$
d_i = \frac{n \bmod b^{i+1} - n \bmod b^i}{b^i}
$

is the value of each digit of the number.

For example, in base 10, the digit sum of 84001 is:

$
F_{10}(84001) = 8 + 4 + 0 + 0 + 1 = 13
$

For any two bases $2 \leq b_1 < b_2$ and for sufficiently large natural numbers $n$,

$
\sum_{k=0}^{n} F_{b_1}(k) < \sum_{k=0}^{n} F_{b_2}(k)
$

The sum of the base 10 digits of the integers 0, 1, 2, ... is given by OEIS: A007953 in the On-Line Encyclopedia of Integer Sequences. Borwein & Borwein (1992) use the generating function of this integer sequence (and of the analogous sequence for binary digit sums) to derive several rapidly converging series with rational and transcendental sums.

### Extension to Negative Integers

The digit sum can be extended to negative integers using a signed-digit representation to represent each integer.

### Properties

The number of $n$-digit numbers with digit sum $q$ can be calculated using:

$
f(n, q) = \begin{cases}
1 & \text{if } n = 1 \\
f(n, 9n - q + 1) & \text{if } q > \left\lceil \frac{9n}{2} \right\rceil \\
\sum_{i = \max(q - 9, 1)}^{q} f(n-1, i) & \text{otherwise}
\end{cases}
$

## Digital Root

The digital root (also known as the repeated digital sum) of a natural number in a given base is the single-digit value obtained through an iterative process of summing the digits. Each iteration uses the result from the previous iteration to compute a new digit sum until a single-digit number is reached.

For example, in base 10, the digital root of the number 12345 is 6 because the sum of the digits (1 + 2 + 3 + 4 + 5) equals 15, and then summing the digits of 15 (1 + 5) gives 6.

In base 10, the digital root can be computed by taking the remainder upon division by 9 (except when the digital root is 9, where the remainder upon division by 9 will be 0). This property allows it to be used as a divisibility rule.

A natural number $n$ is a digital root if it is a fixed point for $F_b$, which occurs if $F_b(n) = n$.

All natural numbers $n$ are preperiodic points for $F_b$, regardless of the base. This is because if $n \geq b$, then

$
n = \sum_{i=0}^{k-1} d_i b^i
$

and therefore

$
F_b(n) = \sum_{i=0}^{k-1} d_i < \sum_{i=0}^{k-1} d_i b^i = n
$

because $b > 1$. If $n < b$, then trivially $F_b(n) = n$.

Therefore, the only possible digital roots are the natural numbers $0 \leq n < b$, and there are no cycles other than the fixed points of $0 \leq n < b$.

### Example

In base 12, 8 is the additive digital root of the base 10 number 3110. The digits in base 12 are calculated as follows:

$
d_0 = \frac{3110 \bmod 12 - 3110 \bmod 1}{1} = \frac{2 - 0}{1} = 2
$

$
d_1 = \frac{3110 \bmod 144 - 3110 \bmod 12}{12} = \frac{86 - 2}{12} = 7
$

$
d_2 = \frac{3110 \bmod 1728 - 3110 \bmod 144}{144} = \frac{1382 - 86}{144} = 9
$

$
d_3 = \frac{3110 \bmod 20736 - 3110 \bmod 1728}{1728} = \frac{3110 - 1382}{1728} = 1
$

So,

$
F_{12}(3110) = \sum_{i=0}^{3} d_i = 2 + 7 + 9 + 1 = 19
$

This process shows that 3110 is 1972 in base 12. For $F_{12}(19)$:

$
d_0 = \frac{19 \bmod 12 - 19 \bmod 1}{1} = 7
$

$
d_1 = \frac{19 \bmod 144 - 19 \bmod 12}{12} = 1
$

Thus,

$
F_{12}(19) = 1 + 7 = 8
$

Since 8 is a 1-digit number in base 12, $F_{12}(8) = 8$.

### Direct Formulas

We can define the digit root directly for base $b > 1$ as follows:

#### Congruence Formula

For a given number $n$ in base $b$:

$
\text{dr}_b(n) = \begin{cases}
0 & \text{if } n = 0, \\
b - 1 & \text{if } n \neq 0 \text{ and } n \equiv 0 \pmod{(b - 1)}, \\
n \mod (b - 1) & \text{if } n \not\equiv 0 \pmod{(b - 1)}
\end{cases}
$

Alternatively,

$
\text{dr}_b(n) = \begin{cases}
0 & \text{if } n = 0, \\
1 + ((n - 1) \mod (b - 1)) & \text{if } n \neq 0
\end{cases}
$

#### Explanation

The digital root is the value modulo $b - 1$ because $b \equiv 1 \pmod{(b - 1)}$, which means $b^i \equiv 1^i \equiv 1 \pmod{(b - 1)}$. Thus, for any digit $d_i$ in position $i$, $d_i b^i \equiv d_i \pmod{(b - 1)}$.

For a three-digit number $n = d_2 b^2 + d_1 b^1 + d_0 b^0$:

$
\text{dr}_b(n) \equiv d_2 b^2 + d_1 b^1 + d_0 b^0 \equiv d_2 (1) + d_1 (1) + d_0 (1) \equiv d_2 + d_1 + d_0 \pmod{(b - 1)}
$

### Using the Floor Function

The digital root of a positive integer $n$ can also be defined using the floor function:

$
\text{dr}_b(n) = n - (b - 1) \left\lfloor \frac{n - 1}{b - 1} \right\rfloor
$

### Properties

- **Sum**: The digital root of $a_1 + a_2$ in base $b$ is the digital root of the sum of the digital roots of $a_1$ and $a_2$:

  $
  \text{dr}_b(a_1 + a_2) = \text{dr}_b(\text{dr}_b(a_1) + \text{dr}_b(a_2))
  $

- **Difference**: The digital root of $a_1 - a_2$ in base $b$ is congruent to the difference of the digital roots of $a_1$ and $a_2$ modulo $b - 1$:

  $
  \text{dr}_b(a_1 - a_2) \equiv (\text{dr}_b(a_1) - \text{dr}_b(a_2)) \pmod{(b - 1)}
  $

- **Negation**: The digital root of $-n$ in base $b$:

  $
  \text{dr}_b(-n) \equiv -\text{dr}_b(n) \pmod{(b - 1)}
  $

- **Product**: The digital root of $a_1 \cdot a_2$ in base $b$ is the digital root of the product of the digital roots of $a_1$ and $a_2$:

  $
  \text{dr}_b(a_1 \cdot a_2) = \text{dr}_b(\text{dr}_b(a_1) \cdot \text{dr}_b(a_2))
  $

### Additive Persistence

The additive persistence counts the number of times we must sum a number's digits to arrive at its digital root.

**Example**: The additive persistence of $2718$ in base $10$ is $2$:

1. $ 2 + 7 + 1 + 8 = 18 $
2. $ 1 + 8 = 9 $

There is no limit to the additive persistence of a number in a number base $b$.

### Pseudocode Example

```pseudocode
FUNCTION digit_sum(x, b):
    total = 0
    WHILE x > 0:
        total = total + (x MOD b)
        x = x DIV b
    RETURN total

FUNCTION digital_root(x, b):
    seen = EMPTY_SET
    WHILE x NOT IN seen:
        seen.ADD(x)
        x = digit_sum(x, b)
    RETURN x

FUNCTION additive_persistence(x, b):
    seen = EMPTY_SET
    WHILE x NOT IN seen:
        seen.ADD(x)
        x = digit_sum(x, b)
    RETURN SIZE(seen) - 1
```

## Multiplicative Digital Root

### Overview

In number theory, the multiplicative digital root of a natural number $ n $ in a given base $ b $ is found by multiplying the digits of $ n $ together, repeating this process until only a single digit remains. This final single digit is called the multiplicative digital root of $ n $.

### Example

The multiplicative digital roots for the first few positive integers are:
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 2, 4, 6, 8, 0, 2, 4, 6, 8, 0, 3, 6, 9, 2, 5, 8, 2, 8, 4, 0. (sequence A031347 in the OEIS).

### Definition

Let $ n $ be a natural number. The digit product function for base $ b > 1 $ is defined as follows:

$ F*b: \mathbb{N} \rightarrow \mathbb{N} $
$ F_b(n) = \prod*{i=0}^{k-1} d_i $

Here,
$ k = \lfloor \log_b n \rfloor + 1 $
is the number of digits in the number in base $ b $, and 
$ d_i = \frac{n \bmod b^{i+1} - n \bmod b^i}{b^i} $
is the value of each digit of the number.

A natural number $ n $ is a multiplicative digital root if it is a fixed point for $ F_b $, which occurs when $ F_b(n) = n $.

### Example in Base 10

For example, in base $ b = 10 $:

The multiplicative digital root of 9876 is calculated as:
$ F*{10}(9876) = (9) \times (8) \times (7) \times (6) = 3024 $
$ F*{10}(3024) = (3) \times (0) \times (2) \times (4) = 0 $
$ F\_{10}(0) = 0 $

### Properties

All natural numbers $ n $ are preperiodic points for $ F_b $, regardless of the base. This is because:

If $ n \geq b $, then
$ n = \sum*{i=0}^{k-1} d_i b^i $
and therefore,
$ F_b(n) = \prod*{i=0}^{k-1} d*i = d*{k-1} \prod*{i=0}^{k-2} d_i < d*{k-1} b^{k-1} < \sum\_{i=0}^{k-1} d_i b^i = n $

If $ n < b $, then trivially
$ F_b(n) = n $

Therefore, the only possible multiplicative digital roots are the natural numbers $ 0 \leq n < b $, and there are no cycles other than the fixed points of $ 0 \leq n < b $.

## Multiplicative Persistence

The multiplicative persistence of a number $ n $ is the number of iterations needed for $ F_b^i(n) $ to reach a fixed point. If it never reaches a fixed point, the multiplicative persistence is undefined.

### Conjecture in Base 10

In base 10, it is conjectured that no number has a multiplicative persistence $ i > 11 $. This has been verified for numbers $ n \leq 10^{20585} $.

The smallest numbers with persistence 0, 1, ..., are:
0, 10, 25, 39, 77, 679, 6788, 68889, 2677889, 26888999, 3778888999, 277777788888899 (sequence A003001 in the OEIS).

### Search Optimization

The search for these numbers can be optimized by considering the properties of their decimal digits. These digits must be sorted, and except for the first two digits, all digits must be 7, 8, or 9. There are additional restrictions on the first two digits. Given these constraints, the number of candidate $ k $-digit numbers with record-breaking persistence is proportional to the square of $ k $.

### Large Numbers

Any missing number from the sequence above would have multiplicative persistence > 11. Such numbers are believed not to exist and would need to have over 20,000 digits if they do exist.

### Extension to Negative Integers

The multiplicative digital root can be extended to negative integers using a signed-digit representation.

### Pseudocode for Multiplicative Persistence

Here is the pseudocode that implements the digit product, multiplicative digital root, and multiplicative persistence:

```pseudo
function digit_product(x, b)
    if x == 0
        return 0
    total = 1
    while x > 1
        if x % b == 0
            return 0
        if x % b > 1
            total = total * (x % b)
        x = x // b
    return total

function multiplicative_digital_root(x, b)
    seen = []
    while x not in seen
        seen.append(x)
        x = digit_product(x, b)
    return x

function multiplicative_persistence(x, b)
    seen = []
    while x not in seen
        seen.append(x)
        x = digit_product(x, b)
    return len(seen) - 1
```

### Explanation of Pseudocode

1. **digit_product(x, b)**:

   - Calculates the product of the digits of $ x $ in base $ b $.
   - If $ x $ is 0, it returns 0.
   - Otherwise, it multiplies the digits of $ x $ until $ x $ is reduced to 1 or 0.

2. **multiplicative_digital_root(x, b)**:

   - Finds the multiplicative digital root of $ x $ in base $ b $.
   - Keeps track of seen numbers to detect cycles and avoid infinite loops.

3. **multiplicative_persistence(x, b)**:
   - Determines the multiplicative persistence of $ x $ in base $ b $.
   - Uses a list to keep track of seen numbers and returns the number of iterations needed to reach a fixed point.
