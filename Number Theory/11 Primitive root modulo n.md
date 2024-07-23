# Primitive Root Modulo $ n $

**Definition:**

- A primitive root modulo $ n $ is an integer $ g $ such that every integer $ a $ coprime to $ n $ can be expressed as $ g^k \equiv a \pmod{n} $ for some integer $ k $.

**Key Point:**

- $ g $ generates the entire set of integers coprime to $ n $ under modulo $ n $.

**Example:**

- For $ n = 7 $, the integer 3 is a primitive root because:
  - $ 3^1 \equiv 3 \pmod{7} $
  - $ 3^2 \equiv 2 \pmod{7} $
  - $ 3^3 \equiv 6 \pmod{7} $
  - $ 3^4 \equiv 4 \pmod{7} $
  - $ 3^5 \equiv 5 \pmod{7} $
  - $ 3^6 \equiv 1 \pmod{7} $

**Explanation:**

- This sequence shows that 3 generates all integers coprime to 7 (1, 2, 3, 4, 5, 6).

**Utility:**

- Primitive roots are essential in number theory and cryptography because they enable the representation of all integers coprime to $ n $ through their powers.

## Multiplicative Order

**Definition:**

- The multiplicative order of an integer $ a $ modulo $ n $ is the smallest positive integer $ k $ such that $ a^k \equiv 1 \pmod{n} $.

**Key Point:**

- It indicates how many times $ a $ must be multiplied by itself modulo $ n $ to return to 1.

  **Example:**

  - For $ n = 7 $ and $ a = 3 $:
    - $ 3^6 \equiv 1 \pmod{7} $
  - The multiplicative order of 3 modulo 7 is 6.

- An integer $ g $ is a primitive root modulo $ n $ if its multiplicative order is $ \phi(n) $, where $ \phi $ is Euler's totient function.

  **Example:**

  - For $ n = 7 $, $ \phi(7) = 6 $. Since 3 has a multiplicative order of 6, it is a primitive root modulo 7.

## Discrete Logarithm

**Definition:**

- The discrete logarithm of an integer $ a $ to the base $ g $ modulo $ n $ is the exponent $ k $ such that $ g^k \equiv a \pmod{n} $.

**Key Point:**

- Finding $ k $ given $ a $, $ g $, and $ n $ is computationally difficult, which is why this concept is vital in cryptography.

  **Example:**

  - For $ n = 7 $, $ g = 3 $, and $ a = 6 $:
    - $ 3^3 \equiv 6 \pmod{7} $
    - The discrete logarithm of 6 to the base 3 modulo 7 is $ k = 3 $.

**Application:**

- The discrete logarithm problem is fundamental in cryptographic protocols such as Diffie-Hellman key exchange and elliptic curve cryptography.

## Shanks' Baby-step Giant-step algorithm

Shanks' Baby-step Giant-step algorithm is a method for solving the discrete logarithm problem. The discrete logarithm problem is the problem of finding an integer $ k $ such that:

 $ g^k \equiv a \pmod{p} $

Here, $ g $ is a known base, $ a $ is a known value, and $ p $ is a prime modulus.

### Steps of Shanks' Baby-step Giant-step Algorithm

1. **Preliminaries:**

   - Let $ m = \lceil \sqrt{p-1} \rceil $, where $ \lceil x \rceil $ denotes the ceiling function, which rounds $ x $ up to the nearest integer.

2. **Baby Steps:**

   - Compute and store the values of $ g^j \pmod{p} $ for $ j = 0, 1, 2, \ldots, m-1 $.
   - Store these values in a table (or dictionary) with $ g^j $ as the key and $ j $ as the value.

3. **Giant Steps:**

   - Compute $ g^{-m} \pmod{p} $. This can be done using the extended Euclidean algorithm to find the modular inverse of $ g $ modulo $ p $ and then raising it to the power $ m $.
   - Initialize a variable $ y $ to $ a \pmod{p} $.
   - For each $ i $ from 0 to $ m-1 $:
     - Check if $ y $ is in the table created during the baby steps.
     - If $ y = g^j \pmod{p} $ for some $ j $, then the solution is $ k = im + j $.
     - Update $ y $ to $ y \cdot g^{-m} \pmod{p} $.

4. **Solution:**
   - If a match is found in the giant step, return $ k $.
   - If no match is found, the algorithm terminates without a solution (although this should not happen if $ g $ is a generator).

### Example

Let's find $ x $ such that $ 2^x \equiv 22 \pmod{29} $.

1. **Preliminaries:**

   - $ p = 29 $
   - $ g = 2 $
   - $ h = 22 $
   - $ m = \lceil \sqrt{28} \rceil = 6 $

