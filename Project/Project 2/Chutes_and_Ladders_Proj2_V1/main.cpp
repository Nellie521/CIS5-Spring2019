/* 
 * File:   main.cpp
 * Author: Nellie Garcia
 * Created on April 26th, 2019, 5:27 PM
 * Purpose:  Chutes and Ladders Project 2 Version 1
 *           Functions - Majority of the work
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
int intro (int,int);
void chutlad (int,string,int,int);  //Overloading
void chutlad (int,int,int,int,int,int,int,int,int,string,string);
bool winDet (int &);  //Going to use boolean to determine chutlad wins
void output (int,int,int,int,string,string);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned char   die;    //Die input
    unsigned int    nPlayer,//Number of players
                    place1, //Place for player 1
                    place2, //Place for player 2
                    cwin1,  //Counting first player's wins
                    cwin2;  //Counting second player's wins
    int             x=0;      //Used for defaulted argument
    float           nGames; //Number of games
    bool            win1,   //Win/Lose for player 1
                    win2;   //Win/Lose for player 2
    bool            end1,   //End first player's turn
                    end2;   //End second player's turn
    string          name1,  //Name of first player
                    name2;  //Name of second player
    ifstream        in;     //Input file
    ofstream        out;    //Output file
    
    //Initialize or input i.e. set variable values
    int nPlayers=intro(nPlayer,x);
    cout<<"Enter the number of games you want to play: ";
    cin>>nGames;            //Set number of games
    nGames=rint(nGames);    //Round to integer
    place1=place2=0;
    win1=win2=false;
    end1=end2=false;
    cwin1=cwin2=0;
    string inName="GameInfo.dat";
    char outName[]="GameStats.dat";
    in.open(inName.c_str());    //Open input file
    out.open(outName);          //Open output file
    
    //Map inputs -> outputs
    switch (nPlayers) {
        //One player
        case 1: {
            if (nPlayers==1) {
                //Entering names
                cout<<"Enter the First Player's name: ";
                cin>>name1;
                cout<<endl;
                
                //Chutes and Ladders Game
                chutlad (place1,name1,nGames,cwin1);
            }
        }

        //Two players
        case 2: {
            if (nPlayers==2) {
                
                //Entering names
                cout<<"Enter the First Player's name: ";
                cin>>name1;
                cout<<"Enter the Second Player's name: ";
                cin>>name2;
                cout<<endl;
                
                //Chutes and Ladders Game
                chutlad(place1,place2,nGames,cwin1,cwin2,win1,win2,
                        end1,end2,name1,name2);
            }
        }
    }
    
    //Output results to file
    if (nPlayers==1) {
        out<<endl;
        out<<"Number of players = "<<setw(3)<<nPlayers<<endl;
        out<<"Number of games   = "<<setw(3)<<nGames<<endl;
    }
    else {
        out<<endl;
        out<<"Number of players = "<<setw(3)<<nPlayers<<endl;
        out<<"Number of games   = "<<setw(3)<<nGames<<endl;
    }
    
    //Output results
    output (nPlayers,nGames,cwin1,cwin2,name1,name2);
    
    
    //Exit stage right or left!
    in.close();
    out.close();
    return 0;
}

int intro (int nPlayer,int x=0) {
    static int y=0;     //Static variable inside function
    cout<<"Chutes and Ladders Game"<<endl;
    cout<<"The goal is to reach number 100"<<endl;
    cout<<"You can have up to two players"<<endl;
    cout<<"Enter the number of players: ";
    cin>>nPlayer;       //Set number of players
    while (nPlayer>2) { //Validating user input
        cin.clear();
        cout<<"You cannot have more than two players"<<endl;
        cout<<"Enter the number of players: ";
        cin>>nPlayer;
    }
    if (nPlayer==1) return (x+y+1);   //Used for defaulted argument
    else if (nPlayer==2) return 2;
}

void chutlad (int place1,string name1,int nGames, int cwin1) {
    int die;
    //For loop for number of games
    for(int i=1;i<=nGames;i++) {

        //Reset place and wins
        place1=0;

        //Begin game
        do {
            if (place1<100) {
                die=rand()%6+1;     //Dice roll
                place1+=die;        //Place before chutes or ladders
            }

            //Place cannot go over 100
            while (place1>100) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<"You cannot land over 100. Go back!"<<endl;
                place1-=die;    //Backtrack place1
            }

            //Testing chutes and ladders
            if (place1==1) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved up a ladder!"<<endl;
                place1=38;
            }
            else if (place1==4) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved up a ladder!"<<endl;
                place1=14;
            }
            else if (place1==9) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved up a ladder!"<<endl;
                place1=31;
            }
            else if (place1==16) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=6;
            }
            else if (place1==21) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved up a ladder!"<<endl;
                place1=42;
            }
            else if (place1==28) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved up a ladder!"<<endl;
                place1=84;
            }
            else if (place1==36) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved up a ladder!"<<endl;
                place1=44;
            }
            else if (place1==47) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=26;
            }
            else if (place1==49) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=11;
            }
            else if (place1==51) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved up a ladder!"<<endl;
                place1=67;
            }
            else if (place1==56) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=53;
            }
            else if (place1==62) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=19;
            }
            else if (place1==64) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=60;
            }
            else if (place1==71) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved up a ladder!"<<endl;
                place1=91;
            }
            else if (place1==80) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved up a ladder!"<<endl;
                place1=100;
            }
            else if (place1==87) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=24;
            }
            else if (place1==93) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=73;
            }
            else if (place1==95) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=75;
            }
            else if (place1==98) {
                cout<<name1<<"'s number: "<<place1<<endl;
                cout<<name1<<"'s moved down a chute!"<<endl;
                place1=78;
            }

            //Output place1
            cout<<name1<<"'s number: "<<place1<<endl;

            //Win Determination and Display Win
            if (winDet(place1)==true) {
                cwin1++;
                cout<<endl;
                cout<<name1<<" wins!"<<endl<<endl;
                if (i==nGames) {
                    cout<<left<<setw(13)<<name1<<"wins = "<<setw(3)<<cwin1<<endl;
                }
            }
            
        }while(place1!=100);
    }
}

void chutlad (int place1,int place2,int nGames,int cwin1,int cwin2,
                int win1,int win2,int end1,int end2,string name1,string name2) {
    int die;
    //For loop for number of games
    for (int i=1;i<=nGames;i++) {

        //Reset place, wins, and ends
        place1=place2=0;
        win1=win2=end1=end2=false;

        //Loop turns in order
        do {
            //First player's turn
            do {
                die=rand()%6+1;     //Dice roll
                place1+=die;        //Place before chutes or ladders

                //Place cannot go over 100
                while (place1>100) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<"You cannot land over 100. Go back!"<<endl;
                    place1-=die;   //Backtrack place1
                }

                //Testing chutes and ladders
                if (place1==1) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved up a ladder!"<<endl;
                    place1=38;
                }
                else if (place1==4) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved up a ladder!"<<endl;
                    place1=14;
                }
                else if (place1==9) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved up a ladder!"<<endl;
                    place1=31;
                }
                else if (place1==16) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=6;
                }
                else if (place1==21) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved up a ladder!"<<endl;
                    place1=42;
                }
                else if (place1==28) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved up a ladder!"<<endl;
                    place1=84;
                }
                else if (place1==36) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved up a ladder!"<<endl;
                    place1=44;
                }
                else if (place1==47) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=26;
                }
                else if (place1==49) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=11;
                }
                else if (place1==51) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved up a ladder!"<<endl;
                    place1=67;
                }
                else if (place1==56) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=53;
                }
                else if (place1==62) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=19;
                }
                else if (place1==64) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=60;
                }
                else if (place1==71) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved up a ladder!"<<endl;
                    place1=91;
                }
                else if (place1==80) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved up a ladder!"<<endl;
                    place1=100;
                }
                else if (place1==87) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=24;
                }
                else if (place1==93) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=73;
                }
                else if (place1==95) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=75;
                }
                else if (place1==98) {
                    cout<<name1<<"'s number: "<<place1<<endl;
                    cout<<name1<<"'s moved down a chute!"<<endl;
                    place1=78;
                }

                //Output place1
                cout<<name1<<"'s number: "<<place1<<endl;

                //Win Determination - Ternary Operator
                (place1==100)?(win1=true):(win1=false);

                //End first player's turn
                end1=true;
                end2=false;

                //End of game?
                if (win1==true) {
                    end2=true;
                    cwin1++;
                }

            }while (end1==false);

            //Second player's turn
            while (end2==false) {
                die=rand()%6+1;     //Dice roll
                place2+=die;        //Place before chutes or ladders

                //Place cannot go over 100
                while (place2>100) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<"You cannot land over 100. Go back!"<<endl;
                    place2-=die;    //Backtrack place2
                }

                //Testing chutes and ladders
                if (place2==1) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved up a ladder!"<<endl;
                    place2=38;
                }
                else if (place2==4) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved up a ladder!"<<endl;
                    place2=14;
                }
                else if (place2==9) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved up a ladder!"<<endl;
                    place2=31;
                }
                else if (place2==16) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=6;
                }
                else if (place2==21) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved up a ladder!"<<endl;
                    place2=42;
                }
                else if (place2==28) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved up a ladder!"<<endl;
                    place2=84;
                }
                else if (place2==36) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved up a ladder!"<<endl;
                    place2=44;
                }
                else if (place2==47) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=26;
                }
                else if (place2==49) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=11;
                }
                else if (place2==51) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved up a ladder!"<<endl;
                    place2=67;
                }
                else if (place2==56) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=53;
                }
                else if (place2==62) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=19;
                }
                else if (place2==64) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=60;
                }
                else if (place2==71) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved up a ladder!"<<endl;
                    place2=91;
                }
                else if (place2==80) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved up a ladder!"<<endl;
                    place2=100;
                }
                else if (place2==87) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=24;
                }
                else if (place2==93) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=73;
                }
                else if (place2==95) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=75;
                }
                else if (place2==98) {
                    cout<<name2<<"'s number: "<<place2<<endl;
                    cout<<name2<<"'s moved down a chute!"<<endl;
                    place2=78;
                }

                //Output place2
                cout<<name2<<"'s number: "<<place2<<endl;

                //Win Determination
                if (place2==100) {
                    win2=true;
                    cwin2++;
                }

                //End second player's turn
                end1=false;
                end2=true;
            }
        }while (win1==false&&win2==false);

        //Display who wins
        if (win1==true||win2==true) {
            if (win1==true) {
                cout<<endl<<name1<<" wins!"<<endl<<endl;
                if (i==nGames) {
                    cout<<left<<setw(13)<<name1<<"wins = "<<setw(3)<<cwin1<<endl;
                    cout<<left<<setw(13)<<name2<<"wins = "<<setw(3)<<cwin2<<endl;
                }
            }
            else {
                cout<<endl<<name2<<" wins!"<<endl<<endl;
                if (i==nGames) {
                    cout<<left<<setw(13)<<name1<<"wins = "<<setw(3)<<cwin1<<endl;
                    cout<<left<<setw(13)<<name2<<"wins = "<<setw(3)<<cwin2<<endl;
                }
            }
        }
    }
}

bool winDet (int &place1) { //Pass by reference
    if (place1==100) {
        return true;
    }
    else return false;
}

void output (int nPlayers,int nGames,int cwin1,int cwin2,
        string name1,string name2) {
    //Output results
    if (nPlayers==1) {
        cout<<"Number of players = "<<setw(3)<<nPlayers<<endl;
        cout<<"Number of games   = "<<setw(3)<<nGames<<endl;
    }
    else {
        cout<<"Number of players = "<<setw(3)<<nPlayers<<endl;
        cout<<"Number of games   = "<<setw(3)<<nGames<<endl;
    }
    
    //Exit
    exit(0);
}