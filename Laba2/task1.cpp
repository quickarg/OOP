#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Введите название: ";
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
        cin.ignore();
    }
    void putdata() {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }
};

class Book : public Publication {
private:
    int page_count;
public:
    void getdata() {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> page_count;
        cin.ignore();
    }
    void putdata() {
        Publication::putdata();
        cout << "Количество страниц: " << page_count << endl;
    }
};

class Type : public Publication {
private:
    float recording_time;
public:
    void getdata() {
        Publication::getdata();
        cout << "Введите время записи в минутах: ";
        cin >> recording_time;
        cin.ignore();
    }
    void putdata() {
        Publication::putdata();
        cout << "Время записи: " << recording_time << " минут" << endl;
    }
};

int main() {
    Book book;
    Type audio;

    cout << "Введите данные для книги" << endl;
    book.getdata();
    cout << endl;

    cout << "Введите данные для аудиозаписи" << endl;
    audio.getdata();
    cout << endl;

    cout << "Данные о книге" << endl;
    book.putdata();
    cout << endl;

    cout << "Данные об аудиозаписи" << endl;
    audio.putdata();

    return 0;
}