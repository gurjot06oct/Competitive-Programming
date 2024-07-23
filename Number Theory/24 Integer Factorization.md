# Integer Factorization

Integer factorization involves finding the prime factors of a given integer $ N $. There are several methods for integer factorization, with different levels of complexity and efficiency. Here, I'll describe the **trial division method** and the **Pollard's rho algorithm**, providing pseudocode for both.

## 1. Trial Division Method

The trial division method is the simplest factorization method. It involves dividing $ N $ by each integer up to $ \sqrt{N} $ to check for factors.

### Pseudocode for Trial Division:

```pseudo
function trialDivision(N):
    factors = []
    // Check for the number of 2s that divide N
    while N is even:
        factors.append(2)
        N = N / 2

    // N must be odd at this point, so skip even numbers
    for i = 3 to sqrt(N) step 2:
        while N % i == 0:
            factors.append(i)
            N = N / i

    // If N is still greater than 2, then N is prime
    if N > 2:
        factors.append(N)

    return factors
```

## Explanation:

1. **Initial Setup:**

   - Start with an empty list of factors.
   - Check if $ N $ is even and divide it by 2 until it is odd, adding 2 to the factor list each time.

2. **Iteration:**

   - Iterate over odd numbers from 3 up to $ \sqrt{N} $.
   - For each number, divide $ N $ by that number as long as it is divisible, adding the divisor to the factor list each time.

3. **Final Check:**
   - If $ N $ is still greater than 2, it must be a prime number and is added to the factor list.

## 2. Pollard's Rho Algorithm

Pollard's rho algorithm is a more advanced factorization method that uses a pseudo-random function to find factors of $ N $. It is particularly useful for large numbers where trial division becomes inefficient.

### Pseudocode for Pollard's Rho:

```pseudo
function pollardsRho(N):
    if N is even:
        return 2

    function f(x):
        return (x * x + 1) % N

    x = 2
    y = 2
    d = 1

    while d == 1:
        x = f(x)
        y = f(f(y))
        d = gcd(abs(x - y), N)

    if d == N:
        return None  // Failure, need to retry with a different function or seed
    else:
        return d

function gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a
```

## Explanation:

1. **Initial Setup:**

   - Start with a function $ f(x) = (x^2 + 1) \mod N $.
   - Initialize two variables, $ x $ and $ y $, both set to 2, and a divisor $ d $ set to 1.

2. **Iteration:**

   - Use a loop to apply the function $ f $ to $ x $ and $ f(f) $ to $ y $, checking the greatest common divisor (GCD) of $ |x - y| $ and $ N $ each time.

3. **Factor Found:**
   - If $ d $ becomes a non-trivial factor (not 1 or $ N $), return it.
   - If $ d $ equals $ N $, the algorithm failed and may need to be retried with a different function or seed value.

These methods provide a starting point for integer factorization. For larger numbers or more efficient factorization, advanced methods such as the Quadratic Sieve or the General Number Field Sieve can be used.

## 3. Fermat's Factorization Method

Fermat's factorization method is based on the representation of an odd integer $ N $ as the difference of two squares:

$ N = a^2 - b^2 $

This can be rewritten as:

$ N = (a - b)(a + b) $

Fermat's method involves finding such integers $ a $ and $ b $. Here's the step-by-step process along with pseudocode:

### Steps:

1. **Initial setup:**

   - Start with $ a $ as the ceiling of the square root of $ N $: $ a = \lceil \sqrt{N} \rceil $.
   - Compute $ b^2 = a^2 - N $.

2. **Iteration:**

   - If $ b^2 $ is a perfect square, then $ b = \sqrt{b^2} $.
   - If $ b^2 $ is not a perfect square, increment $ a $ by 1 and recompute $ b^2 = a^2 - N $.
   - Repeat until $ b^2 $ is a perfect square.

3. **Factorization:**
   - Once $ b^2 $ is a perfect square, you have $ a $ and $ b $ such that $ N = (a - b)(a + b) $.
   - Return the factors $ (a - b) $ and $ (a + b) $.

### Pseudocode:

