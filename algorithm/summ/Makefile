#rename file Makefile, generate multiple targets
#http://www.csl.mtu.edu/cs4411.ck/www/NOTES/make/multiple.html
all: tree linked_list hash_table

tree: tree.cpp tree.h defines.h
	g++ -o tree tree.cpp

linked_list:linked_list.cpp linked_list2.cpp test_linked_list.cpp linked_list.h defines.h
	g++ -o linked_list linked_list.cpp test_linked_list.cpp linked_list2.cpp

hash_table: hash_table.cpp hash_table.h defines.h
	g++ -o hash_table hash_table.cpp 