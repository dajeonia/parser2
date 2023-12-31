/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envpmkr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:49:24 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/09 13:53:32 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*nvmkr(t_env *node)
{
	char	*middle;
	char	*result;

	middle = ft_strjoin(node->name, "=");
	if (!middle)
		return (0);
	result = ft_strjoin(middle, node->value);
	free(middle);
	return (result);
}

char	**envpmkr(t_env *envlst)
{
	int		i;
	char	**result;
	t_env	*temp;

	result = (char **)malloc(sizeof(char *) * (envsize(envlst) + 1));
	if (!result)
		return (0);
	temp = envlst;
	i = 0;
	while (temp)
	{
		if (temp->value)
		{
			result[i] = nvmkr(temp);
			if (!(result[i]))
			{
				twodfree(result);
				return (0);
			}
			i++;
		}
		temp = temp->next;
	}
	result[i] = NULL;
	return (result);
}
