## Cifrario di Vigenere

🔗 Link GitPages:
[https://1esa1.github.io/Cifrario-di-Vigenere/](https://1esa1.github.io/Cifrario-di-Vigenere/)

Applicativo C che implementa il cifrario di Vigenere con una semplice interfaccia grafica (raylib). Permette di cifrare e decifrare testo usando una chiave.

### Funzionalita
- Cifratura Vigenere su testi alfabetici.
- Decifratura Vigenere con la stessa chiave.
- Supporto per maiuscole e minuscole, mantenendo gli spazi e la punteggiatura.

### Struttura del progetto
- [main.c](main.c): avvio applicazione e interfaccia grafica.
- [vigenere.c](vigenere.c): implementazione di cifratura/decifratura.
- [vigenere.h](vigenere.h): prototipi delle funzioni.
- [tests/](tests/): file di prova.

### Requisiti
- Compiler C (gcc/clang).
- Libreria raylib.

### Compilazione
Esempio su macOS (raylib installata):

```bash
cc main.c vigenere.c -o vigenere \
	-lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
```

Su Linux (raylib installata):

```bash
cc main.c vigenere.c -o vigenere -lraylib -lm -ldl -lpthread
```

### Esecuzione
```bash
./vigenere
```

### Note sull'uso
Nel file [main.c](main.c) sono presenti esempi di input e chiave:

- `input`: testo in chiaro da cifrare.
- `key`: chiave di cifratura.
- `output`: testo cifrato risultante.

La cifratura segue la formula:

$$
C = (P + K) \bmod 26
$$

### Test rapidi
I file in [tests/](tests/) possono essere usati come riferimento per verificare risultati attesi.

### Licenza
Progetto Personale 
