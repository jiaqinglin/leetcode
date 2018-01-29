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
};           


