#include<bits/stdc++.h>
#define 사용하다 using
#define 이름공간 namespace
사용하다 이름공간 std;
#define 정수 int
#define 실수 double
#define 긴 long
#define 짧은 short
#define 만약 if
#define 아니면 else
#define 아니면만약 else if
#define 해라 do
#define 동안반복 while
#define 반복 for
#define 기본 main
#define 큐 queue
#define 스택 stack
#define 덱 deque
#define 우선순위큐 priority_queue
#define 앞에넣다 push_front
#define 뒤에넣다 push_back
#define 밀다 push
#define 비다 empty
#define 맨위 top
#define 앞 front
#define 뒤 back
#define 뽑다 pop
#define 앞에뽑다 pop_front
#define 뒤에뽑다 pop_back
#define 정렬 sort
#define 입력 cin
#define 출력 cout
#define 자동지정변수 auto
#define 지정되지않은 unsigned
#define 참과거짓 bool
#define 동적배열 vector
#define 지우다 erase
#define 모두지우다 clear
#define 시작 begin
#define 끝 end
#define 역시작 rbegin
#define 역끝 rend
#define 지정하다 typedef
#define 줄바꿈 "\n"
#define 쌍 pair
#define 첫번째 first
#define 두번째 second
#define 공간 size
#define 길이 length
#define 객체 class
#define 공공의 public
#define 개인의 private
#define 깨뜨리다 break
#define 계속하다 continue
#define 가다 goto
#define 문자열 string
#define 문자 char
#define 구조체 struct
#define 공용체 union
#define 열거체 enum
#define 공허 void
#define 전환하다 switch
#define 경우 case
#define 반환하다 return
#define 시간 tie
#define 사실 true
#define 거짓 false
#define 일시고정 static
#define 위대한 greater
#define 새로운 new
#define 줄가져오다 getline
#define 틀 template
#define 상수 const
#define 뒤집다 reverse
#define 표준입출력 ios
#define 표준입출력과동기화 sync_with_stdio
#define 빠른줄바꿈 "\n"
#define 공간재지정 resize
#define 이진저장 memset
#define 공간의 sizeof
#define 아니다 !
#define 그리고 and
#define 또는 or
#define 여집합 ~
#define 합집합 |
#define 교집합 &
#define 베타적논리합 ^
#define 절댓값 abs
#define 제곱 pow
#define 고치다 fixed
#define 바꾸다 swap
정수 기본(){
    표준입출력::표준입출력과동기화(거짓);
    입력.시간(0); 출력.시간(0);
    정수 엔;
    동적배열<정수>알(엔);
    반복(자동지정변수&ㅍ:알)입력>>ㅍ;
    정렬(알.시작(),알.끝());
    출력<<알.앞()*알.뒤();
    반환하다 0;
}