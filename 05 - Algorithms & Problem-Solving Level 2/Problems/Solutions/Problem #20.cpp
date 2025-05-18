
#include <iostream>
#include <string>

using namespace std;

enum EnType { SpicialCharacter, Digit, SmallLetter, CapitalLetter};
enum EnASCII { SpicialCarachtersFrom = 33, SpicialCarachtersTo = 46,  Zero = 48, Nine = 57 , A = 65, Z = 90, a = 97, z = 122 };


int GetRandomNumber(int From, int To)
{
	srand(time(0));
	return rand() % (To - From + 1 ) + From ;
}

char GetRandom(EnType Type)
{
	switch (Type)
	{
	case SpicialCharacter:
		return GetRandomNumber(SpicialCarachtersFrom, SpicialCarachtersTo);
	case Digit:
		return GetRandomNumber(Zero, Nine);
	case SmallLetter:
		return GetRandomNumber(a, z);
	case CapitalLetter:
		return GetRandomNumber(A, Z);
	}
}

int main()
{

	cout << GetRandom(Digit);
}