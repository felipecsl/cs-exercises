# Given an array of pairs that represent a child-parent
# relationship in a tree, return a data structure representing
# the tree
# E.g.
#     3
#   / |  \
# 2   1   4
# PAIRS = [(4,3), (2,3), (1,3)]

require_relative '../ruby/data_structures/tree'

def make_tree(pairs)
  t = Tree.new

  pairs.each do |p|
    t.add(p.first, p.last)
  end

  t
end

t = make_tree [[4,3], [2,3], [1,3], [3,5], [7,2]]
t.dump

# 5 -> [3 -> [4, 2 -> [7], 1]]
