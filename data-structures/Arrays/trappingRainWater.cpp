#include<bits/stdc++.h>

using namespace std;

int trap(vector<int> heights){
	int left = 0;
	int right = heights.size()-1;
	int leftMax = heights[left];
	int rightMax = heights[right];

	int water = 0;
	
	while(left < right){
		if(leftMax < rightMax){
			leftMax = max(leftMax, heights[left]);
			water += leftMax - heights[left];
			left++;
		}else{
			rightMax = max(rightMax, heights[right]);
			water += rightMax - heights[right];
			right--;
		}
	}
	return water;
}

int main(){
	vector<int> heights = {1,0,1,0,2,1,0,1,3,2,1,2,1};
	int ans = trap(heights);
	cout << ans << "\n";
	return 0;
}