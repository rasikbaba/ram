#!/bin/bash

# File to store the address book data
address_book_file="address_book.txt"

# Function to create a new address book
create_address_book() {
    touch "$address_book_file"
    echo "Address book created."
}

# Function to view the address book
view_address_book() {
    if [ ! -f "$address_book_file" ]; then
        echo "Address book is empty."
    else
        echo "Address book:"
        cat "$address_book_file"
    fi
}

# Function to insert a record into the address book
insert_record() {
    echo "Enter name:"
    read name
    echo "Enter phone number:"
    read phone
    echo "Enter email:"
    read email

    echo "Name: $name, Phone: $phone, Email: $email" >> "$address_book_file"
    echo "Record inserted."
}

# Function to delete a record from the address book
delete_record() {
    echo "Enter name to delete:"
    read name

    if grep -q "^Name: $name" "$address_book_file"; then
        sed -i "/^Name: $name/d" "$address_book_file"
        echo "Record deleted."
    else
        echo "Record not found."
    fi
}

# Function to modify a record in the address book
modify_record() {
    echo "Enter name to modify:"
    read name

    if grep -q "^Name: $name" "$address_book_file"; then
        echo "Enter new phone number:"
        read phone
        echo "Enter new email:"
        read email

        sed -i "/^Name: $name/ {N; s/Phone: ./Phone: $phone/; s/Email: ./Email: $email/;}" "$address_book_file"
        echo "Record modified."
    else
        echo "Record not found."
    fi
}

# Main program loop
while true; do
    echo "Address Book"
    echo "a) Create address book"
    echo "b) View address book"
    echo "c) Insert a record"
    echo "d) Delete a record"
    echo "e) Modify a record"
    echo "f) Exit"
    echo "Enter your choice:"
    read choice

    case "$choice" in
        a)
            create_address_book
            ;;
        b)
            view_address_book
            ;;
        c)
            insert_record
            ;;
        d)
            delete_record
            ;;
        e)
            modify_record
            ;;
        f)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice."
            ;;
    esac

    echo
done



