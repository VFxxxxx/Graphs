// обходвширину.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
ofstream fout("output.txt");
void way(vector <int> &p, int s, int start)
{
	if (s != start)
	{
		way(p, p[s], start);
		fout << p[s] + 1 << ' ';
	}
}

int main()
{
	int n, temp;
	ifstream fin("input.txt");
	fin >> n;
	//vector <set <int>> Adj(n);
	vector <int> G(n);
	vector <int> E(n*n);

	vector <bool> color(n);//посещённость
	vector <int> p(n), d(n); //путь, расстояние
	queue <int> Q;// очередь
	int k = 0;
	//заполняем список смежности
	for (int v = 0; v < n; v++)
	{
		d[v] = -1;
		color[v] = false;
		p[v] = -1;

		for (int u = 0; u < n; u++)
		{
			fin >> temp;
			if (temp == 1) {
				//	Adj[v].insert(u);
				E[k] = u;
				k++;
			}
		}
		G[v] = k;
	}

	int start, dest;
	//считываем из какой вершины будем искать поиском в ширину расстояние до искомой
	fin >> start >> dest;
	fin.close();
	start--;
	dest--;
	Q.push(start);
	d[start] = 0;
	color[start] = true;
	//cout << start + 1 << endl;
	int en, st;
	//пошли запускать поиск
	while (!Q.empty())
	{
		int s = Q.front();
		Q.pop();
		//for (auto u : Adj[s])
		en = G[s];

		if (s == 0) { st = 0; } //параметры для того, что бы все рёбра из данной вершины просматривать
		else { st = G[s - 1]; }
		for (int u = st; u < en; u++)
			if (!color[E[u]]) //если ещё не были, то добавляем в очередь и красим как увиденную
			{
				p[E[u]] = s;
				color[E[u]] = true;
				//cout << E[u] + 1 << endl;
				d[E[u]] = d[s] + 1;
				Q.push(E[u]);
			}
	}

	
	fout << d[dest] << "\n"; //нашли дистанцию
	if (p[dest] != -1) //выведем путь
	{
		way(p, dest, start);
		if (d[dest] != 0)
			fout << dest + 1<<' ';
	}
	fout.close();
	return 0;
}