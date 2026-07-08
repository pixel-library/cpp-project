#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <cctype>

using namespace std;

//==================== GLOBAL VARIABLES ====================//

char board[3][3];

string player1, player2;
char symbol1, symbol2;

string currentPlayer;
char currentSymbol;

int player1Wins = 0;
int player2Wins = 0;
int drawMatches = 0;
int totalMatches = 0;

//==================== FUNCTION PROTOTYPES ====================//

void menu();
void rules();

void initializeBoard();
void displayBoard();

void playerDetails();
void chooseSymbol();
void toss();

void playGame();
void playerMove();

bool checkWinner();
bool checkDraw();

void switchPlayer();

void displayScoreboard();
void resetScoreboard();

int getValidPosition();
char playAgain();

//==================== BOARD ====================//

void initializeBoard()
{
    char value = '1';

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j] = value++;
        }
    }
}

void displayBoard()
{
    cout << "\n";

    for(int i=0;i<3;i++)
    {
        cout << " ";

        for(int j=0;j<3;j++)
        {
            cout << board[i][j];

            if(j<2)
                cout << " | ";
        }

        cout << endl;

        if(i<2)
            cout << "---+---+---" << endl;
    }

    cout << endl;
}

//==================== RULES ====================//

void rules()
{
    cout << "\n========== TIC TAC TOE RULES ==========\n";

    cout << "1. Two players play the game.\n";
    cout << "2. Player 1 chooses X or O.\n";
    cout << "3. Toss decides who starts.\n";
    cout << "4. Enter positions from 1 to 9.\n";
    cout << "5. First player to make 3 in a row wins.\n";
    cout << "6. If board fills without winner, match is draw.\n";

    cout << "=======================================\n";
}

//==================== SCOREBOARD ====================//

void displayScoreboard()
{
    cout << "\n========== SCOREBOARD ==========\n";

    cout << "Total Matches : " << totalMatches << endl;

    cout << player1
         << " (" << symbol1 << ") Wins : "
         << player1Wins << endl;

    cout << player2
         << " (" << symbol2 << ") Wins : "
         << player2Wins << endl;

    cout << "Draw Matches : "
         << drawMatches << endl;

    cout << "===============================\n";
}

void resetScoreboard()
{
    player1Wins = 0;
    player2Wins = 0;
    drawMatches = 0;
    totalMatches = 0;

    cout << "\nScoreboard Reset Successfully!\n";
}

//==================== PLAYER DETAILS ====================//

void playerDetails()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Player 1 Name : ";
    getline(cin, player1);

    cout << "Enter Player 2 Name : ";
    getline(cin, player2);
}

//==================== SYMBOL SELECTION ====================//

void chooseSymbol()
{
    while(true)
    {
        cout << "\n"
             << player1
             << ", Choose Symbol (X/O): ";

        cin >> symbol1;

        symbol1 = toupper(symbol1);

        if(symbol1=='X' || symbol1=='O')
            break;

        cout << "Invalid Choice! Try Again.\n";
    }

    if(symbol1=='X')
        symbol2='O';
    else
        symbol2='X';
}

//==================== RANDOM TOSS ====================//

void toss()
{
    srand(time(0));

    int tossResult = rand()%2;

    if(tossResult==0)
    {
        currentPlayer = player1;
        currentSymbol = symbol1;
    }
    else
    {
        currentPlayer = player2;
        currentSymbol = symbol2;
    }

    cout << "\nToss Winner : "
         << currentPlayer
         << " (" << currentSymbol << ")\n";
}

//==================== INPUT VALIDATION ====================//

int getValidPosition()
{
    int position;

    while (true)
    {
        cout << "\n" << currentPlayer << " (" << currentSymbol
             << ") Enter Position (1-9): ";

        if (!(cin >> position))
        {
            cout << "Invalid Input! Enter numbers only.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (position < 1 || position > 9)
        {
            cout << "Position must be between 1 and 9.\n";
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Position already occupied.\n";
            continue;
        }

        return position;
    }
}

//==================== PLAYER MOVE ====================//

void playerMove()
{
    int position = getValidPosition();

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    board[row][col] = currentSymbol;
}

//==================== SWITCH PLAYER ====================//

void switchPlayer()
{
    if (currentPlayer == player1)
    {
        currentPlayer = player2;
        currentSymbol = symbol2;
    }
    else
    {
        currentPlayer = player1;
        currentSymbol = symbol1;
    }
}

//==================== WIN CHECK ====================//

bool checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentSymbol &&
            board[i][1] == currentSymbol &&
            board[i][2] == currentSymbol)
            return true;

        if (board[0][i] == currentSymbol &&
            board[1][i] == currentSymbol &&
            board[2][i] == currentSymbol)
            return true;
    }

    if (board[0][0] == currentSymbol &&
        board[1][1] == currentSymbol &&
        board[2][2] == currentSymbol)
        return true;

    if (board[0][2] == currentSymbol &&
        board[1][1] == currentSymbol &&
        board[2][0] == currentSymbol)
        return true;

    return false;
}

//==================== DRAW CHECK ====================//

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

//==================== PLAY GAME ====================//

void playGame()
{
    initializeBoard();

    toss();

    while (true)
    {
        displayBoard();

        playerMove();

        if (checkWinner())
        {
            displayBoard();

            cout << "\nCongratulations "
                 << currentPlayer
                 << "! You Win.\n";

            totalMatches++;

            if (currentPlayer == player1)
                player1Wins++;
            else
                player2Wins++;

            break;
        }

        if (checkDraw())
        {
            displayBoard();

            cout << "\nMatch Draw!\n";

            drawMatches++;
            totalMatches++;

            break;
        }

        switchPlayer();
    }
}

//==================== PLAY AGAIN ====================//

char playAgain()
{
    char choice;

    cout << "\nPlay Again? (Y/N): ";
    cin >> choice;

    return toupper(choice);
}

//==================== MENU ====================//

void menu()
{
    int choice;
    char again;

    do
    {
        cout << "\n========== TIC TAC TOE ==========\n";
        cout << "1. Play Game\n";
        cout << "2. Rules\n";
        cout << "3. Scoreboard\n";
        cout << "4. Reset Scoreboard\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            playerDetails();

            chooseSymbol();

            do
            {
                playGame();

                again = playAgain();

            } while (again == 'Y');

            break;

        case 2:

            rules();
            break;

        case 3:

            displayScoreboard();
            break;

        case 4:

            resetScoreboard();
            break;

        case 5:

            cout << "\nThank You!\n";
            break;

        default:

            cout << "Invalid Choice.\n";
        }

    } while (choice != 5);
}

//==================== MAIN ====================//

int main()
{
    menu();

    return 0;
}


