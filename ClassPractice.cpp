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
    vector<string> playerInv(5);
    char space[10] = "0";

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

    cout << endl << inventory[0] << " has " << inventory[0].size() << " letters in it" << endl;

    cout << endl << "You lost an item in your last battle!" << endl;
    //Delete item from vector
    inventory.pop_back();

    //Iteration FOR
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }

    cout << endl << "An enemy has stolen all your weapons!!" << endl;
    inventory.clear();

    if (inventory.empty())
    {
        cout << "It is empty in here..." << endl;
    }
    else
    {
        for (unsigned int i = 0; i < inventory.size(); i++)
        {
            cout << inventory[i] << endl;
        }
    }

    cout << endl << "You can only have " << playerInv.size() << " in your inventory" << endl;

    cout << "Tell me what is in your inventory" << endl;
    for (unsigned int i = 0; i < 5; i++)
    {
        cin >> playerInv[i];
    }

    cout << endl << "This is your current inventory" << endl;
    for (unsigned int i = 0; i < playerInv.size(); i++)
    {
        cout << playerInv[i] << endl;
    }
}
