# Formulas for Primes

## Formulas Based on Wilson's Theorem

### A Simple Formula

$ f(n) = \left\lfloor \frac{n! \mod (n + 1)}{n} \right\rfloor (n - 1) + 2 $

For positive integer $ n $, where $\lfloor \cdot \rfloor$ is the floor function, which rounds down to the nearest integer. By Wilson's theorem, $ n + 1 $ is prime if and only if $ n! \equiv -1 \ (\text{mod} \ (n + 1)) $. Thus, when $ n + 1 $ is prime, the first factor in the product becomes one, and the formula produces the prime number $ n + 1 $. But when $ n + 1 $ is not prime, the first factor becomes zero and the formula produces the prime number 2. This formula is not an efficient way to generate prime numbers because evaluating $ n! \mod (n + 1) $ requires about $ n - 1 $ multiplications and reductions modulo $ n + 1 $.

### Willans' Formula (1964)

$ p*n = 1 + \left( \sum*{i=1}^{2^n} \left\lfloor \left( \sum\_{j=1}^i \left( \cos \left( \frac{(j-1)!+1}{j} \pi \right) \right)^2 \right) \frac{n}{i} \right\rfloor \right)^{1/n} $

for the $ n $ th prime number $ p_n $. This formula reduces to

$ p*n = 1 + \sum*{i=1}^{2^n} [\pi(i) < n] $

that is, it tautologically defines $ p_n $ as the smallest integer $ m $ for which the prime-counting function $ \pi(m) $ is at least $ n $. This formula is also not efficient. In addition to the appearance of $(j - 1)!$, it computes $ p_n $ by adding up $ p_n $ copies of 1; for example,

$ p_5 = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 0 + 0 + \cdots + 0 = 11 $

The articles _What is an Answer?_ by Herbert Wilf (1982) and _Formulas for Primes_ by Underwood Dudley (1983) have further discussion about the worthlessness of such formulas.

## Formula Based on a System of Diophantine Equations

Because the set of primes is a computably enumerable set, by Matiyasevich's theorem, it can be obtained from a system of Diophantine equations. Jones et al. (1976) found an explicit set of 14 Diophantine equations in 26 variables, such that a given number $ k + 2 $ is prime if and only if that system has a solution in nonnegative integers:

$ \alpha_0 = wz + h + j - q = 0 $

$ \alpha_1 = (gk + 2g + k + 1)(h + j) + h - z = 0 $

$ \alpha_2 = 16(k + 1)^3(k + 2)(n + 1)^2 + 1 - f^2 = 0 $

$ \alpha_3 = 2n + p + q + z - e = 0 $

$ \alpha_4 = e^3(e + 2)(a + 1)^2 + 1 - o^2 = 0 $

$ \alpha_5 = (a^2 - 1)y^2 + 1 - x^2 = 0 $

$ \alpha_6 = 16r^3y^4(a^2 - 1) + 1 - u^2 = 0 $

$ \alpha_7 = n + \ell + v - y = 0 $

$ \alpha_8 = (a^2 - 1)z^2 + 1 - m^2 = 0 $

$ \alpha_9 = ai + k + 1 - \ell - i = 0 $

$ \alpha\_{10} = \left( (a + u^2(u^2 - a))^2 - 1 \right)(n + 4dy)^2 + 1 - (x + cu)^2 = 0 $

$ \alpha\_{11} = p + \ell(a - n - 1) + b(2an + 2a - n^2 - 2n - 2) - m = 0 $

$ \alpha\_{12} = q + y(a - p - 1) + s(2ap + 2a - p^2 - 2p - 2) - x = 0 $

$ \alpha\_{13} = z + p\ell(a - p) + t(2ap - p^2 - 1) - pm = 0 $

The 14 equations $\alpha_0, \ldots, \alpha_{13}$ can be used to produce a prime-generating polynomial inequality in 26 variables:

$ (k + 2)(1 - \alpha*0^2 - \alpha_1^2 - \cdots - \alpha*{13}^2) > 0. $

is a polynomial inequality in 26 variables, and the set of prime numbers is identical to the set of positive values taken on by the left-hand side as the variables $a, b, \ldots, z$ range over the nonnegative integers.

A general theorem of Matiyasevich says that if a set is defined by a system of Diophantine equations, it can also be defined by a system of Diophantine equations in only 9 variables. Hence, there is a prime-generating polynomial as above with only 10 variables. However, its degree is large (in the order of $10^{45}$). On the other hand, there also exists such a set of equations of degree only 4, but in 58 variables.

## Mills' Formula

The first such formula known was established by W. H. Mills (1947), who proved that there exists a real number $ A $ such that, if

$ d_n = \left\lfloor A^{3^n} \right\rfloor $

then

$ d_n = \left\lfloor A^{3^n} \right\rfloor $

