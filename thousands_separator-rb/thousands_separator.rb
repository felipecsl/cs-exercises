# Given a number n, return a string with the same number
# separated by commas on the thousands.
# For example:
#
# 35235235 => 35,235,235
# 2923 => 2,923
# 54 => 54

def convert(n)
  ret = []
  chars = n.to_s.chars.reverse
  tmp = ""

  chars.each_with_index do |c, i|
    tmp = tmp + c
    if (i+1) % 3 == 0
      ret << tmp.reverse
      tmp = ""
    end
  end

  ret << tmp.reverse unless tmp.empty?

  ret.reverse.join(",")
end

convert 35235235
