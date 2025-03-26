# Progetto: Gestione Hotel con BST

## Descrizione
Il progetto consiste nella realizzazione di un'applicazione per la gestione di prenotazioni online in hotel, dove gli hotel vengono mantenuti ordinati in ordine decrescente per "stelle". Ogni hotel ha:
- Un numero di stelle (intero)
- Un nome (stringa di massimo 20 caratteri)
- Un luogo (stringa di massimo 20 caratteri)

A tale scopo, si utilizzerà un albero binario di ricerca (BST) ordinato in ordine decrescente per stelle. I dati verranno caricati da un file `hotel.txt`, il cui formato è:
- Prima riga: numero di hotel
- Righe successive: elenco degli hotel con nome, luogo e numero di stelle

## Requisiti
Il progetto prevede l'implementazione dei seguenti punti:

### Punto 0: Documentazione con Doxygen e Git
- Documentare il codice affinché la chiamata a Doxygen generi la documentazione del progetto.
- Creare un branch denominato con il proprio nome.
- Completare ogni punto del progetto e consegnarlo tramite push su repository GitLab.

**Valutazione: 4 punti**

### Punto 1: Creazione del modulo "hotel"
- Creare il modulo `hotel` (`hotel.h` e `hotel.cc`) definendo le strutture dati e implementando le relative primitive.
- Creare un progetto con il relativo `makefile` per l'acquisizione del BST dal file `hotel.txt`.
- Il progetto deve includere i moduli:
  - `hotel`
  - `bst`
  - `compito.cc` per la gestione del caricamento e la stampa in ordine decrescente per stelle.

**Valutazione: 18 punti**

### Punto 2.a: Ricerca hotel in base al numero di stelle
- Scrivere la procedura:
  ```cpp
  void ricerca(bst, int, bool);
  ```
  - Se il parametro booleano è `true`, stampare tutti gli hotel con un numero di stelle maggiore di quello in input.
  - Se il parametro booleano è `false`, stampare tutti gli hotel con un numero di stelle minore o uguale.
  - La procedura deve sfruttare le proprietà del BST.

**Valutazione: 5 punti**

### Punto 2.b: Calcolo del numero di hotel sopra una soglia
- Estendere `compito.cc` con la funzione:
  ```cpp
  int media(bst, int, char*);
  ```
  - Dati in input un BST, un numero di stelle "soglia" e un luogo, restituire il numero di hotel nel luogo specificato con un numero di stelle superiore alla soglia.

**Valutazione: 5 punti**

### Punto 3: Ricerca hotel in base al luogo
- Estendere `compito.cc` con la procedura:
  ```cpp
  void per-luogo(bst, char*);
  ```
  - Dato un BST e un luogo in ingresso, stampare tutti gli hotel presenti nel luogo.

**Valutazione: 4 punti**

## Totale punteggio massimo: 32 punti

---


