#include <stdio.h>
#define DIM 100

int main(){
    int mod;
    int K, i, lung;
    char testo[DIM], pos, c;

    printf("Ave! Scegli la modalità:\n" 
        "- Trascrizione testo in cifrario di Cesare (invia 0)\n"
        "- Traduzione testo scritto in cifrario di Cesare (invia 1)\n");
    scanf("%d", &mod);

    if(mod==0) { // MOD trascrizione

        printf("Inserisci il numero chiave:\n");
        scanf("%d", &K);


        printf("Inserisci un testo usando il cifrario di Cesare con %d chiave:\n", K);
        scanf(" %99[^\n]", testo);

        for(lung = 0; testo[lung] != '\0'; lung++);

        
        for(i=0; i<lung; i++){

            if(testo[i] >= 'a' && testo[i] <= 'z'){  //Verifica lettera e non altro
                
                pos = (testo[i] - 'a' + K)%('z' - 'a' + 1);
                testo[i] = 'a' + pos;

                printf("%c", testo[i]);


            }else if(testo[i] >= 'A' && testo[i] <= 'Z') { 

                pos = (testo[i] - 'A' + K)%('Z' - 'A' + 1);
                testo[i] = 'A' + pos;

                printf("%c", testo[i] );


            }else {
                printf("%c", testo[i] );
            }

    } printf("\n");

//

    } else{ // MOD traduzione

        printf("Inserisci un testo di %d usando il cifrario di Cesare con k chiave:\n", DIM-1);
        scanf(" %99[^\n]", testo);

        for(lung = 0; testo[lung] != '\0'; lung++);

        for(K=0; K<=('z' - 'a'); K++){
            
            printf("Traduzione con chiave %d: ", (26-K)%26);

            for(i=0; i<=lung; i++){

                if(testo[i] >= 'a' && testo[i] <= 'z'){  //Verifica lettera e non altro
                    
                    pos = (testo[i] - 'a' + K)%('z' - 'a' + 1);
                    
                    c = 'a' + pos;
                    printf("%c", c);


                }else if(testo[i] >= 'A' && testo[i] <= 'Z') { 

                    pos = (testo[i] - 'A' + K)%('Z' - 'A' + 1);
                    
                    c = 'A' + pos;
                    printf("%c", c);


                }else {
                    printf("%c", testo[i] );
                }
            }

            printf("\n");
        }
    }

	return 0;
}




