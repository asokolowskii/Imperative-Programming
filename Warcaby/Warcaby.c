
#include <stdio.h>
#include <stdlib.h>

#define N 20

void start(char board[][N], int n) {
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            board[i][j] = '_';

    for (i = 0; i < 4; ++i)
        for (j = 0; j < n; ++j)
            if ((i + j) % 2 == 0)
                board[i][j] = '1';

    for (i = n - 4; i < n; ++i)
        for (j = 0; j < n; ++j)
            if ((i + j) % 2 == 0)
                board[i][j] = '2';
}

int move(char board[][N], int n, int i, int j) {
    char p = board[i][j];
    if (p != '1' && p != '2') return 0;
    int d = (p == '1') ? 1 : -1;
    int ni = i + d;

    if (ni >= 0 && ni < n) {
        if (j + 1 < n && board[ni][j + 1] == '_') {
            board[ni][j + 1] = p;
            board[i][j] = '_';
            return 1;
        }
        if (j - 1 >= 0 && board[ni][j - 1] == '_') {
            board[ni][j - 1] = p;
            board[i][j] = '_';
            return 1;
        }
    }

    return 0;
}

int capture(char board[][N], int n, int i, int j) {
    char p = board[i][j];
    if (p != '1' && p != '2') return 0;
    char o = (p == '1') ? '2' : '1';
    int d = (p == '1') ? 1 : -1;

    int mi = i + d, mjr = j + 1, mjl = j - 1;
    int ni = i + 2 * d, njr = j + 2, njl = j - 2;

    if (ni >= 0 && ni < n) {
        if (njr < n && board[mi][mjr] == o && board[ni][njr] == '_') {
            board[mi][mjr] = '_';
            board[ni][njr] = p;
            board[i][j] = '_';
            return 1;
        }
        if (njl >= 0 && board[mi][mjl] == o && board[ni][njl] == '_') {
            board[mi][mjl] = '_';
            board[ni][njl] = p;
            board[i][j] = '_';
            return 1;
        }
    }

    return 0;
}

void print_board(char board[][N], int n) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

int main() {
    int n, seed, steps;
    scanf("%d %d %d", &n, &seed, &steps);

    srand(seed);

    char board[N][N];
    start(board, n);

    int s;
    for (s = 0; s < steps; ++s) {
        char player = (s % 2 == 0) ? '1' : '2';

        int i, j;
        do {
            i = rand() % n;
            j = rand() % n;
        } while (board[i][j] != player);

        if (!capture(board, n, i, j))
            move(board, n, i, j);
    }

    print_board(board, n);

    int c1 = 0, c2 = 0;
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j) {
            if (board[i][j] == '1') ++c1;
            if (board[i][j] == '2') ++c2;
        }

    printf("%d %d\n", c1, c2);
    return 0;
}
