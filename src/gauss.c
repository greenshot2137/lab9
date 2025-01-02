#include "gauss.h"
#include <stdlib.h>
#include <stdio.h>

// Zamienia dwa wiersze w macierzy
void swap_rows(Matrix* mat, Matrix* b, int row1, int row2) {
    double* tempRow = mat->data[row1];
    mat->data[row1] = mat->data[row2];
    mat->data[row2] = tempRow;

    double tempB = b->data[row1][0];
    b->data[row1][0] = b->data[row2][0];
    b->data[row2][0] = tempB;
}

// zmienia wartoœci wierszy dla ka¿dego miejsca do wyzerowania
void substract_rows(Matrix* mat, Matrix* b, int d) {
    for (int r = d + 1; r < mat->r; r++) {
        // oblicza skalar
        double scalar = mat->data[r][d] / mat->data[d][d];

        // zmienia wartoœci wiersza r
        for (int col = 0; col < mat->c; col++)
            mat->data[r][col] -= scalar * mat->data[d][col];

        b->data[r][0] -= scalar * b->data[d][0];
    }
}

/**
 * Zwraca 0 - eliminacja zakoñczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix* mat, Matrix* b) {
    // dla ka¿dej kolumny (indeksów diagonala)
    for (int d = 0; d < mat->r; d++) {
        // Wybór elementu g³ównego
        int maxRow = d;
        for (int r = d + 1; r < mat->r; r++) {
            if (fabs(mat->data[r][d]) > fabs(mat->data[maxRow][d])) {
                maxRow = r;
            }
        }

        // Zamiana wierszy, jeœli potrzeba
        if (maxRow != d) {
            swap_rows(mat, b, d, maxRow);
        }

        // Obs³uga przypadku dla zera i zwraca 1
        if (mat->data[d][d] == 0)
            return 1;

        // zmienia wartoœci wierszy
        substract_rows(mat, b, d);
    }

    return 0;
}

