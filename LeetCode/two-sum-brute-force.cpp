#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int length = nums.size();
        for (int i=0; i<length-1; i++){
            for( int j=i+1; j<length; j++){
                if(nums[i]+nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    goto label;
                }
            }
        }
        label: return res;
    }
};

int main(){
    Solution solution;
    vector<int> result;

    vector<int> nums{2,7,11,15};
    int target = 9;
    
    result = solution.twoSum(nums, target);

    for(auto i: result){
        cout << i << ", " << endl;
    }
    return 0;
}
