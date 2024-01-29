# Cannot proove Fermi Golden Rule in Shrodinger picture

All books proove the golden rule in the _interaction picture_. As its not clear the reason of that choice, I tried to get the rule in the Shrodinger picture, but i find a different result!

Here I show my "proof" in the Shrodinger picture.
I also enhance that it is relevant to understand where this proove is wrong, in order to understand why it is easier to work in the interaction picture!

If the system is in the eigenstate $|n \rangle$ of $H_0$ at time $t=0$, the coefficient of state $|m \rangle$ at time $t$ is $c_m(t) = \langle m|U(t)|n \rangle$ where $U(t)$ is the time evolution operator.
As Shrodinger equation can be written as $\dot{U} = -iU$ ($\hbar = 1$), we can express $U(t)$ as its _Dyson serie_
$$U(t) = 1 - {i}\int_0^tdt'H(t') + ({-i})^2\int_0^tH(t')dt'\int_0^{t'}dt'' H(t'') + ...$$
Where the omitted terms are $o(t^2)$.

So
$$c_m(t) = \langle m|U(t)|n \rangle = c_{m}^{(0)}(t) + c_{m}^{(1)}(t) + c_{m}^{(2)}(t) + o(t^2)$$
where the first coefficients of the sum are
$$c_{m}^{(0)}(t) = \langle m|1|n \rangle = \delta_{m,n}$$
$$c_{m}^{(1)}(t) = -i\int_0^tdt'\langle m|H(t')|n \rangle = -i\int_0^tdt'\langle m|H_0 + V(t')|n \rangle = 
$$
$$= -i\int_0^tdt'e^{i(E_n-E_m)t'}\delta_{n,m} -i\int_0^tdt'V_{m,n}(t') $$
and $V_{n,l}(t) = \langle n|V(t)|l\rangle$, where $V$ is the interaction term in the _Shrodinger picture_.

As we are interested in scatterings, we consider $m\neq n$, so $c_m^{(0)}=0$ and the _first order approximation_ of $|c_m(t)|^2$ is

$$|c_m(t)|^2 \simeq |c_m^{(1)}|^2 = |\int_0^tdt'V_{m,n}(t')|^2$$

This result is **incompatible** with the one you can find in many books, working in the interaction picture
$$|c_m(t)|^2 \simeq |c_m^{(1)}|^2 = |\int_0^tdt'e^{i(E_m-E_n)t'}V_{m,n}(t')|^2$$

Where the exponential in the integral is _fundamental_ to get the famous delta in the rule!