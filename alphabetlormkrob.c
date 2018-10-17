#include "stdio.h"
main(){
    int row;
    char ch='A';
    int op=0;
    int temp;
    scanf("%d",&row);
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            ch='A'+(op%26);
            printf("%c",ch);
            op+=1;
        }
        printf("\n");
    }
    ch='A';
    if(row>=4){
        for(int opr=3;opr<row;opr++){
            if(opr==3){
                ch=ch+4;
                printf("%c",ch);
            }
            else{
                printf("%c",ch);
                for(int i=1;i<=opr-3;i++){
                        if(ch+1>'Z'){
                            ch='A';
                            printf("%c",ch);
                        }
                        else{
                            ch=ch+1;
                            printf("%c",ch);
                        }
                }
            }
            ch=ch+3;
        }
    }
}
