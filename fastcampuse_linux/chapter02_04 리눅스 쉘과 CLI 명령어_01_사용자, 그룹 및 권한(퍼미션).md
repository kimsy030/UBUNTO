사용자와 권한 관련 명령어
• 계정 종류 :
• root 유저와 사용자 계정
• 계정 살펴보기 /etc/passwd, /etc/shadow, /etc/group
• 내 권한 (whoami, id)
• 그룹 계정 및 권한(sudoer & sudo) 
• 사용자 생성과 그룹 생성 (adduser, useradd, usermod, deluser, userdel, addgroup, delgroup)
• 파일 권한 다루기 (chmod, chown, chgrp, umask)
• 파일 다루기 상급
• setuid, setgid
02-1
사용자 유형
사용자 계정 - superuser 와 user
슈퍼유저란?
시스템 운영 관리자 계정으로 일반적으로 리눅스 운영체제에서는 루트(root) 유저를 말한다.
관리자 권한을 일반 사용자 권한과 구분하며 사용자의 부주의로 발생하는 시스템 손상과 바이러스, 
악성코드의 침입에 의한 피해를 보호한다.
• whoami - 내가 누구인지 내 계정 확인
• id - 내가 갖고 있는 권한 (포함된 그룹) 확인
꼭 강조…
내가 관리하는 PC 라도,
나는 슈퍼유저가 아니다!!
02-2
사용자 유형
사용자 계정 - 권한 조사
• whoami
• id
02-3
사용자 유형
사용자 계정 - 권한의 대여
• sudo
슈퍼유저(superuser) 의 권한을 수행(do) 한다.

