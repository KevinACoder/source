//
class node
{
	int  _val;
	node _next;
	node(int val)
	{
		this._val = val;
	}

	Integer get_len(node head)
	{
		node cur = head;

		Integer len = 0;
		while(cur != null)
		{
			cur = cur._next;
			++len;
		}

		return len;
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

	void print()
	{
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

	node reverse_list(node head, Integer from, Integer to)
	{
		if(to > get_len(head) || from >= to)
		{
			return head;
		}

		node cur = head;
		node pre = null; //one node previous the part to be reversed
		node start = null;
		node pos = null; //one node after the part to be reversed
		node end = null;
		Integer len = 0;
		while(cur != null)
		{
			++len;
			pre = (len == from-1)?cur:pre; //assign if it is the target node
			start = (len == from)?cur:start;
			pos = (len == to+1)?cur:pos;
			end = (len == to)?cur:end;

			cur = cur._next;
		}

		node nhead = (pre == null)?head:pre; //check if head need to be chged

		//reverse part
		{
			end._next = null;
			start = start.reverse_list(start);
			end = start;
			while(end._next != null)
			{
				end = end._next;
			}
		}

		//re-assemble
		if(pre == null)
		{
			head = start;
		}
		else
		{
			head._next = start;
		}
		end._next = pos;

		return nhead;
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
		head.push(9);
		head.push(11);
		head.print();

		node head2 = new node(2);
		head2.push(5);
		head2.push(7);
		head2.print();

		node head3 = new node(1);
		head3.push(2);
		head3.push(3);

		head2.print_common_part_in_sorted_list(head);

		//head.remove_last_kth_node(4);
		//head.remove_middle_node();
		//head = head.reverse_list(head);
		//head = head.reverse_list(head, 1, 4);
		head3 = head3.reverse_list(head3, 1, 2);
		head.print();
	}
}

