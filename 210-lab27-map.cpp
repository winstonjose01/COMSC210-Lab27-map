// COMSC210 | Lab 27 | Winston Jose
// IDE Userd: Visual Studio code
// Github link : https://github.com/winstonjose01/COMSC210-Lab27-map 

#include <iostream>
#include <map>
#include <vector>
#include <limits>
using namespace std;

// Function declarations for each menu option and supporting functions
bool execute_choice(map<string, tuple<int,string,string>> &, int);
string add_village(map<string, tuple<int,string,string>> &);
void delete_village(map<string, tuple<int,string,string>> &,string);
void print_village(map<string, tuple<int,string,string>> &);
void increase_friendship(map<string, tuple<int,string,string>> &, string);
void decrease_friendship(map<string, tuple<int,string,string>> &, string);
void search_village(map<string, tuple<int,string,string>> &, string);

int main() {
    // declarations
    map<string, tuple<int,string,string>> villagerColors; // Map to store villager data
    int choice;  // Variable to store user menu choice
    bool flag = true;  // Flag to control the menu loop

    // Prepopulate map with villager data
    villagerColors["Drago"] = {5, "Alligator", "Snap to It!"};
    villagerColors["Kyle"] = {10, "Wolf", "Hubba hubba!"};
    villagerColors["Raymund"] = {8, "Cat", "Nice fit"};

    while(flag){
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Frienship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "choice --> ";
        cin >> choice;

        flag = execute_choice(villagerColors, choice);  // Process choice
    }
    return 0;
}
// Executes the selected menu choice and calls the relevant function
bool execute_choice(map<string, tuple<int,string,string>> &village, int choice){
    switch(choice){
        case 1: { // Add a villager to the map
                string name;
                name = add_village(village);  // Add villager and get their name
                print_village(village);
                cout << name << " has been added." << endl;
                cout << endl;
                break;
        }
        case 2:{ // Delete a village from the map
                string person;
                cout << "\nWho do you want to remove from the village?: ";
                cin >> person;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                delete_village(village, person);
                print_village(village);
                break;
        }
        case 3:{  // Increase points for a particular villager
                string name;
                cin.clear();
                cout << "\nWhich friend do you want to increase points?: ";
                cin >> name;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                increase_friendship(village, name);
                print_village(village);
                break;

        }
        case 4:{ // Decrease points for a particular villager
                string name;
                cin.clear();
                cout << "\nWhich friend do you want to decrease points?: ";
                cin >> name;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                decrease_friendship(village, name);
                print_village(village);
                break;

        }
        case 5:{ // Search the village using a name
                string name;
                cin.clear();
                cout << "\nWho do you want to find from the village?: ";
                cin >> name;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                search_village(village,name);
                break;
        }
        case 6:{ 
                return false;  // Exit the menu loop
        }
        default:{ // If th input choice is not correct
                cout << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Choice is not valid." << endl << endl;
                return true;
                break;
        }
    }
    return true;
}

// Adds a new villager to the village map
// arguments: A map `village` that holds the villager data
// returns: A string, the name of the added villager
string add_village(map<string, tuple<int,string,string>> &village){
    string name;
    int level;
    string species;
    string phrase;

    cin.clear();
    cout << "Villager name: ";
    cin >> name;

    cout << "Friendship level:" ;
    cin >> level;

    cout << "Species: ";
    cin >> species;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Catchphrase: ";
    getline(cin, phrase);

    village.insert(make_pair(name,make_tuple(level,species,phrase)));
    return name;

}
// Deletes an existing villager from the village map
// arguments: A map `village` that holds the villager data and the name of the villager to be removed
// returns: No returns
void delete_village(map<string, tuple<int,string,string>> &village,string name){
    auto it = village.find(name);
    if (it != village.end()){
        village.erase(it);
    }
    else{
        cout << name << " is not part of the village." << endl;
    }
}
// Prints the members of the village
// arguments: A map `village` that holds the villager data.
// returns: No returns
void print_village(map<string, tuple<int,string,string>> &village){
    // access the map using iterators
    cout << "\nVillage details :" << endl;
    for (map<string, tuple<int,string, string>>::iterator it = village.begin(); 
                                               it != village.end(); ++it) {
        cout << "\t" << it->first << " [";
        cout << get<0> (it->second) << ", ";
        cout << get<1> (it->second) << ", ";
        cout << get<2> (it->second) << "] ";
        cout << endl;
    }
    cout << endl;
}
// Increases the frienship points of a particular villager
// arguments: A map `village` that holds the villager data and the name of the villager
// returns: No returns
void increase_friendship(map<string, tuple<int,string,string>> &village, string name){
    // access the map using iterators
    auto it = village.find(name);
    if (it != village.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        if (get<0>(it->second) >= 10){
            cout << "Your friendship level is already max out to 10." << endl;
            cout << "You cannot add anymore" << endl;
            return;
        }
        get<0> (it->second) =  get<0> (it->second) + 1;
    } else
        cout << endl << name << " not found." << endl;
}
// Decreases the frienship points of a particular villager
// arguments: A map `village` that holds the villager data and the name of the villager
// returns: No returns
void decrease_friendship(map<string, tuple<int,string,string>> &village, string name){
    // access the map using iterators
    auto it = village.find(name);
    if (it != village.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        if (get<0>(it->second) <= 0){
        cout << "\nYour friendship level is already at 0." << endl;
        cout << "You cannot deduct anymore" << endl;
        return;
        }
        get<0> (it->second) =  get<0> (it->second) - 1;
    } else
        cout << endl << name << " not found." << endl;
}
// Searches and for a particular villager using his/her name and prints their information
// arguments: A map `village` that holds the villager data and the name of the villager
// returns: No returns
void search_village(map<string, tuple<int,string,string>> &village, string name){
    // search for an element using .find() to avoid errors
    auto it = village.find(name);
    if (it != village.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << name << " [";
        cout << get<0> (it->second) << ", ";
        cout << get<1> (it->second) << ", ";
        cout << get<2> (it->second) << "] ";
        cout << endl << endl;
    } else
        cout << endl << name << " not found." << endl << endl;
    
}


