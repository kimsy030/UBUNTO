#include <stdio.h>

typedef struct swInfo
{
  char swName[256];
  char swArgv[4][256];
}

void readFileList()
{
  while(!EOF)
  {
    		// FileList File로부터 S/W 정보를 한 줄 씩 획득한다.
    		// 획득한 S/W 정보를 “;”을 token으로하여 분리한다.
	        // 공백을 삭제한 후 swInfo structure에 저장한다.
  }
}

typdef struct SwfirstInfo
｛
		struct SwInfo swInfo; //블록 정보
		pid_t_swpid; //pid
		time_t start_time; //초기화 시간
		int status; // 초기화 사유
		int restar_count; //초기화 회수
       int need_start;
}

char* reason_ToString(int status){
	if(status == -9999){
			//status값이 초기값인 –9999이면 init을 return
	}
	if(WIFEXITED(status))// 자식이 정상적으로 종료
	{
			// status 값이 정상 종료된 프로세스면
			// “Exit(WEXITSTATUS(status))”를 return
	}else if(WIFSIGNALED(status)){ //참을 반환
			//status 값이 signal로 종료된 프로세스면
			//“Signal( WTERMSIG(status, 
                      //strsignal(WTERMSIG(status))“를 반환
	}
}

int writeSwLog(struct SwfirstInfo swfirstInfo)
{
	// SwfirstInfo안에 있는 정보중 swName, startTime
	//status 값을 reason_ToString함수로 문자열로 바꾼 값인
	// restart_count 값을 ./log/restart.txt에 출력한다.
}

int swInitStart(int swBlock_Conunt, struct SwInfo* swInfos, struct SwfirstInfo* swfirstInfo)
{
	for(int i = 0; i < swBlock_Count; i++)
	{
		// swFork_Exec 함수로 SwInfo structure의 I번째 인덱스에 
		해당하는
		//S/W 블록을 argument와 함께 초기화한다.
		if(pid < 0) return -1;
		//SwfirstInfo structure array의 I번째 인덱스에 해당하는 
		//요소의 swInfo 멤버 변수의 S/W 블록 정보를 초기화 
		//./log/restart.txt에 기록  
	} 
	return 0;
}

int swFork_Exec(const char* swName, char argv[4][256])
{
	//fork를 이용해  자식 프로세서 생성 
	if(pid == 0)
	{
		//execl 함수를 통해 swBlock을 argv와 함께 초기화 
	 } else if(pid > 0){
	 	return pid;
	 }
	 return -1;
}

int swRestart(struct SwfristInfo* swfirstInfo)
{
	// 인자로 받은 S/W 블록을 초기화
	pid = swFork_Exec();
	if(pid < 0) return -1;
	//pid 및 현재시간 대입후 restart_count 멤버 변수 1증가 
	// writeSwLog를 이용하여 재초기화 정보 기록 
	return 0; 
}

int printSwfirstInfos(int swBlockCount, struct SwEarlyInfo* swEarlyInfo)
{
	for(int i = 0; i < swBlockCount; i++)
	{
		//SwfirstInfo structure array의 i번째 요소
		//swName, startTime, status, restartCount 값을 출력  
	}
	return 0;
}
