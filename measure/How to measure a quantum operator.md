# How should we build the apparatus to measure a Quantum Observable $\hat{O}$?

It is not clear, simply considering the postulates, how to perform a **projective measurement** of an operator $\hat{O}$ **in an experiment**.

To describe how **experimentally** you measure an Observable, you have to avoid the concept of projective measure and describe the **measurement process** through the interaction between the **experimental apparatus** and the system.

Now we'll study the **interaction hamiltonian** $H_{SA}$ between the two systems and we'll find what are the **properties it must have** in order for the Apparatus to **correctly do his job**.
[We do not talk about eviroment interaction yet, even thought it is the interaction that SELECTS the observed quantity by removing the ambiguity. We do like this to make the speech more natural, we'll introduce things when we need them!]

## Example: Measuring the spin of a qubit
Imagine to have a **qubit** and that you want to measure its operator $\hat{S_x}$, what are the **general properties** that your apparatus has to match in order to measure **that particular** operator?

### Premeasurement
When you perform a measurement, you have a **macroscopic indicator** whose position/orientation _is supposed to_ describe what is the state of the system.
So the most reasonable way of describing this **quantomechanically** is this:

$$`\hat{U}_{SA}(\ket{+}\otimes\ket{A_0}) = \ket{+}\otimes\ket{A_+}`$$
$$`\hat{U}_{SA}(\ket{-}\otimes\ket{A_0}) = \ket{-}\otimes\ket{A_-}`$$

where $\ket{+},\ket{-}$ are the eigenstates of the Observable **of the system that the apparatus measures**, while $\ket{A_+},\ket{A_-}$ are two states of the apparatus, corresponding to two different orientation of the macroscopic indicator. 

Using the superposition principle, you get
$$`\hat{U}_{SA}(\alpha\ket{+}+\beta\ket{-})\otimes\ket{A_0} = \alpha\ket{+}\ket{A_+} + \beta\ket{-}\ket{A_-}`$$

In this way the interaction establishes a correlation (**entanglement**) between the basis of eigenstates of the operator we are measuring and an appartus' basis; so if you make a **projective** measure on the apparatus [**by reading the position of the macroscopic indicator**], you can conclude what is the state of the system.

The states $\ket{+},\ket{-}$ are orthogonal, as they are eigenstates corresponding to different eigenvalues. But also $\ket{A_+},\ket{A_-}$ are orthogonal because, in order for the apparatus to properly work, the two different orientation of the indicator must be **clearly different**.
_Naively_, this translates in a small overlap between the states $\ket{A_+},\ket{A_-}$, so we say that $\braket{A_+|A_-}\simeq 0$.
**To be precise**, this evolution is not abrupt, but it takes a **very short time** for the two apparatus states to become orthogonal as it **decays exponentially fast** [exponetially, because at the level of reduced density matrix, this is a **dephasing effect**; we'll see it].
[measure implies decoherence]

### Ambiguity
The above relation is very reasonable, but it has a **big problem**.

In fact, you can express the apparatus states as linear combinations of states of another basis of the apparatus
$$`\ket{A_\pm} = c_{\pm+}\ket{\tilde{A}_+} + c_{\pm-}\ket{\tilde{A}_-}`$$

Now, if you **consider the case where**
$$`\alpha C_{++} = \beta C_{-+} = 2^{-\frac12}`$$
$$`\alpha C_{+-} = -\beta C_{-+} = -2^{-\frac12}`$$

You end up with
$$`\ket{\Psi} = \ket{0}\ket{\tilde{A}_+} + \ket{1}\ket{\tilde{A}_-}`$$

So there is **even** an entanglement between the eigenstates of $\hat{S}_z$ and the apparatus states.
As we do not know what are the apparatus' states associated with the different orientations of the indicator (that's because we're making a **quantomehanical** description of a **macroscopic object**, so it is not clear how two connect the two things)
we see an **ambiguity**, in the sense that we **cannot tell** "anymore" **what is the Operator** measured by the apparatus.

From a different point of view, you can interpret this ambiguity as the ability of the system to measure both $S_{x}$ and $S_{z}$.
This brings to a problem not because the operator do not commute (we are not telling that the apparatus can measure "simultaneously" the two operators) but because **everyday experience** tells us that each apparatus measures a _specific operator_, it measure position **or** momentum, **not both**.

### Enviroment selection

But **this ambiguity is not real** as, in order for the apparatus to measure the **desired** operator, there are some properties that the apparatus has to satisfy. And those properties lead to constraints on the shape of the interaction, and **we expect** they remove the ambiguity.

In order for the apparatus to work properly, we **ask** that the entanglement between the system and the apparatus is **kept in time**. This means requiring that the entanglement **is solid** respect to the time when the _projective measure_ on the enviroment _happens_.
Formally the requirement is that, **during the interaction with the apparatus**, the composite system has this evolution

[For the moment we IGNORE the enviroment presence]
$$`\hat{U} (\ket{S_i}\ket{A_0})=e^{i\varphi_i(t)}\ket{S_i}\ket{A_i(t)}`$$

**Notice that** if this is the evolution of the composite system, then if we write the _most general state_

$$`\ket{\Psi} = \sum_i\alpha_i\ket{S_i}\ket{A_0}`$$

it evolves like

$$`\ket{\Psi}\rightarrow \sum_i \alpha_i e^{i\varphi(t)}\ket{S_i}\ket{A_i}`$$
where $\{\ket{A_i}\}$ are orthogonal (or precisely they became exponentially fast orthogonal).
So if you take the partial trace **over the apparatus**, you can trace out **over this basis** and so the **reduced matrix** you are left with, as the $\{\ket{S_i}\}$ are orthogonal, is diagonal with entries $\alpha_i^2$, that do not change in time.

So this shape of the evolution, **does not change in time** the **probabilities** of getting the different results by measuring the operator; and that is too a property we expect to hold.



So $\hat{U}$ commutes with every operator $\ket{S_i}\bra{S_i}$ and $\hat{U} = e^{-iH_{SA}t}$ as we assume that the interaction with the apparatus is 
- very localized in time
- and very strong, because it has to establish a strong entanglement in this small time; so we can neglect all other interactions

then we have
$$`[H_{AS}, \ket{S_i}\bra{S_I}] = 0\quad\forall i`$$

That means that it commutes with every linear combination $O_S = \sum_i O_i\ket{S_i}\bra{S_i}$, that is a _generic_ operator that is diagonal in the basis $\{\ket{S_i}\}$.

So this commutator relation puts a constraint on **which basis** (or equivalently which operator) the apparatus measures.
But it **is NOT sufficient** to determine **the basis** of the measure, as there could be more basis that satisfy this condition.
In fact this relation _simply tells that_ the entanglement is enstablished and mantained in time, but we saw before entanglement with more than one basis (basis ambiguity).
Anyway, there is an **additional constraint** that removes the ambiguity, that is a **constraint of the enviroment interaction**.

[In reality the basis can be a **common set** of eigenstates of more **commuting** operators. So you can measure many operators _at the same time_. This does not rise problems as they commute.]

We ask that the probability of measuring each state of the apparatus, that is entangled with a state of the system's basis **we're measuring**, is not affected by the interaction with the enviroment.

That means that the **projector of the apparatus basis** commutes with $H_{AE}$
[We assume that the measured system does not interact with the enviroment, so only the apparatus does. This is a _realistic assumption_, for example a superconducting qubit is usually coupled to a a resonator, that is coupled to an RF line. So there is **NO direct coupling** of the qubit with the RF line, the enviroment]

$$`[H_{AE}, P_A] = 0`$$

    So we found the TWO commutative relations that must be satisfied in an experimental setup in order for it to measure the desired observable of the system.

So **we managed to answer** to the original question about "How to build (form a purely theoretical point of view) an apparatus to measure a quantum operator" by presenting those two commutation relations.
Then, by putting **those constraints** (the commutation relation) we **expect** the basis ambiguity to disappear.

------

But this is a **naive** idea and, in addition, the previous reasoning is not rigorous, as we studied **separately** two interaction that are both present **on the same time**.

The rigorous reason why there is no ambiguity, is that until we consider only two systems (system and apparatus), then we can use the **Shmitz Decomposition theorem** to state that **every state**

$$`\sum_{ij} \alpha_{ij}\ket{S_i}\ket{S_j} = \sum_k \tilde{\alpha}_k \ket{S_k}\ket{\tilde{A}_k}`$$
**always** as an entangled state and the decomposition **is not necessarly unique**.

But, **when we consider a 3rd system (the rest of the world)** then the theorem does not hold anymore.
What happens now is that a decomposition is no more granted but, **if it exists it is unique** [tridecompositional uniqueness theorem]

So the rigorous reason is a **purely mathematical statement** and shows the importance of considering the **rest of the world** in the state of the composite system, in order for the apparent ambiguity to disappear.
For this reason, the removal of the ambguity is called "Enviroment induced superselection", because it is the enviroment that selects **ONE** basis of the system (the measured one).
[We expect this is the same basis where the reduced density matrix obtained by tracing out the rest of the world gdls gets diagonal in time. But I don't know how tho proove this, we should get in the proof of the mathematical theorem in 3D]

This **SPECIAL unique** basis of the system (or **equivalently** the entangled one of the apparatus) is called **pointer basis**.
The idea of the name is that usually the entangled apparatus basis is thought as the state of the apparatus associated with different orientations of a macroscopic pointer.

-----------------------------

[The other path (not the Generalized Shmitz theorem) we followed is not rigorous, but was worth to follow as it gave an answer to our original question!

You can argue that the answer may be wrong because the path followed is not rigorous, but I say that, unless the fact that _we considered separately the different interactions_, all the considerations are very reasonable and, in addition, **the final result we get is reasonable!**.

In fact, if you want to measure the position of a particle, you will exploit an interaction mechanism of the particle with other bodies (like coulomb interaction).
And those interactions are functions of **only** position so they commute with the observed quantity (position).]

[Unfortunately, I could not find any way of expaining why the apparatus states became rapidly orthogonal.
It is very simple to show that measure implies dephasing and so orthogonality of those states (because you have to be able to distinguish them clearly!).
But this does not explain WHY it happens...
]


## The measure problem
Notice that we did not explained "how quantum measure works", but just "how to build the apparatus to perform a measure".

In fact we still rely on the postulate of quantum measurement, as we still need to perform a **projective measurement** on the apparatus to get information about the state of the system.
We just moved **the problem of measurement** from the system to the apparatus.
**How** a projective measure takes place (that is what we call **wave-function collapse**) remains still something mysterious.