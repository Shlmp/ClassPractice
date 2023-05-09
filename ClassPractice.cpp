#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;

void vectorsPart1();
void vectorReserve();
void vectorIter();
void guessWord();


int main()
{
    vector<string> inventory;
    inventory.push_back("Sword");
    inventory.push_back("Shield");
    inventory.push_back("Hammer");
    inventory.push_back("Rifle");

    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;

    cout << "Your items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Exchange
    cout << "\n Your " << inventory[2] << " was traded for a bow";
    myIterator = inventory.begin() + 2;
    *myIterator = "Bow";
    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Size
    cout << "\n The name of the item " << *myIterator << " has ";
    cout << (*myIterator).size() << " letters";

    cout << "\n The name of the item " << *myIterator << " has "; //Another way of coding for iter
    cout << (myIterator)->size() << " letters";

    //Insert
    cout << "\n\nCongratulations! You retrieved your stolen bomb!!\n";
    inventory.insert(inventory.begin() + 4, "Bomb");
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Delete
    cout << "\nYour " << inventory[1] << " has been destroyed by an enemy!!!\n";
    inventory.erase(inventory.begin() + 1);
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }
}


void guessWord()
{
    string guesses = "nightmare";
    string guess2 = "";
    char playerGuess[11] = "";
    int lives = 5;


    cout << "The word is: " << guesses << endl;
    guess2 = guesses;
    random_shuffle(guesses.begin(), guesses.end());
    cout << " This are your mixed letters: " << guesses << "        Lives: " << lives << endl << endl;
    cout << "Now guess" << endl;

    do
    {
        cin >> playerGuess;

        if (playerGuess != guess2 && lives > 0)
        {
            cout << endl << "You guessed wrong" << endl;
            lives--;
            cout << "Guess again           Lives: " << lives << endl;
            if (lives < 2 && lives == 1)
            {
                cout << "This is your last try" << endl;
            }
            if (lives < 1)
            {
                cout << "You lose";
            }
        }
        else
        {
            cout << "You win";
            return;
        }
    } while (lives > 0);
}

void vectorIter()
{
    const int NUM_SCORES = 4;
    int score;

    vector<int>::const_iterator iter;

    vector<int> scores;

    for (int i = 0; i < NUM_SCORES; i++)
    {
        cout << "Score " << i + 1 << endl;
        cin >> score;
        scores.push_back(score);
    }

    cout << endl << "  Scores" << endl;
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }

    /*Find*/
    cout << "\nLets find out if your score is in the vector!! Whats your score?" << endl;
    cin >> score;

    iter = find(scores.begin(), scores.end(), score);

    if (iter != scores.end())
    {
        cout << endl << "Your score is in the vector\n";
    }
    else
    {
        cout << endl << "Your score does not exist here\n";
    }

    /*Random Shuffle*/
    srand(time(NULL));
    random_shuffle(scores.begin(), scores.end());
    cout << "\n Mixed Scores" << endl;
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }

    /*Sort*/
    cout << "\nLets change the order!" << endl;
    sort(scores.begin(), scores.end());
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }

    /*Sort Greater*/
    cout << "\nLets change the order again but backwards!" << endl;
    sort(scores.begin(), scores.end(), greater<int>());
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }


    string word = "Random";
    cout << endl << word << endl;
    random_shuffle(word.begin(), word.end());
    cout << word << endl;
}

void vectorReserve()
{
    vector<int> scores(10, 0);
    cout << "Vector size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;

    scores.reserve(11);

    cout << "Vector size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;
}

void vectorsPart1()
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