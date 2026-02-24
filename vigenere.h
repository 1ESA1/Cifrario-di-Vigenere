/**
 * Vigenère Cipher Implementation in C
 **/

#ifndef VIGENERE_H
#define VIGENERE_H

// Function prototypes for Vigenère cipher
void vigenere_cipher(char *plaintext, char *key, char *ciphertext);
void vigenere_decipher(char *ciphertext, char *key, char *plaintext);

#endif