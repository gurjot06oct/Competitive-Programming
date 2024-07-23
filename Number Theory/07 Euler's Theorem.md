# Euler's theorem

Euler's theorem is a fundamental result in number theory. It provides a relationship between powers, modular arithmetic, and the Euler's totient function. Here's an explanation of Euler's theorem:

## Statement of Euler's Theorem

Euler's theorem states that if$$a$$and$$n$$are coprime integers (i.e.,$$\gcd(a, n) = 1 $), then:

$$a^{\phi(n)} \equiv 1 \pmod{n} $

where$$\phi(n)$$denotes Euler's totient function, which counts the number of integers up to$$n$$that are coprime with$$n $.

## Totient Function ($$\phi(n) $)

The totient function, denoted as$$\phi(n) $, is a fundamental arithmetic function in number theory. It counts the number of integers up to$$n$$that are coprime with$$n $, meaning they share no common divisors other than 1. Here's how it is defined:

$
 \phi(n) = n \prod_{p \mid n} \left( 1 - \frac{1}{p} \right)
$

Where:

-$$n$$is a positive integer.
-$$p$$ranges over all distinct prime factors of$$n $.

### Properties and Use:

- **Prime Numbers**: For a prime number$$p $,$$\phi(p) = p - 1 $. This is a special case of Euler's totient function, known as Fermat's little theorem.

- **Multiplicative Property**: If$$\gcd(m, n) = 1 $, then$$\phi(mn) = \phi(m) \cdot \phi(n) $.

- **Summation Formula**:
  $
  \sum_{d \mid n} \phi(d) = n
  $
  , where the sum is over all divisors$$d$$of$$n $.

## Example

Let's illustrate Euler's theorem with an example:

- Take$$a = 3$$and$$n = 10 $.

- Compute$$\phi(10) $:

 $$\phi(10) = 10 \left( 1 - \frac{1}{2} \right) \left( 1 - \frac{1}{5} \right) = 10 \cdot \frac{1}{2} \cdot \frac{4}{5} = 4 $

- According to Euler's theorem:

 $$3^4 \equiv 1 \pmod{10} $

Indeed, calculating$$3^4 = 81$$and$$81 \mod 10 = 1 $, confirms Euler's theorem.

## Cototient Function ($$\phi'(n) $)

The cototient function, denoted as$$\phi'(n) $, is less commonly used but related to the totient function$$\phi(n) $. It counts the number of integers up to$$n$$that are **not** coprime with$$n $. In other words, it counts integers up to$$n$$that share at least one common divisor with$$n $.

$$\phi'(n) = n - \phi(n) $

### Example:

- For$$n = 10 $:
  -$$\phi(10) = \phi(2 \cdot 5) = (2-1)(5-1) = 4 $.
  -$$\phi'(10) = 10 - 4 = 6 $.

## Divisor sum property

This interesting property was established by Gauss:

$$\sum\_{d|n} \phi{(d)} = n$

Here the sum is over all positive divisors $d$ of $n$ .

For instance the divisors of 10 are 1, 2, 5 and 10. Hence  
$\phi{(1)} + \phi{(2)} + \phi{(5)} + \phi{(10)} = 1 + 1 + 4 + 4 = 10$ .

# Fermat's little theorem

Fermat's Little Theorem is a fundamental result in number theory, named after the French mathematician Pierre de Fermat. It provides a powerful tool for understanding the behavior of integers under exponentiation in modular arithmetic. Euler's theorem is a generalization of Fermat's little theorem. Here's an explanation of Fermat's Little Theorem:

## Statement

If$$p$$is a prime number and$$a$$is an integer not divisible by$$p $, then:

$$a^{p-1} \equiv 1 \pmod{p} $

Or equivalently,

$$a^p \equiv a \pmod{p} $

## Explanation

1. **Basic Formulation**: Fermat's Little Theorem states that if$$p$$is a prime number and$$a$$is an integer not divisible by$$p $, then$$a^{p-1}$$is congruent to$$1$$modulo$$p $. This means that$$a^{p-1}$$leaves a remainder of$$1$$when divided by$$p $.

