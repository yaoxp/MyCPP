# this

[learncpp.com](https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/)

## *this* pointer
```c++
simple.setID(2)
```

```c++
Simple::setID(Simple * const this, int id);
Simple::setID(&simple, 2);
// note that simple has been changed from an object prefix to a function argument.
```
``
1. When we call `simple.setID(2)`, the compiler actually calls `Simple::setID(&simple, 2)`, and `simple` is passed by address to the function.
2. The function has a hidden parameter named `this` which receives the address of `simple`.
3. Member variables inside `setID()` are prefixed with `this->`, which points to `simple`. So when the compiler evaluates `this->m_id` it's actually resolving to `simple.m_id`.

## Explicitly referencing *this*
1. If you have a member function that has a parameter with the same name as a data member, you can disambiguate them by using `this`.
```c++
struct Something
{
    int data{}; // not using m_ prefix because this is a struct

    void setData(int data)
    {
        this->data = data; // this->data is the member, data is the local parameter
    }
};
```

2. It can sometimes be useful to have a member function return the implicit object as a return value.
The primary reason to do this is to allow member function to be "chained" together, so several member functions
can be called on the same object in a single expression!  This is called `function chaining`(or`method chaining`).
```c++
class Calc
{
private:
    int m_value{};

public:
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() { return m_value; }
};
```
```c++
#include <iostream>

int main()
{
    Calc calc{};
    calc.add(5).sub(3).mult(4); // method chaining

    std::cout << calc.getValue() << '\n';

    return 0;
}
```

3. Resetting a class back to default state
If your class has a default constructor, you may be interested in providing a way to return an existing object back to its default state.

The best way to reset a class back to a default state is to create a `reset()` member function, have that function create a new object(using
the default constructor), and then assign that new object to the current implicit object, like this:
```c++
#include <iostream>

class Calc
{
private:
    int m_value{};

public:
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() { return m_value; }

    void reset() { *this = {}; }
};


int main()
{
    Calc calc{};
    calc.add(5).sub(3).mult(4);

    std::cout << calc.getValue() << '\n'; // prints 8

    calc.reset();

    std::cout << calc.getValue() << '\n'; // prints 0

    return 0;
}
```

## Why *this* a pointer and not a reference
when `this` was added to the languages, reference didn't exist yet.

If `this` were added to the C++ language today, it would undoubtedly be
a reference instead of a pointer. In other more modern C++-like languages,
such as Java and C#, `this` is implemented as a reference.