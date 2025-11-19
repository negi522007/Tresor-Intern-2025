#!/usr/bin/env python3
##
## EPITECH PROJECT, 2025
## receipt
## File description:
## python backend
##

from flask import Flask, request, render_template
from fpdf import FPDF
from datetime import datetime
from flask_mail import Mail
import send_mail

app = Flask(__name__)
app.config['MAIL_SERVER'] = 'smtp.gmail.com'
app.config['MAIL_PORT'] = 587
#app.config['MAIL_USE_SSL'] = True
app.config['MAIL_USE_TLS'] = True
app.config['MAIL_USERNAME'] = "gastonagbdl@gmail.com"
app.config['MAIL_DEFAULT_SENDER'] = "gastonagbdl@gmail.com"
with open("../secret_password", "r") as f:
    app.config['MAIL_PASSWORD'] = f.read()
mail = Mail(app)

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

def generate_receipt(infos):
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
    if infos["email_address"] is not "":
        send_mail.send_receipt(recipient=infos["email_address"], filepath=f"{infos["receipt_date"]}-quittance-{infos["receipt_reference"]}.pdf", mail=mail)

@app.route("/", methods=['GET', 'POST'])
def main():
    if request.method == "POST":
        amount = int(request.form.get("receipt_amount"))
        infos = { "customer_name": request.form.get("customer_name"),
                  "customer_phone": request.form.get("customer_phone"),
                  "email_address": request.form.get("email_address"),
                  "receipt_amount": f" {amount} FCFA",
                  "receipt_place": request.form.get("receipt_place"),
                  "payment_method": request.form.get("payment_method"),
                  "receipt_date": request.form.get("receipt_date"),
                  "receipt_reference": "",
                  "receipt_time": ""
               }
        generate_receipt(infos)
    return render_template("index.html")

if __name__ == "__main__":
    app.run(debug=True)