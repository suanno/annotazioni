# Numerical approach for solving the Shrodinger equation (where H is TIME DEPENDENT)
Given an hamiltonian $H(t) = H_0 + V(t)$, the **core idea** of the method is this approximation:

$$U(t_0,t_0+\tau) = e^{-\frac{i}{2}(V(t_0)+V'(t_0)\frac{\tau}{2})\tau}e^{-iH_0\tau}e^{-\frac{i}{2}(V(t_0)+V'(t_0)\frac{\tau}{2})\tau} + o(\tau^2)$$
where $U(t_0,t_0+\tau)$ is the _time evolution operator_ from time $t_0$, to time $t_0+\tau$ (where $\tau$ is small).
### Proof
In order to proove the above formula, we expand as taylor series both the left member and the right member.
Then we consider only terms of order 1, $\tau$ or $\tau^2$, while we represent the the remaining terms _all togheter_ with the symbol $o(\tau^2)$. Then we show the two expressions are equal, unless a term that is $o(\tau^2)$.

The exact formula for the time evolution operator is (for simplicity of notation we choose $t_0 = 0$ and call $U(0,0+\tau)=U(\tau)$)
$$U(\tau) = 1 -i\int_0^{\tau}dtH(t) - \int_0^{\tau}dtH(t)\int_0^tdt'H(t') + ...$$
Before expanding the above expression until second order ($\tau^2$), we show that the _next terms_ of the sum are of order greater than $\tau^2$, so we show that $(...) = o(\tau^2)$.

----
If in the first integral we write $H(t)$ as its _taylor serie_ $H(t)\simeq H(0) + H'(0)t + o(t)$, we get $$\int_0^{\tau}dtH(t) = H(0)\tau + H'(0)\frac{\tau^2}{2} + o(\tau^2) = H(0)\tau + o(\tau)$$
where we used the fact $\int_0^{\tau}o(t)dt = o(\tau^2)$, because $o(t)$ means that the leading order is $t^2$ _or greater_, so $o(t) = \alpha_2 t^2 + \alpha_3 t^3 + ...$ and if you integrate $t^2$ you get a term of order $\tau^3 = o(\tau^2)$. We also enhance that $o(t)t = o(t^2)$ for the same reason.


If we do the same for the second term of the sum, we get
$$\int_0^{\tau}dtH(t)\int_0^{t}dt'H(t') = \int_0^{\tau}dtH(t)(H(0)t + o(t)) = $$
.
$$ = \int_0^{\tau}dtH(t)H(0)t + \int_0^{\tau}dtH(t)o(t) = $$
.
$$ = H(0)\int_0^{\tau}dt (H(0)+H'(0)t+o(t))t + \int_0^{\tau}dt(H(0)+H'(0)t+o(t))o(t) = $$
.
$$ = H^2(0)\frac{\tau^2}{2} + o(\tau^2)$$
where we put the terms of order $\tau^3$ and $o(\tau^3)$ inside $o(\tau^2)$.

So we showed that the first integral is $H(0)\tau + o(\tau) = o(1)$ and the second (double) integral is $H^2(0)\frac{\tau^2}{2} + o(\tau^2) = o(\tau)$. So the next terms of the sum will be $(...) = o(\tau^2)$, so we can neglect them for our purpose.

----

