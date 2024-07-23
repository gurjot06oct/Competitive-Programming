# Modular Arithmetic

**Modular arithmetic** is a branch of number theory that deals with integers under modulo operations. It involves calculations performed with respect to a modulus, which is a non-negative integer denoted by $ m $. The key concept in modular arithmetic is **congruence**.

## Congruence

In modular arithmetic, two integers $ a $ and $ b $ are said to be congruent modulo $ m $ if they have the same remainder when divided by $ m $. Formally, we write:

$ a \equiv b \pmod{m} $

This notation means that $ a $ and $ b $ leave the same remainder when divided by $ m $. Equivalently, $ a $ and $ b $ are congruent modulo $ m $ if $ m $ divides $ a - b $. In other words, $ a $ and $ b $ are congruent modulo $ m $ if $ a $ and $ b $ are multiples of $ m $ apart.

## Properties of Congruence

1. **Reflexive:** $ a \equiv a \pmod{m} $
2. **Symmetric:** If $ a \equiv b \pmod{m} $, then $ b \equiv a \pmod{m} $
3. **Transitive:** If $ a \equiv b \pmod{m} $ and $ b \equiv c \pmod{m} $, then $ a \equiv c \pmod{m} $

## Operations in Modular Arithmetic

### Addition:

$ (a + b) \mod m = [(a \mod m) + (b \mod m)] \mod m $

### Subtraction:

$ (a - b) \mod m = [(a \mod m) - (b \mod m)] \mod m $

### Multiplication:

$ (a \cdot b) \mod m = [(a \mod m) \cdot (b \mod m)] \mod m $

### Exponential:

For integers $ a $, $ b $, and $ m > 0 $, and for any integer $ n \geq 0 $, the following property holds:

$ a^n \equiv b^n \pmod{m} $

This means that if two integers $ a $ and $ b $ are congruent modulo $ m $, then their $ n $-th powers are also congruent modulo $ m $.

## Basic Properties

These are the basic properties of congruence in modular arithmetic:

- If $ a_1 \equiv b_1 \pmod{m} $ and $ a_2 \equiv b_2 \pmod{m} $:

  - $ a_1 + a_2 \equiv b_1 + b_2 \pmod{m} $.

  - $ a_1 - a_2 \equiv b_1 - b_2 \pmod{m} $.

  - $ a_1 \cdot a_2 \equiv b_1 \cdot b_2 \pmod{m} $.

- If $ a \equiv b \pmod{m} $:

  - $ ka \equiv kb \pmod{m} $ for any integer $ k $.

  - $ a + k \equiv b + k \pmod{m} $ for any integer $ k $.

  - $ a^k \equiv b^k \pmod{m} $ for any non-negative integer $ k $.

  - $ p(a) \equiv p(b) \pmod{m} $ for any polynomial $ p(x) $ with integer coefficients.

  - If $ b $ divides $ a $, then $ \left(\frac{a}{b}\right) \mod m = \frac{(a \mod (bm))}{b} $.

- Cancellation of Common Terms:

  - If $ a + k \equiv b + k \pmod{m} $, then $ a \equiv b \pmod{m} $.
  - If $ ka \equiv kb \pmod{m} $ and $ k $ is coprime with $ m $, then $ a \equiv b \pmod{m} $.
  - If $ ka \equiv kb \pmod{km} $ and $ k \neq 0 $, then $ a \equiv b \pmod{m} $.

## Modular Multiplicative Inverse

The modular multiplicative inverse of an integer $ a $ modulo $ m $ is an integer $ x $ such that:

$ a \cdot x \equiv 1 \pmod{m} $

In other words, $ x $ is the number that, when multiplied by $ a $, yields a product congruent to 1 modulo $ m $.

## Existence of the Modular Multiplicative Inverse

A modular multiplicative inverse of $ a $ modulo $ m $ exists if and only if $ a $ and $ m $ are coprime, i.e., $\gcd(a, m) = 1$. This condition ensures that there is an integer solution to the equation $ a \cdot x \equiv 1 \pmod{m} $.

## Calculating the Modular Multiplicative Inverse

The modular multiplicative inverse can be calculated using Bézout's identity and the Extended Euclidean Algorithm.

## Important Note

When $a$ and $m$ are coprime (i.e., $\text{gcd}(a, m) = 1$), the Extended Euclidean Algorithm can be used to find the coefficients $x$ and $y$ such that:

$ ax + my = 1 $

- $x$ is the modular multiplicative inverse of $a$ modulo $m$. This means that $ax \equiv 1 \pmod{m}$.
- $y$ is the modular multiplicative inverse of $m$ modulo $a$. This means that $my \equiv 1 \pmod{a}$.

The Extended Euclidean Algorithm is used to find the integers $ x $ and $ y $ that satisfy Bézout's identity. Here’s how you can calculate the modular multiplicative inverse of $ a $ modulo $ m $:

