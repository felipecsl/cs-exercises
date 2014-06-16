# Devise a function that gets one parameter 'w' and returns all the anagrams for 'w' from the file
# wl.txt.

# "Anagram": An anagram is a type of word play, the result of rearranging the letters of a word or
# phrase to produce a new word or phrase, using all the original letters exactly once; for example
# orchestra can be rearranged into carthorse.

# anagrams("horse") should return:
# ['heros', 'horse', 'shore']
#
#

def anagram(w)
  inputlenght = w.length
  chars = w.chars
  unique_chars = chars.uniq.sort
  lines = IO.readlines('wordlist.txt')
  ret = []

  lines.each do |l|
    word = l.strip
    if word.length == inputlenght
      ret << word if word.chars.uniq.sort == unique_chars
    end
  end

  ret
end

anagram("horse")
