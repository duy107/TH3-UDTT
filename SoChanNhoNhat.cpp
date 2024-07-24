#include<bits/stdc++.h>
using namespace std;
int Min(vector<int> &nums, int l, int r){
	if(l == r){
		return (nums[l] % 2 == 0) ? nums[l] : INT_MAX;
	}
	int m = (l + r) / 2;
	int minLeft = Min(nums, l, m);
	int minRight = Min(nums, m + 1, r);
	return min(minLeft, minRight);
}
int main(){
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int n = nums.size();
	cout << Min(nums, 0, n - 1);
}