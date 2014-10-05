# problem 1:
# Give me the intersection between 2 integer lists

a = -10.upto(10).to_a.shuffle.take(6)
b = -10.upto(10).to_a.shuffle.take(6)
res = {}

a.each do |n|
  res[n] = 1 unless res[n]
end

b.each do |n|
  res[n] = 2 if res[n] == 1
end

res.select { |k, v| v == 2 }.keys