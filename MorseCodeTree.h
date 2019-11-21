#pragma
#include<iostream>
#include<fstream> //So we can use txt
#include<string>
using namespace std;

struct node { 
	//Each node will either go left or right
	char data;
	node* left; //left is .
	node* right;//right is _
	virtual ~node() {}
	node()
	{
		left = NULL;
		right = NULL;
		data = NULL;
	}

};

class MorseTree {
public:
	MorseTree() {
		ifstream fin; //We're passing in the morse code .txt file
		fin.open("morse.txt");

		char letter; // This is the letter
		string code; // This is the character
		root = new node; // Declare the root
		while (fin.good()) // This puts every letter into the tree
		{
			fin >> letter; // This passes only the first character of each line (letter)
			fin >> code; //This passes in everything else in the line (the code);
			insert(letter, code);
		}
	};

	//Returns only one letter
	char getletter(string x)
	{
		node* temp = root;
		for (int i = 0; i < x.size();i++)
		{
			if (x[i] == '.')
			{
				temp = temp->left;
			}
			else if (x[i] == '_')
			{
				temp = temp->right;
			}
		}
		cout<<temp->data;
		return temp->data;
	};




private:
	void insert(char letter, string code)
	{
		node* temp = root;

		for (int i = 0;i <code.size();i++)
		{
			if (code[i] == '.')
			{
				if (temp->left == NULL)
				{
					temp->left = new node;
				}
				temp = temp->left;
			}
			else if (code[i] == '_')
			{
				if (temp->right == NULL)
				{
					temp->right = new node;
				}
				temp = temp->right;
			}
		}
		temp->data = letter;
	};
	node *root;
};