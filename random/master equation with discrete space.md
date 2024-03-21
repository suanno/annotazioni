# If time is discrete
Let's consider a 1D walk where you cannot stay still on a site.

Let's call the probability of being at site $N$ at time $n$
$$P_N(n)$$
**Notice** that, even if $n$ is in brackets, it is discrete and not continuos!

And let's call $q$ the probability of moving to the left neighbor site and $p$ on the right neighbor.
From our assumptions $q+p = 1$.

$$P_N(n+1) = pP_{N-1}(n) + qP_{N+1}(n)$$

From this equation, there is **no way** of getting a differential equation (to recover derivatives) as space and time are discrete.
You can only take a **continuos limit** in both space and time, to find the Diffusion equation.

# If time is continuos
Here we cannot consider anymore the previous system, because
1) it makes no sense anymore saying that the walker cannot stay still, as the time step $dt$ is no more fixed, as in the discrete case.
If you take $dt$ to be very very small, _no walker_ will move to another discrete site!

2) The below equation **cannot be true anymore**
    $$P_N(t+dt) = pP_{N-1}(t+dt) + qP_{N+1}(t+dt)$$
    as now that time is continuos, you recognize, if $dt$ is small 
    $$p=\gamma_p(t) dt \qquad q = \gamma_q(t) dt$$

    where $\gamma_p$ and $\gamma_q$ are **transition rates** (here you have transition rate; in the discrete case you have transition probabilities per step).

    As 
    - the step $dt$ is arbitrary (as soon as it is small so you can talk about transition probabilities proportional to $dt$, so of transition _rates_)
    - and $\gamma$ does not depend on $dt$
    
    then $\gamma(t)dt$ cannot be independent on $dt$!!!
    So you cannot write the above equation, where $q$ and $p$ are numbers!!!

    Let's find an equation that holds, by making a **net balance**
    $$\Delta P_N(t) = +[\gamma_pdtP_{N-1}(t)+\gamma_qdtP_{N+1}(t)]$$
    $$- [\gamma_qdtP_{N}(t)+\gamma_pdtP_{N}(t)]$$

    If you multiply and divide by $dt$ small, and simplify the "dts" left (all of them simplify!)

    $$\partial_t P_N = \gamma_pP_{N-1}+\gamma_qP_{N+1}-(\gamma_p+\gamma_q)P_{N}$$

    You can see that this equation is NOT the equation we told to be false, because the ratios are always $\geq 0$.

    The rates of course can depend on time, but for simplicity we can assume they are equal, so we get

    $$\partial_t P_N = \gamma (P_{N-1}+P_{N+1}-2P_{N})$$

    Usually you can see the equation written considering $\gamma = 1$.
    As $\gamma$ has the dimension of $[1/T]$, by making this choice you loose dimensional consistency in the equation.
    But the way you _mathematically_ solve the equation with or without the precence of $\gamma$ is the same... (it doesn't change the shape of the solution, it is only a parameter of the solution)