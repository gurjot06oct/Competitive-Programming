# Basic Terms

## Prime Numbers

A **prime number** is a natural number greater than 1 that has no positive divisors other than 1 and itself. This means it cannot be formed by multiplying two smaller natural numbers. Prime numbers are the building blocks of the integers, as every number can be factored into a product of primes.

**Examples:**

- The first few prime numbers are 2, 3, 5, 7, 11, 13, and so on.
- 2 is the only even prime number; all other primes are odd.

## Composite Numbers

A **composite number** is a natural number greater than 1 that is not prime, meaning it has more than two positive divisors. In other words, a composite number can be divided exactly by at least one positive integer other than 1 and itself.

**Examples:**

- The number 4 is composite because it can be divided by 1, 2, and 4.
- The number 9 is composite because it can be divided by 1, 3, and 9.

## Factors

**Factors** of a number are the integers that can be multiplied together to produce that number. For a given number $ n $, a factor is any integer $ d $ such that $ n \mod d = 0 $.

**Examples:**

- Factors of 12 are 1, 2, 3, 4, 6, and 12.
- Factors of 15 are 1, 3, 5, and 15.

## Least Common Multiple (LCM)

The **least common multiple (LCM)** of two or more integers is the smallest positive integer that is divisible by each of the numbers. It represents the smallest number into which each of the original numbers can divide without leaving a remainder.

**Examples:**

- The LCM of 4 and 5 is 20 because 20 is the smallest number divisible by both 4 and 5.
- The LCM of 6 and 8 is 24 because 24 is the smallest number divisible by both 6 and 8.

## Greatest Common Divisor (GCD)

The **greatest common divisor (GCD)** of two or more integers is the largest positive integer that divides each of the numbers without leaving a remainder. It is also known as the greatest common factor (GCF).

**Examples:**

- The GCD of 8 and 12 is 4 because 4 is the largest number that divides both 8 and 12.
- The GCD of 18 and 24 is 6 because 6 is the largest number that divides both 18 and 24.

## Coprime

Two integers are **coprime** (or relatively prime) if their GCD is 1. This means that the two numbers have no common prime factors and cannot be divided by any same integer greater than 1.

**Examples:**

- 8 and 15 are coprime because their GCD is 1.
- 14 and 25 are coprime because their GCD is 1.

# Divisibility

## Definitions

Consider the division of 97 by 24:

$ 97 = 24 \cdot 4 + 1 $

Here, 4 is the quotient and 1 is the remainder. In the division:

$ 96 = 24 \cdot 4 + 0 $

the remainder is 0. Therefore, 96 is divisible by both 24 and 4.

**Definition 1:** Let $ a $ and $ b $ be two natural numbers such that $ b $ leaves a remainder of 0 upon division by $ a $. Then $ b $ is said to be divisible by $ a $, denoted $ a | b $. Alternatively, the notation $ b .. a $ is sometimes used, but in this note, we will primarily use $ a | b $. Here, $ a $ is called a divisor of $ b $, and $ b $ is a multiple of $ a $. If $ b $ leaves a remainder other than 0, then $ b $ is not divisible by $ a $, denoted $ a \nmid b $.

**Examples:**

- $ 7 | 343 $
- 565655 is a multiple of 5
- 29 is a divisor of 841

Practice with more examples to become familiar with the notations and definitions of divisibility, as further reading will require a solid understanding of these concepts.

**Definition 2:** A number is prime if it is not divisible by any positive integer except 1 and itself. Prime numbers are fundamental in number theory and are the building blocks of the entire subject.

**Examples:**

- 2 is the only even prime number.
- For any even number greater than 2, it must be divisible by 2 and thus cannot be a prime.
- The first three odd primes are 3, 5, and 7.

**Definition 3:** A number is called even if it leaves a remainder of 0 upon division by 2, and odd if it leaves a remainder of 1. The property of a number being even or odd is called parity. Two numbers have the same parity if they are both odd or both even; otherwise, they have opposite parity.

**Examples:**

- 5 and 7 have the same parity, whereas 4 and 3 do not.

**Claims to Verify:**

1. The sum and difference of two numbers with the same parity are even.
2. The sum and difference of two numbers with different parity are odd.
3. Increasing or decreasing a number by a multiple of 2 does not change its parity.
4. Any odd multiple of a number has the same parity as the number, while an even multiple has even parity.
5. Parity remains unchanged when raising a number to a power.

## Properties of Divisibility

Here are some properties and corollaries related to divisibility:

1. If $ a | b $, then $ \frac{b}{a} $ is a positive integer.

- Let $ b = ak $. Thus, if $ a | b $, there exists a unique positive integer (the quotient) such that $ b = ak $.

