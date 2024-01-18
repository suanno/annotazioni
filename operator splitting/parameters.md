# Implementation in a way that you can go from variables to physical quantities in a clear way

We consider no potential for simplicity (**free_particle.c**)
$$\Psi(x,0) = e^{-\frac12\frac{(x-x_c)^2}{\sigma^2}}e^{i\frac{p}{\hbar}x}$$
And, at each discrete step $\tau$ the **is evolved** such that
$$\Psi(x,t)\rightarrow\Psi(x,t+\tau) = IFFT(e^{i\frac{\hbar}{2m}q^2\tau}FFT(\Psi(x,t)))$$

Let's express all **physical quantities** as a non-dimensional factor (that is a variable in the code) times a proper dimension (we write those dimensional terms as $\hat{u}$ e.g. $\hat{u_x}$ is the dimensional term we adopt for _lenghts_):

**Note**: As "a" and "$\tau$" are variables, they are not the **physical** steps!!!

- $x = Xa\hat{u_x}$, quindi il passo del reticolo spaziale è $a\hat{u_x}$ (a è adimensionale, mentre il passo ha le dimensioni di una lunghezza).
The lattice is $X=0,1,...,N$.

    So $x_c = Ca\hat{u_x}$, $\sigma = \Sigma a\hat{u_x}$, $L = N_{steps}a\hat{u_x}$

- $t = T\tau\hat{u_t}$, so $tspan = N_{steps}\tau\hat{u_t}$

- $\hbar = H\hat{u_E}\hat{u_t}$ and $p/\hbar = \frac{P}{H\hat{u_x}}$ and $m = M\hat{u_E}\frac{\hat{u_x}^2}{\hat{u_t}^2}$

- $q = (\frac{2\pi}{Na\hat{u_x}})Q$ where the q lattice is (**for unknown reasons**) $Q=0,1,2,...,(\frac{N}{2}-1),-\frac{N}{2}, -\frac{N}{2}+1,...,-1$

As a consequence:
$$\Psi(x,0) = e^{-\frac12\frac{(X-C)^2}{\Sigma^2}}e^{i\frac{P}{H}aX}$$
and
$$e^{i\frac{\hbar}{2m}q^2\tau}\rightarrow e^{i\frac{Hq^2}{2M}\tau}$$

Now, if you insert any value as the variables in the code
- $C, \Sigma, P, M$
- $H$
- $a, \tau$
- $N, N_{steps}$

AND you choose the dimensional terms (note that the choice of $H$ puts a constraint!), then you can find the values of the **physical (REAL) quantities**!

## Open problem
Notice that the speed of the packed is $v = p/m$, so you can decide that, at time $t=tspan$, the packed moved of a **physical** distance $\alpha L$, by putting
$$\frac{PH}{M} = \alpha \frac{Na}{N_{steps}\tau}$$


But the codes behave respecting the above formula only is the mass $M$ is _sufficiently small_. Even if you set $P/M$, $M$ and then assign $P = P/M*M$ (so if you assign the velocity $p/m$ directly), the problem still exists.
If the mass is not sufficiently small, the distance travelled is significantly smaller or the packet splits in two.
No idea why.