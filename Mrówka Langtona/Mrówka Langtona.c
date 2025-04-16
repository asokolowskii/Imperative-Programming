
#include <stdio.h>
#include <stdlib.h>

// Kierunki
typedef enum { NORTH, EAST, SOUTH, WEST } Direction;

// Struktura mrówki
typedef struct {
    int x, y;
    Direction dir;
} Ant;

// Inicjalizacja planszy losowymi liczbami 1-8
void init_board(int*** board, const int n) {
    *board = malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        (*board)[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            (*board)[i][j] = (rand() % 8) + 1;
        }
    }
}

// Zwalnianie pamieci planszy
void free_board(int** board, const int n) {
    for (int i = 0; i < n; ++i) {
        free(board[i]);
    }
    free(board);
}

// Wypisanie planszy
void print_board(int** board, const int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Wypisanie stanu mrówki
void print_ant(const Ant ant) {
    char dir_char;
    switch (ant.dir) {
        case NORTH: dir_char = 'N'; break;
        case EAST:  dir_char = 'E'; break;
        case SOUTH: dir_char = 'S'; break;
        case WEST:  dir_char = 'W'; break;
    }
    printf("%d %d %c\n", ant.x, ant.y, dir_char);
}

// Ruchy
void move_forward(Ant* ant, int n) {
    switch (ant->dir) {
        case NORTH: ant->x = (ant->x - 1 + n) % n; break;
        case EAST:  ant->y = (ant->y + 1) % n; break;
        case SOUTH: ant->x = (ant->x + 1) % n; break;
        case WEST:  ant->y = (ant->y - 1 + n) % n; break;
    }
}

void move_backward(Ant* ant, int n) {
    ant->dir = (ant->dir + 2) % 4;
    move_forward(ant, n);
    ant->dir = (ant->dir + 2) % 4;
}

void move_right(Ant* ant, int n) {
    Direction temp = ant->dir;
    ant->dir = (ant->dir + 1) % 4;
    move_forward(ant, n);
    ant->dir = temp;
}

void move_left(Ant* ant, int n) {
    Direction temp = ant->dir;
    ant->dir = (ant->dir + 3) % 4;
    move_forward(ant, n);
    ant->dir = temp;
}

// Ruch zgodnie z aktualnym polem
void ant_move(int** board, const int n, Ant* ant) {
    int* cell = &board[ant->x][ant->y];
    switch (*cell) {
        case 1: *cell = 7; move_forward(ant, n); break;
        case 2: *cell = 4; ant->dir = (ant->dir + 1) % 4; break;
        case 3: *cell = 2; ant->dir = (ant->dir + 3) % 4; break;
        case 4: *cell = 6; move_right(ant, n); break;
        case 5: *cell = 3; move_left(ant, n); break;
        case 6: *cell = 5; move_backward(ant, n); break;
        case 7: *cell = 8; ant->dir = (ant->dir + 2) % 4; break;
        case 8: *cell = 1; break; // nic nie robi
    }
}

// Symulacja dzialania mrówki
void ant_simulation(int** board, const int n, Ant* ant, const int steps) {
    ant->x = 0;
    ant->y = 0;
    ant->dir = EAST;

    for (int i = 0; i < steps; ++i) {
        ant_move(board, n, ant);
    }
}

int main() {
    int n, seed, steps;
    scanf("%d %d %d", &n, &seed, &steps);

    srand(seed);

    int** board;
    init_board(&board, n);

    Ant ant;
    ant_simulation(board, n, &ant, steps);

    print_board(board, n);
    print_ant(ant);

    free_board(board, n);
    return 0;
}
