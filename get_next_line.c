#include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>


char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	size_t  readed;
	size_t		i;
	int		tmp;
	char	*line;
	static char *old_line = NULL;
	static size_t  full_readed = 0;

	line = old_line;
	old_line = NULL;
	while (1)
	{
		readed = read(fd, &buffer, BUFFER_SIZE);
		if (readed == 0) {
			return line;
		}
		if (readed < 0) {
			return NULL;
		}
		i = 0;
		while (i < readed && buffer[i] != '\n')
			i++;
		if ( i == readed)
		{
			ft_realloc_and_copy();
			line[full_readed + i] = buffer[i];
			full_readed += readed;
		}
		else {
			tmp = i + 1;
			ft_realloc_and_copy();
			i = tmp;
			full_readed = readed - i;
			old_line = malloc(sizeof(char) * (readed - i + 1));
			old_line[readed - i] = 0;
			while (i < readed)
			{
				old_line[i - tmp] = buffer[i];
				i++;
			}
			return line;
		}
	}
		
}

void	*ft_realloc_and_copy(int fd, size_t start)
{
	
	line = ft_realloc(line, sizeof(char) * (full_readed + i + 1));
	line[full_readed + i--] = 0;
	while (i > 0)
	{
		line[full_readed + i] = buffer[i];
		i--;
	}
	line[full_readed + i] = buffer[i];
}

// int main()
// {
//     int fd;
//     char *line;

//     fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Erreur lors de l'ouverture du fichier");
//         return 1;
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("-- %s\n", line);
//         free(line);
//     }
//     close(fd);
// 	return 0;
// }