import java.io.*;
import java.util.*;

public class binary_tree
{
	public static void main(String[] args) 
	{
		System.out.print("binary_tree \n");
		bt_node root = new bt_node(1);
		root = root.push(root, 2);
		root = root.push(root, 3);
		//root.pre_order_recur(root);
		//root.pre_order_traversal(root);
		//root.in_order_traversal(root);
		root.post_order_traversal(root);
	}
}

class bt_node //only one public class is alloweds in one java file
{
	public int val;
	public bt_node left;
	public bt_node right;
	public bt_node(int data)
	{
		this.val = data;
	}

	bt_node push(bt_node root, int data)
	{
		if(root == null)
			root = new bt_node(data); //create new node
		else if(data < root.val) 
			root.left = push(root.left, data); //build link with its parent
		else
			root.right = push(root.right, data);

		return root;
	}

	void pre_order_recur(bt_node node)
	{
		if(node == null)
			return;

		System.out.print(node.val + "\n");
		pre_order_recur(node.left);
		pre_order_recur(node.right);
	}

	List<Integer> pre_order_traversal(bt_node head)
	{
		Stack<bt_node> stack = new Stack<bt_node>();
		List<Integer> list = new ArrayList<Integer>();
		bt_node cur = null;
		stack.push(head);

		while(!stack.isEmpty())
		{
			cur = stack.pop();
			if(cur != null)
			{
				list.add(cur.val);
				System.out.print(cur.val + "\n");

				stack.push(cur.right);
				stack.push(cur.left);
			}
		}

		return list;
	}

	List<Integer> in_order_traversal(bt_node head)
	{
		Stack<bt_node> stack = new Stack<bt_node>();
		List<Integer> list = new ArrayList<Integer>();
		bt_node cur = head;

		while(!stack.isEmpty() || cur != null)
		{
			if(cur != null) //first push the whold left sub tree into the stack
			{
				stack.push(cur);
				cur = cur.left; 
			}
			else
			{
				cur = stack.pop(); //pop the left most node
				System.out.print(cur.val + "\n");
				list.add(cur.val);

				cur = cur.right; //switch to the right sub-tree
			}
			System.out.println();
		}
		
		return list;
	}

	List<Integer> post_order_traversal(bt_node root)
	{
		List<Integer> list = new ArrayList<Integer>();
		if(root != null)
		{
			Stack<bt_node> stack1 = new Stack<bt_node>();
			Stack<bt_node> stack2 = new Stack<bt_node>();

			bt_node node = null;
			stack1.push(root);
			while(!stack1.isEmpty())
			{
				node = stack1.pop();
				stack2.push(node);

				if(node.left != null)
				{
					stack1.push(node.left);
				}

				if(node.right != null)
				{
					stack1.push(node.right);
				}
			}

			while(!stack2.isEmpty())
			{
				bt_node cur = stack2.pop();
				list.add(cur.val);
				System.out.print(cur.val + "\n");
			}
		}

		return list;
	}

}