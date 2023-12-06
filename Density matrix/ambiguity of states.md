# Multiple mixtures for the same $\rho$
- If you _manage to_ prepare the system in a **pure** state $\ket{\Psi}$, then the density matrix is $\rho = \ket{\Psi}\bra{\Psi}$, so there is a _bijective_ relation between the state $\ket{\Psi}$ and the density matrix $\rho$.

- Indeed, if you cannot prepare the system in a pure state, or for any reason the system is in a **mixed** state, then $\rho = \sum_n P_n\ket{\Psi_n}\bra{\Psi_n}$ and there are multiple mixed states (even called mixtures) that give the **same** density matrix $\rho$. 

    For example, if you _diagonalize_ $\rho$, getting the eigenvectors $\{\ket{k}\}$ with eigenvalues $\{\rho_k\}$, then you can write $\rho = \sum_k \rho_k\ket{k}\bra{k}$. So you have two ways of writing $\rho$ and so two, in principle different, mixed states that give the same density matrix $\rho$.

    As many mixed states correspond to the same $\rho$, it means that you **loose information about the state** of the system, when you start describing the state of the system with its density matrix.

    In order for the density matrix to be a good tool for describing the state of the system, this loss of information **must be non relevant** for any purpose, so in any experiment that you can make.

### Why it makes sense working with the density matrix, even if it contains LESS information than the state?
**Take it for grant (Zaffaroni)**: 
- The density matrix describes how the system behaves in **any** experiment.
- It contains **all** the information you can extract from the system when you perform any quantum measurement, even if the observed quantity is not represented by an hermitian operator (e.g. Ahranov Bohm).

So we can, during any experiment, _focus on_ the density matrix, instead on the state. This means that the information that you loose about the system is _irrelevant for any purpose_. But what is the information you loose by considering the density matrix?

### The lost information about the state
When you _prepare_ the system in a state (mixed or pure), you follow a **procedure** set (or at least **you know**, otherwise it makes no sense using the term "preparing") the states of the mixture $\ket{\Psi_n}$ and their classical(einsemble) probabilities $P_n$.

If someone has access to multiple copyes of the system prepared in the above state, through some measurements he can recover some information about the state of the system, **but no more** than the one contained in the density matrix (because it contains all the information you can extract through measurements).

So the second person (and thus the **density matrix) knows** 
- sufficient information on the system's state to predict how the system will behave in any experiment,
- but he has no clue on the **procedure** followed to prepare it.

This is the information you loose when you **switch** _from the state to the density matrix_ and you can recognize that its irrelevant for any purpose.

### Time evolution
As a result of the above discussion, we can state that **$\rho$ is the state** of the system (describes completely the state, in spite of some irrelevant information, so we say that **it is** the state).

The fact that not only the state, but even the density matrix has a definite time evolution, _is coherent_ with the fact that we can account $\rho$ as the system's state.

**von Neumann equation**
$$i\hbar\frac{d\rho}{dt} = [H,\rho]$$
**Note**: Even if this equation seems similar to Ehrenfest's theorem, here there are no expectation values! It is similar to the Heisemberg's picture analogue of Ehrenfest's theorem, that is an equation describing how the Heisenberg's picture operators evolve in time. But here we are in the Shrodinger equation, so it is not the case and there are no analogies.