is a prime number for all positive integers $ n $. If the Riemann hypothesis is true, then the smallest such $ A $ has a value of around 1.3063778838630806904686144926... (sequence A051021 in the OEIS) and is known as Mills' constant. This value gives rise to the primes

$ \left\lfloor A^3 \right\rfloor = 2, \left\lfloor A^{27} \right\rfloor = 61, \left\lfloor A^{729} \right\rfloor = 1361, \ldots $

(sequence A051254 in the OEIS). Very little is known about the constant $ A $ (not even whether it is rational). This formula has no practical value because there is no known way of calculating the constant without finding primes in the first place.

Note that there is nothing special about the floor function in the formula. Tóth proved that there also exists a constant $ B $ such that

$ \left\lfloor B^{n^r} \right\rfloor $

is also prime-representing for $ r > 2.106 $.

In the case $ r = 3 $, the value of the constant $ B $ begins with 1.24055470525201424067... The first few primes generated are:

$
2, 7, 337, 38272739, 56062005704198360319209, \\
1761199995814327287356671209104585864397055039072110696028654438846269, \ldots
$

Without assuming the Riemann hypothesis, Elsholtz developed several prime-representing functions similar to those of Mills. For example, if $ A = 1.00536773279817424017 \ldots $, then

$ \left\lfloor A^{10^{10n}} \right\rfloor $

is prime for all positive integers $ n $. Similarly, if

$ A = 3.824999807343914617161551375 \ldots $,

then

$ \left\lfloor A^{3^{13n}} \right\rfloor $

is prime for all positive integers $ n $.

## Wright's Formula

Another tetrationally growing prime-generating formula similar to Mills' comes from a theorem of E. M. Wright. He proved that there exists a real number $ \alpha $ such that, if

$ g*0 = \alpha $
$ g*{n+1} = 2^{2^{gn}} \text{ for } n \ge 0, $

then

$ \left\lfloor g_n \right\rfloor = \left\lfloor 2^{2^{2^{...2^\alpha}}} \right\rfloor $

is prime for all $ n \ge 1 $. Wright gives the first seven decimal places of such a constant: $ \alpha = 1.9287800 $. This value gives rise to the primes

$ \left\lfloor 2^\alpha \right\rfloor = 3, \left\lfloor 2^{2^\alpha} \right\rfloor = 13, \left\lfloor 2^{2^{2^\alpha}} \right\rfloor = 16381. $

$ \left\lfloor 2^{2^{2^{2^\alpha}}} \right\rfloor $ is even, and so is not prime. However, with $ \alpha = 1.9287800 + 8.2843 \times 10^{-4933}, \left\lfloor 2^\alpha \right\rfloor, \left\lfloor 2^{2^\alpha} \right\rfloor, \left\lfloor 2^{2^{2^\alpha}} \right\rfloor $ are unchanged, while $\left\lfloor 2^{2^{2^{2^\alpha}}} \right\rfloor $ is a prime with 4932 digits. This sequence of primes cannot be extended beyond $\left\lfloor 2^{2^{2^{2^\alpha}}} \right\rfloor $ without knowing more digits of $ \alpha $. Like Mills' formula, and for the same reasons, Wright's formula cannot be used to find primes.

## A Function that Represents All Primes

Given the constant $ f_1 = 2.920050977316 \ldots $ (sequence A249270 in the OEIS), for $ n \ge 2 $, define the sequence

$ f*n = \left\lfloor f*{n-1} \right\rfloor \left( f*{n-1} - \left\lfloor f*{n-1} \right\rfloor + 1 \right) $

where $\left\lfloor \cdot \right\rfloor$ is the floor function. Then for $ n \ge 1, f_n $ equals the $ n $-th prime:

$ \left\lfloor f_1 \right\rfloor = 2, \left\lfloor f_2 \right\rfloor = 3, \left\lfloor f_3 \right\rfloor = 5, \ldots $

The initial constant $ f_1 = 2.920050977316 $ given in the article is precise enough for equation (1) to generate the primes through 37, the 12th prime.

The exact value of $ f_1 $ that generates all primes is given by the rapidly-converging series

$ f*1 = \sum*{n=1}^\infty \frac{p_n - 1}{P_n} = 2 + \frac{1}{1} + \frac{3 - 1}{2 \cdot 3} + \frac{5 - 1}{2 \cdot 3 \cdot 5} + \frac{7 - 1}{2 \cdot 3 \cdot 5 \cdot 7} + \cdots, $

where $ p_n $ is the $ n $-th prime, and $ P_n $ is the product of all primes less than $ p_n $. The more digits of $ f_1 $ that we know, the more primes equation (1) will generate. For example, we can use 25 terms in the series, using the 25 primes less than 100, to calculate the following more precise approximation:

$ f_1 \approx 2.92005097731634712092562917112019. $

This has enough digits for equation (1) to yield again the 25 primes less than 100.

