#include "stdio.h"
mount(int y,int x){ /*x=h[i]=height of each mountain*/
    int a,z,b,j;
        for(z=1;z<=y-1;z++){ /*y is for count the turn*/
            printf(" ");
        }
        printf("\\");
        while(z<=x-1){
            printf(" ");
            z++;
        }
        for(a=1;a<=x-y;a++){
            printf(" ");
        }
        printf("/");
        for(b=1;b<=y-1;b++){
            printf(" ");
        }
}

main()
{
    int i,n,max,t;
    int h[50],y;
    scanf("%d",&n); /*n=number of mount*/
    for(i=0;i<=n-1;i++){
        scanf("%d",&h[i]);
    }
    max=h[0];
    for(i=0;i<=n-1;i++){
        if(h[i]>max) max=h[i];
    }
    for(y=1;y<=max;y++){
        for(i=0;i<=n-1;i++){
            if(y<=h[i]){
                mount(y,h[i]);
            }
            else {for(t=1;t<=2*h[i];t++){ /*2 row for make complete mount*/
                printf(" ");
                }
            }
       }
     printf("\n");
    }

}
