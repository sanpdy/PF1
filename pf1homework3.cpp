#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    // Initializing all of the important variables like width, initial position, Opus's position, and Ursula's position.
    int holeWidth;
    int initialPosition;
    int opusPosition;
    int ursulaPosition;
    
    // Intializes variables for Opus and Ursula's movement. 
    int opusMovement = 0;
    int ursulaMovement = 0;
    
    // Starts the srand seed. 
    srand(time(0));
   
    // Gets user input for the hole's width. 
    cout << "Enter hole width (must be greater than 1): " << endl;
    
    do{
        
        cin >> holeWidth;
        
    }while (holeWidth < 2);
   
   // Calculates initial position for Ursula and Opus. 
    if(holeWidth % 2 == 0){
        initialPosition = (holeWidth/2);
    }
    else{
        initialPosition = (holeWidth/2) + 1;
    }

   
    opusPosition = initialPosition;
    ursulaPosition = initialPosition;
   
    
    // Engine runs and finds Opus and Ursula's position until one of them hits a wall. 
    while((opusPosition > 1) && (opusPosition < holeWidth) && (ursulaPosition > 1) && (ursulaPosition < holeWidth)){
        
        // Calculates the new position for Opus and Ursula. 
        opusPosition = opusPosition + opusMovement;
        ursulaPosition = ursulaPosition + ursulaMovement;
       
       // If Opus and Ursula are in the same position.
        if(opusPosition == ursulaPosition) 
        {
            cout << "|";
   
        for(int i = 1; i < opusPosition; i++){
             cout << " ";
        }
        cout << "X";
       
        for(int i = opusPosition; i < holeWidth; i++){
             cout << " ";
        }
        cout << "|" << endl;
        }
       
       // If Opus is to the left of Ursula.
        else if(opusPosition < ursulaPosition)
        {
        cout << "|";
   
        for(int i = 1; i < opusPosition; i++)
             cout << " ";
       
        cout << "O";
       
        for(int i = opusPosition; i < ursulaPosition - 1; i++)
             cout << " ";
       
        cout << "U";
       
        for(int j = ursulaPosition; j < holeWidth; j++)
             cout << " ";
             
        cout << "|" << endl;
        }
       
       // If Opus is to the right of Ursula.
        else if(opusPosition > ursulaPosition)
        {
          cout << "|";
   
        for(int i = 1; i < ursulaPosition; i++)
             cout << " ";
       
        cout << "U";
       
        for(int i = ursulaPosition; i < opusPosition - 1; i++)
             cout << " ";
       
        cout << "O";
       
        for(int j = opusPosition; j < holeWidth; j++)
             cout << " ";
             
        cout << "|" << endl;  
        }
        // Calculates a value which decides for Opus and Ursula's movement.
        opusMovement = (((rand() % 2 + 1) * 2) - 3);
        ursulaMovement = (((rand() % 2 + 1) * 2) - 3);
           
    }
   

    return 0;
}

