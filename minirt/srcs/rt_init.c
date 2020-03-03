/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:52 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:44:34 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

/*
** 	codes d'erreur retour rt_pars :
**	1 = erreur open
**	2 = gnl retour -1
**	3 = get funct error
**	4 = erreur dans resolution : resolution missing
**	5 = erreur lumiere ambiante
**	6 = erreur couleur lumiere ambiante
**	7 = erreur de coordonnee camera
**	8 = erreur camera orientation
**	9 = erreur camera fov
**	10 = erreur coordonnee lumiere objet
**	11 = erreur couleur lumiere objet
**	12 = erreur ratio lumiere objet
**	13 = erreur malloc objet
**	14 = erreur split objet
**	15 = erreur coordonnee objet
**	16 = erreur vector objet
**	17 = erreur color objet
**	18 = erreur diametre objet
**	19 = erreur hauteur objet
**	20 = Resolution deja existante
**	21 = Lumiere d'ambiance deja existante
**	22 = couleur pas entre 0 et 255
**	23 = erreur lumiere ambiante split
**	24 = erreur fov camera range
**	25 = erreur ratio lumiere ambiante range
**	26 = camera orientation range
**	27 = lumiere ambiante missing
*/

void	rt_error_init_ii(char tab[30][100])
{
	ft_strcpy(tab[17], "Error on obj color");
	ft_strcpy(tab[18], "Error on obj diameter");
	ft_strcpy(tab[19], "Error on obj height");
	ft_strcpy(tab[20], "Resolution already exist");
	ft_strcpy(tab[21], "Ambiant light already exist");
	ft_strcpy(tab[22], "Color must be between 0 and 255");
	ft_strcpy(tab[23], "Error on ambiant light in split");
	ft_strcpy(tab[24], "Camera FOV must be between 0 and 180");
	ft_strcpy(tab[25], "Ambiant light ratio must be between 0.0 and 1.0");
	ft_strcpy(tab[26], "Camera orientation must be between - 1.0 and 1.0");
	ft_strcpy(tab[27], "Resolution or Ambiant light is missing");
}

void	rt_error_init(char tab[30][100])
{
	ft_strcpy(tab[1], "Error open");
	ft_strcpy(tab[2], "GNL return -1");
	ft_strcpy(tab[3], "Get Function error");
	ft_strcpy(tab[4], "Resolution missing");
	ft_strcpy(tab[5], "Error on ambiant light");
	ft_strcpy(tab[6], "Error on ambiant light's color");
	ft_strcpy(tab[7], "Error on Cam coordinates");
	ft_strcpy(tab[8], "Error on Cam orientation (all vector at 0 or not in range [-1.0, 1.0])");
	ft_strcpy(tab[9], "Error on Cam FOV");
	ft_strcpy(tab[10], "Error on obj lum coordinates");
	ft_strcpy(tab[11], "Error on obj lum color");
	ft_strcpy(tab[12], "Error on obj lum ratio");
	ft_strcpy(tab[13], "Error on obj malloc");
	ft_strcpy(tab[14], "Error on obj in split");
	ft_strcpy(tab[15], "Error on obj coordinates");
	ft_strcpy(tab[16], "Error on obj vector (all vector at 0 or not in range [-1.0, 1.0])");
	rt_error_init_ii(tab);
}

void 	*rt_error(int k)
{
	char tab[30][100];

	rt_error_init(tab);
	ft_printf("%s\n", tab[k]);
	return (NULL);
}

t_mlx	*rt_init(const char *str)
{
	t_mlx	*mlx;
	int ret;
	char *line;

	line = NULL;
	if (!(mlx = ft_calloc(1, sizeof(*mlx))))
		return (NULL);
	mlx->ptr = mlx_init();
	if ((ret = rt_pars(mlx, str)))
		return (rt_error(ret));
	if (mlx->lum_a_ok == 0 || mlx->y_ok == 0 || mlx->cfov_ok == 0)
		return (rt_error(27));
	mlx->win = mlx_new_window(mlx->ptr, mlx->x, mlx->y, "miniRT");
	return (mlx);
}
