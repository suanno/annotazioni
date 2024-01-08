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
$$R_{II}(t) = <I(t)I(0)>$$

Ed infine definiamo il **noise power spectrum** associato alla corrente $I(t)$ come la **trasformata di Fourier dell'autocorrelazione**, ovvero

$$S_{II}(\omega) = \int_{-\infty}^{\infty}dt e^{-i\omega t}<I(t)I(0)>$$

Questa grandezza descrive il rumore sulla corrente, che emerge quando la misuro. Per vederlo, presento **due interpretazioni** del noise power spectrum.

### 1) Potenza del rumore


