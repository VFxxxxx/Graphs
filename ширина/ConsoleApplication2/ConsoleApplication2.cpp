
//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(vector <int> E, vector <int> G, vector <bool> &color, int u, int &count, int n)
{
	int p = 0;
	int en = G[u];
	int st;
	if (u == 0) { st = 0; } //параметры для того, что бы все рёбра из данной вершины просматривать
	else { st = G[u - 1]; }
	for (int i = st; i < en; i++) {
		//cout << E[ i];
		//cin >> p;
		if (color[E[i]] == true)
		{ 
			color[E[i]] = false;
			cout << E[i]+1 << endl;
			count++;
			dfs(E, G, color, E[i], count, n);
		}
	}
}




int main()
{
	int n, s, count = 1, temp;
	ifstream fin("input.txt");
	fin >> n >> s;
	s--;
	vector <int> G(n);
	vector <int> E(n*n);

	//vector <vector <bool>> Adj(n);
	vector <bool> color(n);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		color[i] = true;
		for (int j = 0; j < n; j++)
		{
			fin >> temp;
			if (temp == 1) {
				//	Adj[v].insert(u);
				E[k] = j;
				k++;
			}
		}
		G[i] = k;
	}
	fin.close();
	color[s] = false;
	cout << s + 1 << endl;
	dfs(E, G, color, s, count, n);
	ofstream fout("output.txt");
	fout << count; //выводит число вершин в одной компоненте связности с данной
	fout.close();
	//cin >> s;
	return 0;
}
//https://informatics.mccme.ru/submits/view.php?user_id=368657#1