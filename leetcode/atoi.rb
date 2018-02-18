# https://leetcode.com/problems/string-to-integer-atoi/description/
# @param {String} str
# @return {Integer}
def my_atoi(str)
  is_positive = nil
  max_int = 2147483647
  min_int = -2147483648
  nums = []
  str.chars.map(&:ord).each do |c|
    if c == 43
      if is_positive.nil?
        is_positive = true
      else
        return 0
      end
    elsif c == 45
      if is_positive.nil?
        is_positive = false
      else
        return 0
      end
    elsif c >= 48 && c <= 57
      nums << c - 48
    else
      if !is_positive.nil? || nums.any? || c != 32
        break
      end
    end
  end
  result = 0
  digits = nums.size - 1
  nums.each_with_index do |n, i|
    pow = digits - i
    result += (n * (10 ** pow))
  end
  if is_positive || is_positive.nil?
    [max_int, result].min
  else
    [min_int, result * -1].max
  end
end

p my_atoi(" b11228552307")