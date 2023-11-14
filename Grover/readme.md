# Grover algorithm
It's an algorithm for quantum computers that searches a _particular object_ in a _database_ with a complexity that is $O(\sqrt(N))$, while classical computers need $O(n)$ operations.

$N$ is the number of objects in the database and it's equal to the number of qubits.

Here we discuss:
- Grover oscillations: The Grover algorithm, differently from what you expect from a searching algorithm, _does not converge_.
In fact, you need to iterate its routine ($GO$ operator application) around **and not over** $\frac{\pi}{4}\sqrt{N}$ times. If you apply this number of routines _twice_, then you are barely sure to find an object different from the one you are looking for.

Here we verify (and the test is positive) this behaviour.