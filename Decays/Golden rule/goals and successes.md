## Successes
- If $t$ is low, then both the calculations (Shrodinger and Interaction) presented in "golden rule stuck.md" are equal.
That's because you have to expand the exponential inside the integral just to order zero, because t is low and you need to keep only the leading (smallest) order in the final expression.
In other terms, the two expressions **differ** of a term that **is $o(t)$**.
- Truncating the Dyson serie (in the Interaction picture) at first order ($|c_m(t)|^2 \simeq |c_m^{(1)}(t)|^2$), you get:
$$P_{n\rightarrow m} = |c_m(t)|^2 = \frac{4|V_{nm}|^2}{(E_n-E_m)^2}\sin^2{\big[\frac{(E_m-E_n)t}{2\hbar}\big]}$$
    so there is non-zero probability that the final state has a _different energy_ respect to initial state.
- If you consider the probability of _escaping from_ state n, you need to sum over _all_ final states $\ket{m}$!
    $$P = \sum_{m\neq n} P_{n\rightarrow m} = \sum_{m\neq n}|c_m(t)|^2$$
    If you define a density of states per interval of energy such that the number of states $\#_{(E,E+dE)} = \rho(E)dE$, then
    $$P = \int dE_m\quad P_n(E_m) \rho(E_m)$$
    Where $$P_n(E_m) = \frac{4|V_{n}(E_m)|^2}{(E_n-E_m)^2}\sin^2{\big[\frac{(E_m-E_n)t}{2\hbar}\big]}$$ is the probability for a transition from state $\ket{n}$ to a state $\ket{m}$ of energy E (to one of them, not the sum on all of them).
    Notice that we are implicitly **assuming** that $P_{n\rightarrow m} = P_{n\rightarrow m}$ if $E_n = E_m$, when we went from a sum over $m$ to an integral in $dE_m$ and we considered $V_{nm} = V_n(E_m)$ (so we assumed this depends on $m$ only through $E_m$).

    #### Delta rises
    In the integral, $P_n(E)$ behaves as a _distribution_. If you think to $P_n(E)$ **no more as a function of E**, but as a distribution (it is still a function of $t$ though), then it holds
    $$\lim_{t\rightarrow \infty} P_n(E_m) =  \frac{\pi t}{2\hbar}|V_{n}(E_m)|^2\quad \delta(E_m - E_n)$$

    Notice that, if you still consider $P(E)$ as a function of $E$, then the above _delta_ makes no sense cause it is not a function.

    If you insert the last expression in the integral, as $\rho(E)$ is independent on time $t$, then the escaping probability $P \propto t$.

    #### On the Interpretation of Golden Rule
    Notice that we stated that the **escaping** probability goes $\sim t$, but NOT the probability of scattering to _one particular_ state $m$. That probability goes as $\sim t^2$ (**NOT LINEARLY**) as stated below! 
## Goals / To understand
### Time dependance of probability: $\sim t$ or $\sim t^2$?
- The escape probability, for long time $t$ ($\lim_{t\rightarrow \infty}$), $P \propto t$.

    In this limit, the probability of moving to a state with different energy becomes less and less probable, because the function of $\omega = \frac{E_m - E_n}{\hbar}$: $P_{n\rightarrow m}(\omega)$ becomes more and more peaked at $\omega = 0$.
    So, in this _long time_ limit, the escape probability is a probability of escaping to a state with the same energy. 

-   But the probability of moving to _a particular state_ with the same energy is found by evaluating $P_{n\rightarrow m}(\omega)$ in the limit $\omega \rightarrow 0$. As the peak of the function increases $\sim t^2$, you find out that this probability is $P_{n\rightarrow m}(\omega)\propto t^2$.


    #### Big consistence problem
    So we find that the (escaping) probability of moving from state $n$ to _any_ state $m$ with the same energy (sum over probabilities of the single particular states) is $P \propto t$.
    While the probability of moving to _one particular of those_ states is $P_{n\rightarrow m}\propto t^2$.

    This is **strange** because this results are **independent** on the density of states, so on the number of final states with the same energy!

### Shrodinger and Interaction picture apparent incompatibility
The expression you get for $|c_m(t)|^2$ is, unless terms that are $o(t^2)$ (note that we are considering modulus _squared_ so its $o(t^2)$, not $o(t)$), equal in the two pictures.
Anyway, this equivalence **gives the opportunity of inserting arbitrary time dependent phases inside the time integral (in the Dyson serie)** and so to modify the final expression you get (so the "shape" of the Golden rule)!!!

### Uncountable final states
If the final states are uncountable (as in the case where the _unperturbed_0 system ($H_0$) is a _free particle_ [not confined, **not even** in a very big box]) then there are problems in defining a density of states, because the number of states in the Energy range $(E, E+dE)$ is infinite and so $\rho(E)dE = \infty$.