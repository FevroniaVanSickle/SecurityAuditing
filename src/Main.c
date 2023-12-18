#include <stdio.h>
#include "ConfigureAudit.h"

int main(int argc, char *argv[]){
    //optionally call tests
    FILE* auditFile = ConfigureAudit();
    Parser(auditFile);
    //reset Audit_Control file
    return 0;
}