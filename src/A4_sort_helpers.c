#include "A4_sort_helpers.h"

#include "stdlib.h"
#include "string.h"
#include "assert.h"

#define SEM_PREFIX "YUDI_"
#define TEMPFILE_PREFIX "YUDI_"

#define NUM_SEMAPHORES 26
const char* lower_chars = "abcdefghijklmnopqrstuvwxyz";
const char* upper_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
sem_t *semaphores[NUM_SEMAPHORES + 1];

// Function: read_all() 
// Provided to read an entire file, line by line.
// No need to change this one.
void read_all( char *filename ) {    
  FILE *fp = fopen( filename, "r" );
  int curr_line = 0;
	
  while( curr_line < MAX_NUMBER_LINES && 
         fgets( text_array[curr_line], MAX_LINE_LENGTH, fp ) )
    {
      curr_line++;
    }
	
  text_array[curr_line][0] = '\0';
  fclose(fp);
}

// Function: read_all() 
// Provided to read only the lines of a file staring with first_letter.
// No need to change this one.
void read_by_letter( char *filename, char first_letter ){

  FILE *fp = fopen( filename, "r" );
  int curr_line = 0;
  text_array[curr_line][0] = '\0';
	
  while( fgets( text_array[curr_line], MAX_LINE_LENGTH, fp ) )
    {
      if( text_array[curr_line][0] == first_letter )
        {
          curr_line++;
        }
      
      if( curr_line == MAX_NUMBER_LINES )
        {
          sprintf( buf, "ERROR: Attempted to read too many lines from file.\n" );
          write( 1, buf, strlen(buf) );
          break;
        }
    }
  
  text_array[curr_line][0] = '\0';
  fclose(fp);
}

// YOU COMPLETE THIS ENTIRE FUNCTION FOR Q1.
void sort_words( ) {
  size_t num_words = 0;
  for (size_t i = 0; i < MAX_NUMBER_LINES; ++i)
    if (text_array[i][0] == '\0')
      {
        num_words = i;
        break;
      }
  
  for (size_t i = 0; i < num_words; ++i)
    for (size_t j = i + 1; j < num_words; ++j)
      {
        if (strcmp(text_array[i], text_array[j]) > 0)
          {
            const size_t buffer_size = sizeof(char) * MAX_LINE_LENGTH;
            char* swap_buffer = (char*) malloc(buffer_size);
            assert(swap_buffer != NULL);
            memset(swap_buffer, '\0', buffer_size);
            strcpy(swap_buffer, text_array[i]);
            strcpy(text_array[i], text_array[j]);
            strcpy(text_array[j], swap_buffer);
            free(swap_buffer);
          }
      }
}

