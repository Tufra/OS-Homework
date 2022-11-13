link ../week01/file.txt _ex2.txt >> ex2.txt
find ../week01/file.txt -inum 12473 >> ex2.txt
find . -inum 12473 -exec rm {} \;