#include<stdio.h>
int main() {
int block_size[] = { 200,400,600,500,300,200}; int p_Req[] = { 357 , 210 , 468 , 491 };
int allo[sizeof(p_Req)/4];
int giv[] = { 0 , 0 , 0 ,0 ,0, 0 };
for(int i = 0 ;i <sizeof(p_Req)/4 ; i ++) {
int d = 0;
for(int j = 0 ;j < sizeof(block_size)/4;j++) {
if(block_size[j]>=p_Req[i] && giv[j]==0) {
allo[i] = j ; 
giv[j] = 1 ; 
d = -1 ; 
break;
} }
if(d!=-1) {
allo[i] = -1 ; }
}
for(int i = 0 ; i <sizeof(p_Req)/4;i++) {
if(allo[i]!=-1) {
printf("Process%d requiered %d and was allocated : %d \n" , i , p_Req[i] , block_size[allo[i]]);
} else {
printf("Process%d is not allocated\n",i); }
}
return 0 ; }
