/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephe <ephe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:11:56 by ephe              #+#    #+#             */
/*   Updated: 2019/09/10 11:45:33 by dadler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

int			op_aff(t_vm *v, t_process *proc, t_param *params)
{
	int		step;

	(void)v;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], 0);
	if (proc->error)
		return (step);
	ft_printf("Aff: %c\n", proc->reg[params[0].val] % 256);
	return (step);
}

void		check_error(t_vm *v, t_process *proc, t_param *param_tab)
{
	int	i;

	i = -1;
	while (++i < v->op_tab[proc->opc - 1].nb_params)
		if (param_tab[i].reg && (param_tab[i].val > REG_NUMBER
			|| param_tab[i].val < 1))
			proc->error = 1;
}

static void	pre_op_ind(t_vm *v, t_process *proc, t_param *params, char options)
{
	if (proc->error)
		return ;
	params->val = reverser_16((short)params->val);
	params->val = (proc->pc + (options & MODULO ? params->val % IDX_MOD :
		params->val)) % MEM_SIZE;
	if (proc->opc == 13)
		params->val = options & READ ? reverser_16(read_ind(v,
			params->val, IND_SIZE)) : params->val;
	else
		params->val = options & READ ? reverser_32(read_ind(v, params->val,
			IND_SIZE)) : params->val;
}

int			pre_op(t_vm *v, t_process *proc, t_param *params, char options)
{
	if (params->direct)
	{
		if (proc->error)
			return (options & TWO_BYTES ? S_IND : S_DIR);
		params->val = options & TWO_BYTES ? reverser_16((short)params->val)
			: reverser_32(params->val);
		return (options & TWO_BYTES ? S_IND : S_DIR);
	}
	else if (params->indirect)
	{
		pre_op_ind(v, proc, params, options);
		return (S_IND);
	}
	else if (params->reg)
	{
		if (proc->error)
			return (S_REG);
		params->val--;
		if (options & REG)
			params->val = reverser_32(proc->reg[params->val]);
		if (options & REG_R)
			params->val = proc->reg[params->val];
		return (S_REG);
	}
	return (0);
}

int			get_offset(int offset)
{
	while (offset < 0)
		offset += MEM_SIZE;
	return (offset % MEM_SIZE);
}
