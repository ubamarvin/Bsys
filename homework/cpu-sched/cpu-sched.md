Response = Firstrun - Arrival

Turnaround = Completion - Arrival

        

1. Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers.
>>ARG policy FIFO
  ARG jlist 200,200,200

  Here is the job list, with the run time of each job:
                                Response time   Turnaround time
  Job 0 ( length = 200.0 )      0               200           
  Job 1 ( length = 200.0 )      200             400
  Job 2 ( length = 200.0 )      400             600
                          Avg   200             400

>>ARG policy SJF
  ARG jlist 200,200,200

  Here is the job list, with the run time of each job:
                                Response time   Turnaround time
  Job 0 ( length = 200.0 )      0               200
  Job 1 ( length = 200.0 )      200             400
  Job 2 ( length = 200.0 )      400             600
                          Avg   200             200

>>Observation: No difference between SJF and FIFO if job-lenghts are all equal since SJF executes at the same order as FIFO



2. Now do the same but with jobs of different lengths: 100, 200, and 300.

>>ARG policy FIFO
  ARG jlist 100,200,300

  Here is the job list, with the run time of each job: 
                                Response time   Turnaround time
  Job 0 ( length = 100.0 )      0               100
  Job 1 ( length = 200.0 )      100             300
  Job 2 ( length = 300.0 )      300             600
                          AVG   133             333

>>ARG policy FIFO
  ARG jlist 300,200,100
  
  Here is the job list, with the run time of each job: 
                                Response time       Turnaround time
  Job 0 ( length = 300.0 )      0                   300
  Job 1 ( length = 200.0 )      300                 500
  Job 2 ( length = 100.0 )      500                 600
                          Avg   266                 466


>>ARG policy FIFO
  ARG jlist 200,300,100

  Here is the job list, with the run time of each job: 
                                Response time       Turnaround time
  Job 0 ( length = 200.0 )      0                   200
  Job 1 ( length = 300.0 )      200                 500
  Job 2 ( length = 100.0 )      500                 600
                          AVG   233                 433

_______________________________________________________________
>>ARG policy SJF
  ARG jlist 100,200,300

  Here is the job list, with the run time of each job: 
                                Response time   Turnaround time
  Job 0 ( length = 100.0 )      0               100
  Job 1 ( length = 200.0 )      100             300
  Job 2 ( length = 300.0 )      300             600
                          AVG   133             333
________________________________________________________________




3. Now do the same, but also with the RR scheduler and a time-slice of 1.

>>ARG policy RR
  ARG jlist 100,200,300
  
  Here is the job list, with the run time of each job:
                                Response-time       Turnaround-time (Completion = (Waittime + Jobtime))
  Job 0 ( length = 100.0 )      0                   298
  Job 1 ( length = 200.0 )      1                   499
  Job 2 ( length = 300.0 )      2                   600
                          AVG   1                   465.67

>>ARG policy RR
  ARG jlist 300,200,100
  
  Here is the job list, with the run time of each job:
                                Response-time       Turnaround-time
  Job 0 ( length = 300.0 )      0                   600
  Job 1 ( length = 200.0 )      1                   500
  Job 2 ( length = 100.0 )      2                   300
                                                    466.67

>>ARG policy RR
  ARG jlist 200,300,100

  Here is the job list, with the run time of each job:
                                Response-time       Turnaround-time
  Job 0 ( length = 200.0 )      0                   499
  Job 1 ( length = 300.0 )      1                   600
  Job 2 ( length = 100.0 )      2                   300
                                                    466.33
>> SJF + RR liefert niedrigste Turnaround time?


4. For what types of workloads does SJF deliver the 
same turnaround times as FIFO?
>>same order
>>same job lenght which leads to same order



5. For whattypes of workloads and quantumlengths 
does SJF deliver the same response times as RR?

>> SJW and RR Workloads have same lenght, thus elimating the order problem
>> RR quatum leap is equal or greater than workload lenght

>>>>ARG policy SJF
  ARG jlist 200,200,200

  Here is the job list, with the run time of each job:
                                Response time   Turnaround time
  Job 0 ( length = 200.0 )      0               200
  Job 1 ( length = 200.0 )      200             400
  Job 2 ( length = 200.0 )      400             600
                          Avg   200             400

>>ARG policy RR
  ARG jlist 200,200,200  -q 200
 
  Here is the job list, with the run time of each job:
                                Response time   Turnaround time                        
  Job 0 ( length = 200.0 )      0               200
  Job 1 ( length = 200.0 )      200             400
  Job 2 ( length = 200.0 )      400             600
                          AVG   200             400

>>Workloads are the same in terms of distribution
>>RR has JOb order in SJF fashion
>>RR q is equal or greater than greatest workload lenght


ARG policy SJF
ARG jlist 100,200,300

Here is the job list, with the run time of each job: 
                                R               T
  Job 0 ( length = 100.0 )      0               100
  Job 1 ( length = 200.0 )      100             300
  Job 2 ( length = 300.0 )      300             600
                                133.33          333.33

ARG policy RR
ARG jlist 100,200,300

Here is the job list, with the run time of each job: 
                                R               T
  Job 0 ( length = 100.0 )      0               100
  Job 1 ( length = 200.0 )      100             300
  Job 2 ( length = 300.0 )      300             600
                                133.33          333.33






6. What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend?
>>the response time increases provides that it isnt the last job which increases?



7. What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?
>> Worst-case response time = something devided by n
>>as quantum length increases, RR approximates FIFO