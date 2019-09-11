/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephe <ephe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:16:55 by ephe              #+#    #+#             */
/*   Updated: 2019/09/06 16:40:11 by ephe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

static int			ft_check_argv(int argc, char **argv, t_parse_argv *av)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (ft_strstr(argv[i], ".cor"))
			av->count_champ++;
	if (argc < 2 || av->count_champ < 1)
	{
		ft_usage();
		return (-1);
	}
	else if (av->count_champ > MAX_PLAYERS)
	{
		ft_putendl("Too many champions");
		return (-1);
	}
	return (0);
}

static int			init_ft_argv(t_vm *v, t_parse_argv *av, int argc,
	char **argv)
{
	ft_bzero(av, sizeof(t_parse_argv));
	if (ft_check_argv(argc, argv, av))
		return (0);
	ft_bzero(v->players, sizeof(t_champ) * MAX_PLAYERS);
	v->visu = 0;
	return (1);
}

static t_type_argv	*ft_parse_init(t_vm *v)
{
	t_type_argv		*type;

	if (!(type = (t_type_argv *)malloc(sizeof(t_type_argv) * 6)))
		exit_fail(v, NULL, NULL, 0);
	type[0] = (t_type_argv){"-visu", init_visu};
	type[1] = (t_type_argv){"-v", verbose};
	type[2] = (t_type_argv){"-dump", dump};
	type[3] = (t_type_argv){"-d", dirty};
	type[4] = (t_type_argv){"-n", num_champ};
	type[5] = (t_type_argv){".cor", ft_init_champ};
	return (type);
}

int					ft_argv(t_vm *v, int argc, char **argv)
{
	t_type_argv		*type;
	t_parse_argv	av;
	int				i;

	if (!(init_ft_argv(v, &av, argc, argv)))
		return (-1);
	if (!(type = ft_parse_init(v)))
		return (0);
	while (++av.i < argc)
	{
		i = -1;
		while (++i < 6)
			if (ft_strstr(argv[av.i], type[i].str))
			{
				if (i != 5 && ft_strcmp(argv[av.i], type[i].str))
					return (ft_usage() + wrapper((void*)&type, 0));
				if (type[i].f(argc, argv, &av, v))
					return (wrapper((void*)&type, 1));
				break ;
			}
		if (i == 6)
			return (ft_usage() + wrapper((void*)&type, 0));
	}
	ft_memdel((void*)&type);
	return (av.count_champ);
}
