/** 
 * Applicativo in C che permette di Gestire input e file, 
 * 
 * Consente una cifratura simmetrica con Cifrario di Vigenère,
 * 
 * utilizzando una chiave di cifratura, e seguendo la formula:
 * 
 * C = (P + K) / mod 26
 * 
 * @param plaintext: testo in chiaro da cifrare
 * @param key: chiave di cifratura
 * @param ciphertext: testo cifrato risultante
 * 
 * Utilizzo "fgets" per gestire input sicuri ed evitare BufferOverflow.
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vigenere.h" 

// Funzione per cifratura con Cifrario di Vigenère
void vigenere_cipher(char *plaintext, char *key, char *ciphertext) {
    int i, j;
    
    // Calcolo la lunghezza della chiave per ciclarla correttamente 
    int key_length = strlen(key);
    // Verifico che la chiave non sia vuota
    if (key_length == 0) {
        fprintf(stderr, "Errore: La chiave di cifratura non può essere vuota.\n");
        exit(EXIT_FAILURE);
    }
    // Ciclo attraverso ogni carattere del testo in chiaro
    for (i = 0, j = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) { // Se il carattere è alfabetico
            int offset_text = isupper(plaintext[i]) ? 'A' : 'a'; // Determino l'offset per lettere maiuscole o minuscole
            int position_text = plaintext[i] - offset_text; // Posizione del carattere nel range 0-25
            int offset_key = isupper(key[j % key_length]) ? 'A' : 'a'; // Determino l'offset per la chiave
            int position_key = key[j % key_length] - offset_key; // Posizione del carattere della chiave nel range 0-25
            // Cifratura: C = (P + K) mod 26
            ciphertext[i] = (position_text + position_key) % 26 + offset_text; // Calcolo il carattere cifrato e lo converto in ASCII
            j++; // Incremento j solo per caratteri alfabetici
        } else {
            // Se il carattere non è alfabetico, lo copio direttamente
            ciphertext[i] = plaintext[i];
        }
    } ciphertext[i] = '\0'; // Termino la stringa cifrata
}

// Funzione decifratura con Cifrario di Vigenère
void vigenere_decipher(char *ciphertext, char *key, char *plaintext) {
    int i, j;
    
    // Calcolo la lunghezza della chiave per ciclarla correttamente 
    int key_length = strlen(key);
    // Verifico che la chiave non sia vuota
    if (key_length == 0) {
        fprintf(stderr, "Errore: La chiave di cifratura non può essere vuota.\n");
        exit(EXIT_FAILURE);
    }
    // Ciclo attraverso ogni carattere del testo cifrato
    for (i = 0, j = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) { // Se il carattere è alfabetico
            int offset_text = isupper(ciphertext[i]) ? 'A' : 'a'; // Determino l'offset per lettere maiuscole o minuscole
            int position_text = ciphertext[i] - offset_text; // Posizione del carattere nel range 0-25
            int offset_key = isupper(key[j % key_length]) ? 'A' : 'a'; // Determino l'offset per la chiave
            int position_key = key[j % key_length] - offset_key; // Posizione del carattere della chiave nel range 0-25
            // Cifratura: C = (P + K) mod 26
            plaintext[i] = (position_text - position_key + 26) % 26 + offset_text; // Calcolo il carattere cifrato e lo converto in ASCII
            j++; // Incremento j solo per caratteri alfabetici
        } else {
            // Se il carattere non è alfabetico, lo copio direttamente
            plaintext[i] = ciphertext[i];
        }
    } plaintext[i] = '\0'; // Termino la stringa cifrata
}
