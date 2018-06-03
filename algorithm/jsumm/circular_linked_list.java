public class circular_linked_list
{
	public static void main(String[] args) 
	{
		System.out.print("circular_linked_list \n");
		node head = new node(2);
	}
}
class node
{
	int val;
	int next;

	node(int val_)
	{
		this.val = val_;
	}

	int get_len(node head)
	{
		node cur = head;

		Integer len = 0;
		while(cur != null)
		{
			cur = cur.next;
			++len;
		}

		return len;
	}

	void push(int val)
	{
		node curnode = this;
		while(curnode.next != null)
		{
			curnode = curnode.next;
		}

		curnode.next = new node(val);
	}

	void print()
	{
		node curnode = this;
		System.out.print("START\n");
		while(curnode != null)
		{
			System.out.print(curnode.val + " ");
			curnode = curnode.next;
		}

		System.out.print("\nEND\n");
	}

	node get_tail(node head)
	{
		while(head.next != null)
			head = head.next;

		return head;
	}

	node delete_node(node head, int ix)
	{
		if(head == null || ix >= get_len(head))
			return head;

		if(ix == 0)
		{
			return head.next;
		}

		int count = 0;
		node pre = null;
		node cur = head;
		while(count < ix)
		{
			pre = cur;
			cur = cur.next;
		}

		pre.next = cur.next;

		return head;
	}

	node josephus_kill(node head, int step)
	{
		if(head == null || head.next = null || step < 1)
			return head;

		node tail = get_tail(head);

		while(get_len(head) > 1)
		{
			int start = (get_len(head)+1)%2;
		}
	}

	void elimination_game(int len)
	{
		node head = new node(1);

		for(int i = 2 ; i <= len; ++i)
		{
			head.push(i);
		}

		print(head);
		//head = josephus_kill(head, 2);
		print(head);
	}
}