/*
Matthew Winter
CSC 275
Assignment 1 - MechTech

Overview

	Object-Oriented Programming using  Classes, Encapsulation, Abstraction, Polymorphism, and Inheritance.

Guidelines
	You may create a project called Pirates vs Ninjas, then meet each expectation below in your application.

	Or

	As long as you meet each expectation below in your application, you may use any theme you like instead of Pirates and Ninjas. Some examples are, but not limited to.

	Autos, Trucks and Sports Cars.
	Boxes, Moving Boxes, Lunch Boxes.
	Animals, Tigers, Bears, and llamas.
	Spaceship, capital ship, fighter, and shuttle.
	Feel free to be creative and expand on content.

In your main() function Expectations
	In your main function, display a cool intro to the game.
	Add a game loop into your main() function and give a user an exit choice after the game or a scenario is over.

Using Classes Expectations
	Create a class called GameStructure.

Using Inheritance Expectations
	Create a class called Character which inherits from the GameStructure class.
	Create a public property in the Character class and call it Name.
	Create 2 classes which inherit from the Character class.  (examples, ninja and pirate).
	Create a method called ThrowStars in the Ninja class which outputs the phrase to the screen "I am throwing stars!";
	Create a method called UseSword in the Pirate class which outputs to the screen "I am Swooshing my Sword!".
	Create a constructor for both subclasses of the  Character class to initialize all public and private properties in the Character class and subclasses. (Hint: The constructor is only needed in the Ninja and Pirate classes)

Using Encapsulation and Abstraction Expectations
	Create one private property called Health in the Character superclass. (Encapsulation)
	Create getter and setter public methods in the Character superclass to access and update this private Health property. (Abstraction)
	In the setter method check health before setting the value, if the new Health value will be less than zero, then set the property Health to zero and display "Character has Expired..." to the screen.

Using Polymorphism Expectations
	Create 2 methods named Talk using Overloading Polymorphism in the Character class.
	Give one Talk method this method signature:  void Talk(string stuffToSay)
	Give the other Talk this method signature:  void Talk(string name, string stuffToSay)
	Make both Talk methods say their name then stuff to say.
	Create a virtual attack method in the Character class that returns 10 hit points.
	Create an override attack method in both subclasses (Ninja, and Pirate) of the Character class using Overriding Polymorphism and set their attack return values at 25 hit points.

Abstraction Expectations
	Create a pure virtual method called Help in the GameStructure class. (Abstraction)
	Override the Help method in the Character class.
	Override the Help method in both character subclasses.

Pro Tips for the Help methods:

	The Help Methods return type would be void and take no parameters.
	In the GameStructure class, the Help method would be virtual and empty.
	In the Character class, the Help method would be overridden and empty.
	In each character class, Ninja and Pirate the Help method would look something like this.

void Help()
{
cout << "Ninja's are really cool, can you can use them to throw stars!" << endl;
}

Other Expectations
	Using your own comments, comment each line of code with the exception of cout statements unless it is at the top of a block of them.

	You must have a great user experience.

Submission Deliverables
	Do NOT submit a zip, if you must submit a bunch of files do it as a link to a git repo
	Submit  a video of your program in action.  Show all functionality.
*/

#include <iostream> // Including the input/output stream library.
#include <string>   // Including the string library.
#include <cstdlib>  // Including the C standard library for random numbers.
#include <ctime>    // Including the C time library for seeding random numbers.
#include <limits>   // Including limits for input validation.
using namespace std; // Using the standard namespace.

// Variables
int choice; // Declaring an integer variable called choice.

// Parent Class
class GameStructure { // Base class for game elements.
public:
    virtual void Help() = 0; // Pure virtual function to be implemented by derived classes.
};

// Child Class
class Character : public GameStructure { // Character class inheriting from GameStructure.
private:
    int Health; // Private property for character's health.

public:
    string Name; // Public property for character's name.

    // Getter and Setter for Health
    int GetHealth() {
        return Health;
    }

    void SetHealth(int newHealth) {
        if (newHealth < 0) {
            Health = 0;
            cout << Name << " has expired..." << endl;
        }
        else {
            Health = newHealth;
        }
    }

   // Overloaded Talk methods using Polymorphism
   // void Talk(string stuffToSay) {
   //    cout << Name << " says: " << stuffToSay << endl;
   //}
   //
   // void Talk(string name, string stuffToSay) {
   //     cout << name << " says: " << stuffToSay << endl;
   //}

    // Virtual Attack method
    virtual int Attack(int attackChoice) {
        return 10; // Base attack value.
    }

    // Overriding the Help method
    void Help() { // Empty implementation as per assignment requirement.
    }
};

// RedMech Class
class RedMech : public Character { // RedMech class inheriting from Character.
public:
    // Constructor to initialize properties
    RedMech() {
        Name = "Red Mech";
        SetHealth(100);
    }

    // Unique methods for RedMech
    int UseRocketGlove() {
        cout << "Using Rocket Glove attack!" << endl;
        return 25; // Damage value for Rocket Glove.
    }

    int UseFlameThrower() {
        cout << "Using Flame Thrower attack!" << endl;
        return 20; // Damage value for Flame Thrower.
    }

    // Overriding the Attack method
    int Attack(int attackChoice) {
        if (attackChoice == 1) {
            cout << Name << " attacks with Rocket Glove!" << endl;
            return UseRocketGlove();
        }
        else if (attackChoice == 2) {
            cout << Name << " attacks with Flame Thrower!" << endl;
            return UseFlameThrower();
        }
        else {
            cout << Name << " makes a basic attack!" << endl;
            return 10; // Basic attack damage.
        }
    }

