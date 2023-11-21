# Schror's 9 qubits error correction algorithm
Here we implement the error correction algorithm and we look if it works with a State where there happened a **general continuos error**.

Now the state of the system is no more an eigenstate of the stabilizers (it is so only if there is a bit-flip OR phase-flip OR bit-phase-flip OR no error, not if it is a continuos superposition of those simple errors).
So the wave-function collapses (in a state different from itself), when a stabilizer is measured!