2. **Equivalent Form**: Another way to state the theorem is that$$a$$raised to the power of$$p$$is congruent to$$a$$itself modulo$$p $. This can be derived from the first statement by multiplying both sides by$$a $.

## Implications and Applications

- **Primality Testing**: Fermat's Little Theorem is used in algorithms to test whether a number$$p$$is prime. If$$a^{p-1} \not\equiv 1 \pmod{p}$$for some$$a $, then$$p$$is definitely composite. However, if$$a^{p-1} \equiv 1 \pmod{p}$$for many different values of$$a $,$$p$$is likely to be prime (though not guaranteed due to the existence of Carmichael numbers).

- **Modular Exponentiation**: The theorem simplifies computations involving large powers of integers modulo a prime$$p $. Instead of calculating$$a^b$$directly and then taking modulo$$p $, one can reduce$$b$$modulo$$p-1$$and compute$$a^b \mod p$$directly using the theorem.

- **Cryptographic Applications**: Fermat's Little Theorem is foundational in some aspects of public key cryptography, especially in the RSA algorithm where it is used to efficiently compute modular inverses.

## Example

**Example 1**: Let's take$$p = 5$$and$$a = 2 $.

- According to Fermat's Little Theorem,$$2^4 \equiv 1 \pmod{5} $.
- Calculating$$2^4 = 16 $, and$$16 \mod 5 = 1 $, which confirms the theorem.

**Example 2**: For a prime$$p = 7$$and$$a = 3 $,

-$$3^6 \equiv 1 \pmod{7} $.
- Calculating$$3^6 = 729 $, and$$729 \mod 7 = 1 $, which again confirms the theorem.

## Fermat quotient

Fermat quotients are a fascinating concept in number theory, specifically related to Fermat's Little Theorem. Here's a concise explanation:

**Fermat's Little Theorem:**
If$$p$$is a prime number and$$a$$is an integer not divisible by$$p $, then$$a^{p-1} \equiv 1 \pmod{p} $.

**Fermat quotient:**
For an integer$$a$$and a prime number$$p $, the Fermat quotient$$q_p(a)$$is defined as:
$$q_p(a) = \frac{a^{p-1} - 1}{p} $

This quotient plays a significant role in studying the properties of integers modulo$$p$$and primes. Here’s a more detailed look at its definition and properties:

1. **Definition**: For an integer$$a$$coprime to$$p $,$$q_p(a)$$is calculated by taking$$a$$to the power of$$p-1 $, subtracting 1, and dividing by$$p $.

2. **Coprime Requirement**:$$a$$must be coprime to$$p$$to ensure$$q_p(a)$$is well-defined.

3. **Properties**:

   - **Fermat's Little Theorem**: Ensures that$$q_p(a)$$is an integer for$$a$$coprime to$$p $.
   - **Cyclic Nature**: If$$a$$is a generator of the reduced residue system modulo$$p $,$$q_p(a)$$becomes a cyclic number.
   - **Congruences**: Various congruences include:
     -$$q_p(1) = 0 $
     -$$q_p(-a) \equiv q_p(a) \pmod{p} $
     -$$q_p(a^b) \equiv b q_p(a) \pmod{p} $
     -$$q_p(a^r) \equiv r q_p(a) \pmod{p} $
     -$$q_p(pa) \equiv q_p(a) \pm 1 \pmod{p} $
     -$$q_p(p) = \pm 1 \pmod{p} $
     -$$a^{p-1} \equiv 1 + p \cdot q_p(a) \pmod{p^2} $
   - **Iterative Properties**:$$q_p(a + np) = q_p(a) - n$$for integers$$n $.
   - **Divisibility**:$$q_p(a)$$is always an integer.

4. **Applications:**
   - **Primality Testing**: Fermat quotients are used in probabilistic primality tests like the Fermat test.
   - **Number Theory**: They provide insights into the structure of prime numbers and their relationships with other integers.

