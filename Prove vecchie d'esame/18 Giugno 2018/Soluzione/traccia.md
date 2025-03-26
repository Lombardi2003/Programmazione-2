# Prova di laboratorio di Programmazione II - 18/06/18

## Descrizione
Si vuole realizzare una piccola parte di un sistema per la gestione di carte fedeltà. Ogni cliente ha:
- un numero di carta (intero);
- un nome e cognome (stringa di massimo 40 caratteri);
- il numero totale di punti accumulati.

Le carte fedeltà dei clienti vengono registrate in un **binary search tree (BST)** per velocizzare la ricerca per codice (chiave del BST).

Ogni giorno viene mantenuta traccia degli acquisti effettuati dai clienti. Per ogni acquisto si registra:
- il codice della carta;
- il totale punti accumulati con l'acquisto.

La cartella `18-06-22` contiene i file **carta.h**, **bst.h** e **bst.cc**.

---

## Specifiche di sviluppo

### Punto 1
Estendere il modulo **"carta"** (`carta.h`, `carta.cc`):
- Definire il tipo `tipo_inf`, contenente nome, cognome e totale punti.
- Implementare le relative primitive.
- Creare un progetto (con **makefile**) per l'acquisizione delle carte fedeltà da tastiera.
- Il progetto include:
  - Modulo `carta`.
  - Modulo `bst` (dove sono già implementate le primitive per un BST con chiave `int` corrispondente al codice della carta).
  - File `compito.cc` per l'acquisizione di una sequenza di `n` carte, con `n` inserito da tastiera. I dati delle carte vengono inseriti riga per riga.

**Valutazione:** 18 punti

---

### Punto 2
Estendere il modulo **"bst"** con la primitiva di stampa della sequenza di carte in ordine crescente di valore. La primitiva deve essere richiamata dal `main`.

**Valutazione:** 2 punti

---

### Punto 2.b
Estendere il file **`compito.cc`** aggiungendo la funzione:
```cpp
int totalePunti(bst, int inf, int sup);
```
La funzione:
- Riceve in ingresso un BST e due numeri di carta `inf` e `sup`.
- Restituisce la somma dei punti accumulati dalle carte con numero di carta **compreso tra `inf` e `sup`**.
- Deve essere richiamata dal `main`, dopo aver richiesto all'utente i due estremi.

**Valutazione:** 4 punti

---

### Punto 3
Estendere il file **`compito.cc`** aggiungendo la funzione:
```cpp
void aggiorna(bst, int codice, int punti);
```
La funzione:
- Riceve in ingresso un BST e i dati relativi a un acquisto.
- Se la carta esiste, aggiorna i punti accumulati.
- Se la carta **non** esiste, segnala errore.
- Deve essere richiamata nel `main` per un numero arbitrario di acquisti. La sequenza termina quando l'utente inserisce un carattere specifico.
- Dopo l'aggiornamento, deve stampare il BST risultante.

**Valutazione:** 3 punti

---

### Punto 4
Estendere il file **`compito.cc`** affinché al termine della fase di aggiornamento venga stampato **l'elenco delle carte che non hanno effettuato acquisti in giornata**.

**Valutazione:** 5 punti

---

## Requisiti e Note
- La valutazione avviene **punto per punto**.
- Dipendenze tra i punti: **(1 → 2 → 3 → 4), (1 → 2.b)**.
- Per ogni punto completato, il codice deve **compilare** e rispettare le specifiche.
- **È vietato**:
  - Usare `break`.
  - Dichiarare variabili globali.
- È possibile consultare solo il materiale del corso e i libri di testo consigliati.

### Consegna
1. Creare una cartella `/tmp/esame/risultato/` etichettata con il proprio numero di matricola.
2. Inserire nella cartella:
   - Tutti i file `.h` e `.cc` del progetto.
   - Il **makefile**.
3. Il **makefile deve produrre un eseguibile funzionante** per essere valutato.

---

## Esempi di esecuzione

### Dati di input (clienti)
```
1236
Anna Viola
22

4412
Paolo Rossi
36

2628
Marco Neri
176

3036
Mario Bianchi
144
```
**Output atteso per il Punto 2** (stampa ordinata per numero di carta):
```
1236 Anna Viola 22
2628 Marco Neri 176
3036 Mario Bianchi 144
4412 Paolo Rossi 36
```

### Dati di input (acquisti)
```
4412 34
1238 37
3036 22
```
**Output atteso per il Punto 3** (errore per carta inesistente + stampa aggiornata):
```
Errore: Carta 1238 non trovata
1236 Anna Viola 22
2628 Marco Neri 176
3036 Mario Bianchi 166
4412 Paolo Rossi 70
```

### Input per il Punto 2.b
```
2000 4000
```
**Output atteso:**
```
Totale punti: 412
```

### Output atteso per il Punto 4 (carte senza acquisti in giornata):
```
1236 Anna Viola 22
2628 Marco Neri 176
```

