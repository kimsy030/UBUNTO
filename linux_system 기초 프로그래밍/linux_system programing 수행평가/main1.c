#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct Swfirstinfo
{
    pid_t swpid; //pid
    char *Swname; // 블록 이름
    char *des[3]; // description
    int des_len;  // description length
    int restart_count; //초기화 회수
    char *start_time; //시작 시간
    char status[256]; // 초기화 사유
} swfirstinfo;

int list_len = 0;              // Sw블록 리스트의 길이
swfirstinfo **FileList(char *);     // Value을 담을 리스트, 리스트 길이, 읽을 파일명
swfirstinfo **swInitStart(swfirstinfo **); // 초기화할 리스트, 길이
void printSwfirstinfo(swfirstinfo **); // 리스트의 정보를 출력
void setandcontrol(swfirstinfo **); // 프로세스 동작 설정 및 부모 프로세스 제어
void swRestart(swfirstinfo **, pid_t, int); // 재시작
bool checkparent(swfirstinfo**); // 리스트 모두 검사해서 부모 프로세스인지 판별
int signallist[10] = {SIGKILL, SIGABRT, SIGALRM, SIGKILL, SIGABRT, SIGALRM, SIGKILL, SIGABRT, SIGALRM, SIGINT};


int main(int argc, char **argv)
{
    int i, j;
    if (argc != 2)
    {
        printf("사용법: %s <childprocess_blocklist>\n", argv[0]);
        return -1;
    }
    swfirstinfo **swfirstinfolist; // main 리스트

    swfirstinfolist = FileList(argv[1]);       // 리스트 파싱(파일명)
    swfirstinfolist =swInitStart(swfirstinfolist); // 리스트 초기화(리스트)
    setandcontrol(swfirstinfolist);            // 리스트 제어(리스트)
    return 0;
}

swfirstinfo **FileList(char *filename)// 리스트 파싱(파일명)
{ 
    swfirstinfo **filelist;
    char **linelist = malloc(sizeof(char *) * 10);
    char *buf, *temp;
    int fd, err, i, j;
    off_t size;

    if ((fd = open(filename, O_RDONLY, 0644)) == -1)
    {
        printf("파일[%s]을 열 수 없습니다!\n", filename);
        exit(-1);
    }

    if ((size = lseek(fd, 0, SEEK_END)) == -1)
    {
        printf("파일 디스크립터[%d]를 옮기는 과정에서 에러가 발생하였습니다!\n", fd);
        exit(-1);
    }

    if ((err = lseek(fd, 0, SEEK_SET)) == -1)
    {
        printf("파일 디스크립터[%d]를 옮기는 과정에서 에러가 발생하였습니다!\n", fd);
        exit(-1);
    }

    buf = malloc(sizeof(char) * size + 1);

    if (read(fd, buf, size + 1) == -1)
    {
        printf("파일 디스크립터[%d]를 읽는 과정에서 에러가 발생하였습니다!\n", fd);
        exit(-1);
    }

    temp = strtok(buf, "\n");

    for (i = 0; temp != NULL; (temp = strtok(NULL, "\n")), i++)
    {
        linelist[i] = malloc(strlen(temp));
        strcpy(linelist[i], temp);
    }

    list_len = i;
    filelist = malloc(sizeof(swfirstinfo *) * list_len);

    for (i = 0; i < list_len; i++)
    {
        filelist[i] = malloc(sizeof(swfirstinfo));
        temp = strtok(linelist[i], ";");
        filelist[i]->Swname = malloc(strlen(temp));
        strcpy(filelist[i]->Swname, temp);
        filelist[i]->des_len = 0;

        for (j = 0; j < 3; j++)
        {
            temp = strtok(NULL, ";");
            if (temp == NULL)
                break;
            filelist[i]->des[j] = malloc(strlen(temp));
            strcpy(filelist[i]->des[j], temp);
            filelist[i]->des_len++;
        }

        free(linelist[i]);
    }
    free(linelist);
    free(buf);
    close(fd);
    return filelist;
}

