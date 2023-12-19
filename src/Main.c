#include <stdio.h>
#include "ConfigureAudit.c"
#include "Parser.c"
/**
 * Main file for SecurityAuditing/src
 * @author Fevronia Van Sickle 
 * @version 12/19
 */

/**
 * taps into and configures audit pipe and processes events
*/
int main(int argc, char *argv[]){

    FILE* auditFile = ConfigureAudit();
    Parser(auditFile);
 
    return 0;
}