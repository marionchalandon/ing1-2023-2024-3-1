#include <stdio.h>
#include <conio.h>

void afficher(char tableau[12][22]){ //sous fonction qui permetnd'afficher le tableau
    int i,j;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 22; j++) {
            printf("%c", tableau[i][j]);
        }
        printf("\n");
    }

}

int main() {
    char tab[12][22] = {
            "**********************",
            "*                    *",
            "*                    *",
            "*                    *",
            "*                    *",
            "*                    *",
            "*                    *",
            "*                    *",
            "*                    *",
            "*                    *",
            "*                    *",
            "**********************",
    };

    tab[1][1] = 'v';//afficgahe des oiseaux dans les coins de la map
    tab[10][1] = 'v';
    tab[10][20] = 'v';
    tab[1][20] = 'v';

    int snoopyX = 10; // Position X initiale de Snoopy
    int snoopyY = 5;  // Position Y initiale de Snoopy
    tab[snoopyY][snoopyX] = 's'; // Affichage de Snoopy au milieu

    tab [5][9]= '#'; //affichage des blocs poussables autour de snoopy
    tab [5][11]='#';
    tab [4][10]='#';
    tab [6][10]='#';
    afficher(tab);





    return 0;
}
