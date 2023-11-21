#include <iostream>
#include <fstream>
#include "AnimalDB.h"
using namespace std;

void readFile(const string filename, AnimalDB &animals)
{
    // open file, check if failed
    ifstream din;
    din.open(filename.c_str());

    if (din.fail())
    {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }

    // declare local temp. class variables for reading data
    int id = 1;
    string type;
    float weight;
    int age;
    float price;
    string extra;
    char dollar;

    while (!din.eof())
    {
        // logic for reading in data, ignoring unwanted data
        din >> type >> weight;
        getline(din, extra);
        din >> age;
        getline(din, extra);
        din.get(dollar);
        din >> price;
        getline(din, extra);

        // define new Animal object and insert new animal into Donna's inventory
        Animal newAnimal(id++, type, weight, age, price);
        if (!din.eof())
            animals.insertDonnaInventory(newAnimal);
    }
    din.close();
}

void writeFile(const string filename, AnimalDB animals)
{
    // open file for output, check if failed
    ofstream dout;
    dout.open(filename.c_str());

    if (dout.fail())
    {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }

    // loop for each index in the userCart array, write data of each Animal object to output file in CSV formats
    for (int i = 0; i < animals.getNumUserCart(); i++)
    {
        Animal currentAnimal = animals.getAnimalUserCart(i);
        dout << currentAnimal.getID() << ','
             << currentAnimal.getType() << ','
             << currentAnimal.getWeight() << ','
             << currentAnimal.getAge() << ','
             << currentAnimal.getPrice() << ',' << endl;
    }
    dout << ",,,," << animals.getCurrentTotal();
    dout.close();
}

void printMenu()
{
    cout << "\nWelcome to Donna's Farm! Here are your choices:"
         << "\n1: Print all animals in Donna's inventory"
         << "\n2: Print your current shopping cart"
         << "\n3: Print animals of a certain type"
         << "\n4: Print animals within a range of weight"
         << "\n5: Print animals within a range of age"
         << "\n6: Add an animal to your shopping cart"
         << "\n7: Print your current shopping cart total"
         << "\n8: Complete your order, print receipt and exit the program\n";
}

char getUserChoice()
{
    char userChoice = '0';

    do
    {
        cout << "\nEnter menu selection: ";
        cin >> userChoice;
        if (userChoice < '1' || userChoice > '8')
            cout << "\nError: invalid input. Please try again." << endl;
    } while (userChoice < '1' || userChoice > '8');

    return userChoice;
}

int main()
{
    // declare AnimalDB object
    AnimalDB animals;

    // read in data from file
    readFile("donnaInventory.txt", animals);

    // print menu and get user choice
    printMenu();
    char userChoice = getUserChoice();

    // loop until user decides to exit program
    while (userChoice != '8')
    {
        switch (userChoice)
        {
        case '1':
            animals.printDonnaInventory();
            break;
        case '2':
            animals.printUserCart();
            break;
        case '3':
        {
            string type;
            cout << "Enter type:" << endl;
            cin >> type;

            if (type == "rooster")
            {
                type = "Rooster";
            }
            else if (type == "rabbit")
            {
                type = "Rabbit";
            }
            else if (type == "horse")
            {
                type = "Horse";
            }
            else if (type == "goat")
            {
                type = "Goat";
            }
            else if (type == "duck")
            {
                type = "Duck";
            }
            else if (type == "sheep")
            {
                type = "Sheep";
            }
            else if (type == "mule")
            {
                type = "Mule";
            }
            else if (type == "cow")
            {
                type = "Cow";
            }
            else if (type == "donkey")
            {
                type = "Donkey";
            }
            else if (type == "turkey")
            {
                type = "Turkey";
            }
            else if (type == "pig")
            {
                type = "Pig";
            }
            else if (type == "chicken")
            {
                type = "Chicken";
            }

            bool found = animals.printType(type);
            if (!found)
            {
                cout << endl;
                cout << "No animals of type: " << type << " were found in Donna's inventory." << endl;
            }
            break;
        }
        case '4':
            float min;
            float max;

            do
            {
                cout << "Enter a minimum weight that is at least zero:" << endl;
                cin >> min;
            } while (min < 0);

            do
            {
                cout << "Enter a maximum weight which is greater than your minimum:" << endl;
                cin >> max;
            } while (max <= min);

            bool found;
            found = animals.printWeightRange(min, max);
            if (!found)
            {
                cout << endl;
                cout << "No animals were found in Donna's inventory within the range of " << min << " kg and " << max << " kg." << endl;
            }
            break;
        case '5':
        {
            int min;
            int max;
            do
            {
                cout << "Enter a minimum age that is at least zero:" << endl;
                cin >> min;
            } while (min < 0);
            do
            {
                cout << "Enter a maximum age which is greater than your minimum:" << endl;
                cin >> max;
            } while (max <= min);
            bool found;
            found = animals.printAgeRange(min, max);
            if (!found)
            {
                cout << "No animals were found in Donna's inventory within the range of " << min << " years old and " << max << " years old. " << endl;
            }
            break;
        }
        case '6':
        {
            int id;
            cout << "Enter an Animal's ID to add to your cart:" << endl;
            cin >> id;
            bool found;
            found = animals.insertUserCart(id-1);
            if (!found)
            {
                cout << "No animals with the ID:" << id << " were found in Donna's inventory." << endl;
            }
            break;
        }
        case '7':
        
            float total;
            total = animals.getCurrentTotal();
            cout << "The total cost of the animals in your cart is $" << total << endl;
            break;

        case '8':
            break;

        default:
            cout << "\nError: invalid input. Please try again." << endl;
            break;
        }
        printMenu();
        userChoice = getUserChoice();
    }

    // write user's shopping cart to output file
    writeFile("receipt.csv", animals);

    return 0;
}