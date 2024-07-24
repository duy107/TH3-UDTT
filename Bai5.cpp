#include<bits/stdc++.h>
using namespace std;
float sum(vector<float> &nums, int l, int r){
	if(l == r){
		return (nums[l] > 0) ? nums[l] : 0;
	}
	int m = (l + r) / 2;
	float sumLeft = sum(nums, l, m);
	float sumRight = sum(nums, m + 1, r);
	return sumLeft + sumRight;
}
int main(){
	vector<float> nums = {-1.1, 2.2, -3.3, -4.4, -5.5, 6.6, 7.7, -8.8, -9.9, -10.1, 11.1, 12.2, 13.3, -14.4, -15, -16, 17, -18, -19, 20};
	int n = nums.size();
	cout << sum(nums, 0, n - 1);
}  