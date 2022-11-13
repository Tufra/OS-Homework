touch ./tmp/file1
touch ./tmp/file2

link ./tmp/file1 ./tmp/link1
link ./tmp/file1 ./tmp/link2
link ./tmp/file1 ./tmp/link3
link ./tmp/file2 ./tmp/link4
gcc ./ex4.c -o ./ex4



./ex4

# rm ./ex4

rm ./tmp/link1
rm ./tmp/link2
rm ./tmp/link3
rm ./tmp/link4