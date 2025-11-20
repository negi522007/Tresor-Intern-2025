#!/usr/bin/env python3
##
## EPITECH PROJECT, 2025
## receipt
## File description:
## python backend
##

from flask import Flask, request, render_template, session, redirect, url_for
from flask_mail import Mail
import database
import generate

app = Flask(__name__)
with open("../secret_key", "r") as f:
    app.secret_key = f.read()
app.config['MAIL_SERVER'] = 'smtp.gmail.com'
app.config['MAIL_PORT'] = 587
app.config['MAIL_USE_TLS'] = True
app.config['MAIL_USERNAME'] = "gastonagbdl@gmail.com"
app.config['MAIL_DEFAULT_SENDER'] = "gastonagbdl@gmail.com"
with open("../secret_password", "r") as f:
    app.config['MAIL_PASSWORD'] = f.read()
mail = Mail(app)

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
        generate.generate_receipt(infos, mail=mail)
        database.insert_infos(infos=infos)
    return render_template("index.html")

@app.route("/login", methods=['GET', 'POST'])
def login():
    if request.method == "POST":
        name = request.form.get("name")
        password = request.form.get("password")

        if name == "admin" and password == "Iamadmin":
            session["logged_in"] = True
            return redirect(url_for('query'))
        else:
            return "Login incorrect"
    return render_template("login.html")

@app.route("/query", methods=['GET', 'POST'])
def query():
    if not session.get("logged_in"):
        return redirect(url_for('login'))
    results = []
    if request.method == "POST":
        amount = (request.form.get("receipt_amount"))
        if amount:
            amount = f" {amount} FCFA"
        infos = { "customer_name": request.form.get("customer_name"),
                  "customer_phone": request.form.get("customer_phone"),
                  "email_address": request.form.get("email_address"),
                  "receipt_amount": amount,
                  "receipt_place": request.form.get("receipt_place"),
                  "payment_method": request.form.get("payment_method"),
                  "receipt_date": request.form.get("receipt_date"),
                  "receipt_reference": request.form.get("receipt_reference"),
                  "receipt_time": request.form.get("receipt_time")
               }
        results = database.research(infos=infos)
        #print("\n\n\n", results, "\n\n")
    return render_template("query.html", results=results)

@app.route('/logout')
def logout():
    session.pop('logged_in', None)
    return redirect(url_for('login'))

if __name__ == "__main__":
    app.run(debug=True)