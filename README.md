# 🚀 Tresor-Intern-2025 -- Digital Receipt Generation System

A complete system (C program + Flask web application) for generating and
managing digital receipts for the *Trésorerie Générale de l'État du
Bénin*, following official specifications.\
The project collects customer payment data, generates a receipt, stores
it in a structured file system, and sends it by email when available.

## 📌 Table of Contents

-   [Project Overview](#project-overview)
-   [Features](#features)
-   [Technology Stack](#technology-stack)
-   [Repository Structure](#repository-structure)
-   [C Application](#c-application)
-   [Web Application (Flask)](#web-application-flask)
-   [Admin Login](#admin-login)
-   [Environment Variables](#environment-variables)
-   [Running the Application Locally](#running-the-application-locally)
-   [Author](#author)

# 🧾 Project Overview

This project implements a **digital receipt generation system** based on
the problem specification provided by the *Direction Générale du Trésor
et de la Comptabilité Publique* (DGTCP).\
It was first developed in **C** as a console application and later
improved into a **web application** using **Flask** to offer a modern
user interface.

The application collects customer information, generates a receipt with
a unique reference number, stores it in a folder corresponding to the
current date, and sends it by email if an address is provided.

# ⭐ Features

### 🟦 Common Features (C + Web version)

-   Collect customer information:
    -   Name\
    -   Phone number\
    -   Email (optional)\
    -   Amount\
    -   Payment method (ESPECE, CHEQUE, MOMO)\
    -   Receipt date\
    -   Receipt place\
-   Automatic receipt reference generation:\
    Format → **AA999999-TGE**
-   PDF receipt generation
-   Automatic directory structure based on date\
-   Store one file per receipt\
-   Display/print a receipt informations before create the file\
-   Search a specific receipt\
-   List all receipts
-   Automatic email sending

# 🌐 Web Application (Flask)

The Flask version improves the UX and adds: - Web form to collect
information\
- Admin login & protected query page\
- Page to search/filter receipts\
- Logout system\
- Deployment on Render

### Available Routes

  Route       Description
  ----------- -----------------------------------------
  `/`         Customer form → Generate & send receipt
  `/login`    Login as administrator
  `/query`    Search existing receipts
  `/logout`   Logout admin

# 🔐 Admin Login

Default credentials:

    Username: admin
    Password: Iamadmin

# 🛠 Technology Stack

### C Application

-   C99\
-   libHaru\
-   libcurl\
-   Makefile\
-   File-based receipt storage

### Web Application

-   Python 3\
-   Flask\
-   SQLite database\
-   Flask-Mail\
-   FPDF\
-   Gunicorn\
-   HTML / CSS / JavaScript

### Deployment

-   Render.com\
-   GitHub integration\
-   Environment variables for secret data

# 📁 Repository Structure

Tresor-Intern-2025/
│
├── Makefile
│
├── src/                          # C Application source code
│   ├── file_managing.c
│   ├── gen_file.c
│   ├── get_infos.c
│   ├── main.c
│   ├── print_infos.c
│   └── send_receipt.c
│
├── include/
│   └── receipt.h                 # Header file for the C program
│
├── webApp/                       # Flask Web Application
│   ├── app.py                    
│   ├── database.py               
│   ├── generate.py               
│   ├── receipt.db                
│   ├── send_mail.py              
│   ├── templates/                # HTML templates
│   └── static/                   # CSS files
│
└── README.md

# 🔐 Environment Variables

    MAIL_USERNAME
    MAIL_PASSWORD
    SECRET_KEY

# 🧪 Running the Application Locally

This project contains **two independent applications**:

- A **C console application** (run from the repository root)
- A **Flask web application** (run from the `webApp/` directory)

Both versions follow the same logic and generate identical receipts.

---

## 1️⃣ Running the C Application (Console Mode)

### Compile the project
At the root of the repository, run:

```bash
make re
```

This compiles all .c files inside src/ and produces the executable.

Run the program

```bash
./receipt
```
### 1. Navigate into the folder

```bash
cd WebApp
```

### 2. Create and activate a virtual environment
```bash
    python3 -m venv venv
    source venv/bin/activate
```

### 3. Install dependencies
```bash
    pip install -r requirements.txt
```
### 4. Run the web application
```bash
    python3 app.py
```
App runs at:

    http://127.0.0.1:5000

# 👤 Author

**Exaucé AGBODJALOU**\
Intern -- Direction de l'Informatique et des Archives - Service Etudes & Developpement\
Trésorerie Générale de l'État -- Bénin
