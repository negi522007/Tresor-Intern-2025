/*
** EPITECH PROJECT, 2025
** receipt
** File description:
** generate file
*/

#include "../include/receipt.h"

int gen_file(infos_t receipt_infos)
{
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Image image;
    char amount[100];
    int reference = 0;
    FILE *file = NULL;

    pdf = HPDF_New(NULL, NULL);
    page = HPDF_AddPage(pdf);
    HPDF_Page_SetWidth(page, 595);
    HPDF_Page_SetHeight(page, 842);
    image = HPDF_LoadPngImageFromFile(pdf, "src/header.png");
    HPDF_Page_DrawImage(page, image, 0, 750, 600, 100);
    HPDF_Page_BeginText(page);
    HPDF_Page_SetFontAndSize(page, HPDF_GetFont(pdf, "Helvetica", NULL), 20);
    HPDF_Page_TextOut(page, 200, 720, "Quittance numerique");
    HPDF_Page_SetFontAndSize(page, HPDF_GetFont(pdf, "Helvetica", NULL), 10);
    HPDF_Page_TextOut(page, 10, 675, "Nom du client: ");
    HPDF_Page_TextOut(page, 80, 675, receipt_infos.customer_name);
    HPDF_Page_TextOut(page, 10, 655, "Numero de telephone du client: ");
    HPDF_Page_TextOut(page, 152, 655, receipt_infos.customer_phone);
    HPDF_Page_TextOut(page, 10, 635, "Adresse mail du client: ");
    HPDF_Page_TextOut(page, 115, 635, receipt_infos.email_address);
    HPDF_Page_TextOut(page, 350, 675, "Date de la quittance: ");
    HPDF_Page_TextOut(page, 450, 675, receipt_infos.receipt_date);
    HPDF_Page_TextOut(page, 350, 655, "Heure de la quittance: ");
    HPDF_Page_TextOut(page, 458, 655, "yo");
    HPDF_Page_TextOut(page, 350, 635, "Reference de la quittance: ");
    HPDF_Page_TextOut(page, 475, 635, receipt_infos.receipt_reference);
    reference = my_getnbr(receipt_infos.receipt_reference) + 1;
    sprintf(receipt_infos.receipt_reference, "AA%06d-TGE", reference);
    file = fopen("receipt_reference", "w");
    fwrite(receipt_infos.receipt_reference, 12, 1, file);
    fclose(file);
    HPDF_Page_TextOut(page, 10, 540, "Montant de la quittance: ");
    sprintf(amount, "%d FCFA", receipt_infos.receipt_amount);
    HPDF_Page_TextOut(page, 120, 540, amount);
    HPDF_Page_TextOut(page, 10, 520, "Poste comptable: ");
    HPDF_Page_TextOut(page, 90, 520, receipt_infos.receipt_place);
    HPDF_Page_TextOut(page, 10, 500, "Mode de payement: ");
    HPDF_Page_TextOut(page, 102, 500, receipt_infos.payment_method);
    HPDF_Page_EndText(page);
    sprintf(amount, "quittance_%s.pdf", receipt_infos.receipt_reference);
    HPDF_SaveToFile(pdf, amount);
    HPDF_Free(pdf);
    return 0;
}
