#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    int age;
    double weight;

public:
    virtual void makeSound() = 0;

    virtual void move() = 0;

    virtual void printInfo() {
        cout << "The animal is named " << name << ". It is " << age << " years old and weights " << weight << "kg." << endl;
    }

    Animal() {
    }

    Animal(const string& name, int age, double weight) {
        this->name = name;
        this->age = age;
        this->weight = weight;
    }
};

class Mammal : public Animal {
private:
    bool hasFur;
    int lifespan;

public:
    Mammal(const string& name, int age, double weight, bool hasFur, int lifespan)
        : Animal(name, age, weight) {
        this->hasFur = hasFur;
        this->lifespan = lifespan;
    }

    void feedMilk() {
        cout << name << " is feeding milk." << endl;
    }

    void regulateTemperature() {
        cout << name << " is warm-blooded." << endl;
    }
};

class Cat : public Mammal {
private:
    bool isIndoor;
    double clawLength;

public:
    Cat(const string& name, int age, double weight, bool hasFur, int lifespan, bool isIndoor, double clawLength)
        : Mammal(name, age, weight, hasFur, lifespan) {
        this->isIndoor = isIndoor;
        this->clawLength = clawLength;
    }

    void makeSound() override {
        cout << "Meow!" << endl;
    }

    void move() override {
        cout << "Cat is walking silently." << endl;
    }

    void printInfo() override {
        Animal::printInfo();
        cout << "The cat also has claws of " << clawLength << " cm." << endl;
        if (isIndoor) cout << name << " is now indoor and is walking around the house" << endl;
        else cout << name << " is now walking outside the house" << endl;
    }

    void scratch() {
        cout << name << " is scratching." << endl;
    }
};

int main() {

    Cat cat("Alexa", 10, 25, true, 30, true, 20);
    cat.printInfo();
    cat.makeSound();
    cat.move();
    cat.scratch();
    cat.feedMilk();
    cat.regulateTemperature();
    return 0;
}
