#include "gui/std_lib_facilities.h"

struct Person
{
    string name;
    int age;

    //default constructor

    Person(string n, int a){
        name = n;
        age = a;
    }
    
};

istream& operator>>(istream& is, Person& d){
    int age;
    string name;
    is >> name >> age;
    if(!is)
    {
        return is;
    }
    Person person(name, age);
    d = person;
    return is;
}
ostream& operator<<(ostream& os, const Person& d){
    return os << d.name << " " << d.age << endl;
}

int main(){
    //1.
    Person firstPerson;
    firstPerson.name = "Goofy";
    firstPerson.age = 63;
    cout << firstPerson.name << " is " << firstPerson.age << " years old." << endl;
    //2.
    Person opPerson;
    cin >> opPerson;
    cout << opPerson;
    //3.
}