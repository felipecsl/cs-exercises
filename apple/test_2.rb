# Given an array of integers, return an equal-length array
# such that the value of the output array at index 'i' is
# the product of all values in the input array EXCEPT the
# value at index 'i'

# E.g.
# > print multiply_except_self([5,2,2,3])
# [12, 30, 30, 20]
# [12, 0, -30, 20]
# - [0, 12 * 30 * 20, 0, 0]
#> [(12 * -30 * 20) / 12, ]

def find_solution(arr)
  arr.each_with_index do |e, i|
    rest = arr[0..i - 1] + arr[i + 1..-1]
    prod = rest.reduce(:*)
    arr[i] = prod
  end

  arr
end

def find_faster(arr)
  return [] if arr.empty?

  prod = arr[0]
  zeroes = {}

  arr.each_with_index do |e, i|
    next if i == 0

    unless e == 0
      prod = prod * e
    else
      zeroes[i] = true
    end
  end

  arr.each_with_index do |e, i|
    if e != 0
      if zeroes.keys.empty?
        arr[i] = prod / e
      else
        arr[i] = 0
      end
    else
      arr[i] = prod
    end
  end

  arr
end

# Interviewer's solution
def find_faster_nicky(arr)
  return [] if arr.empty?

  prod = 1
  there_is_zero = false

  arr.each_with_index do |e, i|
    unless e == 0
      prod = prod * e
    else
      there_is_zero = true
    end
  end

  arr.each_with_index do |e, i|
    if e == 0 && there_is_zero
      arr[i] = prod
    elsif there_is_zero
      arr[i] = 0
    else
      arr[i] = prod / e
    end
  end

  arr
end

puts find_faster [12, 0, -30, 20]
