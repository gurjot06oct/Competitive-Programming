# Factorial Modulo$$p $

## Problem Overview

When working with binomial coefficients or other combinatorial formulas, you might need to compute factorials modulo a prime number$$p $. This involves ignoring the multiple factors of$$p$$that appear in the factorial. Here's how to handle it.

## Objective

Calculate$$n! \bmod p$$while ignoring the factors of$$p $. Denote this modified factorial as$$n!\_{\%p} $.

For example, for$$n = 7$$and$$p = 3 $:
$$7!_{\%3} \equiv 1 \cdot 2 \cdot \underbrace{1}_{3} \cdot 4 \cdot 5 \cdot \underbrace{2}\_{6} \cdot 7 \equiv 2 \bmod 3 $

## Factorial Decomposition

#### Objective

The goal of Factorial Decomposition in the context of computing$$n! \mod p$$is to break down$$n!$$into manageable parts that allow us to ignore multiples of$$p$$and compute the result efficiently modulo$$p $.

#### Steps Involved

1. **Understanding Factorials and Modulo$$p $**

   Factorials$$n!$$grow very quickly, especially when$$n$$is large. When calculating$$n! \mod p $, where$$p$$is a prime number, we are interested in removing all factors of$$p$$from$$n! $.

2. **Breaking Down$$n! $**

   - **Full Blocks**: Divide$$n!$$into blocks where each block consists of$$p$$consecutive numbers. For example, if$$p = 3 $, the blocks would be$$1 \cdot 2 \cdot 3 $,$$4 \cdot 5 \cdot 6 $, and so on.

   - **Last Partial Block**: The last block may not be complete if$$n$$is not perfectly divisible by$$p $. This block contains the remaining numbers up to$$n$$that don't form a complete$$p $-sized block.

