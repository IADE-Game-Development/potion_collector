
#include <stdio.h>
#include <stdbool.h>

// Configurations
#define MAP_ROWS 12
#define MAP_COLS 12

// Tile codes
#define TILE_WALL 'W'
#define TILE_FLOOR 'F'
#define TILE_POTION 'P'

// Player structure

// Globals (Map and Player)

// Functions to be implemented
void printMenu(void);
void printMap(void);
void printPlayerStats(void);

char readUserInput(void);
void movePlayer(char dir);

bool isTileWalkable(char t);
int inBounds(int y, int x);

// ====== Main ======
int main(void) {
    printf("Hello Wizard! 🧙‍♂️");
    return 0;
}

// Implementations