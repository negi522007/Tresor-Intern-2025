/*
** EPITECH PROJECT, 2025
** receipt
** File description:
** get receipt infos
*/
#include "../include/receipt.h"

int check_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
            return 1;
    }
    return 0;
}

infos_t get_infos(infos_t receipt_infos)
{
    FILE *file = NULL;
    size_t size = 0;
    char *cache = NULL;

    printf("\033[94m>\033[0m Entrez le nom du client: "); getline(&receipt_infos.customer_name, &size, stdin); size = 0;
    printf("\n\n\033[94m>\033[0m Entrez le numéro de téléphone du client (numéro à 10 chiffres): "); getline(&receipt_infos.customer_phone, &size, stdin); size = 0;
    printf("\n\n\033[94m>\033[0m Entrez l'addresse mail du client (Veuillez sauter cette étape si le client n'en dispose pas): "); getline(&receipt_infos.email_address, &size, stdin); size = 0;
    printf("\n\n\033[94m>\033[0m Entrez le montant de la quittance: "); getline(&cache, &size, stdin);
    if (check_number(cache)) {
        printf("Veuillez entrer un montant valide.\n");
        exit(84);
    }
    receipt_infos.receipt_amount = atoi(cache);
    printf("\n\n\033[94m>\033[0m Entrez le poste comptable: "); getline(&receipt_infos.receipt_place, &size, stdin);
    printf("\n\n\033[94m>\033[0m Entrez le mode de versement (ESPECE, CHEQUE ou MOMO): "); getline(&receipt_infos.payment_method, &size, stdin);
    printf("\n\n\033[94m>\033[0m Entrez la date de la quittance: "); getline(&receipt_infos.receipt_date, &size, stdin);
    file = fopen("receipt_reference", "r");
    if (!file) {
        printf("Il y a un prolème avec le fichier receipt_reference, veuillez le régler.\n"); 
        exit(84);
    }
    getline(&receipt_infos.receipt_reference, &size, file);
    fclose(file);
    free(cache);
    return receipt_infos; 
}

int check_date(char *str)
{
    if (strlen(str) != 11)
        return 1;
    if (str[0] < '0' || str[0] > '3')
        return 1;
    if (str[1] < '0' || str[1] > '9')
        return 1;
    if (str[2] != '/' || str[5] != '/')
        return 1;
    if (str[3] < '0' || str[3] > '1')
        return 1;
    if (str[4] < '0' || str[4] > '9')
        return 1;
    if (str[6] < '0' || str[6] > '9')
        return 1;
    if (str[7] < '0' || str[7] > '9')
        return 1;
    if (str[8] < '0' || str[8] > '9')
        return 1;
    if (str[9] < '0' || str[9] > '9')
        return 1;
    return 0;
}

int check_infos(infos_t *receipt_infos)
{
    if (check_number((*receipt_infos).customer_phone) || strlen((*receipt_infos).customer_phone) != 11) {
        printf("Veuillez entrez un numéro de téléphone à 10 chiffres.\n");
        return 84;
    }
    if (!strcmp((*receipt_infos).receipt_place, "\n")) {
        free((*receipt_infos).receipt_place);
        (*receipt_infos).receipt_place = strdup("TGE");
    }
    if (strcmp((*receipt_infos).payment_method, "ESPECE\n") && strcmp((*receipt_infos).payment_method, "CHEQUE\n") && strcmp((*receipt_infos).payment_method, "MOMO\n")) {
        printf("Entrez un mode de payment valide (ESPECE, CHEQUE ou MOMO)\n");
        return 84;
    }
    if (check_date((*receipt_infos).receipt_date)) {
        printf("Entrez une date valide suivant le format JJ/MM/AAAA.\n");
        return 84;
    }
    return 0;
}