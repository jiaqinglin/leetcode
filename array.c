// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//     	unordered_map<int,int>hash;
//     	vector<int> result;
//     	for(int i=0;i<nums.size();i++){
//     		int numToFind=target-nums[i];
//     		if(hash.find(numToFind)!=hash.end()){
//     			result.push_back(hash[numToFind]);
//     			result.push_back(i);
//     			return result;
//     		}
//     		 hash[nums[i]]=i;
//     	}
//        return result;
//     }
// };

#include <algorithm>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int num_len = num.size();
        int index=0,first=0,second=0;
        for(int i=0;i<num_len;i++){
            if(nums[i]>first){
                second = first;
                first=nums[i];
                second
            }
        }
    }
};