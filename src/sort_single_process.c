//
// FILE: sort_single_process.c
// This is the simplest main we could think of to give you a warm up and practice with
// sorting strings. Leave this file unchanged and just complete sort_words for Q1.
//

#include "A4_sort_helpers.h"

int main( int argc, char *argv[] ){

	if( argc != 2 ){
		printf( "Usage: %s input_file\n", argv[0] );
		return 1;
	}

	read_all( argv[1] );
	sort_words( );

	int curr_line = 0;
	while( text_array[curr_line][0] != '\0' ){
		sprintf( buf, "%s",  text_array[curr_line] );
		write(1,buf,strlen(buf));
		curr_line++;
	}

	sprintf( buf, "Sorting complete!\n" );
	write( 1, buf, strlen(buf) );

	return 0;
}
