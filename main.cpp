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
		this->name = "Unknown";
		this->age = 0;
		this->weight = 0.0;
	}

	Animal(const string& name, int age, double weight) {
		this->name = name;
		this->age = age;
		this->weight = weight;
	}

	virtual ~Animal() {}
};

class Mammal : public Animal {
private:
	bool hasFur;
	int lifespan;

public:

	Mammal() : Animal() {
		this->hasFur = true;
		this->lifespan = 0;
	}

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
	Cat() : Mammal() {
		this->isIndoor = false;
		this->clawLength = 1.0;
	}

	Cat(const string& name, int age, double weight, bool hasFur = true, int lifespan = 15, bool isIndoor = true, double clawLength = 2.0)
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

	void drinkMilk() {
		cout << name << " is drinking milk." << endl;
	}
};

class PersianCat : public Cat {
private:
	double furLength;

public:
	PersianCat() : Cat() {
		this->furLength = 15.0;
	}

	PersianCat(const string& name, int age, double weight, bool hasFur = true, int lifespan = 15,
		bool isIndoor = true, double clawLength = 2.0, double furLength = 10.0)
		: Cat(name, age, weight, hasFur, lifespan, isIndoor, clawLength)
	{
		if (!hasFur) {
			this->furLength = 0.0;
		} else {
			this->furLength = furLength;
		}
	};

	void makeSound() override {
		cout << "Soft meow..." << endl;
	}

	void groom() {
		cout << name << " is grooming its long fur." << endl;
	}

	void sleep() {
		cout << name << " is sleeping peacefully." << endl;
	}

	void printInfo() override {
		Cat::printInfo();
		cout << "Fur length: " << furLength << " cm" << endl;
	}
};

class Dog : public Mammal {
private:
	string breed;
	bool isGuardDog;

public:
	Dog() : Mammal()
	{
		this->breed = "none";
		this->isGuardDog = false;
	}

	Dog(const string& name, int age, double weight, bool hasFur = true, int lifespan = 12, string breed = "Mixed", bool isGuardDog = false)
		: Mammal(name, age, weight, hasFur, lifespan)
	{
		this->breed = breed;
		this->isGuardDog = isGuardDog;
	}

	void makeSound() override {
		cout << "Bark!" << endl;
	}

	void move() override {
		cout << name << " is running." << endl;
	}

	void guard() {
		cout << name << " is guarding the house." << endl;
	}

	void catchItem() {
		cout << name << "is catching an item." << endl;
	}

	void printInfo() override {
		Animal::printInfo();
		cout << "Breed: " << breed << endl;
		cout << "Guard dog: " << (isGuardDog ? "Yes" : "No") << endl;
	}
};

class Bird : public Animal {
private:
	double wingSpan;
	bool canFly;

public:
	Bird() : Animal() {
		this->wingSpan = 0.0;
		this->canFly = true;
	}

	Bird(const string& name, int age, double weight, double wingSpan = 1.0, bool canFly = true)
		: Animal(name, age, weight) {
		this->wingSpan = wingSpan;
		this->canFly = canFly;
	}

	void layEggs() {
		cout << name << " is laying eggs." << endl;
	}

	void buildNest() {
		cout << name << " is building a nest." << endl;
	}

	void printInfo() override {
		Animal::printInfo();
		cout << "Wing span: " << wingSpan << " meters" << endl;
		cout << "Can fly: " << (canFly ? "Yes" : "No") << endl;
	}
};

class Eagle : public Bird {
private:
	double flightSpeed, visionRange;

public:
	Eagle() : Bird() {
		this->flightSpeed = 0.0;
		this->visionRange = 0.0;
	}

	Eagle(const string& name, int age, double weight, double wingSpan = 2.0, bool canFly = true, double flightSpeed = 120.0, double visionRange = 3.0)
		: Bird(name, age, weight, wingSpan, canFly) {

		this->flightSpeed = flightSpeed;
		this->visionRange = visionRange;
	}

	void makeSound() override {
		cout << "Screech!" << endl;
	}

	void move() override {
		cout << name << " is flying high in the sky." << endl;
	}

	void hunt() {
		cout << name << " is hunting." << endl;
	}

	void soar() {
		cout << name << " is soaring gracefully." << endl;
	}

	void printInfo() override {
		Bird::printInfo();
		cout << "Flight speed: " << flightSpeed << " km/h" << endl;
		cout << "Vision range: " << visionRange << " km" << endl;
	}
};

int main() {

	Animal* animals[] = {
		new Cat("Denis", 5, 4.5),
		new Eagle("Storm", 3, 6.0),
		new Dog("Rex", 4, 20.0, true, 12, "German Shepherd", true),
		new PersianCat("Fluffy", 2, 3.5, true, 17, false, 6.0, 13.0)
	};

	for (int i = 0; i < 4; i++) {

		cout << "\n--- Animal " << i << " ---\n";

		animals[i]->printInfo();
		animals[i]->makeSound();
		animals[i]->move();

		if (Dog* d = dynamic_cast<Dog*>(animals[i])) {
			d->guard();
		}
		else if (Eagle* e = dynamic_cast<Eagle*>(animals[i])) {
			e->hunt();
		}
		else if (PersianCat* p = dynamic_cast<PersianCat*>(animals[i])) {
			p->groom();
		}
		else if (Cat* c = dynamic_cast<Cat*>(animals[i])) {
			c->scratch();
		}

		delete animals[i];
	}

	return 0;
}
