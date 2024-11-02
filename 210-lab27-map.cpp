#include <iostream>
#include <map>
#include <vector>
#include <limits>
using namespace std;

int execute_choice(map<string, tuple<int,string,string>> &, int);
void add_village(map<string, tuple<int,string,string>> &);
void delete_village(map<string, tuple<int,string,string>> &,string);
void print_village(map<string, tuple<int,string,string>> &);
void increase_friendship(map<string, tuple<int,string,string>> &, string);
void decrease_friendship(map<string, tuple<int,string,string>> &, string);
void search_village(map<string, tuple<int,string,string>> &, string);

int main() {
    // declarations
    map<string, tuple<int,string,string>> villagerColors;
    int choice;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Drago"] = {5, "Alligator", "Snap to It!"};
    villagerColors["Kyle"] = {10, "Wolf", "Hubba hubba!"};
    villagerColors["Raymund"] = {8, "Cat", "Nice fit"};



    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "choice --> ";
    cin >> choice;

    execute_choice(villagerColors, choice);
    //villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    // cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    // for (auto pair : villagerColors) {
    //     cout << pair.first << ": ";
    //     for (auto color : pair.second)
    //         cout << color << " ";
    //     cout << endl;
    // }



    // delete an element
    //villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    // string searchKey = "Audie";
    // auto it = villagerColors.find(searchKey);
    // if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
    //                                    // if searchKey is not found
    //     cout << "\nFound " << searchKey << "'s favorite colors: ";
    //     for (auto color : it->second)  // range loop to traverse the value/vector
    //         cout << color << " ";
    //     cout << endl;
    // } else
    //     cout << endl << searchKey << " not found." << endl;

    // // report size, clear, report size again to confirm map operations
    // cout << "\nSize before clear: " << villagerColors.size() << endl;
    // villagerColors.clear();
    // cout << "Size after clear: " << villagerColors.size() << endl;

    // return 0;
}

int execute_choice(map<string, tuple<int,string,string>> &village, int choice){
    switch(choice){
        case 1: add_village(village);
                print_village(village);
                break;
        case 2:{ 
                string person;
                cout << "Who do you want to remove from the village?: ";
                getline (cin, person);
                delete_village(village, person);
                print_village(village);
                break;
        }
        case 3:{
                string name;
                cout << "Which friend do you want to increase points?";
                getline(cin, name);
                increase_friendship(village, name);

        }
        case 4:{
                string name;
                cout << "Which friend do you want to decrease points?";
                getline(cin,name);
                decrease_friendship(village, name);
                break;

        }
        case 5:{
                string name;
                cout << "Who do you want to find from the village?: ";
                getline(cin,name);
                search_village(village,name);
                break;
        }
        case 6:{
                exit;
                break;
        }
        
        default: return
    }

    return choice;
}


void add_village(map<string, tuple<int,string,string>> &village){
    string name;
    int level;
    string species;
    string phrase;

    cin.clear();
    cout << "Villager name: ";
    getline(cin, name);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Friendship level:" ;
    cin >> level;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Species: ";
    getline(cin, species);

    cout << "Catchphrase: ";
    getline(cin, phrase);


    village.insert(make_pair(name,make_tuple(level,species,phrase)));

}

void delete_village(map<string, tuple<int,string,string>> &village,string name){
    auto it = village.find(name);
    if (it != village.end()){
        village.erase(it);
    }
    else{
        cout << name << " is not part of the village." << endl;
    }
}

void print_village(map<string, tuple<int,string,string>> &village){
    // access the map using iterators
    cout << "\nVillage details :" << endl;
    for (map<string, tuple<int,string, string>>::iterator it = village.begin(); 
                                               it != village.end(); ++it) {
        cout << it->first << " [";
        cout << get<0> (it->second) << ", ";
        cout << get<1> (it->second) << ", ";
        cout << get<2> (it->second) << "] ";
        cout << endl;
    }
}

void increase_friendship(map<string, tuple<int,string,string>> &village, string name){
    // access the map using iterators
    auto it = village.find(name);
    if (it != village.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        get<0> (it->second) =  get<0> (it->second) + 1;
    } else
        cout << endl << name << " not found." << endl;
}

void decrease_friendship(map<string, tuple<int,string,string>> &village, string name){
    // access the map using iterators
    auto it = village.find(name);
    if (it != village.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        get<0> (it->second) =  get<0> (it->second) - 1;
    } else
        cout << endl << name << " not found." << endl;
}

void search_village(map<string, tuple<int,string,string>> &village, string name){
    // search for an element using .find() to avoid errors

    auto it = village.find(name);
    if (it != village.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << name << " [";
        cout << get<0> (it->second) << ", ";
        cout << get<1> (it->second) << ", ";
        cout << get<2> (it->second) << "] ";
        cout << endl;
    } else
        cout << endl << name << " not found." << endl;
    
}


