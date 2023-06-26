/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:05:48 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/27 00:31:24 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
GNL INSTRUCTION
0: Check bad fd, if yes then return NULL

1: Reading BUFFER -> sb_readone()
- 1. use read() to read file
- 2. if EOF or ERROR then ft_free(buffer)
- 3. return byte from read()

2: Reading oneline (until has \n) -> sb_readline()
- 1. use sb_readone() to read text until has \n
- 2. if ERROR found then ft_free everything and return NULL
- 3. if EOF meet but no \n then just return

3: Serparate buffer to two part
- 1. before \n to line -> ft_strndup
- 2. after \n to temp -> ft_strndup
- 3. ft_free current text
- 4. pointting text to temp

4: Return line and save text
*/

// merge text and buff together
// and ft_free input text & buffer

static char	*sb_buffmanage(char *text, char *buff, size_t bs, t_list **head)
{
	char	*str;
	size_t	size;

	size = ft_strclen(text, 0) + bs + 1;
	str = ft_strjoin(text, buff, head);
	ft_free(text, head);
	ft_free(buff, head);
	return (str);
}

// read function is in here
// return byte of what it read

static ssize_t	sb_readone(int fd, char **pbuffer, t_list **head)
{
	ssize_t	byte;

	*pbuffer = ft_malloc(sizeof(char), BUFFER_SIZE + 1, head);
	if (!(*pbuffer))
		return (-1);
	byte = read(fd, *pbuffer, BUFFER_SIZE);
	if (byte == -1 || byte == 0)
	{
		ft_free(*pbuffer, head);
		return (byte);
	}
	(*pbuffer)[byte] = 0;
	return (byte);
}

// build string until it has \n + extra
// EOF & Normal give text 
// ERROR or EOF with text = NULL give NULL

static char	*sb_readline(int fd, char *text, t_list **head)
{
	ssize_t	len;
	size_t	i;
	char	*buffer;
	char	flag;

	while (1)
	{
		len = sb_readone(fd, &buffer, head);
		if (len == 0)
			break ;
		if (len == -1)
		{
			ft_free(text, head);
			return (NULL);
		}
		i = ft_strclen(buffer, '\n');
		flag = (buffer[i] != '\n');
		text = sb_buffmanage(text, buffer, len, head);
		if (!flag || !text)
			break ;
	}
	return (text);
}

// if separate line ft_malloc fail
// then ft_free everything and return NULL

static char	*sb_failsafe(char *text, char *line, char *temp, t_list **head)
{
	ft_free(text, head);
	if (line)
		ft_free(line, head);
	if (temp)
		ft_free(temp, head);
	return (NULL);
}

// text -> line + temp
// ft_free(text)
// temp -> text
// return line

char	*get_next_line(int fd, t_list **head)
{
	size_t		i;
	size_t		templen;
	char		*line;
	char		*temp;
	static char	*text;

	if (fd <= -1 || fd > OPEN_MAX)
		return (NULL);
	text = sb_readline(fd, text, head);
	if (!text)
		return (NULL);
	i = ft_strclen(text, '\n');
	templen = ft_strclen(&text[i + (text[i] != 0)], 0);
	line = ft_strndup(text, i + (text[i] != 0), head);
	temp = ft_strndup(&text[i + (text[i] != 0)], templen, head);
	if (!line || !temp)
		return (sb_failsafe(text, line, temp, head));
	ft_free(text, head);
	text = temp;
	if (text[0] == 0)
		text = sb_failsafe(text, NULL, NULL, head);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd = open("test", O_RDONLY);
// 	char *print;
// 	print = get_next_line(fd);
// 	while (print)
// 	{
// 		printf("%s",print);
// 		ft_free(print);
// 		print = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
