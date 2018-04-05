#include "Josephus.h"

int main()
{
	srand(time(NULL)); // random number seeder to generate different numbers each time

	char choice;
	List list = List();

	// try out with random numbers or 1-10
	//for (int i = 0; i < 10; i++)
	//{
	//	list.insert(i+1 /*rand() % 16*/ );
	//}
	//list.print();
	//list.josephus(1);

	while (true)
	{
		cin >> choice;
		switch (choice)
		{
		case 'i':
		{
			int temp;
			cin >> temp;
			list.insert(temp);
			break;
		}
		case 'p':
			list.print();
			break;
		case 'j':
		{
			int temp;
			cin >> temp;
			list.josephus(temp);
			break;
		}			
		case 'e':
			exit(1);
		default :
			break;
		}
	}

	_getch();
	return 0;
}