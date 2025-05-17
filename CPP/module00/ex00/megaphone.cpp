/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:31:48 by tamadan           #+#    #+#             */
/*   Updated: 2024/04/29 18:31:49 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **str)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for(int i = 1; str[i]; i++)
        {
            for (int j = 0; str[i][j]; j++)
            {
                std::cout << (char) toupper(str[i][j]);
                
            }
            if(str[i + 1] != NULL)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return(0);
}

