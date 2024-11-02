#include <iostream>
#include <map>
#include <vector>
using namespace std;

int display_menu();
void add_map(map<string, tuple<int,string,string>> &);

int main() {
    // declarations
    map<string, tuple<int,string,string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Drago"] = {5, "Alligator", "Snap to It!"};
    villagerColors["Kyle"] = {10, "Wolf", "Hubba hubba!"};
    villagerColors["Raymund"] = {8, "Cat", "Nice fit"};
    //villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}

int display_menu(){
    int choice;
    switch(choice){
        case 1:
        break;
    }

    return choice;
}


void add_map(map<string, tuple<int,string,string>> &village){
    string name;
    int level;
    string species;
    string phrase;

    cout << "Villager name: ";
    getline(cin, name);
    cout << "Firendship level:" ;
    cin >> level;
    cout << "Species: ";
    getline(cin, species);
    cout << "Catchphrase: ";
    getline(cin, phrase);

    village.insert({{name},make_tuple(level,species,phrase)});

}