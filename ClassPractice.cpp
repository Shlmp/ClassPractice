#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <clocale>


using namespace std;

int askNumber(string question, int high, int low = 1);

void vectorsPart1();
void vectorReserve();
void vectorIter();
void guessWord();
void iterInventory();
void guessWordTeacher();
void MatrixBox();
void inventoryDisplay();

//References
void swap();
void badSwap(int x, int y);
void goodSwap(int& x, int& y);

void display(const vector<string>& vec);

//Exam2
string GetRandomItem(vector<string>& items);
void DisplayInventory(vector<string>& inventory);
bool AskYesNo(string question);
void ShowMenu();
void ReplaceItem(int& replace);
void BuySpace(unsigned int& gems, vector<string>& inventoryBought, string& itemReplace);

//only constants are global
const int MAX_ITEMS = 6;
const int SPACE_COST = 6;
const int FREE_ITEMS = 3;

int main()
{
    std::setlocale(LC_ALL, "es_ES.UTF-8");
    unsigned int gems = 8;

    //Items
    vector<string> items = { "Sword", "Hammer", "Bomb", "Shield" };

    //Inventory
    vector<string> inventory;
    inventory.reserve(MAX_ITEMS);
    vector<string> ::const_iterator iter;
    bool isContinue;
    int replace = 0;

    do
    {
        system("cls");
        cout << "\n--- INVENTORY ---\n";
        cout << "Gems: " << gems << endl;

        //random_shuffle(items.begin(), items.end());
        string itemFound = GetRandomItem(items);

        cout << "You found a " << itemFound << "!!\n";
        if (inventory.size() >= FREE_ITEMS)
        {
            ShowMenu();
            int option = askNumber("\nChoose a number between: ", 3);

            switch (option)
            {
            case 1:
                system("cls");
                cout << "What item dou you want to replace?\n";
                DisplayInventory(inventory);
                ReplaceItem(replace);
                inventory[replace] = itemFound;
                break;
            case 2:
                break;
            case 3:
                system("cls");
                DisplayInventory(inventory);
                BuySpace(gems, inventory, itemFound);
                break;
            default:
                break;
            }
        }
        else
        {
            inventory.push_back(itemFound);
        }

        //DisplayItems
        DisplayInventory(inventory);

        isContinue = AskYesNo("Continue exploring?");
    } while (isContinue);
    system("cls");
    cout << "\nbye\n";
}

void ReplaceItem(int& replace)
{
    cin >> replace;
    cout << "\n--- NEW INVENTORY ---\n";
}

void BuySpace(unsigned int& gems, vector<string>& inventoryBought, string& itemReplace)
{
    cout << "A new slot costs " << SPACE_COST << " gems!\n";
    if (gems > SPACE_COST)
    {
        AskYesNo("You can buy a new slot!!\n Do you wish to do so?\n");
        gems = gems - SPACE_COST;
        cout << "Congratulations, you bought a new slot!\n";
        inventoryBought.push_back(itemReplace);
    }
    else
    {
        cout << "You do not have enough for a new slot\n";
    }
}

string GetRandomItem(vector<string>& items)
{
    srand(time(NULL));
    int itemRandomIndex = (rand() % items.size());
    string itemSelected = items[itemRandomIndex];

    return itemSelected;
}

void DisplayInventory(vector<string>& inventory)
{
    vector<string> ::const_iterator iter;
    int i = 0;
    
    cout << "\n--- Your Items---\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << i << " - "  << *iter << endl;
        i++;
    }
}

bool AskYesNo(string question)
{
    char answer;

    do
    {
        cout << "\n" << question << "(y/n)\n";
        cin >> answer;
    } while (answer != 'y' && answer != 'n');
    if (answer == 'y')
    {
        return true;
    }
    return false;
}

void ShowMenu()
{
    cout << "\n      Oh no!!\nYour inventory is full!!!\nWhat would you like to do?\n";
    cout << "1 - Replace object\n";
    cout << "2 - Leave behind new object\n";
    cout << "3 - Buy new slot for " << SPACE_COST << " gems\n";
}

