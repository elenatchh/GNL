#include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>


char	*get_next_line(int fd)
{
	char					buffer[BUFFER_SIZE];
	size_t 					readed;
	static struct s_stat	raf;
	char					*ret;


	ret = get_current_line(&raf, NULL, 0);
	while (ret == NULL)
	{
		readed = read(fd, &buffer, BUFFER_SIZE);
		if (readed == 0)
			return (raf.line);
		if (readed < 0)
			return (NULL);
		ret = get_current_line(&raf, buffer, readed);
	}
	return (ret);
}

char	*get_current_line(struct s_stat *raf, char *buffer, size_t readed)
{	
	size_t	i;

	if (buffer == NULL)
	{
		buffer = raf->old_line;
		readed = raf->full_readed;
		raf->old_line = NULL;
		raf->full_readed = 0;
	}
	i = 0;
	while (i < readed && buffer[i] != '\n')
		i++;
	if (i == readed)
	{
		raf->line = ft_r_and_c(raf->line, sizeof(char) * raf->full_readed + i, i, buffer);
		raf->full_readed += readed;
		return (NULL);
	}
	return (ft_parse_line( buffer, i, readed, raf));

}

char	*ft_parse_line(char *buffer, size_t i, size_t readed, struct s_stat *raf)
{
	size_t	tmp;

	tmp = i + 1;
	raf->line = ft_r_and_c(raf->line, sizeof(char) * (raf->full_readed + i + 1), i, buffer);
	raf->full_readed = readed - i;
	raf->old_line = malloc(sizeof(char) * (readed - i + 1));
	raf->old_line[readed - i] = 0;
	while (i < readed)
	{
		raf->old_line[i - tmp] = buffer[i];
		i++;
	}
	return (raf->line);
}

char	*ft_r_and_c(char *str,  size_t n, size_t end, char *buffer)
{
	char	*tmp;
	int		i;

	tmp = malloc(n);
	i = 0;
	while (str && str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	if (str)
		free(str);
	if (end == 0)
		return (NULL);

	str = tmp;
	str[i + end--] = 0;

	while (end > 0)
	{
		str[i + end] = buffer[end];
		end--;
	}
	str[i + end] = buffer[end];
	return (str);
}

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    while ((line = get_next_line(0)) != NULL)
    {
        printf("-- %s\n", line);
        free(line);
    }
    close(fd);
	return 0;
}

