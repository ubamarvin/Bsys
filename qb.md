
2.0
What is the role of the Os in terms of resources?
    -manage them.

2.2 Describe virtualization?
    -Each process has its own memory space which the os
    maps on the physical memory adresses
    -each process has its own virtual cpu 

2.3 Describe some matters refering to Concurrency (refers to a host of problems/large number of matters or problems)?
    - making many processes within the same memory space work as intended 

2.3 "Unfortunately, the problems of concurrency are no longer limited just to the OS itself." 
    q: When do they arise

2.3 can code 2.5 Final value go over 2N ?

2.4 Describe persitence ?
    - Data is stored in a manner that is liable to change rapidly and unpredictabily (power-outtage). The  persitence deals with solutions

2.4 What does the Os software "File-system" do ?
    - manages the disk, stores files.

2.4 Briefly, what does the file-system have to do to write a file in the disk
    -where should the data go, keep track of that in structs, issue i/o requests to unerlying storage device

2.A How does ram persitence work? When my pc crashes, data usually isnt completely lost?

2.5 The design goals are ?
    - abstraction
        system must be easy to use.
    - high performance/minimal overhead
        os must not be a ramhogger
    - protection between apps and apps and apps and os
        An apps Malicous/accidental bad beahviour musnt harm other apps or Os
    - high degree of reliability
        Os musnt crash as that stops all other apps
    - mobility

2.6 Why is implementating a file system as a library bad?
    -any app could r/w directly on disk

2.6 "The UNIX environment was friendly for programmers and developers alike"
    -whats the difference?

4.0 whats a process?
    - a running programm

4.0 what is time-sharing in virtualization context?
    -process1 runs, then stops, then process2 runs, then process 2 stopps, then process1 resumes

4.0 What does the Os need to implement virtualization?
    -mechanisms: e.g stop/start prgramm
    -policies: Descision making alghorithms. e.g which process will run next will be decided by a scheduling policie.
    


    





5.2
How does the wait() call inform the parent that the child process has finished executing?

5.3
How does the exec() call work, does it create a new process?

5.4
What is a unix shell?
What is a unix system?

6.1
what is limited direct execution


