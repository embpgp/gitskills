##  makefile
#

##定义obj文件的编译规则
hello.o:hello.cpp hello.h
	g++ -Wall -c $< -o $@
main.o:main.cpp hello.h
	g++ -Wall -c $< -o $@

#定义可执行文件的hello的编译规则
hello: hello.o main.o
	g++ -Wall -o $@ $^

.PHONY:all
all:	hello

.PHONY:clean
clean:
	rm -f hello.o main.o hello
