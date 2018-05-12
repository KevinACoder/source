class fresh_juice{
	enum fresh_juice_size{s, m, l}
	fresh_juice_size size;
}

public class fresh_juice_test{
	public static void main(String[] args) {
		fresh_juice juice = new fresh_juice();
		juice.size = fresh_juice.fresh_juice_size.s;
		System.out.println("juice size: " + juice.size);
	}
}
