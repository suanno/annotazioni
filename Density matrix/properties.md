# Lista da implementare
- Traccia 1
- Purezza dello stato, traccia $\rho^2$
- Rappresentazione come vettore dentro la sfera di bloch
- Dinamica di $\rho$
- Statistica delle misure è contenuta sulla diagonale di $\rho$ se rappresentata nella base degli autostati dell'operatore misurato
- Traccia parziale come stato del sistema dal punto di vista di un solo sottosistema (ovvero tutta la info che posso estrarre facendo misure SOLO sul sosttosistema, esempio 2 elettroni nello stato EPR)

- Differenza tra meccanica classica e quantistica :
    - Sperimentale: Esperimento di interferenza. Tante particelle in uno stato di sovrapposizione manifestano una **fisica diversa** rispetto ad una **mixture classica**(prob. classiche).
    - Teorica: Prob classiche sono una **certezza** sulla statistica dei campioni. Se prendo una particella **so** che **E'** 40% up oppure **E'** 60% down **già prima della misura**. Quelle quantistiche mi dicono che, **solo DOPO AVER fatto** la misura, la particella **sarà** 40 up o 60 down.  

# Statistics of any Operator $\hat{O}$ measure from $\rho$
$\rho = \sum_n P_n \ket{\Psi_n}\bra{\Psi_n}$
we can express this matrix in the basis of eigenstates $\{\ket{j}\}$ of an operator $\hat{O}$, so $\rho = \sum_j c_j \ket{j}\bra{j}$.

Now the states showing up in the $\rho$ expression are **orthogonal** _eigenstates_ of $\hat{O}$. This means that the probability of finding the system in the state $\ket{j}$ with a measure of $\hat{O}$ is simply the "classical probability" $|c_j|^2$ showing up in the $\rho$ expression (In general the states $\ket{\Psi_n}$ are non-orthogonal linear combinations of eigenstates of $\hat{O}$, so you have both classical and quantum probabilities. So in general that is not obvious, but in this case we have **just classical** probabilities!). Note that $c_j = \bra{j} \hat{O} \ket{j}$.

So the statistics of a measure of $\hat{O}$ is **fully contained** in the diagonal of the matrix representation of $\rho$ in the basis of eigenstates of $\hat{O}$.

### + Calculating $\braket{O} $ as $ Tr(\rho\hat{O})$
$\braket{O} = \sum_j c_jo_j$ where $\hat{O}\ket{j} = o_j\ket{j}$.

Now consider $Tr(\rho \hat{O}) = \sum_j \bra{j}\rho\hat{O}\ket{j}$ and expliciting $\rho = \sum_j c_{j'} \ket{j'}\bra{j'}$, you find out
$$\rho = \sum_j \bra{j} \sum_{j'}c_{j'}\ket{j'}\bra{j'}\hat{O}\ket{j}$$
Using $\bra{j}\ket{j'}=\delta_{j,j'}$ we eliminate the sum over $j'$ evaluating $j'=j$ and so $\rho = \sum_j c_j\bra{j}\hat{O}\ket{j} = \sum_j c_jo_j$.
So $Tr(\rho\hat{O}) = \braket{\hat{O}}$.

# Trace
- $Tr(\rho) = 1$
- $Tr(\rho^2) \leq 1$
And we can understand if the state is mixed from the trace, because it is $=1$ only if the state is pure.

