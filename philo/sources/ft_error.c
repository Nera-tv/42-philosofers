/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:08:24 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:54:51 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	write_error(t_table *table, char *msg)
{
	free(table->ph);
	printf("%s", msg);
	table->error++;
	return (1);
}
