#include"interface.h"
#include<iostream>
#include<fstream>

using namespace std;

void interface::show()
{
	user person1;
	cout << "All information (admin access only)" << endl;
	ifstream fin;
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
		try
		{
			while (fin.read((char*)&person1, sizeof(user)))
			{
				cout << "User Number : " << person1.numberuser << "  ";
				cout << "User Password : " << person1.password << " ";
				cout << "User depozit : " << person1.data << " ";
				cout << endl;

			}
		}
		catch (const std::exception&ex)
		{
			cout << ex.what() << endl;
			cout << "Error" << endl;
		}

	}
	fin.close();

}
