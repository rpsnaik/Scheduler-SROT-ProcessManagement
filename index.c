#include<stdio.h>

int main(){
    int n,i,j,k,l,m,o,p;
    printf("This is a Process Scheduler \n");
    printf("Enter the No.of Process you are having ?\n");
    scanf("%d",&n);
    int a[n], b[n];
    char c[n];
    printf("You choosed %d Process",n);
    printf("Enter the Process Arrival Time, Burst Time & Priority (L-Low Priority or H-High Priority) on the same line seperated by a space \n");
    printf("Example : 0 5 L Which mean 0-Arrival Time, 1-Burst Time & L-Low Priority \n");
    for (i = 0; i < n; i++)
    {
        int flag = 0;
    	do{
            scanf("%d %d %c",&a[i],&b[i],&c[i]);
            if((c[i] == 'L') || (c[i] == 'H')){
                flag = 1;
            }else{
                flag = 0;
                printf("The Priority of the Last Added Process is Invalid Please Re-Enter again ... ! \n");
            }
        }while(flag == 0);
    }
    
    
    //Adding in a Queue based on Priority
    int lQueueSize =0, hQueueSize=0;
    int lQueue[100], hQueue[100];
    for(k = 0; k<n; k++){
        if(c[k] == 'L'){
            //Adding in Low Priority Queue
            lQueue[lQueueSize] = k;
            lQueueSize += 1;
        }else if(c[k] == 'H'){
            //Adding in High Priority Queue
            hQueue[hQueueSize] = k;
            hQueueSize += 1;
        }
    }

    printf("Low Priority Queue : \n");
    printf("Arrival Time ----- Brust Time ----- Priority \n");
    for(l = 0; l < lQueueSize; l++){
    	printf("%d      %d     %c \n",a[lQueue[l]], b[lQueue[l]], c[lQueue[l]]);
	}
    
    printf("High Priority Queue : \n");
    printf("Arrival Time ----- Brust Time ----- Priority \n");
    for(m = 0; m < hQueueSize; m++){
    	printf("%d      %d     %c \n",a[hQueue[m]], b[hQueue[m]], c[hQueue[m]]);
	}

    //Here Comes the Timer
    printf("Process Starts Here : \n \n");
    int empty = lQueueSize + hQueueSize;
    int time = 0;
    do{
        printf("At Time : %d : \n",time);

        //Giving Priority to High Priority Processes
        if(hQueueSize > 0){
            int hminimumBurstTime = 2000;
            int indexofPid;
            for(o = 0; o < hQueueSize; o++){
                if(a[hQueue[o]] <= time){
                    if(hminimumBurstTime > b[hQueue[o]]){
                      hminimumBurstTime == b[hQueue[o]];
                      indexofPid = o;
                    }
                }
            }
            printf("Selected Process to Exe : %d      %d     %c \n",a[hQueue[indexofPid]], b[hQueue[indexofPid]], c[hQueue[indexofPid]]);
            if(b[hQueue[indexofPid]] > 2){
                b[hQueue[indexofPid]] = b[hQueue[indexofPid]] - 2;
            }else{
                for(p = indexofPid - 1; p<hQueueSize-1; p++){
                    a[hQueue[p]] = a[hQueue[p+1]];
                    b[hQueue[p]] = b[b[hQueue[p+1]]];
                    c[hQueue[p]] = c[hQueue[p+1]];
                }
            }

        }else{
            //Low Priority Process
        }

        time+=1;
        printf("\n");

        
    }while(time < n);
    



    return 0;
}