```pseudo
function fermatFactorization(N):
    if N is even:
        return 2, N / 2

    a = ceil(sqrt(N))
    b2 = a^2 - N

    while not isPerfectSquare(b2):
        a = a + 1
        b2 = a^2 - N

    b = sqrt(b2)

    factor1 = a - b
    factor2 = a + b

    return factor1, factor2

function isPerfectSquare(x):
    s = sqrt(x)
    return s * s == x
```

## Explanation:

- **Initialization:**

  - Start with $ a $ as the smallest integer greater than or equal to the square root of $ N $.
  - Compute $ b^2 $ as the difference between $ a^2 $ and $ N $.

- **Iteration:**

  - Use a loop to increment $ a $ and recompute $ b^2 $ until $ b^2 $ is a perfect square.
  - The `isPerfectSquare` function checks if a number is a perfect square by taking its square root and squaring it back.

- **Factorization:**
  - Once $ b^2 $ is found to be a perfect square, compute $ b $ and use it to find the factors of $ N $.

This method works efficiently for numbers where the difference between $ a $ and $ b $ is small, but it can be slow for numbers with large factors close to $ \sqrt{N} $.

## 4. Dixon's Factorization Method

Dixon's factorization method is an integer factorization algorithm that uses congruences of squares to factor a composite number $ n $. It relies on finding numbers $ x $ and $ y $ such that $ x^2 \equiv y^2 \pmod{n} $ and then using these to find factors of $ n $. The method involves using a factor base and solving a system of linear equations.

### Steps:

1. **Select a Factor Base:**

   - Choose a set of small primes that will be used to factor the numbers $ y $ (smooth numbers).

2. **Generate Relations:**

   - Find several pairs $ (x, y) $ such that $ x^2 \equiv y \pmod{n} $ and $ y $ can be factored completely over the factor base.

3. **Build a Matrix:**

   - Construct a matrix where each row corresponds to a relation $ x^2 \equiv y \pmod{n} $.
   - The columns correspond to the primes in the factor base, and the entries are the exponents of the primes in the factorization of $ y $, taken modulo 2.

4. **Solve the Matrix:**

   - Use Gaussian elimination to find a non-trivial linear combination of the rows that sum to the zero vector.

5. **Compute the Congruence of Squares:**

   - From the solution of the matrix, compute the product of the corresponding $ x $ values and the product of the corresponding $ y $ values to form a congruence of squares.

6. **Factorize $ n $:**
   - Use the greatest common divisor (GCD) to find non-trivial factors of $ n $.

### Pseudocode:

```pseudo
function dixonFactorization(n):
    factorBase = generateFactorBase(n)
    relations = []

    while not enoughRelations(relations, factorBase):
        x = randomInteger()
        y = (x^2) % n
        if isSmooth(y, factorBase):
            relations.append((x, y))

    matrix = buildMatrix(relations, factorBase)
    solution = solveMatrix(matrix)

    x = 1
    y = 1
    for rel in solution:
        x = (x * rel.x) % n
        y = (y * rel.y) % n

    factor1 = gcd(x - y, n)
    factor2 = gcd(x + y, n)

    if factor1 == 1 or factor1 == n:
        return None  // Failure, need to retry
    else:
        return factor1, factor2

function generateFactorBase(n):
    // Generate small primes for the factor base
    primes = []
    for p in smallPrimesUpToBound:
        if p is a quadratic residue modulo n:
            primes.append(p)
    return primes

function isSmooth(number, factorBase):
    // Check if the number can be completely factored using the factor base
    for p in factorBase:
        while number % p == 0:
            number = number / p
    return number == 1

function buildMatrix(relations, factorBase):
    // Build the matrix where each row corresponds to a relation
    // Each column corresponds to a prime in the factor base
    // Entries are the parity of the exponent of each prime
    matrix = []
    for (x, y) in relations:
        row = []
        for p in factorBase:
            count = 0
            while y % p == 0:
                y = y / p
                count = count + 1
            row.append(count % 2)
        matrix.append(row)
    return matrix

function solveMatrix(matrix):
    // Use Gaussian elimination to solve the matrix
    // Find a subset of rows whose sum is the all-zero row
    // Return the corresponding relations
    // Implementation of Gaussian elimination
    // Return the solution (set of relations that sum to zero)
```

