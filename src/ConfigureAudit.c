#include "ConfigureAudit.h"

/**
 * Auditing program to flag and report events to user
 * @author Fevronia Van Sickle 
 * @version 12/19
 */

 /**
  * accesses auditPipe and configures audit_control file 
  */
FILE* ConfigureAudit(){

    //make sure we are in root
    if (!userID()){
        fprintf(stderr, "Error: program must be run by root user.\n If error persists, run with sudo and/or check user permission settings.\n");
    }

    //open audit pipe to access audit trail file
    char* auditPipePath = "/dev/auditpipe";

    FILE* auditTrailFile;
    int auditFileDescriptor; 
    //flags for file create and file delete
    u_int auditFlags = 0x00000010 | 0x00000020;

    auditTrailFile = fopen(auditPipePath, "r");

    if (auditTrailFile == NULL) {
        fprintf(stderr, "Error: audit pipe cannot be opened %s\n", auditPipePath);
        exit(1);
    }

    //using descriptor in order to use ioctl system calls
    auditFileDescriptor = fileno(auditTrailFile);

    //getters
    
    //ioctl returns zero if successful
    int queueMin = ioctl(auditFileDescriptor, AUDITPIPE_GET_QLIMIT_MIN, &queueMin);
    if (queueMin == -1) {
        fprintf(stderr, "Error: cannot get min length of audit queue\n");
        exit(1);
    }

    int queueMax = ioctl(auditFileDescriptor, AUDITPIPE_GET_QLIMIT_MAX, &queueMax);
    if (queueMax== -1) {
        fprintf(stderr, "Error: cannot get max length of audit queue\n");
        exit(1);
    }

    int maxAuditData = ioctl(auditFileDescriptor, AUDITPIPE_GET_MAXAUDITDATA, &maxAuditData);
    if (queueMax== -1) {
        fprintf(stderr, "Error: cannot get max amount of audit data\n");
        exit(1);
    }

    //setters

    //audit only local events so we can use preset flags
    int mode = AUDITPIPE_PRESELECT_MODE_LOCAL;
    int setMode = ioctl(auditFileDescriptor, AUDITPIPE_SET_PRESELECT_MODE, &mode);
    if (setMode == -1) {
        fprintf(stderr, "Error: cannot set audit pipe mode to local.\n");
    }

    //configure audit control file
    u_int attributableEvents, nonAttributableEvents = auditFlags;

    int attEvents = ioctl(auditFileDescriptor, AUDITPIPE_GET_MAXAUDITDATA, &attEvents);
    if (attEvents== -1) {
        fprintf(stderr, "Error: cannot set attributable events\n");
        exit(1);
    }

    int nonAttEvents = ioctl(auditFileDescriptor, AUDITPIPE_GET_MAXAUDITDATA, &nonAttEvents);
    if (nonAttEvents== -1) {
        fprintf(stderr, "Error: cannot set Non-attributable events\n");
        exit(1);
    }
    return auditTrailFile;
}
