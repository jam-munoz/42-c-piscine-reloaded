/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:11:52 by joamunoz          #+#    #+#             */
/*   Updated: 2026/09/26 10:26:29 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

static void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*file;
	char	buf[1024];
	int		fd;
	int		bytes_read;

	if (argc < 2)
		ft_putstr("File name missing.\n", STDERR_FILENO);
	if (argc > 2)
		ft_putstr("Too many arguments.\n", STDERR_FILENO);
	if (argc != 2)
		return (-1);
	file = argv[1];
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n", STDERR_FILENO);
		return (1);
	}
	bytes_read = read(fd, buf, 1024);
	while (bytes_read > 0)
	{
		write(STDOUT_FILENO, buf, bytes_read);
		bytes_read = read(fd, buf, 1024);
	}
	close(fd);
}
