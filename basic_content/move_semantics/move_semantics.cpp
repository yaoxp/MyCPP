//
// Created by yaoxp on 2023/9/26.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class BigObj {
public:
    explicit BigObj(size_t length) : length_(length) {
        cout << "constructor: " << length << endl;
    }

    // destructor
    ~BigObj() {
        cout << "destructor: " << length_ << endl;
        if (data_ != nullptr) {
            delete[] data_;
            length_ = 0;
        }
    }

    // 拷贝构造函数
    BigObj(const BigObj &other) : length_(other.length_), data_(new int[other.length_]) {
        cout << "copy constructor: " << other.length_ << endl;
        if (other.data_ != nullptr) {
            std::copy(other.data_, other.data_ + length_ - 1, data_);
        }
    }

    // 赋值运算符
    BigObj &operator=(const BigObj &other) {
        cout << "assign operator: " << other.length_ << endl;
        if (this != &other) {
            delete[] data_;
            length_ = other.length_;
            data_ = new int[length_];
            if (other.data_ != nullptr) {
                std::copy(other.data_, other.data_ + length_ - 1, data_);
            }
        }
        return *this;
    }

    // 移动构造函数
    BigObj(BigObj &&other) noexcept {  // 什么时候用noexcept
        cout << "move constructor: " << other.length_ << endl;
        data_ = other.data_;
        length_ = other.length_;

        other.data_ = nullptr;
        other.length_ = 0;
    }

    // 移动赋值运算符
    BigObj &operator=(BigObj &&other) noexcept {
        cout << "move assign operator: " << other.length_ << endl;
        if (this != &other) {
            delete[] data_;

            data_ = other.data_;
            length_ = other.length_;

            other.data_ = nullptr;
            other.length_ = 0;
        }
        return *this;
    }

    [[nodiscard]] size_t length() const {
        return length_;
    }
private:
    size_t length_ = 0;
    int *data_ = nullptr;
};

void testMove(const BigObj &obj) {
    cout << "const BigObj &obj length " << obj.length() << endl;
}

void testMove(const BigObj &&obj) {
    cout << "const BigObj &&obj length " << obj.length() << endl;
}

BigObj fun1() {
    BigObj obj(20);
    return obj;
}

BigObj fun2() {
    BigObj obj(30);
    return std::move(obj);
}

int main() {
//    int &i = 1;       // 错误，1不是右值
    const int &j = 1;   // 引用常量。正确。 编译器会给常量1开辟一片内存，并将引用名作为这片内存的别名。

    {
        std::vector<BigObj> v;
        v.insert(v.end(), BigObj(1));
        v.insert(v.end(), BigObj(2));   // vector扩容
        v.emplace(v.end(), 3);              // vector扩容
        BigObj obj1 = BigObj(4);
        v.insert(v.end(), std::move(obj1));
        //v.insert(v.end(), BigObj(50));
        cout << "========== v count: " << v.size() << endl;
    }

    {
        cout << "===========================" << endl;
        BigObj obj1 = BigObj(10);
        testMove(obj1);

        testMove(BigObj(11));
    }

    {
        cout << "===========================" << endl;
        cout << "不要在函数中使用std::move()进行返回" << endl;
        BigObj obj1 = fun1();
        cout << "~~~~~" << endl;
        BigObj obj2 = fun2();
    }
    return 0;
}