// // 747. Largest Number At Least Twice of Others

// class Solution {
// public:
//     int dominantIndex(vector<int>& nums) {
//         int first = 0,second = 0;
//         int index = 0;
//         int arr_len = nums.size();
        
//         for(int i=0;i<arr_len;i++){
//             if(nums[i]>first){
//                 second = first;
//                 first = nums[i];
//                 index = i;
//             }
//             else if(nums[i]>second){
//                 second = nums[i];
//             }
//         }
        
//         if(first>=2*second){
//             return index;
//         }
//         else{
//             return -1;
//         }
//     }
// };

// // 1. Two Sum
// // 返回target
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//         vector<int> result;
//         vector<int> array;
//         array.assign(nums.begin(), nums.end());
//         sort(array.begin(),array.end());
//         int current_left = 0;
//         int current_right = (int)nums.size()-1;
//         while (current_left<current_right) {
//             if(array[current_left]+array[current_right]==target){
// //                int index_1 = (int)(find(nums.begin(), nums.end(), array[current_left]) - nums.begin());
// //                int index_2 = (int)(find(nums.begin(), nums.end(), array[current_right]) - nums.begin());
//                 result.push_back(array[current_left]);
//                 result.push_back(array[current_right]);
//                 break;
//             }
//             else if(array[current_left]+array[current_right]<target){
//                 current_left++;
//             }
//             else{
//                 current_right--;
//             }
//         }
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int>map;
//         vector<int> res;
//         for(int i=0;i<nums.size();i++){
//             int num2find = target - nums[i];
//             if(map.find(num2find)!=map.end()){
//                 res.push_back(map[num2find]);
//                 res.push_back(i);
//             }
//             map[nums[i]] = i;
//         }
//         return res;
//     }
// };



// // Merge Sorted Array
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         if(n==0){
//             return;
//         }
//         if(m==0){
//             nums1.assign(nums2.begin(), nums2.end());
//         }
//         int idx1=m-1,idx2=n-1,idx_glo=m+n-1;
//         while (idx1>=0 && idx2>=0) {
//             if(nums1[idx1]>nums2[idx2]){
//                 nums1[idx_glo--]=nums1[idx1--];
//             }
//             else{
//                 nums1[idx_glo--]=nums2[idx2--];
//             }
//         }
//         while (idx2>=0) {
//             nums1[idx_glo--]=nums2[idx2--];
//         }
//     }
// };   

//  746. Min Cost Climbing Stairs

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int dp[cost.size()];
//         dp[0]=cost[0];
//         dp[1]=cost[1];
//         for(int i=2;i<cost.size();i++){
//             dp[i]=min(dp[i-1], dp[i-2])+cost[i];
//         }
//         return min(dp[cost.size()-2], dp[cost.size()-1]);
//     }
// private:
//     int min(int a, int b){
//         return a>b ? b:a;
//     }
// };


// // 724. Find Pivot Index
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         if(nums.size()<=2){
//             return -1;
//         }
//         int sum1[nums.size()];
//         sum1[0] = nums[0];
//         for(int i=1;i<nums.size();i++){
//             sum1[i]=sum1[i-1]+nums[i];
//         }
//         int left_sum = 0;
//         for(int i=0;i<nums.size();i++){
//             if(sum1[i]==sum1[nums.size()-1]-left_sum){
//                 return i;
//             }
//             else{
//                 left_sum = sum1[i];
//             }
//             printf("%d ",left_sum);
            
//         }
//         return -1;
//     }
// };

// // 717. 1-bit and 2-bit Characters
// class Solution {
// public:
//     bool isOneBitCharacter(vector<int>& bits) {
//         int n = (int)bits.size();
//         int i = 0;
//         while (i<n-1) {
//             if(bits[i]==0){
//                 i++;
//             }
//             else{
//                 i+=2;
//             }
//         }
//         return i==n-1;
//     }
// };

// // 26. Remove Duplicates from Sorted Array

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if(nums.size()==0){
//             return 0;
//         }
//         int current_index=0;
//         int dif_index = 1;
//         for(;dif_index<nums.size();dif_index++){
//             if(nums[dif_index]!=nums[current_index]){
//                 nums[++current_index] = nums[dif_index];
//             }
//         }
//         return current_index+1;
//     }
// };


