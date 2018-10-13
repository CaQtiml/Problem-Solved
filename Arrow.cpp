#include "stdio.h"
void leftup(int a,int b);
void leftdown(int a,int b);
void rightup(int a,int b);
void rightdown(int a,int b);
main(){
    char cmd;
    int a;
    int b;
    scanf("%c",&cmd);
    if(cmd=='L'||cmd=='l'){
        scanf("%d",&a);
        scanf("%d",&b);
        leftup(a,b);
        leftdown(a,b);
    }
    if(cmd=='R'||cmd=='r'){
        scanf("%d",&a);
        scanf("%d",&b);
        rightup(a,b);
        rightdown(a,b);
    }
}
void leftup(int a,int b){
    int active=a-b;
    int active2=b-a;
    int varb=b;
    int vara=a;

        if(a<b){
            for(int y=1;y<=active2;y++){
                for(int i=1;i<=varb;i++){
                printf(" ");
                }

                printf("/");
                    varb--;
                    printf("\n");
            }
            int conb=varb;
            for(int j=1;j<=conb;j++){
                for(int k=1;k<=varb-1;k++){
                    printf(" ");
                }
                varb--;
                printf("//");
                printf("\n");
            }
        }



        else{
            for(int i=1;i<=a;i++){
                for(int j=1;j<=vara-1;j++){
                    printf(" ");
                }
                printf("/");
                if(active>0){
                    active--;
                }
                else{
                    printf("");
                    printf("/");
                }
                printf("\n");
                vara--;
            }
        }
}

void leftdown(int a,int b){
    if(a<=b){
        int t=0;
        for(int i=0;i<b;i++){
            for(int j=0;j<i;j++){
                printf(" ");
            }
            if(t<a){
                printf("\\\\");
                t++;
            }
            else{
                printf(" \\");
                t++;
            }
            printf("\n");
        }
    }
    else{
        int t=1;
        for(int i=0;i<a;i++){
            for(int j=0;j<i;j++){
                printf(" ");
            }
            if(t<=b){
                printf("\\\\");
                t++;
            }
            else{
                printf("\\");
                t++;
            }
            printf("\n");
        }

    }
}

void rightup(int a,int b){
    if(a>b){
        int t=1;
        for(int i=1;i<=a;i++){
            for(int j=0;j<i;j++){
                printf(" ");
            }
            if(t<a-b+1){
                printf("\\");
                t+=1;
            }else{
                printf("\\\\");
                t+=1;
            }
            printf("\n");
        }
    }

    else{
        int vara=1;
        for(int i=1;i<=b;i++){
            for(int j=0;j<i;j++){
                printf(" ");
            }
            if(a==b){
                printf("\\\\");
            }
            else if(vara<=b-a){
                printf(" \\");
                vara++;
            }
            else if(vara>b-a){
                printf("\\\\");
                vara++;
            }
            printf("\n");
        }
    }

}

void rightdown(int a,int b){
    if(a<b){
        int varrow=b;
        int t=1;
        for(int i=1;i<=b;i++){
            for(int j=1;j<=varrow;j++){
                printf(" ");
            }
            if(t<=a){
                printf("//");
                t+=1;
            }else{
                printf(" /");
                t+=1;
            }
            varrow-=1;
            printf("\n");
        }
    }
    else{
        if(a==b){
            int y=1;
            for(int i=1;i<=a;i++){
                for(int j=y;j<=a;j++){
                    printf(" ");
                }
                printf("//");
                printf("\n");
                y+=1;
            }
        }
        else{
            int vara=a;
            int t=0;
            for(int i=1;i<=a;i++){
                for(int j=1;j<=vara;j++){
                    printf(" ");
                }
                if(t<=b-1){
                    printf("//");
                    t++;
                }
                else{
                    printf("/");
                    t++;
                }
                vara-=1;
                printf("\n");
            }
        }
    }
}
//COPYRIGHT 2018
//SIVAKORN LERTTRIPINYO