기본 명령어 - 파일다루기
• 파일 보기 ls, ls -l, ls -al
• 파일 내용 보기 cat, more, less
• 파일 만들기/지우기 touch, rm
• 파일 복사 cp
• 파일 이동 mv
• 파일 숏컷 ln (심볼릭 링크)
• 파일 속성 보기 file
• 디렉토리 만들기 mkdir, rmdir
• 디렉토리 이동 cd, cd -
• 디렉토리 구조 . / .. / ~
• 터미널 지우기 clear
• 시스템 종료 reboot, poweroff, shutdown
02
-
1
윈도우의
파일 다루기 윈도우의 파일 다루기
02-2
윈도우의
파일 다루기 윈도우의 파일 다루기 - CLI 사용하기 (cmd)
02-3
윈도우의
파일 다루기 윈도우의 파일 다루기 - CLI 사용하기 (cmd) advanced
ren *.txt *.docx
ren “*문서*” “패스트캠퍼스 문서*”
ren “*문서(?).*” “*문서-?.*”
03 
화면지우기
기본 명령어 - 화면 지우기 (clear)
clear
터미널 창 지우기
참고:
$ <- 프롬프트(prompt)
~ <- 홈 디렉토리
04-1
리눅스의
파일 다루기 기본 명령어 - 파일다루기
• 파일 보기
• 파일 만들기
• 디렉토리 만들기
04-2
리눅스의
파일 다루기 기본 명령어 - 파일 목록 보기 (ls = list)
ls [OPTION]… [FILE]…
다양한 옵션을 이용하여 디렉토리 내 파일 목록 조회하기
• ls 
• ls -l
• ls -a
• ls -al
• ls -a -l
• ls *.txt
: list
: long list
: all
: all + long
: all + long
: 확장자가 *.txt 파일인것
04-3
리눅스의
파일 다루기 기본 명령어 - 파일 만들기 (touch)
touch [OPTION]… [FILE]…
파일을 툭~ 건드리기 (정확히는 파일 생성보다는 현재 시간(timestamp)로 바꾸기)
(해당 파일이 존재하지 않는 경우 0바이트 파일 생성)
• touch hello.txt
• touch test1 test2 test3
• touch .hello.txt
히든파일 만들기 (맨 앞의 점)
(위 hello.txt 와 다른 파일임)
• 확인
ls vs ls -a
04-3
리눅스의
파일 다루기 기본 명령어 - 파일 내용 보기 (cat = concatenate)
cat [OPTION]… [FILE]…
파일 내용 보여주기 (정확히는 input 과 output 을 연결(concatenate)하기)
(input = 파일, output = standard out)
• cat hello.txt
• cat /etc/passwd
• cat /var/log/syslog
• cat -e /etc/passwd : 줄의 맨 뒤에 $붙이기 (히든 캐릭터 공백 등 확인)
• cat -n /etc/passwd : 줄 번호 보여주기
04-4
리눅스의
파일 다루기 기본 명령어 - 파일 내용 보기 (more)
more [OPTION]… [FILE]…
파일 내용 보여주기 (페이지 단위로 이동 - space)
(줄단위로 이동 - enter)
• more hello.txt
• more /etc/passwd
• more /var/log/syslog
04-5
리눅스의
파일 다루기 기본 명령어 - 파일 내용 보기 (less)
less [OPTION]… [FILE]…
파일 내용 보여주기 (페이지 단위로 이동 - space)
(줄단위로 이동 - enter)
(방향키 - 상하좌우, 페이지up/down)
• less hello.txt
• less /etc/passwd
• less /var/log/syslog
more 보다 향상된 기능, 그리고 모든 파일을 메모리에 올리지 않아 more 대비 속도가 빠름
04-6
리눅스의
파일 다루기 기본 명령어 - 파일 삭제 (rm - remove)
rm [OPTION]… [FILE]…
파일 (또는 디렉토리) 삭제
• rm hello.txt
• rm test1 test2 test3
• rm /etc/passwd (실패) - 보호된 파일?! 권한?!
05-1
디렉토리 다루기
기본 명령어 - 디렉토리 생성 (mkdir - make directory, rmdir - remove directory)
mkdir [OPTION]… [DIRECTORY]…
디렉토리 생성
• mkdir dir1
• mkdir dir2 dir3
• mkdir dir1/sub1
• mkdir dir1/sub2
• mkdir -p dir2/sub1 (parents)
rmdir [OPTION]… [DIRECTORY]…
디렉토리 삭제
• rmdir dir1
• rmdir dir2 dir3
• rmdir -p dir2 (parents)
참고(주의)
• rm dir1 (실패)
• rm -r dir1 (성공) (recursive)
사용자 주의
05-2
디렉토리 이동
기본 명령어 - 디렉토리 이동 (cd - change directory)
• cd dir1
• cd .. (부모 디렉토리)
• cd dir1/sub1
• cd .
• cd ../..
• cd ~/ (홈 디렉토리)
• cd
• cd - (이전 디렉토리)
• 디렉토리 구조
• . (나 자신)
• .. (부모 디렉토리)
• ~ (홈 디렉토리)
• - (이전 디렉토리)
06
리눅스의
파일 다루기 기본 명령어 - 파일 복사/이동 (cp - copy / mv - move)
cp [OPTION]… [SRC] [DST]
파일 복사
• 사전준비
touch hello.txt test1 test2
mkdir dir1
• cp hello.txt hello2.txt
• cp test1 dir1
• cp test2 dir1
• cp -r dir1 dir2
• 클린업
rm -r dir1 dir2
rm hello2.txt
: 파일 복사
: 파일 디렉토리 안으로 복사
: 디렉토리 복사
• 사전준비
touch hello.txt test1 test2
mkdir dir1
• mv hello.txt hello2.txt
• mv test1 dir1
• mv test2 dir1
• mv dir1 dir2
07-1
리눅스의
파일 링크 기본 명령어 - 파일 링크 (ln - link)
ln [OPTION]… [TARGET] [LINKNAME]
파일에 하드링크/소프트링크(심볼릭 링크) 만들기
• 사전준비
touch hello.txt
• 소프트링크 (심볼릭 링크)
ln -s hello.txt hellosymlink
• 하드링크
ln hello.txt hellolink
• 파일 링크 확인
ls -ali
07-2
리눅스의
파일 링크 기본 명령어 - 파일 시스템 구조
link의 유형 개념
• 하드링크
ln hello.txt hellolink
• 소프트링크 (심볼릭 링크)
ln -s hello.txt hellosymlink
hello.txt 파일
hellolink
10M + 10M ≠ 20M ??
10 M + 10M = 10M
hello.txt 파일
hellosymlink
10M + x Bytes
07-3
리눅스의
파일 링크 기본 명령어 - 파일 시스템 구조 (inode 맛보기)
inode의 초간단 개념
파일
DATA
hello.txt
hellolink
inode
DIR
DIR
FILE FILE
inode 파일
DATA
mode
owner
size
timestamp
direct blocks
indirect blocks
…
…
hellosymlink inode
08
리눅스의
파일 다루기 기본 명령어 - 파일 속성 보기 (file)
file [OPTION]… [FILE]…
파일의 속성 보여주기
• file hello
• file /etc/passwd
• file dir1
• file /usr/bin/file
• file hellosymlink
09 
시스템 종료
기본 명령어 - 시스템 종료(reboot, poweroff, shutdown)
reboot
재부팅
poweroff
종료
shutdown [OPTIONS] [TIME]
주어진 시간에 종료 (기본값 +1 - 1분후)
shutdown -P now : 바로 종료
shutdown -r now : 바로 재시작
reboot, poweroff 두 명령어 모두 바로 적용되니 사용시 주의
10
도움말
기본 명령어 - 도움말/매뉴얼 (man - manual)
man [OPTION]… [PAGE] [COMMAND]
매뉴얼 보기
PAGE 종류
1. 일반 명령어
2. 시스템 호출
3. C표준 라이브러리 함수
4. 특수파일 (/dev 등)
5. 파일 형식과 Conventions
6. 게임과 화면보호기
7. 기타
8. 시스템관리 명령어와 데몬
예시)
• man man
• man printf
• man 3 printf
• man socket
• man -a printf
(모두 출력)
• man -k printf
(검색)
• man -k ^printf
(검색 -정규표현식)
11
파일편집기
기본 명령어 - 파일편집기 (vi / vim / nano)
vi hello.txt
vi /etc/passwd
nano hello.txt
nano /etc/passwd
sudo apt install vim : vi-improved 도구 설치
vimtutor : vi 학습기
