#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class BookType { Fiction, Technical };

class Book {
private:
    string author;
    string title;
    BookType type;

public:
    Book(const string& author, const string& title, BookType type) 
        : author(author), title(title), type(type) {}

    void display() const {
        cout << "Автор: " << author << ", Название: " << title << ", Тип: ";
        if (type == BookType::Fiction) {
            cout << "Художественная литература";
        } else {
            cout << "Техническая литература";
        }
        cout << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        for (const auto& book : books) {
            book.display();
        }
    }
};

int main() {
    Library library;

    Book book1("Джордж Оруэлл", "1984", BookType::Fiction);
    Book book2("Дональд Кнут", "Искусство программирования", BookType::Technical);
    Book book3("Лев Толстой", "Война и мир", BookType::Fiction);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.displayBooks();

    return 0;
}