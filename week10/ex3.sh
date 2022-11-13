touch _ex3.txt
echo "sus amogus" > _ex3.txt

touch ex3.txt
chmod a-x _ex3.txt >> ex3.txt
chmod u=rwx,o=rwx _ex3.txt >> ex3.txt
chmod g=rwx _ex3.txt >> ex3.txt


# 660 -> owner and group have read/write permission, others have no permissions
# 775 -> owner and group have all permissions, others have read/execute permissions
# 777 -> everybody has all permissions (read/write/execute)