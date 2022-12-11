/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:25:49 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 19:31:00 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../sources.h"

int		ft_size(t_list *begin_list);
void	ft_free_node(t_list *node, int pointers);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_indexof_list(t_list *list_ptr, void *data_ref, int (*cmp)());
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_create_elem(void *data);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_get_by_key(t_list *begin_list, char *key);
void	ft_remove_by_key(t_list **list, char *key);

void	ft_add(t_list **begin_list, void *data);
int		ft_remove(t_list **list, void *data, int (*cmp)(), void (*freef)());
t_list	*ft_get(t_list *begin_list, int nbr);
t_list	*ft_list_range(int min, int max);

int		ft_remove_at(t_list **list, int ind, void (*freef)());
void	ft_free_list(t_list **list, void (*freef)());

int		ft_pop(t_list **list, void (*freef)());
#endif