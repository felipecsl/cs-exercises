# problem 2:
# I will give you a list of integers, please give me a sub-list such that the sum is the max possible.

# [1, -3, 4, -1, 5]

# The sub list here is 4, -1, 5 = 8, you can just give me the sum.

def max_sublist(list)
  current_max = 0
  overall_max = 0

  list.each do |n|
    current_max = [current_max + n, 0].max
    overall_max = [current_max, overall_max].max
  end

  overall_max
end

puts max_sublist [1, -3, 4, -1, 5]
