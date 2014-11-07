# K Difference
# <p>Given <strong>N</strong> numbers ,<em><strong> [N&lt;=10^5] </strong></em>we need to count the total pairs of numbers&nbsp;
# which have a difference of K.<strong> [K&gt;0 and K&lt;10^9]</strong>. The solution should have as low of a computational time complexity as possible.&nbsp;</p>

input = STDIN.gets.chomp.split(' ').map(&:to_i)
N = input.first
K = input.last
numbers = STDIN.gets.chomp.split(' ').map(&:to_i)

hash = {}
total = 0

numbers.each do |n|
  if hash.has_key?(n)
    total += hash[n].length
  end
  if !hash.has_key?(n + K)
    hash[n + K] = [n]
  else
    hash[n + K] << n
  end
  if !hash.has_key?(n - K)
    hash[n - K] = [n]
  else
    hash[n - K] << n
  end
end

puts total
