#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> d = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1,-2}, {1, -2}, {2, -1}};
bool check(int i, int j, int n, vector<vector<bool>> &visited){
	return i >= 0 && i < n && j >=0 && j < n && !visited[i][j];
}
void dfs(int i, int j, int n, vector<vector<int>> &res, int k, vector<vector<bool>> &visited){
	res[i][j] = k;
	visited[i][j] = true;
	if(k == pow(n, 2)){
		for(int i = 0; i < n; i++){
			for(int j = 0;  j < n; j++){
				cout << res[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "==============" << endl;
	}
	for(auto it : d){
		int dx = i + it.first;
		int dy = j + it.second;
		if(check(dx, dy, n, visited)){ 
			dfs(dx, dy, n, res, k + 1, visited);
			visited[dx][dy] = false;
		}
	}
}
int main(){
	int n;
	cin >> n;
	vector<vector<int>> res(n, vector<int>(n, 0));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	dfs(0, 0, n, res, 1, visited);
}