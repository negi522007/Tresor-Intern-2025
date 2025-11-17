/*
** EPITECH PROJECT, 2025
** receipt
** File description:
** header
*/

#ifndef RECEIPT_H_
    #define RECEIPT_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <string.h>
    #include <stdlib.h>
    #include <hpdf.h>

typedef struct infos {
    char *customer_name;
    char *customer_phone;
    char *email_address;
    int receipt_amount;
    char *receipt_place;
    char *payment_method;
    char *receipt_date;
    char *receipt_reference;
} infos_t;

infos_t get_infos(infos_t recept_info);
char *clean_str(char *str, char *delim);
int check_char(char c, char *str);
int print_infos(infos_t receipt_infos);
int check_infos(infos_t *receipt_infos);
int gen_file(infos_t receipt_infos);
int my_getnbr(char *str);
#endif