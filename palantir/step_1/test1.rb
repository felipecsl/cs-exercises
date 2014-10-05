# Description: Given an input string, find and return the first unique character in that string.

# Desired complexity: Provide a solution with complexity O(n). However, please submit your work even if the complexity of your approach is higher than O(n).

# Examples
# Input Output
# AAABCDDLHBH - C
# BANANAS ARE BLUE  - S

def firstNonRepeatingCharacter(input)
  result = {}
  arr = []

  input.chars.each do |c|
    if result[c]
      result[c] += 1
    else
      result[c] = 1
    end
  end

  result.keys.detect { |k| result[k] == 1 }
end