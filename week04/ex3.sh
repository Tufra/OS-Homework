gcc ex3.c -o ex3

./ex3 3 &
echo "for n = 3"

for i in `seq 1 4` 
do
    echo "i = $i"
    pstree $$
    sleep 5
done

./ex3 5 &
echo "for n = 5"

for i in `seq 1 6` 
do
    echo "i = $i"
    pstree $$
    sleep 5
done