### Understanding Cyclic Behavior:

1. **Modulo$$p$$Behavior:**

   - For a fixed prime$$p $,$$q_p(a)$$depends on$$a$$modulo$$p $. This means$$q_p(a)$$will repeat every$$p$$values of$$a $.

2. **Modulo$$p^2$$Behavior:**

   - When considering$$q_p(a)$$modulo$$p^2 $, the values can exhibit more complex cyclic patterns. While not strictly periodic,$$q_p(a)$$tends to show periodic behavior over longer intervals.

3. **Example of Cyclic Pattern:**
   - Take$$p = 5$$as an example:
     - Calculate$$q_5(a)$$for$$a = 1, 2, 3, 4 $:
       -$$q_5(1) = 1 $
       -$$q_5(2) = 6 $
       -$$q_5(3) = 16 $
       -$$q_5(4) = 31 $
     - Notice the sequence$$1, 6, 16, 31$$repeats after every$$p = 5$$values of$$a $.

# Modular Multiplicative Inverse using Euler's Theorem:

To find the modular multiplicative inverse of $a \mod n$, you want to find an integer $x$$such that:

$$a \cdot x \equiv 1 \pmod{n} $

Using Euler's theorem, the modular multiplicative inverse of $a \mod n$$can be found as:

$$a^{\phi(n) - 1} \equiv a^{-1} \pmod{n} $

## Steps:

1. **Compute $\phi(n)$**: Determine the value of Euler's totient function $\phi(n)$.

2. **Compute $a^{\phi(n) - 1} \mod n$**: Use exponentiation to find $a$$raised to the power of $\phi(n) - 1$, and then take the result modulo $n$.

## Special Case:

When$$m$$is a prime number, the calculation of the modular multiplicative inverse becomes simpler. This is because Euler's totient function$$\phi(m)$$for a prime$$m$$is$$m - 1 $.

Using specific case of Euler's theorem for prime moduli, we have:

$$a^{m-1} \equiv 1 \pmod{m} $

Thus:

$$a^{m-2} \equiv a^{-1} \pmod{m} $

So, the modular multiplicative inverse of$$a$$modulo$$m$$is:

$$x \equiv a^{m-2} \pmod{m} $

Let's go through an example to illustrate the process. Suppose we want to find the modular multiplicative inverse of $a = 7$$modulo $n = 11$.

## Example:

1. **Compute $\phi(11)$**:
   Since 11 is a prime number, $\phi(11) = 11 - 1 = 10$.

2. **Compute $7^{10 - 1} \mod 11$**:
  $$7^9 \mod 11 $

We can compute $7^9 \mod 11$$using modular exponentiation:

$$7^9 \equiv (7^2)^4 \cdot 7 \equiv 49^4 \cdot 7 \equiv 5^4 \cdot 7 \pmod{11} $

Continuing with the calculations:

$$5^4 \equiv 625 \equiv 9 \pmod{11} $
$$9 \cdot 7 \equiv 63 \equiv 8 \pmod{11} $

So, the modular multiplicative inverse of 7 modulo 11 is 8.

## Key Points and Interpretation

1. **Coprime Requirement**: Euler's theorem requires that$$a$$and$$n$$be coprime. If$$\gcd(a, n) = 1 $, then$$a$$has a multiplicative inverse modulo$$n $, allowing us to talk about powers of$$a$$modulo$$n $.

2. **Implication**: The theorem implies that raising$$a$$to the power of$$\phi(n) $, where$$\phi(n)$$is the Euler's totient function of$$n $, results in$$1$$modulo$$n $.

3. **Special Cases**:

   - For general composite$$n $,$$\phi(n)$$gives the exponent to which$$a$$must be raised to obtain$$1$$modulo$$n $.

4. **Applications**:

   - **Cryptographic Applications**: Used in RSA encryption algorithm for secure communication.
   - **Group Theory**: Relates to the structure of multiplicative groups modulo$$n $.
   - **Number Theory**: Provides insights into the distribution of integers modulo$$n$$and properties of prime numbers.
