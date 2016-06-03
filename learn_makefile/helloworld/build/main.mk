##  main.mk
#

include build/systems/system.mk
## 定义产品信息。这里BUILD_SPECS设置为空，表示我们不做额外定制化  
PRODUCT_SPECS :=build/spec.mk  
include build/products/product.mk

## 定义平台相关的编译命令。这里PLATFORM_SPECS为空，表示我们不做额外定制化。  
PLATFORM_SPECS :=  
include build/platforms/platform.mk  
  
## 将产品信息中的定义的feature与平台定义的编译选项混合  
CXXFLAGS+=$(OPTIONS)  

OBJS:=hello.o main.o  
TARGET:=hello
  
## 定义obj文件的编译规则  
hello.o : hello.cpp hello.h  
	$(CXX) $(CXXFLAGS) -c $< -o $@  
main.o : main.cpp hello.h  
	$(CXX) $(CXXFLAGS) -c $< -o $@  
      
## 定义可执行文件hello.exe的编译规则      
$(TARGET):  $(OBJS)  
	$(CXX) $(CXXFLAGS)  -o $@ $^  
  
all:	hello 
	
clean:
	$(RM) $(TARGET) $(OBJS)
