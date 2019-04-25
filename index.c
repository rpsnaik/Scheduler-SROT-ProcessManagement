#include<stdio.h>
#include<stdlib.h>

int main(){

    int iload, ijload;
    for(iload = 0; iload<50; iload++){
        printf("########   Starting the Scheduler ######### \n");
        for(ijload = 0; ijload<iload; ijload++){
            printf("#");
        }
        
        printf("\n[%d %%]",(iload+1)*2);
        system("@cls||clear");
    }
    //system("@cls||clear");
    printf("Scheduler Loaded Successfully...\n");
    sleep(1);

    int n,i,j,k,l,m,o,p,nl;
    int closing_flag = 0;
    int lclosing_flag = 0;
    printf("Welcome to Process Scheduler \n");
    printf("Enter the No.of Process you are having ?\n");
    scanf("%d",&n);
    int a[n], b[n];
    char c[n];
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
    printf("\nCreating the Multilevel Queue based on Priority...\n");
    sleep(2);
    printf("MultiLevel Queue Created Successfully... \n");
    printf("\n \n \n");
    printf("*************      Low Priority Queue       **************\n");
    printf("ProcessID ---- Arrival Time ----- Brust Time ----- Priority \n");
    for(l = 0; l < lQueueSize; l++){
        printf("    L%d",l+1);
    	printf("           %d             %d                 %c \n",a[lQueue[l]], b[lQueue[l]], c[lQueue[l]]);
	}

    printf("\n \n \n");
    printf("*************      High Priority Queue       **************\n");
    printf("ProcessID ---- Arrival Time ----- Brust Time ----- Priority \n");
    for(m = 0; m < hQueueSize; m++){
        printf("    H%d",m+1);
    	printf("           %d             %d                 %c \n",a[hQueue[m]], b[hQueue[m]], c[hQueue[m]]);
	}
    printf("\n \n \n");
    printf("Hold on for a moment \n");
    for(ijload = 0; ijload<iload; ijload++){
        printf("#");
    }
    printf("\n \n \n");
    if((hQueueSize > 0) && (lQueueSize > 0)){
        //Here Comes the Timer
        printf("Process Starts Here : \n \n");
        printf("      Arrival Time ----- Brust Time ----- Priority ----- Waiting Time -----  TurnAroundTime\n");
        int empty = lQueueSize + hQueueSize;
        int time = 0;
        printf("\n");
        do{
            //printf("At Time : %d : \n",time);

            //Giving Priority to High Priority Processes
            if(hQueueSize > 0){
                closing_flag = 0;
                int hminimumBurstTime = 2000;
                int indexofPid;
                for(o = 0; o < hQueueSize; o++){
                    if(a[hQueue[o]] <= time){
                        if(hminimumBurstTime > b[hQueue[o]]){
                        hminimumBurstTime = b[hQueue[o]];
                        indexofPid = o;
                        //printf("The List of Less than the Given Time instance are :  %d      %d     %c \n",a[hQueue[indexofPid]], b[hQueue[indexofPid]], c[hQueue[indexofPid]]);
                        }
                    }
                }
                if(b[hQueue[indexofPid]] <= 2){
                    printf("           %d                 %d              %c               %d               %d    \n", a[hQueue[indexofPid]], b[hQueue[indexofPid]], c[hQueue[indexofPid]], time-a[hQueue[indexofPid]], time-a[hQueue[indexofPid]]);
                }
                    printf("           %d                 %d              %c               %d               (Not Yet Completed)    \n", a[hQueue[indexofPid]], b[hQueue[indexofPid]], c[hQueue[indexofPid]], time-a[hQueue[indexofPid]]);
                if(b[hQueue[indexofPid]] > 2){
                    b[hQueue[indexofPid]] = b[hQueue[indexofPid]] - 2;
                }else{
                    //printf("Cutting off \n");
                    for(p = indexofPid; p<hQueueSize-1; p++){
                            a[hQueue[p]] = a[hQueue[p+1]];
                            b[hQueue[p]] = b[hQueue[p+1]];
                            c[hQueue[p]] = c[hQueue[p+1]];
                    }
                    hQueueSize-=1;
                    if(hQueueSize == 0){
                        closing_flag = 1;
                    }    
                }

                //printf("Arrival Time ----- Brust Time ----- Priority \n");
                // for(m = 0; m < hQueueSize; m++){
                //     printf("%d      %d     %c \n",a[hQueue[m]], b[hQueue[m]], c[hQueue[m]]);
                // }

            }else{
                lclosing_flag = 0;
                //Low Priority Process
                int lminimumBurstTime = 2000;
                int indexofPid;
                for(nl = 0; nl < lQueueSize; nl++){
                    if(a[lQueue[nl]] <= time){
                        if(lminimumBurstTime > b[lQueue[nl]]){
                        lminimumBurstTime = b[lQueue[nl]];
                        indexofPid = nl;
                        //printf("The List of Less than the Given Time instance are :  %d      %d     %c \n",a[hQueue[indexofPid]], b[hQueue[indexofPid]], c[hQueue[indexofPid]]);
                        }
                    }
                }
                // printf("    %d      %d     %c \n", a[lQueue[indexofPid]], b[lQueue[indexofPid]], c[lQueue[indexofPid]]);
                if(b[hQueue[indexofPid]] <= 2){
                    printf("           %d                 %d              %c               %d               %d    \n", a[lQueue[indexofPid]], b[lQueue[indexofPid]], c[lQueue[indexofPid]], time-a[lQueue[indexofPid]]);
                }
                    printf("           %d                 %d              %c               %d               (Not Yet Completed)    \n", a[lQueue[indexofPid]], b[lQueue[indexofPid]], c[lQueue[indexofPid]], time-a[lQueue[indexofPid]]);
                if(b[lQueue[indexofPid]] > 2){
                    b[lQueue[indexofPid]] = b[lQueue[indexofPid]] - 2;
                }else{
                    //printf("Cutting off \n");
                    for(p = indexofPid; p<lQueueSize-1; p++){
                            a[lQueue[p]] = a[lQueue[p+1]];
                            b[lQueue[p]] = b[lQueue[p+1]];
                            c[lQueue[p]] = c[lQueue[p+1]];
                    }
                    lQueueSize-=1;
                    if(lQueueSize == 0){
                        lclosing_flag = 1;
                    }    
                }

                // printf("Arrival Time ----- Brust Time ----- Priority \n");
                // for(m = 0; m < lQueueSize; m++){
                //     printf("%d      %d     %c \n",a[lQueue[m]], b[lQueue[m]], c[lQueue[m]]);
                // }

            }

            time+=2;
    
        }while((closing_flag == 0) || (lclosing_flag == 0) );
    }else{
        printf("Warning : There Should be at least 2 Processes and minimum one High Priority Process and minimum one Low Priority Process \n");
        printf("Exited\n");
    }

    return 0;
}
