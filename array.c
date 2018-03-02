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

// // 665. Non-decreasing Array

// class Solution {
// public:
//     bool checkPossibility(vector<int>& nums) {
//         int len = (int)nums.size();
//         bool decrease = false;
//         if(len<=1) return true;
//         for(int i=1;i<len;i++){
//             if(nums[i]<nums[i-1]){
//                 if(decrease){
//                     return false;
//                 }
//                 else{
//                     if(i-2>=0 && nums[i]<nums[i-2]){
//                         nums[i]=nums[i-1];
//                     }
//                     decrease = true;
//                 }
//             }
//         }
//         return true;
//     }
// };

// // 766. Toeplitz Matrix

// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int row = (int)matrix.size();
//         int col = (int)matrix[0].size();
// //        行扫描
//         for(int i=0;i<col;i++){
//             int this_element = matrix[0][i];
//             for(int m=0,n=i;m<row && n<col; m++,n++){
//                 if(matrix[m][n] != this_element){
//                     return false;
//                 }
//             }
//         }
// // 列扫描        
//         for(int j=0;j<row;j++){
//             int this_element = matrix[j][0];
//             for(int m=j,n=0;m<row && n<col; m++,n++){
//                 if(matrix[m][n] != this_element){
//                     return false;
//                 }
//             }
//         }
        
//         return true;
//     }
// };


// 主要是看的哈希值


// // 697. Degree of an Array


// class Solution {
// public:
    
// //     int max(int a,int b){
// //         return a>b ? a:b;
// //     }
    
// //     int min(int a,int b){
// //         return a<b ? a:b;
// //     }
    
//     int findShortestSubArray(vector<int>& nums) {
//         unordered_map<int, int>num_fre;
//         unordered_map<int, int>start_index;
//         unordered_map<int, int>end_index;
//         unordered_map<int, int >::iterator iter;
//         int max_fre = INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             int num = nums[i];
//             if (start_index.find(num)==start_index.end()){
//                 num_fre[num]=0;
//                 start_index[num]=i;
//             }
//             num_fre[num] += 1;
//             end_index[num]=i;
//             max_fre = max(max_fre,num_fre[num]);
//         }
        
//         int res = INT_MAX;
        
//         for(iter = num_fre.begin();iter!=num_fre.end();iter++){
//             if(iter->second == max_fre){
//                 res = min(res,end_index[iter->first] - start_index[iter->first]+1);
//             }
//         }
//         return res;
//     }
// };


// 674. Longest Continuous Increasing Subsequence

// class Solution {
// public:
//     int findLengthOfLCIS(vector<int>& nums) {
//         if(nums.size()==0) return 0;
//         int res=1;
//         int current_LCIS = 1;
//         for(int i=0;i<nums.size()-1;i++){
//             if (nums[i+1]>nums[i]) {
//                 current_LCIS+=1;
//             }
//             else{
//                 current_LCIS = 1;
//             }
//             res = max(current_LCIS,res);
//         }
//         return res;
//     }
// };


// // 661. Image Smoother

// class Solution {
// public:
    
//     vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
//         vector<vector<int>> res;
// // vector<vector<int>> res(row ,vector<int>(col));
//         res.assign(M.begin(), M.end());
//         int row = (int)M.size();
//         int col = (int)M[0].size();
//         for(int i =0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 int sum = 0;
//                 int count = 0;
//                 for(int m=-1;m<=1;m++){
//                     for(int n=-1;n<=1;n++){
//                         int x_axis = m+i;
//                         int y_axis = n+j;
//                         if(x_axis>=0 && x_axis<row && y_axis>=0 && y_axis<col){
//                             sum+=M[x_axis][y_axis];
//                             count+=1;
//                         }
//                     }
//                 }
//                 res[i][j] = sum/count;
//             }
//         }
//         return res;
//     }
// };


// // 643. Maximum Average Subarray I

// class Solution {
// public:
    
//     double max(double a, double b){
//         return a>b?a:b;
//     }
//     double findMaxAverage(vector<int>& nums, int k) {
//         int window_sum = 0;
//         for(int i=0;i<k;i++){
//             window_sum+=nums[i];
//         }
//         double maxAverage = window_sum/(k*1.0);
//         for(int i=0;i<nums.size()-k;i++){
//             window_sum = window_sum + nums[i+k] - nums[i];
//             double average = window_sum/(k*1.0);
//             maxAverage = max(maxAverage,average);
//         }
//         return maxAverage;
//     }
// };

// // 628. Maximum Product of Three Numbers

// class Solution {
// public:
//     static bool cmp(int a,int b){
//         return a>b;
//     }
    
//     int maximumProduct(vector<int>& nums) {
//         sort(nums.begin(), nums.end(),cmp);
//         int ans1 = nums[0]*nums[1]*nums[2];
//         int ans2 = nums[nums.size()-1]*nums[nums.size()-2]*nums[0];
//         return max(ans1, ans2);
//     }
// };

