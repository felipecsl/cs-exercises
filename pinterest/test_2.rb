#-----------------------------------------------------------------
# input: ["cat", "act", "bat", "alligator", "tac", "tab", "dog"]
# output: [["cat", "act", "tac"], ["bat", "tab"], ["dog"], ["alligator"]]

def anagram(words)
  words_hash = {}

  words.each do |w1|
      sorted_word = w1.chars.sort

      if words_hash.has_key?(sorted_word)
          words_hash[sorted_word] << w1
      else
          words_hash[sorted_word] = [w1]
      end
  end

  words_hash.values
end
