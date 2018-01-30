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
