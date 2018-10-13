#include "stdio.h"
void up(int a);
void down(int a);
main(){
    int row;
    scanf("%d",&row);
    up(row);
    for(int i=1;i<=row;i++){
        printf(" ");
    }
    printf("1");
    for(int i=1;i<=(row*2)-1;i++){
        printf("=");
    }
    printf("A");
    printf("\n");
    down(row);
}
void up(int row){

    int varrow=row;
    for(int i=1;i<=row-1;i++){
        for(int j=1;j<=i;j++){
            printf("-");
        }
        int d=varrow%10;
        //varrow-=1;
        printf("%d",d);
        for(int k=1;k<=(2*(varrow-1)-1);k++){
            printf("+");
        }
        //int e=varrow%10;
        printf("%d",d);
        for(int j=0;j<=2*(i-1);j++){
            printf("-");
        }
        printf("%c",'A'+((varrow-1)%26));
        for(int k=1;k<=(2*(varrow-1)-1);k++){
            printf("+");
        }
        printf("%c",'A'+((varrow-1)%26));
        varrow-=1;
        printf("\n");
    }
}

void down(int row)
{
    int varrow=row;
    int num=2;
    for(int i=row-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("-");
        }
        printf("%d",num%10);

        for(int j=1;j<=(2*(num-1))-1;j++){
            printf("+");
        }
        printf("%d",num%10);

        for(int k=1;k<=(2*(varrow-1)-1);k++){
            printf("-");
        }
        varrow-=1;
        printf("%c",'A'+((num-1)%26));
        for(int j=1;j<=(2*(num-1))-1;j++){
            printf("+");
        }
        printf("%c",'A'+((num-1)%26));
        num+=1;
        printf("\n");
    }
}
