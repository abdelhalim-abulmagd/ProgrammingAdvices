
#include <iostream>
#include <string>

using namespace std;


string NumberToText(long long int Number)
{
    string Text = "";
        
    string OneToNine[]{ "", "One", "Two", "Three",  "Four", "Five", 
        "Six",  "Seven", "Eight", "Nine","Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    string Tens[]{ "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    long long int Tmp = Number;

    if (Number < 0)
    {
        Number = -Number;
        Text += "Negative ";
    }

    if (Number <= 19)
    {
        Text += OneToNine[Number];
        return Text;
    }

    else if (Number >= 20 && Number <= 99)
    {
        int Remainder = Number / 10;

        Text += Tens[Remainder] + " ";

        Text += NumberToText(Number % 10);
        return Text;
    }

    else if (Number >= 100 && Number <= 999)
    {

        int Remainder = Number  / 100;
        
        Text += OneToNine[Remainder] + " Hundreds ";
        Text += NumberToText(Number % 100);
        return Text;
    }

    else if (Number >= 1000 && Number <= 9999)
    {

        int Remainder = Number / 1000;

        Text += OneToNine[Remainder] + " Thousands ";
        Text += NumberToText(Number % 1000);
        return Text;
    }
    else if (Number >= 10000 && Number <= 99999)
    {

        int Remainder = Number / 10000;

        Text += Tens[Remainder] + "-";
        Text += NumberToText(Number % 10000);
        return Text;
    }
    else if (Number >= 100000 && Number <= 999999)
    {

        int Remainder = Number / 100000;

        Text += OneToNine[Remainder] + " Hundred ";
        Text += NumberToText(Number % 100000);
        return Text;
    }

    else if (Number >= 1000000 && Number <= 9999999)
    {

        int Remainder = Number / 1000000;

        Text += OneToNine[Remainder] + " Million ";
        Text += NumberToText(Number % 1000000);
        return Text;
    }

    return Text;
}


int main()
{

    cout << NumberToText(120);
}
