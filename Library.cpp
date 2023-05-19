#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Book structure
struct Book {
    string title;
    string author;
    string genre;
    string publicationYear;
};

// Function to display the menu
void displayMenu() {
    cout << "==== Library Management System ====" << endl;
    cout << "1. Add a Book" << endl;
    cout << "2. Display All Books" << endl;
    cout << "3. Search for a Book" << endl;
    cout << "4. Save Books to File" << endl;
    cout << "5. Load Books from File" << endl;
    cout << "6. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Enter your choice: ";
}

// Function to add a book
void addBook(vector<Book>& books) {
    Book newBook;
    cout << "\nEnter Book Title: ";
    getline(cin >> ws, newBook.title);
    cout << "Enter Author Name: ";
    getline(cin >> ws, newBook.author);
    cout << "Enter Genre: ";
    getline(cin >> ws, newBook.genre);
    cout << "Enter Publication Year: ";
    getline(cin >> ws, newBook.publicationYear);

    books.push_back(newBook);
    cout << "\nBook added successfully!" << endl;
}

// Function to display all books
void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available." << endl;
        return;
    }

    cout << "==== Book Catalog ====" << endl;
    for (const Book& book : books) {
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Genre: " << book.genre << endl;
        cout << "Publication Year: " << book.publicationYear << endl;
        cout << "----------------------" << endl;
    }
}

// Function to search for a book by title
void searchBook(const vector<Book>& books, const string& title) {
    bool found = false;

    for (const Book& book : books) {
        if (book.title == title) {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Genre: " << book.genre << endl;
            cout << "Publication Year: " << book.publicationYear << endl;
            cout << "----------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to save books to a file
void saveBooksToFile(const vector<Book>& books) {
    ofstream file("books.txt");
    if (file.is_open()) {
        for (const Book& book : books) {
            file << book.title << endl;
            file << book.author << endl;
            file << book.genre << endl;
            file << book.publicationYear << endl;
        }
        file.close();
        cout << "Books saved to file." << endl;
    } else {
        cout << "Error: Unable to save books to file." << endl;
    }
}

// Function to load books from a file
void loadBooksFromFile(vector<Book>& books) {
    ifstream file("books.txt");
    if (file.is_open()) {
        books.clear();
        string line;
        while (getline(file, line)) {
            Book book;
            book.title = line;
            getline(file, book.author);
            getline(file, book.genre);
            getline(file, book.publicationYear);
            books.push_back(book);
        }
        file.close();
        cout << "Books loaded from file." << endl;
    } else {
        cout << "Error: Unable to load books from file." << endl;
    }
}

int main() {
    vector<Book> books;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                displayBooks(books);
                break;
            case 3: {
                cin.ignore();
                cout << "Enter the title to search: ";
                string title;
                getline(cin >> ws, title);
                searchBook(books, title);
                break;
            }
            case 4:
                saveBooksToFile(books);
                break;
            case 5:
                loadBooksFromFile(books);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}
