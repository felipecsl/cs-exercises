class Node
  def initialize(data)
    @data = data
    @children = []
  end

  def data
    @data
  end

  def children
    @children
  end
end

# Simple tree structure, not strictly binary.
class Tree
  def initialize
    @root = nil
  end

  def add(data, parent_data)
    unless @root
      @root = Node.new(parent_data)
      @root.children << Node.new(data)
      return
    end

    if parent = find_node(parent_data)
      parent.children << Node.new(data)
    elsif @root.data == data
      temp = @root
      @root = Node.new(parent_data)
      @root.children << temp
    else
      throw "invalid tree structure."
    end
  end

  # Depth first search
  def find_node(data, n = @root)
    return nil unless n
    return n if n.data == data

    n.children.each do |c|
      found = find_node(data, c)
      return found if found
    end

    nil
  end

  def dump(nodes = [@root])
    nodes.each_with_index do |n, i|
      if n.children.any?
        print "#{n.data}: ["
        dump n.children
        print "]"
      else
        print n.data
      end
      print ", " if i < nodes.size - 1
    end
  end
end
