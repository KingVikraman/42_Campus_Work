/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:17:38 by rvikrama          #+#    #+#             */
/*   Updated: 2024/08/13 22:53:02 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

/*********** CHAR HEADERS ***********/
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_line(char *buffer);

/*********** SIZE_T HEADERS ***********/
size_t	ft_strlen(const char *String);

/*********** VOID HEADERS ***********/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementNum, size_t elementSize);

#endif

/*
Objective of the Project..

——The goal of the “Get Next Line” project is 
to create a function that reads a text file 
and returns one line at a time. This is crucial
 for handling files in programming,especially 
 when dealing with large files or streams where
  you don't want to load everything into memory at once.



Key Concepts
1. File Handling Basics:
    * Opening a File: This involves accessing 
	a file so you can read from or write to it.
    * Reading from a File: This means extracting
	 data from the file. You might read the entire
	  file at once or read it piece by piece 
	  (line by line, for example).
    * Closing a File: This is important to free up
	 system resources and ensure that all data is 
	 properly saved and the file is not left open.

2. Function Requirements:
    * Return One Line at a Time: Your function 
	 should read the file incrementally, returning
	 one line at a time each time it is called.
    * Handle Large Files Efficiently: Instead 
	  of reading the entire file into memory, your
	  function should be able to read chunks and manage
	  the file efficiently.

Detailed Steps
1. Open the File:
    * Use appropriate system calls or library functions
	 to open the file and get a file descriptor.

2. Read the File:
    * Implement logic to read data from the file.
	 This might involve reading chunks of data into a buffer.
    * Detect the end of a line by looking for newline characters.
	
3. Store and Return the Line:
    * Extract the line from the buffer and return it.
    * Keep track of your position in the file so you 
	  can continue from where you left off on 
	  subsequent calls.

4. Handle End of File (EOF):
    * When the end of the file is reached, return NULL
	 or an appropriate indicator to signify that there 
	 are no more lines to read.

5. Close the File:
    * Ensure that you properly close the file after 
	you’re done with reading to release resources.

*/

/*
What is Static Variables?

* What is a Static Variable? In programming, a 
static variable is the one allocated “statically,” 
which means its lifetime is throughout the program run.
 It is declared with the 'static' keyword and persists its 
 value across the function calls.

What is static variable vs dynamic variable?

* Static variables have a fixed size during the runtime 
and cannot be changed. Dynamic variables can change size 
during runtime, which allows for efficient usage of memory.
 Dynamic variables often require the use of pointers, which c
 an make the code more complex and harder to understand.

*/
