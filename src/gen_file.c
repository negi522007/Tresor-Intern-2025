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
    HPDF_Page_TextOut(page, 80, 675, "yo");
    HPDF_Page_TextOut(page, 10, 655, "Numero de telephone du client: ");
    HPDF_Page_TextOut(page, 152, 655, "yo");
    HPDF_Page_TextOut(page, 10, 635, "Adresse mail du client: ");
    HPDF_Page_TextOut(page, 115, 635, "yo");
    HPDF_Page_TextOut(page, 350, 675, "Date de la quittance: ");
    HPDF_Page_TextOut(page, 450, 675, "yo");
    HPDF_Page_TextOut(page, 350, 655, "Heure de la quittance: ");
    HPDF_Page_TextOut(page, 458, 655, "yo");
    HPDF_Page_TextOut(page, 350, 635, "Reference de la quittance: ");
    HPDF_Page_TextOut(page, 475, 635, "yo");
    HPDF_Page_TextOut(page, 10, 540, "Montant de la quittance: ");
    HPDF_Page_TextOut(page, 120, 540, "yo");
    HPDF_Page_TextOut(page, 10, 520, "Poste comptable: ");
    HPDF_Page_TextOut(page, 90, 520, "yo");
    HPDF_Page_TextOut(page, 10, 500, "Mode de payement: ");
    HPDF_Page_TextOut(page, 102, 500, "yo");
    HPDF_Page_EndText(page);
    HPDF_SaveToFile(pdf, "text.pdf");
    HPDF_Free(pdf);
    return 0;
}
