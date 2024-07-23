## Matrix Exponentiation

Matrix exponentiation is a powerful technique used to solve linear recurrence relations efficiently. When you have a recurrence relation that depends on two previous values with coefficients greater than 1, you can represent the problem using matrices and perform exponentiation to find the $n$-th term in logarithmic time.

Let's take an example recurrence relation:

 $ T(n) = a \cdot T(n-1) + b \cdot T(n-2) $

Here, $a $ and $b $ are coefficients.

### Step-by-Step Explanation

1. **Define the Recurrence Relation:**

   $
   T(n) = a \cdot T(n-1) + b \cdot T(n-2)
   $

   Assume the initial conditions are $ T(0) $ and $ T(1) $.

2. **Convert the Recurrence Relation to Matrix Form:**

   We want to express the recurrence relation in terms of matrix multiplication. Define a vector $V$:

   $
   V(n) = \begin{pmatrix} T(n) \\ T(n-1) \end{pmatrix}
   $

   The recurrence relation can be rewritten as:

   $
   \begin{pmatrix} T(n) \\ T(n-1) \end{pmatrix} = \begin{pmatrix} a & b \\ 1 & 0 \end{pmatrix} \begin{pmatrix} T(n-1) \\ T(n-2) \end{pmatrix}
   $

3. **Matrix Representation:**

   Define matrix $M$:

   $
   M = \begin{pmatrix} a & b \\ 1 & 0 \end{pmatrix}
   $

   Now, the vector can be expressed as:

   $
   V(n) = M \cdot V(n-1)
   $

   To find $ V(n) $, we need to exponentiate the matrix $M$.

4. **Matrix Exponentiation:**
   To compute $ V(n) $, we raise $M $ to the power $ (n-1) $:

   $
   V(n) = M^{(n-1)} \cdot V(1)
   $

   Here, $ V(1) = \begin{pmatrix} T(1) \\ T(0) \end{pmatrix} $.

5. **Recursive Matrix Exponentiation:**
   Matrix exponentiation can be done efficiently using the divide-and-conquer method:

   - If $k $ is even: $ M^k = (M^{k/2}) \cdot (M^{k/2}) $
   - If $k $ is odd: $ M^k = M \cdot M^{k-1} $

### Example Calculation

Let's say we have a recurrence relation:

 $ T(n) = 2T(n-1) + 3T(n-2) $

with initial conditions $ T(0) = 1 $ and $ T(1) = 2 $.

The matrix $ M $ would be:

$
M = \begin{pmatrix} 2 & 3 \\ 1 & 0 \end{pmatrix}
$

To find $ T(n) $, we compute $ M^{(n-1)} $ and multiply it by $ V(1) $:

$
V(1) = \begin{pmatrix} 2 \\ 1 \end{pmatrix}
$

**Recursive function to perform matrix exponentiation:**

```python
def matrix_multiply(A, B):
    return [
        [A[0][0] * B[0][0] + A[0][1] * B[1][0], A[0][0] * B[0][1] + A[0][1] * B[1][1]],
        [A[1][0] * B[0][0] + A[1][1] * B[1][0], A[1][0] * B[0][1] + A[1][1] * B[1][1]]
    ]

def matrix_exponentiation(M, power):
    if power == 1:
        return M
    if power % 2 == 0:
        half_power = matrix_exponentiation(M, power // 2)
        return matrix_multiply(half_power, half_power)
    else:
        return matrix_multiply(M, matrix_exponentiation(M, power - 1))

def compute_T_n(a, b, T0, T1, n):
    M = [[a, b], [1, 0]]
    if n == 0:
        return T0
    if n == 1:
        return T1
    M_exp = matrix_exponentiation(M, n-1)
    V1 = [T1, T0]
    T_n = M_exp[0][0] * V1[0] + M_exp[0][1] * V1[1]
    return T_n

# Example usage
a = 2
b = 3
T0 = 1
T1 = 2
n = 5
print(compute_T_n(a, b, T0, T1, n))  # Output for T(5)
```

In this example, the `compute_T_n` function will compute the 5th term of the recurrence relation using matrix exponentiation, providing an efficient solution.
