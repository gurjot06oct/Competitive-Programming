# Solutions of Linear Diophantine Equations

## **Using the Extended Euclidean Algorithm**

The extended Euclidean algorithm not only finds the gcd of two integers but also expresses this gcd as a linear combination of the integers. This is crucial in finding particular solutions to the linear Diophantine equation.

**Steps:**

1. **Apply the Euclidean Algorithm** to find $ \text{gcd}(a, b) $.

   - Divide $ a $ by $ b $: $ a = bq_1 + r_1 $.

   - Continue the process with $ b $ and $ r_1 $: $ b = r_1q_2 + r_2 $, etc., until the remainder is 0.

   - The last non-zero remainder is $ \text{gcd}(a, b) $.

2. **Back-substitute** to express $ \text{gcd}(a, b) $ as a combination of $ a $ and $ b $.

**Example:**
Find integers $ x $ and $ y $ that satisfy $ 240x + 46y = 2 $.

1. Apply the Euclidean Algorithm to $ 240 $ and $ 46 $:

   $
   \begin{aligned}
   240 &= 46 \cdot 5 + 10, \\
   46 &= 10 \cdot 4 + 6, \\
   10 &= 6 \cdot 1 + 4, \\
   6 &= 4 \cdot 1 + 2, \\
   4 &= 2 \cdot 2 + 0.
   \end{aligned}
   $

   So, $ \text{gcd}(240, 46) = 2 $.

2. Back-substitute to express $ 2 $ as a linear combination of $ 240 $ and $ 46 $:

   $
   \begin{aligned}
   2 &= 6 - 4 \cdot 1 \\
   &= 6 - (10 - 6 \cdot 1) \cdot 1 \\
   &= 6 \cdot 2 - 10 \\
   &= (46 - 10 \cdot 4) \cdot 2 - 10 \\
   &= 46 \cdot 2 - 10 \cdot 9 \\
   &= 46 \cdot 2 - (240 - 46 \cdot 5) \cdot 9 \\
   &= 46 \cdot 47 - 240 \cdot 9
   \end{aligned}
   $

   Thus, one particular solution is $ x_0 = -9 $ and $ y_0 = 47 $.

## **General Solution**

Once a particular solution $(x_0, y_0) $ is found, the general solution to the linear Diophantine equation $ ax + by = c $ can be expressed as:

$
x = x_0 + \frac{b}{d}t, \quad y = y_0 - \frac{a}{d}t,
$

where $ t $ is an integer parameter and $ d = \text{gcd}(a, b) $.

**Example (continued):**
Given $ 240x + 46y = 2 $ with particular solution $ x_0 = -9 $ and $ y_0 = 47 $, and $ d = 2 $:

$
x = -9 + \frac{46}{2}t = -9 + 23t,
$

$
y = 47 - \frac{240}{2}t = 47 - 120t,
$

where $ t $ is any integer.

# Solving Multiple Linear Diophantine Equations

Sometimes, more than one linear Diophantine equation must be solved simultaneously. Consider the system:

$
\begin{cases}
a_1x + b_1y = c_1 \\
a_2x + b_2y = c_2
\end{cases}
$

Such a system can be solved by various methods, such as:

1. **Elimination Method:** Combine the equations to eliminate one variable.
2. **Matrix Methods:** Represent the system in matrix form and use matrix operations to find solutions.
3. **Substitution:** Solve one equation for one variable and substitute into the other.

**Example:**
Solve the system:

$
\begin{cases}
3x + 2y = 5 \\
4x + 3y = 7
\end{cases}
$

1. Eliminate $ y $:

   $
   \begin{aligned}
   3x + 2y &= 5 \quad (1) \\
   4x + 3y &= 7 \quad (2)
   \end{aligned}
   $

   Multiply (1) by 3 and (2) by 2:

   $
   \begin{aligned}
   9x + 6y &= 15 \quad (3) \\
   8x + 6y &= 14 \quad (4)
   \end{aligned}
   $

2. Subtract (4) from (3):

   $
   (9x + 6y) - (8x + 6y) = 15 - 14,
   $

   $
   x = 1.
   $

