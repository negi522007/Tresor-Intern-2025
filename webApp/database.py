#!/usr/bin/env python3
##
## EPITECH PROJECT, 2025
## receipt
## File description:
## database management
##

import sqlite3

def insert_infos(infos):
    connexion = sqlite3.connect("receipt.db")
    cursor = connexion.cursor()

    cursor.execute("""INSERT INTO infos (
                   receipt_reference,
                   customer_name,
                   customer_phone,
                   email_address,
                   receipt_amount,
                   receipt_place,
                   payment_method,
                   receipt_date,
                   receipt_time) 
                   VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)""", 
                   (infos["receipt_reference"],
                    infos["customer_name"],
                    infos["customer_phone"],
                    infos["email_address"],
                    infos["receipt_amount"],
                    infos["receipt_place"],
                    infos["payment_method"],
                    infos["receipt_date"],
                    infos["receipt_time"]
                    ))
    connexion.commit()
    connexion.close()