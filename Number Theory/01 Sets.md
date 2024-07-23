# Set Theory

Set theory is a foundational branch of mathematics that deals with collections of objects, known as sets. Here are the basics:

## Definition and Notation

- A **set** is a well-defined collection of distinct objects.
- Elements or members of a set are denoted by$$x \in A $, where$$x$$belongs to the set$$A $.
- Sets are typically denoted by capital letters, e.g.,$$A, B, X $.

## Ways to Define Sets

- **Listing Elements**:$$X = \{x_1, x_2, \ldots, x_n\} $
- **Using Properties**:$$X = \{x : x \text{ satisfies } P\} $

## Important Sets

-$$\mathbb{N} $: Natural numbers$$\{1, 2, 3, \ldots\} $
-$$\mathbb{Z} $: Integers$$\{\ldots, -2, -1, 0, 1, 2, \ldots\} $
-$$\mathbb{Q} $: Rational numbers$$\left\{\frac{p}{q} : p, q \in \mathbb{Z}, q \neq 0\right\} $
-$$\mathbb{R} $: Real numbers
-$$\mathbb{C} $: Complex numbers

## Subset and Equality

-$$A \subseteq B $: Set$$A$$is a subset of$$B $.
-$$A = B $: Sets$$A$$and$$B$$are equal if they contain exactly the same elements.
-$$\emptyset $: Empty set, containing no elements, is a subset of every set.

## Set Operations

- **Union**:$$A \cup B = \{x : x \in A \text{ or } x \in B\} $
- **Intersection**:$$A \cap B = \{x : x \in A \text{ and } x \in B\} $
- **Complement**:$$A^c = \{x : x \in U \text{ and } x \notin A\} $, where$$U$$is the universal set.
- **Difference**:$$A \setminus B = \{x : x \in A \text{ and } x \notin B\} $

## De Morgan's Laws

-$$(A \cup B)^c = A^c \cap B^c $
-$$(A \cap B)^c = A^c \cup B^c $

# Cartesian Products

The Cartesian product of two sets$$A$$and$$B$$is the set of all ordered pairs$$(a, b)$$where$$a \in A$$and$$b \in B $:

$$A \times B = \{(a, b) \mid a \in A, b \in B\} $

## Example

If$$A = \{x, y\}$$and$$B = \{1, 2, 3\} $:

$$A \times B = \{(x, 1), (x, 2), (x, 3), (y, 1), (y, 2), (y, 3)\} $

# Equivalence Relations

In set theory, equivalence relations formalize relationships between elements within a set. Here's an introduction:

## Definition of Equivalence Relation

An equivalence relation on a set$$S$$is a subset$$U \subseteq S \times S$$satisfying:

1. **Symmetry**:$$(x, y) \in U \Rightarrow (y, x) \in U $
2. **Reflexivity**:$$\forall x \in S, (x, x) \in U $
3. **Transitivity**:$$(x, y) \in U \text{ and } (y, z) \in U \Rightarrow (x, z) \in U $

## Equivalence Notation

If$$U$$is an equivalence relation, we write$$x \sim y$$to denote that$$x$$and$$y$$are equivalent under$$U $.

## Equivalence Class

An equivalence class is a subset formed by an equivalence relation. For any$$x \in S $, the equivalence class of$$x$$is:

$$[x] = \{ y \in S \mid y \sim x \} $

## Properties of Equivalence Classes

1. **Non-Empty and Union of Equivalence Classes**:

   - Every equivalence class$$[x]$$is non-empty because$$x \sim x $.
   - The union of all equivalence classes covers the entire set$$S $.

2. **Equality and Disjointness of Equivalence Classes**:
   - If$$y \in [x] $, then$$[y] = [x] $.
   - Any two elements$$y$$and$$z$$in$$S$$either belong to the same equivalence class or to different (disjoint) equivalence classes.

# Mappings

A mapping, or function, relates each element of one set to exactly one element of another set.

## Definition

Given sets$$A$$and$$B $, a mapping$$f$$from$$A$$to$$B$$is denoted$$f: A \to B$$and satisfies:
$$\forall a \in A, \exists! b \in B \text{ such that } (a, b) \in f $

## Notation and Terminology

-$$f(a) = b$$denotes that$$f$$maps$$a$$to$$b $.
-$$A$$is the domain of$$f $.
-$$f(A) = \{f(a) \mid a \in A\}$$is the range or image of$$f $.

## Types of Mappings

- **Injective (One-to-One)**:$$f$$is injective if$$f(a_1) = f(a_2)$$implies$$a_1 = a_2 $.
- **Surjective (Onto)**:$$f$$is surjective if for every$$b \in B $, there exists an$$a \in A$$such that$$f(a) = b $.
- **Bijective**:$$f$$is bijective if it is both injective and surjective.

## Composition of Mappings

Given mappings$$f: A \to B$$and$$g: B \to C $, their composition$$g \circ f: A \to C$$is defined by:
$$(g \circ f)(a) = g(f(a)) $

