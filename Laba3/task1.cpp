#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Detail {
protected:
    string name;
    Detail(const string& n) : name(n) {}
    Detail() : name("") {}
public:
    virtual void getdata() {
        cout << "Введите название детали: ";
        getline(cin, name);
    }

    virtual void putdata() {
        cout << "Деталь: " << name << endl;
    }

    virtual ~Detail() {}

    template<typename T>
    friend T* CreateInstance();
};

class Sborka : public Detail {
protected:
    string assemblyInfo;
    Sborka(const string& n) : Detail(n), assemblyInfo("") {}
    Sborka() : Detail(), assemblyInfo("") {}
public:
    void getdata() override {
        Detail::getdata();
        cout << "Введите информацию о сборке: ";
        getline(cin, assemblyInfo);
    }

    void putdata() override {
        cout << "Сборка: " << name << endl;
        cout << "Информация о сборке: " << assemblyInfo << endl;
    }
    template<typename T>
    friend T* CreateInstance();
};

template<typename T>
T* CreateInstance() {
    return new T();
}

int main() {
    vector<Detail*> items;

    Detail* d = CreateInstance<Detail>();
    d->getdata();
    items.push_back(d);

    Sborka* s = CreateInstance<Sborka>();
    s->getdata();
    items.push_back(s);

    cout << endl << "Вывод данных:" << endl;

    for(auto item : items) {
        item->putdata();
        cout << endl;
    }

    for(auto item : items) {
        delete item;
    }

    return 0;
}