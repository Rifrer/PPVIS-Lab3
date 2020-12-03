#include "operation.h"
#include<iostream>
#include<fstream>
using namespace std;

void operation::addordeletemoneytofromdepozit()
{
	user person;
	int number;
	cout << "Enter your login"<<endl;
	cin >> number;
	
	ifstream fin1("person.txt", ios::binary);
	ofstream fout1("temporary.txt", ios::binary);

	while (!fin1.eof())
	{
		try
		{
		fin1.read((char*)&person, sizeof(user));
		if (number != person.numberuser and !fin1.eof())
		{
			fout1.write((char*)&person, sizeof(user));
		}
		if (number == person.numberuser and !fin1.eof())
		{
			int i;
			cout << "What would you like to do?(1-take money,2-put money) " << endl;
			cin >> i;
			int k = 0;
			int templmoney;
			if (i == 1)
			{
				templmoney = person.data;

				cout << "How much money would you like to take?" << endl;
				cin >> k;
				person.data = templmoney - k;
				
			}
			if (i == 2)
			{
				templmoney = person.data;
				cout << "How much money would you like to put?" << endl;
				cin >> k;
				person.data = templmoney + k;
			}
      
			fout1.write((char*)&person, sizeof(user));
		}
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
			cout << "Error" << endl;
		}
	}
	fin1.close();
	fout1.close();
	ifstream fin("temporary.txt", ios::binary);
	ofstream fout("person.txt", ios::binary);
	while (!fin.eof())
	{
		try
		{
		fin.read((char*)&person, sizeof(user));
		if (!fin.eof())
		{
			fout.write((char*)&person, sizeof(user));
		}
		}
		catch (const std::exception&ex)
		{
			cout << ex.what() << endl;
			cout << "Error" << endl;
		}
	}
	fin.close();
	fout.close(); 

}

void operation::printbalance()
{
	user person;
	int number;
	cout << "Enter your login" << endl;
	cin >> number;
	

	ifstream finn;
	
	try
	{
		finn.open("person.txt", ofstream::app | ofstream::binary);

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Error" << endl;
	}
	if (!finn.is_open())
	{
		cout << "error" << endl;
	}
	else
	{
		try
		{
		while (finn.read((char*)&person, sizeof(user)))
		{
			if (person.numberuser == number)
			{
				cout << "User Number is " << person.numberuser << endl;
				cout << "Your balance is " << person.data << endl;
			}
		}
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
			cout << "Error" << endl;
		}

	}
	finn.close();
}

