/*
** EPITECH PROJECT, 2025
** receipt 
** File description:
** send the receipt
*/

#include "../include/receipt.h"

int send_receipt(char *filename, char *email_address)
{
    FILE *file = fopen("secret_password", "r");
    if (!file) {
        printf("Le fichier 'secret_password' n'a pas pu s'ouvrir, veuillez vérifier qu'il est bien là et contient le mot de passe de connexion\n"); 
        exit(84);
    }
    size_t size = 0;
    char *smtp_password = NULL;
    getline(&smtp_password, &size, file);
    fclose(file);
    char *smtp_server = "smtp.gmail.com";
    char *smtp_username = "gastonagbdl@gmail.com";
    char *from = "<gastonagbdl@gmail.com>";
    
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl, CURLOPT_USERNAME, smtp_username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, smtp_password);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);
        recipients = curl_slist_append(recipients, strtok(email_address, "\n"));
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);

        curl_mime *mime;
        curl_mimepart *part;

        mime = curl_mime_init(curl);
        part = curl_mime_addpart(mime);
        curl_mime_data(part, "Veuillez trouver en attaché votre quittance.", CURL_ZERO_TERMINATED);
        part = curl_mime_addpart(mime);
        curl_mime_filedata(part, filename);
        curl_mime_type(part, "application/pdf");
        curl_mime_filename(part, filename);
        curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            printf("L'email n'a pas pu etre envoyé: %s\n", curl_easy_strerror(res));
        else
            printf("L'email a été envoyé avec succès à l'adresse '%s'.\n", email_address);
        
        curl_slist_free_all(recipients);
        //curl_slist_free_all(headers);
        curl_mime_free(mime);
        curl_easy_cleanup(curl);
    }
    return 0;
}