compile commands
gcc PA4pA.c -lpthread -lm -o a.out
gcc PA4pB.c -lpthread -lm -o b.out

./a.out
pi = 3.141539

./b.out 
Usage: ./b.out <number of threads> 

./b.out 10 20
Usage: ./b.out <number of threads>

./b.out -3
<number of threads> should be a positive integer 

./b.out 50
pi = 3.141544