# Description: Given an input string, update the string so that a letter 't' is never followed by a letter 'h'. To do this, whenever 'h' is following a 't' we have to invert the order and make sure that the 't' is after the 'h'.

# Desired complexity: Provide a solution that only performs a single pass of the input string. However, please submit your work even if it traverses the input string more than once.

# Examples:
# Input Output
#  theater   hteater
#  the author of the book  hte auhtor of hte book
#  ttth  httt
#

def characterReverse(input)
  length = input.length

  (length - 1).downto(1) do |i|
    if input[i] == "h" && input[i - 1] == "t"
      input[i] = "t"
      input[i - 1] = "h"

      i.upto(length - 1) do |j|
        if input[j] == 't' && input[j + 1] == 'h'
          input[j] = 'h'
          input[j + 1] = 't'
        end
      end
    end
  end

  input
end

# characterReverse("theater") == "hteater" ? "PASSED" : "---FAILED---"
# characterReverse("the author of the book") == "hte auhtor of hte book" ? "PASSED" : "---FAILED---"
# characterReverse("ttth") == "httt" ? "PASSED" : "---FAILED---"
# characterReverse("thththththth") == "hhhhhhtttttt" ? "PASSED" : "---FAILED---"
