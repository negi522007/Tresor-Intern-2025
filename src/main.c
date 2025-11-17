/*
** EPITECH PROJECT, 2025
** receipt
** File description:
** main
*/

#include "../include/receipt.h"

infos_t free_space(infos_t receipt_infos)
{
    free(receipt_infos.customer_name);
    free(receipt_infos.customer_phone);
    free(receipt_infos.email_address);
    free(receipt_infos.payment_method);
    free(receipt_infos.receipt_date);
    free(receipt_infos.receipt_place);
    free(receipt_infos.receipt_reference);
    return receipt_infos;
}

int main(void)
{
    //gen_file();
    infos_t receipt_infos = {0};
    //gen_file(receipt_infos);
    printf("\033[91m----------------------------------------------------------------------------------------------------------------\033[0m\n");
    printf("\n\033[93mBienvenu dans l'application de collecte des recettes au guichet principale de la Trésorerie Générale de l'Etat.\n\nVeuillez remplir les informations ci-dessous pour générer la quittance numérique.\033[0m\n\n");
    printf("\033[91m----------------------------------------------------------------------------------------------------------------\033[0m\n\n");
    receipt_infos = get_infos(receipt_infos);
    if (check_infos(&receipt_infos)) {
        receipt_infos = free_space(receipt_infos);
        return 84;    
    }
    if (!print_infos(receipt_infos))
        gen_file(receipt_infos);
    receipt_infos = free_space(receipt_infos);
        //scanf("> Entrez le nom du client: %s", &receipt_infos.customer_name) 
}