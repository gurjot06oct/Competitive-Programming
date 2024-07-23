# Montgomery Reduction & Montgomery Multiplication

Montgomery multiplication and Montgomery reduction are fundamental techniques in modular arithmetic, particularly crucial for optimizing computations involving large numbers in cryptographic algorithms such as RSA. Here’s a clear explanation focusing on their key aspects:

## Montgomery Multiplication

Montgomery multiplication aims to accelerate modular multiplications $ x \cdot y \mod n $ by transforming them into simpler operations within the Montgomery space. Here’s how it operates:

### Montgomery Representation

1. **Selection of $ r $**:

   - Choose a positive integer $ r \geq n $ that is coprime to $ n $. Typically, $ r $ is a power of 2 (i.e., $ r = 2^m $) for efficient implementation using shifts and masks.
   - Compute $ \bar{x} = x \cdot r \mod n $ and $ \bar{y} = y \cdot r \mod n $. These are the Montgomery representations of $ x $ and $ y $.

2. **Multiplication in Montgomery Space**:

   - $\bar{x} \cdot \bar{y} = \overline{x \cdot y} = (x \cdot y) \cdot r \bmod n.$

   - $\bar{x} \cdot \bar{y} = (x \cdot y) \cdot r \cdot r \bmod n.$

   - $\bar{x} \cdot \bar{y} := \bar{x} \cdot \bar{y} \cdot r^{-1} \bmod n.$

## Montgomery Reduction (REDC Algorithm)

Montgomery reduction is essential for efficiently computing $ x \cdot r^{-1} \mod n $, crucial for converting results from the Montgomery space back to the standard modular form. Here’s how it’s executed:

### Pre-computation

1. **Computing $ r^{-1} $**:

   - Use the extended Euclidean algorithm to compute $ r^{-1} \mod n $, ensuring $ \gcd(r, n) = 1 $.
   - $r \cdot r^\prime + n \cdot n^\prime = 1.$
   - $ r^\prime := r^{-1} \mod n $
   - $ n^\prime := n^{-1} \mod r $

2. **Reduction Algorithm**:

   - For a given $ x $, compute $ q = (x \mod r) \cdot n' \mod r $.
   - Calculate $ a = (x - q \cdot n) / r $ and adjust $ a $ if negative by adding $ n $.
   - Return $ a $, representing $ x \cdot r^{-1} \mod n $.

## Advantages and Applications

- **Efficiency**: Montgomery multiplication simplifies modular multiplication by avoiding costly division operations.
- **Security**: Widely applied in cryptographic systems for its performance benefits and resistance to timing attacks.
- **Implementation**: Requires initial conversion of numbers into Montgomery form, but subsequent operations within this space are highly efficient.

## Efficient Inverse Calculation Trick

To compute the modular inverse $ n' := n^{-1} \bmod r $ efficiently, we can use the following trick, inspired by Newton's method:

$ a \cdot x \equiv 1 \bmod 2^k \Longrightarrow a \cdot x \cdot (2 - a \cdot x) \equiv 1 \bmod 2^{2k} $

### Proof

Assume $ a \cdot x = 1 + m \cdot 2^k $. Then we have:

$
\begin{aligned}
a \cdot x \cdot (2 - a \cdot x) &= 2 \cdot a \cdot x - (a \cdot x)^2 \\
&= 2 \cdot (1 + m \cdot 2^k) - (1 + m \cdot 2^k)^2 \\
&= 2 + 2 \cdot m \cdot 2^k - 1 - 2 \cdot m \cdot 2^k - m^2 \cdot 2^{2k} \\
&= 1 - m^2 \cdot 2^{2k} \\
&\equiv 1 \bmod 2^{2k}.
\end{aligned}
$

This result means that we can start with $ x = 1 $ as the inverse of $ a $ modulo $ 2^1 $. By applying this trick iteratively, we double the number of correct bits of $ x $ in each iteration.
