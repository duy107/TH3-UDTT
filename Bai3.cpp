#include<bits/stdc++.h>
using namespace std;
int Max(vector<int> &nums, int l, int r){
	if(l == r){
		return nums[l];
	}
	int m = (l + r) / 2;
	int maxLeft = Max(nums, l, m);
	int maxRight = Max(nums, m + 1, r);
	return max(maxLeft, maxRight);
}
int main(){
	vector<int> nums = {1, 2, 5, 9, 2, 4, 7};
	cout << Max(nums, 0, nums.size() - 1);
}