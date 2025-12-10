/*
 * Programme principal - Gestion des types d'emplacement
 * Camping "La Cerisaie"
 */

#include <stdio.h>
#include "include/types_emplacement.h"

int main(void) {
    int choix;

    printf("\n");
    printf("   GESTION DES TYPES D'EMPLACEMENT\n");
    printf("   Camping \"La Cerisaie\"\n");

    do {
        printf("\nMenu principal :\n");
        printf("1 - Ajouter un type d'emplacement\n");
        printf("2 - Modifier un type d'emplacement\n");
        printf("3 - Supprimer un type d'emplacement\n");
        printf("4 - Consulter un type d'emplacement\n");
        printf("5 - Lister tous les types d'emplacement\n");
        printf("0 - Quitter\n");
        printf("\nVotre choix : ");
        if (scanf("%d", &choix) != 1) {
            /* Entrée invalide, on vide l'entrée standard */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            choix = -1;
        }

        switch (choix) {
            case 1:
                ajouter_type_emplacement();
                break;
            case 2:
                modifier_type_emplacement();
                break;
            case 3:
                supprimer_type_emplacement();
                break;
            case 4:
                consulter_type_emplacement();
                break;
            case 5:
                lister_types_emplacement();
                break;
            case 0:
                printf("\nAu revoir !\n");
                break;
            default:
                printf("\nChoix invalide !\n");
                break;
        }

    } while (choix != 0);

    return 0;
}