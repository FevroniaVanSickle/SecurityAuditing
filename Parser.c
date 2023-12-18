#include <Parser.h>

/**
 * take in events from audit pipe and print out results
*/

//read an event record from a file descriptor and put the content in the buffer buf 
//passed as parameter (which must be freed after use). 
//The function return the number of bytes read.
int au_read_rec(FILE *fp, u_char **buf);

//To read the buffer with the record inside we have to fetch every token on it sequentially, 
//using the au_fetch_tok
int au_fetch_tok(tokenstr_t *tok, u_char *buf, int len);

//we have a token, we can print it on a file descriptor
void au_print_tok(FILE *outfp, tokenstr_t *tok, char *del, char raw, char sfrm);

//special way of printing flags that will take an additional parameter
void au_print_flags_tok(FILE *outfp, tokenstr_t *tok, char *del, int oflags);


//print out tokens in file 

//print out warning 