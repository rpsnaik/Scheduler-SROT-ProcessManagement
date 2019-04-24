# Scheduler-SROT-ProcessManagement

As per the Question assigned I am subjected to create a multilevel Queue in which the Upper Queue having higher Priority than the lower one, based on the Burst Time I need to Select the one having the least burst time(So as the Process Executes faster) and execute it, and further it was mentioned that we need to check the process with least burst time after every 2 secs.

Algorithm (Priority Queue): 
	Based on the above given situation I decided to make use of a Queue, with Priority Queue Algorithm. The user is subjected to assign the arrival time, burst time and the Priority either H-High or L-Low.
Once we got all the data from the user the program will create two queues one for the lowest priority process and other for highest priority processes.
Once both the Queues were Created, we apply our Priority Queue Algorithm to find the process with less burst time. Once we found we try to execute that and for each 2 secs we continue with the process of finding the least burst time process.
As there were two Queues the highest Priority Processes were executed first followed by the lowest priority queue. 

Code Snippets :
	In the Main function the below Snippet helps the user to get the no.of process to be executed followed by arrival time burst time and Priority.
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


2.
Adding To a Multilevel Queue based on Priority

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


3.
Once the above snippet runs it will create a successful multilevel Queue,

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


4.
Here Comes the Priority Queue Algorithm :

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

Description : 
	As per the Question assigned I am subjected to create a multilevel Queue in which the Upper Queue having higher Priority than the lower one, based on the Burst Time I need to Select the one having the least burst time(So as the Process Executes faster) and execute it, and further it was mentioned that we need to check the process with least burst time after every 2 secs.
 Constraints : 
	As there is an  occurrence of a priority queue which actually is multilevel queue. So there should be atleast 2 Processes to execute and each of them belong to different catogery.
else{
        printf("Warning : There Should be at least 2 Processes and minimum one High Priority Process and minimum one Low Priority Process \n");
        printf("Exited\n");
    }

It will be raised when this kinda situation happens.
