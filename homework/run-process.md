1. Runprocess-run.pywiththefollowingflags:-l 5:100,5:100. What should the CPU utilization be (e.g., the percent of time the CPUis in use?) Why do youknowthis? Use the-c and-p flags to see if you were right.

>>Cpu utilization is 100%, because the flag 5:100 specified 5 instructions with 100% percent cpu instruction type.



2. Nowrun with these flags: ./process-run.py-l 4:100,1:0. These flags specify one process with 4 instructions (all to use the CPU),andonethatsimplyissues anI/Oandwaitsforittobedone. Howlong does it take to complete both processes? Use-c and-p to find out if you were right.

>> 4 ticks for the first, 2 ticks for the second, 5  for I/0



3. Switch the order of the processes:-l 1:0,4:100. What happens now? Does switching the order matter? Why? (As always, use-c and-pto see if you were right)
>> i presume the the second process will run during i/0. Switching the order matters because PId 0 state is blocked after io, allowing pid 1 to run and execute 



4. We’ll now explore some of the other flags. One important flag is-S, which determines how the system reacts when a process issues an I/O. With the flag set to SWITCH ON END, the system will NOT switch to another process while one is doing I/O, instead waiting until the process is completely finished. What happens when you run the following two processes (-l 1:0,4:100-c-S SWITCH ON END),onedoingI/Oandtheother doing CPU work?

>>PID 1 can only run after PID 0 is done




5. Now, run the same processes, but with the switching behavior set to switch to another process whenever one is WAITINGforI/O(-l 1:0,4:100-c-S SWITCH ON IO).Whathappensnow? Use-c and-pto confirm that you are right.

>> While PID 0 is I/O PID 1 executes til done

6. One other important behavior is what to do when an I/O completes. With-I IO RUN LATER, when an I/O completes, the process that issued it is not necessarily run right away; rather, whatever was running at the time keeps running. What happens when you run this combination of processes? (./process-run.py-l 3:0,5:100,5:100,5:100-S SWITCH ON IO-c-p-I IO RUN LATER)Aresystem resources being effectively utilized? 

>>System resourcess are not effectively utilized due to the fact that the last 2 I/O processes are scheduled in last resulting in idle cpu time

7. Nowrunthesameprocesses,butwith-I IO RUN IMMEDIATEset, which immediately runs the process that issued the I/O. How does this behavior differ? Why might running a process that just completed an I/O again be a good idea?

>>The difference is, that the cpu is now effectively utilized.
it is a good idea if it is certain that it runs another I/O because then the process will be BLOCKED allowing READY processes to run while I/O is done