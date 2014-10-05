# https://www.hackerrank.com/challenges/two-arrays
# You are given two integer arrays, A and B, each containing N integers. The size of the array is less than or equal to 1000. You are free to permute the order of the elements in the arrays.

# Now here's the real question - is there an arrangement of the arrays, such that, Ai+Bi ≥ K for all i, where Ai denotes the ith element in the array A.

# INPUT Format
# The first line contains an integer, T, the number of test-cases. T test cases follow. Each test case has the following format:

# The first line contains two integers, N and K. The second line contains N space separated integers, denoting A array. The third line describes B array in a same format.

# Output Format
# For each test case, if such an arrangement exists output "YES", otherwise "NO" (without quotes).


# Constraints
# 1 <= T <= 10
# 1 <= N <= 1000
# 1 <= K <= 109
# 0 <= Ai, Bi ≤ 109

INPUT = File.open("INPUT1.txt")

def read_array
  INPUT.gets.chomp.split(' ')
end

def read_int_array
  INPUT.gets.chomp.split(' ').map(&:to_i)
end

def read_int
  INPUT.gets.chomp.to_i
end

T = read_int
test_cases = []

1.upto(T) do
  n_k = read_int_array
  k = n_k.last
  a = read_int_array
  b = read_int_array
  test_cases << { a: a, b: b, k: k}
end

test_cases.each do |tc|
  a = tc[:a].sort
  b = tc[:b].sort.reverse
  k = tc[:k]

  result = true
  a.each_with_index do |x, i|
    if a[i] + b[i] < k
      result = false
      break
    end
  end

  puts(result ?  "YES" : "NO")
end