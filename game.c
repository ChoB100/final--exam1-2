#include <stdio.h>
#include <string.h>
#include <termio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
int getch(void);
struct Player{
    char name[20];
    int x;
    int y;
    int stage;
};
void start();
int map2(struct Player p);//mola;
int blindmaze(struct Player p);//1stage.exe
void blindmap(char map[20][20]);//1stage map
int two(struct Player p,struct Player p2);//2stage.exe
void main(){
    struct Player p,p2;
    
    char cmd;
    int pick;

    intro:
    system("clear");
    p.x=1;
    p.y=1;
    p2.x=1;
    p2.y=20;
    
    fflush(stdin);
    start();
    pick=getch();
    if(pick=='x'){
        goto end ;
    }
    printf("\n                   Your Name:");
    scanf("%s",p.name);
    system("clear");
    printf("\n\n\n\n");
    printf("                             Loding..\n\n");
    printf("                    ########(      )(        )\n");
    sleep(1);
    system("clear");
    printf("\n\n\n\n");
    printf("                             Loding..\n\n");
    printf("                    ################(        )\n"); 
    sleep(1);
    system("clear");
    printf("\n\n\n\n");
    printf("                             Loding..\n\n");
    printf("                    ##########################\n");
    sleep(1);
    printf("Player : %s \n\n\n",p.name);
    blindmaze(p);//blindmaze fin
    two(p,p2);//two 게임 끝
    
   end:
   sleep(1);
   system("clear");
   printf("Game is Over ");
}//main끝

int getch(void){//getch함수

    struct termios oldt;
    struct termios newt;
    int ch;
    tcgetattr(STDIN_FILENO,&oldt);
    newt=oldt;
    newt.c_lflag &=~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
    return ch;
}//getch함수 끝
void start(){
    printf("########################################################################################\n");
    printf("###########                 #######     ######            ####                  ########\n");
    printf("##########    ###     ###   ######       ############    #####                  ########\n");
    printf("##########    ###     ###   #####  ###   ###########   #######   #######################\n");
    printf("##########    ###     ###   ####  #####  #########    ########   #######################\n");
    printf("##########    ###     ###   ###  ######  ########   ##########                  ########\n");
    printf("##########    ###     ###   ##            ######   ###########                  ########\n");
    printf("##########    ###     ###   #   #######   #####   ############   #######################\n");
    printf("##########    ###     ###   #  ########   ####            ####                  ########\n");
    printf("########################################################################################\n");
    printf("\n\n");
    printf("                                 UP:W                                            \n\n");
    printf("                    LEFT:A                RIGHT:D\n\n");
    printf("                                DOWN:S \n");
    printf("\n\n\n                  Press any button (press 'x' to Exit)");
}
int blindmaze(struct Player p){//재형이가 만든게임
    system("clear");
    int i,j,exit=0,mc=0;
    int count,count_cmd=0,cn;
    char map[20][20],cmd;
    char space=' ';
    p.x=p.y=2;
    blindmap(map);
    map[16][15]='&';//finish point
    printf("\n\n\n\n");
    printf("                        STAGE 1\n\n");
    printf("            Memorize the MAZE for '10' second\n");
    printf("       I.You'll lose your point everytime you hit the wall!\n");
    printf("       II.Take 'P' to the '&' !! \n");

    sleep(6);
    system("clear");
    printf("Name: %s\n",p.name);
    map[p.x][p.y]='P';
        for(i=0;i<20;i++){
            for(j=0;j<20;j++){
                printf("%2c",map[i][j]);
            }
            printf("\n");
        }
        sleep(5);
        while(1){
            map[p.x][p.y]='P';
            system("clear");
            printf("Player name : %s \n\n\n",p.name);
            for(i=0;i<20;i++){
                for(j=0;j<20;j++){
                    if((2<=i&&i<=17)&&(2<=j&&j<=17)){
                        if(map[i][j]=='#')
                            printf("%2c",space);
                        else
                            printf("%2c",map[i][j]);
                    }
                    else
                        printf("%2c",map[i][j]);
                }
                printf("\n");
            }
            cmd=getch();
            switch(cmd){
                case 'w':
                    if(p.x!=1&& map[p.x-1][p.y] != '#'&&map[p.x-1][p.y]!='@'){
                        count_cmd ++;
                        map[p.x][p.y]=' ';
                        p.x --;
                    }
                    else map[p.x-1][p.y]='@';
                    break;
                case 'a':
                    if(p.y!=1 && map[p.x][p.y-1]!= '#'&&map[p.x][p.y-1]!='@'){
                        count_cmd ++;
                        map[p.x][p.y]=' ';
                        p.y --;
                    }
                    else
                        map[p.x][p.y-1]='@';
                    break;
                case 's':
                    if(p.x != 18 && map[p.x+1][p.y]!= '#'&&map[p.x+1][p.y]!= '@'){
                        count_cmd ++;
                        map[p.x][p.y]=' ';
                        p.x ++;
                    }
                    else
                        map[p.x+1][p.y]='@';
                    break;
                case 'd':
                    if(p.y!= 18 && map[p.x][p.y+1]!='#'&&map[p.x][p.y+1]!='@'){
                        count_cmd ++;
                        map[p.x][p.y]=' ';
                        p.y ++;
                    }
                    else
                        map[p.x][p.y+1]='@';
                    break;
            }
            if(p.x==16 &&p.y==15){
                map[16][15]='P';
                map[17][15]=' ';
                system("clear");
                for(i=0;i<20;i++){
                    for(j=0;j<20;j++){
                        printf("%2c",map[i][j]);
                    }
                    printf("\n");
                }
            return 0;
            }
        }
return 0;
}
//재형이가 만든게임 끝
void blindmap(char map[20][20]){
    int i,j;

    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            map[i][j]=' ';
            if(i==19||i==18)
                map[i][j]='#';
            if(i==0||i==1||j==0||j==1||j==19||j==18){
                map[i][j]='#';
                } 
            }
        }
