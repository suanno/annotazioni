# What can decoherence theory explain?

In decoherence theory, we subdivide the universe in 3 subsistems: the system (S), the measurement apparatus (A) and the enviroment ($\epsilon$)
$$H = H_S + H_A + H_{\epsilon}$$

The **measure procedure** is composed of two steps
- Premeasure (S and A interaction)
- Enviroment induced superselection (A and $\epsilon$ interaction)

### Premeasure
The state of the universe is **initially** (before any interaction between the 3 subsystems) is **separable**.
$$\ket{\Psi(0)} = \sum_n c_n\ket{s_n}\otimes\ket{A_0}\otimes\ket{\Epsilon_0}$$
where $\{\ket{s_n}\}$ is an orthonormal basis of $H_S$ and $\ket{A_0}, \ket{\Epsilon_0}$ are the initial states of the apparatus (A) and the enviroment ($\epsilon$).

When the interaction between the system and the apparatus took place, if you consider it to be **strong and localized in time**, you can neglect the interaction between (S+A) and the enviroment ($\epsilon$).

Due to Shmidt decomposition theorem, and considering no interaction with the enviroment (and no evolution of the enviroment) in the _small time interval_ when the system-apparatus interaction takes place; we can **uniquely decompose**
$$\ket{\Psi(t)} = \sum_n \alpha_n(\ket{s'_n}\otimes\ket{a_n})\otimes\ket{\Epsilon_0}$$
where $\{\ket{s'_n}\}$ is an orthonormal basis of $H_S$ in principle _different from_ $\{\ket{s_n}\}$ and $\{\ket{a_n}\}$ is an orthonormal basis (or at least an orthonormal set) of $H_A$.

When we introduced the states $\{\ket{s_n}\}$ and the coefficients $c_n$, we did not require anything on this basis or this coefficients.
So we can choose to represent the initial state of the system in the basis $\{\ket{s'_n}\}$; so we choose $\ket{s_n} = \ket{s'_n}\forall n$.

Then, for reasons unclear to me, the coefficients of the Shmidt decomposition $\alpha_n = c_n$ and so the _system-apparatus_ interaction **evolves the universe state** as
$$\sum_n c_n\ket{s_n}\otimes\ket{A_0}\otimes\ket{\Epsilon_0} \rightarrow \sum_n c_n(\ket{s_n}\otimes\ket{a_n})\otimes\ket{\Epsilon_0}$$

So the system-apparatus interaction establishes a **correlation** between the system and the apparatus.

In order to appreciate this correlation, you have to consider the **collapse of the wave function postulate** when you perform a quantum measure.
If you then measure the operator $\hat{O}_S$, acting on space $H_S$ and with eigenvectors $\{\ket{s_n}\}$, then the _universe state_ will collapse into a state of the kind $\ket{s_n}\otimes\ket{a_n}\otimes\ket{\Epsilon_0}$. So the state in which the apparatus is after the measure, **contains a record** of the result of the measurement performed on the system.

The idea is that _practically_, when you perform a measurment _on the system_, you let the system _pass through_ an apparatus and then you read the position of the _pointer_ on the analogic interface of the apparatus.
So you _find out_ the result of the measure, by looking at the _state of the apparatus_, which contains a record of the result of the measure.

#### Apparatus states ambiguity
Notice that, in order for the apparatus to record the measurement's result, there is no need for the states $\{\ket{a_n}\}$ to be orthogonal. In fact the states of the expansion $\{\ket{s_n}\otimes\ket{a_n}\}$ remain orthogonal, because the states $\{\ket{s_n}\}$ are orthogonal. And you want the states of the expansion $\{\ket{s_n}\otimes\ket{a_n}\}$ to be orthonormal if you want account the Bohrn rule, for example.

As there is no need for the states $\{\ket{a_n}\}$ to be orthogonal, then the decomposition of $\ket{\Psi(t)}$ is **not unique**. Thus there is an **ambiguity** on the choice of the states $\{\ket{a_n}\}$.

Decoherence theory tells that **you can't choice** the states $\{\ket{a_n}\}$, but they are determined by the form of the interaction between the apparatus and the enviroment.
So there is no choice to make and thus no ambiguity.
**Notice that**: The concept of the apparatus state containing a record of a measurement on the system, can be introduced even if we do not talk of decoherence, but we describe the measurement process _just as_ a wave function collapse (as we did above to enhance the correlation). And it is a very natural way of describing the way we _practically_ get the result of a measurement.
So we can state that, if we describe a measure postulating the wave function collapse, then there is an ambiguity, while in decoherence theory this ambiguity is not present.
So this is an **advantage** decoherence theory shows over the _wave function collapse description_.

You can show that, by changing the apparatus basis $\{\ket{a_n}\}\rightarrow \{\ket{a'_k}\}$ (where $\ket{a'_k} = \sum_n\bra{a_n}\ket{a'_k}\ket{a_n}$), the universe state will _collapse_ into a state of the kind $\ket{s'_k}\otimes\ \ket{a'_k}$ when we measure on the system an operator $\hat{O'}_S$ whose eigenstates are $\{\ket{s'_k}\}$.
But the everyday _experience_ tells us that the same apparatus cannot be used to measure different observables $\hat{O}$ and $\hat{O'}$. For example, a machine that is built to measure the position of a particle, is not able to measure even its momentum (even in two different experiment, not "simultaneously").

So the "apparatus basis ambiguity" is a _real problem_, because is not coherent with the everyday experience.
### Enviroment induced superselection
If we activate the apparatus-enviroment interaction _after_ the system-apparatus interaction (so now the second is no more present), then the system+apparatus becomes correlated with the enviroment, so
$$\sum_n c_n(\ket{s_n}\otimes\ket{a_n})\otimes\ket{\Epsilon_0} \rightarrow \sum_n c_n\ket{s_n}\otimes\ket{a_n}\otimes\ket{\epsilon_n}$$
where $\{\ket{\epsilon_n}\}$ is a set of states in $H_{\epsilon}$, not even necessarly linear independet.

Now that the subsystems are 3, we cannot apply the Shmidt decomposition theorem, but there is a theorem that grants that if a decomposition exists, then it is unique.
The uniqueness of this decomposition, and the fact that it is unique even without asking the states $\{\ket{\epsilon_n}\}$ and $\{\ket{a_n}\}$ to be orthogonal, **selects the apparatus basis** $\{\ket{a_n}\}$, so the ambiguity disappears.

**The (unique)** apparatus basis that appears in the universe state decomposition is called **pointer basis** (because, as we said before, the apparatus states **that show up in the decomposition** describe the position of the pointer in the analogic display of the machine). 

**But why** the universe state shall **evolves in such a way?**. Or equivalently, why it must preserve **the same** correlation between the system and the apparatus it had before interacting with the enviroment?

This is due to the everyday experience, that shows us that the machines we use to perform measurements do their job even if they inevitably interact with the enviroment.

There is an argument telling that you can find the _pointer basis_ as the eigenstates basis of an operator, acting on $H_A$, that commutes with the apparatus-enviroment interaction. So the interaction with the enviroment determines the pointer basis (this concept is called **enviroment-induced superselection**).

### Decoherence in the reduced density matrix