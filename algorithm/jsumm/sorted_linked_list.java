//
class node
{
	int  _val;
	node _next;
	node(int val){
	this._val = val;
	}

	void push(int val)
	{
		node curnode = this;
		while(curnode._next != null)
		{
			curnode = curnode._next;
		}

		curnode._next = new node(val);
	}

	void print(){
		node curnode = this;
		System.out.print("START\n");
		while(curnode != null)
		{
			System.out.print(curnode._val + " ");
			curnode = curnode._next;
		}

		System.out.print("\nEND\n");
	}

	void print_common_part_in_sorted_list(node head2)
	{
		node curnode1 = this;
		node curnode2 = head2;

		while(curnode1 != null && curnode2 != null)
		{
			if(curnode1._val > curnode2._val)
			{
				curnode2 = curnode2._next;
			}
			else if(curnode2._val > curnode1._val)
			{
				curnode1 = curnode1._next;
			}
			else
			{
				System.out.print(curnode1._val + " ");
				curnode1 = curnode1._next;
				curnode2 = curnode2._next;
			}
		}
	}

	void remove_last_kth_node(int k)
	{
		node fastnode = this;
		node slownode = this;
		node bef_slow_node = null;

		int step = 1;
		while(fastnode._next != null)
		{
			if(step >= k)
			{
				bef_slow_node = slownode;
				slownode = slownode._next;
			}

			fastnode = fastnode._next;
			++step;
		}

		if(bef_slow_node == null)
		{
			if(step == k) //need to delete head
			{
				this._val = this._next._val;
				this._next = this._next._next;
			}
		}
		else
		{
			bef_slow_node._next = slownode._next;
		}
	}

	int remove_middle_node()
	{ 
		if(this == null || this._next == null)
			return -1; //cannot delete head
		else if(this._next._next == null)
		{
			int val = this._val;
			this._val = this._next._val; //replace head
			this._next = this._next._next;
			return val;
		}

		node tailnode = this._next._next;
		node midnode = this;
		node bef_midnode = null;

		while(tailnode != null && tailnode._next != null)
		{
			tailnode = tailnode._next._next;
			bef_midnode = midnode;
			midnode = midnode._next;
		}

		int val = midnode._val;
		bef_midnode._next = midnode._next;
		return val;
	}

	node reverse_list(node head)
	{
		node pre = null;
		node next = null;
		node cur = head;

		while(cur != null)
		{
			next = cur._next; //preserve position of next node 
			cur._next = pre; //do reverse

			pre = cur; // move cur to next
			cur = next;
		}

		head = pre; //chg head

		return head;
	}
}

public class sorted_linked_list
{
	public static void main(String[] args) 
	{
		System.out.print("sorted_linked_list \n");
		node head = new node(1);
		head.push(3);
		head.push(5);
		head.push(7);
		head.print();

		node head2 = new node(2);
		head2.push(5);
		head2.push(7);
		head2.print();

		head2.print_common_part_in_sorted_list(head);

		//head.remove_last_kth_node(4);
		head.remove_middle_node();
		head = head.reverse_list(head);
		head.print();
	}
}