// // 605. Can Place Flowers
// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         int count=0;
//         for(int i=0;i<flowerbed.size();i++){
//             if(i==0){
//                 if(flowerbed[i]==0 && flowerbed[i+1]==0) {
//                     count++;
//                     flowerbed[i]=1;
//                 }
//             }
//             else if (i==flowerbed.size()-1){
//                 if(flowerbed[i]==0 && flowerbed[i-1]==0){
//                     count++;
//                     flowerbed[i]=1;
//                 }
//             }
//             else if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){ flowerbed[i]=1;
//                 count++;
//             }
//         }
//         printf("%d",count);
//         return count>=n;
//     }
// };


// // 566. Reshape the Matrix

// class Solution {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
//         int original_row = (int)nums.size();
//         int original_col = (int)nums[0].size();
//         if(r*c != original_col*original_row) return nums;
//         vector<vector<int>>res(r,(vector<int>(c)));
//         int order =0;
//         for(int i=0;i<r;i++){
//             for(int j=0;j<c;j++){
//                 int m = order/original_col;
//                 int n = order%original_col;
//                 // printf("%d,%d,%d\n",order,m,n);
//                 res[i][j]=nums[m][n];
//                 order++;
//             }
//         }
//         return res;
//     }
// };

// // 561. Array Partition I

// class Solution {
// public:
//     int arrayPairSum(vector<int>& nums) {
//         int sum = 0;
//         sort(nums.begin(), nums.end());
//         for(int i=0;i<nums.size();i+=2){
//             sum += nums[i];
//         }
//         return sum;
//     }
// };

// // 485. Max Consecutive Ones
// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int max_consecutive = 0;
//         int cur_consecutive = 0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==1){
//                 cur_consecutive+=1;
//                 max_consecutive = max(max_consecutive,cur_consecutive);
//             }
//             else{
//                 cur_consecutive = 0;
//             }
//         }
//         return max_consecutive;
//     }
// };

// // 448. Find All Numbers Disappeared in an Array

// class Solution {
// public:
    
//     void swap(int *a, int *b){
//         int temp = *a;
//         *a = *b;
//         *b = temp;
//     }
    
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++){
// //        使每个位置的元素都在自己的位置上，直到该元素的位置上就是该元素
//             while (nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]) {
//                 swap(&nums[i], &nums[nums[i]-1]);
//             }
//         }
//         vector<int> res;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=i+1){
//                 res.push_back(i+1);
//             }
//         }
//         return res;
//     }
// };

// // # 283. Move Zeroes

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int current_pos = 0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=0){
//                 nums[current_pos++]=nums[i];
//             }
//         }
//         for(int i=current_pos;i<nums.size();i++){
//             nums[i]=0;
//         }
//     }
// };

// // # 217. Contains Duplicate
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int numsSize = (int)nums.size();
//         if(numsSize<=1){
//             return false;
//         }
//         unordered_map<int, int>map;
//         for(int i=0;i<numsSize;i++){
//             if(map.find(nums[i])!=map.end()){
//                 return true;
//             }
//             else{
//                 map[nums[i]]=1;
//             }
//         }
//         return false;
//     }
// };

// // 268. Missing Number
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         bool exist_max = false;
//         for(int i=0;i<nums.size();i++){
//             if(abs(nums[i])==nums.size()) exist_max=true;
//             int index = abs(nums[i]);
//             nums[index] = -nums[index];
//         }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>0){
//                 return i;
//             }
//         }
//         if(exist_max){
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i]>=0){
//                     return i;
//                 }
//             }
//         }
//         return (int)nums.size();
//     }
// };

// // 169. Majority Element

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int>map;
//         for(int i=0;i<nums.size();i++){
//             if(map.find(nums[i])!=map.end()){
//                 map[nums[i]]+=1;
//             }
//             else{
//                 map[nums[i]]=1;
//             }
//         }
//         unordered_map<int, int>::iterator iter;
//         for(iter=map.begin();iter!=map.end();iter++){
//             if(iter->second>nums.size()/2){
//                 return iter->first;
//             }
//         }
//         return 0;
//     }
// };

// // 167. Two Sum II - Input array is sorted

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         unordered_map<int, int>hash;
//         vector<int>res;
//         for(int i=0;i<numbers.size();i++){
//             int num2find = target-numbers[i];
//             if(hash.find(num2find)!=hash.end()){
//                 res.push_back(hash[num2find]+1);
//                 res.push_back(i+1);
//             }
//             else{
//                 hash[numbers[i]]=i;
//             }
//         }
//         return res;
//     }
// };

// // 122. Best Time to Buy and Sell Stock II

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.size()<=1) return 0;
//         int max_profit=0;
//         for(int i=0;i<prices.size()-1;i++){
//             if(prices[i+1]>prices[i]){
//                 max_profit += prices[i+1]-prices[i];
//             }
//         }
//         return max_profit;
//     }
// };
