CREATE TABLE infos (
    receipt_reference TEXT PRIMARY KEY,
    customer_name TEXT NOT NULL,
    customer_phone TEXT NOT NULL,
    email_address TEXT,
    receipt_amount INTEGER NOT NULL,
    receipt_place TEXT NOT NULL,
    payment_method TEXT CHECK (payment_method IN ('ESPECE', 'CHEQUE', 'MOMO')),
    receipt_date TEXT NOT NULL,
    receipt_time TEXT NOT NULL
);