#include "stdio.h"
main(){
    int r,col,opc;
    scanf("%d",&r);
    scanf("%d",&col);
    scanf("%d",&opc);
    int size=r*col;
    if(opc<=col){
        if(opc<r){
            for(int i=0;i<opc;i++){
                char ch='A'+(opc-1)+(i*(col-1));
                printf("%c",ch);
            }
        } else{
            for(int i=0;i<r;i++){
                char ch='A'+(opc-1)+(i*(col-1));
                printf("%c",ch);
            }
        }
    }
}

