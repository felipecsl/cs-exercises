class BST
  def initialize(arr)
    arr.each do |i|
      insert i
    end
  end

  def insert(item)
    x = @root
    y = nil
    while x != nil
      y = x
      if item < x.key
        x = x.left
      else
        x = x.right
      end
    end
    node = Node.new(y, item)
    if y == nil
      @root = node
    else
      if node.key < y.key
        y.left = node
      else
        y.right = node
      end
    end
  end

  def inorder_walk(node = @root)
    if node != nil
      inorder_walk(node.left)
      puts node.key
      inorder_walk(node.right)
    end
  end

  def postorder_walk(node = @root)
    if node != nil
      postorder_walk(node.left)
      postorder_walk(node.right)
      puts node
    end
  end

  def preorder_walk(node = @root)
    if node != nil
      puts node
      preorder_walk(node.left)
      preorder_walk(node.right)
    end
  end

  def search(key, node = @root)
    if node == nil || node.key == key
      node
    else
      if node.key < key
        search(key, node.right)
      else
        search(key, node.left)
      end
    end
  end

  def min(node = @root)
    while node.left != nil
      node = node.left
    end
    node
  end

  def max(node = @root)
    while node.right != nil
      node = node.right
    end
    node
  end
end

class Node
  attr_accessor :parent, :left, :right, :key

  def initialize(parent, key, left = nil, right = nil)
    @parent = parent
    @key = key
    @left = left
    @right = right
  end

  def to_s
    "node #{@key}, parent #{@parent ? @parent.key : 'nil'}, left #{@left ? @left.key : 'nil'}, right #{@right ? @right.key : 'nil'}"
  end
end

bst = BST.new(0.upto(20).map { |i| (rand() * 100).to_i }.uniq)
bst.preorder_walk
p "Min = " + bst.min.to_s
p "Max = " + bst.max.to_s
search = (rand() * 100).to_i
p "Search for #{search} = " + bst.search(search).to_s