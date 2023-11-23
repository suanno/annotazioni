# Introduzione su 'Distributed' and 'Shared' memory
- In un sistema 'distributed-memory' ogni core ha la SUA memoria. Esiste quindi un problema di trasferire informazione tra i processi, che avviene mediante comunicazione fra i processi che viene gestita da opportune funzioni "send", "receive", oppure funzioni di 'comunicazione collettiva' come 'broadcast' (che comunque utilizzano dentro di loro funzioni di comunicazioni semplici, ma l'informazione viene propagata seguendo dei "diagrammi efficenti").
MPI è la libreria che consente di fare parallel computing assegnando ad ogni core la sua zona di memoria.
- In un sistema 'shared-memory' tutti i core condividono la stessa memoria, quindi non c'è bisogno di comunicare tra i core (un grosso problema in meno a livello di implementazione).
OpenMPI è la libreria che consente di fare shared memory parallel computing.

[OpenMPI è un modo di programmare a livello più alto di MPI (non so se la memoria condivisa vada virtualizzata per essere usata, ma in tal caso questo è il motivo per cui è più alto]

Siccome lavorando in un sistema 'shared memory' non devo farmi problemi legati alla comunicazione fra core (che è un GROSSO problema), con una 'shared' anziché 'distributed' memory è più facile parallelizzare un codice seriale (convetire/tradurre).
Mentre in un sistema 'distributed memory' devo proprio ripensare a come risolvere il problema affinché giri in parallelo (non è fattibile tradurre un codice seriale)

IO penserò SEMPRE ad un sistema 'shared memory'.
