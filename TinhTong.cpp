#include<bits/stdc++.h>
using namespace std;
int sum(string n){
	if (n.length() == 1) return stoi(n);
	int tmp = (n[n.length() - 1] - '0');
	n.pop_back();
	return tmp + sum(n);
}
int main(){
	string n;
	cin >> n;
	cout << sum(n);
}