    // Overriding the Help method
    void Help() {
        cout << "Red Mechs are close-range brawlers with high health (100pts) but lower damage." << endl;
    }
};

// BlueMech Class
class BlueMech : public Character { // BlueMech class inheriting from Character.
public:
    // Constructor to initialize properties
    BlueMech() {
        Name = "Blue Mech";
        SetHealth(75);
    }

    // Unique methods for BlueMech
    int FireRailgun() {
        cout << "Firing Railgun attack!" << endl;
        return 35; // Damage value for Railgun.
    }

    int LaunchMissiles() {
        cout << "Launching Missiles attack!" << endl;
        return 25; // Damage value for Missiles.
    }

    // Overriding the Attack method
    int Attack(int attackChoice) {
        if (attackChoice == 1) {
            cout << Name << " attacks with Railgun!" << endl;
            return FireRailgun();
        }
        else if (attackChoice == 2) {
            cout << Name << " attacks with Missiles!" << endl;
            return LaunchMissiles();
        }
        else {
            cout << Name << " makes a basic attack!" << endl;
            return 10; // Basic attack damage.
        }
    }

    // Overriding the Help method
    void Help() {
        cout << "Blue Mechs are long-range snipers with lower health (75pts) but higher damage." << endl;
    }
};

// Introduction functions
void DisplayIntro1() {
    cout << "Welcome to MechTech!" << endl;
    cout << "In this game, you will be able to choose between two factions." << endl;
    cout << "The Red or the Blue." << endl;
    cout << "Each piloting a mech in the battle arena." << endl;
    cout << "Each faction has its own unique abilities and playstyle." << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore(); // Clear the input buffer
    cin.get();    // Wait for the user to press Enter.
}

void DisplayIntro2() {
    cout << "Please choose your faction." << endl;
    cout << "1. Red Mech" << endl;
    cout << "The Red faction is a close-range brawler with high health (100pts) but lower damage." << endl;
    cout << "2. Blue Mech" << endl;
    cout << "The Blue faction is a long-range sniper with lower health (75pts) but higher damage." << endl;
    cout << "3. Exit" << endl;
}

// Function to prompt user for attack choice
int GetPlayerAttackChoice() {
    int attackChoice;
    cout << "Choose your attack:" << endl;
    cout << "1. Primary Attack" << endl;
    cout << "2. Secondary Attack" << endl;
    cin >> attackChoice;
    // Clear the input buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return attackChoice;
}

// Main function with game loop
int main() {
    int userChoice = 1; // Initialize to 1 to ensure the loop runs at least once.
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation.

    do {
        DisplayIntro1(); // Display the game introduction.
        DisplayIntro2(); // Display faction choices.
        cin >> choice;   // Get the user's faction choice.

        // Clear the input buffer to prevent issues with leftover input
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Character* player = nullptr;   // Initialize to nullptr.
        Character* opponent = nullptr; // Initialize to nullptr.

        // Create player and opponent based on choice
        if (choice == 1) {
            player = new RedMech();
            opponent = new BlueMech();
            cout << "You have chosen the Red Mech." << endl;
        }
        else if (choice == 2) {
            player = new BlueMech();
            opponent = new RedMech();
            cout << "You have chosen the Blue Mech." << endl;
        }
        else if (choice == 3) {
            cout << "Exiting game." << endl;
            break; // Exit the game loop.
        }
        else {
            cout << "Invalid choice. Exiting game." << endl;
            break; // Exit the game loop.
        }

        // Game scenario
        cout << "Battle Start!" << endl;
        player->Help();   // Display player's mech help.
        opponent->Help(); // Display opponent's mech help.

        // Simulate battle
        while (player->GetHealth() > 0 && opponent->GetHealth() > 0) {
            // Player's turn
            cout << "\nYour turn!" << endl;
            int attackChoice = GetPlayerAttackChoice(); // Get player's attack choice.
            int damage = player->Attack(attackChoice);
            opponent->SetHealth(opponent->GetHealth() - damage);

            // Display health after player's attack
            cout << "\n[Health Update]" << endl;
            cout << player->Name << " Health: " << player->GetHealth() << endl;
            cout << opponent->Name << " Health: " << opponent->GetHealth() << endl;

            cout << "Press Enter to continue..." << endl;
            cin.get(); // Wait for the user to press Enter.

            if (opponent->GetHealth() == 0) {
                cout << opponent->Name << " has been defeated!" << endl;
                break;
            }

            // Opponent's turn
            cout << "\nOpponent's turn!" << endl;
            int opponentAttackChoice = (rand() % 2) + 1; // Random attack choice between 1 and 2.
            damage = opponent->Attack(opponentAttackChoice);
            player->SetHealth(player->GetHealth() - damage);

            // Display health after opponent's attack
            cout << "\n[Health Update]" << endl;
            cout << player->Name << " Health: " << player->GetHealth() << endl;
            cout << opponent->Name << " Health: " << opponent->GetHealth() << endl;

            cout << "Press Enter to continue..." << endl;
            cin.get(); // Wait for the user to press Enter.

            if (player->GetHealth() == 0) {
                cout << player->Name << " has been defeated!" << endl;
                break;
            }
        }

        // Cleanup
        if (player != nullptr) {
            delete player;
            player = nullptr;
        }
        if (opponent != nullptr) {
            delete opponent;
            opponent = nullptr;
        }

        // Prompt to play again
        cout << "Do you want to play again? (1 = Yes, 2 = No): ";
        cin >> userChoice;

        // Clear the input buffer
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (userChoice == 1);

    cout << "Thank you for playing MechTech!" << endl;
    return 0; // End of the program.
}
