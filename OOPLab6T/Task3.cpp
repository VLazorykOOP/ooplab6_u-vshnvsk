/*Створити ієрархію типів, що описують класи сутностей. 
Класи мають поля характерні сутності та успадковувати поля батьківських класів. 
Визначити конструктори та віртуальні деструктори, перевантажити операції введення та виведення. 
В похідному класі визначити виводить інформацію про об’єкт класу, що успадковане від батьківських класів. 
Продумати ієрархію типів таким чином щоб похідний клас успадковував двох батьків(множинне спадкування).
Ієрархія типів складається з сутностей: людина, батько, мати, дочка.
*/
#include <iostream>
#include <string>

using namespace std;

class Human
{
protected:
    string name;
    int age;
    string sex;
public:
    Human() : name("0"), age(0), sex("0"){}
    Human(string n, int a, string s) : name(n), age(a), sex(s){}
    virtual ~Human(){}

    virtual void print()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Male: " << sex << endl;
    }

    friend istream& operator>>(istream& in, Human& h)
    {
        cout << "Enter name: ";
        in >> h.name;
        cout << "Enter age: ";
        in >> h.age;
        cout << "Enter male: ";
        in >> h.sex;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Human& h)
    {
        out << "Name: " << h.name << endl;
        cout << "Age: " << h.age << endl;
        cout << "Male: " << h.sex << endl;
        return out;
    }
};

class Father : public virtual Human
{
protected:
    int NumChildren;
public:
    Father() : NumChildren(0){}
    Father(string n, int a, string s, int nc) : Human(n, a, s), NumChildren(nc){}
    virtual ~Father(){};

    virtual void print()
    {
        Human::print();
        cout << "Number of children: " << NumChildren << endl;
    }

    friend istream& operator>>(istream& in, Father& f)
    {
        in >> static_cast<Human&>(f);
        cout << "Enter number of children: ";
        in >> f.NumChildren;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Father& f)
    {
        out << static_cast<const Human&>(f) << "Number of children: " << f.NumChildren << endl;
        return out;
    }
};

class Mother : public virtual Human
{
protected:
    string profession;
public:
    Mother() : profession("0"){}
    Mother(string n, int a, string s, string p) : Human(n, a, s), profession(p){}
    virtual ~Mother(){}

    virtual void print()
    {
        Human::print();
        cout << "Profession: " << profession << endl;;
    }

    friend istream& operator>>(istream& in, Mother& m)
    {
        in >> static_cast<Human&>(m);
        cout << "Enter profession: ";
        in >> m.profession;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Mother& m)
    {
        out << static_cast<const Human&>(m) << "Profession: " << m.profession << endl;
        return out;
    }
};

class Daughter : public Father, public Mother
{
public:
    Daughter(){}
    Daughter(string n, int a, string s, int nc, string p) : Human(n, a, s), Father(n, a, s, nc), Mother(n, a, s, p){}
    virtual ~Daughter(){}

    virtual void print()
    {
        Human::print();
        cout << "Number of children(Parents): " << NumChildren << endl;
        cout << "Profession(Mother): " << profession << endl;
    }

    friend istream& operator>>(istream& in, Daughter& d)
    {
        in >> static_cast<Human&>(d) >> static_cast<Father&>(d) >> static_cast<Mother&>(d);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Daughter& d)
    {
        out << static_cast<const Human&>(d) << "Number of children(Parents): " << d.NumChildren << endl;
        cout << "Profession(Mother): " << d.profession << endl;
        return out;
    }
};

int main()
{
    Father f("Anton", 35, "Male", 1);
    cout << "Displaying Father: " << endl; 
    cout << f;

    Mother m("Inna", 32, "Female", "High School");
    cout << "Displaying Mother: " << endl;
    cout << m;

    Daughter d("Anna", 12, "Female", 1, "High School");
    cout << "Displaying Daughter: " << endl;
    cout << d;

    cout << "---Enter dad's details---" << endl;
    Father a;
    cin >> a;
    cout << "---Entered data---" << endl;
    cout << a;

    cout << "---Enter mom's details---" << endl;
    Mother b;
    cin >> b;
    cout << "---Entered data---" << endl;
    cout << b;

    cout << "---Enter data about the daughter---" << endl;
    Father c;
    cin >> c;
    cout << "---Entered data---" << endl;
    cout << c;

    return 0;
}
