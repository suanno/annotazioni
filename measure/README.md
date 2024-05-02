# Introduction: Problems of the standard interpretation of quantum mechanics
Before getting into the topic of my presentation, let's make **a few CONSIDERATIONS** about **measure in quantum mechanics** 

- There is a problem of **incompatibility** among postulates.
The isolated systems have unitary (so continuos) evolution,
But when we make a measurement, the state of the system **collapses istantaneously** on an eigenstate and this process is **not continuos**.
- Then, as the measure is a concept **defined in the postulates** (the measure is defined as a projection of the state on a subspace), it is not clear
    - **How** a projective measure works and **when** it happens **during an experiment**
    - What means from an **experimental** point of view **measure an Operator $\hat{O}$**. 

Today we'll not solve this fundamental problem of quantum mechanics, but we'll present a description of quantum measurement that **at least**
- Explains how to **experimentally measure an Operator** (from a purely theoretical view)
- And manages to explain **operatively** the results of an experiment **avoiding** the concept of **projective** measure

So we **will NOT question** about what happens to the state of the universe when you perform a quantum measure

This question is accounted as "the problem of measure" and we can find anwers only considering **interpretations** of quantum mechanics.

But this is a more phylosopical problem so I will not speak about it.

# How should we build the apparatus to measure a Quantum Observable $\hat{O}$?

The way we answer to this question is to **think** a measure in quantum mechanics **as a** process where a measuring apparatus interacts with the measured system.
We will **ask some reasonable properties** that the apparatus must satisfy in order to **correctly measure the desired observable** AND this will **lead to** some **constraints** on the **form** of the **interaction** between the system and the apparatus.
We can then **read those constraints** as **the way we should design** the apparatus in order to measure an operator.

**But in order to** find those constraints, we have to **show concretely** HOW we deal with the measure concept in the theory, and we'll do this with an example

## Example: Measuring the spin of a qubit

### Premeasurement
### Ambiguity
### Enviroment selection

So our answer to the first question is that: in order for the apparatus **to do its job** the above conditions on the interaction hamiltonians $H_{AS}$ and $H_{AE}$ must be fullfilled. 

## The measure problem
Notice that we did not explained "how quantum measure works", but just "how to build the apparatus to perform a measure".
In fact we still rely to the postulate of quantum measurement, as we still need to perform a **projective measurement** on the apparatus.
We just moved the problem of measurement from the sys to the apparatus.
How a projective measure takes place is still something mysterious.


# How we can avoid talking about projective measure and explain (operatively) the results of an experiment?
We can do so, by describing the interaction with the Apparatus _at the level of_ **density matrix**.

## Example: Double Stern-Gerlach setup
Let's consider to **prepare** particles in an even superposition
$$\ket{\Psi_0} = \frac{\ket{+}+\ket{-}}{2}$$
The particles pass through a stern-gerlach apparatus, after which we have other two stern-gerlach apparatus operating _in reverse_.



But we have talked about **projective measurement** that is a concept we're trying to **work around**.
Now I'll show that this effect, **at the level of denisty matrix**, can be implementing without recurring to this concept, by properly tuning the interaction between the system (particle) and the apparatus (entity supposed to measure the path; the stern gerlachs are the rest of the enviroment)

The idea is that we saw how the interaction with the apparatus entangles the system's states of the **pointer basis** to some orthogonal apparatus states.
So if you consider the reduced density matrix ...
you find that **it is diagonal in the pointer basis**.
So we simply need to tune the interaction hamiltonian in a way that the pointer basis is $\ket{+}, \ket{-}$ and we have already seen how to do so **in general**.

So we have seen that, **at the level of the reduced density matrix**, the effect of a projective measure can be reproduced by a proper interaction hamiltonian with the apparatus; so **avoiding** the **unconfortable** concept of projective measure.

This is a relevant result, in fact the reduced density matrix has less information than the one contained in the state of the universe, but it contains ALL the information that can be extracted by making a measurement on the system.
So managing to avoid the concept of projective measure at the level of the reduced density matrix, means being able to **explain the results of experiments** without recurring to this unconfortable concept.



# Suitable extras
- Measure implies dephasing of the reduced density matrix
- Entropy of entanglement: a quantitative thing to find the pointer basis (stability criterion)
- Shmitz theorem idea of why it holds in 2D but not in 3D
- Usually apparatus measure position of the system (particle) and tipically interaction between particles depend on position. So the condition on $H_{SA}$ is not so obscure or abstract.