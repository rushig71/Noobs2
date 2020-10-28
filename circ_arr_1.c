#include<stdio.h>
#include<stdlib.h>
#define max 100

void show(int array[],int t,int f){
    if(t>f){
        for(int x=f;x<=t;x++){
            printf("%d ",array[x]);
        }
    }
    else if(f>t){
        for(int x=f;x<max;x++){
            printf("%d ",array[x]);
        }
        for(int x=0;x<=t;x++){
            printf("%d ",array[x]);
        }
    }
    printf("\n");
}
int overflow(int f,int t){
    if(t==max-1&&f==0){
        printf("\n\nOVERFLOW\n\n");
        return 0;
    }
    else if(t==f-1){
        printf("\n\nUNDERFLOW\n\n");
        return 0;
    }
    else{return 1;}
}
int underflow(int f, int t){
    if(f==t){
        return 0;
    }
    else{return 1;}
}
    //add_start
void start(int array[],int f,int t,int value){
    switch(overflow(f,t)){
        case 1:
        array[f]=value;
        if(t<max-1){t++;}
        else{t=0;}
        break;
        case 0:
        return;
    }
}
    //add_last
void push(int array[],int f,int t, int value){
    switch(overflow(f,t)){
        case 1:
        array[t]=value;
        if(t<max-1){t++;}
        else{t=0;}
        case 0:
        return;
    }
}
    //delete_start
int delete(int array[],int f,int t){
    int value;
    switch(underflow(f,t)){
        case 1:
        value=array[f];
        if(f<max-1){f++;}
        else{f=0;}
        return value;
        case 0:
        return 0;
    }
}
    //delete_last
int pop(int array[],int f,int t){
    int value;
    switch(underflow(f,t)){
        case 1:
        value=array[t];
        if(t>0){t--;}
        else{t=max-1;}
        return value;
        case 0:
        return 0;
    }
}
int main(){
    int arr[max];
    int front=0,tail=0;
    int i=1,k=0;
    while(i==1){
        printf("1. show()\n2. start()\n3. push()\n4. delete()\n5. pop()\n 6. End\n");
        scanf("%d",&k);
        switch(k){
            case 1:
            show(arr, front, tail);
            break;
            case 2:
            start(arr, front, tail,rand()%51);
            break;
            case 3:
            push(arr,front,tail,rand()%51);
            break;
            case 4:
            k=delete(arr, front, tail);
            break;
            case 5:
            k=pop(arr, front, tail);
            break;
            case 6:
            i=0;
            break;
        }
    }
}