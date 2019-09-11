/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:28:02 by ibaran            #+#    #+#             */
/*   Updated: 2019/08/08 15:45:44 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champion		*init_champion(void)
{
	t_champion	*new_champion;

	if (!(new_champion = (t_champion*)malloc(sizeof(t_champion))))
		error(ERR_MEMORY);
	ft_fillstr(new_champion->name, '\0', PROG_NAME_LENGTH);
	new_champion->name_size = -1;
	ft_fillstr(new_champion->comment, '\0', COMMENT_LENGTH);
	new_champion->comment_size = -1;
	return (new_champion);
}

t_instruction	*init_instruction(char *name)
{
	t_instruction	*new_instruction;

	if (!(new_instruction = (t_instruction*)malloc(sizeof(t_instruction))))
		error(ERR_MEMORY);
	new_instruction->name = name;
	new_instruction->length = -1;
	new_instruction->operation = NULL;
	new_instruction->last_operation = NULL;
	new_instruction->next = NULL;
	return (new_instruction);
}

t_operation		*init_operation(char *name)
{
	t_operation	*new_operation;

	if (!(new_operation = (t_operation*)malloc(sizeof(t_operation))))
		error(ERR_MEMORY);
	if ((new_operation->oper_code = get_oper_code(name)) == -1)
		lex_error(ERR_UNKMOWN_OPERATION, name);
	new_operation->arg_type_code = -1;
	new_operation->line_nbr = 0;
	new_operation->arg_value[0] = 0;
	new_operation->arg_value[1] = 0;
	new_operation->arg_value[2] = 0;
	new_operation->arg_str[0] = NULL;
	new_operation->arg_str[1] = NULL;
	new_operation->arg_str[2] = NULL;
	new_operation->arg_type[0] = -1;
	new_operation->arg_type[1] = -1;
	new_operation->arg_type[2] = -1;
	new_operation->arg_size[0] = 0;
	new_operation->arg_size[1] = 0;
	new_operation->arg_size[2] = 0;
	new_operation->length = -1;
	new_operation->binary = NULL;
	new_operation->next = NULL;
	return (new_operation);
}
