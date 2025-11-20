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

def research(infos):
    connexion = sqlite3.connect("receipt.db")
    cursor = connexion.cursor()
    params = []
    query_stc = "SELECT * FROM infos WHERE 1=1"
    if infos["receipt_reference"]:
        query_stc += " AND receipt_reference = ?"
        params.append(infos["receipt_reference"])
    if infos["customer_name"]:
        query_stc += " AND customer_name = ?"
        params.append(infos["customer_name"])
    if infos["customer_phone"]:
        query_stc += " AND customer_phone = ?"
        params.append(infos["customer_phone"])
    if infos["email_address"]:
        query_stc += " AND email_address = ?"
        params.append(infos["email_address"])
    if infos["receipt_amount"]:
        query_stc += " AND receipt_amount = ?"
        params.append(infos["receipt_amount"])
    if infos["receipt_place"]:
        query_stc += " AND receipt_place = ?"
        params.append(infos["receipt_place"])
    if infos["payment_method"]:
        query_stc += " AND payment_method = ?"
        params.append(infos["payment_method"])
    if infos["receipt_time"]:
        query_stc += " AND receipt_time = ?"
        params.append(infos["receipt_time"])
    if infos["receipt_date"]:
        query_stc += " AND receipt_date = ?"
        params.append(infos["receipt_date"])
    cursor.execute(query_stc, params)
    results = cursor.fetchall()
    connexion.close()
    print("\n\n\n", results, "\n\n")
    return results