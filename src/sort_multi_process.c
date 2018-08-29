#include "A4_sort_helpers.h"

int main( int argc, char *argv[] ){

	if( argc != 2 ){
		printf( "Usage: %s input_file output_file\n", argv[0] );
		return 1;
	}

    // This is the call to your initialize function. It gives you a chance
    // to setup any variables and files you may want to use to coordinate your
    // processes. Note that it occurs before any fork() has been called, so you
    // know it's run in the original parent process.
	int ret = initialize( );
	if( ret != 0 ){
		sprintf(buf, "ERROR: initialize returned non-zero %d.\n", ret );
		write(1, buf, strlen(buf));
		return ret;
	}

    // The following code spawns the 32 processes (the original parent plus 31 more).
    // Each process is assigned an ID. The first parent will have 0.
	int f;
	int fork_levels = 5;
	int id = 0;
	for( int fork_level=0; fork_level<fork_levels; fork_level++ ){
		
		f=fork();
		if( f == 0 ){
			id += pow(2,fork_level);
		}
		else if( f < 0 ){
			sprintf(buf, "ERROR: f was negative at iteration %d.\n", fork_level );
			write(1, buf, strlen(buf));
			return 1;
		}
	}

    // This code calls your process_by_letter 26 times, one for each small alphabet letter.
    // Note that each call is made by a separate process.
	if( id >= 1 && id < 27 ){
		ret = process_by_letter( argv[1], 'a'+ id -1 );
		if( ret != 0 ){
			sprintf(buf, "ERROR: process_by_letter returned non-zero %d.\n", ret );
			write(1, buf, strlen(buf));
			return ret;
		}
	}

    // This code calls your finalize function once. Note this is by the original parent.
	if( id == 0 ){
		ret = finalize( );
		if( ret != 0 ){
			sprintf(buf, "ERROR: finalize returned non-zero %d.\n", ret );
			write(1, buf, strlen(buf));
			return ret;
		}
	}

	return 0;
}
