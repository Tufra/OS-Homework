touch lofs.img
fallocate --length 50M lofs.img

LOOP_DEVICE=$(sudo losetup -f)
sudo losetup -fP lofs.img
sudo mkfs.ext4 $LOOP_DEVICE

mkdir lofsdisk
sudo mount $LOOP_DEVICE lofsdisk
sudo chown -R $USER: ./lofsdisk