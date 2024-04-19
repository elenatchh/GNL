#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	size_t  readed;
	int		i;
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
		while (buffer[i] != '\n' && i < readed)
			i++;
		if ( i == readed)
		{
			line = ft_realloc(sizeof(char) * (full_readed + i + 1));
			line[full_readed + i--] = 0;
			while (i >= 0)
			{
				line[full_readed + i] = buffer[i];
				i--;
			}
			full_readed += readed;
		}
		else {
			tmp = i;
			line = ft_realloc(sizeof(char) * (full_readed + i + 1));
			line[full_readed + i--] = 0;
			while (i >= 0)
			{
				line[full_readed + i] = buffer[i];
				i--;
			}
			i = tmp;
			full_readed = readed - i;
			old_line = malloc(sizeof(char) * (readed - i + 1));
			old_line[readed - i] = 0;
			while (i < readed)
			{
				old_line[readed - i] = buffer[i];
				i++;
			}
			return line;
		}
	}
		
}
