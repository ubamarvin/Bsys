1. Run a few randomly-generated problems with just two jobs and two queues; compute the MLFQ execution trace for each. Make your life easier by limiting the length of each job and turning off I/Os. 

2. How would you run the scheduler to reproduce each of the examples in the chapter? 
    fig 8.2
    >>python3 ./mlfq.py -l 0,200,0 -q 10 -a 1 -c

    fig 8.3 left
    >>python3 ./mlfq.py -l 0,200,0:100,20,0 -q 10 -a 1 -c

    fig 8.3 right
    >>python3 ./mlfq.py -l 0,175,0:50,25,1 -q 10 -a 1 -i 5 -S -c

    fig 8.4 left
    >>python3 ./mlfq.py -l 0,130,0:100,50,1:100,50,1 -i 1 -S -c

    fig 8.5 right 
    >>python3 ./mlfq.py -l 0,130,0:100,50,1:100,50,1 -i 1 -S -B 120 -c Wrong
    >> kp wie ich des nach N sekunden in nem interval von i boosten kann

    fig 8.5
    >>python3 ./mlfq.py -l 0,200,0:70,50,10 -i 1 -S -c

    fig 8.6
    >>python3 ./mlfq.py -l 0,200,0:70,50,7 -i 1 -c

    fig 8.7
    >>python3 ./mlfq.py -l 0,150,0:0,150,0 -Q 10,20,50  -a 2 -c








3. Howwouldyouconfigure the scheduler parameters to behave just like a round-robin scheduler?
>>onlz one Queue, timeallot multiple of time slice
>> -n 1 -q x with x being shorter than the shortest job 

4. Craft a workload with two jobs and scheduler parameters so that one job takes advantage of the older Rules 4a and 4b (turned on with the-S flag) to game the scheduler and obtain 99% of the CPU over a particular time interval.
>>python3 ./mlfq.py -l 0,100,0:0,100,9 -i 1 -q 10 -a 1 -S -c


5. Givenasystemwithaquantumlengthof10msinitshighestqueue, howoftenwouldyouhavetoboostjobsbacktothehighestpriority level (with the-B flag) in order to guarantee that a single longrunning (and potentially-starving) job gets at least 5% of the CPU? 


6. One question that arises in scheduling is which end of a queue to add a job that just finished I/O; the-I flag changes this behavior for this scheduling simulator. Play around with some workloads and see if you can see the effect of this flag.
>>with the I flag, the job which just finished I/O runs immediately again provided in its queue
>>python3 ./mlfq.py -l 0,50,0:0,50,10 -i 1 -I -c