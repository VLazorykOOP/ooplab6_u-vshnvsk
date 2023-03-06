/*Створити абстрактний клас набір дані із віртуальною функцією норма. 
Створити похідні класи: комплексне число, вектор з 10 елементів, матриця (2х2). 
Визначити функцію норми: для комплексних чисел - модуль у квадраті, для вектора - корінь */
#include <iostream>
#include <math.h>

using namespace std;

class DataSet
{
public:
    virtual double norm() = 0;
};

class ComplexNumber : public DataSet
{
private:
    double X, Y;
public:
    ComplexNumber(double x, double y) : X(x), Y(y){}
    virtual double norm()
    {
        return X*X + Y*Y;
    }
};

class Vector10 : public DataSet
{
private:
    double elements[10];
public: 
    Vector10(double e0, double e1, double e2, double e3, double e4, 
    double e5, double e6, double e7, double e8, double e9)
    {
        elements[0] = e0;
        elements[1] = e1;
        elements[2] = e2;
        elements[3] = e3;
        elements[4] = e4;
        elements[5] = e5;
        elements[6] = e6;
        elements[7] = e7;
        elements[8] = e8;
        elements[9] = e9;
    }

    virtual double norm()
    {
        double sum = 0;
        for(int i = 0; i < 10; i++)
        {
            sum += elements[i]*elements[i];
        }
        return sqrt(sum);
    }
};

class Matrix2x2 : public DataSet
{
private:
    double elements[2][2];
public:
    Matrix2x2(double e00, double e01, double e10, double e11)
    {
        elements[0][0] = e00;
        elements[0][1] = e01;
        elements[1][0] = e10;
        elements[1][1] = e11;
    }

    virtual double norm()
    {
        double determinant = elements[0][0]*elements[1][1] - elements[0][1]*elements[1][0];
        return determinant;
    }
};

int main()
{
    ComplexNumber c(3, 5);
    cout << "Complex Number: " << c.norm() << endl;

    Vector10 v(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    cout << "Vector: " << v.norm() << endl;

    Matrix2x2 m(1, 2, 3, 4);
    cout << "Matrix 2x2: " << m.norm() << endl;
    return 0;
}