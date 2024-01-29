# Small t
We require that t is small (_how small?_) when we make the following approximations/considerations:
### 1) Truncate $c_m(t)$ expansion
$$U(t) = 1 - \frac{i}{\hbar}\int_0^tH(t')dt' + o(t)$$
and if perturbation is costant $V(t) = V$ and the initial state is $H_0\ket{n} = \epsilon_n\ket{n}$
$$c_m(t) = \braket{m|U(t)|n}  = \delta_{mn} - \frac{i}{\hbar}\braket{m|(\epsilon_n+V)|n}\int_0^tdt' + o(t) = $$
$$ = \delta_{nm}(1-\frac{i}{\hbar}\epsilon_n t) -\frac{i}{\hbar}\braket{m|V|n}t + o(t)$$
$$|c_m(t)|^2 = \frac{1}{\hbar^2}|\braket{m|V|n}|^2t^2 + o(t^2)\quad\text{ if $m\neq n$}$$

while in Interaction picture
$$U_I(t) = 1 - \frac{i}{\hbar}\int_0^te^{-\frac{i}{\hbar}H_0t'}V(t')e^{+\frac{i}{\hbar}H_0t'}dt' + o(t)$$
$$c_m^{(I)}(t) = \braket{m|U_I(t)|n} = \delta_{mn} - \frac{i}{\hbar}\braket{m|V|n}\int_0^te^{\frac{i}{\hbar}(\epsilon_n - \epsilon_m)t'}dt' + o(t) =$$
$$ = \delta_{nm} -\frac{i}{\hbar}\braket{m|V|n}\frac{2\hbar}{(\epsilon_n-\epsilon_m)}e^{\frac{i}{2\hbar}(\epsilon_n-\epsilon_m)t}\big(e^{\frac{i}{2\hbar}(\epsilon_n-\epsilon_m)t} - e^{-\frac{i}{2\hbar}(\epsilon_n-\epsilon_m)t})\frac{1}{2i} + o(t)= $$
$$ = \delta_{nm} -i\braket{m|V|n}\frac{2}{(\epsilon_n-\epsilon_m)}e^{\frac{i}{2\hbar}(\epsilon_n-\epsilon_m)t}\sin{\big[\frac{(\epsilon_n - \epsilon_m)t}{2\hbar}]} + o(t)$$
$$|c_m^{(I)}(t)|^2 = \frac{4|V_{nm}|^2}{(E_n-E_m)^2}\sin^2{\big[\frac{(E_m-E_n)t}{2\hbar}\big]} + o(t^2)\quad\text{ if $m\neq n$}$$

### 2) Show the expressions obtained in the two picture are the same (check robustness of the "small times idea")
Without using perturbation theory, $|c_m^{(I)}(t)|^2 = |c_m(t)|^2$ and the expression you get in the two picture, **even if they do not seem to be equal, they are the same**. That's because, _as $t$ is small_, $\sin(\alpha t) = \alpha t + o(t)$ (you can check that easily and find that the two expression are the same).

So, in both pictures, we find that the scattering probability $\ket{n}\rightarrow \ket{m}$ goes as $t^2$.

# Large t
### 1) Get the delta and the linear in time scattering probability

