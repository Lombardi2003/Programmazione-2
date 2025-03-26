# Prova di laboratorio di Programmazione II - 19/07/18

## Descrizione
Si vuole realizzare un sistema per la gestione di un social network simile a Twitter, rappresentato da un **grafo orientato non pesato**. I nodi del grafo sono di due tipi:
- **Utente (U)**: identificato dal **nickname**.
- **Tweet (T)**: rappresentato da un **testo** (massimo 80 caratteri).

Gli **archi** del grafo rappresentano tre tipi di relazione:
1. **Follow**: da **utente** a **utente** (U1 follow U2).
2. **Ownership**: da **tweet** a **utente** (T owner U).
3. **Like**: da **utente** a **tweet** (U like T).

La cartella `19-07-18` contiene i file:
- `grafo.h`, `grafo.c`
- `coda.c`, `coda.h`
- `node.h` (contiene il tipo di dato `node`).
- `graph` (contiene la struttura del grafo: prima riga con il numero di nodi, righe successive con gli archi sorgente → destinazione).
- `node` (contiene il contenuto dei nodi: prima riga = contenuto, seconda riga = tipo).

---

## Specifiche di sviluppo

### Punto 1
Creare un progetto (con **Makefile**) per l’acquisizione del grafo. Il progetto include:
- Il modulo **`grafo`**.
- Il file **`compito.cc`**.

Nel `main` del file `compito.cc`:
- Acquisire il grafo orientato dal file `graph`.
- Implementare la procedura `stampa(graph)` che **stampa gli archi del grafo**.

**Valutazione:** 18 punti

---

### Punto 2
Estendere il progetto per gestire il **contenuto dei nodi**:
- Nel `main`, acquisire il contenuto dei nodi dal file `node`.
- Memorizzare i nodi in un **vettore dinamico** `node*` (dimensione `n` = numero di nodi).
- Gli indici nel vettore vanno da `0..n-1`, corrispondenti agli identificativi `1..n`.
- Modificare `stampa(graph, node*)` per stampare gli archi in formato "verbose":
  - **Esempio di output:**
    ```
    pippo FOLLOW pluto
    pippo LIKE Mi piace il cioccolato
    ```
- Includere `node.h` nel progetto.

**Valutazione:** 4 punti

---

### Punto 3.a
Stampare i **Most Influential People** (utenti con più like ricevuti sui loro tweet):
- Aggiungere la funzione:
  ```cpp
  int* totalLike(graph, node*);
  ```
  - Restituisce un **vettore dinamico** `V` con `V[i-1] =` numero totale di **like** ricevuti dai tweet dell’utente `i`.
  - Se il nodo non è un utente, `V[i-1] = 0`.
- Richiamare `totalLike` dal `main`, trovare gli utenti con più like e stamparne i nickname.

**Valutazione:** 5 punti

---

### Punto 3.b
Stampare l’elenco di utenti **seguiti direttamente o indirettamente** da un utente specifico:
- Aggiungere la procedura:
  ```cpp
  void follow(graph, node*, int);
  ```
  - Dati **grafo**, **vettore nodi** e **ID utente**, stampa tutti gli utenti seguiti direttamente o tramite catena di follow.
  - **Esempio:** Se `U` segue `U1`, `U1` segue `U2`, allora `U` segue anche `U2`.
- Richiamare `follow` dal `main`, chiedendo all’utente un ID da tastiera.
- Includere `coda.c` e `coda.h` nel progetto (utili per l'implementazione di `follow`).

**Valutazione:** 5 punti

---

## Requisiti e Note
- La valutazione è **punto per punto** con dipendenze:
  - (1 → 2 → 3.a)
  - (1 → 2 → 3.b)
- **Il codice deve compilare e rispettare le specifiche** per ogni punto.
- **È vietato:**
  - Usare `break`.
  - Dichiarare variabili globali.
- È consentito consultare solo il materiale del corso e i libri di testo consigliati.

### Consegna
1. Creare una cartella `/tmp/esame/risultato/` etichettata con il proprio numero di matricola.
2. Inserire nella cartella:
   - Tutti i file `.h` e `.cc` del progetto.
   - Il **makefile**.
3. Il **makefile deve produrre un eseguibile funzionante** per essere valutato.

---

## Esempi di esecuzione

### Output atteso per il Punto 1
L’elenco degli archi deve essere stampato come indicato nel file `graph`.

### Output atteso per il Punto 2
```
fede LIKE Amo la Ferrari
fede LIKE Mi piace il cioccolato

Mi piace il cioccolato OWNER ale
Oggi piscina OWNER fede
Voglia di vacanze OWNER fede

ale FOLLOW ricky
ale FOLLOW fede
ale LIKE Oggi piscina
ale LIKE Amo la Ferrari

ricky FOLLOW fede
ricky LIKE Voglia di vacanze

Amo la Ferrari OWNER ricky

wilma FOLLOW ale
```

### Output atteso per il Punto 3.a
```
fede
ricky
```

### Output atteso per il Punto 3.b (dato in ingresso il nodo 8)
```
L’utente wilma segue:
fede
ricky
ale
```

