# Intro
Oggi voglio presentare il ruolo che il _rumore_ gioca nella misura dello stato di un qubit superconduttivo.

Inizio presentando alcuni strumenti matematici con cui si descrive il rumore nei sistemi fisici, cercando di portare l'attenzione sul loro significato fisico e pratico piuttosto che sui conti.

In seguito considererò il caso specifico della misura di un qubit superconduttivo, introducendo i concetti di _misura lenta_ e di misura _quantum non demolition_.
Infine mostrerò che queste misure hanno un limite, imposto dal principio di indeterminazione.

# Rumore
Per introdurre gli strumenti con cui descrivere il rumore in un sistema fisico, consideriamo un _semplice esempio_:

In un circuito elettrico, l'interazione del circuito con l'ambiente può essere _ragionevolmente_ descritta introducendo nel circuito una **sorgente di rumore**, rappresentata da un _generatore di corrente fittizio_.
Qui lo mostriamo in serie all'impedenza del circuito, che qui è una resistenza per semplicità.

[Circuito Noise I source in serie resistenza]

Siccome è una sorgente di rumore, la corrente $I(t)$ ad ogni istante è una realizzazione di una **variabile aleatoria**, la cui media statistica $<I(t)> = 0$.

Definiamo il correlatore tra la corrente a due tempi diversi come
$$G_{II}(t,t') = <I(t)I(t')>$$
Quale è il significato fisico di questo oggetto?
- Se due variabili aleatorie $x,y$ sono indipendenti, allora $<xy> = 0$.
- Se $t = t'$, allora recupero la definizione di **varianza** di $I(t)$.
Ora consideriamo il caso speciale in cui uno dei due tempi è 0 e definiamo così l'autocorrelazione
$$R_{I}(t) = <I(t)I(0)>$$

Ed infine definiamo il **noise power spectrum** associato alla corrente $I(t)$ come la **trasformata di Fourier dell'autocorrelazione**, ovvero

$$S_{II}(\omega) = \int_{-\infty}^{\infty}dt e^{-i\omega t}<I(t)I(0)>$$

Questa grandezza descrive il rumore sulla corrente, che emerge quando la misuro. Per vederlo, presento **due interpretazioni** del noise power spectrum.

