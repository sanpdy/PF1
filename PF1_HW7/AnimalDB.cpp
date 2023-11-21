#include "AnimalDB.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

AnimalDB::AnimalDB()
{
  numDonnaInventory = 0;
  numUserCart = 0;
}

// copy constructor
AnimalDB::AnimalDB(const AnimalDB &copy)
{
  numDonnaInventory = copy.numDonnaInventory;
  numUserCart = copy.numUserCart;

  for (int i = 0; i < numDonnaInventory; i++)
  {
    donnaInventory[i] = copy.donnaInventory[i];
  }

  for (int i = 0; i < numUserCart; i++)
  {
    userCart[i] = copy.userCart[i];
  }
}

// destructor
AnimalDB::~AnimalDB()
{
}

// getter methods for array sizes
int AnimalDB::getNumDonnaInventory() const 
{ 
  return numDonnaInventory; 
}

int AnimalDB::getNumUserCart() const 
{ 
  return numUserCart; 
}

// method that returns an animal at a given index in user's shopping cart
Animal AnimalDB::getAnimalUserCart(int index) const
{
  if (index < 0 || index >= numUserCart)
  {
    // print error message and return  Animal
    cout << "Error: invalid index for shopping cart" << endl;
    return Animal();
  }
  return userCart[index];
}

// method for returning animal with given ID in Donna's inventory
Animal AnimalDB::getAnimalDonnaInventory(int id) const
{
  
  for (int i = 0; i < numDonnaInventory; i++)
  {
    if (donnaInventory[i].getID() == id)
    {
      return donnaInventory[i];
    }
  }
  // print error message and return dummy Animal if ID is not found
  cout << "Error: ID not found in inventory" << endl;
  return Animal();
}

// method for returning current running total of user's shopping cart
float AnimalDB::getCurrentTotal() const
{
  float total = 0;
  for (int i = 0; i < numUserCart; i++)
  {
    total += userCart[i].getPrice();
  }
  return total;
}

// insert method for adding new animal to Donna's inventory
bool AnimalDB::insertDonnaInventory(const Animal &animal)
{
  if (numDonnaInventory >= 100)
  {
    // print error message and return false if inventory is full
    cout << "Error: inventory is full" << endl;
    return false;
  }
  donnaInventory[numDonnaInventory++] = animal;
  return true;
}

// insert method for adding new animal to user's shopping cart
bool AnimalDB::insertUserCart(int id)
{
  if (id < 0 || id >= numDonnaInventory)
  {
    cout << "Invalid animal ID" << endl;
    return false;
  }

  Animal animal = donnaInventory[id];

  if (numUserCart == MAX_ANIMALS)
  {
    cout << "User's cart is full" << endl;
    return false;
  }

  userCart[numUserCart++] = animal;
  return true;
}

// print method for Donna's Inventory
void AnimalDB::printDonnaInventory() const
{
  cout << "Donna's Inventory" << endl;
  cout << "~~~~~~~~~~~~~~~~~" << endl;
  for (int i = 0; i < numDonnaInventory; i++)
  {
    donnaInventory[i].print();
  }
}

// print method for user's shopping cart
void AnimalDB::printUserCart() const
{
  cout << "User's Cart" << endl;
  cout << "~~~~~~~~~~~" << endl;
  for (int i = 0; i < numUserCart; i++)
  {
    userCart[i].print();
  }
}

// print method for animals by type
bool AnimalDB::printType(string type) const
{
  bool found = false;
  for (int i = 0; i < numDonnaInventory; i++)
  {
    if (donnaInventory[i].getType() == type)
    {
      donnaInventory[i].print();
      found = true;
    }
  }
  return found;
}

// print method for animals by weight range
bool AnimalDB::printWeightRange(float min, float max) const
{
  bool found = false;
  for (int i = 0; i < numDonnaInventory; i++)
  {
    float weight = donnaInventory[i].getWeight();
    if (weight >= min && weight <= max)
    {
      donnaInventory[i].print();
      found = true;
    }
  }
  return found;
}

// print method for animals by age range
bool AnimalDB::printAgeRange(int min, int max) const
{
  bool found = false;
  for (int i = 0; i < numDonnaInventory; i++)
  {
    int age = donnaInventory[i].getAge();
    if (age >= min && age <= max)
    {
      donnaInventory[i].print();
      found = true;
    }
  }
  return found;
}