#include "../forras/std_lib_facilities.h"

struct Person
{
    private:
        string firstName;
        string secondName;
        int age;

    public:
        void SetFirstName(string n)
        {
            firstName = n;

            string invalid[] = {";", ":", "\"", "\'", "[", "]", "*", "&", "^", "%", "$", "#", "@", "!", "\""};

            for (int i = 0; i < size(invalid); i++)
            {
                if (n.find(invalid[i]) != string::npos)
                {
                    throw runtime_error("Invalic character used in the name.");
                }
            }
        }
        string GetFirstName()
        {
            return firstName;
        }
        void SetSecondName(string n)
        {
            secondName = n;

            string invalid[] = {";", ":", "\"", "\'", "[", "]", "*", "&", "^", "%", "$", "#", "@", "!", "\""};

            for (int i = 0; i < size(invalid); i++)
            {
                if (n.find(invalid[i]) != string::npos)
                {
                    throw runtime_error("Invalic character used in the name.");
                }
            }
        }
        string GetSecondName()
        {
            return secondName;
        }
        void SetAge(int a)
        {
            age = a;
            if(age < 0 || age >= 150)
            {
                throw runtime_error("The specified number is out of range.");
            }
        }
        int GetAge()
        {
            return age;
        }

    /*
    //default constructor
    Person(){};
    //constructor
    Person(string n, int a)
    {
        name = n;
        age = a;
    }*/
};
istream& operator>>(istream& is, Person& d){
    int age;
    string firstName;
    string secondName;
    is >> firstName >> secondName >> age;
    if(!is)
    {
        return is;
    }
    Person person;
    person.SetFirstName(firstName);
    person.SetSecondName(secondName);
    person.SetAge(age);
    d = person;
    return is;
}
ostream& operator<<(ostream& os, Person& d){
    return os << d.GetFirstName() << " " << d.GetSecondName() << " " << d.GetAge() << endl;
}

vector<Person> persons;

int main(){
    //1.
    Person firstPerson;
    firstPerson.SetFirstName("Goofy");
    firstPerson.SetAge(63);
    cout << firstPerson.GetFirstName() << " is " << firstPerson.GetAge() << " years old." << endl;
    //2.
    Person opPerson;
    cin >> opPerson;
    cout << opPerson;
    //8.
    for (int i = 0; i < 5; i++)
    {
        Person p;
        cin >> p;
        persons.push_back(p);
    }
    for (Person i : persons)
    {
        cout << i;
    }

    return 0;
}