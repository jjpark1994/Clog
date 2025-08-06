#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdarg.h>

typedef enum {
	DEBUG,
	INFO,
	WARN,
	ERROR
}LOG_LEVEL;

//로그파일 열기
void open_log(const char *filename);

//로그 기록
void write_log(LOG_LEVEL level, const char* func, int line, const char* fmt, ...);

//로그 파일 닫기
void close_log();
