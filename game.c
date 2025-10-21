
#include <stdio.h>
#include <stdbool.h>

// Configurations (Static Values)
#define MAP_ROWS 12
#define MAP_COLS 12

// Tile codes
#define TILE_WALL 'W'
#define TILE_FLOOR 'F'
#define TILE_POTION 'P'

// Player structure
struct Player
{
    int level;
    int attack;
    int defense;

    int position_x;
    int position_y;
    // int hp;
};

// Globals (Map and Player)
char map[MAP_ROWS][MAP_COLS] = {
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'W', 'W', 'F', 'F', 'P', 'F', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'W', 'W', 'F', 'F', 'F', 'F', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'W'},
    {'W', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'W'},
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}};

struct Player player = {1, 5, 5, 3, 3};

// Functions to be implemented
void printMenu(void);
void printMap(void);
void printPlayerStats(void);

char readUserInput(void);
void movePlayer(char dir);

bool isTileWalkable(char t);
int inBounds(int y, int x);

void collectItems();

// ====== Main ======
int main(void)
{
    printf("Hello Wizard! 🧙‍♂️\n");
    while (1 == 1) {
        // Windows Terminal Clean Function (Uses stdlib)
        //system("cls");
        printPlayerStats();
        printMap();
        char input = readUserInput();
        movePlayer(input);

        collectItems();

        printf("\n\n\n\n\n\n\n");
    }

    return 0;
}

bool isTileWalkable(char t) {
    return (t != 'W');
}

void collectItems() {
    if (map[player.position_x][player.position_y] == 'P') {
        map[player.position_x][player.position_y] = 'F';
        player.level++;
        player.attack += 5;
        player.defense += 3;
    }
    // For example in the future if we have monsters (TILE = 'M')
    // we can have this:
    //if (map[player.position_x][player.position_y] == 'M') {
        // FIGHT HERE!
    //}
}

void printPlayerStats() {
    printf("🗡️ Attack: %d\n", player.attack);
    printf("🛡️ Defense: %d\n", player.defense);
    printf("💡 Level: %d\n", player.level);
    printf("🆇 Player Position: [%d,%d]\n", player.position_x, player.position_y);
}

char readUserInput(void) {
    printf("\n\t   W - UP");
    printf("\nA - LEFT   S - DOWN  D - RIGHT\n");
    printf("Direction: ");
    char input;
    scanf(" %c", &input);
    return input;
}

void movePlayer(char dir) {
    printf("Moving player to %c\n\n", dir);
    switch(dir) {
        case 'W':
        case 'w':
            if (isTileWalkable(map[player.position_x-1][player.position_y]))
                player.position_x--;
            break;
        case 'A':
        case 'a':
            if (isTileWalkable(map[player.position_x][player.position_y-1]))
                player.position_y--;
            break;
        case 'S':
        case 's':
            if (isTileWalkable(map[player.position_x+1][player.position_y]))
                player.position_x++;
            break;
        case 'D':
        case 'd':
            if (isTileWalkable(map[player.position_x][player.position_y+1]))
                player.position_y++;
            break;
    }
}

// Implementations
void printMap(void)
{
    for (int x = 0; x < MAP_ROWS; x++)
    {
        for (int y = 0; y < MAP_COLS; y++)
        {
            if (x == player.position_x && y == player.position_y)
                printf("🧙");
            else if (map[x][y] == 'W')
                printf("🟥");
            else if (map[x][y] == 'F')
                printf("⬜️");
            else if (map[x][y] == 'P')
                printf("🍔");
            else
                printf("%c", map[x][y]);
        }
        printf("\n");
    }
}