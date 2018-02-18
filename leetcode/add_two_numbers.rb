# Definition for singly-linked list.
class Nd
  attr_accessor :val, :next
  def initialize(val, nxt = nil)
    @val = val
    @next = nxt
  end

  def to_s
    if @next.nil?
      @val
    else
      "#{@val} -> #{@next.to_s}"
    end
  end

  def compact
    if @next.nil?
      @val.to_s
    else
      "#{@val}#{@next.compact}"
    end
  end
end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def add_two_numbers(l1, l2)
  nd_l1 = list_node_to_nd(l1)
  nd_l2 = list_node_to_nd(l2)
  return (nd_l1.compact.reverse.to_i + nd_l2.compact.reverse.to_i)
    .to_s
    .reverse
    .chars
    .map(&:to_i)
end

def to_ll(first, *more)
  if more.empty?
    return Nd.new(first)
  end
  Nd.new(first, to_ll(*more))
end

def list_node_to_nd(node)
  if node.next.nil?
    return Nd.new(node.val)
  else
    return Nd.new(node.val, list_node_to_nd(node.next))
  end
end

puts add_two_numbers(to_ll(2, 4, 3), to_ll(5, 6, 4))
