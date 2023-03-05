/* Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з 
елементами даних класів у кожному класі. 
Схема успадкування на рисунку за варіантами. 
Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. 
Вивести розміри об’єктів даних класів*/

#include <iostream>

using namespace std;

class BaseCircle
{
protected:
    int dat;
public:
    BaseCircle() : dat(1) {}
    BaseCircle(int d) : dat(d) {}
};

class Circle1 : protected BaseCircle
{
protected:
    int circle1;
public: 
    Circle1() : circle1(1){}
    Circle1(int c1) : circle1(c1){}
    Circle1(int c1, int cc1) : BaseCircle(c1), circle1(cc1){}
};

class Circle2 : protected BaseCircle, Circle1
{
protected:
    int circle2;
public: 
    Circle2() : circle2(1){}
    Circle2(int c2) : circle2(c2){}
    Circle2(int a, int b, int c) : BaseCircle(a), Circle1(b, c){}
};

class Circle3 : protected Circle1
{
protected: 
    int circle3;
public:
    Circle3() : circle3(1){}
    Circle3(int c3) : circle3(c3){}
    Circle3(int c3, int cc3, int ccc3) : Circle1(c3, cc3), circle3(ccc3){}    
};

class Circle4 : protected Circle2, Circle3
{
protected:
    int circle4;
public:
    Circle4() : circle4(1){}
    Circle4(int c4) : circle4(c4){}
    Circle4(int a, int b, int c, int d, int e, int f) : Circle2(a, b, c), Circle3(d, e, f){}

    void show()
    {
        cout << "dat =? Error C2385 ambiguous access level dat " << endl;
    }
};

//virtual

class Circle1V : virtual protected BaseCircle
{
protected:
    int circle1;
public:
    Circle1V() : circle1(1){}
    Circle1V(int c1) : circle1(c1){}
    Circle1V(int c1, int cc1) : BaseCircle(c1), circle1(cc1){}
};

class Circle2V : virtual protected BaseCircle, Circle1V
{
protected:
    int circle2;
public: 
    Circle2V() : circle2(1){}
    Circle2V(int c2) : circle2(c2){}
    Circle2V(int a, int b, int c) : BaseCircle(a), Circle1V(b, c){}
};

class Circle3V : virtual protected Circle1V
{
protected: 
    int circle3;
public:
    Circle3V() : circle3(1){}
    Circle3V(int c3) : circle3(c3){}
    Circle3V(int c3, int cc3, int ccc3) : Circle1V(c3, cc3), circle3(ccc3){}    
};

class Circle4V : virtual protected Circle2V, Circle3V
{
protected:
    int circle4;
public:
    Circle4V() : circle4(1){}
    Circle4V(int c4) : circle4(c4){}
    Circle4V(int a, int b, int c, int d, int e, int f) : Circle2V(a, b, c), Circle3V(d, e, f){}

    void show()
    {
        cout << "dat =? Error C2385 ambiguous access level dat " << endl;
    }
};


int main()
{
    //Circle4 a, b(1, 2, 3, 4, 5);

    cout << "Default:" << endl;
    cout << "Base size: " << sizeof(BaseCircle) << " bytes" << endl;
    cout << "Circle1 size: " << sizeof(Circle1) << " bytes" << endl;
    cout << "Circle2 size: " << sizeof(Circle2) << " bytes" << endl;
    cout << "Circle3 size: " << sizeof(Circle3) << " bytes" << endl;
    cout << "Circle4 size: " << sizeof(Circle4) << " bytes" << endl;

    cout << "Virtual:" << endl;
    cout << "Base size: " << sizeof(BaseCircle) << " bytes" << endl;
    cout << "Circle1V size: " << sizeof(Circle1V) << " bytes" << endl;
    cout << "Circle2V size: " << sizeof(Circle2V) << " bytes" << endl;
    cout << "Circle3V size: " << sizeof(Circle3V) << " bytes" << endl;
    cout << "Circle4V size: " << sizeof(Circle4V) << " bytes" << endl;

    return 0;
}