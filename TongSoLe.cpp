#include<bits/stdc++.h>
using namespace std;
int sum(vector<int> nums, int index){
	if(index == nums.size()) return 0;
	if(nums[index] % 2 != 0){
		return nums[index] + sum(nums, index + 1);
	}
	return sum(nums, index + 1);
}
int main(){
	vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << sum(nums, 0);
}