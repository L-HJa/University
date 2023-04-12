#include"Header.h"
#include"poker.h"

int main()
{
	SetConsoleOutputCP(65001);

	LPCWSTR TitleName = TEXT("Black Jack");
	SetConsoleTitle(TitleName);
	
	srand(time(NULL));
	Newgame();

	system("pause");
	return 0;
}