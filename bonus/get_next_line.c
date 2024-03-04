/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:10 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/03 15:58:59 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_backup(int fd, char *buff, char *backup)
{
	int		count;
	char	*temp;

	count = 1;
	while (count > 0 && !ft_strchr(backup, '\n'))
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free(buff);
			free(backup);
			return (NULL);
		}
		else if (count == 0)
			break ;
		buff[count] = 0;
		temp = backup;
		backup = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
	}
	free(buff);
	return (backup);
}

char	*extract_line(char *backup)
{
	char	*line;
	int		count;

	count = 0;
	while (backup[count] != '\n' && backup[count] != '\0')
		count++;
	if (backup[count] == '\n')
		count++;
	line = ft_substr(backup, 0, count);
	return (line);
}

char	*re_backup(char *backup)
{
	int		c;
	char	*temp;

	c = 0;
	while (backup[c] != '\n' && backup[c])
		c++;
	if (!backup[c] || (backup[c] == '\n' && backup[c + 1] == '\0'))
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	temp = ft_strdup(&backup[c + 1]);
	free(backup);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = malloc(sizeof(char) * (((size_t)BUFFER_SIZE) + 1));
	if (!buff)
		return (0);
	backup = read_backup(fd, buff, backup);
	if (!backup)
		return (0);
	line = extract_line(backup);
	if (!line)
		return (0);
	backup = re_backup(backup);
	return (line);
}
