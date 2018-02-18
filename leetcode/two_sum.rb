# https://leetcode.com/problems/two-sum/description/
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  0.upto(nums.size - 1) do |i|
    (i + 1).upto(nums.size - 1) do |j|
      if nums[j] + nums[i] == target
        return [i, j]
      end
    end
  end
end

p two_sum([2, 7, 11, 15], 9)
p two_sum([3, 2, 4], 6)
p two_sum([-1,-2,-3,-4,-5], -8)
p two_sum([-3,4,3,90], 0)