1. **Run the Euclidean Algorithm** to find $\gcd(a, m)$:

   - Use the Euclidean Algorithm to express the gcd as a linear combination of $ a $ and $ m $.

2. **Use the Extended Euclidean Algorithm** to backtrack and find the coefficients $ x $ and $ y $:

   - Initialize $ x_0 = 1 $, $ y_0 = 0 $, $ x_1 = 0 $, $ y_1 = 1 $.
   - Update the coefficients as you backtrack through the steps of the Euclidean Algorithm.

3. **Extract the modular multiplicative inverse**:

   - The coefficient $ x $ obtained from the equation $ ax + my = 1 $ is the modular multiplicative inverse of $ a $ modulo $ m $.

## Example Calculation

Let's calculate the modular multiplicative inverse of $ a = 15 $ modulo $ m = 26 $.

1. **Euclidean Algorithm**:

   $
   \begin{aligned}
   26 &= 15 \cdot 1 + 11 \\
   15 &= 11 \cdot 1 + 4 \\
   11 &= 4 \cdot 2 + 3 \\
   4 &= 3 \cdot 1 + 1 \\
   3 &= 1 \cdot 3 + 0
   \end{aligned}
   $

   Here, $\gcd(15, 26) = 1$, so the inverse exists.

2. **Extended Euclidean Algorithm** (backtrack to find $ x $ and $ y $):

   $
   \begin{aligned}
   1 &= 4 - 3 \cdot 1 \\
   &= 4 - (11 - 4 \cdot 2) \\
   &= 4 \cdot 3 - 11 \\
   &= (15 - 11) \cdot 3 - 11 \\
   &= 15 \cdot 3 - 11 \cdot 4 \\
   &= 15 \cdot 3 - (26 - 15) \cdot 4 \\
   &= 15 \cdot 7 - 26 \cdot 4
   \end{aligned}
   $

   Thus, $ 1 = 15 \cdot 7 - 26 \cdot 4 $. Therefore, $ x = 7 $ is the modular multiplicative inverse of $ 15 $ modulo $ 26 $.

3. **Verify**:

   $
   15 \cdot 7 \equiv 105 \equiv 1 \pmod{26}
   $

# Residue Class System

## Definition

A **residue class system** is a way of categorizing integers based on their remainders when divided by a fixed positive integer, typically denoted by $ n $. This categorization uses the concept of congruence modulo $ n $.

## Congruence Modulo $ n $

Two integers $ a $ and $ b $ are said to be congruent modulo $ n $ (written as $ a \equiv b \pmod{n} $) if their difference $ a - b $ is an integer multiple of $ n $. Formally, $ a \equiv b \pmod{n} $ if $ n $ divides $ a - b $.

## Residue Class

A **residue class** modulo $ n $ is the set of all integers that are congruent to a particular integer $ a $ modulo $ n $. This set is denoted by $[a]_n$, which means:

$ [a]\_n = \{ a + kn \mid k \in \mathbb{Z} \} $

## Complete Residue System

A **complete residue system** modulo $ n $ is a set of $ n $ integers, each of which belongs to a different residue class modulo $ n $. These integers are representative of all possible remainders when any integer is divided by $ n $.

### Example

For $ n = 5 $, a complete residue system modulo 5 could be $\{0, 1, 2, 3, 4\}$. Any integer can be expressed as one of these values modulo 5.

## Reduced Residue System

A **reduced residue system** modulo $ n $ is a subset of a complete residue system that includes only those integers that are coprime with $ n $ (i.e., their greatest common divisor with $ n $ is 1).

### Example

For $ n = 8 $, a reduced residue system modulo 8 could be $\{1, 3, 5, 7\}$, since these are the integers less than 8 that are coprime with 8.

## Properties of Residue Classes

1. **Equivalence Relation**: Congruence modulo $ n $ is an equivalence relation, meaning it is reflexive, symmetric, and transitive.
2. **Partitioning**: The set of all integers is partitioned into $ n $ residue classes modulo $ n $. Each integer belongs to exactly one residue class.
3. **Addition and Multiplication**: Residue classes can be added and multiplied, which induces a well-defined addition and multiplication operation on the set of residue classes.

## Applications

- **Cryptography**: Many cryptographic algorithms, such as RSA, use properties of residue classes.
- **Number Theory**: The study of residue classes is fundamental in number theory, especially in solving congruences and understanding modular arithmetic.
- **Computer Science**: Residue class systems are used in hashing functions, error detection and correction, and other algorithms.

### Key Points

- **Congruence Relation**: $ a \equiv b \pmod{n} $
- **Residue Class**: $[a]_n = \{ a + kn \mid k \in \mathbb{Z} \}$
- **Complete Residue System**: $ n $ distinct integers representing all residue classes
- **Reduced Residue System**: Subset of complete residue system with integers coprime to $ n $
