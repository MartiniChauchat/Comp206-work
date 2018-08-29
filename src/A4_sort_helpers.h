#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <math.h>
#include <errno.h>

#define MAX_NUMBER_LINES 100000
#define MAX_LINE_LENGTH  200
char text_array[MAX_NUMBER_LINES][MAX_LINE_LENGTH];
char buf[MAX_LINE_LENGTH];

void read_all( char *filename );
void read_by_letter( char *filename, char first_letter );

void sort_words( );
int initialize( );
int process_by_letter( char* input_filename, char first_letter );
int finalize( );
