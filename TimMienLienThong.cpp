#include<bits/stdc++.h>
using namespace std;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
bool check(int i, int j, vector<vector<int>> &matrix){
	return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && matrix[i][j] == 1;
}
void dfs(int i, int j, vector<vector<int>> &matrix){
	matrix[i][j] = 2;
	for(int k = 0; k < 4; k++){
		int dx = i + x[k];
		int dy = j + y[k];
		if(check(dx, dy, matrix)){
			dfs(dx, dy, matrix);
		}
	}	
}
int main(){
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	vector<vector<int>> matrix(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 1){
				cnt++;
				dfs(i, j, matrix);
			}
		}
	}
	cout << cnt << endl;
}