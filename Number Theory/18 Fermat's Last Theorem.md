# Fermat's Last Theorem (FLT)

Fermat's Last Theorem states that there are no three positive integers $ a, b, $ and $ c $ that satisfy the equation $ a^n + b^n = c^n $ for any integer value of $ n $ greater than 2. In other words, there are no solutions in positive integers $ a, b, c $ for the equation $ a^n + b^n = c^n $ when $ n > 2 $.

**Key Concepts in the Proof**

- **Elliptic Curves:** These are algebraic curves described by cubic equations that played a central role in Wiles' approach.
- **Modular Forms:** These are functions that have deep connections with number theory and were crucial in establishing links between elliptic curves and other areas of mathematics.
- **Galois Representations:** These representations provide a way to study symmetries of algebraic equations and were used to connect the properties of elliptic curves to Fermat's Last Theorem.

## Equivalent Statements of Fermat's Last Theorem

Fermat's Last Theorem, initially formulated by Pierre de Fermat in the 17th century, posits that the equation $ x^n + y^n = z^n $ has no solutions in positive integers $ x, y, z $ when $ n > 2 $. Over the centuries, several equivalent formulations of this theorem have been established, shedding light on its deep connections within number theory and algebraic geometry.

### Original Statement

**Original Formulation:** For $ n, x, y, z \in \mathbb{N} $ (where $ \mathbb{N} $ denotes the set of natural numbers) and $ n > 2 $, the equation $ x^n + y^n = z^n $ has no solutions.

### Equivalent Statements

1. **Over Integers (Z):**

   - **Statement 1:** The equation $ x^n + y^n = z^n $, where $ n \geq 3 $, has no non-trivial solutions $ x, y, z \in \mathbb{Z} $ (integers).
   - **Reasoning:** This equivalence holds straightforwardly when $ n $ is even. If $ n $ is odd and all three $ x, y, z $ are negative, changing them to $ -x, -y, -z $ provides a solution in $ \mathbb{N} $. Similar adjustments for mixed signs ensure any non-trivial integer solution implies a solution in $ \mathbb{N} $.

2. **Over Rational Numbers (Q):**

   - **Statement 2:** The equation $ x^n + y^n = z^n $, where $ n \geq 3 $, has no non-trivial solutions $ x, y, z \in \mathbb{Q} $ (rational numbers).
   - **Reasoning:** Because $ x, y, z $ must be rational with equal exponents $ n $, any solution in $ \mathbb{Q} $ can be scaled to $ \mathbb{Z} $, hence to $ \mathbb{N} $.

3. **Transformed to a Unit Equation:**

   - **Statement 3:** The equation $ x^n + y^n = 1 $, where $ n \geq 3 $, has no non-trivial solutions $ x, y \in \mathbb{Q} $.
   - **Reasoning:** A solution $ a, b, c \in \mathbb{Z} $ to $ x^n + y^n = z^n $ translates to $ a/c, b/c \in \mathbb{Q} $ for $ v^n + w^n = 1 $, and vice versa.

   This formulation reduces the problem dimensionally and allows for analysis over $ \mathbb{Q} $, where the structure is more amenable to rigorous study.

4. **Connection to Elliptic Curves:**
   - **Statement 4:** If $ a, b, c $ is a non-trivial solution to $ a^p + b^p = c^p $ for an odd prime $ p $, then $ y^2 = x(x - a^p)(x + b^p) $ (Frey curve) forms an elliptic curve without a modular form.
   - **Implication:** Andrew Wiles' proof demonstrates that such equations do not have modular forms. The existence of such a curve contradicts the Modularity Theorem, and hence, the non-existence of non-trivial solutions to $ x^n + y^n = z^n $.

## Important Conjectures

### 1. Mordell Conjecture

**Statement:** The Mordell Conjecture, proposed by Louis Mordell in 1922, is a conjecture in number theory concerning the rational points on elliptic curves.

**Details:**

- **Elliptic Curves:** An elliptic curve is a specific type of cubic equation in two variables with a distinguished point at infinity, used extensively in number theory.
- **Conjecture:** The conjecture states that if $ E $ is an elliptic curve defined over the rational numbers $ \mathbb{Q} $, then the group of rational points $ E(\mathbb{Q}) $ is finitely generated.
- **Ramification:** This implies that for any elliptic curve, there are only finitely many rational points, which is non-trivial due to the curve's infinite geometric nature.

**Resolution:** The conjecture was proved by Gerd Faltings in 1983, who showed that $ E(\mathbb{Q}) $ is indeed a finitely generated abelian group, affirming Mordell's conjecture.

### 2. Euler's Sum of Powers Conjecture

**Statement:** Euler's Sum of Powers Conjecture, attributed to Leonhard Euler, proposes a relation between the sum of powers of $ n $ th powers and higher powers.

**Details:**

- **Conjecture:** Euler conjectured that for $ n > 1 $, there are no positive integer solutions $ a, b, c, $ and $ d $ such that $ a^n + b^n = c^n + d^n $.
- **Fermat-like:** This is reminiscent of Fermat's Last Theorem but extends to sums of more than two terms and potentially higher powers.
- **Status:** As of now, the conjecture remains unresolved, and it is an open problem in number theory.

### 3. abc Conjecture

**Statement:** The abc Conjecture, formulated by Joseph Oesterlé and David Masser in 1985, relates to the prime factors of three integers $ a, b, $ and $ c $.

**Details:**

- **Conjecture:** For three coprime integers $ a, b, $ and $ c $ such that $ a + b = c $, the product of the distinct prime factors of $ abc $ is usually large, provided $ c $ is not much larger than $ \text{rad}(abc) $, where $ \text{rad}(n) $ denotes the product of distinct prime factors of $ n $.
- **Implications:** The conjecture has profound implications in Diophantine equations and connects with other areas such as elliptic curves and the distribution of prime numbers.
- **Status:** The abc Conjecture is still open, with significant progress made in recent years but no definitive proof yet established.

### 4. Catalan's Conjecture

**Statement:** Catalan's Conjecture, posed by Eugène Charles Catalan in 1844, concerns the solutions to exponential Diophantine equations.

**Details:**

- **Conjecture:** Catalan conjectured that the only solution in consecutive powers for the equation $ x^a - y^b = 1 $, where $ a, b > 1 $, $ x > 0 $, $ y > 0 $, and $ a, b $ are integers, is $ 3^2 - 2^3 = 1 $.
- **Resolution:** In 2002, Preda Mihăilescu provided a proof for Catalan's Conjecture, showing that $ x^a - y^b = 1 $ has exactly one solution in positive integers for $ a, b > 1 $.

### 5. Pillai's Conjecture

**Statement:** Pillai's Conjecture, named after the Indian mathematician Subbayya Sivasankaranarayana Pillai, concerns the solutions to the equation involving powers of integers.

**Details:**

- **Conjecture:** Pillai conjectured that for any positive integers $ m $ and $ n $, the equation $ |a^m - b^n| = 1 $ has only finitely many solutions in positive integers $ a $ and $ b $.
- **Status:** The conjecture is still open, and while partial results and specific cases have been proven, a general proof remains elusive.