### Example: Factorizing 1649 Using Dixon's Method

1. **Select a Factor Base:**

   - Suppose our factor base is \{2, 3, 5, 7\}.

2. **Generate Relations:**

   - Find pairs $ (x, y) $ such that $ x^2 \equiv y \pmod{n} $ and $ y $ factors over the factor base:

     $
     \begin{aligned}
     41^2 &\equiv 32 = 2^5 \pmod{1649}, \\
     42^2 &\equiv 115 = 5 \cdot 23 \pmod{1649}, \\
     43^2 &\equiv 200 = 2^3 \cdot 5^2 \pmod{1649}.
     \end{aligned}
     $

3. **Build a Matrix:**

   - Construct the matrix from the exponents modulo 2:

     $
     \begin{array}{c|cccc}
     & 2 & 3 & 5 & 7 \\
     \hline
     41^2 & 1 & 0 & 0 & 0 \\
     42^2 & 0 & 0 & 1 & 0 \\
     43^2 & 1 & 0 & 1 & 0 \\
     \end{array}
     $

4. **Solve the Matrix:**

   - Use Gaussian elimination to find a linear combination that sums to zero:

     $
     \begin{array}{c|cccc}
     & 2 & 3 & 5 & 7 \\
     \hline
     41^2 & 1 & 0 & 0 & 0 \\
     43^2 & 1 & 0 & 1 & 0 \\
     \end{array}
     $

     - Combining $ 41^2 $ and $ 43^2 $:

     $
     41^2 \cdot 43^2 \equiv 32 \cdot 200 = 2^5 \cdot 2^3 \cdot 5^2 = 2^8 \cdot 5^2 = (2^4 \cdot 5)^2 = 80^2 \pmod{1649}.
     $

5. **Factorize $ n $:**

   - Compute:

     $
     \begin{aligned}
     \text{gcd}(114 - 80, 1649) &= 17, \\
     \text{gcd}(114 + 80, 1649) &= 97.
     \end{aligned}
     $

   - Factors of 1649 are 17 and 97.

## 5. Quadratic Sieve

In number theory, a cQuadratic Sieve is a congruence commonly used in integer factorization algorithms. The idea is to find numbers $ x $ and $ y $ such that:

$ x^2 \equiv y^2 \pmod{n} $

$ x \not\equiv \pm y \pmod{n} $

This implies:

$ x^2 - y^2 \equiv 0 \pmod{n} $

$ (x + y)(x - y) \equiv 0 \pmod{n} $

This means that $ n $ divides the product $ (x + y)(x - y) $. Since $ x \not\equiv \pm y \pmod{n} $, $ n $ does not divide $ x + y $ nor $ x - y $ individually, ensuring that each factor contains some, but not all, factors of $ n $. The greatest common divisors of $ (x + y, n) $ and $ (x - y, n) $ will give us the factors of $ n $.

### Using a Factor Base

A technique used in more advanced factorization methods, such as Dixon's factorization method, the quadratic sieve, and the general number field sieve, involves constructing a congruence of squares using a factor base. Instead of finding one pair $ x^2 \equiv y^2 \pmod{n} $ directly, we find many "relations" $ x^2 \equiv y \pmod{n} $, where $ y $ has only small prime factors (they are smooth numbers). By multiplying some of them together, we get a square on the right-hand side.

### Example 1: Factorizing 35

1. Take $ n = 35 $.
2. Find $ x $ and $ y $:
   $ 6^2 = 36 \equiv 1 = 1^2 \pmod{35} $
3. Factorize using GCD:
   $ \gcd(6 - 1, 35) \cdot \gcd(6 + 1, 35) = 5 \cdot 7 = 35 $

### Example 2: Factorizing 1649 Using Dixon's Factorization Method

1. Take $ n = 1649 $.
2. Obtain several congruences:
   $ 41^2 \equiv 32 = 2^5 \pmod{1649} $
   $ 42^2 \equiv 115 = 5 \cdot 23 \pmod{1649} $
   $ 43^2 \equiv 200 = 2^3 \cdot 5^2 \pmod{1649} $
