/*
** EPITECH PROJECT, 2025
** receipt
** File description:
** print infos
*/
#include "../include/receipt.h"
int print_infos(infos_t receipt_infos)
{
    printf("Veuillez confirmer les informations entrées.\n\n");
    printf("\033[92mNom du client:\033[0m %s", receipt_infos.customer_name);
    printf("\033[92mNuméro de téléphone du client:\033[0m %s", receipt_infos.customer_phone);
    printf("\033[92mAdresse mail du client:\033[0m %s", receipt_infos.email_address);
    printf("\033[92mMethode de payement:\033[0m %s", receipt_infos.payment_method);
    printf("\033[92mMontant de la quittance:\033[0m %d\n", receipt_infos.receipt_amount);
    printf("\033[92mDate de payement:\033[0m %s", receipt_infos.receipt_date);
    printf("\033[92mPoste comptable:\033[0m %s\n", receipt_infos.receipt_place);
    printf("\033[92mNuméro de la quittance:\033[0m %s\n\n", receipt_infos.receipt_reference);
    printf("Entrez \033[91mY/y\033[0m pour confirmer les informations ci-dessus et n'importe quel autre touche pour les rejeter.\n");
    if (getchar() == 'y' || getchar() == 'Y')
        return 0;
    return 1;
}
