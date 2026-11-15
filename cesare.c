
#include <stdio.h>
#define DIM 100

int main() {
    int mod;
    int K, i, lung;
    char testo[DIM], pos, c;

    printf("====================================\n");
    printf("          CIFRARIO DI CESARE\n");
    printf("====================================\n");
    printf("Seleziona un'operazione:\n\n");
    printf("[0] Cifra un testo\n");
    printf("[1] Decifra un testo (chiave sconosciuta)\n\n");
    printf("Scelta: ");
    scanf("%d", &mod);

    if (mod == 0) { // CIFRATURA

        printf("\n--- CIFRATURA ---\n");

        printf("Inserisci la chiave numerica: ");
        scanf("%d", &K);

        printf("Inserisci il testo da cifrare:\n");
        scanf(" %99[^\n]", testo);

        for (lung = 0; testo[lung] != '\0'; lung++);

        printf("\nTesto cifrato:\n");

        for (i = 0; i < lung; i++) {

            if (testo[i] >= 'a' && testo[i] <= 'z') {

                pos = (testo[i] - 'a' + K) % 26;
                testo[i] = 'a' + pos;

                printf("%c", testo[i]);

            } else if (testo[i] >= 'A' && testo[i] <= 'Z') {

                pos = (testo[i] - 'A' + K) % 26;
                testo[i] = 'A' + pos;

                printf("%c", testo[i]);

            } else {
                printf("%c", testo[i]);
            }
        }

        printf("\n");

    } else if (mod == 1) { // DECIFRATURA

        printf("\n--- DECIFRATURA ---\n");

        printf("Inserisci il testo da decifrare:\n");
        scanf(" %99[^\n]", testo);

        for (lung = 0; testo[lung] != '\0'; lung++);

        printf("\nPossibili traduzioni:\n\n");

        for (K = 0; K < 26; K++) {

            printf("Chiave %2d: ", (26 - K) % 26);

            for (i = 0; i < lung; i++) {

                if (testo[i] >= 'a' && testo[i] <= 'z') {

                    pos = (testo[i] - 'a' + K) % 26;
                    c = 'a' + pos;

                    printf("%c", c);

                } else if (testo[i] >= 'A' && testo[i] <= 'Z') {

                    pos = (testo[i] - 'A' + K) % 26;
                    c = 'A' + pos;

                    printf("%c", c);

                } else {
                    printf("%c", testo[i]);
                }
            }

            printf("\n");
        }

    } else {
        printf("\nScelta non valida. Seleziona 0 oppure 1.\n");
    }

    return 0;
}
