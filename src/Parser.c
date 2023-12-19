#include "Parser.h"
/**
 * Processes output from audit pipe user
 * @author Fevronia Van Sickle 
 * @version 12/19
 */


/**
 * take in events from audit pipe and print out results
*/
void Parser(FILE* auditFile){


    //code for processing audit tokens from @ashish-gehani on github 

    FILE* output = stdout;
    FILE* errors = stderr;
    char* delimiter = ",";
    int raw = 1; // Convert raw to string
    int shortForm = 1; // Use short form
    u_char* buffer;
    int remainingRecords = 1;
    int recordLength;
    int recordBalance;
    int processedLength;
    int tokenCount;
    int fetchToken;
    tokenstr_t token;

    //continues to print out audit tokens while there are still tokens to print
    //will continue until user halts the program
    while (remainingRecords) {

        // Read an audit record
        recordLength = au_read_rec(auditFile, &buffer);
        if (recordLength == -1) {
            remainingRecords = 0;
            break;
        }

        recordBalance = recordLength;
        processedLength = 0;
        tokenCount = 0;

        while (recordBalance) {

            // Extract a token from the record
            fetchToken = au_fetch_tok(&token, buffer + processedLength, recordBalance);

            if (fetchToken == -1) {
                // fprintf(errors, "Error fetching token.\n");
                break;
            }

            // Print the long form of the token as a string
            au_print_tok(output, &token, delimiter, raw, shortForm);
            fprintf(output, "\n");

            tokenCount++;
            processedLength += token.len;
            recordBalance -= token.len;
        }

        free(buffer);
        // fprintf(output, "\n");
    }

    fclose(auditFile);
    fprintf(output, "Provenance collection has ended.\n");

    
}