# http://www.careercup.com/question?id=18824667
# You are given an array of 1's 2's and 3's.
# Sort this list so the 1's are first, the 2's come second, and the 3's come third.

# Ex: Input [1, 3, 3, 2, 1]
# Output [1, 1, 2, 3, 3]

# But there is a catch!! The algorithm must be one pass, which means no merge/quick sort.
# Also no extra list allocations are allowed, which means no bucket/radix/counting sorts.

# You are only permitted to swap elements.

module Enumerable
  def sorted?
    each_cons(2).all? { |a, b| (a <=> b) <= 0 }
  end
end

def swap(arry, a, b)
  # puts "#{a} #{b}"
  temp = arry[a]
  arry[a] = arry[b]
  arry[b] = temp
  # p arry
end

arr = 1.upto(50).map { (rand() * 3).to_i + 1 }

puts 'Before: ' + arr.to_s

i = 0
start_index = 0
end_index = arr.length - 1

while i <= end_index
  if arr[i] < 2
    swap(arr, start_index, i)
    start_index += 1
    i +=1
  elsif arr[i] > 2
    swap(arr, end_index, i)
    end_index -= 1
  else
    i += 1
  end
end

puts 'After: ' + arr.to_s
puts "Sorted? " + arr.sorted?.to_s