This program accesses the audit pipe on MacOS and prints warnings if files are created or deleted. 

In order to run this program you must:
* be running MacOS Ventura or have downloaded Auditd separately 
* run the program as the root user. This is best accomplished by using sudo after compiling

The program is currently set up to notify users of file deletion or file creation. 
Instructions for use:
1. compile the main file
2. run the main file with sudo
3. once program is running, create a new file
4. a warning will be printed that a file has been created
5. with program still running, delete a file
6. a warning will be printed that a file has been deleted
7. exit the program and/or reset your audit_control file

After you are done running the program you may want to reset your audit control file to normal so as to not affect computer performance. 

Instructions to reset audit control file: 

acknowledgements:
inspiration for userID method from @santoru
inspiration for tapping into auditpipe from @SPADE

runs 
Test.py
ConfigureAudit.c
Parser.c
ResetAuditFile.c
