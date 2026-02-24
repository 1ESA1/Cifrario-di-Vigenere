/**
 * Interfaccia per il Cifrario di Vigenère
 */

#include "raylib.h"
#include "vigenere.h"

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
    vigenere_cipher(input, key, output);

    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Cifrario di Vigenere", 50, 20, 30, BLACK);

        DrawText("Testo in chiaro:", 50, 100, 20, GRAY);
        DrawText(input, 50, 130, 40, DARKBLUE);

        DrawText("Testo cifrato:", 50, 220, 20, GRAY);
        DrawText(output, 50, 250, 40, MAROON);

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