02-4
사용자 유형
사용자 계정 - 권한의 대여 - sudoer
• sudo visudo
슈퍼유저의 권한을 편집
설정파일을 통한 변경
• 사용자 권한
• %그룹 권한
설정파일 상세
• 계정명 호스트명=(실행계정명) 명령어
• user1 ALL=(ALL) /sbin/ifconfig
사용자를 sudo 권한에 추가
• useradd -aG user1 sudo (Ubuntu)
• useradd -aG user1 wheel (Amazon AMI)
02-5
사용자 유형
사용자 계정 - 권한의 대여 - su
su [username]
사용자의 권한을 대여 (즉, 사용자로 로그인 한 것과 같은 효과)
언제 사용하느냐? 관리자가 사용자 계정을 관리하고 이슈/장애를 분석 할 때
사용방법:
• su user2
user2의 id로 로그인 한다 (user2의 pw 필요)
• su - user2
user2 의 id로 로그인 한다 (user2의 pw 필요, user2 의 home 디렉토리 사용)
• su 혹은 su root
root 의 id 로 로그인 한다 (root의 pw 필요. 하지만 우분투는 root 암호 비활성화.)
• sudo su
내 권한을 상승하여 root 사용자의 권한으로 로그인 한다 (현재 디렉토리 사용)
• sudo su -
내 권한을 상승하여 root 사용자의 권한으로 홈 디렉토리 사용 (root의 home)
• sudo su - user2
user2 사용자의 권한으로 홈 디렉토리 사용 (sudoer(user1)의 pw 필요, user2 의 home)
03-1
사용자 계정과
그룹 유형 사용자 계정과 그룹 계정
• cat /etc/passwd : 사용자 계정 확인
• cat /etc/shadow : 사용자 암호
• cat /etc/group : 사용자 그룹 확인
03-2
사용자 계정과
그룹 유형 사용자 계정과 그룹 계정 - 사용자 계정 (/etc/passwd)
• cat /etc/passwd : 사용자 계정 확인
사용자명 패스워드 계정 UID 계정 GUI 이름 홈 디렉토리 로그인 쉘
root x 0 0 root /root /bin/bash
user1 x 1000 1000 user1,,, /home/user1 /bin/bash
www-data x 33 33 www-data /var/www /usr/sbin/nologin
0 : root
1 ~ 99 : predefined
100 ~ 999 : administrative and
system accounts
1000 ~ : user
슈퍼유저
사용자
서비스 계정
03-3
사용자 계정과
그룹 유형 사용자 계정과 그룹 계정 - 사용자 계정 (/etc/shadow)
• cat /etc/shadow : 사용자 암호
• 리눅스(유닉스)의 모든 시간 epoch = 1970년 1월 1일 00:00:00 UTC
사용자명 패스워드 최종
수정일
패스워드
최소 변경일
패스워드
최대 사용일
패스워드 만료
경고기간
패스워드
유예 기간
계정 만료
기간
예약필드
root ! 18357 0 99999 7
user1 $6$x0de2… 18357 0 99999 7
www-data * 17953 0 99999 7
! : locked
$1$ : MD5
$2a$ : Blowfish
$2y$ : Blowfish
$5$ : SHA-256
$6$ : SHA-512
04-1
사용자 계정
사용자 추가 (adduser - add user)
adduser [options] [--home DIR] [--shell SHELL] [--disabled-password] [--disabled-login] user
새로운 사용자 추가
04-2
사용자 계정
사용자 추가 (useradd - user add with default (none-dialog 방식) / adduser 의 아래 레벨 실행파일)
useradd [options] user
사용자 (기본값으로) 추가
• useradd user3 : 사용자 user3 추가
• useradd -D : 사용자 생성 기본값 확인
• useradd -D -b /usr : 사용자 기본 홈 디렉토리 /usr 로 변경
• useradd -D -s /bin/bash : 사용자 기본 쉘 bash로 변경
• useradd -D -e 2020-12-31 : 사용자 계정 만료일 설정
참고: 계정 생성시 참조하는 파일들
• /etc/default/useradd
• /etc/login.defs
• /etc/skel/
04-3
사용자 계정
사용자 암호 정책 변경 / 암호 변경 (chage - change age / passwd)
chage [option] user
사용자 암호 정책 변경
• passwd [options] user : 암호변경
• passwd -l user : 계정 잠금
• passwd -u user : 계정 잠금 해제
• passwd -S user : 계정 상태 확인
• passwd -n <mindays> user : 암호 최소 기간
• passwd -x <maxdays> user : 암호 최대 기간
• man passwd
• chage user2 : 암호 정책 변경
• chage -l user2 : 암호 정책 확인
• chage -E 2020-12-31 -m 1 -M 90 -W 7 user2
04-3
사용자 계정
사용자 삭제 (deluser - delete user)
deluser [options] user
사용자 계정 삭제
userdel user
none-interactive 모드로 모두 삭제
• deluser user2
• deluser user2 --remove-home
새로운 사용자를 동일ID 로 만들경우, 
이전 디렉토리에 맵핑
• userdel user2 : 사용자 계정 삭제 (홈 삭제)
• userdel -f user2 : 로그인 중이더라도 삭제
05
-
1
그룹 계정
그룹 생성
(addgroup
- add group)
addgroup [options] group
그룹 계정 생성
groupadd [options] group
실제 addgroup
의 바이너리
05-2
그룹 계정
그룹 삭제 (delgroup - delete group)
delgroup [options] group
그룹 계정 삭제
05-3
그룹 계정 / 
사용자 계정 그룹 계정 / 사용자 할당 (또는 사용자 정보 수정) (usermod - user mod)
usermod [options] user
사용자 계정 정보 수정 (moduser 는 없음 (interactive 방식인…))
사용자를 그룹에 추가
• usermod -c <name change> user2 : 사용자 이름 수정
• usermod -a -G sudo user2 : user2 를 sudo 그룹에 추가
adduser user2 sudo : user2 를 sudo 그룹에 추가
• deluser user2 sudo : user2를 sudo 그룹에서 제거
(실행후 결과 번역 오류) 
Removing user ‘user2’ from group ‘sudo’ …
Done.
06-1
파일의 권한
파일의 권한
사용자 접근 권한의 구분
소유자(User) / 그룹(Group) / 그외 (Other)
User Group Other
읽기 쓰기 실행 읽기 쓰기 실행 읽기 쓰기 실행
r w x r w x r w x
4 2 1 4 2 1 4 2 1
r : read
w : write
x : execute
합산 : 7 7 7
유형 (d = directory, l = link)
권한
링크수
소유자
그룹
파일크기
변경일자
이름 0 --- : 권한무
1 --x : 실행
2 -w- : 쓰기
3 -wx : 쓰기 & 실행
4 r-- : 읽기
5 r-x : 읽기 & 실행
6 rw- : 읽기 & 쓰기
7 rwx : 읽기 & 쓰기 & 실행
06-2
파일의 권한
파일의 생성 권한 (umask - user mask)
파일/디렉토리 생성 권한의 확인
소유자(User) / 그룹(Group) / 그외 (Other)
• 리눅스의 기본 파일 권한: 666
• 리눅스의 기본 디렉토리 권한: 777
이 말은, umask 가 0 일 경우 새로 생성되는 파일의 권한은 666 (rw-rw-rw-) 을 갖게 됨)
디렉토리 권한은 777 (rwxrwxrwx) 을 갖게 됨
여기서, umask 가 2 (혹은 0002) 일 경우에는
파일 기본권한 666 에서 002를 빼면
• 110 110 110 = 666
• 000 000 010 = 002
• 110 110 100 = 664, 즉 rw-rw-r-- 로 생성 됨
디렉토리 기본권한 777 에서 002를 빼면
• 111 111 111 = 777
• 000 000 010 = 002
• 111 111 101 = 775, 즉 rwxrwxr-x 로 생성 됨
06-3
파일의 권한
파일의 권한 - 권한 변경 (chmod - change mode)
chmod [OPTION]… [MODE]… file…
파일/디렉토리 권한의 변경
소유자(User) / 그룹(Group) / 그외 (Other)
• chmod 777 hello.txt : 숫자값을 통한 user/group/other 에 rwx 권한 부여
• chmod 700 hello.txt : 숫자값을 통한 user 에 rwx 권한 부여 (group/other 에는 --- 권한 부여)
• chmod u+x hello.txt : user 에 x(실행) 권한 추가
• chmod u-x hello.txt : user 에 x(실행) 권한 삭제
• chmod g+rw hello.txt : group 에 rw(읽기/쓰기) 권한 추가
• chmod g-rx hello.txt : group 에 rw(읽기/쓰기) 권한 삭제
• chmod o+rwx hello.txt : other 에 rwx(읽기/쓰기/실행) 권한 추가
• chmod o-rwx hello.txt : other 에 rwx(읽기/쓰기/실행) 권한 삭제
• chmod +x hello.txt : user/group/other 에 x(실행) 권한 추가
06-4
파일의 권한
파일의 권한 - 소유권 변경 (chown - change owner, chgrp - change group)
chown [OPTION]… [USER][:GROUP] FILE…
파일/디렉토리의 소유자/그룹 변경
chgrp [OPTION]… [GROUP] FILE…
파일/디렉토리의 그룹 변경
소유자(User) / 그룹(Group) / 그외 (Other)
• chown user2 hello.txt : 해당 파일(hello.txt) 의 소유자를 user2 로 변경
• chown user2:user2 hello.txt : 해당 파일(hello.txt) 의 소유자와 그룹을 모두 user2 로 변경
• chown :user2 hello.txt : 해당 파일(hello.txt) 의 그룹을 user2 로 변경
• chgrp user2 hello.txt : 해당 파일(hello.txt) 의 그룹을 user2 로 변경
07-1
특수 실행 권한
파일의 특수 실행 권한 (setuid, setgid, sticky bit)
파일의 권한을 일시적으로 소유주(setuid) 혹은 소유그룹(setgid)의 권한으로 빌려서 실행함
Sticky bit은 해당 디렉토리에 생성된 파일은 해당 사용자의 소유주로 저장됨
소유자(User) / 그룹(Group) / 그외 (Other)
• SetUID 는 4xxx, SetGID 는 2xxx 로, StickyBit 은 1xxx 로 설정한다.
각각 설정 위치는 rws------, rwxrws---, drwxdrxdwt 로 표시된다.
• 기존 권한의 위치에 덮어쓰기 때문에, 해당 기능만 존재할 경우 대문자 S/S/T 로 표기 된다.
각각 설정 위치는 rwS------, rwxrwS---, drwxdrxdwT 로 표시된다.
기존 권한 (실행권한) 을 포함하고 있는 경우 소문자 s/s/t로 표시된다.
• chmod u+s filename
• chmod g+s filename
• chmod +t directoryname
07-2
특수 실행 권한
파일의 특수 실행 권한 (setuid, setgid, sticky bit)
(다소 복잡한) 실습
시나리오 : 두명의 사용자가 있고, user1 이 만든 읽기 전용 파일에 user2 가 setuid 권한을 통해 접근
user1, user2 두명의 사용자
• user1의 readonly 파일 생성
• /bin/cat 을 복사해서 mycat 으로 생성 및 setuid 를 통해 실행 권한을 부여
• user2 가 readonly 파일을 직접 읽을 수는 없지만,
• setuid 가 실행된 파일로는 읽을 수 있음
