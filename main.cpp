#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    system("cls");//pour que la tableau se mette a jour automatiquement
    int largeur = 20;
    int hauteur = 10;
    char cadre[hauteur][largeur];
    int positionY = 5; // Position initiale X du pion (lignes)
    int positionX = 10; // Position initiale Y du pion (colonnes)
    int vCount = 4; // Nombre de 'V' restants
    int blocPousseY = -1; // Variables pour suivre la direction de poussée
    int blocPousseX = -1;
    bool blocsPousses[hauteur][largeur];


    // Remplir le tableau et faire le cadre de X
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            if (j == 0 || j == largeur - 1) {
                cadre[i][j] = 'X';
            } else if (i == 0 || i == hauteur - 1) {
                cadre[i][j] = 'X';
            } else {
                cadre[i][j] = ' ';
            }
            // Ajout des 'V' à chaque coin du cadre à l'intérieur
            if ((i == 1 && (j == 1 || j == largeur - 2)) || (i == hauteur - 2 && (j == 1 || j == largeur - 2))) {
                cadre[i][j] = 'V';
            }
        }
    }

    for (int i = 0; i < hauteur; i++) { //initialisé les blocs non poussés
        for (int j = 0; j < largeur; j++) {
            blocsPousses[i][j] = false;
        }
    }


    // Placer le pion au centre du tableau
    cadre[positionY][positionX] = 'S';
    cadre[5][9] = '#'; //affichage des blocs poussables autour de snoopy
    cadre[5][11] = '#';
    cadre[4][10] = '#';
    cadre[6][10] = '#';

    cadre [2][1] ='C'; //affichage des blocs cassable
    cadre [1][2] ='C';

    cadre [7][2]='$'; //affichage des blocs piégés
    cadre [6][2]= '$';
    cadre [7][3]='$';

    while (1) {

        system("cls"); // Effacer l'écran avec la bibliotheque windows

        // Afficher le tableau car boucle
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 20; j++) {
                printf("%c", cadre[i][j]);
            }
            printf("\n");
        }
        int a;
        printf("Deplacez le pion avec les fleches, q (revenir au menu principal): ");
        printf("%d", a);
        a = getch();

        // Effacer la position actuelle du pion
        cadre[positionY][positionX] = ' ';

        // Mettre à jour la position du pion en fonction du déplacement
        if (a == 72 && positionY > 1 && !blocsPousses[positionY - 1][positionX] && cadre[positionY - 1][positionX] != 'C') { //fleche du haut et on blinde pour pas sortir du cadre
            if (cadre[positionY - 1][positionX] == '$') {
                system("cls");
                printf("Game over\n");
                break;
            }
            positionY--;
            blocPousseY = -1; // Pousse vers le haut
            blocPousseX = 0;
        } else if (a == 80 && positionY < hauteur - 2 && !blocsPousses[positionY + 1][positionX] && cadre[positionY + 1][positionX] != 'C') { //fleche du bas et on blinde pour pas sortir du cadre
            if (cadre[positionY + 1][positionX] == '$') {
                system("cls");
                printf("Game over\n");
                break;
            }
            positionY++;
            blocPousseY = 1; // Pousse vers le bas
            blocPousseX = 0;
        } else if (a == 75 && positionX > 1 && !blocsPousses[positionY][positionX - 1] && cadre[positionY][positionX - 1] != 'C') { //fleche de gauche et on blinde pour pas sortir du cadre
            if (cadre[positionY][positionX-1] == '$') {
                system("cls");
                printf("Game over\n");
                break;
            }
            positionX--;
            blocPousseY = 0;
            blocPousseX = -1; // Pousse vers la gauche
        } else if (a == 77 && positionX < largeur - 2 && !blocsPousses[positionY][positionX + 1] && cadre[positionY][positionX + 1] != 'C') { //fleche de droite et on blinde pour pas sortir du cadre
            if (cadre[positionY][positionX+1] == '$') {
                system("cls");
                printf("Game over\n");
                break;
            }
            positionX++;
            blocPousseY = 0;
            blocPousseX = 1; // Pousse vers la droite
        } else if (a == 'q') {
            break; // Quitter le programme si 'q' est appuyé


        }else if (a == 'c') {// Si la touche "c" est pressée
            // Vérifiez si le pion est sur une case adjacente à un bloc "C"
            if ((positionY > 1 && cadre[positionY - 1][positionX] == 'C') ||
                (positionY < hauteur - 2 && cadre[positionY + 1][positionX] == 'C') ||
                (positionX > 1 && cadre[positionY][positionX - 1] == 'C') ||
                (positionX < largeur - 2 && cadre[positionY][positionX + 1] == 'C')) {


                // Vérifiez et supprimez les blocs "C" adjacents
                if (positionY > 1 && cadre[positionY - 1][positionX] == 'C') {
                    cadre[positionY - 1][positionX] = ' ';
                }
                if (positionY < hauteur - 2 && cadre[positionY + 1][positionX] == 'C') {
                    cadre[positionY + 1][positionX] = ' ';
                }
                if (positionX > 1 && cadre[positionY][positionX - 1] == 'C') {
                    cadre[positionY][positionX - 1] = ' ';
                }
                if (positionX < largeur - 2 && cadre[positionY][positionX + 1] == 'C') {
                    cadre[positionY][positionX + 1] = ' ';
                }
            }
        }



        if (cadre[positionY][positionX] == '#' && !blocsPousses[positionY][positionX] && cadre[positionY + blocPousseY][positionX + blocPousseX] == ' ') {
            cadre[positionY + blocPousseY][positionX + blocPousseX] = '#';
            blocsPousses[positionY + blocPousseY][positionX + blocPousseX] = true;
            cadre[positionY][positionX] = ' ';
        }


        if (cadre[positionY][positionX] == 'V') {
            cadre[positionY][positionX] = ' ';
            vCount--;
            if (vCount == 0) {
                system("cls"); // Effacer l'écran
                printf("Bravo ! Niveau réussi\n");
                break;
            }
        }

        // Mettre à jour la position du pion sur le tableau
        cadre[positionY][positionX] = 'S';


    }
    printf("Appuyez sur une touche pour quitter le jeu...\n");
    getch(); // Attendre que l'utilisateur appuie sur une touche pour quitter

    return 0;
}