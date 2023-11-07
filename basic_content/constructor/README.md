# Constructor

`
Many new programmers are confused about whether constructors create the objects or not.
They do not -- the compiler sets up the memory allocation for the object prior to the constructor call.
The constructor is then called on the uninitialized object.
`

开发者自定义构造函数后，编译器不再自动生成默认构造函数，想生成用=default.

## default constructor

## copy constructor
`If you do not provide a copy constructor for your classes, C++ will create a public implicit copy constructor for you`