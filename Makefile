pharse: test.o ini.o
	gcc -o pharse test.o ini.o

clean:
	rm -f test.o ini.o
