# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
# @param {String} s
# @return {Integer}
def length_of_longest_substring(str)
  if str.empty?
    return 0
  end
  map = {}
  curr_start = 0
  max_length = 0
  found_start = 0
  found_end = 0
  i = 0
  begin
    s = str[i]
    if map[s].nil?
      map[s] = 1
      i += 1
    else
      if map.keys.size > max_length
        # new max substring
        found_start = curr_start
        found_end = i
        max_length = map.keys.size
      end
      map.clear
      i = curr_start + 1
      curr_start += 1
    end
  end while i < str.length
  if map.keys.size > max_length
    # new max substring
    found_start = curr_start
    found_end = str.length
    max_length = map.keys.size
  end
  if max_length > 0
    str[found_start..found_end - 1].length
  else
    1
  end
end

puts length_of_longest_substring("abcabcbb")
puts length_of_longest_substring("bbbbb")
puts length_of_longest_substring("pwwkew")
puts length_of_longest_substring("au")
puts length_of_longest_substring("dvdf")
puts length_of_longest_substring("tmmzuxt")
puts length_of_longest_substring("wobgrovw")