#include <iostream>
#include <string>
#include <stdexcept>

class Transport {
public:
    virtual ~Transport() noexcept = default;
    virtual void info() const = 0;
};

class Bicycle : public Transport {
public:
    Bicycle(const std::string& model) : model(model) {}
    void info() const override {
        std::cout << "Bicycle: " << model << std::endl;
    }
private:
    std::string model;
};

class Car : public Transport {
public:
    Car(const std::string& brand, int power) : brand(brand), power(power) {}
    void info() const override {
        std::cout << "Car: " << brand << ", Power: " << power << " HP" << std::endl;
    }
private:
    std::string brand;
    int power;
};

class Truck : public Transport {
public:
    Truck(const std::string& brand, double load) : brand(brand), load(load) {}
    void info() const override {
        std::cout << "Truck: " << brand << ", Load Capacity: " << load << " tons" << std::endl;
    }
private:
    std::string brand;
    double load;
};

template <typename T>
class PointerArray {
public:
    PointerArray(size_t capacity) : capacity(capacity), size(0) {
        data = new T*[capacity];
    }

    ~PointerArray() {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }
        delete[] data;
    }

    void add(T* obj) {
        if (size >= capacity) {
            throw std::out_of_range("Array is full");
        }
        data[size++] = obj;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return *data[index];
    }

private:
    T** data;
    size_t capacity;
    size_t size;
};

int main() {
    PointerArray<Transport> transports(3);
    transports.add(new Bicycle("Mountain Bike"));
    transports.add(new Car("Toyota", 150));
    transports.add(new Truck("Volvo", 20.5));

    for (size_t i = 0; i < 3; ++i) {
        transports[i].info();
    }

    PointerArray<int> numbers(2);
    numbers.add(new int(42));
    numbers.add(new int(17));

    for (size_t i = 0; i < 2; ++i) {
        std::cout << "Number: " << numbers[i] << std::endl;
    }

    return 0;
}