// MarcoLoPiccolo_PolymorphismLabExtraCredit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //Preproccessor
using namespace std; //allows us to use functions without std:: in front

class Dice
{
public:
    Dice();              //Two constructors with either being able to be invoked if the user wants to have a set number of sides
    Dice(int numSides);   //or the user being able to set their own number of sides
    virtual int rollDice()const;  //virtual function here so that the same named function can be used later in the derived class
protected:
    int numSides;  //protected value that can only be accessed through member functions
};

class LoadedDice : public Dice {     //Creates a derived class that allows access to Dice Class
public:
    LoadedDice();        //Constructors that have the same function as the parent Dice Class
    LoadedDice(int numSides);
    int rollDice()const;   //Uses the same named member function above using polymorphism
};

int rollTwoDice(const Dice& die1, const Dice& die2);  //Function header

int main()
{
    LoadedDice random1(6);   //creates two random dice with 6 sides using the loaded derived class
    LoadedDice random2(6);

    for (int i = 0; i < 10; i++) {  //for loop is used to show the sum of the two rolled 
        int sumOfDice;              //dice which is saved in sum of dice
        sumOfDice = rollTwoDice(random1, random2);    //calls roll two dice function which will use the loaded dice in place of the dice class using polymorphism
        cout << sumOfDice << endl;  //outputs the dice to the screen
    }
    
    system("Pause");
    return 0;
}

Dice::Dice()   //member function that is the constructor if no sides are entered and gives back 6 sides by default then
{
    numSides = 6;
    srand(time(NULL)); // Seeds random number generator
}

Dice::Dice(int numSides)  //Constructor that has input from the user with number of sides 
{
    this->numSides = numSides;  //uses pointer to save numsides into the protected value of num sides
    srand(time(NULL)); // Seeds random number generator
}

int Dice::rollDice()const  //function that randomizes what side the dice will land on
{
    return (rand() % numSides) + 1;
}

LoadedDice::LoadedDice() {  //constructors function the same as class functions of class Dice
    numSides = 6;
    srand(time(NULL)); // Seeds random number generator
}

LoadedDice::LoadedDice(int numSides) {
    this->numSides = numSides;   //uses pointer to save numsides into the protected value of num sides
    srand(time(NULL)); // Seeds random number generator
}

int LoadedDice::rollDice()const {  //Function first randomizes the value by using rand() % 2 to give 0 and 1
    int flipCoin = rand() % 2;  //This allows for 50 percent of the time for the value to be 0 which if it is then 
    if (flipCoin == 0) {   //the roll dice function returns the highest number on the dice which is the number of sides
        return numSides;
    }
    else {  //otherwise it uses the same process as the class Dice function of the same name
        return ((rand() % numSides) + 1);
    }
}

// Take two dice objects, roll them, and return the sum
//Function will use LoadedDice through polymorphism in main function
int rollTwoDice(const Dice& die1, const Dice& die2)
{
    return die1.rollDice() + die2.rollDice();
}