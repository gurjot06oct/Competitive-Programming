# Binary Exponentiation

Binary exponentiation (also known as exponentiation by squaring) is a technique to compute $a^n$ using only $O(\log n)$ multiplications, rather than the $O(n)$ multiplications required by the naive approach.

This method can be used with any associative operation, such as modular multiplication and matrix multiplication.

## Algorithm

Raising $a$ to the power of $n$ naively involves multiplying $a$ by itself $n-1$ times:
$ a^n = a \cdot a \cdot \ldots \cdot a $

However, this is impractical for large $a$ or $n$. Binary exponentiation leverages the properties:
$ a^{b+c} = a^b \cdot a^c $
$ a^{2b} = (a^b)^2 $

The key idea is to use the binary representation of the exponent. For example:
$ 3^{13} = 3^{1101_2} = 3^8 \cdot 3^4 \cdot 3^1 $

Since $n$ has $\lfloor \log_2 n \rfloor + 1$ digits in binary, only $O(\log n)$ multiplications are needed, given the powers $a^1, a^2, a^4, a^8, \ldots, a^{2^{\lfloor \log n \rfloor}}$.

To compute these powers efficiently, note that each power is the square of the previous one:

$
\begin{aligned}
3^1 &= 3 \\
3^2 &= (3^1)^2 = 3^2 = 9 \\
3^4 &= (3^2)^2 = 9^2 = 81 \\
3^8 &= (3^4)^2 = 81^2 = 6561
\end{aligned}
$

Thus, to compute $3^{13}$, we multiply the relevant powers (skipping $3^2$ since the corresponding bit is not set):
$ 3^{13} = 6561 \cdot 81 \cdot 3 = 1594323 $

The algorithm's complexity is $O(\log n)$, requiring $\log n$ computations of powers and at most $\log n$ multiplications.

## Recursive Approach

The recursive formula is:

$
a^n =
\begin{cases}
1 & \text{if } n = 0 \\
(a^{\frac{n}{2}})^2 & \text{if } n > 0 \text{ and } n \text{ is even} \\
(a^{\frac{n-1}{2}})^2 \cdot a & \text{if } n > 0 \text{ and } n \text{ is odd}
\end{cases}
$

### Pseudocode for Recursive Approach

```
function binpow(a, n):
    if n == 0:
        return 1
    res = binpow(a, n // 2)
    if n % 2 == 0:
        return res * res
    else:
        return res * res * a
```

## Iterative Approach

This approach avoids recursion by using a loop, which can be more efficient in practice.

### Pseudocode for Iterative Approach

```
function binpow(a, n):
    result = 1
    while n > 0:
        if n is odd:
            result = result * a
        a = a * a
        n = n // 2
    return result
```

By using either of these methods, you can efficiently compute large powers with a logarithmic number of multiplications.

# Applications

## Effective Computation of Large Exponents Modulo a Number

### Problem

Compute $ x^n \bmod m $. This is a common operation used in tasks like computing the modular multiplicative inverse.

### Solution

Since the modulo operator doesn't interfere with multiplications ($ a \cdot b \equiv (a \bmod m) \cdot (b \bmod m) \pmod{m} $), we can use the same binary exponentiation algorithm, replacing each multiplication with a modular multiplication.

### Pseudocode

```
function binpow(a, b, m):
    a = a % m
    result = 1
    while b > 0:
        if b is odd:
            result = (result * a) % m
        a = (a * a) % m
        b = b // 2
    return result
```

### Note

For large $ b \gg m $, if $ m $ is a prime number, $ x^n \equiv x^{n \bmod (m-1)} \pmod{m} $. For composite $ m $, $ x^n \equiv x^{n \bmod \phi(m)} \pmod{m} $. This follows from Fermat's little theorem and Euler's theorem.

## Effective Computation of Fibonacci Numbers

### Problem

Compute the $ n $-th Fibonacci number $ F_n $.

### Solution

To compute the $ n $-th Fibonacci number efficiently, we use a $ 2 \times 2 $ matrix that describes the transformation from $ F*i $ and $ F*{i+1} $ to $ F*{i+1} $ and $ F*{i+2} $. By raising this matrix to the $ n $-th power, we can find $ F_n $ in $ O(\log n) $ time.

### Overview

1. Define the transformation matrix:
   $
   \begin{pmatrix}
   1 & 1 \\
   1 & 0
   \end{pmatrix}
   $
2. Raise this matrix to the $ n $-th power using binary exponentiation.
3. Extract $ F_n $ from the resulting matrix.

## Applying a Permutation $ k $ Times

### Problem

Given a sequence of length $ n $, apply a given permutation $ k $ times.

### Solution

Raise the permutation to the $ k $-th power using binary exponentiation, and then apply it to the sequence. This results in a time complexity of $ O(n \log k) $.

### Pseudocode

```
function applyPermutation(sequence, permutation):
    newSequence = empty list of the same size as sequence
    for i from 0 to size of sequence - 1:
        newSequence[i] = sequence[permutation[i]]
    return newSequence

function permute(sequence, permutation, k):
    while k > 0:
        if k is odd:
            sequence = applyPermutation(sequence, permutation)
        permutation = applyPermutation(permutation, permutation)
        k = k // 2
    return sequence
```

