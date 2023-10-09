//
// Created by yaoxp on 2023/10/5.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum class Color {
    red,
    green,
    blue,
};

std::ostream &operator<<(std::ostream &out, Color color) {
    switch (color) {
        case Color::red:
            return out << "red";
        case Color::green:
            return out << "green";
        case Color::blue:
            return out << "blue";
        default:
            return out << "???";
    }
}

std::istream &operator>>(std::istream &in, Color &color) {
    int input{};
    in >> input;

    color = static_cast<Color>(input);
    return in;
}

int main() {
    Color color = Color::red;
    cout << "color is " << color << endl;
    Color inputColor;
    cout << "input color: ";
    cin >> inputColor;
    cout << "input color is " << inputColor << endl;
}