#include "account.h"
#include<iostream>
#include<fstream>


using namespace std;

void account::enter()
{

	user person1;

	cout << "Write your login" << endl;
	cin >> person1.numberuser;

	cout << "Write your password" << endl;

	cin >> person1.password;
	cout << "Put money" << endl;
	cin >> person1.data;


	cout << endl;
	ofstream fin;
	fin.exceptions(ofstream::badbit | ofstream::failbit);
	try
	{
		fin.open("person.txt", ofstream::app | ofstream::binary);
		
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Error" << endl;
	}
	if (!fin.is_open())
	{
		cout << "error" << endl;
	}
	else
	{
		fin.write((char*)&person1, sizeof(user));
	}
	fin.close();

}


