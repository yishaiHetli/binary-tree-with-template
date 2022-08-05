//yishai hetli 318645173
#include <iostream>
#include<string>
using namespace std;
#include "SearchTree_h.h"
#include"Student.h"
enum {
	A = 'a', B, C, D, E
};
int main()
{
	SearchTree<Student>Ts;
	Student stu;
	char choise = 'a';
	while (choise != E)
	{
		cout << "enter a-e\n";
		cin >> choise;
		switch (choise)
		{
		case A:
			cout << "enter a student:\n";
			cin >> stu;
			Ts.add(stu);
			break;
		case B:
			cout << "enter a student:\n";
			cin >> stu;
			if (Ts.search(stu))
				Ts.remove(stu);
			else
				cout << "not exist\n";
			break;
		case C:
			cout << "enter a student:\n";
			cin >> stu;
			if (Ts.search(stu))
				cout << "exist\n";
			else
				cout << "not exist\n";
			break;
		case D:
			Ts.inOrder();
			break;
		case E:
			break;
		default:
			cout << "ERROR\n";
		}
	}

	return 0;
}
