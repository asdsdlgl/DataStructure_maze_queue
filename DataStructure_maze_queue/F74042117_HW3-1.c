#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int vertmove [8]={0,1, 0,-1,1, 1,-1,-1};
int horizmove[8]={1,0,-1, 0,1,-1,-1, 1};//東 南 西 北 東南 西南 西北 東北 
int count=0;
FILE *fp2;
void path(int **maze,int **mark,int curipos,int curjpos,int startipos,int startjpos,int endipos,int endjpos,int rows,int cols){
	int i,j,nextrow,nextcol,temp=0;
	
	if(curipos==endipos&&curjpos==endjpos){
		for(i=1;i<rows+1;i++){
			for(j=1;j<cols+1;j++){
				if(startjpos==i&&startipos==j)fprintf(fp2,"s");
				else if(endjpos==i&&endipos==j){
					fprintf(fp2,"d");
					temp++;
					} 
				else if(maze[i][j])fprintf(fp2,"1");
				else if(mark[i][j]){
					fprintf(fp2,"*");
					temp++;
				}
				else fprintf(fp2,"0");
			}
			fprintf(fp2,"\n");
		}
		fprintf(fp2,"\n"); 
		if(!count)count = temp;
		if(count>temp)count = temp;
		
		return;
	}
	for(i=0;i<8;i++){
		nextrow = curjpos + vertmove[i];
		nextcol = curipos + horizmove[i];
		if(!maze[nextrow][nextcol]&&!mark[nextrow][nextcol]){
			mark[nextrow][nextcol] = 1;
			path(maze,mark,nextcol,nextrow,startipos,startjpos,endipos,endjpos,rows,cols);
			mark[nextrow][nextcol] = 0;
		}
	}
	return;
}

int main(){
	FILE *fp;
	fp2 = fopen("out.txt","w");
	fp = fopen("in.txt","r");
	int i,j,rows=0,cols=0,startipos,startjpos,endipos,endjpos;
	char arr[200]={0};
	while(fgets(arr,200,fp)!=NULL){
		rows++;
	}
	cols = strlen(arr);
	rewind(fp);
	//fseek(fp,0,SEEK_SET);
	
	int **maze = (int **)malloc((rows+2)*sizeof(int *));
	int **mark = (int **)malloc((rows+2)*sizeof(int *));
	for(i=0;i<(rows+2);i++){
		maze[i] = (int *)calloc((cols+2),sizeof(int));
		mark[i] = (int *)calloc((cols+2),sizeof(int));
	}
	
	for(i=0;i<rows+2;i++)
		for(j=0;j<cols+2;j++)
			maze[i][j]=1;
			
	for(i=0;i<rows;i++){
		fgets(arr,200,fp);
		for(j=0;j<cols;j++){
			if(arr[j]=='s'){
				arr[j] = '0';
				startipos = j+1;
				startjpos = i+1;
			}
			if(arr[j]=='d'){
				arr[j] = '0';
				endipos = j+1;
				endjpos = i+1;
			}
			maze[i+1][j+1]=arr[j]-'0';
		} 
	}
	
	path(maze,mark,startipos,startjpos,startipos,startjpos,endipos,endjpos,rows,cols);
	
	if(count==0){
		fprintf(fp2,"No route!!");
	}else{
		fprintf(fp2,"The shorest path: %d steps",count);
	}
	
	for(i=0;i<(rows+2);i++){
		free(maze[i]);
		free(mark[i]);	
	}
	free(maze);
	free(mark);
	 
	fclose(fp);
	fclose(fp2);
} 
