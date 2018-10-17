#include "stdio.h"
main(){
    char ch[10000];
    char ch2[1000000];
    int c=0;
    int len=0;
    //int keb=0;
    int cpr;
    int row;
    scanf("%s",ch);
    scanf("%d",&cpr);
    scanf("%d",&row);
    //printf("%c",ch[3]);
    while(ch[c]!='\0'){
        len++;
        c++;
    }
    int keb=cpr*row;
    for(int u=0;u<keb;u++){
        int u2=u;
        if(u2>len-1){
            u2=u2%(len);
        }
        ch2[u]=ch[u2];
    }
    //printf("%s",ch2);
    //printf("%d",len);
    int op=0;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=cpr;j++){
            printf("%c",ch2[op]);
            op++;
        }
        printf("\n");
    }
}
