/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:53:38 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:44:02 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

int		ft_strcontain(char *to_count, char target);
int		ft_contain_subs(char *to_count, char *target);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_isnum(char *str);
int		ft_is_str_int(char *str);

int		ft_start_with(char *str, char *end);
int		ft_end_with(char *str, char *end);

int		ft_count(char *to_count, char target);
int		ft_str_index_of(char *to_count, char target);

int		ft_strcmp(char *s1, char *s2);
int		ft_strcmpl(char *s1, char *s2);
int		ft_strcmpn(char *s1, char *s2, int n);

int		ft_strlen(const char *str);
int		ft_strlen_to(char *to_count, char target);

void	ft_encrypt(char *str, char *key);
void	ft_decrypt(char *str, char *key);

char	*ft_clean_enclosures(char *str, char *charset);

char	*ft_itoa(int nb);
char	*ft_itob(int nb, char *base);

char	*ft_strncpy(char *s1, char *s2, int n);
char	*ft_strdup(char *src);

char	*ft_str_remove_at(char *str, int index, int len, int free_);

char	*ft_replace(char *to_ch, char *to_re, char *re);
char	*ft_replacen(char *to_ch, char *to_re, char *re, int ammount);

char	*ft_join(char **arr, char *glue);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strstr(char *str, char *to_find);
char	*ft_strafterstr(char *str, char *to_find);

char	*ft_iatoa(int *arr, int size);

#endif