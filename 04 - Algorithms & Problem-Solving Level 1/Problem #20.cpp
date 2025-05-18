
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const float Pi = 3.14;
 
float ReadSquareSide()
{
	float Side;
	cout << "Side : ";
	cin >> Side;
	return Side;
}

float CalculateCircleAreaInscribedInSquare(const float &Side)
{
	return Pi *  pow(Side / 2, 2);
}	

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateCircleAreaInscribedInSquare(ReadSquareSide())));
}
