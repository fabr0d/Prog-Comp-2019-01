#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */	
using namespace std;

void print_vector_strings(vector<string> people)
{
	for (int i = 0; i < people.size(); i++)
	{
		cout << people[i] << ", ";
	}
	cout << " " << endl;
}

bool set_all_to_cero(vector<string> people)
{
	int cont = 0;
	for (int i = 0; i < people.size(); i++)
	{
		if (people[i] == "1")
		{
			cont++;
		}
	}
	
	if (cont==17)
	{
		ofstream outfile;
		outfile.open("people.txt");


		for (int i = 0; i < people.size(); i++)
		{
			outfile << "0" << endl;
		}
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	vector<string> people;
	ifstream file("people.txt");
	string str;
	while (getline(file, str))
	{
		people.push_back(str);
	}
	file.close();

	print_vector_strings(people);
	
	if (set_all_to_cero(people) == true)
	{
		cout << "ya salieron todos :s" << endl;
		return 0;
	}
	else
	{
		cout << "aun faltan" << endl;

	}

	srand(time(NULL));
	int randnum = rand() % 17+1;
	cout << "randnum: " << randnum << endl;
	
	while (people[randnum-1]=="1")
	{
		randnum = rand() % 17+1;
		cout << "randnum: " << randnum << endl;
	}
	cout << "El elejido para salir es : " << randnum << endl;

	people[randnum-1] = "1";

	ofstream outfile;
	outfile.open("people.txt");

	for (int i = 0; i < people.size(); i++)
	{
		outfile << people[i] << endl;
	}

}