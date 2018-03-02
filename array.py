# # 747. Largest Number At Least Twice of Others
# class Solution:
#     def dominantIndex(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         from copy import deepcopy

#         arry = deepcopy(nums)

#         if len(arry) == 0:
#             return -1
#         elif len(arry) == 1:
#             return 0
#         else:
#             arry.sort()
#             if arry[-1] >= 2*arry[-2]:
#                 return nums.index(arry[-1])
#             else:
#                 return -1

# # 1. Two Sum
# class Solution:
#     def twoSum(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         nummap = {}
#         for index in range(0, len(nums)):
#             num2find = target - nums[index]
#             if num2find in nummap:
#                 return nummap[num2find], index
#             else:
#                 nummap[nums[index]] = index


# # Merge Sorted Array
# class Solution:
#     def merge(self, nums1, m, nums2, n):
#         idx1 = m-1
#         idx2 = n-1
#         idx_glo = m+n-1
#         while idx1 >= 0 and idx2 >= 0:
#             if nums1[idx1] > nums2[idx2]:
#                 nums1[idx_glo] = nums1[idx1]
#                 idx1 -= 1
#                 idx_glo -= 1
#             else:
#                 nums1[idx_glo] = nums2[idx2]
#                 idx2 -= 1
#                 idx_glo -= 1
#         while idx2 >= 0:
#             nums1[idx_glo] = nums2[idx2]
#             idx2 -= 1
#             idx_glo -= 1


# # 746. Min Cost Climbing Stairs

# class Solution:
#     def minCostClimbingStairs(self, cost):
#         """
#         :type cost: List[int]
#         :rtype: int
#         """
#         size = len(cost)
#         dp = [cost[0], cost[1]]
#         for x in range(2, size):
#             dp.append(min(dp[x-1], dp[x-2])+cost[x])
#         return min(dp[-1], dp[-2]) 


# # 724. Find Pivot Index

# class Solution:
#     def pivotIndex(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         from copy import deepcopy
#         if len(nums) <= 2:
#             return -1
#         sum1 = deepcopy(nums)
#         sum2 = deepcopy(nums)
#         for i in range(1, len(nums)):
#             sum1[i] = sum1[i-1] + sum1[i]
#         for i in reversed(range(0, len(nums)-1)):
#             sum2[i] = sum2[i] + sum2[i+1]
#         print(sum1)
#         print(sum2)
#         for i in range(0, len(nums)):
#             if sum1[i] == sum2[i]:
#                 return i

#         return -1


# 717. 1-bit and 2-bit Characters

# class Solution:
#     def isOneBitCharacter(self, bits):
#         """
#         :type bits: List[int]
#         :rtype: bool
#         """
#         arr_len = len(bits)
#         i = 0
#         while i < arr_len-1:
#             i += bits[i] + 1

#         return i == arr_len-1

# 26. Remove Duplicates from Sorted Array

# class Solution:
#     def removeDuplicates(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         if len(nums) == 0:
#             return 0
#         current_index = 0
#         for diff_index in range(1, len(nums)):
#             if nums[current_index] != nums[diff_index]:
#                 current_index += 1
#                 nums[current_index] = nums[diff_index]
#         return current_index + 1


# # 665. Non-decreasing Array

# class Solution:
#     def checkPossibility(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: bool
#         """
#         decrease = False
#         if len(nums) <= 1:
#             return True
#         for i in range(1, len(nums)):
#             if nums[i] < nums[i-1]:
#                 if decrease:
#                     return False
#                 else:
#                     if i-2 >= 0 and nums[i] < nums[i-2]:
#                         nums[i] = nums[i-1]
#                     decrease = True
#         return True


# # 697. Degree of an Array

# class Solution:
#     def findShortestSubArray(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         import sys
#         num_fre = {}
#         sub_start = {}
#         sub_end = {}
#         max_fre = -sys.maxsize
#         for i, num in enumerate(nums):
#             # 如果在的话
#             if num not in sub_start.keys():
#                 num_fre[num] = 0
#                 sub_start[num] = i

#             num_fre[num] += 1
#             sub_end[num] = i
#             max_fre = max(max_fre, num_fre[num])
#         res = sys.maxsize
#         for num, count in num_fre.items():
#             if count == max_fre:
#                 res = min(res, sub_end[num]-sub_start[num]+1)
#         return res


# # 695. Max Area of Island
# class Solution:
#     def maxAreaOfIsland(self, grid):
#         """
#         :type grid: List[List[int]]
#         :rtype: int
#         """
#         maxArea = 0
#         for i in range(0, len(grid)):
#             for j in range(0, len(grid[0])):
#                 if grid[i][j] != 0:
#                     maxArea = max(maxArea, self.areaOfIsland(grid, i, j))
#         return maxArea

#     def areaOfIsland(self, grid, i, j):
#         if i>=0 and i < len(grid) and j>=0 and j< len(grid[0]) and grid[i][j]!=0:
#             grid[i][j] = 0
#             return 1 + self.areaOfIsland(grid, i-1, j) + self.areaOfIsland(grid, i+1, j) + self.areaOfIsland(grid, i, j-1) + self.areaOfIsland(grid, i, j+1)
#         return 0


