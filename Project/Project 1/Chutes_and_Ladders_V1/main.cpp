/* 
 * File:   main.cpp
 * Author: Nellie Garcia
 * Created on April 2nd, 2019, 11:21 AM
 * Purpose:  Chutes and Ladders Version 1
 *           Only does one player
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //C Standard Library - Random Number
#include <ctime>     //Time Library
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
#include <fstream>   //File Library
#include <string>    //String Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned int    die,    //Die input
                    place;  //Place for player
    bool            win;    //Win/Lose
    
    //Initialize or input i.e. set variable values
    cout<<"Chutes and Ladders Game"<<endl;
    place=0;
    win=false;
    
    //Map inputs -> outputs
    do {
        die=rand()%6+1;     //Dice roll
        place+=die;         //Place before chutes or ladders
        
        //Place cannot go over 100
        while (place>100) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You cannot land over 100. Roll again!"<<endl;
            place-=die;     //Backtrack place
            die=rand()%6+1; //Re-roll die
            place+=die;     //Move to new place
        }
        
        //Testing chutes and ladders
        if (place==1) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved up a ladder!"<<endl;
            place=38;
        }
        else if (place==4) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved up a ladder!"<<endl;
            place=14;
        }
        else if (place==9) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved up a ladder!"<<endl;
            place=31;
        }
        else if (place==16) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=6;
        }
        else if (place==21) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved up a ladder!"<<endl;
            place=42;
        }
        else if (place==28) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved up a ladder!"<<endl;
            place=84;
        }
        else if (place==36) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved up a ladder!"<<endl;
            place=44;
        }
        else if (place==47) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=26;
        }
        else if (place==49) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=11;
        }
        else if (place==51) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved up a ladder!"<<endl;
            place=67;
        }
        else if (place==56) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=53;
        }
        else if (place==62) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=19;
        }
        else if (place==64) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=60;
        }
        else if (place==71) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved up a ladder!"<<endl;
            place=91;
        }
        else if (place==80) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved up a ladder!"<<endl;
            place=100;
        }
        else if (place==87) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=24;
        }
        else if (place==93) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=73;
        }
        else if (place==95) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=75;
        }
        else if (place==98) {
            cout<<"Number on board: "<<place<<endl;
            cout<<"You moved down a chute!"<<endl;
            place=78;
        }
        
        //Output place
        cout<<"Number on board: "<<place<<endl;
        
        //Win Determination
        if (place==100) {
            win=true;
        }
    }while (win==false);
    
    //Display the outputs
    if (win==true) {
        cout<<"You win!"<<endl;
    }

    //Exit stage right or left!
    return 0;
}