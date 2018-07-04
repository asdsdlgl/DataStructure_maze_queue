#include<stdio.h>
#include<stdlib.h>
#define maxsize 4
typedef struct{
	char key;
}element;
element queue[maxsize];
int rear = 0;
int front = 0;
void queueFull(){
	int i;
	printf("Queue is full\n");
	if(rear==0)rear=maxsize-1-front;//前一個數字 
	else rear = front-1;
	printf("Front = %d Rear = %d\n",front,rear);

	if(rear>=front){
		printf("Queue:");
		for(i=0;i<maxsize;i++){			//正規繞 
			printf("[");
			if(i>front&&i<=rear)
				printf("%c",queue[i].key);
			printf("]");
		}
		printf("\n");
	}else{
		printf("Queue:");				//繞圈後 
		for(i=0;i<=rear;i++){
			printf("[");
			printf("%c",queue[i].key);	//rear
			printf("]");
		}
		for(i=0;i<front-rear;i++)		//無數字 
			printf("[]");
		for(i=front+1;i<maxsize;i++){	//front
			printf("[");
			printf("%c",queue[i].key);
			printf("]");
		}
		printf("\n");
	}
}
void queueEmpty(){
	int i;
	printf("Queue is empty\n");
	printf("Front = %d Rear = %d\n",front,rear);
	if(rear>=front){
		printf("Queue:");
		for(i=0;i<maxsize;i++){
			printf("[");
			if(i>front&&i<=rear)
				printf("%c",queue[i].key);
			printf("]");
		}
		printf("\n");
	}else{
		printf("Queue:");
		for(i=0;i<=rear;i++){
			printf("[");
			printf("%c",queue[i].key);
			printf("]");
		}
		for(i=0;i<front-rear;i++)
			printf("[]");
		for(i=front+1;i<maxsize;i++){
			printf("[");
			printf("%c",queue[i].key);
			printf("]");
		}
		printf("\n");
	}
}
void add(element item){
	int i=0,flag=0;
	rear = (rear+1)%maxsize;
	if(front==rear){
		queueFull();
		return;
	}
	queue[rear] = item;
	
	printf("Front = %d Rear = %d\n",front,rear);

	if(rear>=front){
		printf("Queue:");
		for(i=0;i<maxsize;i++){			//正規繞 
			printf("[");
			if(i>front&&i<=rear)
				printf("%c",queue[i].key);
			printf("]");
		}
		printf("\n");
	}else{
		printf("Queue:");				//繞圈後 
		for(i=0;i<=rear;i++){
			printf("[");
			printf("%c",queue[i].key);	//rear
			printf("]");
		}
		for(i=0;i<front-rear;i++)		//無數字 
			printf("[]");
		for(i=front+1;i<maxsize;i++){	//front
			printf("[");
			printf("%c",queue[i].key);
			printf("]");
		}
		printf("\n");
	}
}
void delet(){
	int i,flag=0;
	if(rear==front){ 
		queueEmpty();
		return;
		}
	front = (front+1)%maxsize;
	printf("delete:%c\n",queue[front]);
	printf("Front = %d Rear = %d\n",front,rear);
	if(rear>=front){
		printf("Queue:");
		for(i=0;i<maxsize;i++){
			printf("[");
			if(i>front&&i<=rear)
				printf("%c",queue[i].key);
			printf("]");
		}
		printf("\n");
	}else{
		printf("Queue:");
		for(i=0;i<=rear;i++){
			printf("[");
			printf("%c",queue[i].key);
			printf("]");
		}
		for(i=0;i<front-rear;i++)
			printf("[]");
		for(i=front+1;i<maxsize;i++){
			printf("[");
			printf("%c",queue[i].key);
			printf("]");
		}
		printf("\n");
	}
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
