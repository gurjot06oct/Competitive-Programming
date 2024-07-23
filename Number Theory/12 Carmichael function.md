# Carmichael's Theorems

The Carmichael function,$$\lambda(n)$$, also known as Carmichael's totient function, is an arithmetic function in number theory related to Euler's totient function,$$\phi(n)$$. Here’s a detailed explanation:

## Definition

For a positive integer$$n$$,$$\lambda(n)$$is defined as the smallest positive integer$$m$$such that:
$$a^m \equiv 1 \pmod{n} $
for all integers$$a$$that are coprime to$$n$$.

The formula for$$\lambda(n)$$in simplified form is:

$
\lambda(n) = \begin{cases}
\phi(n) & \text{if } n \text{ is } 1, 2, 4, \text{ or an odd prime power}, \\
\frac{1}{2} \phi(n) & \text{if } n = 2^r, \ r \geq 3
\end{cases}
$

$
\lambda(n) = \operatorname{lcm} \left( \lambda(p_1^{e_1}), \lambda(p_2^{e_2}), \ldots, \lambda(p_k^{e_k}) \right)
$

where$$n = p_1^{e_1} p_2^{e_2} \ldots p_k^{e_k}$$is the prime factorization of$$n $, and$$\lambda(p_i^{e_i})$$is the Carmichael function applied to the prime power$$p_i^{e_i} $. This simplification reflects that$$\lambda(n)$$is determined by the least common multiple of$$\lambda$$values computed for each prime power component of$$n $.For prime powers$$p^k$$, where$$p$$is a prime and$$k \geq 1$$:$$\phi(p^k) = p^k - p^{k-1} $

The values for$$\lambda(n)$$based on the simplified formula for different cases of$$n $:

1. **Case 1:$$n$$is 1, 2, 4, or an odd prime power**

   - For$$n = 1 $:$$\lambda(1) = \phi(1) = 1 $.
   - For$$n = 2 $:$$\lambda(2) = \phi(2) = 1 $.
   - For$$n = 4 $:$$\lambda(4) = \phi(4) = 2 $.
   - For$$n = p^k$$where$$p$$is an odd prime:$$\lambda(p^k) = \phi(p^k) $.

2. **Case 2:$$n = 2^r $,$$r \geq 3 $**

   -$$\lambda(2^r) = \frac{1}{2} \phi(2^r) $.
   - For example,$$\lambda(8) = \frac{1}{2} \phi(8) = \frac{1}{2} \cdot 4 = 2 $.

## Relation to Euler's Totient Function$$\phi(n) $

$$\lambda(n)$$divides$$\phi(n)$$, where$$\phi(n)$$counts the integers up to$$n$$that are coprime to$$n$$.

- Specifically,$$\lambda(n) \mid \phi(n)$$.

## Primitive$$\lambda$$-Root Modulo$$n $

The Carmichael function$$\lambda(n) $, in number theory, identifies the smallest positive integer$$m$$such that$$a^m \equiv 1 \pmod{n}$$for all integers$$a$$coprime to$$n $. A **primitive$$\lambda $-root modulo$$n $** is an integer$$g$$meeting specific conditions related to$$\lambda(n) $:

1. **Coprime Condition**:$$g$$is coprime to$$n $.
2. **Order Condition**:$$g$$has the property that$$g^{\lambda(n)} \equiv 1 \pmod{n} $.
3. **Uniqueness of Order**: For any integer$$m < \lambda(n) $,$$g^m \not\equiv 1 \pmod{n} $.

### Example Explanation

Let's illustrate this with an example:

#### Example: Finding Primitive$$\lambda $-Roots Modulo$$n $

Consider$$n = 15 $.

1. **Compute$$\lambda(n) $**:

   - First, calculate$$\phi(15) $:$$\phi(15) = 15 \cdot \left(1 - \frac{1}{3}\right) \cdot \left(1 - \frac{1}{5}\right) = 8 $.
   - Determine$$\lambda(15) $: Since$$15 = 3 \cdot 5 $, and both 3 and 5 are primes,
     $
     \lambda(15) = \operatorname{lcm}(\lambda(3), \lambda(5)) = \operatorname{lcm}(2, 4) = 4.
     $

