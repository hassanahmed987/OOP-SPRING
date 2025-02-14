#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;
const int MAX_BORROWERS = 50;

class Library {
private:
    string bookList[MAX_BOOKS];
    bool availableBooks[MAX_BOOKS];
    string borrowedBooks[MAX_BORROWERS];
    int totalBooks;
    int totalBorrowers;

public:
    Library() : totalBooks(0), totalBorrowers(0) {
        for (int i = 0; i < MAX_BOOKS; ++i) {
            availableBooks[i] = true;
        }
    }

    void addBook(const string& bookName) {
        if (totalBooks < MAX_BOOKS) {
            bookList[totalBooks] = bookName;
            availableBooks[totalBooks] = true;
            totalBooks++;
            cout << "Book \"" << bookName << "\" added to the library." << endl;
        } else {
            cout << "Library is full! Cannot add more books." << endl;
        }
    }

    void lendBook(const string& bookName, const string& studentName) {
        bool found = false;
        for (int i = 0; i < totalBooks; ++i) {
            if (bookList[i] == bookName && availableBooks[i]) {
                availableBooks[i] = false;
                borrowedBooks[totalBorrowers] = studentName;
                totalBorrowers++;
                cout << studentName << " borrowed the book: " << bookName << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Sorry, the book \"" << bookName << "\" is not available." << endl;
        }
    }

    void returnBook(const string& bookName, const string& studentName) {
        bool found = false;
        for (int i = 0; i < totalBooks; ++i) {
            if (bookList[i] == bookName && !availableBooks[i]) {
                availableBooks[i] = true;
                for (int j = 0; j < totalBorrowers; ++j) {
                    if (borrowedBooks[j] == studentName) {
                        borrowedBooks[j] = "";
                        cout << studentName << " returned the book: " << bookName << endl;
                        found = true;
                        break;
                    }
                }
                break;
            }
        }

        if (!found) {
            cout << "The book \"" << bookName << "\" was not borrowed by " << studentName << "." << endl;
        }
    }

    void showAvailableBooks() const {
        cout << "Available books in the library:" << endl;
        for (int i = 0; i < totalBooks; ++i) {
            if (availableBooks[i]) {
                cout << bookList[i] << endl;
            }
        }
    }
};

int main() {
    Library library;

    library.addBook("C++ Programming");
    library.addBook("Data Structures");
    library.addBook("Algorithms");
    
    library.showAvailableBooks();

    library.lendBook("C++ Programming", "Alice");
    library.lendBook("Algorithms", "Bob");

    library.showAvailableBooks();

    library.returnBook("C++ Programming", "Alice");

    library.showAvailableBooks();

    return 0;
}
