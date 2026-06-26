# Cifrario Di Vigenere

[![License](https://img.shields.io/badge/License-Personal_Project-4285F4?style=plastic&logo=github)](https://github.com/1ESA1/Cifrario-di-Vigenere)
[![Language](https://img.shields.io/badge/Language-C-00599C?style=plastic&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/Platform-macOS%20%7C%20Linux-555555?style=plastic&logo=terminal)](https://github.com/1ESA1/Cifrario-di-Vigenere)
[![Last Commit](https://img.shields.io/github/last-commit/1ESA1/Cifrario-di-Vigenere?style=plastic&logo=github)](https://github.com/1ESA1/Cifrario-di-Vigenere/commits/main)
[![Repo Size](https://img.shields.io/github/repo-size/1ESA1/Cifrario-di-Vigenere?style=plastic&logo=github)](https://github.com/1ESA1/Cifrario-di-Vigenere)
[![GitHub issues](https://img.shields.io/github/issues/1ESA1/Cifrario-di-Vigenere?style=plastic&logo=github)](https://github.com/1ESA1/Cifrario-di-Vigenere/issues)

**Applicativo in C che implementa il cifrario di Vigenere con interfaccia grafica (raylib).** Permette di cifrare e decifrare testo alfabetico utilizzando una chiave, mantenendo spazi e punteggiatura.

[![GitPages](https://img.shields.io/badge/GitPages-1ESA1-4285F4?style=plastic&logo=github)](https://1esa1.github.io/Cifrario-di-Vigenere/)

## Funzionalità
- **Cifratura Vigenere** su testi alfabetici.
- **Decifratura Vigenere** con la stessa chiave.
- Supporto per **maiuscole e minuscole**, mantenendo gli spazi e la punteggiatura.

## 📁 Struttura progetto
- [main.c](main.c): avvio applicazione e interfaccia grafica.
- [vigenere.c](vigenere.c): implementazione di cifratura/decifratura.
- [vigenere.h](vigenere.h): prototipi delle funzioni.
- [tests/](tests/): file di prova.

## ⚙️ Requisiti
- Compiler C (gcc/clang) version >= 4.8).
- Libreria raylib version >= 4.0.

### Installazione di raylib
*Su macOS (con Homebrew):*
```bash
brew install raylib
```
*Su Linux*
```bash
sudo apt install libraylib-dev
```

### 🛠️ Compilazione
Esempio su macOS (raylib installata):

```bash
cc main.c vigenere.c -o vigenere \
	-lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
```

*Su Linux (raylib installata):*

```bash
cc main.c vigenere.c -o vigenere -lraylib -lm -ldl -lpthread
```

*Su Windows (con MinGW e raylib)*
Assicurati che raylib sia nella cartella lib/ e includi i percorsi:
```bash
gcc main.c vigenere.c -o vigenere.exe -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm
```

## 🚀 Esecuzione
```bash
./vigenere
```

### Note sull'utilizzo
Nel file [main.c](main.c) sono presenti esempi di input e chiave:

- `input`: testo in chiaro da cifrare.
- `key`: chiave di cifratura.
- `output`: testo cifrato risultante.

La cifratura segue la formula:

$$
C = (P + K) \bmod 26
$$

dove:
- C = carattere cifrato
- P = carattere in chiaro
- K = carattere della chiave
##   
[![Tests](https://img.shields.io/badge/Run_Tests-6DB33F?style=plastic&logo=testing-library&logoColor=white)](tests/) *I file in [tests/](tests/) possono essere usati come riferimento per verificare risultati attesi.*
Esempio di test:

```bash
# Cifra il contenuto di input.txt e confronta con output_atteso.txt
./vigenere < tests/input.txt > output.txt
diff output.txt tests/output_atteso.txt
```
Se il comando diff non mostra differenze, il test è superato.
##  
[![Contributing](https://img.shields.io/badge/Contributing-663399?style=plastic&logo=github&logoColor=white)](CONTRIBUTING.md)
[![Report Issues](https://img.shields.io/badge/Report_Issues-FF5252?style=plastic&logo=github&logoColor=white)](https://github.com/1ESA1/Cifrario-di-Vigenere/issues)
[![Pull Requests](https://img.shields.io/badge/Pull_Requests-4CAF50?style=plastic&logo=github&logoColor=white)](https://github.com/1ESA1/Cifrario-di-Vigenere/pulls) *Read [CONTRIBUTING.md](CONTRIBUTING.md) for the complete guidelines on how to contribute to the project.*  

[![GitHub](https://img.shields.io/badge/GitHub-project_developed_by_1ESA1-0288D1?style=plastic&logo=github&logoColor=white)](https://github.com/1ESA1)
[![License](https://img.shields.io/badge/License-Apache%202.0-5C2D91?style=plastic&logo=apache&logoColor=white)](LICENSE)
