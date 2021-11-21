#include <cstdio>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int queue[25],N;
int move(int now,int which,int len)
{
	for(int i=1;i<=len;i++){
        while(true){
            now=(now+which+N-1)%N+1;
            if(!queue[now]) break;
        }
	}
	return now;
}
int main()
{
	int K,M;
	while(scanf("%d%d%d",&N,&K,&M)&&N)
	{
		int sum=N;
		int pos1=N;
		int pos2=1;
		memset(queue,0,sizeof(queue));
		while(sum)
		{
			pos1=move(pos1,1,K);
			pos2=move(pos2,-1,M);
			cout << setw(3) << pos2;
            //printf("%3d",pos1);
			sum--;
			if(pos1!=pos2)
			{
                cout << setw(3) << pos2;
				//printf("%3d",pos2);
				sum--;
			}
			queue[pos1]=queue[pos2]=1;
			if(sum)
				printf(",");
			else
				printf("\n");
		}
	}
	return 0;
}