2. **Identify Primitive$$\lambda $-Roots**:

   - To find primitive$$\lambda $-roots modulo$$15 $, we look for integers$$g$$that satisfy:

     -$$g$$is coprime to$$15$$(i.e.,$$\gcd(g, 15) = 1 $).
     -$$g^4 \equiv 1 \pmod{15} $.
     -$$g^m \not\equiv 1 \pmod{15}$$for$$m < 4 $.

   - Possible values for$$g $: 2, 7, 8, and 13 are primitive$$\lambda $-roots modulo$$15 $.

     -$$2^4 \equiv 1 \pmod{15} $,
     -$$7^4 \equiv 1 \pmod{15} $,
     -$$8^4 \equiv 1 \pmod{15} $,
     -$$13^4 \equiv 1 \pmod{15} $.

   - These values exhibit the cyclic behavior where the powers of each$$g$$cycle through all coprime residues modulo$$15$$in exactly$$\lambda(15) = 4$$steps before returning to 1.

## Carmichael's Theorems

### Theorem 1

If$$a$$is coprime to$$n $, then$$a^{\lambda(n)} \equiv 1 \pmod{n} $. This theorem establishes that$$\lambda(n)$$is the smallest positive integer such that$$a^{\lambda(n)} \equiv 1 \pmod{n}$$holds for all integers$$a$$coprime to$$n $. Moreover,$$\lambda(n)$$determines the order of every element in the multiplicative group of integers modulo$$n $, meaning the order of any element coprime to$$n$$divides$$\lambda(n) $.

**Explanation**:

- The Carmichael function$$\lambda(n)$$provides the smallest exponent$$m$$such that$$a^m \equiv 1 \pmod{n}$$for all$$a$$coprime to$$n $.
- This theorem ensures a uniform cyclic behavior among elements coprime to$$n $, where$$\lambda(n)$$bounds the periodicity of their powers modulo$$n $.

### Theorem 2

For every positive integer$$n $, there exists at least one primitive$$\lambda $-root modulo$$n $. Moreover, if$$g$$is such a root, then there are$$\phi(\lambda(n))$$primitive$$\lambda $-roots congruent to powers of$$g $. This theorem guarantees the existence of primitive$$\lambda $-roots modulo$$n$$and clarifies that these roots are not necessarily congruent to powers of a single root$$g $.

**Explanation**:

- A primitive$$\lambda $-root modulo$$n$$is an element$$g$$coprime to$$n$$such that$$g$$has the smallest order$$\lambda(n)$$among all elements coprime to$$n $.
- The theorem asserts that for any$$n $, there exists at least one such primitive root$$g $, and the total number of primitive$$\lambda $-roots modulo$$n$$is$$\phi(\lambda(n)) $.
- These roots are fundamental in number theory, particularly in applications involving cyclic properties of integers modulo$$n $, such as in cryptography and modular arithmetic.

**Examples**:

- **For$$n = 15 $**:

 $$\lambda(15) = 4 $

 $$\phi(15) = 8 $

 $$\phi(\lambda(15)) = 2 $

  There are four primitive$$\lambda$$-roots modulo 15: 2, 7, 8, and 13. These roots satisfy$$1 \equiv 2^4 \equiv 8^4 \equiv 7^4 \equiv 13^4 \pmod{15}$$.
  While 2 and 8 are congruent to powers of each other, and 7 and 13 are congruent to powers of each other, neither 7 nor 13 is congruent to a power of 2 or 8, and vice versa. There are 2 primitive$$\lambda $-roots modulo$$15 $, which are$$2$$and$$7 $.

- **For$$n = 9 $**:

 $$\lambda(9) = \phi(9) = 6 $

 $$\phi(\lambda(9)) = 2$$.

  There are two primitive$$\lambda$$-roots modulo 9: 2 and 5. Each is congruent to the fifth power of the other and is also a primitive$$\phi$$-root modulo 9.

## Additional Properties

1. **Minimality of$$\lambda(n) $**: If$$a^m \equiv 1 \pmod{n}$$for all integers$$a$$coprime to$$n$$, then$$\lambda(n)$$divides$$m$$.

2. **Divisibility**: For integers$$a$$and$$b$$, if$$a \mid b$$, then$$\lambda(a) \mid \lambda(b)$$.

3. **Composition**: For any positive integers$$a$$and$$b$$,$$\lambda(\mathrm{lcm}(a, b)) = \mathrm{lcm}(\lambda(a), \lambda(b))$$.

4. **Exponential Cycle Length**: If$$n = p*1^{r_1} p_2^{r_2} \cdots p_k^{r_k}$$, where$$p_i$$are distinct primes and$$r_i$$are their respective powers, then$$\lambda(n)$$is the least common multiple of$$\lambda(p_i^{r_i})$$. For$$r*{\mathrm{max}} = \max*i \{ r_i \}$$,$$a^r \equiv a^{\lambda(n) + r} \pmod{n}$$holds for all$$a$$and$$r \geq r*{\mathrm{max}}$$.
