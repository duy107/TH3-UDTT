#include<bits/stdc++.h>
using namespace std;
void merge(vector<float> &nums, int l, int m, int r){
	vector<float> a (nums.begin() + l, nums.begin() + m + 1);
	vector<float> b (nums.begin() + m + 1, nums.begin() + r + 1);
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()){
		if(a[i] <= b[j]){
			nums[l] = a[i];
			i++;
		}else{
			nums[l] = b[j];
			j++;
		}
		l++;
	}
	while(i < a.size()){
		nums[l] = a[i];
		i++;
		l++;
	}
	while(j < b.size()){
		nums[l] = b[j];
		j++; 
		l++;
	}
}
void mergeSort(vector<float> &nums, int l, int r){
	if(l >= r){
		return;
	}
	int m = (l + r) / 2;
	mergeSort(nums, l, m);
	mergeSort(nums, m + 1, r);
	merge(nums, l, m, r);
}
int main(){
	vector<float> nums = {3.4, 2.2, 1.4, 6.8, 3.2, 9.9, 1.0, 0.9, 0.3, 0.10};
	int n = nums.size();
	mergeSort(nums, 0, n - 1);
	for(float t : nums){
		cout << t << ' ';
	}
}