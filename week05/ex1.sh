gcc publisher.c -o pub
gcc subscriber.c -o sub

gnome-terminal --title=publisher -- ./pub $1

echo "$1"

for i in `seq 1 $1` 
do
    gnome-terminal -- ./sub
done

rm ./pub
rm ./sub