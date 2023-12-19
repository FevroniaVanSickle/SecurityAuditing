This program accesses the audit pipe on MacOS and prints output of audit log

In order to run this program you must:
* be running MacOS Ventura or have downloaded Auditd separately 
* run the program as the root user. This is best accomplished by using sudo after compiling
* follow the steps below for compiling 

The program is currently set up to notify users audited events. 
Instructions for use:
1. compile the main file with: gcc -w -o main Main.c -lbsm
2. run the main file with sudo: sudo ./main
3. once program is running, click on objects or create files
6. Event logs will be printed to the console
7. Logs will continue to be printed as long as the program is running. 
7. Exit the program 

acknowledgements:
inspiration for userID method from @santoru on github
inspiration for processing audit tokens from @ashish-gehani on github 

notes about warnings:
Compiling main produces errors about the deprecation of BSM library functions. This is expected, as the program works with deprecated source code due to Auditd itself being deprecated. 

Src includes
ConfigureAudit.c
Parser.c

