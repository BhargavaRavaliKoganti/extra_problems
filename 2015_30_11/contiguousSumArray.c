#include<stdio.h>
#include<stdlib.h>
int x = -1;
int y = -1;
void maxContiguousArraySum(int *, int);

int main(){
    	int givenArray[] = {1,2,3,4,5,-2,-3,-4,-20,10};
    	int len = 10;
   	int sum = 0;
    	maxContiguousArraySum(givenArray, len);
    	for(int i = x; i < y+1; i++){
		sum += givenArray[i];
		printf("%d->", givenArray[i]);
	}
	printf("\n%d\n",sum);
    	return 0;
}

void maxContiguousArraySum(int *arr, int size){
        int max = 0;
	int curSum = 0;
	int z = -1;
        for (int i = 0; i < size; i++)
        {
                curSum = curSum + arr[i];
                if(z == -1)
                        z = i;
                if (curSum <= 0){
                        curSum = 0;
                        z = -1;
                }
                if (max < curSum){
                        max = curSum;
                        x = z;
                        y = i;
                }
        }
        return;
}

