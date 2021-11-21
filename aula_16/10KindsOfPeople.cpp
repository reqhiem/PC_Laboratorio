
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;

vvi offsets = {{-1,0},{0,1},{1,0},{0,-1}};

void dfs(int i, int j, vs &grid, vvb &visited, vvi &grid2, int rows, int cols, char fc, int fn){
	visited[i][j] = true;
	grid2[i][j] = fn;
	int xx, yy;
	for (int k = 0; k < 4; k++){
		switch (k) {
            case 0:
                xx = i - 1; yy = j;
                break; break;
            case 1:
                xx = i; yy = j + 1;
                break;
            case 2:
                xx = i + 1; yy = j;
                break; break;
            case 3:
                xx = i; yy = j - 1;
                break;
		};

		if (xx >= 0 && xx < rows && yy >= 0 && yy < cols && !visited[xx][yy] && grid[xx][yy] == fc){
			dfs(xx, yy, grid, visited, grid2, rows,  cols, fc, fn);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j, k;

	int rows, cols;
	int numQueries;
	int cont = 0;
	int r1, r2, c1, c2;
	cin >> rows >> cols;
	vvi grid2(rows);
	vs grid(rows);
	vvb visited(rows);
	for (i = 0; i < rows; i++){
		cin >> grid[i];
		grid2[i].resize(cols);
		visited[i].resize(cols, false);
	}
	
	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++){
			if (!visited[i][j]){
				dfs(i, j, grid, visited, grid2, rows, cols, grid[i][j], cont);
				cont++;
			}
		}
	}

	cin >> numQueries;
	for (i = 0; i < numQueries; i++){
		cin >> r1 >> c1 >> r2 >> c2;

		r1--; r2--; c1--; c2--;
		if (grid2[r1][c1] == grid2[r2][c2]){
			if (grid[r1][c1] == '0'){
				cout << "binary\n";
			}
			else{
				cout << "decimal\n";
			}
		}
		else{
			cout << "neither\n";
		}
	}
	return 0;
}