/**
    Given a data structure like:
    public class ListNode extends Object {
        int data;
        ListNode next;
    }
    Implement a deep copy method for the data structure.
    Specifically, you will be creating an implementation for the following interface:

    ListNode deepCopy( ListNode head);

 */

import java.util.Map;
import java.util.HashMap;

class Solution {

    public static class ListNode extends Object {
        public int data;
        public ListNode next;
    }

    /**
     * Simple example test main.
     */
    public static void main(String[] args) {
        // Test list
        ListNode node1 = new ListNode();
        ListNode node2 = new ListNode();
        ListNode node3 = new ListNode();
        ListNode node4 = new ListNode();
        node1.data = 1;
        node2.data = 1;
        node3.data = 3;
        node4.data = 1;
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node2;

        ListNode head = node1;
        ListNode copy = deepCopy(head); // Calls your code

        node3.data = 99;

          Map<ListNode, Integer> nodesHash = new HashMap<ListNode, Integer>();
        while (copy != null) {
          if (nodesHash.containsKey(copy)) {
            System.out.println("cycle at node " + copy.data);
            break;
          }
          else {
            System.out.println(copy.data);
            nodesHash.put(copy, copy.data);
            copy = copy.next;
          }
        }
      if (copy==null) {
        System.out.println("List ends with null");
      }
    }

    /**
     * Implement me!
     */
  public static ListNode deepCopy(ListNode head) {
    if (head == null)
      return null;

    Map<ListNode, Integer> nodesHash = new HashMap<ListNode, Integer>();
    ListNode n1 = new ListNode();
    ListNode n2 = new ListNode();
    n1.data = head.data;
    ListNode n = head.next;
    ListNode newHead = n1;

    nodesHash.put(head, head.data);

    while(n != null) {
      if (nodesHash.containsKey(n)) {
        Integer data = nodesHash.get(n);
        n1.next = findNode(newHead, n.data);
        break;
      } else {
        nodesHash.put(n, n.data);
        n2 = new ListNode();
        n2.data = n.data;
        n1.next = n2;
        n = n.next;
        n1 = n2;
      }
    }

    return newHead;
  }

  public static ListNode findNode(ListNode head, int data) {
    while(head != null) {
      if (head.data == data)
        return head;
      head = head.next;
    }
    return null;
  }
}