## Properties of Composition

- Composition of mappings is associative:$$(h \circ g) \circ f = h \circ (g \circ f) $.
- The identity mapping$$\text{id}\_A: A \to A$$satisfies$$\text{id}\_A(a) = a$$for all$$a \in A $.

## Inverses of Mappings

A mapping$$f: A \to B$$has an inverse$$f^{-1}: B \to A$$if:

$$f(f^{-1}(b)) = b \text{ and } f^{-1}(f(a)) = a $

A function$$f$$is invertible if and only if it is bijective.

# Partitions of a Set

A partition$$\mathcal{P}$$of a set$$X$$is a collection of non-empty subsets$$\{X*i\}*{i \in I}$$such that:

1.$$X_i \cap X_j = \emptyset$$for all$$i \neq j$$(the subsets are pairwise disjoint).
2.$$\bigcup\_{i \in I} X_i = X$$(the union of all subsets covers the entire set$$X $).

A partition divides$$X$$into non-overlapping parts, ensuring every element of$$X$$belongs to exactly one subset.

## Example

For$$X = \{1, 2, 3, 4\} $, a partition could be:

$$\mathcal{P} = \{\{1, 2\}, \{3\}, \{4\}\} $

## Equivalence Relations and Partitions

Given an equivalence relation $\sim$$on a set $X$, the equivalence classes of $X$$form a partition of $X$. Conversely, if $P = \{X_i\}$$is a partition of a set $X$, then there is an equivalence relation on $X$$with equivalence classes $X_i$.

## Disjoint or Equal Equivalence Classes

Two equivalence classes of an equivalence relation are either disjoint or equal.

## Example

Let $r$$and $s$$be two integers and $n \in \mathbb{N}$. $r$$is congruent to $s$$modulo $n$$if $r - s$$is evenly divisible by $n$, i.e., $r - s = nk$$for some $k \in \mathbb{Z}$. We write $r \equiv s \pmod{n}$. For instance, $41 \equiv 17 \pmod{8}$$since $41 - 17 = 24$$is divisible by 8. This congruence relation modulo $n$$forms an equivalence relation on $\mathbb{Z}$.

Consider the equivalence relation established by the integers modulo 3:

- $[0] = \{ \ldots, -3, 0, 3, 6, \ldots \}$
- $[1] = \{ \ldots, -2, 1, 4, 7, \ldots \}$
- $[2] = \{ \ldots, -1, 2, 5, 8, \ldots \}$

Notice that $[0] \cup [1] \cup [2] = \mathbb{Z}$$and the sets are disjoint. The sets $[0]$, $[1]$, and $[2]$$form a partition of the integers.

# Binary Operations

In mathematics, a **binary operation** on a set$$S$$is a fundamental concept that formalizes how two elements from$$S$$can be combined to produce a third element in$$S $. Formally, a binary operation$$\circ$$is defined as a function$$\circ: S \times S \to S $, where$$S \times S$$denotes the Cartesian product of$$S$$with itself, consisting of all ordered pairs$$(a, b)$$where$$a, b \in S $.

## Definition and Properties

1. **Closure:** For any elements$$a, b \in S $, the result of the operation$$a \circ b$$must also belong to$$S $. Mathematically,$$a \circ b \in S $.

2. **Associativity:** The operation$$\circ$$is associative if$$(a \circ b) \circ c = a \circ (b \circ c)$$for all$$a, b, c \in S $. This property ensures that the order of operations does not affect the result.

3. **Identity Element:** There exists an element$$e \in S$$such that for any$$a \in S $,$$a \circ e = e \circ a = a $.$$e$$is called the identity element of the operation.

4. **Inverses:** For each$$a \in S $, there exists an element$$b \in S$$(denoted$$a^{-1} $) such that$$a \circ b = b \circ a = e $, where$$e$$is the identity element. Not all binary operations have inverses.

## Examples

Let's consider some familiar examples:

- **Addition and Multiplication:** On the set of natural numbers$$\mathbb{N} $, integers$$\mathbb{Z} $, rationals$$\mathbb{Q} $, and reals$$\mathbb{R} $, addition$$+$$and multiplication$$\cdot$$are binary operations. They satisfy closure, associativity, have identity elements (0 for addition, 1 for multiplication), and most elements have inverses (negatives for addition, reciprocals for multiplication).

- **Subtraction and Division:** On$$\mathbb{Z}, \mathbb{Q},$$and$$\mathbb{R} $, subtraction$$-$$and division$$\div$$are binary operations. However, division is not defined for all elements (division by zero is undefined).

- **Modular Arithmetic:** Consider$$\mathbb{Z}\_n = \{0, 1, 2, \ldots, n-1\}$$with addition modulo$$n$$$$(a + b \mod n)$$and multiplication modulo$$n$$$$(a \cdot b \mod n) $. These operations are binary and satisfy all the above properties within the modulus$$n $.
