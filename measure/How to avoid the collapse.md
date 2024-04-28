
# How we can avoid talking about projective measure and explain (operatively) the results of an experiment?
We can do so, by describing the interaction with the Apparatus _at the level of_ **density matrix**.

## Example: Double Stern-Gerlach setup
Let's consider to **prepare** particles in an even superposition
$$\ket{\Psi_0} = \frac{\ket{+}+\ket{-}}{2}$$
The particles pass through a stern-gerlach apparatus, after which we have other two stern-gerlach apparatus operating _in reverse_.


[Disegnino]

If you do not perform any projective measure _during the paricle path_, the state **of any** particle will **not change** as you can see from **superposition principle** that


    Half wave-function will go up, half down, but then they will recombine!

But if you measure the path of the particles **after the reverse** stern-gerlach layer, then the particles at the end will be **in a different state** ($\ket{+}$ or $\ket{-}$) and you will have a **classical statistical mixtures** of the eigenstates $\ket{+}, \ket{-}$.

From the point of view of the **reduced density matrix**, you can see it is different in the two cases

$$\rho_1 = (\frac12\quad \frac12\\\qquad \frac12 \quad \frac12)$$

$$\rho_2 = (\frac12\quad 0\\\qquad 0 \quad \frac12)$$

[We talk about **reduced** matrix because the particle will entangle with the second system (apparatus) that measures its path after the _reverse S.G. layer_.
So we have to trace out the apparatus.
**Notice that**: we are not accounting the S.G. devices as measure apparatus in this problem.
In fact, when you use such devices, the measure happens on the screen, not where the S.G. is!!!]

But we have talked about **projective measurement** that is a concept we're trying to **work around**.
Now I'll show that this effect, **at the level of denisty matrix**, can be implementing without recurring to this concept, **by properly tuning the interaction** between the system (particle) and the apparatus (entity supposed to measure the path; the stern gerlachs are the rest of the enviroment)

The idea is that we saw how the interaction with the apparatus entangles the system's states of the **pointer basis** to some orthogonal apparatus states.

$$\ket{\Psi} = \frac{1}{\sqrt{2}}(\ket{+}\ket{A_+} + \ket{-}\ket{A_-})$$

[We are not writing _the rest of the world_ hilbert space. But we told that the pointer basis is the _only one_ when you have entanglement between all three systems!]

So if you consider the reduced density matrix of the system, by tracing out the apparatus, you find that **it becomes fast diagonal in the pointer basis** (as we told that the apparatus states become rapidly orthogonal [measure implies dephasing])
$$\rho = (\frac12\quad 0\\\quad 0 \quad\frac12)$$

So we simply need **to tune the interaction** hamiltonianS (both syst-app and app-env) in a way that the pointer basis is $\ket{+}, \ket{-}$ and we have already seen how to do so **in general**:

$$[S_{x}, H_{SA}] = 0$$
$$[S_{x}, H_{EA}] = 0$$
[The second is not correct, because the operators acts on orthogonal spaces and so it makes no sense. But the idea is that the projector on the pointer basis (intending the apparatus one) commutes with the interaction. But the apparatus pointer basis is correlated with the measured basis, so this is the reason **why tipically it is written so**]

So we have seen that, **at the level of the reduced density matrix**, the effect of a projective measure can be reproduced by a proper interaction hamiltonian; so **avoiding** the **unconfortable** concept of projective measure.

This is a relevant result, in fact the reduced density matrix has less information than the one contained in the state of the universe, but it contains **ALL the information that can be extracted by making an EXPERIMENT on the system**.
So managing to avoid the concept of projective measure at the level of the reduced density matrix, means being able to **explain the results of experiments** without recurring to this unconfortable concept.