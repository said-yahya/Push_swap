#include "push_swap.h"

static int  ft_sqrt(int nb)
{
    int sqrt;

    if (nb <= 0) return (0);
    sqrt = 1;
    while (sqrt * sqrt < nb)
        ++sqrt;
    if (sqrt * sqrt == nb)
        return (sqrt);
    if ((sqrt * sqrt - nb) < (nb - ((sqrt - 1) * (sqrt - 1))))
        return (sqrt);
    return (sqrt - 1);
}

static void push_to_b(t_control *ctrl, int low, int high)
{
    if (ctrl->a->top->index <= low)
    {
        pb(ctrl->a, ctrl->b, 1, ctrl);
        rb(ctrl->b, 1, ctrl);
    }
    else if (ctrl->a->top->index <= high)
        pb(ctrl->a, ctrl->b, 1, ctrl);
    else
        ra(ctrl->a, 1, ctrl);
}

static int get_max_position(t_stack *b, int target)
{
    t_node  *current;
    int     position;

    current = b->top;
    position = 0;
    while (position < b->size)
    {
        if (current->index == target)
            return (position);
        current = current->next;
        position++;
    }
    return (-1);
}

static void return_to_a(t_control *ctrl)
{
    int size;
    int position;
    int target;

    while (ctrl->b->size > 0)
    {
        size = ctrl->b->size;
        target = size - 1;
        position = get_max_position(ctrl->b, target);
        if (position < size / 2)
        {
            while (ctrl->b->top->index != target)
                rb(ctrl->b, 1, ctrl);
        }
        else
        {
            while (ctrl->b->top->index != target)
                rrb(ctrl->b, 1, ctrl);
        }
        pa(ctrl->a, ctrl->b, 1, ctrl);
    }
}

void sort_medium(t_control *ctrl)
{
    int low;
    int high;
    int chunk_size;
    int total_size;

    indexing(ctrl->a);
    low = 0;
    total_size = ctrl->a->size;
    chunk_size = ft_sqrt(ctrl->a->size) * 1.5;
    high = chunk_size;
    while (ctrl->a->size > 0)
    {
        push_to_b(ctrl, low, high);
        if (ctrl->b->size > 1 && ctrl->b->size > low && high < total_size - 1)
        {
            low++;
            high++;
        }
    }
    return_to_a(ctrl);
}