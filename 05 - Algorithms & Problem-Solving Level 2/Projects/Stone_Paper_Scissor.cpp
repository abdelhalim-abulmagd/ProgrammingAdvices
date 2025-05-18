#include <iostream>
using namespace std;


enum EnChoices { Stone = 1, Paper = 2, Scissor = 3, Yes = 4, No = 5};
enum EnPlayer { Computer, Player, Equal };

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

EnChoices ReadChoice(string Msg)
{
    cout << Msg;
    short Choice;
    cin >> Choice;
    return static_cast<EnChoices>(Choice);
}

EnChoices GetRandomChoice()
{
    return static_cast<EnChoices> (RandomNumber(1, 3));
}

EnPlayer CheckWinner(EnChoices ComputerChoice, EnChoices PlayerChoice)
{
    switch (ComputerChoice)
    {
    case Stone:
        switch (PlayerChoice)
        {
        case Stone:
            return Equal;
        case Paper:
            return Player;
        case Scissor:
            return Computer;
        };

    case Paper:
        switch (PlayerChoice)
        {
        case Stone:
            return Computer;
        case Paper:
            return Equal;
        case Scissor:
            return Player;
        };

    case Scissor:
        switch (PlayerChoice)
        {
        case Stone:
            return Player;
        case Paper:
            return Computer;
        case Scissor:
            return Equal;
        };
    }
}

string GetChoiceString(EnChoices Choice)
{
    switch (Choice)
    {
    case Stone:
        return "Stone";
    case Paper:
        return "Paper";
    case Scissor:
        return "Scissor";
        break;
    }
}

string GetResult(EnPlayer player)
{
    switch (player)
    {
    case Computer:
        return "Computer";
    case Player:
        return "Player";
    case Equal:
        return "Equal";
    }
}

void PrintResultScreen(string Winner, EnChoices ComputerChoice, EnChoices PlayerChoice)
{
    cout << "Your Choice is : " << GetChoiceString(PlayerChoice) << '\n';
    cout << "Computer Choice is : " << GetChoiceString(ComputerChoice) << '\n';

    cout << "Winner Is " << Winner << '\n';
}

EnChoices GetAnswer(string Msg)
{
    cout << Msg;
    char Answer;
    cin >> Answer;
    
    return tolower(Answer) == 'y' ? Yes : No;
}

void StartGame()
{
    do
    {
        EnChoices PlayerChoice = ReadChoice("[1] Stone\n[2] Paper\n[3] Scissor\n");
        EnChoices ComputerChoice = GetRandomChoice();

        PrintResultScreen(GetResult(CheckWinner(ComputerChoice, PlayerChoice)), ComputerChoice, PlayerChoice);


    } while (GetAnswer("Wanna PlayAgain [Y] or [n] : ") == Yes);
}

int main()
{
    StartGame();
    return 0;
}
