#include <iostream>
#include <stdexcept>

template <typename Type>
class RealVector {
    Type* data;
    size_t current_size;
    size_t current_capacity;

    void resize(size_t new_capacity) {
        if (this->current_capacity == new_capacity) return;

        Type* new_data = new Type[new_capacity];

        for (size_t i = 0; i < current_size; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        current_capacity = new_capacity;
    }

public:
    RealVector() : data(nullptr), current_size(0), current_capacity(0) {}

    ~RealVector() { delete[] data; }

    size_t size() const { return current_size; }
    size_t capacity() const { return current_capacity; }

    bool empty() const { return current_size == 0; }

    void push_back(const Type& value) {
        if (current_size == current_capacity) {
            size_t new_capacity = (current_capacity == 0) ? 1 : current_capacity * 2;
            resize(new_capacity);
        }
        data[current_size++] = value;
    }

    void push(const Type& value, size_t index) {
        if (index > current_size) {
            throw std::out_of_range("Unavailable operation");
        }

        if (current_size >= current_capacity) {
            size_t new_capacity = (current_capacity == 0) ? 1 : current_capacity * 2;
            Type* new_data = new Type[new_capacity];

            for (size_t i = 0; i < index; ++i) {
                new_data[i] = data[i];
            }

            for (size_t i = index; i < current_size; ++i) {
                new_data[i + 1] = data[i];
            }

            delete[] data;
            data = new_data;
            current_capacity = new_capacity;
        }
        else {
            for (size_t i = current_size; i > index; --i) {
                data[i] = data[i - 1];
            }
        }

        data[index] = value;
        ++current_size;
    }

    void pop_back() {
        if (current_size == 0) {
            throw std::out_of_range("Unavailable operation");
        }
        --current_size;
        data[current_size].~Type();
    }

    void pop(size_t index) {
        if (index >= current_size) {
            throw std::out_of_range("Unavailable operation");
        }

        data[index].~Type();

        for (size_t i = index; i < current_size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --current_size;
    }

    void print() {
        for (size_t i = 0; i < current_size; i++) {
            std::cout << data[i] << ",";
        }
        std::cout << std::endl;
    }
};

int main() {
    RealVector<int> vector;

    for (int i = 1; i <= 10; ++i) {
        vector.push_back(i * 10);
    }
    vector.print();

    vector.push(55, 6);
    vector.push(77, 8);
    vector.print();

    vector.pop(2);
    vector.pop(4);
    vector.print();
}