3. Multiply congruences to get a square:
   $ 32 \cdot 200 = 2^{5+3} \cdot 5^2 = 2^8 \cdot 5^2 = (2^4 \cdot 5)^2 = 80^2 $
   $ 32 \cdot 200 = 80^2 \equiv 41^2 \cdot 43^2 \equiv 114^2 \pmod{1649} $
4. Use values of $ 80 $ and $ 114 $ to get factors:
   $ \gcd(114 - 80, 1649) \cdot \gcd(114 + 80, 1649) = 17 \cdot 97 = 1649 $

### Pseudocode for Finding Congruences of Squares Using a Factor Base

```pseudo
function findCongruencesOfSquares(n):
    factorBase = generateFactorBase(n)
    relations = []

    while not enoughRelations(relations, factorBase):
        x = randomInteger()
        y = (x^2) % n
        if isSmooth(y, factorBase):
            relations.append((x, y))

    matrix = buildMatrix(relations, factorBase)
    solution = solveMatrix(matrix)

    x = 1
    y = 1
    for rel in solution:
        x = (x * rel.x) % n
        y = (y * rel.y) % n

    return gcd(x - y, n), gcd(x + y, n)

function generateFactorBase(n):
    // Generate small primes for the factor base
    // Use primes less than a certain bound

function isSmooth(number, factorBase):
    // Check if the number can be completely factored using the factor base

function buildMatrix(relations, factorBase):
    // Build the matrix where each row corresponds to a relation
    // Each column corresponds to a prime in the factor base
    // Entries are the parity of the exponent of each prime

function solveMatrix(matrix):
    // Use Gaussian elimination to solve the matrix
    // Find a subset of rows whose sum is the all-zero row
```

This method leverages linear algebra to find congruences of squares efficiently, allowing for factorization of large integers by breaking the problem into manageable pieces.

## 6. Pollard's p − 1 Algorithm

Pollard's $ p - 1 $ algorithm is a number theory-based integer factorization algorithm that exploits the properties of the group of units modulo a composite number $ n $. It is particularly effective when $ n $ has a prime factor $ p $ such that $ p - 1 $ is smooth, i.e., it has only small prime factors.

### Steps:

1. **Choose a Bound $ B $:**

   - This bound $ B $ is used to control the smoothness of $ p - 1 $.

2. **Select a Random Base $ a $:**

   - Choose a random integer $ a $ such that $ 1 < a < n $.

3. **Compute $ a^{k!} \mod n $:**

   - For each prime $ q $ up to $ B $, compute $ a^{q^k} \mod n $, where $ k $ is the largest integer such that $ q^k \leq B $.

4. **Compute GCD:**

   - Compute $ \gcd(a^{M} - 1, n) $, where $ M $ is the product of all $ q^k $ computed in the previous step.
   - If the GCD is a non-trivial factor of $ n $, then return it.

5. **If no factor is found, increase $ B $ and repeat.**

### Pseudocode:

```pseudo
function pollards_p_minus_1(n, B):
    a = random(2, n-1)
    M = 1

    for prime in smallPrimesUpTo(B):
        power = floor(log(B) / log(prime))
        M = M * prime^power

    aM = mod_exp(a, M, n)  // a^M % n
    g = gcd(aM - 1, n)

    if 1 < g < n:
        return g
    else:
        return failure

function mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp = exp // 2
    return result

// Helper function to get small primes up to a bound
function smallPrimesUpTo(B):
    primes = []
    sieve = [true] * (B + 1)
    for p in range(2, B + 1):
        if sieve[p]:
            primes.append(p)
            for multiple in range(p * p, B + 1, p):
                sieve[multiple] = false
    return primes
```

### Example: Factorizing $ n = 1387 $ with $ B = 5 $

1. **Choose $ B = 5 $.**
2. **Select a random base $ a $:**
   - Let $ a = 2 $.
3. **Compute $ M $:**
   - For small primes up to 5:
     - $ 2^2 = 4 $ (since $ 2^2 \leq 5 $)
     - $ 3^1 = 3 $ (since $ 3^1 \leq 5 $)
     - $ 5^1 = 5 $ (since $ 5^1 \leq 5 $)
   - $ M = 4 \cdot 3 \cdot 5 = 60 $.
