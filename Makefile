all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

test1: all
	bin/gauss dane/C dane/d

test2: all
	bin/gauss dane/E dane/f

test3: all
	bin/gauss dane/G dane/h

test4: all
	bin/gauss dane/I dane/j

test5: all
	bin/gauss dane/K dane/l