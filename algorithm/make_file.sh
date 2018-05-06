#$1: main cpp, $2: sub cpp
gcc -c $2 -o sub.o
gcc $1 sub.o -o run 