3. **Mathematical Representation**

   Let's express this decomposition mathematically:

   $
   n! = (1 \cdot 2 \cdot \ldots \cdot (p-1)) \cdot (p \cdot (p+1) \cdot \ldots \cdot (2p-1)) \cdot \ldots \cdot ((kp) \cdot ((kp)+1) \cdot \ldots \cdot n)
   $

   - Each segment$$(ip) \cdot ((ip)+1) \cdot \ldots \cdot ((i+1)p-1)$$represents a full block for$$i = 0, 1, 2, \ldots, \lfloor n/p \rfloor $.

   - The last segment$$((\lfloor n/p \rfloor p) \cdot ((\lfloor n/p \rfloor p)+1) \cdot \ldots \cdot n$$represents the partial block.

4. **Modulo Operation**

   To compute$$n! \mod p $, we only need to consider the products of these blocks modulo$$p $, because multiples of$$p$$in each block will result in$$0 \mod p $.

5. **Implementation Insight**

   - Precompute factorials$$0!, 1!, \ldots, (p-1)!$$modulo$$p$$to efficiently handle the factorial values for smaller numbers.

   - Use binary exponentiation to manage the large numbers effectively, especially when dealing with powers and large factorials.

#### Example

Let's illustrate with an example where$$n = 7$$and$$p = 3 $:

- **Factorial Breakdown**:

 $$7! = 1 \cdot 2 \cdot 3 \cdot 4 \cdot 5 \cdot 6 \cdot 7 $

  - Full blocks of size 3:$$1 \cdot 2 \cdot 3 $,$$4 \cdot 5 \cdot 6 $,$$7 $.

  - Compute each block modulo 3:

    -$$1 \cdot 2 \cdot 3 \equiv 2 \mod 3 $
    -$$4 \cdot 5 \cdot 6 \equiv (1 \cdot 2 \cdot 0) \equiv 0 \mod 3 $
    -$$7 \equiv 1 \mod 3 $

  - Combine results:
    $
    7! \mod 3 = (2 \cdot 0 \cdot 1) \mod 3 = 0
    $

- **Last Partial Block**:

  The last numbers$$7$$do not form a complete block of size 3, so we handle them separately.

## Complexity

- The recursion depth is$$O(\log_p n) $.
- The overall complexity is$$O(p \log_p n) $.

## Implementation

Using precomputed factorials$$0!, 1!, \dots, (p-1)!$$modulo$$p $:

```pseudocode
function factmod(n, p):
    // Step 1: Precompute factorials modulo p
    f = array of size p
    f[0] = 1
    for i from 1 to p-1:
        f[i] = f[i-1] * i % p

    // Step 2: Calculate n!_{\%p}
    result = 1
    while n > 1:
        if (n // p) % 2 == 1:
            result = p - result
        result = result * f[n % p] % p
        n = n // p
    return result

```

### Steps

#### Step 1: Precompute Factorials Modulo$$p $

First, we need to compute the factorials of numbers from 0 to$$p-1$$modulo$$p $. This is because these values will be reused multiple times during the calculation.

```pseudocode
f = array of size p
f[0] = 1
for i from 1 to p-1:
    f[i] = f[i-1] * i % p
```

- `f[0] = 1`: By definition,$$0! = 1 $.
- For each `i` from 1 to$$p-1 $, compute$$i! \mod p$$and store it in `f[i]`.

#### Step 2: Calculate$$n!\_{\%p} $

Next, we use the precomputed factorials to compute$$n!\_{\%p} $.

```pseudocode
result = 1
while n > 1:
    if (n // p) % 2 == 1:
        result = p - result
    result = result * f[n % p] % p
    n = n // p
```

- **Initialization**: Start with `result = 1`.
- **Loop**: While `n > 1`, repeat the following steps:
  1. **Handle Blocks**:
     - Determine how many complete blocks of size$$p$$are there in `n` using `n // p`.
     - If the number of blocks (`n // p`) is odd, flip the sign of the result by setting `result = p - result`. This is because each block of size$$p$$contributes $(-1) \mod p$, and the sign flips based on the number of blocks.
  2. **Compute Partial Block**:
     - Compute the factorial of `n % p` using the precomputed array `f`. This handles the remainder part of `n`.
     - Update the result as `result = result * f[n % p] % p`.
  3. **Reduce `n`**:
     - Reduce `n` by dividing it by `p`. This effectively removes one block and prepares for the next iteration.

### Example

Using$$n = 11$$and$$p = 3 $:

- Compute$$f $:

  -$$f[0] = 1 $
  -$$f[1] = 1 $
  -$$f[2] = 2 $

- Initialize$$result = 1 $.

- Process each block:

  -$$n = 11 $:
    -$$11 \div 3 = 3 $,$$3 \% 2 = 1$$(odd), flip result to$$3 - 1 = 2 $.
    -$$result = (2 \cdot f[11 \% 3]) \% 3 = (2 \cdot 2) \% 3 = 1 $.
    -$$n = 11 \div 3 = 3 $.
  -$$n = 3 $:
    -$$3 \div 3 = 1 $,$$1 \% 2 = 1$$(odd), flip result to$$3 - 1 = 2 $.
    -$$result = (2 \cdot f[3 \% 3]) \% 3 = (2 \cdot 1) \% 3 = 2 $.
    -$$n = 3 \div 3 = 1 $.

- Final result:$$11! \mod 3 = 2 $.

### Alternative Approach

If memory is limited and storing all factorials is not feasible, compute necessary factorials on the fly.

### Multiplicity of$$p$$in$$n! $

The multiplicity of$$p$$in$$n!$$is the number of times$$p$$appears as a factor in the prime factorization of$$n! $. This is important for computing binomial coefficients modulo$$p $.

#### Legendre's Formula

Legendre's formula gives the multiplicity of a prime$$p$$in$$n! $:

$$\nu*p(n!) = \sum*{i=1}^{\infty} \left\lfloor \frac{n}{p^i} \right\rfloor $

This formula counts the number of multiples of$$p $,$$p^2 $,$$p^3 $, and so on, up to$$n $.

### Step-by-Step Calculation

Let's compute the multiplicity of$$p = 3$$in$$11!$$as an example.

1. **Calculate$$\left\lfloor \frac{n}{p^i} \right\rfloor $**

   We compute the sum for$$i$$until$$\left\lfloor \frac{n}{p^i} \right\rfloor$$becomes zero.

   $
   \begin{aligned}
   \left\lfloor \frac{11}{3^1} \right\rfloor &= \left\lfloor \frac{11}{3} \right\rfloor = \left\lfloor 3.67 \right\rfloor = 3 \\
   \left\lfloor \frac{11}{3^2} \right\rfloor &= \left\lfloor \frac{11}{9} \right\rfloor = \left\lfloor 1.22 \right\rfloor = 1 \\
   \left\lfloor \frac{11}{3^3} \right\rfloor &= \left\lfloor \frac{11}{27} \right\rfloor = \left\lfloor 0.41 \right\rfloor = 0 \\
   \end{aligned}
   $

2. **Sum the Values**

   Add the values obtained in each step:

   $
   \nu_3(11!) = 3 + 1 + 0 = 4
   $

### Pseudocode for Multiplicity Calculation

Here's the pseudocode to compute the multiplicity of$$p$$in$$n! $:

```pseudocode
function multiplicity_factorial(n, p):
    count = 0
    power = p
    while n >= power:
        count += n // power
        power *= p
    return count
```

### Example: Multiplicity of 3 in 11!

1. Initialize$$count = 0$$and$$power = p = 3 $.

2. Loop while$$n \geq power $:

   -$$n = 11, power = 3 $:
     -$$count += 11 // 3 = 3 $
     -$$power \*= 3 = 9 $
   -$$n = 11, power = 9 $:
     -$$count += 11 // 9 = 1 $
     -$$power \*= 3 = 27 $
   -$$n = 11, power = 27$$(loop exits as$$11 < 27 $).

3. Return$$count = 3 + 1 = 4 $.
