##  main.mk
#

RM:= rm -f

CXX:=g++
CXXFLAGS:=-Wall

OBJS:=hello.o main.o
TARGETS:=hello
##定义obj文件的编译规则
hello.o:hello.cpp hello.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
main.o:main.cpp hello.h
	$(CXX) $(CXXFLAGS)  -c $< -o $@

#定义可执行文件的hello的编译规则
$(TARGETS): hello.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY:all
all:	$(TARGETS)

.PHONY:clean
clean:
	$(RM)  $(TARGETS) $(OBJS)