void TicTacToe()
{
    const int ROWS = 3;
    const int COLUMNS = 3;
    char board[ROWS][COLUMNS] = { {'O', 'X', 'O'},
                                  {' ', 'X', 'X'},
                                  {'X', 'O', 'O'} };

    cout << "---- TIC TAC TOE ----\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    cout << endl << "---- TIC TAC TOE ----" << endl;
    board[1][0] = 'X';
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << "X wins!!\n";
}

void MatrixBox()
{
    const int HEIGHT_WITH = 80;
    for (int i = 0; i < HEIGHT_WITH; i++)
    {
        for (int j = 0; j < HEIGHT_WITH; j++)
        {
            int Sumij = i + j;
            if (i == 0 || j == 0 || i == HEIGHT_WITH - 1 || j == HEIGHT_WITH - 1 || i == j || Sumij == HEIGHT_WITH - 1)
            {
                cout << " 1 ";
            }
            else
            {
                cout << " . ";
            }
        }
        cout << endl;
    }
}

void inventoryDisplay()
{
    vector<string> inventory;

    inventory.push_back("Sword");
    inventory.push_back("Armor");
    inventory.push_back("Gun");

    cout << "Your inventory is" << endl;
    display(inventory);
}

void display(const vector<string>& vec)
{
    vector<string>::const_iterator iter;

    for (iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << endl;
    }
}

//Swap references
void swap()
    {
    int firstScore = 10;
    int secondScore = 100;
    int temporalScore = 0;

    cout << "First Score: " << firstScore << endl << "Second Score: " << secondScore << endl;

    //BAD SWAP
    badSwap(firstScore, secondScore);

    cout << endl << "CHANGE" << endl << endl;
    cout << "First Score: " << firstScore << endl << "Second Score: " << secondScore;

    //GOOD SWAP
    goodSwap(firstScore, secondScore);

    cout << endl << endl << "CHANGE" << endl << endl;
    cout << "First Score: " << firstScore << endl << "Second Score: " << secondScore;
    }

void badSwap(int x, int y)
{
    int aux = x;
    x = y;
    y = aux;
}

void goodSwap(int& x, int& y)
{
    int aux = x;
    x = y;
    y = aux;
}

void guessWordTeacher()
{
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    vector<string> words;
    words.push_back("COMPUTER");
    words.push_back("GAME");
    words.push_back("CODE");
    words.push_back("REFRIGERATOR");

    srand(time(NULL));
    int randomNumber = rand();
    int wordsRandomIndex = (randomNumber % words.size());
    string wordSelected = words[wordsRandomIndex];

    //cout << wordSelected << endl;

    random_shuffle(wordSelected.begin(), wordSelected.end());
    cout << wordSelected << endl;

    string correctWord;

    do
    {
        cin >> correctWord;
        transform(correctWord.begin(), correctWord.end(), correctWord.begin(), ::toupper);
        //cout << correctWord << endl;

        if (correctWord == words[wordsRandomIndex])
        {
            cout << "You guessed right!!" << endl;
            break;
        }
        else
        {
            attempts++;
            cout << "You failed... really?\nNow you only have " << MAX_ATTEMPTS - attempts << " attempts, Congratz" << endl;
        }
    } while (attempts != MAX_ATTEMPTS);

    if (attempts == MAX_ATTEMPTS)
    {
        cout << endl << "You lost a simple guessing game, congratz. Your better off graduating life" << endl << "BTW the word was: ";
        cout << words[wordsRandomIndex];
    }
    else
    {
        cout << endl << "yay! You got it!! And in " << attempts + 1 << " attempts no less";
    }
}

void iterInventory()
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

int askNumber(string question, int high, int low)
{
    int number = 0;
    do {
        cout << question << low << " & " << high << endl;
        cin >> number;
    } while (number > high || number < low);
    return number;
}