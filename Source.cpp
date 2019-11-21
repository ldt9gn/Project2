#include"MorseCodeTree.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main()
{
	MorseTree tree;
	char x = tree.getletter("._");
	cout << x;
	cin.ignore();
}