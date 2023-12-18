#include <stdio.h>
#include "ConfigureAudit.c"
#include "Parser.c"

int main(int argc, char *argv[]){
    //optionally call tests
    FILE* auditFile = ConfigureAudit();
    Parser(auditFile);
    //reset Audit_Control file
    return 0;
}