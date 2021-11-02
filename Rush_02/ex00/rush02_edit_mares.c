/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush02_edit_mares.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/26 14:51:17 by evan-der      #+#    #+#                 */
/*   Updated: 2020/09/27 20:10:36 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	read_lines(char *str);
int		len_dict();
void	read_dictionary();
void	input_error();
void	ft_putchar(char c);


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	input_error()
{
	write(1, "Error\n", 6);
}

void	read_dictionary()
{
	//Declare variables	
	int count; // To store the amount of characters in dict file
	int i; //This will be an iterator in the while loop
	char *ptr; //This pointer will be used to allocate memory with malloc
	int fd; // File descriptor needed to open, read and close the dictionary file. 

	count = len_dict(); // Len_dict function counts the amount of characters in the dictionary
	printf("Count = %d\n", count);
	ptr = (char*) malloc(count * sizeof(char)); // Allocating memory using the count variable.
	i = 0;
	
	char buf[count]; //Make a buffer with the count
	
	fd = open("numbers.dict", O_RDONLY); // Open the dictionary file
	read(fd, buf, count); // Read it in the buf variable, which now has the right size
	close(fd); // Close the dictionary file
	//In the below while loop, the contents of buff willl be stored in ptr, which was created with malloc
	while (i < count)
	{
		*(ptr + i) = *(buf + i); 
	   	i++;	
	}
	printf("%s\n", ptr);
}


// This function calculates how many characters are in a string
int		len_dict()
{
	int fd;
	int i;
	int count;
	int result;

	i = 0;
	count = 0;
	result = 1;
	//Open the file
	fd = open("numbers.dict", O_RDONLY, 0777);	
		while (result != 0)
		{
			char buf[count];
			result = read(fd, (buf + i), 1);
			count++;
			i++;
		}
	//Close the file
	close(fd);
	return (count - 1);	
}	

int		main(int argc, char *argv[])
{
	char *input;

	input = argv[1];
//	ft_searchar(input);
	
	// input validation, now only for 1 argument = value to be converted, not for new dictionary.
	// TO DO check if argument is positive and not too big.
	if(argc == 2)
	{
		read_dictionary();
	}
	else
		input_error();
	return (0);
}
/************************************************************************************************\
* input validation: check for amount of given arguments, check if given value is positive,
* 		check for correct size of given value (unsigned int, long long?)
* open and read dictionary (and of course, close ;)) into dict-string
* error if trouble with dictionary parsing
* function to count digits of given value
* function to divide given value to seperate digits in ones, tens, hundreds etc
* for hundreds and bigger: function to split first number from hundred/thousand/million etc
* starting with biggest, function to find the given split numbers in dict-string
* error if given dictionary doesn't provide solution
* function to print out the matching characters from dict-string on output
*
* Note: free the malloc!
*
* Make Makefile :)																							   
\***********************************************************************************************/
