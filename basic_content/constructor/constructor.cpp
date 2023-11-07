//
// Created by yaoxp on 2023/10/12.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Rectangle {
public:
    Rectangle() = default;
    Rectangle(int width, int high) : width_(width), high_(high) {}

    // Copy constructor
    Rectangle(const Rectangle& R): width_(R.width_), high_(R.high_) {
        cout << "copy constructor\n";
    }

    void printf() const {
        cout << "width: " << width_ << endl;
        cout << "high: " << high_ << endl;
    };

    [[nodiscard]] int area() const {
        return width_ * high_;
    }

    [[nodiscard]] int perimeter() const {
        return width_ * 2 + high_ * 2;
    };
private:
    int width_{};
    int high_{};
};

void printRectangle(Rectangle f) {
    f.printf();
}

Rectangle generateRectangle(int n, int d) {
    Rectangle r{n, d};
    return r;
}

int main() {
    Rectangle f{5,3};
    printRectangle(f);

    Rectangle r2{generateRectangle(1, 2)};
    printRectangle(r2);


    return 0;
}