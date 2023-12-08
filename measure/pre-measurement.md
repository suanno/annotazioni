# Schmidt decomposition (Theorem)
Given a bipartite system $H = H_A\otimes H_B$, then **any** state of the composite system $\ket{\Psi}\in H$ can be **always** expressed as
$$\ket{\Psi} = \sum_n c_n\ket{a_n}_A\otimes\ket{b_n}_B$$
where $\{\ket{a_n}_A\}$ is a _orthonormal basis_ of $H_A$ and $\{\ket{b_n}_B\}$ is an orthonormal basis of $H_B$.
The choise of the two basis is **not arbitrary**, but it's determined by the state $\ket{\Psi}$. The Schmidt **decomposition is unique**!

**Notice that**: The above statement makes sense only if $dim(H_a) = dim(H_B)$, otherwise the basis have different dimensions an so cannot be labelled with the same index. In this case the above decomposition _is still possible_, but the basis of the subsystem with higher dimension is substituded by _just_ an _orthonormal_ set with the dimension of the lower dimensional subsystem. 

[Wikipedia](https://en.wikipedia.org/wiki/Schmidt_decomposition)

### Application (von Neuman description of measure)
When a measurement apparatus (A) interacts with the system (S), the _composite system_ was initially in a separable state
$$\ket{\Psi(0)} = \ket{\varphi}_S\otimes\ket{\phi}_A = \sum_n \alpha_n \ket{n}_S \otimes \sum_m \beta_m\ket{m}_A$$
where $\{\ket{n}\}_S$ is an othonormal basis of the system (S) and $\{\ket{m}\}_A$ is an othonormal basis of the apparatus (A).

Then, when the _system-apparatus_ interaction starts, the _composite system_ evolves from a separable state to an entangled state, because
$$\sum_n \alpha_n \ket{n}_S \otimes \sum_m \beta_m\ket{m}_A = \sum_{n,m}\gamma_{n.m}(0)(\ket{n}\otimes\ket{m})$$
evolves in time, so $\gamma_{n.m}(0)\rightarrow\gamma_{n.m}(t)$. As a consequence, the state
$$\ket{\Psi(t)} = \sum_{n,m}\gamma_{n.m}(t)(\ket{n}\otimes\ket{m})$$
isn't, in general, separable anymore!

So $\ket{\Psi(t)}$ is an entangled state and cannot be expressed as the kroneker product of two systems belonging to the systema and the apparatus. **But** we can use the Schmidt decomposition theorem and write
$$\ket{\Psi(t)} = \sum_k c_k\ket{S_n}_S\otimes\ket{A_n}_A$$
So the time evolution of the composite _system's state_ is

$$\sum_n \alpha_n \ket{n}_S \otimes \sum_m \beta_m\ket{m}_A \rightarrow \sum_k c_k\ket{S_k}_S\otimes\ket{A_k}_A$$

where $\{\ket{n}_S\}$ and $\{\ket{S_k}_S\}$ are two **different** _orthonormal basis_ of the system (S), and the same statement holds for the apparatus (A).

**Notice that**: While $\{\ket{n}_S\}$ and $\{\ket{m}_A\}$ are always basis of the subsystems, $\{\ket{S_k}_S\}$ and $\{\ket{A_k}_S\}$ are basis only if $dim(H_S) = dim(H_A)$. Otherwise they are _just orthonormal sets_ (of dimension $\leq$ than their subsystem dimension).

### Correlation (central concept in von Neumann description of measure)
From the Schmidt decomposition, you can see that it exists a correlation between the system and the apparatus.

Adopting, for **just this sentence**, a _collapse description_ of measure, then if you perform a measurement _on the system_ of an operator whose eigenstates are the states $\{\ket{S_k}_S\}$, then the _composite state_ will collapse into a state of the kind $\ket{S_k}_S\otimes\ket{A_k}_A$ and so the apparatus will be in the state $\ket{{A_k}}_A$.
This sentence show explicitly there is a correlation between the two subsystems. We enhanced the correlation adopting a _collapse description_ but the correlation exists in the state **independently on what you postulate** for describing how a measure works.

Indeed, this correlation **seem useless**, because the is no _a priori_ relation between the coefficients $c_k$ and $a_n$, so you cannot extract any information about the system's initial state by exploiting the correlation granted by the Shmidt theorem.

At this stage comes the **von Neumann contribute**, in fact he prooved that there always exists an _unitary operator_ $U$ such that the coefficients $c_k$ _of the Shmidt decomposition_ of $U\ket{\Psi}$ are equal to the coefficients $a_n$ of the system's state before appling $U$ to the composite system's state. So the correlation is **usefull** if the composite system's state evolves with this operator.

This equivalently means that **there exists** a _time independent_ **interaction hamiltonian** $H_{int}$ (describing the interaction between the system and the apparatus) and an **interaction time** $\Delta t$, such that $U = e^{-\frac{i}{\hbar}H_{int}t}$.

If the interaction with the apparatus is _fast and strong_, so the interaction time $t$ is small, but $H_{int}t$ is sufficiently big to establish a _strong correlation_ between the system and the apparatus, then we can neglect $H_0$ in the time evolution operator, so
$$e^{-\frac{i}{\hbar}(H_0+H_{int})t}\simeq e^{-\frac{i}{\hbar}H_{int}t}$$
So, if the interaction is described by the proper hamiltonian $H_{int}$ and lasts the proper time $t$, then the interaction _entangles_ the system and apparatus enstablishing a correlation that can be exploited to study the system's state before the interaction.

The (unitary) interaction with the apparatus which establishes correlation between the system and the apparatus is called **PRE-MEASUREMENT**.


### Da capire
Ok, abbiamo visto che esistono una hamiltoniana ed un tempo di interazione per cui si instaura questa correlazione _utile_, ma nella realtà l'hamiltoniana di interazione è questa?

Negli articoli si dà per scontato che il processo di premeasurement instauri una correlazione che mantiene i coefficienti dello stato.