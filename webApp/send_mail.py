#!/usr/bin/env python3
##
## EPITECH PROJECT, 2025
## receipt
## File description:
## send flask email
##
from flask_mail import Message

def send_receipt(recipient, filepath, mail):
    msg = Message("Quittance numérique", 
                  recipients=[recipient], 
                  body="Veuillez recevoir votre quittance numérique."
                  )
    with open(filepath, 'rb') as f:
        msg.attach(filepath, "application/pdf", f.read())
    mail.send(msg)
    return True