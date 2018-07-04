#include<stdio.h>
#include<stdlib.h>
#define maxsize 4
typedef struct{
	char key;
}element;
element queue[maxsize];
int rear = -1;
int front = -1;
void queueFull(){
	printf("Queue is full\n");
	int i;
	front = -1;
	rear = maxsize-1;
	printf("Front = %d Rear = %d\n",front,rear);
	for(i=0;i<maxsize;i++){
		printf("[");
		printf("%c",queue[i].key);
		printf("]");
	}
	printf("\n");
}
void add(element item){
	int i=0,flag=0,temp=0;
	if(rear==maxsize-1){
		if(front==-1){
			queueFull();
			return ;
		}
		rear--;
		flag = 1;
	}
	
	rear++;
	
	if(!flag)queue[rear] = item;
	
	if(flag){
		if(front==-1){
		for(i=front+1;i<=rear;i++){
			queue[temp].key = queue[i].key;
			temp++;
		}
		front = -1;
		rear = temp-1;
		}else{
			for(i=front+1;i<=rear;i++){
				queue[temp] = queue[i];
				temp++;
			}
			front = -1;
			queue[temp] = item;
			rear = temp;
		}
	}
	printf("Front = %d Rear = %d\n",front,rear);
	
	printf("Queue:");
	for(i=0;i<maxsize;i++){
		printf("[");
		if(i>front&&i<=rear)
			printf("%c",queue[i].key);
		printf("]");
	}
	printf("\n");
}
void queueEmpty(){
	printf("Queue is empty\n");
	front = -1;
	rear = -1;
	printf("Front = %d Rear = %d\n",front,rear);
	printf("Queue:[][][][]\n");
}
void delet(){
	int i,flag=0,temp=1;
	if(rear==front){ 
		queueEmpty();
		return; 
		}
		
	if(!flag)printf("delete:%c\n",queue[++front]);
	
	printf("Front = %d Rear = %d\n",front,rear);
	printf("Queue:");
	for(i=0;i<maxsize;i++){
		printf("[");
		if(i>front&&i<=rear)
			printf("%c",queue[i].key);
		printf("]");
	}
	printf("\n");
	return ; 
}
int main(){
	int i=0,num,insert;
	char c;
	element temp;
	while(1){
		printf("Insert(1)delete(2):");
		scanf("%d",&num);
		switch(num){
			case 1:
				printf("insert number:");
				scanf(" %c",&c);
				temp.key = c;
				add(temp);
				break;
			case 2:
				delet();
				break;
			default :
				printf("meaningless input\n");
				break;
		}
	}
} 
