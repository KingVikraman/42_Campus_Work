/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:09:13 by rvikrama          #+#    #+#             */
/*   Updated: 2024/10/09 18:02:30 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*-----------------------------------------------------*/
/*                    OPERATIONS                       */
/*-----------------------------------------------------*/
void	ft_ra(t_stack **a, int j);
void	ft_sa(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_sb(t_stack **b, int j);
void	ft_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr_sub(t_stack **b, int j);
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j);

/*-----------------------------------------------------*/
/*                   CHECK FUNCTIONS                   */
/*-----------------------------------------------------*/
int		space(int c);
int		digit(int c);
int		ft_isalpha(int c);
int		sign(int c);
int		check_error(char **argv, int i, int j);
int		ft_checkdup(t_stack *a);
int		ft_checksorted(t_stack *stack_a);
bool	check_args(char **argv);
void	alpha_check(char **argv);

/*-----------------------------------------------------*/
/*                     ERROR & FREE                    */
/*-----------------------------------------------------*/
void	ft_error(void);
void	ft_free(t_stack**lst);

/*-----------------------------------------------------*/
/*                    SORT & ROTATE                    */
/*-----------------------------------------------------*/
void	ft_sort(t_stack **stack_a);
t_stack	*ft_sort_b(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);

/*                       ...                            */

int		ft_rotate_type_ab(t_stack *a, t_stack *b);
int		ft_rotate_type_ba(t_stack *a, t_stack *b);
int		ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);

/*-----------------------------------------------------*/
/*                 UTILS & SOLVER UTILS                */
/*-----------------------------------------------------*/
int		ft_max(t_stack *a);
int		ft_min(t_stack *a);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_find_index(t_stack *a, int nbr);
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
int		ft_find_place_a(t_stack *stack_a, int nbr_push);

/*                      ...                            */

int		ft_case_rarb(t_stack *a, t_stack *b, int c);
int		ft_case_rarrb(t_stack *a, t_stack *b, int c);
int		ft_case_rrarb(t_stack *a, t_stack *b, int c);
int		ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int		ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int		ft_case_rrarb_a(t_stack *a, t_stack *b, int c);
int		ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
int		ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);

/*-----------------------------------------------------*/
/*            LIST & PARSE & STACK & ADD               */
/*-----------------------------------------------------*/
void	ft_freestr(char **lst);
t_stack	*ft_stack_new(int content);
t_stack	*ft_parse(int argc, char **argv);
t_stack	*ft_parse_args_quoted(char **argv);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
void	list_arguments(char **argv, t_stack **stack_a);

/*-----------------------------------------------------*/
/*              PUSH_SWAP.C & ALGORITHM                */
/*-----------------------------------------------------*/
int		ft_atoi2(const char *str);
t_stack	*ft_sub_process(char **argv);
t_stack	*ft_process(int argc, char **argv);

void	ft_error_ch(void);
void	ft_check_sub(t_stack **a, t_stack **b, char *line);
char	*ft_check(t_stack **a, t_stack **b, char *line);
void	ft_checker_sub(t_stack **a, t_stack **b, char *line);

#endif