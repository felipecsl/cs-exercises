# https://www.hackerrank.com/challenges/service-lane
input = File.open("input1.txt")
n_t = input.gets.chomp.split(' ')
T = n_t.last.to_i
width = input.gets.chomp.split(' ')
test_cases = []

1.upto(T) do
  i_j = input.gets.chomp.split(' ')
  i = i_j.first.to_i
  j = i_j.last.to_i
  test_cases << [i, j]
end

test_cases.each do |tc|
  puts width[tc.first..tc.last].min
end