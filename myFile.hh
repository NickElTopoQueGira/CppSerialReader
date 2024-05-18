#ifndef MYFILE_H
#define MYFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctime>
#include <sstream>

/**
 * Function: createFileName
 * Input values: 
 * Output values: filename
 * Return values: error number
 * Description: 
 * Function to create the file name with the date and time of cration. 
 * in the format: dd/mm/yyy_h:m:s.txt
 */
int creteFileName (char* filename);

/**
 * Function: createFile
 * Input values: file path
 * Output values: 
 * Return values: error number
 * Description: 
 * Creates the file at the location specified in input
 */
int createFile(char* path);

/**
 * Function: writeInAFile
 * Input values: file log path, text to write
 * Output values:
 * Return values: error number
 * Description: 
 * Adds to the file specified as input the message
 */
int writeInAFile(char* path, char* text);

/**
 * Function: isFileExist
 * Input values: path
 * Output values: 
 * Return values: error number
 * Description: 
 * Verify existence of the file.
 */
int isFileExist(char* path);

#endif