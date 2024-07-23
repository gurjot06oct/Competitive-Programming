# Primality Test

A primality test is an algorithm used to determine whether a given number is prime. Primality tests are widely used in various fields of mathematics and are particularly important in cryptography. Unlike integer factorization, which seeks to find the prime factors of a number, primality tests only establish whether the number is prime or not.

## 1. Trial Division

Trial division is the simplest and most straightforward method for determining if a given number$$n$$is prime. It involves checking whether$$n$$is divisible by any prime number less than or equal to$$\sqrt{n} $. If$$n$$is divisible by any of these primes, it is composite; otherwise, it is prime.

### Method

Given an input number$$n $:

1. Check if$$n$$is divisible by any prime number$$p$$such that$$2 \leq p \leq \sqrt{n} $.
2. If any such$$p$$divides$$n$$without leaving a remainder,$$n$$is composite.
3. If no such$$p$$is found,$$n$$is prime.

### Why Check Up to$$\sqrt{n} $?

For any divisor$$p \geq \sqrt{n} $, there must be a corresponding divisor$$n/p \leq \sqrt{n} $. Therefore, it suffices to check only the prime divisors up to$$\sqrt{n} $.

### Example: Checking 100

Consider the number 100. Its divisors are:
$$1, 2, 4, 5, 10, 20, 25, 50, 100 $

To find the prime divisors:

1. Calculate$$\sqrt{100} = 10 $.
2. Check prime numbers up to 10: 2, 3, 5, and 7.

Since 100 is divisible by 2 (100 / 2 = 50), it is not prime.

### Divisor Pairs

Divisor pairs of 100:
$$1 \times 100, 2 \times 50, 4 \times 25, 5 \times 20, 10 \times 10, 20 \times 5, 25 \times 4, 50 \times 2, 100 \times 1 $

Observing the pairs, for each pair$$(a, b) $:

-$$a \leq \sqrt{100} $
-$$b \geq \sqrt{100} $

This observation generalizes to all$$n $: every divisor pair of$$n$$contains a divisor less than or equal to$$\sqrt{n} $.

### Example: Checking 17

To determine the primality of 17:

1. Calculate$$\sqrt{17} \approx 4.12 $.
2. Check prime numbers up to 4: 2 and 3.

Since neither 2 nor 3 divides 17, it is prime.

### Example: Checking 221

To determine the primality of 221:

1. Calculate$$\sqrt{221} \approx 14.86 $.
2. Check prime numbers up to 14: 2, 3, 5, 7, 11, and 13.

Since 221 is divisible by 13 (221 / 13 = 17), it is not prime.

### Optimizations

#### 1. Only Odd Numbers

Since any even number greater than 2 is not prime, we can skip checking even numbers after verifying divisibility by 2.

#### 2. Form$$6k \pm 1 $

All primes greater than 3 are of the form$$6k \pm 1$$(where$$k$$is a nonnegative integer). Hence, after checking 2 and 3, we only need to check numbers of the form$$6k \pm 1$$up to$$\sqrt{n} $.

#### 3. Generalization Using Primorials

For larger numbers, primes greater than$$c \#$$(primorial of$$c $) are of the form$$c \# \cdot k + i $, where$$i$$is coprime to$$c \# $. For example:

-$$6 \# = 2 \cdot 3 \cdot 5 = 30 $
- Primes greater than 30 are of the form$$30k + i $, with$$i \in \{1, 7, 11, 13, 17, 19, 23, 29\} $.

#### 4. Pre-computed Primes

Storing a pre-computed list of primes up to a certain bound (e.g., 200) can speed up the process. Before applying large-scale methods,$$n$$can be checked against this list. If$$n$$is divisible by any of these primes, it is composite.

### Pseudocode

```
function is_prime(n):
    if n <= 1:
        return false
    if n <= 3:
        return true
    if n % 2 == 0 or n % 3 == 0:
        return false

    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return false
        i = i + 6

    return true
```

### Efficiency

Trial division is simple but not the most efficient for large numbers. More advanced algorithms like the Sieve of Eratosthenes, Fermat's primality test, and the AKS primality test offer better performance for large inputs.

## 2. Wilson's Theorem

