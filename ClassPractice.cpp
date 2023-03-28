#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    //vector<string> myStuff = { "sword", "hammer", "bomb" };
    //vector<string> inventory(10);
    //vector<string> inventory(10, "  -  ");
    //vector<string> inventory(myStuff);

    vector<string> inventory;

    inventory.push_back("Sword");
    inventory.push_back("Hammer");
    inventory.push_back("Shield");
     
    cout << "You have " << inventory.size() << " items in your inventory" << endl;

    //Iteration FOR
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }

    cout << "\nYour " << inventory[0] << " has changed into a bomb!" << endl;
    inventory[0] = "Bomb";

    cout << endl;

    //Iteration DO-WHILE
    int i = 0;
    do
    {
        cout << inventory[i] << endl;
        i++;
    } while (i < inventory.size());
}
