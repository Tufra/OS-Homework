gcc ex2.c -o ex2.out -static -static-libgcc
sudo mv ex2.out ./lofsdisk/
cd lofsdisk

sudo touch file1
sudo touch file2

sudo chown -R $USER: ./

echo Maxim > file1
echo Insapov > file2


sudo chroot ./ ./ex2.out > ex2.txt