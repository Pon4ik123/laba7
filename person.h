#include <iostream>
#include <string>
#include <random>
#include <ctype.h>
#include <vector>

using namespace std;

size_t random(size_t number1, size_t number2);

class Person {
    string name;
    size_t age;
    size_t pesel;
    int key1;
public:
    Person() : name("Default"), age(0), pesel(0), key1(0) {}
    ~Person() {}

    string getName() const;
    size_t getAge() const;
    size_t getPesel() const;
    size_t getKey() const;

    void setName(string name);
    void setAge(size_t age);
    void setPesel(size_t pesel);
    void setKey(size_t key);

    void random() {
        random_device rd;
        default_random_engine dfe(rd());
        string sPerson[] = { "Lukash", "Anna", "James", "Igor", "Konrad", "Michal", "Tomas", "Marcin", "Kamil" };
        uniform_int_distribution<size_t> ageDist(10, 90);
        uniform_int_distribution<size_t> peselDist(10000000, 999999999);

        age = ageDist(dfe);
        pesel = peselDist(dfe);
        name = sPerson[dfe() % (sizeof(sPerson) / sizeof(string))];
    }

    void operator()(){
        cout << "Name: " <<name << endl;
        cout << "Age: " << age << endl;
        cout << "PESEL: " <<pesel << endl;
        if (key1 != 0) {
            cout << "Key: " <<key1 << endl;
        }
        else {
            cout << "This person doesn't have a car" << endl;
        }
        cout << "\n";
    }

};

void menu();
void create(vector<Person>& person);
void show(const vector<Person>& person);
void add(vector<Person>& person);
void delete_(vector<Person>& person, size_t index);
void edit(vector<Person>& person, const size_t index);
void find(const vector<Person>& person);