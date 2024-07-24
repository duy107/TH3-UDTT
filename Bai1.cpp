#include<bits/stdc++.h>
using namespace std;
struct SinhVien{
	char ho;
	char ten;
	int namSinh;
};
void merge(vector<SinhVien> &sv, int l, int m, int r){
	vector<SinhVien> a (sv.begin() + l, sv.begin() + m + 1);
	vector<SinhVien> b (sv.begin() + m + 1, sv.begin() + r + 1);
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()){
		if(a[i].ten <= b[j].ten){
			sv[l] = a[i];
			i++;
		}else{
			sv[l] = b[j];
			j++;
		}
		l++;
	}
	while(i < a.size()){
		sv[l] = a[i];
		i++;
		l++;
	}
	while(j < b.size()){
		sv[l] = b[j];
		j++; 
		l++;
	}
}
void mergeSort(vector<SinhVien> &sv, int l, int r){
	if(l >= r){
		return;
	}
	int m = (l + r) / 2;
	mergeSort(sv, l, m);
	mergeSort(sv, m + 1, r);
	merge(sv, l, m, r);
}
void print(SinhVien sv){
	cout << sv.ho << ' ' << sv.ten << ' ' << sv.namSinh << endl;
}
int binarySearch(char name, vector<SinhVien> &sv, int l, int r){
	if(l <= r){
		int m = (l + r) / 2;
		if(strcmp(sv[m].ten, name) == 0){
			return m;
		}else if(sv[m].ten > name){
			return binarySearch(name, sv, l, m - 1);
		}else{
			return binarySearch(name, sv, m + 1, r);
		}
	}
	return -1;
}
int main(){
	vector<SinhVien> sv(6);
	sv[0] = {'T', 'D', 2004};
	sv[1] = {'K', 'H', 2009};
	sv[2] = {'S', 'S', 2002};
	sv[3] = {'E', 'L', 2000};
	sv[4] = {'T', 'A', 2007};
	sv[5] = {'T', 'D', 2001};
	mergeSort(sv, 0, 5);
	for(int i = 0; i < 6; i++){
		print(sv[i]);
	}
//	cout << binarySearch('W', sv, 0, 5);
}