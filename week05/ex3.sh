gcc ex3.c -o ex3

/bin/time -o ./ex3.txt ./ex3 10000000 1 
/bin/time -o ./ex3.txt -a ./ex3 10000000 2
/bin/time -o ./ex3.txt -a ./ex3 10000000 4
/bin/time -o ./ex3.txt -a ./ex3 10000000 10
/bin/time -o ./ex3.txt -a ./ex3 10000000 100

rm ./ex3