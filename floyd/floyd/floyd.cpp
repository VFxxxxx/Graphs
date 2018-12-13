// floyd.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"



#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
int n, k, mat[101][101], i, j;
int min(int a, int b) {

	if( a > b) return b;
	else return a;
}
int main()
{
	ifstream fin("input.txt");

	fin >> n;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			fin >> mat[i][j];
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
	ofstream fout("output.txt");
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			fout << mat[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
	return 0;
}