2. **Baby Steps:**

   - Compute $ 2^j \pmod{29} $ for $ j = 0, 1, 2, 3, 4, 5 $:
     - $ 2^0 \equiv 1 \pmod{29} $
     - $ 2^1 \equiv 2 \pmod{29} $
     - $ 2^2 \equiv 4 \pmod{29} $
     - $ 2^3 \equiv 8 \pmod{29} $
     - $ 2^4 \equiv 16 \pmod{29} $
     - $ 2^5 \equiv 3 \pmod{29} $ (since $ 32 \mod 29 = 3 $)
   - Store these values in a table.

3. **Giant Steps:**

   - Compute $ 2^{-6} \pmod{29} $:
     - $ 2^{-1} \equiv 15 \pmod{29} $ (since $ 2 \cdot 15 \equiv 1 \pmod{29} $)
     - $ 2^{-6} \equiv 15^6 \pmod{29} $
     - $ 15^2 \equiv 22 \pmod{29} $
     - $ 15^4 \equiv 20 \pmod{29} $
     - $ 15^6 \equiv 24 \pmod{29} $
   - Initialize $ y = 22 \pmod{29} $.

4. **Iteration of Giant Steps:**
   - $ i = 0 $: $ y = 22 $, check if 22 is in the table. Not found.
   - $ i = 1 $: $ y = 22 \cdot 24 \equiv 6 \pmod{29} $, check if 6 is in the table. Not found.
   - $ i = 2 $: $ y = 6 \cdot 24 \equiv 28 \equiv -1 \pmod{29} $, check if -1 is in the table. Not found.
   - $ i = 3 $: $ y = (-1) \cdot 24 \equiv -24 \equiv 5 \pmod{29} $, check if 5 is in the table. Not found.
   - $ i = 4 $: $ y = 5 \cdot 24 \equiv 4 \pmod{29} $, check if 4 is in the table. Found $ 4 = 2^2 $.
   - Therefore, $ x = 4 \cdot 6 + 2 = 26 $.

## Discrete Root

The problem of finding a discrete root is defined as follows. Given a prime $ n $ and two integers $ a $ and $ k $, find all $ x $ for which:

 $ x^k \equiv a \pmod{n} $

We solve this problem by reducing it to the discrete logarithm problem.

1. **Primitive Root Modulo $ n $**:

   - Let $ g $ be a primitive root modulo $ n $. Since $ n $ is prime, a primitive root exists, and it can be found in $ O(\text{Ans} \cdot \log \phi(n) \cdot \log n) = O(\text{Ans} \cdot \log^2 n) $ plus the time of factoring $ \phi(n) $.
   - If $ a = 0 $, the only answer is $ x = 0 $.

2. **Reduction to Discrete Logarithm**:

   - Since $ n $ is prime and any number between 1 and $ n-1 $ can be represented as a power of the primitive root, we can rewrite the discrete root problem:

     $ (g^y)^k \equiv a \pmod{n} $

   - Where:

     $ x \equiv g^y \pmod{n} $

   - This can be rewritten as:

     $ (g^k)^y \equiv a \pmod{n} $

3. **Solving the Discrete Logarithm Problem**:
   - We now have one unknown $ y $, which is a discrete logarithm problem. The solution can be found using Shanks' baby-step giant-step algorithm in $ O(\sqrt{n} \log n) $.
   - Once we find one solution $ y_0 $, one solution of the discrete root problem will be:
    $ x_0 = g^{y_0} \pmod{n} $

### Finding All Solutions from One Known Solution

To find all solutions, knowing one of them $ x_0 = g^{y_0} \pmod{n} $:

- A primitive root $ g $ always has an order of $ \phi(n) $, i.e., the smallest power of $ g $ which gives 1 is $ \phi(n) $. Therefore, if we add $ \phi(n) $ to the exponent, we still get the same value:
 $ x^k \equiv g^{ y_0 \cdot k + l \cdot \phi(n)} \equiv a \pmod{n} \quad \forall l \in \mathbb{Z} $

Hence, all solutions are of the form:
 $ x = g^{y_0 + \frac{l \cdot \phi(n)}{k}} \pmod{n} \quad \forall l \in \mathbb{Z} $

Where $ l $ is chosen such that the fraction is an integer. For this to be true, the numerator has to be divisible by the least common multiple of $ \phi(n) $ and $ k $. Remember that the least common multiple of two numbers $ \text{lcm}(a, b) = \frac{a \cdot b}{\gcd(a, b)} $, so we'll get:

 $ x = g^{y_0 + i \frac{\phi(n)}{\gcd(k, \phi(n))}} \pmod{n} \quad \forall i \in \mathbb{Z} $

This is the final formula for all solutions to the discrete root problem.
