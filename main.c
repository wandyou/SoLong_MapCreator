/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanlafarge <nathanlafarge@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:46:27 by nathanlafar       #+#    #+#             */
/*   Updated: 2021/07/25 23:20:40 by nathanlafar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int			ft_digitlen(long nombre)
{
	size_t	size;

	if (nombre == 0)
		return (nombre + 1);
	size = 0;
	if (nombre < 0)
	{
		nombre = -nombre;
		size++;
	}
	while (nombre != 0)
	{
		nombre /= 10;
		size++;
	}
	return (size);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	long	long_n;
	long	len;
	char	*response;

	long_n = n;
	len = ft_digitlen(long_n);
	if (len == 0)
		len = 1;
	response = (char *)malloc((len + 1) * sizeof(char));
	if (!response)
		return (NULL);
	response[len] = '\0';
	len--;
	if (long_n < 0)
		long_n = -long_n;
	while (len >= 0)
	{
		response[len] = (long_n % 10) + 48;
		len--;
		long_n /= 10;
	}
	if (ft_sign(n))
		response[0] = '-';
	return (response);
}

int generate_rand(int min, int max)
{
    return (rand() % (max + 1 - min) + min);
}

int main(int argc, char **argv)
{
    int x;
    int y;
    int largeur;
    int longueur;
    int player = 1;
    int exit = 1;
    int collectible;
    int enemy;
    int wall;
    int rand_x;
    int rand_y;
    char file_name[300] = "";
    char number;
    FILE *fp;
    int z;

    if (argc < 5)
    {
        printf("OH OUBLIE PAS LES PARAMS");
        return(0);
    }

    int nb_maps = atoi(argv[1]);
    for (z = 0; z < nb_maps; z++)
    {
        player = 1;
        exit = 1;
        strcat(file_name, "maps/map");
        strcat(file_name, ft_itoa(z));
        strcat(file_name, ".ber");
        printf("%s\n", file_name);
        fp = fopen (file_name , "w+");
        longueur = generate_rand(0, atoi(argv[2]));
        largeur = generate_rand(0, atoi(argv[3]));
        enemy = atoi(argv[4]);
        char map[longueur][largeur];

        collectible = 0;
        collectible = (largeur*longueur)-(2*largeur)-(2*longueur)+2;
        collectible = (4*collectible)/100;
        if (enemy > 0)
        {
            enemy = 0;
            enemy = (largeur*longueur)-(2*largeur)-(2*longueur)+2;
            enemy = (1*enemy)/100;
        }
        wall = 0;
        wall = (largeur*longueur)-(2*largeur)-(2*longueur)+2;
        wall = (30*wall)/100;

        for(y = 0; y < longueur; y++)
        {
            for(x = 0; x < largeur; x++)
            {
                if (y == 0 || y == longueur - 1)
                    map[y][x] = '1';
                else if (x == 0 || x == largeur - 1)
                    map[y][x] = '1';
                else 
                    map[y][x] = '0';
            }
        }

        while (wall > 0)
        {
            rand_x = generate_rand(1, largeur-2);
            rand_y = generate_rand(1, longueur-2);
            if (map[rand_y][rand_x] == '0')
            {
                map[rand_y][rand_x] = '1';
                wall--;
            }
        }

        while (collectible > 0)
        {
            rand_x = generate_rand(1, largeur-2);
            rand_y = generate_rand(1, longueur-2);
            if (map[rand_y][rand_x] == '0')
            {
                map[rand_y][rand_x] = 'C';
                collectible--;
            }
        }

        while (enemy > 0)
        {
            rand_x = generate_rand(1, largeur-2);
            rand_y = generate_rand(1, longueur-2);
            if (map[rand_y][rand_x] == '0')
            {
                map[rand_y][rand_x] = 'M';
                enemy--;
            }
        }

        while (player > 0)
        {
            rand_x = generate_rand(1, largeur-2);
            rand_y = generate_rand(1, longueur-2);
            if (map[rand_y][rand_x] == '0')
            {
                map[rand_y][rand_x] = 'P';
                player--;
            }
        }

        while (exit > 0)
        {
            rand_x = generate_rand(1, largeur-2);
            rand_y = generate_rand(1, longueur-2);
            if (map[rand_y][rand_x] == '0')
            {
                map[rand_y][rand_x] = 'E';
                exit--;
            }
        }

        for(y = 0; y < longueur; y++)
        {
            for(x = 0; x < largeur; x++)
            {
                fputc(map[y][x], fp);
            }
            if (y < longueur - 1)
                fputc('\n', fp);
        }

        fclose(fp);
        memset(file_name, 0, sizeof(file_name));
    }

    return (0);
}