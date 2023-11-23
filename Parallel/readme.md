# Guide
IO penserò SEMPRE ad un sistema 'shared memory', perché così non mi devo fare problemi sulla comunicazione tra core (che è pallosa da implementare ed inoltre le sue routine hanno un costo computazionale non trascurabile (si pensi al xotto mat x vec)).

Pensando di avere una memoria condivisa, piuttosto che una distribuita, è quindi più semplice "tradurre" un codice seriale in un codice parallelo.

## Tasks
- Foster's metodology: da P.66 in poi, anche l'esempio
- OpenMPI (come implementare parallel in shared memory sistem): Cap 5 (P. 209)
- Simulate n-bodies interacting: Cap 6 (P. 271)
- Taking times: 2.6.4 (P. 63)
