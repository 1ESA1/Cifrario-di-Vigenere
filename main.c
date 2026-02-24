/**
 * Interfaccia per il Cifrario di Vigenère
 */

#include "raylib.h"
#include "vigenere.h"
#include <string.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

// 1. Variabili Globali (così UpdateDrawFrame può vederle)
char input[50] = "HELLO WORLD";
char key[50] = "KEY";
char output[50] = "";

// 2. Funzione di aggiornamento (chiamata 60 volte al secondo)
void UpdateDrawFrame() {
    // Eseguiamo la cifratura
    int keyChar = GetCharPressed();

    // Ciclo while per leggere tutti i caratteri premuti
    while (keyChar > 0) {
        // Se è un carattere valido (lettera o spazio)
        int len = strlen(input);
        // Controlliamo che ci sia spazio nel buffer (sizeof(input) - 1 per lo zero finale)
        if (len < (sizeof(input) - 1)) {
            input[len] = (char)keyChar;
            input[len + 1] = '\0';
        }
        keyChar = GetCharPressed(); // Legge il prossimo carattere
    }

    // Gestione cancellazione (Il Backspace è un tasto di controllo, non un carattere)
    if (IsKeyPressed(KEY_BACKSPACE)) {
        int len = strlen(input);
        if (len > 0) {
            input[len - 1] = '\0';
        }
    }

    //Calcolo della cifratura
    vigenere_cipher(input, key, output);

    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Cifrario di Vigenere", 50, 20, 25, BLACK);
        DrawLine(50, 55, 750, 55, LIGHTGRAY);

        DrawText("Testo in chiaro:", 50, 100, 18, GRAY);
        // Rettangolo per far capire che è un'area di testo
        DrawRectangleLines(50, 130, 700, 50, DARKBLUE);
        DrawText(input, 60, 140, 30, DARKBLUE);

        // Disegna un trattino che lampeggia alla fine del testo
        if ((((int)(GetTime() * 2) % 2 == 0))) { // Lampeggia ogni 0.5 secondi
            int textWidth = MeasureText(input, 30);
            DrawText("_", 65 + textWidth, 140, 30, DARKBLUE);
        }

        DrawText("Testo cifrato:", 50, 220, 18, GRAY);
        DrawText(output, 50, 250, 40, MAROON);

        // Istruzioni in basso
        DrawText("Usa BACKSPACE per cancellare", 50, 400, 15, LIGHTGRAY);

        DrawText("Link: github.com/EnriKo", 50, 400, 10, LIGHTGRAY);
    EndDrawing();
}

int main() {
    InitWindow(800, 450, "Vigenere Web App");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif

    CloseWindow();
    return 0;
}