Wilson's theorem provides a primality test based on a specific congruence involving factorials. The theorem states that a natural number$$p$$greater than 1 is a prime if and only if:

$$(p - 1)! \equiv -1 \pmod{p} $

This means that the factorial of$$p-1$$(the product of all positive integers less than$$p $) is congruent to -1 modulo$$p $.

### Method

Given an input number$$p $:

1. Compute$$(p-1)! $.
2. Check if$$(p-1)! + 1$$is divisible by$$p $.
3. If$$(p-1)! + 1$$is divisible by$$p $, then$$p$$is prime.
4. If not,$$p$$is composite.

#### Example: Checking 5

To determine the primality of 5 using Wilson's theorem:

1. Compute$$(5-1)! = 4! = 4 \times 3 \times 2 \times 1 = 24 $.
2. Check$$24 + 1 = 25 $.
3. Since 25 is divisible by 5, 5 is prime.

#### Example: Checking 7

To determine the primality of 7:

1. Compute$$(7-1)! = 6! = 6 \times 5 \times 4 \times 3 \times 2 \times 1 = 720 $.
2. Check$$720 + 1 = 721 $.
3. Since 721 is divisible by 7, 7 is prime.

#### Example: Checking 10

To determine the primality of 10:

1. Compute$$(10-1)! = 9! = 9 \times 8 \times 7 \times 6 \times 5 \times 4 \times 3 \times 2 \times 1 = 362880 $.
2. Check$$362880 + 1 = 362881 $.
3. Since 362881 is not divisible by 10, 10 is not prime.

### Practical Considerations

While Wilson's theorem is theoretically elegant, it is computationally impractical for large numbers due to the rapid growth of factorials. The number of operations required to compute$$(p-1)!$$makes this method infeasible for large$$p $.

#### Example: Large Numbers

Consider the number 17:

1. Compute$$(17-1)! = 16! = 20922789888000 $.
2. Check$$20922789888000 + 1 = 20922789888001 $.
3. Since 20922789888001 is divisible by 17, 17 is prime.

This example illustrates the computational difficulty, as calculating 16! requires many multiplications and handling large numbers.

## 3. Sieve of Eratosthenes

The Sieve of Eratosthenes is an efficient algorithm to find all prime numbers up to a given limit$$n $. Named after the ancient Greek mathematician Eratosthenes, this algorithm is particularly effective for generating a list of primes and is known for its simplicity and efficiency.

### Algorithm

The Sieve of Eratosthenes works by iteratively marking the multiples of each prime starting from 2. The numbers which remain unmarked at the end of the process are primes.

### Steps

1. **Initialization:**

   - Create a boolean array `is_prime` of size$$n+1$$and initialize all entries as `true`. The indices of this array represent the numbers from 0 to$$n $.
   - Set `is_prime[0]` and `is_prime[1]` to `false` as 0 and 1 are not prime.

2. **Marking Non-Primes:**

   - Starting from the first prime number$$p = 2 $, mark all multiples of$$p$$(i.e.,$$2p, 3p, 4p, \ldots $) as `false`.
   - Move to the next number in the array that is still `true` and repeat the process until you reach$$\sqrt{n} $.

3. **Collect Primes:**
   - The indices of the array that remain `true` are the prime numbers up to$$n $.

### Pseudocode

```python
def sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for p in range(2, int(n**0.5) + 1):
        if is_prime[p]:
            for multiple in range(p * p, n + 1, p):
                is_prime[multiple] = False

    primes = [number for number, prime in enumerate(is_prime) if prime]
    return primes
```

### Example: Finding Primes up to 30

1. **Initialization:**

   - Create an array `is_prime` of size 31, initialized to `true`.

2. **Marking Non-Primes:**

   - Start with$$p = 2 $:
     - Mark multiples: 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 as `false`.
   - Move to$$p = 3 $:
     - Mark multiples: 9, 12, 15, 18, 21, 24, 27, 30 as `false`.
   - Continue with$$p = 5$$and mark multiples: 25, 30 as `false`.

