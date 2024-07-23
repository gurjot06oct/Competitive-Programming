# Linear Congruences

A linear congruence is an equation of the form:

$ ax \equiv b \pmod{m} $

where $ a $, $ b $, and $ m $ are given integers, and $ x $ is the unknown integer to be determined.

## Existence of Solutions

A linear congruence $ ax \equiv b \pmod{m} $ has a solution if and only if the greatest common divisor (gcd) of $ a $ and $ m $ divides $ b $. Formally, the congruence $ ax \equiv b \pmod{m} $ has a solution if:

$ \gcd(a, m) \mid b $

Here's a clear and structured explanation of why this is true:

### Key Points

1. **Linear Congruence:** A linear congruence $ ax \equiv b \pmod{m} $ means there exists an integer $ x $ such that $ ax $ and $ b $ differ by a multiple of $ m $. In other words, $ ax = b + km $ for some integer $ k $.

2. **Greatest Common Divisor:** The greatest common divisor $ \gcd(a, m) $ is the largest positive integer that divides both $ a $ and $ m $.

### Necessary Condition

**If a solution $ x $ exists, then $ \gcd(a, m) $ must divide $ b $:**

- Suppose $ x $ is a solution to $ ax \equiv b \pmod{m} $.
- This means $ ax = b + km $ for some integer $ k $.
- Rearrange this to $ ax - km = b $.
- Note that $ \gcd(a, m) $ divides both $ a $ and $ m $. Let's denote $ d = \gcd(a, m) $.
- Since $ d $ divides $ a $ and $ m $, it must also divide any linear combination of $ a $ and $ m $.
- Therefore, $ d $ divides $ ax - km $, which is $ b $.
- Thus, $ \gcd(a, m) $ divides $ b $.

### Sufficient Condition

**If $ \gcd(a, m) $ divides $ b $, then there is a solution to $ ax \equiv b \pmod{m} $:**

- Let $ d = \gcd(a, m) $.
- Since $ d $ divides $ a $, we can write $ a = d \cdot a_1 $ for some integer $ a_1 $.
- Similarly, since $ d $ divides $ m $, we can write $ m = d \cdot m_1 $ for some integer $ m_1 $.
- Since $ d $ divides $ b $, we can write $ b = d \cdot b_1 $ for some integer $ b_1 $.
- The original congruence $ ax \equiv b \pmod{m} $ can now be rewritten as:
  $
  d \cdot a_1 \cdot x \equiv d \cdot b_1 \pmod{d \cdot m_1}
  $
- Dividing through by $ d $ (which we can do because $ d \neq 0 $):
  $
  a_1 \cdot x \equiv b_1 \pmod{m_1}
  $
- Now, $ a_1 $ and $ m_1 $ are coprime (since $ d = \gcd(a, m) $), meaning $ \gcd(a_1, m_1) = 1 $.
- When two numbers are coprime, the linear congruence $ a_1 x \equiv b_1 \pmod{m_1} $ always has a solution.
- Therefore, the original congruence $ ax \equiv b \pmod{m} $ has a solution.

## Finding Solutions

1. **Simplify the Congruence:**

   If $\gcd(a, m) = d$, divide the entire congruence by $ d $:

   $ \frac{a}{d}x \equiv \frac{b}{d} \pmod{\frac{m}{d}} $

   $ a^\prime \cdot x \equiv b^\prime \pmod{m^\prime} $   
   This reduces the problem to finding solutions for the simpler congruence.

2. **Use the Extended Euclidean Algorithm:**

   To find a solution to $ a^\prime \cdot x \equiv b^\prime \pmod{m^\prime} $  , use the Extended Euclidean Algorithm to express the gcd of $ a^\prime $ and $ m^\prime $ as a linear combination of $ a^\prime $ and $ m^\prime $:

   $ \gcd(a^\prime, m^\prime) = 1 = a^\prime \cdot u + m^\prime \cdot v $

   This gives a particular solution to the congruence.

   $ x = u \cdot b^\prime $

3. **General Solution:**

   Once a particular solution $ x $ is found, the general solution can be written as:

   $ x \pmod{m} = x + k \cdot m $

   where $ k $ is any integer. This represents all solutions to the congruence.

## Example

Solve the congruence $ 12x \equiv 8 \pmod{20} $.

1. **Compute the gcd:**

   $ \gcd(12, 20) = 4 $

   Since $ 4 \mid 8 $, the congruence has solutions.

2. **Simplify the Congruence:**

   Divide by the gcd $ d = 4 $:

   $ \frac{12}{4}x \equiv \frac{8}{4} \pmod{\frac{20}{4}} $

   $ 3x \equiv 2 \pmod{5} $

3. **Use the Extended Euclidean Algorithm:**

   Solve $ 3x \equiv 2 \pmod{5} $:

   $ 5 = 1 \cdot 3 + 2 $

   $ 3 = 1 \cdot 2 + 1 $

   $ 2 = 2 \cdot 1 + 0 $

   Back-substitute to find the coefficients:

   $ 1 = 3 - 1 \cdot 2 $

   $ 1 = 3 - 1 \cdot (5 - 1 \cdot 3) $

   $ 1 = 2 \cdot 3 - 1 \cdot 5 $

   Therefore, $ u = 2 $

   $ x \equiv 2 \cdot 2 $

   $ x \equiv 4 $

4. **General Solution:**

   The particular solution is $ x = 4 $. The general solution is: $ 4 + 20k $ for any integer $ k $.