// YOU COMPLETE THIS ENTIRE FUNCTION FOR Q2.
int initialize( ){
  // Remove the current place-holder code, and write your own.
  sprintf(buf, "Initializing.\n"  );
  write(1, buf, strlen(buf));

  sem_unlink(SEM_PREFIX "A"); sem_unlink(SEM_PREFIX "B");
  sem_unlink(SEM_PREFIX "C"); sem_unlink(SEM_PREFIX "D");
  sem_unlink(SEM_PREFIX "E"); sem_unlink(SEM_PREFIX "F");
  sem_unlink(SEM_PREFIX "G"); sem_unlink(SEM_PREFIX "H");
  sem_unlink(SEM_PREFIX "I"); sem_unlink(SEM_PREFIX "J");
  sem_unlink(SEM_PREFIX "K"); sem_unlink(SEM_PREFIX "L");
  sem_unlink(SEM_PREFIX "M"); sem_unlink(SEM_PREFIX "N");
  sem_unlink(SEM_PREFIX "O"); sem_unlink(SEM_PREFIX "P");
  sem_unlink(SEM_PREFIX "Q"); sem_unlink(SEM_PREFIX "R");
  sem_unlink(SEM_PREFIX "S"); sem_unlink(SEM_PREFIX "T");
  sem_unlink(SEM_PREFIX "U"); sem_unlink(SEM_PREFIX "V");
  sem_unlink(SEM_PREFIX "W"); sem_unlink(SEM_PREFIX "X");
  sem_unlink(SEM_PREFIX "Y"); sem_unlink(SEM_PREFIX "Z");

  semaphores[0]  = sem_open(SEM_PREFIX "A", O_CREAT, S_IRUSR | S_IWUSR, 1);
  semaphores[1]  = sem_open(SEM_PREFIX "B", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[2]  = sem_open(SEM_PREFIX "C", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[3]  = sem_open(SEM_PREFIX "D", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[4]  = sem_open(SEM_PREFIX "E", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[5]  = sem_open(SEM_PREFIX "F", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[6]  = sem_open(SEM_PREFIX "G", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[7]  = sem_open(SEM_PREFIX "H", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[8]  = sem_open(SEM_PREFIX "I", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[9]  = sem_open(SEM_PREFIX "J", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[10] = sem_open(SEM_PREFIX "K", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[11] = sem_open(SEM_PREFIX "L", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[12] = sem_open(SEM_PREFIX "M", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[13] = sem_open(SEM_PREFIX "N", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[14] = sem_open(SEM_PREFIX "O", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[15] = sem_open(SEM_PREFIX "P", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[16] = sem_open(SEM_PREFIX "Q", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[17] = sem_open(SEM_PREFIX "R", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[18] = sem_open(SEM_PREFIX "S", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[19] = sem_open(SEM_PREFIX "T", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[20] = sem_open(SEM_PREFIX "U", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[21] = sem_open(SEM_PREFIX "V", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[22] = sem_open(SEM_PREFIX "W", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[23] = sem_open(SEM_PREFIX "X", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[24] = sem_open(SEM_PREFIX "Y", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[25] = sem_open(SEM_PREFIX "Z", O_CREAT, S_IRUSR | S_IWUSR, 0);
  semaphores[26] = sem_open(SEM_PREFIX "DONE", O_CREAT, S_IRUSR | S_IWUSR, 0);
  
  return 0;
}

// YOU MUST COMPLETE THIS FUNCTION FOR Q2 and Q3.   
int process_by_letter( char* input_filename, char first_letter ){
  // For Q2, keep the following 2 lines in your solution (maybe not at the start).
  // Add lines above or below to ensure the "This process will sort..." lines
  // are printed in the right order (alphabetical).
  size_t semaphore_index = -1 ;
  for (size_t i = 0; i < NUM_SEMAPHORES; ++i)
    if ((first_letter == upper_chars[i]) || (first_letter == lower_chars[i]))
      {
        semaphore_index = i;
        break;
      }
  assert((semaphore_index >= 0) && (semaphore_index < NUM_SEMAPHORES));
  sem_t* current_semaphore = semaphores[semaphore_index];
  sem_t* next_semaphore = next_semaphore = semaphores[semaphore_index + 1];

  sem_wait(current_semaphore);
  
  sprintf( buf, "This process will sort the letter %c.\n",  first_letter );
  write(1,buf,strlen(buf));
  
  // For Q3, uncomment the following 2 lines and integrate them with your overall solution.
  read_by_letter( input_filename, first_letter );
  sort_words();

  char* temp_file_name = (char*) malloc(sizeof(char) * 256);
  assert(temp_file_name != NULL);
  sprintf(temp_file_name, TEMPFILE_PREFIX "%c", first_letter);
  int temp_file = open(temp_file_name, O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR);
  for (size_t i = 0; i < MAX_NUMBER_LINES; ++i)
    {
      if (strcmp(text_array[i], "\0") != 0)
        {
          write(temp_file, text_array[i], sizeof(char) * strlen(text_array[i]));
        }
    }
  close(temp_file);
  free(temp_file_name);

  sem_post(next_semaphore);
  
  return 0;
}

// YOU COMPLETE THIS ENTIRE FUNCTION FOR Q2 and Q3.
int finalize( ){
  // For Q2, keep the following 2 lines in your solution (maybe not at the start).
  // Add lines above or below to ensure the "Sorting complete!" line
  // is printed at the very end, after all letter lines.
  sem_wait(semaphores[NUM_SEMAPHORES]);
  
  sprintf( buf, "Sorting complete!\n" );
  write( 1, buf, strlen(buf) );

  for (size_t i = 0; i <= NUM_SEMAPHORES; ++i)
    sem_close(semaphores[i]);

  // For Q3, come up with a way to accumulate the sorted results from each
  // letter process and print the overal sorted values to standard out.
  // You are not allowed to read from the input file, or call sort_words
  // directly from this function.
  for (int i = 0; i < 26; ++i)
    {
      char* filename = (char*) malloc(sizeof(char) * 256);
      assert(filename != NULL);
      sprintf(filename, TEMPFILE_PREFIX "%c", 'a' + i);
      int file = open(filename, O_RDONLY);
      char buffer;
      while (read(file, &buffer, sizeof(char)))
        {
          write(STDOUT_FILENO, &buffer, sizeof(char));
        }
      close(file);
      remove(filename);
      free(filename);
    }

  return 0;
}