### Note

This task can be solved more efficiently in linear time by building the permutation graph and considering each cycle independently. Compute $ k $ modulo the size of the cycle to find the final position for each number in the cycle.

## Fast Application of a Set of Geometric Operations to a Set of Points

### Problem

Given $ n $ points $ p_i $, apply $ m $ transformations to each of these points. Transformations can include shift, scaling, rotation, or a "loop" operation which applies a list of transformations $ k $ times. Apply all transformations faster than $ O(n \cdot \text{length}) $, where length is the total number of transformations after unrolling "loop" operations.

### Solution

Each transformation can be represented as a linear operation on the coordinates, expressed as a $ 4 \times 4 $ matrix. The transformation matrix for different operations are:

- **Shift Operation**: Shifts coordinates by constants.

  $
  \begin{pmatrix}
  1 & 0 & 0 & 0 \\
  0 & 1 & 0 & 0 \\
  0 & 0 & 1 & 0 \\
  c_x & c_y & c_z & 1
  \end{pmatrix}
  $

- **Scaling Operation**: Scales coordinates by constants.
  $
  \begin{pmatrix}
  s_x & 0 & 0 & 0 \\
  0 & s_y & 0 & 0 \\
  0 & 0 & s_z & 0 \\
  0 & 0 & 0 & 1
  \end{pmatrix}
  $
- **Rotation Operation**: Rotates around the $ x $-axis by $ \theta $.
  $
  \begin{pmatrix}
  1 & 0 & 0 & 0 \\
  0 & \cos \theta & -\sin \theta & 0 \\
  0 & \sin \theta & \cos \theta & 0 \\
  0 & 0 & 0 & 1
  \end{pmatrix}
  $

### Steps

1. Represent each transformation as a $ 4 \times 4 $ matrix.
2. Combine the sequence of transformations into a single matrix product.
3. For a "loop" operation applying $ k $ times, use matrix exponentiation by squaring.
4. Apply the combined transformation matrix to each point.

### Pseudocode

```
function matrixMultiplication(A, B):
    C = 4x4 zero matrix
    for i from 0 to 3:
        for j from 0 to 3:
            for k from 0 to 3:
                C[i][j] += A[i][k] * B[k][j]
    return C

function matrixExponentiation(M, k):
    result = 4x4 identity matrix
    while k > 0:
        if k is odd:
            result = matrixMultiplication(result, M)
        M = matrixMultiplication(M, M)
        k = k // 2
    return result

function applyTransformations(points, transformations, k):
    combinedMatrix = 4x4 identity matrix
    for transformation in transformations:
        combinedMatrix = matrixMultiplication(combinedMatrix, transformation)

    if k > 1:
        combinedMatrix = matrixExponentiation(combinedMatrix, k)

    newPoints = []
    for point in points:
        newPoint = multiplyPointByMatrix(point, combinedMatrix)
        newPoints.append(newPoint)

    return newPoints

function multiplyPointByMatrix(point, matrix):
    x, y, z = point
    newPoint = [0, 0, 0, 1]
    for i from 0 to 3:
        newPoint[i] = matrix[0][i] * x + matrix[1][i] * y + matrix[2][i] * z + matrix[3][i]
    return newPoint[0:3]
```

## Number of Paths of Length $ k $ in a Graph

### Problem

Given a directed unweighted graph with $ n $ vertices, find the number of paths of length $ k $ from any vertex $ u $ to any other vertex $ v $.

### Solution

Raise the adjacency matrix $ M $ of the graph to the $ k $-th power. The resulting matrix $ M^k $ will have $ m\_{ij} $ representing the number of paths of length $ k $ from vertex $ i $ to vertex $ j $.

### Pseudocode

```
function matrixMultiplication(A, B, n):
    C = nxn zero matrix
    for i from 0 to n-1:
        for j from 0 to n-1:
            for k from 0 to n-1:
                C[i][j] += A[i][k] * B[k][j]
    return C

function matrixExponentiation(M, k, n):
    result = nxn identity matrix
    while k > 0:
        if k is odd:
            result = matrixMultiplication(result, M, n)
        M = matrixMultiplication(M, M, n)
        k = k // 2
    return result

function numberOfPaths(graph, k):
    n = size of graph
    adjMatrix = convertGraphToAdjMatrix(graph, n)
    pathsMatrix = matrixExponentiation(adjMatrix, k, n)
    return pathsMatrix
```

## Variation of Binary Exponentiation: Multiplying Two Numbers Modulo $ m $

### Problem

Multiply two numbers $ a $ and $ b $ modulo $ m $ without using bignum arithmetic.

### Solution

Apply the binary construction algorithm with additions instead of multiplications.

### Pseudocode

```
function multiplyModulo(a, b, m):
    result = 0
    a = a % m
    while b > 0:
        if b is odd:
            result = (result + a) % m
        a = (a * 2) % m
        b = b // 2
    return result
```

### Note

Another approach involves using floating-point operations to compute $ \frac{a \cdot b}{m} $, converting to an integer $ q $, and using $ a \cdot b - q \cdot m $. This method is fast but may be less reliable.
