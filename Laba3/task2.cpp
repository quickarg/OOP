#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Это объект класса Base." << endl;
    }

    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override {
        cout << "Это объект класса Derived." << endl;
    }
};

void add(vector<Base*>& storage, Base* obj) {
    storage.push_back(obj);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<Base*> storage;

    const int numObjects = 10;

    for(int i = 0; i < numObjects; ++i) {
        int randomNum = rand();
        if(randomNum % 2 == 0) {
            Base* obj = new Base();
            add(storage, obj);
        } else {
            Base* obj = new Derived();
            add(storage, obj);
        }
    }

    cout << "Вывод информации об объектах в хранилище:" << endl;
    for(Base* obj : storage) {
        obj->show();
    }

    for(Base* obj : storage) {
        delete obj;
    }
    storage.clear();

    return 0;
}