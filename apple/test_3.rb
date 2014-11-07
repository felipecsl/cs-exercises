# 
# Your previous Plain Text content is preserved below:
#

d1 = {
    a: 5,
    b: 'hi',
    c: {
      h: 1,
      k: 3
    }
    d: {
      i: 9
    }
  e: nil
}

d2 = {
  a: 5,
  c: {
    h: 1,
    k: 2
  },
  d: 5,
  e: 2
}

# sample result:

result = {
   b: {
     d1: 'h1'
  },
  c: {
    k: {
      d1: 3,
      d2: 2
    }
  },
  # also d & e...
}

d3 = {
  a: 5
  c: {
    a: 2,
    b: 4,
    d: {
      f: 'hello'
      }
    }
  }

# 1. d1[k] and d2[k] are both ints or strings = output a hash with the differences
# 2. either d1[k] or d2[k] is a hash
#  2.1 - if d1[k] is Hash and d2[k] is regular - { d1: d1[k], d2: d2[k] }
#  2.2 -

def kv_diff(d1, d2)
  diff = {}
  d1.each do |k, v|
    if !d2.has_key?(k)
      diff[k] = { d1: v }
    else
      if d1[k].is_a?(Hash) && d2[k].is_a?(Hash) && d1[k] != d2[k]
        inner_diff = kv_diff(d1[k], d2[k])
        diff[k] = inner_diff
      else
        if d2[k] != d1[k]
          diff[k] = {
            d1: v
            d2: d2[k]
          }
        end
      end
    end
  end

  d2.each do |k, v|
    if !d1.has_key(k)
      diff[k] = { d2: v }
    end
  end
end

puts kv_diff(d1, d2)

#
#

# {, [, (
bracket_str_bad = "{[djfijdifp])"
bracket_str_good = "([djf[ijd]ifp])"
bracket_str_bad1 = "[(djfijdifp])"
s2 = "[)odifjaosdjfiuasdhfiouhasdiufhiaosduhfiouasdhofiuhads]("

def are_brackets_balanced(bracket_str, curly = 0, squary = 0, round = 0)
  if bracket_str.empty?
    if curly != 0 || squary != 0 || round != 0
      return false
    end

    return true
  end

  if bracket_str[0] == '{'
    return are_brackets_balanced(bracket_str[1..-1], curly + 1, squary, round)
  end

  if bracket_str[0] == '['
    return are_brackets_balanced(bracket_str[1..-1], curly, squary + 1, round)
  end

  if bracket_str[0] == '('
    return are_brackets_balanced(bracket_str[1..-1], curly, squary, round + 1)
  end

  if bracket_str[0] == '}'
    return are_brackets_balanced(bracket_str[1..-1], curly - 1, squary, round)
  end

  if bracket_str[0] == ']'
    return are_brackets_balanced(bracket_str[1..-1], curly, squary - 1, round)
  end

  if bracket_str[0] == ')'
    return are_brackets_balanced(bracket_str[1..-1], curly, squary, round - 1)
  end

  return are_brackets_balanced(bracket_str[1..-1], curly, squary, round)
end
