/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:47:56 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/25 13:36:29 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listmem.h"

// if alloc node fail then free mem

static t_mem	*lm_create_node(void *mem)
{
	t_mem	*node;

	node = malloc(sizeof(t_mem));
	if (node == NULL)
	{
		free(mem);
		return (NULL);
	}
	node->mem = mem;
	node->next = NULL;
	return (node);
}

static void	lm_insert_node(t_mem **head, t_mem *node)
{
	t_mem	*oldhead;

	if (node == NULL)
		return ;
	oldhead = *head;
	*head = node;
	(*head)->next = oldhead;
}

void	*lm_malloc(size_t byte, size_t n, t_mem **head)
{
	t_mem		*node;
	void		*mem;

	if (byte == SIZE_MAX || n == SIZE_MAX)
		return (NULL);
	mem = malloc(byte * n);
	if (mem == NULL)
		return (NULL);
	node = lm_create_node(mem);
	if (node == NULL)
		return (NULL);
	lm_insert_node(head, node);
	return (mem);
}

static void	*ft_memset(void *ptr, int c, size_t byte)
{
	size_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (i < byte)
	{
		((unsigned char *)ptr)[i] = ((unsigned char *)&c)[0];
		i++;
	}
	return (ptr);
}

void	*lm_calloc(size_t byte, size_t n, t_mem **head)
{
	t_mem		*node;
	void		*mem;

	if (byte == SIZE_MAX || n == SIZE_MAX)
		return (NULL);
	byte *= n;
	mem = malloc(byte);
	if (mem == NULL)
		return (NULL);
	node = lm_create_node(mem);
	if (node == NULL)
		return (NULL);
	lm_insert_node(head, node);
	return (ft_memset(mem, 0, byte));
}

/*
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst || size < 1 || !src)
		return (srclen);
	i = 0;
	if (size > srclen + 1)
		size = srclen + 1;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[size - 1] = 0;
	return (srclen);
}

char	*ft_strdup(const char *src, t_listmem **root)
{
	size_t	len;
	char	*dest;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dest = lm_malloc(sizeof(char), (len + 1), root);
	if (!dest)
		return (NULL);
	(void)ft_strlcpy(dest, src, len + 1);
	return (dest);
}

#include <stdio.h>
int main(int ac, char **av)
{
	t_listmem	*root = NULL;
	char *test;
	int	i = 0;
	while (i < ac)
	{
		if (i == 0)
		{
			test = ft_strdup(av[i], &root);
			i++;
			continue;
		}
		(void)ft_strdup(av[i], &root);
		i++;
	}
	lm_free(test, &root);
	t_listmem *run = root;
	while (run)
	{
		printf("%s -> ", run->mem);
		run = run->next;
	}
	lm_flush(&root);
	return (0);
}
*/