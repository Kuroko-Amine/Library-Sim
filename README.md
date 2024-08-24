# Library Simulator in C

This mini-project is a 100% C language library simulator.

## Main Menu
The main menu allows users to log in as either an admin or a student. If you don’t have an account, you’ll need to create one before you can log in. **Creating an account as an admin is different from creating one as a student.** Admin accounts require additional privileges.

> **Note 1:** If you encounter a bug when creating an account, it might be due to an issue with the `scanf` function. You may need to replace `scanf(" %[^\n]s", &...);` with `gets("...");` in your code.

> **Note 2:** You cannot add a book with the title "Plqvmtx." This title is used as a placeholder to indicate that a student’s borrowed book list is empty.

### As a student, you can:
- Borrow books for 3 weeks. If the due date passes, you can either return the book or extend the loan by 3 weeks.
- View all available books.
- Search for a book by its title.
- Check if any of your borrowed books have expired.

### As an admin, you can:
- View all accounts.
- Delete or modify an account.
- Add, remove, or update a book.
- View all students.
- View all borrowed books.
- Search for a book.