### 1) Potenza del rumore
Consideriamo il circuito di prima, la potenza _istantanea_ dissipata nella resistenza (e quindi quella **trasferita** dalla sorgente di rumore all'impedenza) è $P(t) = RI^2$.
Se invece calcoliamo la potenza _media_ su un intervallo di tempo $T$, allora questa è $\bar{P}=\frac1T\int_0^Tdt I^2(t)$ (media integrale).

Nel limite in cui l'intervallo di tempo $T$ è molto lungo, è possibile sostituire la media temporale con una media statistica e se scelgo $R=1$ per avere un risultato indipendente da R (equivale a dividere per $R$), ottengo che
$$\bar{P} = \int_{-\infty}^{\infty}S_{II}(\omega)d\omega$$

Questa relazione mi permette di **interpretare** $S(\omega)d\omega$ come la Potenza media trasferita dalla sorgente di rumore al sistema, "alla frequenza $\omega$", _ovvero con segnali_ generati dalla sorgente di rumore di frequenza nell'intervallo [$\omega, \omega+d\omega$].

_Informalmente_, questa interpretazione viene presentata dicendo che "lo spettro $S(\omega)$ ci dice quali frequenze costituiscono il rumore", ma sopra l'ho detto in modo esplicito.

### 2) Varianza di $I(t)$
La varianza della r.v. $I(t)$ è per definizione $$\sigma_{I(t)}^2 = <I^2(t)>$$ (perché $<I(t)>=0$).
Se assumiamo che il rumore sia stazionario, ovvero che la varianza di $I(t)$ non dipenda dal tempo

[Mostrare foto distr. punti che mostra cosa significa **in pratica** che sigma non dipende da t]

questo significa che $\sigma_{I(t)}^2=\sigma_{I(0)}^2=<I(0)I(0)> = R_{I}(0)$.
Usando che l'autocorrelazione è la _trasformata di Fourier inversa_ di $S(\omega)$, segue che
$$\sigma_I^2 = \frac{1}{2\pi}\int_{-\infty}^{\infty}d\omega S_{II}(\omega)$$
per ogni tempo $t$.

Osserviamo che, fino a questo momento, abbiamo considerato $I(t)$ come la corrente generata dalla sorgente di rumore. In generale questa è sovrapposta al segnale che vogliamo misurare, infatti l'espressione generale di una osservabile è
$$I(t) = <I(t)> + \text{Noise}$$
Siccome il rumore ha media statistica nulla, allora il segnale che vogliamo misurare è la media statistica. Per calcolare $S(\omega)$ bisogna quindi sottrarre dall'osservabile la sua media statistica
$$I(t) \rightarrow I(t)-<I(t)>$$

Quindi abbiamo trovato un'altra interpretazione del noise power spectrum. E' ragionevole che le due interpretazioni coesistano, perché la presenza di una varianza è causata dall'interazione con la sorgente di rumore **e quindi** dal fatto che ci sia un **trasferimento di energia** tra il sistema e l'ambiente. Più questa interazione è forte e più mi aspetto che la varianza sia grande. Bisogna però dire che, nonostante ci aspettiamo che per **tutte le osservabili** il noise power spectrum **descriva in qualche modo** la potenza che l'ambiente trasferisce al sistema ad una certa frequenza, non sembre questa potenza trasmessa coincide con il noise power spectrum. Per alcune osservabili questa proprietà è descritta esplicitamente, per altre no, ma comunque l'informazione ci aspettiamo sia presente, in qualche modo.

Osserviamo poi che, in pratica, si lavora con circuiti in cui sono presenti dei filtri (e.g. Passabasso che filtrano le frequenze $\omega > \omega_{max}$).
Siccome $S(\omega)d\omega$ rappresenta la potenza trasmessa al sistema alla frequenza $\omega$ e le frequenze superiori ad $\omega_{max}$ non si possono trasmettere, allora devo _modificare gli estremi di integrazione_ ($+\infty \rightarrow \omega_{max}$).

Consideriamo ora la corrente integrata nel tempo, questa grandezza ci tornerà utile più tardi quando parleremo di come si misura sperimentalmente lo stato di un qubit superconduttivo.
$$m(T) = \int_0^T I(t)dt$$
Considerando $I(t)$ come _la sola parte rumorosa_ della corrente (abbiamo detto che questa è la parte da considerare per calcolare la varianza), si ha che $<I(t)> = 0$ e quindi $<m(T)> = 0$. Di conseguenza è possibile calcolare la varianza di $m(T)$ come
$$<m^2(T)> = \int_{-\infty}^{\infty}d\omega \frac{S_{II}(\omega)}{\omega^2}(1-cos(\omega T))\sim S_{II}(\omega = 0)*T$$
dove il limite è valido per tempi T grandi.

Il tempo $T$ è il tempo trascorso da quando ho iniziato a raccogliere le misure della corrente per calcolare (uno stimatore di) m(T); quindi è la **durata della misura**. L'idea intuitiva secondo la quale **solo** il valore di $S(\omega)$ ad $\omega = 0$ è rilevante nel calcolo della varianza di $m(T)$ è questa:

Se scompongo il rumore come una somma di segnali periodici con frequenze differenti, $S(\omega)$ mi da informazioni sull'intensità della componente del rumore di frequenza $\omega$ (questo è vero per le considerazioni fatte sulla interpretazione di $S(\omega)$ come "potenza del rumore"). Integrando le componenti di frequenza alta (quindi periodo piccolo) nel tempo, quando il tempo di misura $T$ supera il periodo del segnale, **tale somma fa zero**.
Questa idea è sostenuta dal fatto che l'integranda diventa piccata in $\omega = 0$ al crescere della durata della misura.

[Grafico]

Prima di generalizzare questi concetti in meccanica quantistica, voglio evidenziare che l'ultimo risultato ottenuto (_espressione della_ varianza della corrente integrata) è coerente con il TCL.

Dalla corrente integrata è possibile calcolare la media temporale della corrente come _media integrale_ $\bar{I}(T) = \frac{<m(T)>}{T}$ e la varianza sulla media va come $\sim \frac{T}{T^2}=\frac{1}{T}$ (quadrato perché quando calcolo $<m^2>$ ho un quadrato).
In altri termini troviamo che la deviazione standard della media va come $\frac{1}{\sqrt{T}}$, che è quando afferma il TCL.

Tuttavia nelle ipotesi del TCL viene chiesto che le variabili aleatrorie $I(t)$ a tempi diversi siano **indipendenti**, mentre qui non lo sono. Però la correlazione tra valori della corrente a tempi diversi, è descritta dall'autocorrelazione $R_I(t)$ che decade esponenzialmente nel tempo in un tempo che è il **tempo di decorrelazione**.
Quindi l'analogia con il TCL **suggerisce che** è che l'approssmazione $\sigma_{m(T)}^2\sim S(\omega = 0)*T$ sia valida per tempi $T$ grandi _rispetto al tempo di decorrelazione_, che di solito è molto più piccolo del tempo di misura (basta aspettare a sufficienza).
Quindi, in ogni esperimento, possiamo dire che la varianza della corrente integrata è **governata solamente dal** noise power spectrum **alla frequenza $\omega = 0$**.

## Rumore in meccanica quantistica
Il modo **più naturale** di generalizzare la definizione di noise power spectrum in meccanica quantistica è sostituire le osservabili classiche con il corrispondente operatore nella picture **di Heisemberg**. Si sceglie questa picture perché **mantiene** la dipendenza dal tempo nelle osservabili.
Inoltre le medie statistiche vengono sostituite dalla traccia della matrice densità moltiplicata per l'osservabile.

#### Medie statistiche
Facciamo ora una veloce considerazione sul significato di queste medie statistiche. Nel tempo il sistema interagisce con l'ambiente (che prima abbiamo modellizzato con la "sorgente di rumore"). L'interazione con l'ambiente introduce delle probabilità di transizione fra gli stati del sistema (che in linea di principio si possono calcolare usando la regola d'oro e l'hamiltoniana di interazione del sistema con l'ambiente). Perciò, occasionalmente, il sistema transisce in un altro stato e le probabilità contenute nella matrice densità descrivono la frazione di tempo di soggiorno del sistema in ciascuno stato (su un tempo molto lungo).
Dunque la matrice densità descrive l'interazione con l'ambiente (per fare questa considerazione abbiamo implicitamente pensato nella picture di Shrodinger perché qui è più chiaro cosa succede, ma l'idea è questa).
Un'ultima nota che è importante fare sulle medie statistiche è che la probabilità che associo ad ogni stato all'interno della matrice densità è la _probabilità canonica_ **solo all'equilibrio termodinamico**. Quando si fa computazione quantistica tuttavia si lavora in condizioni molto lontane dall'equilibrio termodinamico, perché la misura viene fatta _subito dopo_ aver preparato "ed elaborato" lo stato del qubit. Questo perché è necessario che la misura disti dalla preparazione un tempo piccolo rispetto al tempo di decadimento.
Quindi, anche se apparentemente queste medie statistiche sembra che ci permettano di studiare l'interazione con l'ambiente in modo semplice, in realtà la complessità di questa interazione si nasconde nella forma della matrice densità.

**Per ricorrere alle interpretazioni** discusse prima, bisogna però **individuare l'analogo** in meccanica quantistica del noise power spectrum classico (non è ovvio che sia il noise power spectrum quantistico e **non lo è**! (a meno che non si faccia un limite classico, ovvero $k_bT >> \hbar\omega$, dove le due quantità coincidono)).
Lo facciamo _con un esempio_, considerando un oscillatore armonico e calcolando il noise power spectrum _della posizione_ sia classicamente che in MQ.

#### Oscillatore armonico
Classicamente, all'equilibrio termodinamico, $S_{xx}(\omega) = \frac{k_bT}{M\Omega^2}[\delta(\omega-\Omega)+\delta(\omega+\Omega)]$ dove $\Omega$ ed M sono la frequenza e la massa dell'oscillatore.

Invece, in meccanica quantistica (sempre all'equilibrio termodinamico), si ottiene una espressione diversa, per due motivi:
- Mentre _classicamente_ posizione e momento sono variabili aleatorie indipendenti, dunque scorrelate: $<x(t)p(t)>=0$; in MQ $<\hat{x}\hat{p}>=i\hbar/2$ perché $\hat{a},\hat{a^+}$ (o equivalentemente $x,p$) non commutano.
- Classicamente $<x^2> \sim k_bT$ per il principio di equipartizione, mentre in meccanica quantistica non è nullo a $T=0$, perchè a temperatura nulla lo stato è _certamente nel GS_, ma il valore di aspettazione di $x^2$ sul GS è la ZPF che non è zero (e non dipende dal tempo).
$$S_{xx}(\omega) = x_{ZPF}^2\{n_{BE}(\hbar\omega)\delta(\Omega+\omega)+[n_{BE}+1]\delta(\Omega-\omega)\}$$

Osserviamo la presenza dei termini BE e BE+1. Questi termini compaiono nei rate di assorbimento o emissione di un fotone quando si descrive un **gas di fotoni** che interagisce con un sistema atomico. Qui invece abbiamo un oscillatore armonico (le cui eccitazioni sono bosoni e quindi è descrivibile come un gas di bosoni) che interagisce con una sorgente di rumore (ovvero l'ambiente).

Queste analogie ci **suggeriscono** che il noise power spectrum _in meccanica quantistica_ descriva **le probabilità di transizione del sistema** da uno stato ad un altro **stimolate dall'ambiente** (che comportano lo scambio di un pacchetto di energia di frequenza $\Omega$ con l'ambiente).
Dunque, a differenza del caso classico in cui questo oggetto ci da informazioni sulla potenza **netta** trasferita dall'ambiente al sistema, in MQ ho una **informazione maggiore**: sia su quella trasferità in una direzione con meccanismi di assorbimento, che nell'altra con emissione.
Bisogna comunque dire che classicamente l'energia viene scambiata in modo continuo e quindi in quel caso non si può parlare di energia assorbita o emessa separatamente.
Inoltre, all'equilibrio termodinamico le due delta sono moltiplicate dallo stesso coefficiente, ma siccome fuori dall'equilibrio non mi aspetto che ci sia un bilancio dettagliato tra i rate di emissione ed assorbimento, i coefficienti moltiplicativi saranno diversi (**non avrò questa simmetria** nell'espressione del noise power spectrum).

Ma quale è l'analogo del noise power spectrum classico? Quale è quella grandezza che quantifica la varianza che si manifesta nelle misure?

Non può essere $S(\omega)$ perché, nonostante facendo un limite classico fornisca l'espressione calcolata classicamente, la sua asimmetria è in contrasto con l'interpretazione di $S_{II}(\omega)d\omega$ come potenza scambiata tra l'ambiente ed il sistema alla frequenza (c'è una ambiguità sul considerare $S(\omega)$ oppure $S(-\omega)$, che sono valori diversi!).
Dunque è naturale considerare il noise power spectrum **simmetrizzato** il quale coincide con l'espressione classica nel limite di alte temperature, perché in questo limite l'asimmetria scompare.
E' una idea naive, ma esistono dimostrazioni rigorose sul fatto che l'analogo del noise power spectrum classico sia questo.

## Misura dello stato di un qubit superconduttivo
Sperimentalmente lo stato di un qubit superconduttivo si misura così...

Quindi, **assumendo che** l'ampiezza della corrente DC **coincida con** lo sfasamento dell'onda
$$I(t) = \pm \theta_0 + \delta\theta(t)$$
dove $\delta\theta(t)$ è il rumore sulla fase dell'onda (che discuteremo a breve), e $\pm$ rappresenta lo stato del qubit. Quindi _il valor medio_ della corrente DC contiene l'informazione sullo stato del qubit.

In pratica però non si misura semplicemente il valore della corrente ad un solo istante, ma il valore della corrente integrato nel tempo (è come contare tutti gli elettroni che passano fino ad un certo tempo t).
Il motivo per cui si sceglie di fare una misura di questo tipo, ovvero prolungata nel tempo, è che, come abbiamo visto in precedenza, la sua varianza cresce linearmente nel tempo $\sigma_m^2\sim t$, così come **la separazione** tra i valori della media di $m(t)$ per i due diversi stati del qubit $<m(t)> \sim \pm I_0t$ .
Questo ci consente di **distinguere chiaramente** quale sia lo stato del qubit se aspettiamo sufficientemente a lungo, infatti possiamo definire un **coefficiente di risoluzione**:
$$\eta = \frac{|<m(t)>_+-<m(t)>_-|^2}{\sigma_m^2(t)}\sim t$$
quindi la risoluzione **cresce nel tempo** (vantaggio di misure lente) e possiamo definire **la durata della misura** come il tempo da aspettare per riuscire a distinguere chiaramente tra i due stati (e.g. $\eta = 1$).

Siccome $\sigma_m^2 = S_{\theta\theta}(\omega = 0)t$, allora:
$$\Gamma_{measure} = \frac{4\theta_0^2}{S_{\theta\theta}}$$

Abbiamo presentato il vantaggio che si presenta se si fanno misure lente, ora cerchiamo di capire se ci sono anche degli svantaggi.

## Backaction
E' ragionevole che fare una misura lenta (ovvero non istantanea, ma prolungata nel tempo) sia equivalente a fare tante misure istantanee molto vicine nel tempo.
Tuttavia il principio di indeterminazione ci dice che se misuro un'osservabile $x$ con una precisione $\Delta x$, allora avrò una **variazione ignota** dell'osservabile coniugata $p$ che è $\Delta p \geq \hbar/(2\Delta x)$ (ignota perché non conosco il suo valore, ma solo questa disuguaglianza).

Se faccio _una sola_ misura istantanea, questo effetto collaterale della misura (_backaction_) non mi da fastidio. Tuttavia, quando faccio una misura lenta, io faccio tante misure _successive_ e sarebbe un problema se la variazione ignota dell'osservabile coniugata si ripercuotesse **sui valori futuri** dell'osservabile misurata!
Facciamo un esempio:

- Se misuro il momento di una particella libera _con una misura lenta_, le variazioni ignote della posizione non sono un problema, perché il momento è una costante del moto ed i suoi valori futuri non sono influenzati dalle variazioni della posizione.
- Se, invece, misuro la posizione, allora le _variazioni incontrollabili_ del momento influenzano i valori futuri della posizione, producendo **una traiettoria imprevedibile** se conosco solo la posizione iniziale! Dunque l'informazione sulla posizione iniziale (**che volevo misurare**) è **persa**!  

Le misure lente in cui l'evoluzione dell'osservabile coniugata non dipende da queste variazioni incontrollabili dell'osservabile coniugata, si chiamano QND (Quantum non demolition).
In queste misure, più tempo aspetto e migliore è la risoluzione della misura.
Se, invece, la misura non è QND, allora non posso far durare la misura un tempo troppo lungo, altrimenti perdo l'informazione che voglio ottenere dalla misura.

La misura dello stato di un qubit superconduttivo è QND, perché le osservabili coniugate a $\sigma z$ sono $\sigma x, \sigma y$, e la probabilità di misurare $\sigma z = 0,1$ **non dipende** dai valori di $\sigma x, \sigma y$.

Più esplicitamente, pensando alla sfera di Bloch, l'accoppiamento con la cavità modifica solo la frequenza della precessione attorno a z, ma l'evoluzione dello stato resta una semplice precessione attorno a z, dunque le probabilità di misurare up o down non cambiano nel tempo.
La variazione della frequenza è però
$$\Delta \omega(t) = \omega_c + \chi + 2\chi \hat{n}$$
Dove è presente del rumore su $\hat{n}$, dovuto al fatto che è possibile uno scambio di fotoni tra la cavità e l'ambiente (che in questo caso è la linea di trasmissione accoppiata) e quindi $n$ fluttua.
Se scriviamo $n(t) = <n> + \delta n(t)$, allora l'evoluzione dell'angolo $\varphi$ nella sfera di Bloch è
$$\varphi(t)=\varphi_0 + (\omega_c + \chi + 2\chi<n>)t + 2\chi\int_0^t dt' \delta n(t')$$
Mentre il primo termine fornisce una evoluzione che è diversa da quella che avrei senza la cavità, ma è comunque **prevedibile**, dunque **conserva l'informazione** sul valore iniziale $\varphi_0$, il secondo termine fornisce una evoluzione incontrollabile che, dopo un po', porta ad una totale indeterminazione della fase. 
Se misuro $\varphi(t)$ nei primi istanti, riesco _almeno_ a ricavare che $\varphi_0$ si trova in un certo intervallo. Ma mano a mano che passa il tempo, questo intervallo si ingrandisce e quando la sua lunghezza raggiunge $2\pi$, l'informazione su $\varphi_0$ è completamente persa.

Siccome l'angolo $\varphi_0$ descrive la _sovrapposizione_ degli stati up e down nello stato iniziale, se perdo questa informazione significa che la matrice densità ridotta del sistema diventa diagonale.
Quindi il tempo in cui perdo questa informazione **è il tempo di dephasing del qubit**.
Questo tempo si può calcolare
$$\Gamma_{deph} = 2\chi  S_{nn}$$

Ora consideriamo il rapporto tra le due gamma
$$\frac{\Gamma_{deph}}{\Gamma_{measure}} = \frac{2\chi}{4\theta_0^2}S_{nn}S_{\theta\theta}$$

Il principio di indeterminazione, vincola il valore del prodotto $S_{nn}S_{\theta\theta}$ perché se considero l'onda che viaggia nella linea di trasmissione (il cui sfasamento ha memoria dello stato del qubit) la sua fase ed il numero di fotoni dell'onda (che note le dimensioni della linea determina l'ampiezza dell'onda) sono **coniugate** $\Delta N \Delta \theta \geq 1/2$.

Siccome la fase viene misurata con una misura lenta, ovvero facendo una media (che equivale a misurare la fase _integrata_ nel tempo e poi dividere per il tempo), la sua varianza è $(\Delta \theta)^2 = S_{\theta\theta}/t$ (**diviso** t perché è la media, non la fase integrata). Allo stesso modo si può pensare di misurare $N$ con una misura lenta, integrando il **flusso** di fotoni, dunque $(\Delta N)^2 = S_{\dot{N}\dot{N}}t$ (**per** il tempo, perché misuro un valore integrato, non una media).
Quindi $S_{\theta\theta}S_{\dot{N}\dot{N}}\geq1/4$.

A questo punto bisogna considerare che l'ambiente in questo caso è la linea di trasmissione accoppiata alla cavità, quindi ho uno scambio di fotoni tra cavità e linea, dunque è presente un legame tra le fluttuazioni di $n$ ed $N$. Infatti si trova che $S_{nn} \propto S_{\dot{N}\dot{N}}$.
Quindi

$$\frac{\Gamma_{deph}}{\Gamma_{measure}} \propto S_{\dot{N}\dot{N}}S_{\theta\theta}$$
e facendo conti espliciti per calcolare il coefficiente di proporzionalità, si trova che fa $4$, quindi

$$\frac{\Gamma_{deph}}{\Gamma_{measure}} \geq 1$$
dove l'uguaglianza è vera se $\Delta \theta \Delta N = 1/2$, che significa che l'onda che viaggia nella linea di trasmissione è in uno stato coerente.

Il rapporto quindi non può essere inferiore ad uno, ovvero **il massimo che posso fare** è misurare se lo stato è up o down appena prima che dephasi. Appena la misura termina, ho perso tutta l'informazione sulla fase.