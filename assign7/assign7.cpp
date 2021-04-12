#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>


using namespace std;


int main() 
{
	string rowSequence;
	cout << "Enter the rowSequence: ";
	cin >> rowSequence;

	string columnSequence;
	cout << "Enter the columnSequence: ";
	cin >> columnSequence;

	int numRows = rowSequence.length();
	int numCols = columnSequence.length() ;


	int** twoDimTable = new int* [numRows];
	for (int rowIndex = 0; rowIndex < numRows; rowIndex++) 
	{
		twoDimTable[rowIndex] = new int [numCols];
	}

	//updating table
	for (int i = 0; i <= numRows; i++)
	{
		for (int j = 0; j <= numCols; j++)
		{
			if (i == 0 || j == 0)
				twoDimTable[i][j] = 0;

			else if (rowSequence[i - 1] == columnSequence[j - 1])
				twoDimTable[i][j] = twoDimTable[i - 1][j - 1] + 1;

			else
				twoDimTable[i][j] = max(twoDimTable[i - 1][j], twoDimTable[i][j - 1]);
		}
	}
	cout << "Row sequence: " << rowSequence << endl;
	cout << "Column sequence: " << columnSequence << endl;

	//displaying table
	for (int i = 0; i <= numRows; i++)
	{
		for (int j = 0; j <= numCols; j++)
		{
			cout << twoDimTable[i][j] << " ";
		}
		cout << endl;
	}

	//storing & retrieving LCS
	string LCS = "";

	int i = numRows, j = numCols;

	while (i > 0 && j > 0)
	{
		if (rowSequence[i - 1] == columnSequence[j - 1])
		{
			LCS = rowSequence[i - 1] + LCS;
			i--;
			j--;
		}
		else if (twoDimTable[i - 1][j] > twoDimTable[i][j - 1])
			i--;
		else
			j--;
	}

	cout << "Longest common sequence is: " << LCS;

	system("pause");

	return 0;
}