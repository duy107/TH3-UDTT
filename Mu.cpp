#include<bits/stdc++.h>
using namespace std;
int binhPhuong(int n, int k){
	if(k == 1) return n;
	int tmp = pow(n, k / 2);
	if(n % 2 == 0){
		return tmp * tmp;
	}else{
		return tmp * tmp * n;
	}
}
int main(){
	int n = 5, k = 3;
	cout << binhPhuong(n, k);
}