Name: Tyler Crabtree
Email: Crabtree.Tyler@gmail.com
Class: Computer Science 460
Project: Priority Scheduler

Files: PriorityScheduler(folder), ReadMe.txt, ExampleVideo.mp4, xv6-public.zip (for testing).

PriorityScheduler(folder) contains:
forktest.c, Makefile, proc.c, proc.h, setpriority.c, syscall.c, syscall.h, sysproc.c, user.h, usys.S.

Running Description.
1. Copy files from "priorityScheduler" folder into a fresh version of a "xv6-public" folder (shown in video).
2. In terminal, cd to "xv6-public" folder with newly added files.
3. Use "make qemu SCHEDFLAG=PRIORITY" to compile/run xv6. 
4. Type "setpriority" to see system call, add one integer argument after this (make sure range is from 0 to 200).For example, "setpriority 75" is an example command. 
5. Run "forktest" to see that forktest is functional. 

Example commands:
1. "setpriority 75"
2. "setpriority 100"
3. "forktest"

Notes:
Refer to the ExampleVideo if you need help compiling/running. 
Also, please use a fresh version of xv6 to test, a version with a "ps" system call may not work, I attached a blank xv6 just in case for testing. 

