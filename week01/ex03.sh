date
sleep 3
mkdir rootdir

date
sleep 3
touch rootdir/root.txt

ls / -tr > rootdir/root.txt

date
sleep 3
mkdir homedir

date
sleep 3
touch homedir/home.txt

ls ~ -tr > homedir/home.txt

cat rootdir/root.txt homedir/home.txt
ls rootdir
ls homedir