As with Mills' formula and Wright's formula above, in order to generate a longer list of primes, we need to start by knowing more digits of the initial constant, $ f_1 $, which in this case requires a longer list of primes in its calculation.

## Plouffe's Formulas

In 2018, Simon Plouffe conjectured a set of formulas for primes. Similar to Mills' formula, they are of the form:

$
\{a_0^r\}
$

where $\{\}$ denotes the function rounding to the nearest integer. For example, with $a_0 \approx 43.80468771580293481$ and $r = \frac{5}{4}$, this generates:

$113, 367, 1607, 10177, 102217, \ldots$

(sequence A323176 in the OEIS). Using $a_0 = 10^{500} + 961 + \epsilon$ and $r = 1.01$ with $\epsilon$ being a certain number between 0 and one-half, Plouffe found that he could generate a sequence of 50 probable primes (with high probability of being prime). Presumably, there exists an $\epsilon$ such that this formula will give an infinite sequence of actual prime numbers. The number of digits starts at 501 and increases by about 1% each time.

## Prime Formulas and Polynomial Functions

It is known that no non-constant polynomial function $P(n)$ with integer coefficients exists that evaluates to a prime number for all integers $n$. The proof is as follows: suppose that such a polynomial existed. Then $P(1)$ would evaluate to a prime $p$, so

$P(1) \equiv 0 \pmod{p}.$

But for any integer $k$,

$P(1 + kp) \equiv 0 \pmod{p}$

also, so $P(1 + kp)$ cannot also be prime (as it would be divisible by $p$) unless it were $p$ itself. But the only way $P(1 + kp) = P(1) = p$ for all $k$ is if the polynomial function is constant. The same reasoning shows an even stronger result: no non-constant polynomial function $P(n)$ exists that evaluates to a prime number for almost all integers $n$.

Euler first noticed (in 1772) that the quadratic polynomial

$P(n) = n^2 + n + 41$

is prime for the 40 integers $n = 0, 1, 2, \ldots, 39$, with corresponding primes $ 41, 43, 47, 53, 61, 71, \ldots, 1601 $. The differences between the terms are $ 2, 4, 6, 8, 10, \ldots For n = 40$, it produces a square number, 1681, which is equal to $41 \times 41$, the smallest composite number for this formula for $n \geq 0$. If 41 divides $n$, it divides $P(n)$ too. Furthermore, since $P(n)$ can be written as $n(n + 1) + 41$, if 41 divides $n + 1$ instead, it also divides $P(n)$. The phenomenon is related to the Ulam spiral, which is implicitly quadratic, and the class number; this polynomial is related to the Heegner number $163 = 4 \cdot 41 - 1$. There are analogous polynomials for $p = 2, 3, 5, 11, \text{ and } 17$ (the lucky numbers of Euler), corresponding to other Heegner numbers.

Given a positive integer $S$, there may be infinitely many $c$ such that the expression $n^2 + n + c$ is always coprime to $S$. The integer $c$ may be negative, in which case there is a delay before primes are produced.

It is known, based on Dirichlet's theorem on arithmetic progressions, that linear polynomial functions $L(n) = an + b$ produce infinitely many primes as long as $a$ and $b$ are relatively prime (though no such function will assume prime values for all values of $n$). Moreover, the Green–Tao theorem says that for any $k$ there exists a pair of $a$ and $b$, with the property that $L(n) = an + b$ is prime for any $n$ from 0 through $k - 1$. However, as of 2020, the best known result of such type is for $k = 27$:

$224584605939537911 + 18135696597948930n$

is prime for all $n$ from 0 through 26. It is not even known whether there exists a univariate polynomial of degree at least 2 that assumes an infinite number of values that are prime; see Bunyakovsky's conjecture.

## Possible Formula Using a Recurrence Relation

Another prime generator is defined by the recurrence relation:

$a_n = a_{n-1} + \gcd(n, a_{n-1}), \quad a_1 = 7,$

where $\gcd(x, y)$ denotes the greatest common divisor of $x$ and $y$. The sequence of differences $a_{n+1} - a_n$ starts with $1, 1, 1, 5, 3, 1, 1, 1, 1, 11, 3, 1, 1, 1, 1, 1, 1, 1, 23, 3, 1, 1, 1, 1, 1, 1, 1, 47, 3, 1, 5, 3, \ldots$ (sequence A132199 in the OEIS). Rowland (2008) proved that this sequence contains only ones and prime numbers. However, it does not contain all the prime numbers since the terms $\gcd(n + 1, a_n)$ are always odd and so never equal to $2. 587$ is the smallest prime (other than 2) not appearing in the first $10,000$ outcomes that are different from 1. Nevertheless, in the same paper, it was conjectured to contain all odd primes, even though it is rather inefficient.

Note that there is a trivial program that enumerates all and only the prime numbers, as well as more efficient ones, so such recurrence relations are more a matter of curiosity than of any practical use.
