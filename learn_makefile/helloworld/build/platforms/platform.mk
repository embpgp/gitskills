# platform.mk

## 定义编译命
CXX:=g++
CXXFLAGS:=-Wall

## 加载额外定制的编译命令配置.mk
include build/platforms/platform-specs.mk
