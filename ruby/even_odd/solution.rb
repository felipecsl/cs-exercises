f = STDIN
total_items = f.gets.chomp
A = f.gets.chomp.split(' ').map(&:to_i)
total_pairs = f.gets.chomp.to_i
pairs = []

total_pairs.times do
  itms = f.gets.chomp.split(' ').map(&:to_i)
  pairs << {x: itms.first, y: itms.last }
end

def find(x, y)
  return A[x - 1] if x == y
  return 1 if A[x] == 0
  A[x - 1]
end

pairs.each do |p|
  puts((find(p[:x], p[:y]) % 2 == 0 ? "Even" : "Odd"))
end