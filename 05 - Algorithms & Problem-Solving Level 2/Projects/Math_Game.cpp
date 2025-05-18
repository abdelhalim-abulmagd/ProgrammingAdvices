#include <iostream>
#include <vector>
using namespace std;

enum EnQuestionsLevels { Easy = 1, Medium = 2, Hard = 3, Mix = 4};
enum EnOperations { eAdd=1, eSubtraction=2, eMultiply=3, eDivide=4, eMix =5};
enum EnStatus { eWrong, eRight};
struct StRang
{
    int From;
    int To;
};

struct StGameInfo
{
    int QuestionsCount;
    EnQuestionsLevels Level;
    EnOperations Operation;
};

struct StQuestionInfo
{
    int Numerator;
    int Denominator;
    EnOperations Operation;
    float Solution;
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadNumber(string Msg)
{
    cout << Msg;
    int Number;
    cin >> Number;
    return Number;
}


StGameInfo ReadGameInfo()
{
    StGameInfo GameInfo;

    GameInfo.QuestionsCount = ReadNumber("How Many Questions Do You Want ? : ");
    GameInfo.Level = (EnQuestionsLevels)ReadNumber("Level : [1] Easy, [2] Medium, [3] Hard, [4] Mix, ? : ");
    GameInfo.Operation = (EnOperations)ReadNumber("Operation : [1] Add, [2] Subtraction, [3] Multiply, [4] Divide, [5] Mix, ? : ");
    
    return GameInfo;
}

StRang LevelRang(EnQuestionsLevels Level)
{
    StRang Rang;

    switch (Level)
    {
    case Easy:
        Rang.From = 1, Rang.To = 10;
        break;

    case Medium:
        Rang.From = 10, Rang.To = 200;
        break;

    case Hard:
        Rang.From = 200, Rang.To = 1000;
        break;

    case Mix:
        Rang.From = 1, Rang.To = 1000;
        break;
    }

    return Rang;
}

float Add(int Numerator, int Denominator)
{
    return Numerator + Denominator;
}

float Subtraction(int Numerator, int Denominator)
{
    return Numerator - Denominator;
}

float Multiply(int Numerator, int Denominator)
{
    return Numerator * Denominator;
}

float Divide(int Numerator, int Denominator)
{
    if (Numerator == 0)
        return Denominator;
    else if (Denominator == 0)
        return Numerator;

    return Numerator / Denominator;
}

float Calculator(int Numerator, int Denominator, EnOperations Operation)
{
    switch (Operation)
    {
    case eAdd:
        return Add(Numerator, Denominator);
    case eSubtraction:
        return Subtraction(Numerator, Denominator);
    case eMultiply:
        return Multiply(Numerator, Denominator);
    case eDivide:
        return Divide(Numerator, Denominator);
    }
}

EnOperations GetOpetation(EnOperations Operation)
{
    switch (Operation)
    {
    case eMix:
        return (EnOperations)RandomNumber(Easy, Hard);
    default:
        return Operation;
    }
}

string GetOpetationString(EnOperations Operation)
{
    switch (Operation)
    {
    case eAdd:
        return "+";
    case eSubtraction:
        return "-";
    case eMultiply:
        return "*";
    case eDivide:
        return "/";
    }
}

StQuestionInfo GetQuestion(EnQuestionsLevels Level, EnOperations Operation)
{
    StQuestionInfo Question;

    StRang Rang = LevelRang(Level);

    Question.Numerator = RandomNumber(Rang.From, Rang.To);
    Question.Denominator = RandomNumber(Rang.From, Rang.To);

    Question.Operation = GetOpetation(Operation);

    Question.Solution = Calculator(Question.Numerator, Question.Denominator, Question.Operation);

    return Question;
}

vector<StQuestionInfo> GetQuestions(StGameInfo GameInfo)
{
    vector<StQuestionInfo> Questions;

    for (size_t i = 0; i < GameInfo.QuestionsCount; i++)
    {
        Questions.push_back(GetQuestion(GameInfo.Level, GameInfo.Operation));
    }

    return Questions;
}

void PrintQuestion(StQuestionInfo Question)
{
    cout << Question.Numerator << '\n';
    cout << Question.Denominator << ' ';
    cout << GetOpetationString(Question.Operation) << '\n';

    cout << "------------------\n";
}


EnStatus CheckSolution(int PlayerSolution, int ComputerSolution)
{
    if (PlayerSolution == ComputerSolution)
        return eRight;
    return eWrong;
}

void PrintAnswer(EnStatus Status, float RightAnswer)
{
    switch (Status)
    {
    case eWrong:
        cout << "Your Answer Is Wrong The Right Answer Is : " << RightAnswer << '\n';
        break;
    case eRight:
        cout << "Your Answer Is Right\n";
        break;
    }
}
void StartGame()
{
    StGameInfo GameInfo = ReadGameInfo();
    vector<StQuestionInfo> Questions = GetQuestions(GameInfo);

    for (StQuestionInfo Question : Questions)
    {
        PrintQuestion(Question);
        PrintAnswer(CheckSolution(ReadNumber(""), Question.Solution), Question.Solution);
    }

}

int main()
{
    StartGame();
    return 0;
}