3. **Collect Primes:**
   - Primes up to 30: [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

### Time Complexity

The time complexity of the Sieve of Eratosthenes is$$O(n \log \log n) $. This can be broken down as follows:

1. **Initialization:**

   - Creating the boolean array takes$$O(n)$$time.

2. **Marking Non-Primes:**

   - For each prime$$p $, marking its multiples takes$$O(n/p)$$time.
   - Summing over all primes up to$$\sqrt{n} $, the total time complexity is$$O(n (\frac{1}{2} + \frac{1}{3} + \frac{1}{5} + \ldots)) $.

   The harmonic series of primes converges to$$\log \log n $, leading to the overall complexity of$$O(n \log \log n) $.

### Space Complexity

The space complexity of the Sieve of Eratosthenes is$$O(n) $, as it requires a boolean array of size$$n+1 $.

## 4. Sieve of Atkin

The Sieve of Atkin is an optimized algorithm for finding all prime numbers up to a specified limit. It is more efficient than the traditional Sieve of Eratosthenes for large ranges due to its better theoretical asymptotic complexity.

### Steps of the Algorithm

1. **Initialize the Sieve Array:**

   - Create a sieve list where each position is initially marked as non-prime (false).
   - If the limit is greater than 2 or 3, add 2 and 3 to the list of primes.

2. **Apply Sieve Conditions:**

   - Iterate over the values of `x` and `y` to calculate potential primes based on the following conditions:
     -$$n = 4x^2 + y^2 $
       - Flip primality of `n` if$$n \mod 12$$is 1 or 5.
     -$$n = 3x^2 + y^2 $
       - Flip primality of `n` if$$n \mod 12$$is 7.
     -$$n = 3x^2 - y^2 $
       - Flip primality of `n` if$$n \mod 12$$is 11 and$$x > y $.

3. **Filter Non-Primes:**

   - Iterate through the sieve list and mark all multiples of squares as non-prime.

4. **Collect Primes:**
   - Collect and print all numbers that are still marked as prime in the sieve list.

### Pseudocode

```pseudo
function SieveOfAtkin(limit)
    // Initialize the sieve array with false values
    sieve = array[0 to limit] filled with false

    // 2 and 3 are known to be prime
    if limit > 2 then
        sieve[2] = true
    if limit > 3 then
        sieve[3] = true

    // Apply the sieve conditions
    for x from 1 to sqrt(limit)
        for y from 1 to sqrt(limit)

            // Condition 1
            n = 4*x^2 + y^2
            if n <= limit and (n % 12 == 1 or n % 12 == 5) then
                sieve[n] = not sieve[n]

            // Condition 2
            n = 3*x^2 + y^2
            if n <= limit and n % 12 == 7 then
                sieve[n] = not sieve[n]

            // Condition 3
            n = 3*x^2 - y^2
            if x > y and n <= limit and n % 12 == 11 then
                sieve[n] = not sieve[n]

    // Mark all multiples of squares as non-prime
    for r from 5 to sqrt(limit)
        if sieve[r] == true then
            for i from r^2 to limit by r^2
                sieve[i] = false

    // Collect and print primes
    for a from 1 to limit
        if sieve[a] == true then
            print a

// Driver program
limit = 19
SieveOfAtkin(limit)
```

### Explanation of the Pseudocode

1. **Initialization:**

   - The sieve array is created with `false` values indicating that initially, all numbers are considered non-prime.
   - The known primes 2 and 3 are manually set as `true` if the limit is greater than these values.

2. **Applying Conditions:**

   - The nested loops iterate over potential values of `x` and `y` to compute `n` using the given quadratic equations.
   - For each computed `n`, the algorithm checks the conditions and flips the boolean value in the sieve array if the conditions are met.

3. **Filtering Multiples of Squares:**

   - The algorithm marks multiples of squares as non-prime, starting from the smallest primes found.

4. **Collecting Primes:**
   - Finally, the algorithm iterates over the sieve array and collects all numbers still marked as `true` (indicating they are prime) and prints them.

### Complexity

- **Time Complexity:** $O(\text{limit})$
- **Space Complexity:** $O(\text{limit})$

## 5. Sieve of Sundaram

The Sieve of Sundaram is another efficient algorithm used to generate all prime numbers up to a specified integer$$N $. Developed by Indian mathematician S. P. Sundaram in 1934, it is particularly notable for its simplicity and effectiveness in generating primes.

### Algorithm Explanation

1. **Initialization**:

   - Create a list$$A$$of integers from 1 to$$N $.
   - Define$$k = \frac{N}{2} $.

2. **Sieve Process**:

   - Iterate over pairs of integers$$i, j$$such that$$1 \leq i \leq j \leq k $.
   - For each pair$$i, j $:
     - Compute$$n = i + j + 2ij $.
     - If$$n \leq N $, mark$$n$$as non-prime by setting$$A[n-1] = 0 $.

3. **Identification of Primes**:

   - After sieving, all indices$$1 \leq i \leq k$$where$$A[i-1] \neq 0$$correspond to prime numbers$$p$$of the form$$2p + 1 $.

4. **Output**:
   - The output list of primes consists of$$2$$(included separately) and$$\{2p + 1 \mid A[i-1] \neq 0 \} $.

### Pseudo Code

Here's a pseudo code representation of the Sieve of Sundaram:

```pseudo
function SieveOfSundaram(N):
    k = N / 2
    A = [1] * (k + 1)

    for i from 1 to k:
        for j from i to (k - i) / (2 * i + 1):
            n = i + j + 2 * i * j
            if n <= k:
                A[n-1] = 0

    primes = [2]
    for i from 1 to k:
        if A[i] != 0:
            primes.append(2 * i + 1)

    return primes
```

### Computational Complexity

- **Time Complexity**: The Sieve of Sundaram runs in$$O(N \log N)$$time due to its nested loops and constraints on$$i$$and$$j $.
- **Space Complexity**: It uses$$O(N)$$space for storing the list$$A $.

### Key Points

- The algorithm efficiently generates primes up to$$N$$without directly handling even numbers (except 2).
- It leverages simple arithmetic operations to mark non-primes, making it straightforward to implement.
- Compared to other sieving methods like the Sieve of Eratosthenes, it has a higher time complexity but remains competitive for moderate$$N$$due to its simplicity.

## 6. Fermat Primality Test

The Fermat primality test is a probabilistic test to determine if a number is a prime. It is based on Fermat's Little Theorem, which states that if$$p$$is a prime number and$$a$$is an integer such that$$1 \leq a < p $, then:

$$a^{p-1} \equiv 1 \pmod{p} $

If$$p$$is composite, the above congruence usually does not hold for most values of$$a $. The Fermat primality test uses this property to check the primality of a given number.

### Algorithm

The Fermat primality test works as follows:

1. Choose a random integer$$a$$in the range$$1 \leq a < n $.
2. Compute$$a^{n-1} \mod n $.
3. If$$a^{n-1} \not\equiv 1 \pmod{n} $, then$$n$$is composite.
4. If$$a^{n-1} \equiv 1 \pmod{n} $, then$$n$$is likely prime.

To increase the accuracy, the test can be repeated multiple times with different values of$$a $.

### Pseudocode

```python
import random

def fermat_primality_test(n, k):
    if n <= 1:
        return False
    if n <= 3:
        return True

    for _ in range(k):
        a = random.randint(2, n - 2)
        if pow(a, n - 1, n) != 1:
            return False
    return True
```

### Example: Checking 17 with 3 iterations

1. **Iteration 1:**
   - Choose$$a = 2 $.
   - Compute$$2^{16} \mod 17 = 1 $.
   - Since$$1 \equiv 1 \mod 17 $, 17 might be prime.
2. **Iteration 2:**

   - Choose$$a = 5 $.
   - Compute$$5^{16} \mod 17 = 1 $.
   - Since$$1 \equiv 1 \mod 17 $, 17 might be prime.

3. **Iteration 3:**
   - Choose$$a = 7 $.
   - Compute$$7^{16} \mod 17 = 1 $.
   - Since$$1 \equiv 1 \mod 17 $, 17 might be prime.

Since all iterations passed, 17 is likely prime.

### Limitations

While the Fermat primality test is simple and fast, it has limitations:

1. **False Positives:**
   - Some composite numbers, called Carmichael numbers, can pass the test for all values of$$a$$that are coprime with$$n $.
2. **Probabilistic Nature:**
   - The test only provides a probabilistic guarantee of primality. The accuracy increases with the number of iterations, but there is always a small chance of error.

### Time Complexity

The time complexity of a single iteration of the Fermat primality test is$$O(\log n) $, due to the modular exponentiation operation. Repeating the test$$k$$times results in a total time complexity of$$O(k \log n) $.

## Important Things to Note:

### 1. Pseudoprime

A **pseudoprime** is a composite number that passes a primality test designed for prime numbers. Specifically, a **Fermat pseudoprime** to the base $a$$is a composite number $n$$that satisfies:
$$a^{n-1} \equiv 1 \pmod{n} $
for some integer $a$$where $1 \leq a < n$. While such a number is not actually prime, it "pretends" to be prime under the Fermat test for that particular base $a$.

### 2. Carmichael Number

A **Carmichael number** is a special type of composite number that passes the Fermat primality test for all bases $a$$that are coprime to the number. In other words, if $n$$is a Carmichael number, then:
$$a^{n-1} \equiv 1 \pmod{n} $
for every integer $a$$such that$$\gcd(a, n) = 1 $. This makes Carmichael numbers particularly deceptive when using the Fermat primality test.

### 3. Euler Pseudoprime

An **Euler pseudoprime** to the base $a$$is a composite number $n$$that satisfies:
$$a^{(n-1)/2} \equiv \pm 1 \pmod{n} $
This definition refines the Fermat test using Euler’s criterion, providing a stronger condition that a prime number would satisfy, but there are still composite numbers (Euler pseudoprimes) that pass this test.

### 4. Euler–Jacobi Pseudoprime

An **Euler–Jacobi pseudoprime** to the base $a$$is a composite number $n$$for which the Euler–Jacobi test holds. This test involves checking:
$$a^{(n-1)/2} \equiv \left( \frac{a}{n} \right) \pmod{n} $
where $\left( \frac{a}{n} \right)$$is the Jacobi symbol. Euler–Jacobi pseudoprimes are composite numbers that satisfy this congruence, providing another layer of refinement over the Euler pseudoprime concept.

### 5. Fibonacci Pseudoprime

A **Fibonacci pseudoprime** to a given set of initial conditions is a composite number that passes a primality test based on properties of Fibonacci numbers. These numbers fulfill specific congruences related to the Fibonacci sequence, making them appear prime under tests involving Fibonacci sequences.

### 6. Probable Prime

A **probable prime** (or PRP) is a number that passes a probabilistic primality test like the Fermat test, Miller–Rabin test, or other similar tests, and is thus likely to be prime. However, without deterministic proof, there remains some small chance that the number is actually composite. The term "probable prime" does not specify which test is used, so it could encompass any number that passes any of these probabilistic tests.

## 7. Baillie–PSW Primality Test Algorithm

The Baillie–PSW test consists of the following steps:

1. **Trial Division**: Check if the number$$n$$is divisible by any small prime numbers (typically up to 1000). If$$n$$is divisible by any of these, it is composite.

2. **Miller–Rabin Test to Base 2**: Perform the Miller–Rabin primality test to base 2. This step ensures that the number passes a strong pseudoprime test.

3. **Strong Lucas Test**: Perform a strong Lucas probable prime test using parameters derived from the number$$n $. This step ensures that the number satisfies properties related to Lucas sequences, which are more complex than those tested by the Miller–Rabin test.

### Detailed Steps

#### 1. Trial Division

First, check if$$n$$is divisible by any of the small primes (e.g., 2, 3, 5, ..., 1009). If$$n$$is divisible by any of these primes, it is composite. If not, proceed to the next step.

#### 2. Miller–Rabin Test to Base 2

Perform the Miller–Rabin primality test with base 2:

1. Write$$n - 1$$as$$d \times 2^s$$where$$d$$is odd.
2. Choose$$a = 2 $.
3. Compute$$x = a^d \mod n $.
4. If$$x = 1$$or$$x = n - 1 $,$$n$$passes this iteration.
5. Repeat the squaring step$$s - 1$$times:
   - Compute$$x = x^2 \mod n $.
   - If$$x = n - 1 $,$$n$$passes this iteration.
6. If$$x \neq n - 1$$after$$s$$squarings,$$n$$is composite.

#### 3. Strong Lucas Test

Perform a strong Lucas probable prime test:

1. Choose parameters$$P$$and$$Q$$for the Lucas sequence such that the discriminant$$D = P^2 - 4Q$$is a non-square modulo$$n $. Typically, set$$P = 1$$and$$Q = -1 $.
2. Define the Lucas sequence$$U_n$$and$$V_n$$using the chosen parameters.
3. Compute terms of the sequence to check whether$$n$$satisfies properties similar to those of primes.

### Pseudocode

Here is a pseudocode outline of the Baillie–PSW test:

```python
def is_probable_prime_bpsw(n):
    # Step 1: Trial Division
    small_primes = get_small_primes(up_to=1000)
    for prime in small_primes:
        if n % prime == 0:
            return n == prime

    # Step 2: Miller–Rabin Test to Base 2
    if not miller_rabin_test(n, base=2):
        return False

    # Step 3: Strong Lucas Test
    if not strong_lucas_test(n):
        return False

    return True

def miller_rabin_test(n, base):
    # Write n-1 as d * 2^s
    s, d = 0, n - 1
    while d % 2 == 0:
        d //= 2
        s += 1

    # Compute base^d % n
    x = pow(base, d, n)
    if x == 1 or x == n - 1:
        return True

    for _ in range(s - 1):
        x = pow(x, 2, n)
        if x == n - 1:
            return True

    return False

def strong_lucas_test(n):
    # Choose P = 1, Q = -1 for simplicity
    P, Q = 1, -1
    D = P**2 - 4*Q
    if not is_non_square_mod_n(D, n):
        return False

    # Compute Lucas sequences U_n and V_n
    U_n, V_n = lucas_sequences(n, P, Q)

    # Strong Lucas test conditions
    if U_n % n == 0 or V_n % n == 0:
        return True

    return False

def is_non_square_mod_n(D, n):
    # Check if D is a non-square modulo n
    return pow(D, (n - 1) // 2, n) == n - 1

def lucas_sequences(n, P, Q):
    # Compute Lucas sequences U_n and V_n
    # This is a placeholder; actual implementation requires recursion or iteration
    U_n, V_n = 0, 0
    return U_n, V_n
```

## 8. AKS Primality Test Algorithm

The AKS algorithm is based on properties of binomial coefficients and polynomials. Here’s a detailed explanation of the steps involved:

### Steps of the AKS Primality Test

1. **Check if $n$$is a perfect power**: Verify if there exist integers $a > 1$$and $b > 1$$such that $n = a^b$. If such integers exist, $n$$is composite.
2. **Find the smallest $r$$such that $o_r(n) > (\log_2 n)^2$**: Here, $o_r(n)$$is the order of $n$$modulo $r$, i.e., the smallest positive integer $k$$such that $n^k \equiv 1 \pmod{r}$.
3. **Check if $1 < \gcd(a, n) < n$$for some $a \leq r$**: If such an $a$$is found, then $n$$is composite.
4. **Check if $n \leq r$**: If $n \leq r$, $n$$is prime.
5. **Polynomial congruence check**: For $a = 1$$to $\lfloor \sqrt{\phi(r)} \log n \rfloor$, check if $(X+a)^n \not\equiv X^n + a \pmod{(X^r-1, n)}$. If any of these congruences fails, $n$$is composite.
6. **If all checks are passed, $n$$is prime**.

### Detailed Steps and Concepts

#### Step 1: Check if $n$$is a perfect power

A number $n$$is a perfect power if $n = a^b$$for integers $a > 1$$and $b > 1$. This can be checked by iterating over possible values of $b$$and computing the $b$-th roots.

#### Step 2: Find the smallest $r$$such that $o_r(n) > (\log_2 n)^2$

- The order $o_r(n)$$of $n$$modulo $r$$is the smallest integer $k$$for which $n^k \equiv 1 \pmod{r}$.
- Compute the order for increasing values of $r$$until the condition $o_r(n) > (\log_2 n)^2$$is met.

#### Step 3: Check if $1 < \gcd(a, n) < n$$for some $a \leq r$

- Compute the greatest common divisor of $a$$and $n$$for $a$$from 1 to $r$.
- If any $a$$yields a non-trivial divisor of $n$, then $n$$is composite.

#### Step 4: Check if $n \leq r$

- If $n$$is less than or equal to the chosen $r$, then $n$$is prime.

#### Step 5: Polynomial congruence check

- This step ensures that the polynomial congruences $(X+a)^n \equiv X^n + a \pmod{(X^r-1, n)}$$hold for all $a$$from 1 to $\lfloor \sqrt{\phi(r)} \log n \rfloor$.
- If any congruence fails, then $n$$is composite.

### Pseudocode

Here’s a pseudocode outline for the AKS primality test:

```python
def is_prime_aks(n):
    if n == 2:
        return True
    if n == 1 or n % 2 == 0:
        return False

    # Step 1: Check if n is a perfect power
    if is_perfect_power(n):
        return False

    # Step 2: Find the smallest r such that o_r(n) > (log2(n))^2
    r = find_smallest_r(n)

    # Step 3: Check if 1 < gcd(a, n) < n for some a ≤ r
    for a in range(1, r + 1):
        if 1 < gcd(a, n) < n:
            return False

    # Step 4: Check if n ≤ r
    if n <= r:
        return True

    # Step 5: Polynomial congruence check
    for a in range(1, math.isqrt(phi(r)) * int(math.log2(n)) + 1):
        if not polynomial_congruence(n, r, a):
            return False

    return True

def is_perfect_power(n):
    for b in range(2, int(math.log2(n)) + 1):
        a = int(n ** (1 / b))
        if a ** b == n or (a + 1) ** b == n:
            return True
    return False

def find_smallest_r(n):
    max_k = math.log2(n) ** 2
    r = 2
    while True:
        k = 1
        while k <= max_k and pow(n, k, r) != 1:
            k += 1
        if k > max_k:
            return r
        r += 1

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def phi(r):
    result = r
    p = 2
    while p * p <= r:
        if r % p == 0:
            while r % p == 0:
                r //= p
            result -= result // p
        p += 1
    if r > 1:
        result -= result // r
    return result

def polynomial_congruence(n, r, a):
    X = Symbol('X')
    lhs = expand((X + a) ** n % (X**r - 1))
    rhs = expand(X**n + a)
    return lhs == rhs
```

## 9. Miller–Rabin Primality Test Algorithm

### Steps of the Miller–Rabin Test

1. **Write$$n - 1$$as$$2^s \cdot d $**:

   - Decompose$$n - 1$$into the form$$2^s \cdot d$$where$$d$$is an odd number and$$s$$is a non-negative integer.

2. **Randomly choose a number$$a$$such that$$2 \leq a \leq n - 2 $**:

   - This$$a$$is called a witness.

3. **Compute$$x = a^d \mod n $**:

   - If$$x = 1$$or$$x = n - 1 $, then$$n$$passes the test for this particular$$a $.

4. **Repeat the squaring step$$s - 1$$times**:

   - Compute$$x = x^2 \mod n $. If$$x = n - 1$$at any step, then$$n$$passes the test for this particular$$a $.
   - If$$x = 1$$at any step (except the first), then$$n$$is composite.
   - If none of these conditions are met after$$s - 1$$iterations,$$n$$is composite.

5. **Repeat the above steps for a predetermined number of witnesses**:
   - The more witnesses tested, the higher the confidence in the result if$$n$$passes all the tests.

### Detailed Steps and Concepts

#### Step 1: Write$$n - 1$$as$$2^s \cdot d $

- This step involves finding$$s$$and$$d$$such that$$n - 1 = 2^s \cdot d $.
- Start with$$d = n - 1$$and divide by 2 until$$d$$is odd, incrementing$$s$$each time.

#### Step 2: Randomly choose a number$$a $

- The choice of$$a$$is critical as it serves as the base for testing.
-$$a$$must be between 2 and$$n - 2 $.

#### Step 3: Compute$$x = a^d \mod n $

- This initial calculation determines the first candidate for witness$$a $.
- If$$x$$equals 1 or$$n - 1 $,$$n$$might be prime for this$$a $.

#### Step 4: Repeat the squaring step

- Continue squaring$$x$$and reducing modulo$$n $.
- If$$x$$becomes$$n - 1$$during any of these steps,$$n$$passes the test for this$$a $.
- If$$x$$ever becomes 1 (other than the first calculation),$$n$$is composite.

#### Step 5: Repeat for multiple witnesses

- Perform the above steps for several different values of$$a $.
- If$$n$$passes for all chosen$$a $, the probability that$$n$$is composite is very low.

### Pseudocode

Here is a pseudocode outline for the Miller–Rabin primality test:

```python
import random

def miller_rabin(n, k):
    if n == 2 or n == 3:
        return True
    if n % 2 == 0 or n == 1:
        return False

    # Write n - 1 as 2^s * d
    s = 0
    d = n - 1
    while d % 2 == 0:
        d //= 2
        s += 1

    # Test with k different bases
    for _ in range(k):
        a = random.randint(2, n - 2)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(s - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True
```

### Example

Let's use the Miller–Rabin test to check if 561 is prime with$$k = 3$$(three different bases):

1. **Decompose$$561 - 1 = 560$$as$$2^4 \cdot 35 $**:

   -$$s = 4 $,$$d = 35 $.

2. **Choose three random bases$$a$$between 2 and 559**:

   - For instance, let's use$$a = 2, 7, 10 $.

3. **Test for$$a = 2 $**:

   - Compute$$x = 2^{35} \mod 561 $.
   - If$$x$$is neither 1 nor 560, continue squaring.

4. **Repeat for other values of$$a $**:
   - Each base provides a separate test.

### Relation to Pseudoprimes

- **Pseudoprime**: A composite number that passes the Miller–Rabin test for a specific base$$a $.
- **Strong Pseudoprime**: A composite number that passes the Miller–Rabin test for several bases.
- **Carmichael Number**: A composite number that passes the Miller–Rabin test for all bases$$a$$where$$1 < a < n - 1 $.

## 10. Lucas–Lehmer Primality Test Algorithm

The Lucas–Lehmer primality test is specifically designed to test the primality of Mersenne numbers, which are of the form$$M_p = 2^p - 1 $, where$$p$$is a prime number. Mersenne numbers are particularly interesting because some of them are known to be prime, and they have applications in cryptography and number theory.

### Steps of the Lucas–Lehmer Test

1. **Start with a Mersenne number$$M_p = 2^p - 1 $**, where$$p$$is a prime number.

2. **Initialize**:

   - Let$$s_0 = 4 $.
   - Compute$$s*i = s*{i-1}^2 - 2 \mod M_p$$for$$i = 1, 2, \ldots, p-2 $.

3. **Check if$$s\_{p-2} \equiv 0 \mod M_p $**:
   - If$$s\_{p-2} \equiv 0 \mod M_p $, then$$M_p$$is prime.
   - Otherwise,$$M_p$$is composite.

### Detailed Steps and Concepts

#### Initialization

- Start with$$s_0 = 4 $.

#### Iterative Calculation

- Compute$$s*i = s*{i-1}^2 - 2 \mod M_p$$for$$i = 1, 2, \ldots, p-2 $.

#### Primality Check

- If$$s\_{p-2} \equiv 0 \mod M_p $, then$$M_p$$is prime.
- Otherwise,$$M_p$$is composite.

### Example

Let's apply the Lucas–Lehmer test to check if$$M\_{11} = 2^{11} - 1$$is prime:

1. **Initialize**:

   -$$p = 11 $.
   -$$M\_{11} = 2047 $.
   -$$s_0 = 4 $.

2. **Iterative Calculation**:

   -$$s_1 = 4^2 - 2 \mod 2047 = 14 $.
   -$$s_2 = 14^2 - 2 \mod 2047 = 194 $.
   -$$s_3 = 194^2 - 2 \mod 2047 = 1809 $.
   -$$s_4 = 1809^2 - 2 \mod 2047 = 1456 $.
   -$$s_5 = 1456^2 - 2 \mod 2047 = 471 $.
   -$$s_6 = 471^2 - 2 \mod 2047 = 0 $.

3. **Conclusion**:
   -$$s*{10} \equiv 0 \mod 2047 $, so$$M*{11}$$is prime.

### Lucas–Lehmer Test for Mersenne Numbers

The Lucas–Lehmer test is particularly efficient for testing the primality of Mersenne numbers because of the specific properties of these numbers and the simplicity of the test compared to general primality tests.

### Relation to Mersenne Primes

- **Mersenne Prime**: A Mersenne number$$M_p = 2^p - 1$$that is prime.
- **Lucas–Lehmer Test**: Specifically designed to efficiently determine the primality of Mersenne numbers using iterative calculations.
