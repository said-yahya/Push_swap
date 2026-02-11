#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack;
    char    **nums;
    int     i;

    if (ac == 1)
        return (0);
    nums = ft_split(av[1], ' ');
    if (!nums)
        return (NULL);
    i = 0;
    while (nums[i])
    {
        ft_addback(stack, ft_newnode(ft_atoi(nums[i])));
        i++;
    }
}