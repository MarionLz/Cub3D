#include "../include/cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_putnbr(long long int nb, int base, int *count)
{
	char *hexa = "0123456789abcdef";

	if (nb < 0)
	{
		nb = -nb;
		*count += write(1, "-", 1);
	}
	if (nb >= base)
		ft_putnbr((nb / base), base, count);
	*count += write(1, &hexa[nb % base], 1);
}

void	check_floor_ceiling_format(char **colors)
{
	int	i;
	int	j;

	i = 0;
	while (colors[i])
	{
		j = 0;
		printf("%s\n", colors[i]);
		while (colors[i][j])
		{
			if (!ft_isdigit(colors[i][j]) && colors[i][j] != '\n')
				display_error("1colors components must be 3 digits set between\
0 and 255, separated by a ','");
			j++;
		}
		i++;
	}
	if (i != 3)
		display_error("2colors components must be 3 digits set between 0 and 255, separated by a ','");
}

char	*get_path(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;
	char			*dest;

	i = 0;
	while (s[i] == ' ')
		i++;
	len = 0;
	while (s[i + len] && s[i + len] != ' ' && s[i + len] != '\n')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	j = 0;
	while (j < len)
		dest[j++] = s[i++];
	dest[j] = '\0';
	//printf("%s\n", dest);
	return (dest);
}