map[2][3]='#',map[2][16]='#',map[2][17]='#';
    map[3][3]='#',map[3][5]='#',map[3][7]='#',map[3][8]='#',map[3][10]='#',map[3][11]='#',map[3][12]='#',map[3][14]='#';
    map[4][3]='#',map[4][4]='#',map[4][8]='#',map[4][10]='#',map[4][11]='#',map[4][12]='#',map[4][13]='#',map[4][14]='#',map[4][15]='#',map[4][16]='#';
    map[5][6]='#',map[5][7]='#',map[5][10]='#',map[5][12]='#',map[5][17]='#';
    map[6][3]='#',map[6][4]='#',map[6][5]='#',map[6][9]='#',map[6][10]='#',map[6][12]='#',map[6][13]='#',map[6][15]='#';
    map[7][3]='#',map[7][4]='#',map[7][5]='#',map[7][7]='#',map[7][10]='#',map[7][13]='#',map[7][16]='#';
    map[8][4]='#',map[8][8]='#',map[8][9]='#',map[8][13]='#',map[8][15]='#';
    map[9][3]='#',map[9][6]='#',map[9][9]='#',map[9][11]='#',map[9][13]='#',map[9][16]='#';
    map[10][3]='#',map[10][5]='#',map[10][6]='#',map[10][7]='#',map[10][8]='#',map[10][11]='#',map[10][14]='#',map[10][16]='#';
    map[11][3]='#',map[11][10]='#',map[11][11]='#',map[11][12]='#',map[11][16]='#';
    map[12][3]='#',map[12][5]='#',map[12][7]='#',map[12][8]='#',map[12][10]='#',map[12][15]='#';
    map[13][3]='#',map[13][4]='#',map[13][5]='#',map[13][6]='#',map[13][7]='#',map[13][8]='#',map[13][9]='#',map[13][11]='#',map[13][13]='#',map[13][14]='#';
    map[14][11]='#',map[14][13]='#',map[14][16]='#';
    map[15][3]='#',map[15][5]='#',map[15][7]='#',map[15][8]='#',map[15][11]='#',map[15][12]='#',map[15][15]='#';
    map[16][8]='#',map[16][9]='#',map[16][11]='#',map[16][12]='#',map[16][13]='#',map[16][14]='#',map[16][16]='#';
    map[17][4]='#',map[17][6]='#',map[17][14]='#';
};//블라인드메이즈 맵 완성
int two(struct Player p,struct Player p2){//병욱이가 만든 게임
    char map[20][40];
    int i,j;
    char cmd;
    for(i=0;i<20;i++){
        for(j=0;j<40;j++){
            map[i][j]=' ';
            if(j==39)
                map[i][j]='#';
            if(i==19)
                map[i][j]='#';
            if(i==0||i==0||j==0||j==19||(i==19&&j==19)){
                map[i][j]='#';
            } 
        }
    }//초기 맵 설정
    
        for(i=0;i<60;i++){
            
            map[rand()%20][rand()%20]='#';
            map[rand()%20][rand()%20+20]='#';
        }
    //for(i=3;i<10;i++){
   //     map[i][5]='#';
    //}
    //장애물(추후에 랜덤함수이용해서 할꺼임
    system("clear");
    printf("\n\n\n\n");
    printf("                        STAGE 2\n\n");
    printf("            You can't stop 'P' until you hit the wall!\n");
    printf("           I.'P' and 'D' move at a time\n");
    printf("          II.Take 'P'and'D' to &!!\n");
    sleep(4);

    while(1){
        system("clear");
        printf("Player: %s \n\n\n",p.name);
        map[p.x][p.y]='P';
        map[p2.x][p2.y]='D';
        map[18][18]='&';
        map[18][38]='&';
        for(i=0;i<20;i++){
            for(j=0;j<40;j++){
                
                printf("%2c",map[i][j]);
            }
            printf("\n");
        }//맵 출력
        if(p.x==18&&p.y==18&&p2.x==18&&p2.y==38){//클리어 조건
            system("clear");
            p.x=1,p.y=1;
            p2.x=1,p2.y=19;
            printf("==========Clear!!==========\n");
            sleep(2);
            return 0;
        }
        cmd=getch();

        switch(cmd){
            case 'w':
                if(p.x!=1&&map[p.x-1][p.y]!='#'){
                    map[p.x][p.y]=' ';
                    while(map[p.x-1][p.y]!='#'){
                        p.x--;
                    }
                }
                if(p2.x!=1&&map[p2.x-1][p2.y]!='#'){
                    map[p2.x][p2.y]=' ';
                    while(map[p2.x-1][p2.y]!='#'){
                        p2.x--;
                    }
                }
                break;
            case 'a':
               if(p.y!=1&&map[p.x][p.y-1]!='#'){
                   map[p.x][p.y]=' ';
                    while(map[p.x][p.y-1]!='#'){
                        p.y--;
                    }
               }
               if(p2.y!=1&&map[p2.x][p2.y-1]!='#'){
                   map[p2.x][p2.y]=' ';
                    while(map[p2.x][p2.y-1]!='#'){
                        p2.y--;
                    }
               }
                break;
             case 's':
                 if(p.x!=18&&map[p.x+1][p.y]!='#'){
                     map[p.x][p.y]=' ';
                      while(map[p.x+1][p.y]!='#'){
                        p.x++;
                      }
                 }
                 if(p2.x!=18&&map[p2.x+1][p2.y]!='#'){
                     map[p2.x][p2.y]=' ';
                      while(map[p2.x+1][p2.y]!='#'){
                        p2.x++;
                      }
                 }
                break;
            case 'd':
                if(p.y!=18&&map[p.x][p.y+1]!='#'){
                    map[p.x][p.y]=' ';
                    while(map[p.x][p.y+1]!='#'){
                        p.y++;
                    }
                }
                if(p2.y!=18&&map[p2.x][p2.y+1]!='#'){
                    map[p2.x][p2.y]=' ';
                    while(map[p2.x][p2.y+1]!='#'){
                        p2.y++;
                    }
                }
                break;
        }//플레이어 이동
    }
}
