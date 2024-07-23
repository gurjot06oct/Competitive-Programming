# Bonse's Inequality

**Bonse's Inequality** is a significant result in number theory that provides a lower bound for the largest prime factor of an integer greater than 1. It states that for any integer$$n > 1 $, the largest prime factor$$p$$of$$n$$satisfies:

$$p \geq \sqrt{n} $

## Explanation

Bonse's Inequality asserts that if$$n$$is a composite number (greater than 1 and not prime), then its largest prime factor$$p$$is at least as large as the square root of$$n $. This inequality is useful in number theory for estimating the size of the largest prime factor of composite numbers.

## Intuitive Understanding

Consider$$n$$as a composite number, say$$n = ab $, where$$a$$and$$b$$are integers greater than 1 and$$a \leq b $. If$$p$$is the largest prime factor of$$n $, then$$p$$must be greater than or equal to$$\sqrt{n}$$because if$$p < \sqrt{n} $, then$$p$$would not be able to divide$$n$$as$$p$$would be smaller than one of$$a$$or$$b $.

## Example

Let's illustrate Bonse's Inequality with an example:

For$$n = 100 $:

-$$\sqrt{100} = 10 $.

The prime factors of$$100$$are$$2$$and$$5 $, with$$5$$being the largest prime factor. Here,$$5 \geq 10 $, confirming Bonse's Inequality.

## Applications

**Prime Factorization:** Helps in estimating the size of the largest prime factor of composite numbers without complete factorization.

## Limitations

Bonse's Inequality provides a lower bound for the largest prime factor but does not specify how close$$p$$will be to$$\sqrt{n} $. For some numbers, the largest prime factor can significantly exceed$$\sqrt{n} $, especially for highly composite numbers with multiple large prime factors.

# Number of Divisors

To determine the number of divisors$$d(n)$$and the sum of divisors$$\sigma(n)$$of a given number$$n $, we rely on its prime factorization.

**Multiplicative Property**:$$d(ab) = d(a) \cdot d(b)$$for coprime$$a$$and$$b $.

### Calculation of$$d(n) $:

Every divisor$$d$$of$$n$$must be formed from a subset of the prime factors of$$n $. If$$n$$has a prime factorization$$n = p_1^{e_1} \cdot p_2^{e_2} \cdots p_k^{e_k} $, where$$p_i$$are distinct primes, the number of divisors is given by:

$$d(n) = (e_1 + 1)(e_2 + 1) \cdots (e_k + 1) $

Here,$$e_i$$denotes the exponent of the prime$$p_i$$in the factorization of$$n $.

### Example:

For$$n = 60 = 2^2 \cdot 3 \cdot 5 $:

$$d(60) = (2+1)(1+1)(1+1) = 12 $

# Sum of Divisors

The sum of all divisors$$\sigma(n)$$of$$n$$can also be computed using its prime factorization:

**Multiplicative Property**:$$\sigma(ab) = \sigma(a) \cdot \sigma(b)$$for coprime$$a$$and$$b $.

### Calculation of$$\sigma(n) $:

$$\sigma(n) = \prod\_{i=1}^{k} \frac{p_i^{e_i + 1} - 1}{p_i - 1} $

This formula holds true for$$n = p_1^{e_1} \cdot p_2^{e_2} \cdots p_k^{e_k} $, where$$p_i$$are distinct primes and$$e_i$$are their respective exponents in the factorization of$$n $.

### Example:

For$$n = 60 = 2^2 \cdot 3 \cdot 5 $:

$$\sigma(60) = \left( \frac{2^{2+1} - 1}{2 - 1} \right) \cdot \left( \frac{3^{1+1} - 1}{3 - 1} \right) \cdot \left( \frac{5^{1+1} - 1}{5 - 1} \right) $

These functions compute$$d(n)$$and$$\sigma(n)$$efficiently using the properties of prime factorization, ensuring accurate results even for large numbers.