swfirstinfo **swInitStart(swfirstinfo **init_list)//초기화 함수
{
    int i;
    time_t now;
    struct tm *nowinfo;
    for (i = 0; i < list_len; i++)
    {
        init_list[i]->swpid = fork();

        if (init_list[i]->swpid == 0) // 자식 프로세스 반복문 빠져나옴
            break;
        if (init_list[i]->swpid == -1)// 에러 시 프로그램 종료
        { 
            printf("SW블록[%d] 초기화 에러!\n", i);
            exit(-1);
        }

        now = time(NULL);
        nowinfo = localtime(&now);
        init_list[i]->restart_count = 0;
        init_list[i]->start_time = malloc(sizeof(char) * strlen("XXXX.XX.XX. XX:XX:XX"));
        sprintf(init_list[i]->start_time, "%04d.%02d.%02d. %02d:%02d:%02d", nowinfo->tm_year + 1900, nowinfo->tm_mon + 1, nowinfo->tm_mday, nowinfo->tm_hour, nowinfo->tm_min, nowinfo->tm_sec);
        memset(init_list[i]->status, '\0', sizeof(init_list[i]->status));
        strcpy(init_list[i]->status, "Init.");
    }
    if (checkparent(init_list))
        printSwfirstinfo(init_list);
    return init_list;
}

void setandcontrol(swfirstinfo **list)
{
    if(checkparent(list)) {
        pid_t pid;
        int status;
        while(1) {
            pid = waitpid(-1, &status, WUNTRACED);
            swRestart(list, pid, status);
        }
    }
    else {
        int i;
        for(i = 0; i < list_len; i++) {
            if(list[i]->swpid == 0) {
                sleep(5*i+5);
                kill(getpid(), signallist[i]);
                break;
            }else
                continue;
        }
    }
    return;
}

void printSwfirstinfo(swfirstinfo **list)
{
    int i;
    printf("=========================================================================\n");
    printf("|    NAME    |    Restart Count    |     Start Time       |   status    |\n");
    printf("|------------|---------------------|----------------------|-------------|\n");
    for (i = 0; i < list_len; i++)
    {
        printf("|%11s |%20d |%21s | %11s |\n", list[i]->Swname, list[i]->restart_count, list[i]->start_time, list[i]->status);
        if (i + 1 == list_len)
            continue;
        else
            printf("|------------|---------------------|----------------------|-------------|\n");
    }
    printf("=========================================================================\n");
    return;
}

void swRestart(swfirstinfo** list, pid_t target_pid, int status) {
    int i, signal;
    for(i = 0;i < list_len; i++) {
        if(list[i]->swpid == target_pid) {
            memset(list[i]->status, '\0', sizeof(list[i]->status));
            if(WIFEXITED(status)) {
                sprintf(list[i]->status, "Exit(%d)", WEXITSTATUS(status) >> 8);
            }
            else if(WIFSIGNALED(status)) {
                signal = WTERMSIG(status);
                sprintf(list[i]->status, "Signal(%s)", strsignal(signal));
            }
            list[i]->restart_count++;
            list[i]->swpid = fork();
            if(checkparent(list)) {
                int fd;
                time_t now = time(NULL);
                struct tm *nowinfo = localtime(&now);
                char * finalbuf = malloc(sizeof(char)*500);

                sprintf(finalbuf, "--------------------\nSW 명: %s\n재기동 시점: %04d.%02d.%02d. %02d:%02d:%02d\n재기동 사유: %s\n재기동 회수: %d\n-------------------\n", list[i]->Swname, nowinfo->tm_year + 1900, nowinfo->tm_mon + 1, nowinfo->tm_mday, nowinfo->tm_hour, nowinfo->tm_min, nowinfo->tm_sec, list[i]->status, list[i]->restart_count);
                finalbuf = realloc(finalbuf, strlen(finalbuf));

                mkdir("log", 0777);
                fd = open("log/restart.txt", O_CREAT|O_WRONLY|O_APPEND, 0644);
                write(fd, finalbuf, strlen(finalbuf));
                
                close(fd);
                free(finalbuf);

                system("clear");
                printlistinfo(list);
            }else {
                sleep(5*i+5);
                kill(getpid(), signallist[i]);
            }
            break;
        }
    }
    return;
}

bool checkparent(swfirstinfo** list) {
    bool test = true;
    int i;
    for(i = 0; i < list_len; i++)
        test = test && list[i]->swpid > 0;
    return test;
}
