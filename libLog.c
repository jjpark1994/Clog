#include"libLog.h"

//로그 파일 포인터 
FILE *log_file;
LOG_LEVEL currentLogLevel = INFO;

const char* logLevelString[] = {
	"DEBUG",
	"INFO",
	"WARN",
	"ERROR"
};

//로그파일 열기
void open_log(const char *filename)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);


	//날짜를 형식화 해서 문자열로 만들기
	char date_str[20];
	snprintf(date_str, sizeof(date_str), "%04d-%02d-%02d", tm.tm_year +1900, tm.tm_mon + 1, tm.tm_mday);


	//로그 파일 이름에 날짜 추가
	char log_filename[256];
	snprintf(log_filename, sizeof(log_filename), "%s_%s.log", filename, date_str);

	//로그 파일 열기
	//main에서. log_file 선언
	log_file = fopen(log_filename, "a");
	if(log_file == NULL){
		perror("로그 파일을 열 수 없습니다");
	}
}

//로그 기록
void write_log(LOG_LEVEL level, const char* func, int line,  const char* fmt, ...){

	if(level < currentLogLevel){
		return;
	}

	if(log_file != NULL){
		time_t now = time(NULL);
		char time_str[100];
		strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S",localtime(&now));

		//로그 헤더 생성
		char header[256];
		int headerLen = snprintf(header, sizeof(header),"[%s][%s]func:%s:line:%d:",time_str,logLevelString[level],func, line);

		//가변 인자 처리
		char message[1024];
		va_list args;
		va_start(args, fmt);
		vsnprintf(message, sizeof(message), fmt, args);
		va_end(args);

		fprintf(log_file,"%s%s\n",header,message);
		fflush(log_file);
		
	}
}


//로그 파일 닫기
void close_log(){
	if(log_file != NULL){
		fclose(log_file);
		log_file = NULL;
	}
}
