#include "Animal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ANIMALS = 100;

class AnimalDB {
  private:
    Animal donnaInventory[MAX_ANIMALS]; // array for storing Donna's inventory
    Animal userCart[MAX_ANIMALS]; // array for storing user's shopping cart
    int numDonnaInventory; // tracks number of animals in inventory
    int numUserCart; // tracks number of animals in shopping cart

  public:
    // default constructor
    AnimalDB();
    // copy constructor
    AnimalDB(const AnimalDB& copy);

    // destructor
    ~AnimalDB();

    // getter methods for array sizes
    int getNumDonnaInventory() const;
    int getNumUserCart() const;

    // method for returning animal at given index in user's shopping cart
    Animal getAnimalUserCart(int index) const;

    // method for returning animal with given ID in Donna's inventory
    Animal getAnimalDonnaInventory(int id) const;

    // method for returning current running total of user's shopping cart
    float getCurrentTotal() const;

	// insert method for adding new animal to Donna's inventory
    bool  insertDonnaInventory(const Animal& animal);

    // insert method for adding new animal to user's shopping cart
    bool insertUserCart(int id);

	// print method for Donna's Inventory
	void printDonnaInventory() const;

	// print method for user's shopping cart
	void printUserCart() const;

	// print method for animals by type
	bool printType(string type) const;

	// print method for animals by weight range
	bool printWeightRange(float min, float max) const;

	// print method for animals by age range
	bool printAgeRange(int min, int max) const;

};