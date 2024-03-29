// Baekjoon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 100

static int map[MAX_N][MAX_N];
static int N, M;


typedef struct _POS
{
	int x, y;
}POS;

static queue<POS> q;



static int checkRange(int x, int y)
{
	if (x < 0 || x > N || y < 0 || y > M)
		return 0;
	return 1;
}

static int dy[4] = { 0,0,1,-1 };
static int dx[4] = { 1, -1, 0, 0 };

void Maze()
{
	POS pos;
	cin >> N >> M;
	for (int w = 0; w < N; w++)
	{
		for (int h = 0; h < M; h++)
		{
			cin >> map[w][h];
		
		}
	}

	q.push()
	while (!q.empty())
	{
		pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = pos.y + dy[i];
			int nx = pos.x + dx[i];

			POS temp_pos;
			if (checkRange(ny, nx) && map[ny][nx] == 0)
			{
				map[ny][nx] = map[pos.y][pos.x] + 1;
				temp_pos.y = ny;
				temp_pos.x = nx;
				q.push(temp_pos);
				gRemainCount--;
			}
		}
	}

	if (checkWell())
	{
		cout << gmax - 1 << endl;
		return;
	}
	else
		cout << "-1" << endl;
}

int main()
{
	tomato();
}
