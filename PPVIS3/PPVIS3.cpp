#include "account.h"
#include"decrypt.h"
#include "operation.h"
#include"interface.h"
#include"user.h"
#include <iostream>

using namespace std;

int main(int argc, char* args[])
{
	account client;
	user clients;
	decrypt depozit;
	operation execute;
	interface view;
	int a;
	int b;
	int admin_password = 123456;
A:  system("cls");
	cout << "Choose operation " << endl;
	cout << "1-to create account " << endl;
	cout << "2-to check database" << endl;
	cout << "3-to check your depozit" << endl;
	cout << "4-to check your balance" << endl;
	cout << "5-to change your balance" << endl;
	cout << "6-to look at interface (only if you are admin)" << endl;

	cin >> a;
	if (a == 6)
	{
		cout << "Enter password" << endl;
		cin >> b;
		if (b == admin_password)
		{
			goto B;
		}
		else
		{
			cout << "You dont have access" << endl;
			goto A;
		}

	}
B:switch (a)
{
case 1:client.enter(); break;
case 2:clients.database(); break;
case 3:depozit.decrypt1(); break;
case 4:execute.printbalance(); break; 
case 5:execute.addordeletemoneytofromdepozit(); break;
case 6:view.show(); break;
}
int k;
cout << "Would you like to continue?(1-Yes,2-No)" << endl;
cin >> k;
if (k == 1)
{
	goto A;
}
else if (k == 2)
{
	cout << "Thank you" << endl;
}

}
