#include <stdio.h>
#include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int		ft_atoi_base(const char *str, int str_base);
void	ft_list_push_front(t_list **lst, t_list *new);
int		ft_list_size(t_list *lst);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
int		ft_strcmp(const char *s1, const char *s2);

int	main(void)
{
	t_list	*start;
	t_list	*new;
	t_list	*new2;
	t_list	*new3;

	printf(" _________________BONUS PART!!1!1!1______________\n");
	printf("|_________________ft_atoi_base test______________|\n");
	printf("b10  -123\t\t%d\n", ft_atoi_base("   -123", 10));
	printf("b10  -123456\t\t%d\n", ft_atoi_base("   -123456", 10));
	printf("b10  -12345678\t\t%d\n", ft_atoi_base(" \n  -12345678", 10));
	printf("b10  -1234\\n56..\t%d\n", ft_atoi_base("   -1234\n56789", 10));
	printf("b10  -1234567891\t%d\n", ft_atoi_base("   -1234567891", 10));
	printf("b10  -12345678912\t%d\n", ft_atoi_base("   -12345678912", 10));
	printf("b10  -12345m6789123\t%d\n", ft_atoi_base("   -12345m6789123", 10));
	printf("b11   a\t\t%d\n", ft_atoi_base("a", 11));
	printf("b2    101\t%d\n", ft_atoi_base("101", 2));
	printf("b2    001\t%d\n", ft_atoi_base("001", 2));
	printf("b1    101\t%d\n", ft_atoi_base("101", 1));
	printf("b11   a\t\t%d\n", ft_atoi_base("a", 11));
	printf("b10   a\t\t%d\n", ft_atoi_base("a", 10));
	printf("b16   ff\t%d\n", ft_atoi_base("ff", 16));
	printf("b16   FF\t%d\n", ft_atoi_base("FF", 16));
	printf("b7    11\t%d\n", ft_atoi_base("11", 7));
	printf("b8    11\t%d\n", ft_atoi_base("11", 8));

	printf("_________________ft_list_push_front test_________\n");
	start = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	start->data = "aaaaa";
	start->next = 0;
	new->data = "bbbbb";
	new->next = 0;
	ft_list_push_front(&start, new);
	printf("%s\n", (char*)(start->data));
	printf("%s\n", (char*)(start->next->data));
	printf("#### let's add some more ...\n");
	new2 = malloc(sizeof(t_list));
	new2->data = "zzzzzz";
	new2->next = 0;
	ft_list_push_front(&start, new2);
	printf("%s\n", (char*)(start->data));
	printf("%s\n", (char*)(start->next->data));
	printf("%s\n", (char*)(start->next->next->data));

	printf("________________ft_list_size test________________\n");
	printf("list size = %d\n", ft_list_size(start));
	new3 = malloc(sizeof(t_list));
	new3->data = "zzzazzz";
	new3->next = 0;
	ft_list_push_front(&start, new3);
	printf("list size = %d\n", ft_list_size(start));
	printf("________________ft_list_sort test________________\n");
	t_list *test = malloc(sizeof(t_list));
	test->data = "zzz";
	test->next = 0;
	t_list *test1 = malloc(sizeof(t_list));
	test1->data = "aaa";
	test1->next = 0;
	t_list *test2 = malloc(sizeof(t_list));
	test2->data = "bbb";
	test2->next = 0;
	t_list *test3 = malloc(sizeof(t_list));
	test3->data = "hhhh";
	test3->next = 0;
	t_list *test4 = malloc(sizeof(t_list));
	test4->data = "fffff";
	test->next = 0;
	ft_list_push_front(&test, test1);
	ft_list_push_front(&test, test2);
	ft_list_push_front(&test, test3);
	ft_list_push_front(&test, test4);
	printf("----------------\n");
	printf("NOT sorted list:\n");
	printf("----------------\n");
	printf("%s\n", (char*)(test->data));
    printf("%s\n", (char*)(test->next->data));
	printf("%s\n", (char*)(test->next->next->data));
	printf("%s\n", (char*)(test->next->next->next->data));
	printf("%s\n", (char*)(test->next->next->next->next->data));
	ft_list_sort(&test, ft_strcmp);
	printf("--------------\n");
	printf("sorted list:\n");
	printf("--------------\n");
	printf("%s\n", (char*)(test->data));
    printf("%s\n", (char*)(test->next->data));
	printf("%s\n", (char*)(test->next->next->data));
	printf("%s\n", (char*)(test->next->next->next->data));
	printf("%s\n", (char*)(test->next->next->next->next->data));

	printf("________________ft_list_remove_if test________________\n");
	char	*data_ref = "bbb";
	ft_list_remove_if(&test, (void*)data_ref, ft_strcmp);
	printf("%s\n", (char*)(test->data));
    printf("%s\n", (char*)(test->next->data));
	printf("%s\n", (char*)(test->next->next->data));
	printf("%s\n", (char*)(test->next->next->next->data));
	return (0);
}