4. **Compute $ a^M \mod n $:**
   - $ 2^{60} \mod 1387 $:
     - Using modular exponentiation: $ 2^{60} \mod 1387 = 307 $.
5. **Compute GCD:**
   - $ \gcd(307 - 1, 1387) = \gcd(306, 1387) = 17 $.

Thus, 17 is a non-trivial factor of 1387.

### Explanation of Pollard's $ p - 1 $ Algorithm:

- The algorithm is effective when $ p - 1 $ (where $ p $ is a prime factor of $ n $) is smooth.
- By exponentiating $ a $ to a large power $ M $ composed of small primes and their powers, we are leveraging the group structure of $\mathbb{Z}_p^*$ where the order of $ a $ modulo $ p $ divides $ p - 1 $.
- The GCD step helps to reveal a non-trivial factor of $ n $.

Pollard's $ p - 1 $ algorithm is simple and can be quite powerful, especially for numbers with prime factors having smooth $ p - 1 $ values.

## 7. Segmented Sieve

Segmented Sieve is an optimization of the Sieve of Eratosthenes algorithm used to find all prime numbers in a given range `[L, R]`. This algorithm is particularly useful when `R` is large. Here's a step-by-step explanation and pseudocode for the Segmented Sieve algorithm:

### Steps for Segmented Sieve

1. **Use Simple Sieve to Find Small Primes:**
   - Find all primes up to $\sqrt{R}$ using the simple Sieve of Eratosthenes.
2. **Mark Non-Primes in the Segment:**
   - Use the primes from the simple sieve to mark non-prime numbers in the range `[L, R]`.

### Pseudocode

```pseudo
function simpleSieve(limit):
    isPrime = array of true values of size (limit + 1)
    isPrime[0] = isPrime[1] = false
    for p from 2 to sqrt(limit):
        if isPrime[p]:
            for multiple from p*p to limit step p:
                isPrime[multiple] = false
    primes = empty list
    for p from 2 to limit:
        if isPrime[p]:
            append p to primes
    return primes

function segmentedSieve(L, R):
    limit = floor(sqrt(R)) + 1
    primes = simpleSieve(limit)

    isPrime = array of true values of size (R - L + 1)

    if L == 1:
        isPrime[0] = false  // 1 is not a prime number

    for prime in primes:
        // Find the minimum number in [L, R] that is a multiple of prime
        start = max(prime*prime, L + (prime - L % prime) % prime)
        for j from start to R step prime:
            isPrime[j - L] = false

    // Collect all prime numbers in the range [L, R]
    segmentedPrimes = empty list
    for i from 0 to (R - L):
        if isPrime[i]:
            append (i + L) to segmentedPrimes

    return segmentedPrimes

// Example usage
L = 10
R = 50
primesInRange = segmentedSieve(L, R)
print(primesInRange)
```

### Explanation

1. **simpleSieve(limit):**

   - Create an array `isPrime` where `isPrime[i]` is true if `i` is a prime.
   - Use the Sieve of Eratosthenes to mark non-prime numbers up to `limit`.
   - Collect and return all primes up to `limit`.

2. **segmentedSieve(L, R):**
   - Compute `limit` as $\sqrt{R}$ and find all primes up to `limit` using `simpleSieve`.
   - Create an array `isPrime` to mark the primality of numbers in the range `[L, R]`.
   - For each prime from `simpleSieve`, mark its multiples within the range `[L, R]` as non-prime.
   - Collect and return all numbers in the range `[L, R]` that remain marked as prime.

### Key Points

- The Segmented Sieve algorithm optimizes memory usage by only storing prime information within the given range `[L, R]`.
- It utilizes the simple Sieve of Eratosthenes to efficiently find small primes up to $\sqrt{R}$.
- It avoids redundant calculations by starting marking from the maximum of `prime * prime` and `L`.

This pseudocode should give you a clear idea of how the Segmented Sieve algorithm works and can be implemented in any programming language.
