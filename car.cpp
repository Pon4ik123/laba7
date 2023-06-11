#include "car.h"

istream &operator>>(istream &in, vector<Manufacturer>& manufacturer) {
    manufacturer.clear();
    string manufAmount, carAmount;
    getline(in, manufAmount, '\t');
    getline(in, carAmount, '\t');
    for (int i = 0; i < atoi(manufAmount.c_str()); ++i) {
        manufacturer.push_back(Manufacturer::copyFromFile(in, atoi(carAmount.c_str())));
    }
    return in;
}

ostream &operator<<(ostream &out, vector<Manufacturer>manufacturer) {
    for (size_t i = 0; i < manufacturer.size(); ++i) {
        for(size_t j = 0; j < manufacturer[i].model.size(); ++j)
            manufacturer[i].model[j]->moveToFile(out);
    }

    return out;
}

Manufacturer::Model * Manufacturer::random() {
    random_device rd;
    default_random_engine dfe(rd());
    string manufacturers[] = {"Mazda", "Toyota", "Honda", "Chevrolet", "Volkswagen"};
    uniform_int_distribution<int> speedDist(220, 300);
    uniform_int_distribution<int> yearDist(1999, 2020);
    uniform_int_distribution<int> keyDist(1000, 9999);
    uniform_int_distribution<int> batteryDist(0, 100);
    uniform_int_distribution<int> GazDist(0, 100);
    string manuf = manufacturers[dfe() % (sizeof(manufacturers) / sizeof(string))];
    int speed = speedDist(dfe);
    int year = yearDist(dfe);
    int key = keyDist(dfe);

    if (rand()%2){
        int ptrBattery = batteryDist(dfe);
        Model *model = new ElectricCar(manuf, speed, year, key, ptrBattery);
        return model;
    }
    else {
        int ptrGaz= GazDist (dfe);
        Model* model = new GazCar(manuf, speed, year, key, ptrGaz);
        return model;
    }
}