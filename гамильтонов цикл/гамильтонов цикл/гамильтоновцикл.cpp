// гамильтоновцикл.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int n;
int a[20][20];
bool vis[20];
int answer = 100000;
int s = 0;

bool dfs(int v)
{
	bool flag = true;
	bool res;

	vis[v] = true;
	if (v == 0) {
		for (int i = 0; i<n; i++) flag = flag && vis[i];
		if (flag) {
			vis[v] = false;
			if (answer>s) answer = s;
			return true;
		}

	}

	for (int i = 0; i<n; i++)
		if ((!vis[i]) && (a[v][i] != 0)) {
			s = s + a[v][i];
			res = dfs(i);
			s = s - a[v][i];
		}

	vis[v] = false;
	return false;
}


int main()
{
	
	ifstream fin("input.txt");
	bool final = false;

	fin >> n;

	if (n == 1) {
		cout << "0";
		return 0;
	}

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) fin >> a[i][j];

	for (int i = 0; i<n; i++)
	{
		s = a[0][i];
		final = dfs(i);
	}

	if (answer == 100000) cout << "-1";
	else cout << answer;
	cin >> s;
	return 0;
}
