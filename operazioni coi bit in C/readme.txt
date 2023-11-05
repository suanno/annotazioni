Operatore ">>"
"x >> 1" significa che prendo la rappresentazione binaria di x e la shifto a sinistra di 1.

Operatore "&"
E' un AND BITWISE. Considera le rappresentazioni Binarie dei due INTERI a destra e sinistra e restituisce un intero che ha come rappresentazione binaria l'AND BITWISE.
e.g.: 3(011) & 6(110) = 2(010) (ciò che restituisce è l'intero, non la rappresentazione binaria, quindi 2).

Se facccio "x & 1", siccome la sua rappresentazione di 1 è 000...0001, allora ottengo 1 (0...01) se l'ULTIMO bit di x è 1, mentre 0 (0...00) altrimenti.
In questo modo posso leggere bit per bit un intero così:

for (int i=0; i < sizeof(int)*8; i++){
	printf("Bit %d-esimo da dx: %d", i, x & 1);
	x = x >> 1;
}

"sizeof" restituisce il numero di byte, non di bit!
