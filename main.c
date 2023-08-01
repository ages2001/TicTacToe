#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printTable();

void insert(char location[3], char value);

int isValidLocation(char location[3]);

char returnLocationValue(char location[3]);

int checkLocation(char location[3]);

int isTableFull();

int checkGameStatus();

void clearTable();

char table[9];

int main() {
    printf("\n***************************************************\n");
    printf("Welcome to the Tic-Tac-Toe! (Game made by ages2001)\n");
    printf("***************************************************\n\n");
    while (1) {
        int choice;

        printf("----------\n");
        printf("Operations\n");
        printf("----------\n");
        printf("\n1 - Play the game!");
        printf("\n2 - Exit from game!\n");

        printf("\nEnter the choice (1-2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            clearTable();
            int orderOfPlayer = 1;
            do {
                char p1_location[3], p2_location[3];
                printTable();
                if (orderOfPlayer == 1) {
                    do {
                        printf("Player 1 choose location: ");
                        scanf("%s", p1_location);
                        p1_location[0] = toupper(p1_location[0]);
                    } while (!checkLocation(p1_location));
                    insert(p1_location, 'X');
                    orderOfPlayer = 2;
                } else {
                    do {
                        printf("Player 2 choose location: ");
                        scanf("%s", p2_location);
                        p2_location[0] = toupper(p2_location[0]);
                    } while (!checkLocation(p2_location));
                    insert(p2_location, 'O');
                    orderOfPlayer = 1;
                }
            } while (!checkGameStatus());

            printTable();
            printf("*************\n");
            if (checkGameStatus() == 1) printf("PLAYER 1 WON!\n");
            else if (checkGameStatus() == 2) printf("PLAYER 2 WON!\n");
            else printf("    DRAW!\n");
            printf("*************\n\n");
        } else if (choice == 2) {
            printf("\nThanks for playing the game!\n");
            printf("Exiting...\n");
            exit(0);
        } else
            printf("\nInvalid choice!\n\n");
    }
}


void printTable() {
    printf("\n    A   B   C  \n");
    printf("  |---|---|---|\n");
    printf("1 | %c | %c | %c |\n", table[0], table[1], table[2]);
    printf("  |---|---|---|\n");
    printf("2 | %c | %c | %c |\n", table[3], table[4], table[5]);
    printf("  |---|---|---|\n");
    printf("3 | %c | %c | %c |\n", table[6], table[7], table[8]);
    printf("  |---|---|---|\n\n");
}

void insert(char location[3], char value) {
    if (strcmp("A1", location) == 0) table[0] = value;
    else if (strcmp("B1", location) == 0) table[1] = value;
    else if (strcmp("C1", location) == 0) table[2] = value;
    else if (strcmp("A2", location) == 0) table[3] = value;
    else if (strcmp("B2", location) == 0) table[4] = value;
    else if (strcmp("C2", location) == 0) table[5] = value;
    else if (strcmp("A3", location) == 0) table[6] = value;
    else if (strcmp("B3", location) == 0) table[7] = value;
    else table[8] = value;
}

int isValidLocation(char location[3]) {
    return (strcmp("A1", location) == 0) ||
           (strcmp("A2", location) == 0) ||
           (strcmp("A3", location) == 0) ||
           (strcmp("B1", location) == 0) ||
           (strcmp("B2", location) == 0) ||
           (strcmp("B3", location) == 0) ||
           (strcmp("C1", location) == 0) ||
           (strcmp("C2", location) == 0) ||
           (strcmp("C3", location) == 0);
}

char returnLocationValue(char location[3]) {
    if (strcmp("A1", location) == 0) return table[0];
    else if (strcmp("B1", location) == 0) return table[1];
    else if (strcmp("C1", location) == 0) return table[2];
    else if (strcmp("A2", location) == 0) return table[3];
    else if (strcmp("B2", location) == 0) return table[4];
    else if (strcmp("C2", location) == 0) return table[5];
    else if (strcmp("A3", location) == 0) return table[6];
    else if (strcmp("B3", location) == 0) return table[7];
    else return table[8];
}

int checkLocation(char location[3]) {
    if (!isValidLocation(location)) {
        printf("Invalid location!\n\n");
        return 0;
    }

    if (returnLocationValue(location) != ' ') {
        printf("Location is not empty!\n\n");
        return 0;
    }

    return 1;
}

int isTableFull() {
    int size = sizeof(table) / sizeof(table[0]);
    for (int i = 0; i < size; i++) {
        if (table[i] == ' ')
            return 0;
    }
    return 1;
}

int checkGameStatus() {
    if ((table[0] == table[1]) && (table[1] == table[2]) && table[0] != ' ') {
        if (table[0] == 'X') return 1;
        else return 2;
    } else if ((table[3] == table[4]) && (table[4] == table[5]) && table[3] != ' ') {
        if (table[3] == 'X') return 1;
        else return 2;
    } else if ((table[6] == table[7]) && (table[7] == table[8]) && table[6] != ' ') {
        if (table[6] == 'X') return 1;
        else return 2;
    } else if ((table[0] == table[3]) && (table[3] == table[6]) && table[0] != ' ') {
        if (table[0] == 'X') return 1;
        else return 2;
    } else if ((table[1] == table[4]) && (table[4] == table[7]) && table[1] != ' ') {
        if (table[1] == 'X') return 1;
        else return 2;
    } else if ((table[2] == table[5]) && (table[5] == table[8]) && table[2] != ' ') {
        if (table[2] == 'X') return 1;
        else return 2;
    } else if ((table[0] == table[4]) && (table[4] == table[8]) && table[0] != ' ') {
        if (table[0] == 'X') return 1;
        else return 2;
    } else if ((table[2] == table[4]) && (table[4] == table[6]) && table[2] != ' ') {
        if (table[2] == 'X') return 1;
        else return 2;
    } else if (isTableFull())
        return 3;
    else
        return 0;
}

void clearTable() {
    int size = sizeof(table) / sizeof(table[0]);
    for (int i = 0; i < size; i++)
        table[i] = ' ';
}
