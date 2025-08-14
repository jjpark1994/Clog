# Clog
c 언어로 구현된 로그 구현 입니다.


1. 전처리 까지만, 처리된 소스파일 확인 할것. ex) gcc-E main.c main.i 2
2. 전치리 기법으로 함수 만들어 보고, ex) squre 관례상, 전처리 정의는 항상 대문자로 맵핑. 템플릿 개념같다고 해서 마지막 T를 붙임
3. 컴파일할 매, 전처리가 처리 할 수 있도록 선언을 넘길 수 있음 ex) gcc -DDEBUG -o main main.c main.c가 컴파일할 때, DEBUG가 전처리선언으로 확인은 직접 해 보세요.
4.전처리방식으로 함수명을 generate 하는 에제 만들어 볼것. ex) #define FUNC(name) void func_##name0
5.(옵션) #define 함수를 이용하면, 성능미 빠른 이유.

오늘 컴파일 전처리 방식은 여기서 끝내도록 하겠습니다. 전처리는 위 4가지만 알고 있으면 끝 

다음은 링킹(linking>" 선언/ 정의 



		과제 1 . 정적라이브러리, 동적라이브러리 만들기
		bash >> gcc -c libLog.c -o libLog.o
		bash >> 정적 라이브러리 아카이브 생성 ar rcs liblog.a libLog.o
		이제 liblog.a 라는 라이브러리 파일이 생성
		main.c 컴파일 및 링크
		main.c 를 컴파일 하면서 liblog.a를 링크함
		gcc main.c -L. -log -o main
		실행 ./main
		과제 2 . 과제1에서만들 라이브러리로 실행 파일 만들기
