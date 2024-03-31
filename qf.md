1.F
What is an operating systems responsibility?
    -making it easy to run programs
    -allowing programs to share mem
    -enabling prog to interaxt with device

1.F Describe virtualization, concurrency and persistence each in one sentence.
    -The OS takes a physical resource and transforms it into a virtual form of itself.
    -function running within the same memory space(does each function then "thinks" it has a private cpu?)
    -programs share one phzsical device, os manages that no data is lost


1.F List three advantages of virtualization
    -Apps can reuse common facilities
    -different devices look the same
    -provides higher level or more useful functionality

1.F System call?
    - SysCall allows user(applications) to tell the OS what to do via a std. library

1.F List four OS design goals.
    - make sys easy and convenient to use by building abstractions
    -provie high performance
    -protection
    -reliable

1.F whats a policy?
    -what is done and when()

1.F whats a mechanism?
    -how ot is done (low level code)


4.f explain direct execution?
direct execution allows user process tu run directly on hardware

4.f explain issues with direct execution
user process can fuck with system
user process could run forever
user process could do smthing slow like i/o, effectively stalling the cpu

4.f what is the solution?
limited direct execution

4.f what is limited direct execution
os and hardware maintain some control

3.f
if getpid doesnt return that means the system is fucked

instructions haben auch virtuelle adressen