Now let's expand $U(\tau)$ until second order. Using the above results (we already expanded the two integrals until second order),
$$U(\tau) = 1 -i\big(H(0)\tau + H'(0)\frac{\tau^2}{2}\big) - H^2(0)\frac{\tau^2}{2} + o(\tau^2)=$$
.
$$= 1 -iH(0)\tau + \big(-iH'(0)-H^2(0)\big)\frac{\tau^2}{2} + o(\tau^2)$$

Now we have to expand until second order $e^{-\frac{i}{2}V(0)\tau}e^{-iH_0\tau}e^{-\frac{i}{2}V(0)\tau}$, so we expand _each_ exponantial as its taylor serie, until second order 
$$e^{-\frac{i}{2}(V(0)+V'(0)\frac{\tau}{2})\tau} = (1-\frac{i}{2}(V(0)+V'(0)\frac{\tau}{2})\tau-\frac{1}{8}(V(0)+V'(0)\frac{\tau}{4})^2\tau^2+o(\tau^2)) =$$
.
$$ =  (1-\frac{i}{2}V(0)\tau-\frac{i}{2}V'(0)\frac{\tau^2}{2} - \frac{\tau^2}{8}V(0) + o(\tau^2))$$
.
$$e^{-iH_0\tau} = (1-iH_0\tau-\frac{\tau^2}{2}H_0^2 + o(\tau^2))$$
Now me multiply the **three** exponential, ignoring terms of order greater than second, and we get
$$1-2\frac{i}{2}V(0)\tau-2\frac{i}{4}V'(0)\tau^2-iH_0\tau +
$$
.
$$
+ (-\frac{i}{2})(-i)V(0)H_0\tau^2 +(-\frac{i}{2})(-i)H_0V(0)\tau^2 - 2\frac{1}{8}V^2(0)\tau^2-\frac{\tau^2}{2}H_0^2+o(\tau^2)) =$$
.
$$= 1 -i(H_0+V(0))\tau -iV'(0)\frac{\tau^2}{2} - \frac{\tau^2}{2}(V(0)H_0+H_0V(0))-\frac{\tau^2}{4}V^2(0)-\frac{\tau^2}{2}H_0^2+o(\tau^2)$$

And, if we recognize that $H(0)^2 = (H_0+V(0))^2 = H_0^2 + H_0V(0) + V(0)H_0 + V^2(0)$, we find that
$$e^{-\frac{i}{2}(V(0)+V'(0)\frac{\tau}{2})\tau}e^{-iH_0\tau}e^{-\frac{i}{2}(V(0)+V'(0)\frac{\tau}{2})\tau} = 1-iH(0)\tau -iV'(0)\frac{\tau^2}{2}- H^2(0)\frac{\tau^2}{2}+o(\tau^2)$$
And we remember that
$$U(\tau) = 1 -iH(0)\tau + \big(-iH'(0)-H^2(0)\big)\frac{\tau^2}{2} + o(\tau^2)$$

The last two expressions are the same, if you use that $H_0$ has no time dependance, so $H'(0) = V'(0)$.

# Algorithm implementation
Consider $H = H_0 + V(x,t)$ where $H_0 = -\frac{d^2}{dx^2}$.

So, if we want to evolve the state with the operator-splitting formula, we have to calculate $$e^{-i\tau H_0}\Psi(x,t) = e^{+i\tau\frac{d^2}{dx^2}}\Psi(x,t)$$
but how we calculate the action of the exponantial of a derivative?

If we expand the exponential as its Taylor serie
$$e^{i\tau\frac{d^2}{x^2}}\Psi(x,t) = \sum_n \frac{(i\tau)^n}{n!}\frac{d^{2n}}{dx^{2n}}\Psi(x,t)$$
and calculating numerically those derivatives is something we don't wanna do.

The idea that solves the problem is _moving to frequency domain_, because
$$\mathcal{F}(\frac{d^n}{dx^n}\Psi(x,t)) = (iq)^n\mathcal{F}(\Psi(x,t))$$

So, using the _linearity_ of the Fourier transform
$$\mathcal{F}(e^{i\tau\frac{d^2}{x^2}}\Psi(x,t)) = \sum_n \frac{(i\tau)^n}{n!}(iq)^{2n}\mathcal{F}(\Psi(x,t)) = e^{-i\tau q^2}\mathcal{F}(\Psi(x,t))$$
So now we need just to make a fourier trasform and a simple multiplication.

In order to get $\Psi'(x,t) = e^{i\frac{d^2}{dx^2}}\Psi(x,t)$, we simply calculate an _inverse Fourier transform_
$$\Psi'(x,t) = \mathcal{F^{-1}}(\mathcal{F}(e^{i\frac{d^2}{dx^2}}\Psi(x,t))) = \mathcal{F^{-1}}(e^{-i\tau q^2}\mathcal{F}(\Psi(x,t)))$$
Pay attention to the fact that, after calculating the Fourier transform of $\Psi(x,t)$, you get a function of $q, t$.

## Discretization Problel
Multiplying by $e^{-i\tau q^2}$ the fourier transform of $\Psi(x,t)$ is _not simple_, as $x$ and $q$ are discrete and not continuos variables.
In addition, the Fourier transform $\mathcal{F}$ becomes the DFT.

The real and the reciprocal space are points of a lattice and those two **lattices are related** (as we will find out). So we can define the real lattice and then calculate the reciprocal one from the relation that binds the two lattices. In short, we cannot define as we want both lattice, because they are related in a way that we'll discover soon.

It's natural to discretize the real space as
$$x\rightarrow x_n = na\quad n\in\{0,1,...,N-1\}$$
where $a$ is the lattice spacing and $N$ is the number of lattice sites.

Now consider what is the **analogous property** of 
$$\mathcal{F}(\frac{d}{dx}\Psi(x,t)) = (iq)\mathcal{F}(\Psi(x,t))$$
when you deal with DFT instead of Fourier transform.

$$x = an \implies \frac{d\Psi(x)}{dx}=\frac{dn}{dx}\frac{d\Psi(x)}{dn} = \frac{1}{a}\frac{d\Psi(x)}{dn}$$
Now, as $x \rightarrow an$, we have that $\Psi(x)\rightarrow\Psi_n = \Psi(x_n)$ and we can express the **array** $\Psi_n$ as its inverse DFT
$$\sum_{k=0}^{N-1}\hat{\Psi}_ke^{i\frac{2\pi}{N}kn}$$
so $$\frac{d\Psi(x)}{dx} = \frac{1}{a}\sum_{k=0}^{N-1}(i\frac{2\pi}{N}k)\hat{\Psi}_ke^{i\frac{2\pi}{N}kn}$$

We can read this result as "You can make a derivative in real space, by multiplying the _DFT_ by $(i\frac{2\pi}{Na}k)$".
But we know that in the **analogous property** of the _Fourier transform_ we multiply by (iq) instead.

So, when you discretize reciprocal space, $q$ becomes a discrete variable that can only take the values of a lattice, and
$$q\rightarrow q_n = \frac{2\pi}{Na}k\quad k\in\{0,1,...,N-1\}$$

Here its clear that the two lattices are related, as you can see by the presence of the real lattice spacing $a$ in the above formula.

Now we know how to multiply the Fourier transform of $\Psi(x,t)$ (that in a discrete world becomes the DFT) times $e^{-i\tau q^2}$, that becomes the **array** $e^{-i\tau q_k^2}$ with $k\in\{0,1,...,N-1\}$.

## Boundary conditions
In reality, the reciprocal space shape depends on the boundary conditions you choose.
But, as soon as we make our simulations _far from the boundaries_, we expect boundary condition to not be relevant.