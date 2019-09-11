/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:57:20 by ibaran            #+#    #+#             */
/*   Updated: 2019/08/20 18:21:11 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		print_definition(t_word *word)
{
	if (!word)
		return ;
	if (word->is_instruction)
		ft_printf(" instruction ");
	if (word->is_operation)
		ft_printf(" operation ");
	if (word->is_register)
		ft_printf(" register ");
	if (word->is_direct)
		ft_printf(" direct ");
	if (word->is_indirect)
		ft_printf(" indirect ");
	if (word->is_label)
		ft_printf(" label ");
	if (word->is_separator)
		ft_printf(" separator ");
	if (word->is_command)
		ft_printf(" command ");
	if (word->is_name)
		ft_printf(" name ");
	if (word->is_comment)
		ft_printf(" comment ");
	if (word->is_quote)
		ft_printf(" %s quote ", (word->quote_is_open ? "open" : "closed"));
}

void			print_strings(t_string *string)
{
	t_word		*word;

	while (string)
	{
		ft_putnbr(string->nbr);
		word = string->word;
		while (word)
		{
			ft_printf("%s", word->str);
			print_definition(word);
			word = word->next;
		}
		ft_printf("\n");
		string = string->next;
	}
}

void			print_all_instuctions(t_instruction *instr)
{
	t_operation		*oper;
	int				i;

	while (instr)
	{
		oper = instr->operation;
		ft_printf("%s:\n", instr->name);
		while (oper)
		{
			i = -1;
			while (++i < oper->length)
				ft_printf("%.2x ", oper->binary[i]);
			ft_printf("\n");
			oper = oper->next;
		}
		ft_printf("\n");
		instr = instr->next;
	}
}
