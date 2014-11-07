def permutations_v1(str)
  return '' if str.length == 0
  return [str] if str.length == 1

  last_char = str.chars.last
  perms = permutations_v1 str[0..-2]
  all_perms = [str]
  perms.each do |p|
    p.chars.each_with_index do |q, i|
      t = p.chars.join
      all_perms << t.insert(i, last_char)
    end
  end

  all_perms
end

puts 'v1:'
puts permutations_v1("abcd")

def permutations_v2(str, i, n)
  if i == n
    puts str
  end

  i.upto(n - 1) do |k|
    tmp = str[i]
    str[i] = str[k]
    str[k] = tmp
    permutations_v2(str, i + 1, n)
    tmp = str[k]
    str[k] = str[i]
    str[i] = tmp
  end
end

puts 'v2:'
permutations_v2("abcd", 0, 4)
