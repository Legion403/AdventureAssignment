// Adventure asignment

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    cout << "Hello Player! What is your Name?\n"; //Asks player for their name
    string playerName = "";
    cin >> playerName;

    if(playerName == "Brian") { //Special Message for the proffessor
    cout << "Hello Professor!\n";
    }
    cout << "\nHello " << playerName << "!\n"; 

    int Health = 10;  //Sets the values for health, turns, attack, block, the palyers gold, and the monsters gold. Also seeds for rand
    srand(time(0));
    int turns = 0;
    int attack = 0;
    int block = 0;
    int playerGold = 5;
    int monsterGold = 0;


    cout << "Okay, " << playerName << " The encounter is starting! You have 10 health\n"; //Tells the player the encounter is starting
    int finalTurn = 3 + rand() % 4 + 1; // sets the what turn will be the final turn. its 3 turns plus 1-4 turns
    while(true) {
        turns += 1;

        //If the player keeps playing and makes it to whatever number of turns final turn is set to, it congragulates the player and ends the game
        if(turns == finalTurn) {    
            cout << "" << playerName << ", you made it to the end! Congrats!";
            break;
            }        

        cout << "You encountered a monster!\n";


        attack = rand() % 4 + 1;  //sets attack to a random number between 1 and 4
        block = rand() % 4 + 1;  //sets blcok to a random number between 1 and 4


        // If block is higher than attack then the player blocks the attack
        if(block >= attack) { 
            cout << "You blocked its attack!\n";
            cout << "You got its gold!\n";
            monsterGold = rand() % 20 + 1;    //randomizes how much gold the mosnter was carrying
            playerGold = playerGold + monsterGold;     //adds hpwevermuch gold the monster had to the players gold total.
        } else { //if attack is more than block, the monster attacks the player
            cout << "OW! It attacked you!\n";
            Health = Health - attack;
            cout << "Your at " << Health << " heatlh!\n"; //tells the player how much health they have left
        }
            cout << "You have " << playerGold << " gold.\n";      
            cout << "You have been adventuring for " << turns << " turns.\n";  


            if(Health <= 5) { //if the players health is less than 5, this tells them to see a doctor
                cout << "You should see a doctor!\n";

                string wantsToSeeDoctor = "";
                cout << "Do you want to see a doctor? It costs 10 gold to heal 5 health\n";
                cin >> wantsToSeeDoctor;

                if(wantsToSeeDoctor == "Yes" || wantsToSeeDoctor == "yes" || wantsToSeeDoctor =="y") { //If the player does want to see a doctor
                    if(playerGold >= 10) {
                        cout << "You spent 10 gold to heal 5 health";
                        playerGold = playerGold - 10;
                        Health = Health + 5;  //costs the player 10 gold and heals them by 5 health
                    } if(playerGold <10) {
                        cout << "You dont have the funds!";
                    }
                }
            }

            if(Health <= 0) {
                
                cout << "Oh no, you died adventuring :( ";
                break;
            }
            cout << "\nDo you want to keep adventuring? Yes or No\n";
            string playerResponse = "";
            cin >> playerResponse; 

            if(playerResponse == "No" || playerResponse == "no") {
                cout << "You decided to stop the adventure, and head on home.";
                break;
            }


        
    }
}