# # 674. Longest Continuous Increasing Subsequence
# class Solution:
#     def findLengthOfLCIS(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         if len(nums) == 0:
#             return 0

#         res = 1
#         cursor = 1

#         for i in range(0,len(nums)-1):
#             if nums[i] < nums[i+1]:
#                 cursor += 1
#             else:
#                 cursor = 1
#             res = max(res, cursor)

#         return res


# # 661. Image Smoother

# class Solution:
#     def imageSmoother(self, M):
#         """
#         :type M: List[List[int]]
#         :rtype: List[List[int]]
#         """
#         # from copy import deepcopy
#         # res = deepcopy(M)
#         col = len(M[0])
#         row = len(M)
#         # res = [[0]*col]*row
#         res = [None]*row
#         for i in range(0, row):
#             res[i] = [0]*col
#         for i in range(0, row):
#             for j in range(0, col):
#                 count_sum = 0
#                 count = 0
#                 for m in range(-1,2):
#                     for n in range(-1,2):
#                         x = i+m
#                         y = j+n
#                         if 0 <= x < len(M) and 0 <= y < len(M[0]):
#                             # print(x,y)
#                             count_sum += M[x][y]
#                             count += 1
#                 res[i][j] = count_sum//count
#         return res


# 643. Maximum Average Subarray I

# class Solution:
    # def findMaxAverage(self, nums, k):
    #     """
    #     :type nums: List[int]
    #     :type k: int
    #     :rtype: float
    #     """
    #     if k == len(nums):
    #         return sum(nums) / k
    #     window_sum = sum(nums[0:k])
    #     maxAverage = window_sum / k
    #     for i in range(0, len(nums) - k):
    #         window_sum = window_sum + nums[i+k] - nums[i]
    #         average = window_sum / k
    #         maxAverage = max(maxAverage, average)
    #     return maxAverage


# # 628. Maximum Product of Three Numbers

# class Solution(object):
# def maximumProduct(self, nums):
#     """
#     :type nums: List[int]
#     :rtype: int
#     """
#     sorted_num = sorted(nums)
#     sorted_num.reverse()
#     ans1 = sorted_num[0]*sorted_num[1]*sorted_num[2]
#     ans2 = sorted_num[-1]*sorted_num[-2]*sorted_num[0]
#     return max(ans1, ans2)

# # 605. Can Place Flowers
# class Solution:
#     def canPlaceFlowers(self, flowerbed, n):
#         """
#         :type flowerbed: List[int]
#         :type n: int
#         :rtype: bool
#         """
#         count = 0

#         if len(flowerbed) == 1:
#             if flowerbed[0] == 0:
#                 count += 1
#             return count >= n

#         for i in range(0, len(flowerbed)):
#             if i == 0:
#                 if flowerbed[i] == 0 and flowerbed[i+1] == 0:
#                     count += 1
#                     flowerbed[i] = 1
#             elif i == len(flowerbed)-1:
#                 if flowerbed[i] == 0 and flowerbed[i-1] == 0:
#                     count += 1
#                     flowerbed[i] = 1
#             elif flowerbed[i-1] == 0 and flowerbed[i] == 0 and flowerbed[i+1] == 0:
#                 count += 1
#                 flowerbed[i] = 1
#         return count >= n

# # 566. Reshape the Matrix

# class Solution:
#     def matrixReshape(self, nums, r, c):
#         """
#         :type nums: List[List[int]]
#         :type r: int
#         :type c: int
#         :rtype: List[List[int]]
#         """
#         res = [None] * r
#         for i in range(0, r):
#             res[i] = [0] * c
#         original_row = len(nums)
#         original_col = len(nums[0])
#         if r * c != original_col * original_row: return nums
#         order = 0
#         for i in range(0, r):
#             for j in range(0, c):
#                 m = order // original_col
#                 n = order % original_col
#                 res[i][j] = nums[m][n]
#                 order += 1

#         return res

# # 448. Find All Numbers Disappeared in an Array

# class Solution:
#     def findDisappearedNumbers(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[int]
#         """
#         # 取负法，将有的元素所对应的位置的元素取负

#         for i in range(0, len(nums)):
#             index = abs(nums[i]) - 1
#             if nums[index] > 0:
#                 nums[index] = -nums[index]
        
#         res = []
#         for i in range(0, len(nums)):
#             if nums[i] > 0:
#                 res.append(i+1)
                
#         return res

# 283. Move Zeroes

# class Solution:
#     def moveZeroes(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: void Do not return anything, modify nums in-place instead.

#         """

#         # 是非零元素才动
#         j = 0
#         for i in range(0, len(nums)):
#             if nums[i] != 0:
#                 tmp = nums[i]
#                 nums[i] = nums[j]
#                 nums[j] = tmp
#                 j += 1