2. $ a | a $ and $ a | 0 $ for all $ a \in \mathbb{Z} $.

3. If $ a | b $, then $ a | -b $, $ -a | b $, and $ -a | -b $.

4. If $ a | b $, then $ b \ge a $. The only case when $ b < a $ is $ b = 0 $. Specifically, if $ a, b \in \mathbb{N} $ and $ a | b $, then $ b \ge a $.

5. If $ a | b $ and $ b | a $, then $ a = b $.

6. If $ a | b $ and $ b | c $, then $ a | c $.

- Let $ b = ak $ and $ c = bk' $. Then, $ c = akk' $ implies $ a | c $.

7. If $ a | b $, then $ ac | bc $, and conversely, if $ ac | bc $, then $ a | b $.

8. If $ a | b $ and $ a | c $, then any linear combination of $ b $ and $ c $ is divisible by $ a $.

- In other words, $ a | (bx + cy) $ for integers $ x $ and $ y $.

9. If $ d | p $, then $ d = 1 $ or $ d = p $.

10. If $ a | b $, every prime divisor $ p $ of $ a $ also divides $ b $.

11. If $ a \nmid b $, then there exists a remainder $ r $ such that $ 0 < r < a $. Let $ b = aq + r $. This $ r $ is unique if $ 0 < r < a $.

12. For all composite numbers $ n > 1 $, $ n $ has a prime divisor $ p $ such that $ p \le \sqrt{n} $.

- If $ n $ is composite, it has a smallest prime factor $ p $. Then $ n = pk $ for some $ k \ge p $. If $ k < p $, $ k $ would have a prime factor smaller than $ p $, which is not possible. Therefore, $ k \ge p $, leading to $ n \ge p^2 $, hence $ p \le \sqrt{n} $. This property is useful for determining if a number is prime, especially for small numbers.

## Divisibility by Specific Numbers

Certain numbers have unique divisibility properties, including 2, 3, 4, 5, and 9. Here are some of these properties:

1. **Divisibility by 2:** A number is divisible by 2 if its last digit is divisible by 2.
2. **Divisibility by 3:** A number is divisible by 3 if the sum of its digits is divisible by 3.
3. **Divisibility by 4:** A number is divisible by 4 if its last two digits form a number that is divisible by 4.
4. **Divisibility by 5:** A number is divisible by 5 if its last digit is 0 or 5.
5. **Divisibility by 9:** A number is divisible by 9 if the sum of its digits is divisible by 9.

Feel free to explore and come up with more divisibility rules for other numbers.

## General Divisibility Rules

There are some general rules about divisibility that apply to any numbers:

1. If $ a | b $ and $ a | c $, then:

- $ a | (b + c) $

- $ a | (b - c) $

- $ a | (kb) $ for any integer $ k $

2. If $ d | f $ and $ e | f $, then:

- $ \text{lcm}(d, e) | f $ where lcm is the least common multiple.

3. If $ g | h $ and $ i | j $, then:

- $ gi | hj $

# Fundamental Theorem of Arithmetic

The **Fundamental Theorem of Arithmetic** is a key concept in number theory and states:

**Theorem:** Every integer greater than 1 can be uniquely expressed as a product of prime numbers, up to the order of the factors.

This means that for any integer $ n > 1 $, there is a unique set of prime numbers $ p_1, p_2, \ldots, p_k $ and corresponding positive integers $ e_1, e_2, \ldots, e_k $ such that:

$ n = p_1^{e_1} \cdot p_2^{e_2} \cdot \ldots \cdot p_k^{e_k} $

## Explanation

1. **Uniqueness:** The prime factorization of a number is unique except for the order of the factors. For example, the number 60 can be factorized into primes as:

   $ 60 = 2^2 \cdot 3^1 \cdot 5^1 $

   This factorization is unique up to the order of the primes.

2. **Existence:** Every integer greater than 1 can be broken down into a product of prime numbers. A prime number is defined as a number greater than 1 that has no positive divisors other than 1 and itself.

## Examples

- **Example 1:** Consider the number 84.

  $ 84 = 2^2 \cdot 3^1 \cdot 7^1 $

  Here, 2, 3, and 7 are prime numbers, and their product gives 84.

- **Example 2:** The number 100.

  $ 100 = 2^2 \cdot 5^2 $

  The primes 2 and 5 with their respective exponents 2 and 2 give the unique factorization of 100.

## Applications

1. **Greatest Common Divisor (GCD):** The GCD of two numbers can be found using their prime factorizations by taking the lowest power of all common prime factors.

- For example, to find the GCD of 84 and 100:

  $ 84 = 2^2 \cdot 3^1 \cdot 7^1 $

  $ 100 = 2^2 \cdot 5^2 $

  The common prime factor is 2, and the lowest power is $ 2^2 $.

  $ \text{GCD}(84, 100) = 2^2 = 4 $

