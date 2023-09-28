
all: test.txt using_mmap using_read

bench: all
	hyperfine -w 3 ./using_mmap ./using_read

test.txt:
	head -c 1073741824 < /dev/urandom > test.txt

using_mmap: using_mmap.c
	clang -o using_mmap -O2 using_mmap.c

using_read: using_read.c
	clang -o using_read -O2 using_read.c

clean:
	rm -f test.txt using_mmap using_read