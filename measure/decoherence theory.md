# All I know about decoherence theory

In decoherence theory, we subdivide the universe in 3 subsistems: the system (S), the measurement apparatus (A) and the enviroment ($\epsilon$)
$$H = H_S + H_A + H_{\epsilon}$$

The **measure procedure** is composed of two steps
- Premeasure (S and A interaction)
- Enviroment induced superselection (A and $\epsilon$ interaction)

### Premeasure
The state of the universe is **initially** (before any interaction between the 3 subsystems) is **separable**.
$$\ket{\Psi(0)} = \sum_n c_n\ket{s_n}\otimes\ket{A_0}\otimes\ket{E_0}$$
where $\{\ket{s_n}\}$ is an orthonormal basis of $H_S$ and $\ket{A_0}, \ket{E_0}$ are the initial states of the apparatus (A) and the enviroment ($\epsilon$).

When the interaction between the system and the apparatus took place, if you consider it to be **strong and localized in time**, you can neglect the interaction between (S+A) and the enviroment ($\epsilon$).

Due to Shmidt decomposition theorem, and considering no interaction with the enviroment (and no evolution of the enviroment) in the _small time interval_ when the system-apparatus interaction takes place; we can **uniquely decompose**
$$\ket{\Psi(t)} = \sum_n \alpha_n(\ket{s'_n}\otimes\ket{a_n})\otimes\ket{E_0}$$
where $\{\ket{s'_n}\}$ is an orthonormal basis of $H_S$ in principle _different from_ $\{\ket{s_n}\}$ and $\{\ket{a_n}\}$ is an orthonormal basis (or at least an orthonormal set) of $H_A$. Notice that the sum is over only one index $n$, this is due to the application of the Shmidt theorem.

When we introduced the states $\{\ket{s_n}\}$ and the coefficients $c_n$, we did not require anything on this basis or this coefficients.
So we can choose to represent the initial state of the system in the basis $\{\ket{s'_n}\}$; so we choose $\ket{s_n} = \ket{s'_n}\forall n$.

<font color="red">Then, for reasons unclear to me, the coefficients of the Shmidt decomposition $\alpha_n = c_n$ and so the _system-apparatus_ interaction **evolves the universe state** as</font>

$$\sum_n c_n\ket{s_n}\otimes\ket{A_0}\otimes\ket{E_0} \rightarrow \sum_n c_n(\ket{s_n}\otimes\ket{a_n})\otimes\ket{E_0}$$

So the system-apparatus interaction establishes a **correlation** between the system and the apparatus.

In order to appreciate this correlation, you have to consider the **collapse of the wave function postulate** when you perform a quantum measure.
If you then measure the operator $\hat{O}_S$, acting on space $H_S$ and with eigenvectors $\{\ket{s_n}\}$, then the _universe state_ will collapse into a state of the kind $\ket{s_n}\otimes\ket{a_n}\otimes\ket{E_0}$. So the state in which the apparatus is after the measure, **contains a record** of the result of the measurement performed on the system.

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

You can show (throught some examples) that, if you change the system basis $\{\ket{s_n}\}\rightarrow \{\ket{s''_k}\}$, it is possible to _mantain a correlation_ between the system and the apparatus, by changing the apparatus basis $\{\ket{a_n}\}\rightarrow \{\ket{a''_k}\}$ (where $\ket{a''_k} = \sum_n\bra{a_n}\ket{a''_k}\ket{a_n}$). Explicitly, you can rewrite the universe state as
$$\sum_n c_n(\ket{s_n}\otimes\ket{a_n})\otimes\ket{E_0} = \sum_n c_n(\ket{s''_n}\otimes\ket{a''_n})\otimes\ket{E_0}$$
so if you measure on the system an operator $\hat{O'}_S$, whose eigenstates are $\{\ket{s'_k}\}$, then the universe state will _collapse_ into a state of the kind $\ket{s''_k}\otimes\ \ket{a''_k}$, enabling you to find out the result of a measurement of $\hat{O'}_S$, by looking at the apparatus state.
But the everyday _experience_ tells us that the same apparatus cannot be used to measure different observables $\hat{O}$ and $\hat{O'}$. For example, a machine that is built to measure the position of a particle, is not able to measure even its momentum (even in two different experiment, not "simultaneously").

So the "apparatus basis ambiguity" is a _real problem_, because is not coherent with the everyday experience.
### Enviroment induced superselection
**Disclaimer**: When you read about _decoherence theory_ or _decoherence program_, it is intended to describe how the enviroment-apparatus (or enviroment-system) interaction influences your experimental results, where all information about the possible outcomes and their probabilities is contained in the reduced _density matrix_ of the system (or of the system+apparatus).
The premeasurement step is accounted in decoherence theory, but is a very general and natural consideration that you can made even outside the decoherence theory (as we did above, speaking of a wave function collapse; while in decoherence theory we never speak of a collapse!).
The articles often refer to the premeasurement step as the **von Neumann interpretation** of measure.

If we activate the apparatus-enviroment interaction _after_ the system-apparatus interaction (so now the second is no more present), then the system+apparatus becomes correlated with the enviroment (with this sentence, we are doing an **analogy** with what happens when the system-apparatus interaction), so
$$\sum_n c_n(\ket{s_n}\otimes\ket{a_n})\otimes\ket{E_0} \rightarrow \sum_n c_n\ket{s_n}\otimes\ket{a_n}\otimes\ket{\epsilon_n}$$
where $\{\ket{\epsilon_n}\}$ is a set of states in $H_{\epsilon}$, not even necessarly linear independet.

Now that the subsystems are 3, we cannot apply the Shmidt decomposition theorem (in some articles called **tridecompositional uniqueness theorem**), but there is a theorem that grants that if a decomposition exists, then it is unique.
The uniqueness of this decomposition, and the fact that it is unique even without asking the states $\{\ket{\epsilon_n}\}$ and $\{\ket{a_n}\}$ to be orthogonal, **selects the apparatus basis** $\{\ket{a_n}\}$, so the ambiguity disappears.

**The (unique)** apparatus basis that appears in the universe state decomposition is called **the pointer basis** (because, as we said before, the apparatus states **that show up in the decomposition** describe the position of the pointer in the analogic display of the machine).
Notice that, due to the decomposition, not only there is no choice for the apparatus basis, but even for the system basis (and even the enviroment states $\{\epsilon_n\}$), so there is no choice of the states $\ket{s_n}\otimes \ket{a_n}$ showing up in the decomposition.  
<font color=#0fb503>Notice even that, if the pointer basis is unuque, it means that the states you can find the apparatus after a measurement (the possible positions of the pointer on the display) are finite (and they are the pointer states). That's coherent with our experience.</font>

**But why** the universe state shall **evolve in such a way?**. Or equivalently, why it must preserve **the same** correlation between the system and the apparatus it had before interacting with the enviroment?
[Notice that a correlation between the apparatus and the enviroment must be established, if you do an analogy with what happens when the system-apparatus interaction took place. You can only discuss about wether the previous correlation between system and apparatus remains (and if it remains the same)]

This is due to the everyday experience, that shows us that the machines we use to perform measurements do their job even if they inevitably interact with the enviroment.

So the enviroment interaction (that is **the key of decoherence theory**) **removes** the apparatus **basis ambiguity**. But the strenght of decoherence theory is not the absence of this ambiguity, but the **operative description of measurement** it gives you. In this operative description, the pointer basis plays an important role.

#### Conceptual consideration on Pointer states (why we make all those consideration, instead of directly talk about density matrices?)
I want to **enhance** that we found out the extistance of a _preferred basis_ (the pointer basis) **without** talking about the density matrix, but from _everyday experience considerations_.
Thinking to everyday experience, we concluded that the pointer states (a _finite_ set of states) are the ones in which you find the apparatus _after_ a measurement took place (this is clear if you think to a wave function collapse following the measurement) and by recognizing the apparatus in one of those states, you get the result of a measurement on the system.

**In a while** we will see that this preferred basis plays an interesting role when you consider how the reduced density matrix of the system+apparatus subsystem evolves during the interaction with the enviroment.
<font color="green">
You can even say that the pointer basis is special for the above reason (related to density matrix) and you can explain all quantum measurement properties just dealing with the density matrix and **without making all the considerations made up until here***.
But the discussion would be **very innatural**.
</font>

### Decoherence in the reduced density matrix (Partial solution to the measure problem / Operative description of measure)
The universe state, after both interactions took place, is
$$\ket{\Psi(t)} = \sum_n c_n\ket{s_n}\otimes\ket{a_n}\otimes\ket{\epsilon_n}$$
and is the result of a **unitary** (and so _continuos in time_) **evolution** of the separable state $\ket{\Psi(0)}$. So the density matrix of the universe (that is always in a pure state) is
$$\rho = \sum_{n,m}c_nc^*_m \ket{s_na_n\epsilon_n}\bra{s_ma_m\epsilon_m}$$

Let's trace out the enviroment degrees of freedom and so consider the reduced density matrix of the system+apparatus (S+A)

$$\rho_{S+A} = \sum_k \bra{\epsilon_k}(\sum_{n,m}c_nc^*_m \ket{s_na_n\epsilon_n}\bra{s_ma_m\epsilon_m})\ket{\epsilon_k} = $$

$$= \sum_{n,m}c_nc^*_m\ket{s_na_n}\bra{s_ma_m}\sum_k\braket{\epsilon_k|\epsilon_n}\braket{\epsilon_m|\epsilon_k}$$

When we talked about the uniqueness of the _tridecomposition_, we enhanced that the states $\{\epsilon_n\}$ are not necessarly orthogonal. Indeed, _through some examples_, <font color="red">it can be shown that the enviroment states **that show up in the tridecomposition** (the decomposition is unique and so this set of states is unique) **become soon orthogonal** after the interaction with the enviroment begins.
In particular, their scalar product $\braket{\epsilon_n|\epsilon_k}\rightarrow \delta_{n,k}$ _exponentially_, in a time scale that is **much smaller** than the time scale your machines work.
</font>

So, short after the interaction with the enviroment begins, the reduced density matrix becomes, very fast, **but continuosly** **(quasi)diagonal** in the basis $\{s_n\}\otimes \{a_n\}$, so **in the pointer basis**.
[We have always called "ponter basis" $\{a_n\}$, that is unique because the tridecomposition is so. But even the system basis $\{s_n\}$ is unique, because we cannot change the system's basis while preserving a correlation between system-apparatus AND apparatus-enviroment, due to the tridecomposition uniqueness.
So it makes sense referring also to the basis $\{s_n\}\otimes \{a_n\}$ as "THE pointer basis", because its unique.]

#### Interpretation of the (quasi)diagonal reduced density matrix
The reduced density matrix is (quasi)diagonal in the pointer states basis $\{s_n\}\otimes \{a_n\}$. And we know that a **purely classical mixture** of states correspond to a diagonal density matrix, if the matrix is represented in the basis of the states that show up in the mixture.

This does not mean that the system+apparatus, after the interaction with the enviroment took place **is** in a state that is a purely classical mixture! Indeed, as the **reduced density matrix contains all the information you can extract** from the system+apparatus through experiments on the system+apparatus, this means that

---

When you perform an experiment (measure) on the system+apparatus, it **will react as if it were** in a purely classical mixture of states. The states of the mixture are the **pointer states** $\{\ket{s_n}\otimes\ket{a_n}\}$ and the associated classical(einsemble) probabilities are $|c_n|^2$.


So, in order **to explain the results** of a measurement experiment, you can deal with this **equivalent classiscal system**, because the information you can extract from your quantum system through experiments, is the same you can extract from the equivalent classical system.

---

#### Properties of quantum measurement explained (What decoherence theory manages to explain without postulating a wave function collapse)
- In the classical system (think it as a macroscopic system) you'll **find** the system **in one state** of the mixture with its einsemble probability, that is $|c_n|^2$ for the (pointer)state $\ket{s_n}\otimes\ket{a_n}$. This explains the _Bohrn rule_.

- Then, in a classical system (still think it as a _macroscopic object_), if you find the system in a state, and then you look at the state of the system immediately after, you'll find the system in the same state, so you'll get the same measurement result (think to the position of a grain of sand).
Appreciate that, in order to explain this second property of quantum measurement, you tipically postulate a _wave function collapse_ following a measurement, but here **you never account this postulate!**

With the above two considerations, _all_ the properties of the results of quantum experiments have been explained, without recurring to the wavefunction collapse postulate. But this is just an **Operative description** of quantum measurement, because we did not say anything about "what happens to the universe wave function **when you realize** the system+apparatus **in one pointer state**?". We simply managed to describe the properties of results of quantum measurements **without the need** of thinking to the universe state (we talked of density matricesm, but the density matrix contains less information than the state!).
For this reason, you can read in the articles that "decoherence theory gives only a **partial solution** to the measure problem".

#### Determination of the pointer basis (even called _Stability criterion_)
<font color="red">There is an argument telling that you can find the _pointer basis_ as the eigenstates basis of an operator, acting on $H_A$, that commutes with the apparatus-enviroment interaction. So the interaction with the enviroment determines the pointer basis (this concept is called **enviroment-induced superselection**).</font>
This enables you to answer the question "what **operator** does the apparatus measure?", because it tells you what quantum operator you measure depending on the form of the interaction with the enviroment.