2. **Least Common Multiple (LCM):** The LCM of two numbers is found by taking the highest power of all prime factors present in either number.

- For example, to find the LCM of 84 and 100:

  $ 84 = 2^2 \cdot 3^1 \cdot 7^1 $

  $ 100 = 2^2 \cdot 5^2 $

  The prime factors are 2, 3, 5, and 7. The highest powers are $ 2^2, 3^1, 5^2, 7^1 $.

  $ \text{LCM}(84, 100) = 2^2 \cdot 3^1 \cdot 5^2 \cdot 7^1 = 4200 $

3. **Simplifying Fractions:** Prime factorization helps in simplifying fractions by cancelling common prime factors in the numerator and the denominator.

- For example, to simplify $\frac{84}{100}$:

  $ \frac{84}{100} = \frac{2^2 \cdot 3^1 \cdot 7^1}{2^2 \cdot 5^2} $

  Cancel the common factor $2^2$:

  $ \frac{84}{100} = \frac{3 \cdot 7}{5^2} = \frac{21}{25} $

# Euclid's Lemma

**Euclid's Lemma** is a fundamental result in number theory that relates to the divisibility of integers and primes. It is often used in proofs related to prime numbers and the fundamental theorem of arithmetic.

## Statement

Euclid's Lemma states that if a prime number $ p $ divides the product of two integers $ a $ and $ b $, then $ p $ must divide at least one of $ a $ or $ b $.

**Formally:** If $ p $ is a prime number and $ p \mid ab $, then $ p \mid a $ or $ p \mid b $.

## Proof Outline

To understand why Euclid's Lemma holds true, we can reason through its proof:

1. **Prime Divides Product:** Assume $ p $ is a prime number and $ p \mid ab $. This means there exists an integer $ k $ such that $ ab = pk $.

2. **Consider Prime Factorization:**

- If $ p $ divides $ a $, then we are done.

- If $ p $ does not divide $ a $, then $ p $ and $ a $ must be coprime (since $ p $ is prime and does not divide $ a $). Therefore, $ p $ must divide $ b $ because it divides their product $ ab $.

3. **Conclusion:** In either case, $ p $ divides at least one of $ a $ or $ b $.

## Example

Let's apply Euclid's Lemma to the integers $ a = 15 $, $ b = 7 $, and the prime $ p = 5 $:

- $ ab = 15 \cdot 7 = 105 $.
- $ 5 $ divides $ 105 $.
- By Euclid's Lemma, $ 5 $ must divide $ 15 $ or $ 7 $, which is true since $ 5 $ divides $ 15 $.

# Euclidean Algorithm

The **Euclidean Algorithm** is an efficient method for finding the Greatest Common Divisor (GCD) of two integers. The GCD of two numbers is the largest number that divides both of them without leaving a remainder. The algorithm is based on the principle that the GCD of two numbers also divides their difference.

## Steps of the Euclidean Algorithm

1. **Start with two positive integers** $ a $ and $ b $, where $ a > b $.
2. **Divide** $ a $ by $ b $ and find the remainder $ r $ (i.e., $ a = b \cdot q + r $ for some integer $ q $).
3. **Replace** $ a $ with $ b $ and $ b $ with $ r $.
4. **Repeat** the process until $ r = 0 $. The non-zero remainder just before $ r $ becomes 0 is the GCD of $ a $ and $ b $.

## Example

Let's find the GCD of 252 and 105 using the Euclidean Algorithm.

1. **Initial values:** $ a = 252 $, $ b = 105 $

2. **First step:**

   $ 252 = 105 \cdot 2 + 42 $

   $ a = 105, \ b = 42 $

3. **Second step:**

   $ 105 = 42 \cdot 2 + 21 $

   $ a = 42, \ b = 21 $

4. **Third step:**

   $ 42 = 21 \cdot 2 + 0 $

   $ a = 21, \ b = 0 $

Since the remainder is now 0, we stop. The GCD is the last non-zero remainder, which is 21. Therefore, $ \text{GCD}(252, 105) = 21 $.

## Pseudocode

Here is a pseudocode representation of the Euclidean Algorithm:

- **Recursive**

  ```
  function gcd(a, b)
      if b == 0
          return a
      else
          return gcd(b, a % b)
  ```

- **Iterative**

  ```
  function gcd(a, b)
      while b != 0
          (a, b) = (b, a % b)
      return a
  ```

## Applications

1. **Simplifying Fractions:** The Euclidean Algorithm is used to simplify fractions by dividing the numerator and the denominator by their GCD.
2. **Cryptography:** It is used in algorithms for public-key cryptography, such as RSA.
