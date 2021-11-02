/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dm_sun_morning_main.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/20 11:58:51 by dmalacov      #+#    #+#                 */
/*   Updated: 2020/09/20 20:48:26 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	error()
{
	write(1, "Error\n", 6);
}

void	process_input(char *top, char *bottom, char *left, char *right, char *input)
{
	int		i;
	int		j;
	char	c;
	char	*without_spaces;

	c = ' ';
	without_spaces = (char*) malloc(16);

	i = j = 0;
	while (input[i] != '\0')
	{
		if ((input[i] % 2) == 0 && input[i] >= '1' && input[i] <= '4')
		{
			without_spaces[j] = input[i];
			i++;
			j++;
		}
		else if ((input[i] % 2) != 0 && input[i] == c)
		{
			i++;
		}
		else
		{
			error();
			return ;
		}
	}
	
	i = j = 0;
	while (i < 4)
	{
		top[i] = without_spaces[j];
		i++;
		j++;
	}
	i = 0;
	while (i < 4)
	{
		bottom[i] = without_spaces[j];
		i++;
		j++;
	}
	i = 0;
	while (i < 4)
	{
		left[i] = without_spaces[j];
		i++;
		j++;
	}
	i = 0;
	while (i < 4)
	{
		right[i] = without_spaces[j];
		i++;
		j++;
	}
	free(without_spaces);

	//additional checks to be performed: 
	// 1. where the input contains a '1' on the first position in the string top, bottom, left or right - and thus next to a corner of the array (position [0][0], [0][3], [3][0] or [3][3]), there must be a '1' on the corresponding position. Example: bottom = "1222", that means that left[3] must also be '1', otherwise error
	// 2. each of the strings top, bottom, left and right must contain one '1'
	// 3. there must be no more than one '4' in each of top, bottom, left and right, and no more than two '4' in all of them together
}

void    puzzle(char *top, char *bottom, char *left, char *right, char **array)
{
    // checking pairs of instructions (1-4, 1-3 etc.)
    
    int c;
    int	r;

    c = 0;
    while(c < 4)
    {
        if(top[c] == '1')
        {
            if(bottom[c] == '1')
			{
				error();
			}
            else
            {
                *(array[0] + c) = '4';
                if(bottom[c] == '4')
                {
                    *(array[1] + c) = '3';
                    *(array[2] + c) = '2';
                    *(array[3] + c) = '1';
                }
                if(bottom[c] == '2')
                    *(array[3] + c)  = '3';
            }
        }
        if(top[c] == '2')
        {
            if(bottom[c] == '1' || bottom[c] == '4')
			{
				error();
			}
            else
            {
                if(bottom[c] == '3')
                    *(array[1] + c) = '4';
            }
        }
        if(top[c] == '3')
        {
            if(bottom[c] == '3' || bottom[c] == '4')
			{
				error();
			}
			else
            {
                if(bottom[c] == '1')
                    *(array[3] + c) = '4';
                if(bottom[c] == '2')
                    *(array[2] + c) = '4';
            }
        }
        if(top[c] == '4')
        {
            if(bottom[c] != '1')
			{
				error();
			}
			else
            {
                *(array[0] + c) = '1';
                *(array[1] + c) = '2';
                *(array[2] + c) = '3';
                *(array[3] + c) = '4';
            }
        }
        c++;
    }
    r = 0;
    while(r < 4)
    {
        if(left[r] == '1')
        {
            if(right[r] == '1')
			{
				error();
			}
			else
            {
                array[r][0] = '4';
                if(right[r] == '4')
                {
                    array[r][1] = '3';
                    array[r][2] = '2';
                    array[r][3] = '1';
                }
                if(right[r] == '2')
                    array[r][3] = '3';
            }
        }
        if(left[r] == '2')
        {
            if(right[r] == '1' || right[r] == '4')
            {
				error();
			}
            else
            {
                if(right[r] == '3')
                array[r][1] = '4';
            }
            if(left[r] == '3')
            {
                if(right[r] == '3' || right[r] == '4')
				{
					error();
				}
				else
                {
                    if(right[r] == '1')
                        array[r][3] = '4';
                    if(right[r] == '2')
                        array[r][2] = '4';
                }
            }
            if(left[r] == '4')
            {
                if(right[r] != '1')
				{
					error();
				}
				else
                {
                    array[r][0] = '1';
                    array[r][1] = '2';
                    array[r][2] = '3';
                    array[r][3] = '4';
                }
            }
            r++;
        }
    }
}

void    three_of_a_kind(char **array)
{
    char      c;
    int        i_r;
    int        i_c;
    int        how_many;
    int        row;
    int        col;

    c = '1';
    how_many = row = col = 0;
    while (c <= '4')
    {
    i_r = 0;
    while (i_r < 4)
    {
        i_c = 0;
        while (i_c < 4)
        {
            if (array[i_r][i_c] == c)
            {
                how_many++;
                row = row + i_r;
                col = col + i_c;
            }
            i_c++;
        }
        i_r++;
    }
    if (how_many == 3)
    {
        row = 6 - row;
        col = 6 - col;
        *(array[row] + col) = c;
    }
    c++;
    }
}

void    check_rows_and_columns(char **array)
{
    // filling every row and column till 10
    int r;
    int c;
    int answer;
    int c_count;
    int r_count;
    int count_zeros;

    r = 0;
    count_zeros = 0;
    while (r < 4)
    {
        c_count = 0;
        r_count = 0;
        c = 0;
        answer = 0;
        while (c < 4)
        {
            if (array[r][c] == '0')
            {
                c_count = c;
                r_count = r;
                count_zeros++;
            }
            answer = answer + array[r][c] - 48;
            c++;
        }
        if(count_zeros == 1)
        {
            if(answer == 9)
                array[r_count][c_count] = '1';
            if(answer == 8)
                array[r_count][c_count] = '2';
            if(answer == 7)
                array[r_count][c_count] = '3';
            if(answer == 6)
                array[r_count][c_count] = '4';
        }
        r++;
    }
}

int		main(int argc, char *argv[])
{
	char	*top;
	char	*bottom;
	char	*left;
	char	*right;
	char	*input;
    char	row1[4];
	char	row2[4];
	char	row3[4];
	char	row4[4];
	char	*array[4];
	int i;
    int j;
    
	top = (char*) malloc(4);
	bottom = (char*) malloc(4);
	left = (char*) malloc(4);
	right = (char*) malloc(4);

	array[0] = row1;
	array[1] = row2;
	array[2] = row3;
	array[3] = row4;
	
	input = argv[1];

	if (argc == 2)
	{
        process_input(top, bottom, left, right, input);
		i = j = 0;
        while (i < 4)
        {
            while (j < 4)
            {
                array[i][j] = '0';
                j++;
            }
            i++;
            j = 0;
        }
        puzzle(top, bottom, left, right, array);
        check_rows_and_columns(array);
        three_of_a_kind(array);
        //repeat functions check_rows_and_columns and three_of_a_kind until one of the two occurs: EITHER all positions are filled (i.e., when all filled-in values added together are 40, OR the program cannot find solution and the number of filled in positions does not change from one round to another.)
        //print the solved puzzle in the correct format using the write function
	}
	else
	{
		error();
	}
	return (0);
}
