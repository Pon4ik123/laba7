#include "car.h"

void menu() {
    cout << "1. Create people\n"
            "2. Show created person\n"
            "3. Add person\n"
            "4. Delete person\n"
            "5. Edit person\n"
            "6. Find person by his first name's letter\n"
            "7. Create cars\n"
            "8. Show cars\n"
            "9. Add one\n"
            "10. Delete one car\n"
            "11. Edit one car\n"
            "12. Find car by his first name's letter\n"
            "13. Read from file\n"
            "14. Exit\n";
}

size_t random(size_t number1, size_t number2) {
    random_device rd;
    default_random_engine dfe(rd());
    uniform_int_distribution<size_t> numberDist(number1, number2);
    return numberDist(dfe);
}

void create(vector<Person>& person) {
    size_t size = 2;
    Person a;
    for (size_t i = 0; i < size; i++) {
        a.random();
        person.push_back(a);
    }
    cout << "Person with data was created" << endl;
}

void show(const vector<Person>& person) {
    cout << "========== Person ==========\n" << endl;
    for(int i = 0; i < person.size(); i++){
    Person temp;
    temp.setName(person[i].getName());
    temp.setAge(person[i].getAge());
    temp.setPesel(person[i].getPesel());
    temp.setKey(person[i].getKey());
    temp();
    }
    cout << "======================" << endl;
}

void add(vector<Person>& person) {
    Person temp;
    temp.random();
    person.push_back(temp);
    cout << "The person was added" << endl;
}

void delete_(vector<Person>& person, size_t index) {
    if (index > 0 && index <= person.size()) {
        --index;
        person.erase(person.begin() + index);
        cout << index + 1 << " person was deleted" << endl;
    }
    else {
        cout << "ERROR: Invalid index!" << endl;
    }
}

void edit(vector<Person>& person, const size_t index) {
    if (index > 0 && index <= person.size()) {
        cin.ignore();
        string name, age, pesel;
        cout << "Type new name, age, and PESEL over SPACE-BAR: ";
        getline(cin, name, ' ');
        getline(cin, age, ' ');
        getline(cin, pesel);
        person[index - 1].setName(name);
        person[index - 1].setAge(atoi(age.c_str()));
        person[index - 1].setPesel(atoi(pesel.c_str()));
        cout << "Person edited successfully!" << endl;
    }
    else {
        cout << "ERROR: Invalid index!" << endl;
    }
}

void find(const vector<Person>& person) {
    char ch{};
    cout << "Enter a letter: ";
    cin >> ch;
    if (islower(ch)) {
        ch = toupper(ch);
    }
    cout << "========== Person ==========\n" << endl;
    for (size_t i = 0; i < person.size(); i++) {
        if (!(person[i].getName().find_first_of(ch))) {
            cout << "Name: " << person[i].getName() << endl;
            cout << "Age: " << person[i].getAge() << endl;
            cout << "PESEL: " << person[i].getPesel() << endl;
            cout << "\n";
        }
    }
    cout << "======================" << endl;
}

void create(vector<Manufacturer>& manufacturer) {
    size_t size = 2;//random(1, 10);
    cout << "Enter the number of manufacturers for car: ";
    int number;
    cin >> number;
    for (size_t i = 0; i < size; i++) {
        Manufacturer a;
        for (int j = 0; j < number; j++) {
           a.setcar(Manufacturer::random());
        }
        manufacturer.push_back(a);
    }
    cout << "Cars with data were created" << endl;

    ofstream file("test1.txt");
    if (file.is_open()) {
        file << manufacturer.size() << "\t" << manufacturer[0].getVectorSize() << "\t";
        file << manufacturer;
    }
    file.close();
}

void show(vector<Manufacturer> manufacturer) {
    cout << "========== Cars ==========" << endl;
    cout << "Manufacturer\t" << "Speed\t" << "Year\t" << "Battery/Gaz" << endl;
    for (size_t i = 0; i < manufacturer.size(); i++) {
        manufacturer[i].print();
        cout << "======================" << endl;
    }
}

void add(vector<Manufacturer>& manufacturer) {
    for (int j = 0; j < manufacturer.size(); j++) {
        manufacturer[j].setcar(Manufacturer::random());
    }
    cout << "New car with data was added" << endl;
}

void delete_(vector<Manufacturer>& manufacturer) {
    int index;
    cout << "Enter the index of the car to delete (1-" << manufacturer[0].getsize() << "): ";
    cin >> index;
    if (index < 1 || index > manufacturer.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    manufacturer.erase(manufacturer.begin() + index);
    cout << "Manufacturer was deleted" << endl;
}

void Manufacturer::edit( const size_t index, string manuf_,string year_,string speed_ ) {
    model[index - 1]->manuf=manuf_;
    model[index - 1]->year=atoi(year_.c_str());
    model[index - 1]->speed= atoi(speed_.c_str());
}

void edit(vector<Manufacturer> manufacturer, const size_t index) {
    string year, speed;
    if (index >= 1 && index <= manufacturer.size()) {
        size_t manufacturerIndex;
        cout << "Enter the manufacturer index you want to edit (1-" << manufacturer[index - 1].getsize() << "): ";
        cin >> manufacturerIndex;
        if (manufacturerIndex >= 1 && manufacturerIndex <= manufacturer[index - 1].getsize()) {
            cin.ignore();
            cout << "Enter the new manufacturer, new year and new speed over SPACE-BAR: ";
            string manuf;
            getline(cin, manuf, ' ');
            getline(cin, year, ' ');
            getline(cin, speed);
            manufacturer[index - 1].edit(manufacturerIndex, manuf, year, speed);

            cout << "Manufacturer edited successfully!" << endl;
        }
        else {
            cout << "Invalid manufacturer index!" << endl;
        }
    }
    else {
        cout << "Invalid car index!" << endl;
    }
}

void find(vector<Manufacturer> manufacturer) {
    char ch{};
    cout << "Enter a letter: ";
    cin >> ch;
    if (islower(ch)) {
        ch = toupper(ch);
    }
    cout << "========== Cars ==========" << endl;
    cout << "Manufacturer\t" << "Speed\t" << "Year" << endl;
    for (size_t i = 0; i < manufacturer.size(); i++) {
        for (size_t j = 0; j < manufacturer[i].getsize(); j++) {
            string manuf = manufacturer[i].getCarByIndex(j)->getManuf();
            if (manuf.find(ch) != string::npos) {
                cout << j + 1 << ". " << manuf << "\t" << manufacturer[i].getCarByIndex(j)->getSpeed()
                     << "\t" << manufacturer[i].getCarByIndex(j)->getYear() << endl;
            }
        }
    }
    cout << "======================" << endl;
}

