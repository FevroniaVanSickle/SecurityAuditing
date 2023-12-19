#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <bsm/audit.h>
#include <bsm/libbsm.h>
#include <bsm/audit_kevents.h>
#include <sys/ioctl.h>
#include <security/audit/audit_ioctl.h>
#include <stdbool.h>
#include <unistd.h>


FILE* ConfigureAudit();

//taken from from @santoru on github
bool userID(){
        uid_t userID = geteuid();
        if (userID != 0) {
            return false;
        }
            return true;
    }


