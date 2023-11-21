#include "Animal.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

Animal::Animal()
{
    id = 0;
    type = "";
    weight = 0;
    age = 0;
    price = 0;
}

// Setter constructor
Animal::Animal(int id, string type, float weight, int age, float price)
{
    this->id = id;
    this->type = type;
    this->weight = weight;
    this->age = age;
    this->price = price;
}

// Copy constructor
Animal::Animal(const Animal &copy)
{
    id = copy.id;
    type = copy.type;
    weight = copy.weight;
    age = copy.age;
    price = copy.price;
}

// Destructor
Animal::~Animal() {}

// Getter methods
int Animal::getID() const
{
    return id;
}

string Animal::getType() const
{
    return type;
}

float Animal::getWeight() const
{
    return weight;
}

int Animal::getAge() const
{
    return age;
}
float Animal::getPrice() const
{
    return price;
}

// Setter methods
void Animal::setID(int id)
{
    this->id = id;
}

void Animal::setType(string type)
{
    this->type = type;
}

void Animal::setWeight(float weight)
{
    this->weight = weight;
}

void Animal::setAge(int age)
{
    this->age = age;
}

void Animal::setPrice(float price)
{
    this->price = price;
}

// Print method
void Animal::print() const
{
    cout << "ID: " << id << endl;
    cout << "Type: " << type << endl;
    cout << "Weight: " << weight << " kg " << endl;
    cout << "Age: " << age << " years old " << endl;
    cout << "Price: $" << price << endl;
    cout << endl << endl;
}