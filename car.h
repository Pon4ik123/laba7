#include "person.h"
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>


using namespace std;

size_t random(size_t number1, size_t number2);

class Manufacturer {
    class Model {
        friend class Manufacturer;
        bool etap = false;
        string manuf;
        int speed;
        int year;
        int key2;
    public:
        Model() : manuf("Default"), speed(0), year(0), key2(0) {}
        Model(string manuf, int speed, int year, int key) : manuf(manuf), speed(speed), year(year), key2(key) {}
        Model(Model& other) : manuf(other.manuf), speed(other.speed), year(other.year), key2(other.key2){}
        ~Model() {}

        string getManuf() const { return manuf; }
        int getSpeed() const { return speed; }
        int getYear() const { return year; }
        int getKey() const { return key2; }
        bool getEtap() const { return etap; }


        void setManuf(string s){
            this->manuf = s;
        }
        void setYear(size_t y){
            this->year = y;
        }
        void setSpeed(size_t s){
            this->speed = s;
        }
        void setKey(size_t s){
            this->key2 = s;
        }
        bool setEtap(bool et) { this->etap = et; }

        virtual void print() const{
            cout << left << setw(17) << manuf << left << setw(7) << speed << left << setw(7) << year << left << setw(7);
        }

        virtual void moveToFile(ostream& out){
            out << manuf << "\t" << speed << "\t" << year << "\t" << key2 << "\t";
        }
    };
    //Model** model{nullptr};
    vector <Model*>model;

    class ElectricCar : public Model{
        int battery;
    public:
        ElectricCar() : battery(0), Model(){}
        ElectricCar(const string manuf, int speed, int year, int key, int cm) : Model(manuf, speed, year, key), battery(cm) {}
        ElectricCar(ElectricCar& other) : battery(other.battery), Model(other){}
        ~ElectricCar() {}

        int getBattery() const { return battery; }
        void setBattery(int s) { battery = s; }

        void print() const override{
            Model::print();
            cout << right << setw(7) << battery << "%" << endl;
        }

        void moveToFile(ostream& out) override{
            out << 1 << "\t";
            Model::moveToFile(out);
            out << battery << endl;
        }
    };
    class GazCar : public Model{
        int gaz;
    public:
        GazCar() : gaz(0), Model(){}
        GazCar(const string manuf, int speed, int year, int key, int g) : Model(manuf, speed, year, key), gaz(g) {}
        GazCar(GazCar& other) : gaz(other.gaz), Model(other) {}
        ~GazCar() {}

        int getGaz() const { return gaz; }
        void setGaz(int s) { gaz = s; }

        void print() const override{
            Model::print();
            cout << right << setw(6) << gaz << " m3" << endl;
        }
        void moveToFile(ostream& out) override{
            out << 0 << "\t";
            Model::moveToFile(out);
            out << gaz << endl;
        }
    };
public:
  int getsize(){
      model.size();
  }
    Model* getCarByIndex(int i) const { return model[i]; }

   void setcar(Model *other){
      model.push_back(other);
    };

   // Manufacturer& operator= (const Manufacturer& other);
    friend istream& operator>>(istream& in, vector<Manufacturer>& manufacturer);
    friend ostream& operator<<(ostream&out, vector<Manufacturer>manufacturer);

    Model * operator[](const size_t index){
        return model[index];
    }

    size_t getNumberOfCars() const;
    void setNumberOfCars(int num);
    static Model * random();

    void print(){
        for(size_t i = 0; i < model.size(); i++){
            model[i]->print();
        }
    }
    void edit( const size_t index, string manuf,string year,string speed );

    int getVectorSize(){
        return model.size();
    }

    static Manufacturer copyFromFile(istream& in, int carCount){
        Manufacturer temp;
        string manuf, speed, year, key, batery, gaz;
        string flag;
        for (int j = 0; j < carCount; j++) {
            getline(in, flag, '\t');

            if (atoi(flag.c_str()) == 1) {
                getline(in, manuf, '\t');
                getline(in, speed, '\t');
                getline(in, year, '\t');
                getline(in, key, '\t');
                getline(in, batery);
                temp.model.push_back(new ElectricCar(manuf, atoi(speed.c_str()), atoi(year.c_str()), atoi(key.c_str()), atoi(batery.c_str())));
            }
            else{
                getline(in, manuf, '\t');
                getline(in, speed, '\t');
                getline(in, year, '\t');
                getline(in, key, '\t');
                getline(in, gaz);
                temp.model.push_back(new GazCar(manuf, atoi(speed.c_str()), atoi(year.c_str()), atoi(key.c_str()), atoi(gaz.c_str())));
            }
        }
        return temp;
    }
};

void create(vector<Manufacturer>& manufacturer);
void show(vector<Manufacturer> manufacturer);
void add(vector<Manufacturer>& manufacturer);
void delete_(vector<Manufacturer>& manufacturer);
void edit(vector<Manufacturer> manufacturer, const size_t index);
void find(vector<Manufacturer> manufacturer);