#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
int sendsum(int row);
int main(){
    int row;
    scanf("%d",&row);
    if(row<4){
        printf("0");
    }
    else {
        int ans=sendsum(row);
        printf("%d",ans);
    }

}
int sendsum(int row){
    int sum=0;
    //int oprow=3;
    for(int op=3;op<row;op++){
        for(int op2=0;op2<=op-3;op2++){
            sum=sum+(2+op2);
        }
    }
    return sum;
}
