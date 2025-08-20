# 컴파일러 및 옵션
CC = gcc
CXX = g++
AR = ar
CFLAGS = -Wall -Iinc
ARFLAGS = rcs
	
# 디렉토리
BINDIR = ./bin
INCDIR = ./inc
LIBDIR = ./lib
LIBSRC = ./libsrc
SRCDIR = ./src
TESTDIR = ./test
	
# 파일
LIBNAME = libLog.a
LIBOBJ = $(LIBSRC)/libLog.o
APPNAME = myapp
APP_SRC = $(SRCDIR)/main.c
APP_OBJ = $(SRCDIR)/main.o
	
# gtest??
TEST_SRC = $(TESTDIR)/test_libLog.cpp
TEST_BIN = $(TESTDIR)/test_runner


# 기본 타겟
all: $(LIBNAME) $(APPNAME)
	
# 라이브러리 만들기
$(LIBNAME): $(LIBOBJ)
	$(AR) $(ARFLAGS) $@ $^
	
# 실행 파일 만들기
$(APPNAME): $(APP_OBJ) $(LIBNAME)
	$(CC) -o $@ $^ -L. -lLog
	
# 개별 오브젝트 파일 컴파일
$(LIBOBJ): $(LIBSRC)/libLog.c $(INCDIR)/libLog.h
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(APP_OBJ): $(APP_SRC) $(INCDIR)/libLog.h
	$(CC) $(CFLAGS) -c -o $@ $<

#테스트 빌드 및 실행
test: $(LIBNAME) $(TEST_BIN)
	$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(LIBNAME)
	$(CXX) $(CXXFLAGS) -o $@ $^ -L. -lLog -lgtest -lgtest_main -pthread
	
# 설치
install:
	mkdir -p $(BINDIR) $(LIBDIR)
	cp $(APPNAME) $(BINDIR)/
	cp $(LIBNAME) $(LIBDIR)/
#	cp $(INCDIR)/libLog.h $(INCDIR)/
	
# 정리
clean:
	rm -f $(LIBOBJ) $(APP_OBJ) $(LIBNAME) $(APPNAME)
	rm -f $(TEST_BIN)
		
.PHONY: all install clean
