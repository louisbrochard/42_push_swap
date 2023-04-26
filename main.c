/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:09:21 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/04/26 18:57:45 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc <= 2)
        return (0);
    if (ft_check_arg(argv) == 1)
        ft_exit_error(NULL, NULL);
    if (ft_is_sorted(argv) == 0)
        return (0);
    printf("Prêt au tri");
    return (0);
}