class LinkedList
  def initialize
    @head = nil
    @tail = nil
  end

  def head
    @head
  end

  def tail
    @tail
  end

  def dump
    return unless @head
    node = @head
    begin
      print "#{node.data}, "
      node = node.next
    end while node
    puts
  end

  def add(data)
    node = Node.new(data)
    @tail.next = node if @tail
    @tail = node
    @head = @tail unless @head
  end
end

class Node
  def initialize(data)
    @data = data
    @next = nil
  end

  def data
    @data
  end

  def next=(node)
    @next = node
  end

  def next
    @next
  end
end
