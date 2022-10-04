gcc ex4.c -o ex4

/bin/time -o ./ex4.txt ./ex4 10000000 1 
/bin/time -o ./ex4.txt -a ./ex4 10000000 2
/bin/time -o ./ex4.txt -a ./ex4 10000000 4
/bin/time -o ./ex4.txt -a ./ex4 10000000 10
/bin/time -o ./ex4.txt -a ./ex4 10000000 100

rm ./ex4