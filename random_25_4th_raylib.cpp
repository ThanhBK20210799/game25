#include <raylib.h>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

#define GRID_SIZE 5
#define TILE_SIZE 100
#define NUM_TILES (GRID_SIZE * GRID_SIZE)
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

void InsertWindow(){
    InitWindow(800, 800, "Game with 25 tiles");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();
}
void InitializeTiles(int tiles[], bool tileVisible[], bool tileCorrect[]) {
    for (int i = 0; i < NUM_TILES; i++) {
        tiles[i] = i + 1;
        tileVisible[i] = true;
        tileCorrect[i] = false;
    }

    // shuffle numbers
    srand(time(NULL));
    for (int i = NUM_TILES - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = tiles[i];
        tiles[i] = tiles[j];
        tiles[j] = temp;
    }
}

void DrawTiles(int tiles[], bool tileVisible[], bool tileCorrect[]) {
    for (int i = 0; i < NUM_TILES; i++) {
        int tileX = i % GRID_SIZE;
        int tileY = i / GRID_SIZE;

        Color tileColor = tileVisible[i] ? GRAY : (tileCorrect[i] ? GREEN : RED);

        DrawRectangle(tileX * TILE_SIZE, tileY * TILE_SIZE, TILE_SIZE, TILE_SIZE, tileColor);
        if (tileVisible[i]) {
            DrawText(TextFormat("%02d", tiles[i]), tileX * TILE_SIZE + 35, tileY * TILE_SIZE + 35, 20, WHITE);
        }
    }
}

int main(){
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game with 25 tiles");
    SetTargetFPS(60);

    int tiles[NUM_TILES];
    bool tileVisible[NUM_TILES];
    bool tileCorrect[NUM_TILES];
    int tilesCount = NUM_TILES;

    // Initialize for array with in order number
    for(int i = 0; i < NUM_TILES; i ++){
        tiles[i] = i + 1;
        tileVisible[i] = true;
        tileCorrect[i] = false;
    }

    // Shuffle all number to different order
    srand(time(NULL));
    for (int i = NUM_TILES - 1; i > 0; i --){
        int j = rand() % (i + 1);
        int temp = tiles[i];
        tiles[i] = tiles[j];
        tiles[j] = temp;
    }

    while (!WindowShouldClose()){
        // check left click
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            Vector2 mousePos = GetMousePosition();
            int tileX = mousePos.x / TILE_SIZE;
            int tileY = mousePos.y / TILE_SIZE;
            int index = tileY * GRID_SIZE + tileX; // transform from 2D to 1D to fit array
            // in for loop for(int i = 0; i < NUM_TILES; i ++)
            // make tileX = i % GRID_SIZE 
            // make tileY = i / GRID_SIZE
            
            // check if the tile is still visible
            if (index >= 0 && index < NUM_TILES && tileVisible[index]){
                if (tiles[index] == tilesCount){
                    tileVisible[index] = false;     // fade away
                    tileCorrect[index] = true;      // mark as correct
                    tilesCount --;
                } else {
                    tileCorrect[index] = false;
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        // draw tiles
        for(int i = 0; i <NUM_TILES; i ++){
            int tileX = i % GRID_SIZE;
            int tileY = i / GRID_SIZE;

            Color tileColor = GRAY;                 // default is gray color
            if(!tileVisible[i]){
                tileColor = GREEN;                  // correct
            } else {
                if (tileCorrect[i] == false && !tileVisible[i]){
                    tileColor = RED;                // false
                }
            }

            DrawRectangle(tileX * TILE_SIZE, tileY * TILE_SIZE, TILE_SIZE, TILE_SIZE, tileColor);
            if (tileVisible[i]){
                DrawText(TextFormat("%02d", tiles[i]), tileX * TILE_SIZE + 35, tileY * TILE_SIZE +35, 20 ,WHITE);
            }
            
        }
        EndDrawing();
    }
    CloseWindow();
}