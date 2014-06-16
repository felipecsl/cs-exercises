// Doubly linked list implementation
class MyLinkedList {
  def head
  def tail

  MyLinkedList() {
  }

  def insert(data) {
    def node = new Node(data)

    if (tail) {
      tail.next = node
      node.prev = tail
      tail = node
    } else {
      tail = node
    }

    if (!head)
      head = tail

    node
  }

  def delete(node) {
    if (node.prev)
      node.prev.next = node.next
    else
      head = node.next
  }

  def print() {
    printNode head
    println ''
  }

  def printNode(node) {
    if (!node)
      return

    print node.data + (node.next ? ', ' : '')

    printNode node.next
  }

  class Node {
    def data
    def next
    def prev

    Node (data) {
      this.data = data
    }
  }
}