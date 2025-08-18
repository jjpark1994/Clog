#include"libLog.h"
extern void open_log(const char *filename);
extern void write_log(LOG_LEVEL level,const char* func, int line, const char* fmt, ...);
//extern void close_log();

#define LOG(level, fmt, ...) write_log(level, __func__, __LINE__, fmt, ##__VA_ARGS__)

int main(){ 

	const char *LOG_FILE_NAME = "test";

	open_log(LOG_FILE_NAME);

	LOG(INFO,"프로세스 시작");

	LOG(DEBUG,"프로세스 DEBUG");

	LOG(ERROR,"프로세스 ERROR");
			

	close_log();
}
