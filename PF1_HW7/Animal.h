#ifndef ANIMAL_H
#define ANIMAL_H
#include <fstream>
using namespace std;

class Animal
{
    private:
        int id;
        string type;
        float weight;
        int age;
        float price;

    public:
        // Default constructor
        Animal();

        // Setter constructor
        Animal(int id, string type, float weight, int age, float price);

        // Copy constructor
        Animal(const Animal& animals);

        // Destructor
        ~Animal();

        // Getter methods
        int getID() const;
        string getType() const;
        float getWeight() const;
        int getAge() const;
        float getPrice() const;

        // Setter methods
        void setID(int id);
        void setType(string type);
        void setWeight(float weight);
        void setAge(int age);
        void setPrice(float price);

        // Print method
        void print() const;
};

#endif