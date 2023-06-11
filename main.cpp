#include "car.h"

using namespace std;

int main() {
    int choice;
    size_t index;
    vector<Person>person;
    vector<Manufacturer>manufacturer;

    do {
        menu();
        cout << "Make your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                create(person);
                break;
            case 2:
                show(person);
                break;
            case 3:
                add(person);
                break;
            case 4:
                cout << "Which one do you want to delete?: ";
                cin >> index;
                delete_(person, index);
                break;
            case 5:
                cout << "Which one do you want to edit?: ";
                cin >> index;
                edit(person, index);
                break;
            case 6:
                find(person);
                break;
            case 7:
                create(manufacturer);
                break;
            case 8:
                show(manufacturer);
                break;
            case 9:
                add(manufacturer);
                break;
            case 10:
                delete_(manufacturer);
                break;
            case 11:
                cout << "Which one do you want to change?: ";
                cin >> index;
                edit(manufacturer,index);
                break;
            case 12:
                find(manufacturer);
                break;
            case 13:{
                ifstream file("test1.txt");
                if (file.is_open()){
                    file >> manufacturer;
                }
                file.close();
               break;}
            case 14:
                cout << "Thank you for visit, see you next time" << endl;
                break;
            default:
                cout << "Wrong choice, please try again" << endl;
                continue;
        }

    } while (choice != 14);

    return 0;
}