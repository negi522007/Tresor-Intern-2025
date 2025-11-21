#!/usr/bin/env python3
##
## EPITECH PROJECT, 2025
## receipt
## File description:
## generate pdf file
##

import send_mail
from fpdf import FPDF
from datetime import datetime

def new_ref(str):
    i = 3
    nbr = 0

    while str[i] != '\0' and str[i] >= '0' and str[i] <= '9': 
        nbr = ((nbr * 10) + int(str[i]))
        i += 1
    nbr = nbr + 1
    ref = f"AA-{nbr:06d}-TGE"
    with open("../receipt_reference", "w") as f:
        f.write(ref)

def generate_receipt(infos, mail):
    pdf = FPDF(orientation='P', unit='mm', format=(240, 150))
    pdf.add_page()
    pdf.image('../negi-peaces.jpeg', x=218, y=132, w=20)
    pdf.image('../src/header.png', x=-6, y=8, w=250)
    pdf.set_font("Arial", style="B", size=18)
    pdf.cell(200, 75, txt="Quittance numérique", ln=True, align="C")
    pdf.set_font("Arial", style="B", size=12)
    pdf.text(10, 70, txt="Nom du client: ")
    pdf.text(10, 80, txt="Numéro de téléphone du client: ")
    pdf.text(10, 90, txt="Adresse mail du client: ")
    pdf.text(10, 100, txt="Montant de la quittance: ")
    pdf.text(10, 110, txt="Mode de paiement: ")
    pdf.text(150, 70, txt="Référence de la quittance: ")
    pdf.text(150, 80, txt="Heure de la quittance: ")
    pdf.text(150, 90, txt="Date de la quittance: ")
    pdf.text(150, 100, txt="Poste comptable: ")
    pdf.set_font("Arial", size=12)
    pdf.text(42, 70, txt=infos["customer_name"])
    pdf.text(75, 80, txt=infos["customer_phone"])
    pdf.text(58, 90, txt=infos["email_address"])
    pdf.text(60, 100, txt=infos["receipt_amount"])
    pdf.text(51, 110, txt=infos["payment_method"])
    with open("../receipt_reference", "r") as f:
        infos["receipt_reference"] = f.read()
    pdf.text(205, 70, txt=infos["receipt_reference"])
    new_ref(infos["receipt_reference"])
    infos["receipt_time"] = datetime.now().strftime("%H:%M:%S")
    pdf.text(196, 80, txt=infos["receipt_time"])
    pdf.text(193, 90, txt=infos["receipt_date"])
    pdf.text(187, 100, txt=infos["receipt_place"])
    pdf.output(f"{infos["receipt_date"]}-quittance-{infos["receipt_reference"]}.pdf")
    if infos["email_address"]:
        send_mail.send_receipt(recipient=infos["email_address"], filepath=f"{infos["receipt_date"]}-quittance-{infos["receipt_reference"]}.pdf", mail=mail)
