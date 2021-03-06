/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executeur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:26:22 by esaci             #+#    #+#             */
/*   Updated: 2021/08/03 14:26:24 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

pid_t	ft_executeur(t_pip *pip)
{
	pid_t	pid;

	pid = forker(pip);
	return (pid);
}
