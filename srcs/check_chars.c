#include "../includes/wolf3d.h"

void	check_chars(int fd, char *filename, t_env *env)
{
	char	*line;
	int		i;

	i = 0;

	while (i < 2)
	{
		get_next_line(fd, &line);
		i++;
	}
	env->check_chars = ft_countwords(line, ' ');
	free(line);
	close(fd);
	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
}