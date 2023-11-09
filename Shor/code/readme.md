## About the code
This is the implementation of the Factorization using the Shor algorithm.

The Shor algorithm is substituded with a loop that tries all integer values until it find r such that $a^r = 1 \pmod N$.

There are notes on the existence of $r$, whose results are implemented in the code.


## Fun fact
There are some integers that you can write as the product of TWO primes (N = pq) that you cannot factorize with this algorithm.

That's beacause, to factorize N, you need that
- It exists a \< N such that it exists r \< N such that $a^r = 1 \pmod N$ (and you take the smallest)
- r is even and $y = (a^{\frac{r}{2}} - 1) \neq 0 \pmod N$

e.g.: You cannot factorize 4,6,9,14

The hope is that BIG numbers are always factorizable, because you can try a lot of values of a, since the limitation on the values of a to check is a \< N and N is BIG.