3. Substitute $ x = 1 $ into (1):

   $
   3(1) + 2y = 5,
   $

   $
   2y = 2,
   $

   $
   y = 1.
   $

Thus, the solution is $ x = 1 $, $ y = 1 $.

# Excercise Questions

## Question 1: Basic Existence and Solution

1. **(10 points)** Determine whether the following linear Diophantine equation has integer solutions. If so, find one particular solution.

   $
   15x + 25y = 35
   $

2. **(10 points)** Find the general solution to the equation in Question 1 if a solution exists.

## Question 2: Application of the Extended Euclidean Algorithm

1. **(15 points)** Use the extended Euclidean algorithm to find the gcd of 252 and 198. Express the gcd as a linear combination of 252 and 198.

2. **(10 points)** Using your result from part 1, find a particular solution to the linear Diophantine equation:

   $
   252x + 198y = 18
   $

3. **(10 points)** Write the general solution to the equation $252x + 198y = 18$.

## Question 3: Multiple Equations

1. **(20 points)** Solve the system of linear Diophantine equations:

   $
   \begin{cases}
   7x + 5y = 3 \\
   3x + 2y = 1
   \end{cases}
   $

## Question 4: Application Problem

1. **(20 points)** A factory produces two types of widgets, A and B. Widget A requires 3 hours of labor and 4 units of material. Widget B requires 5 hours of labor and 2 units of material. The factory has a total of 60 hours of labor and 40 units of material available. How many of each type of widget should the factory produce to use exactly all available labor and materials?

   Formulate this situation as a system of linear Diophantine equations and solve it.

## Question 5: Proof and Theory

1. **(15 points)** Prove that the linear Diophantine equation $ ax + by = c $ has infinitely many solutions if it has at least one solution.

2. **(15 points)** Given that $ \text{gcd}(a, b) = 1 $, prove that the linear Diophantine equation $ ax + by = 1 $ always has integer solutions.

## Question 6: Higher Dimensions (Optional/Challenging)

1. **(25 points)** Consider the linear Diophantine equation in three variables:

   $
   ax + by + cz = d
   $

   Derive the condition under which this equation has integer solutions. Discuss the method to find particular solutions and express the general solution.

## Answers to Selected Questions

### Question 1

1. **Solution:**
   The gcd of 15 and 25 is 5, which divides 35, so the equation has solutions. Using the extended Euclidean algorithm:

   $
   \text{gcd}(15, 25) = 5
   $

   Thus, the equation can be simplified:

   $
   15x + 25y = 35 \implies 3x + 5y = 7.
   $

2. **Particular Solution:**
   Find integers $ x $ and $ y $ such that $ 3x + 5y = 7 $. Using the extended Euclidean algorithm:

   $
   7 = 2 \times 3 + 1 \implies 1 = 7 - 2 \times 3 \implies 1 = 7 - 2(15x + 25y) \implies 1 = 3x + 5y.
   $

   We can find particular solutions by back-substitution, eventually yielding $ x = 1 $ and $ y = 1 $. Thus:

   $
   x = 1 + 5t, \quad y = 1 - 3t \quad \text{(general solution)}.
   $

### Question 3

1. **Solution:**

   - Multiply the first equation by 2 and the second by 5:

     $
     \begin{aligned}
     14x + 10y &= 6, \\
     15x + 10y &= 5.
     \end{aligned}
     $

   - Subtract the second from the first:

     $
     -x = 1 \implies x = -1.
     $

   - Substitute $ x = -1 $ into one of the original equations:

     $
     3(-1) + 2y = 1 \implies -3 + 2y = 1 \implies 2y = 4 \implies y = 2.
     $

   Thus, $ x = -1 $, $ y = 2 $.

### Question 5

1. **Proof:**
   Suppose $(x_0, y_0) $ is a particular solution to $ ax + by = c $. The general solution is $ x = x_0 + \frac{b}{d}t $ and $ y = y_0 - \frac{a}{d}t $, where $ t $ is an integer. Since $ t $ can be any integer, there are infinitely many solutions.

2. **Proof:**
   Given $ \text{gcd}(a, b) = 1 $, there exist integers $ x $ and $ y $ such that $ ax + by = 1 $ by Bezout's identity.
