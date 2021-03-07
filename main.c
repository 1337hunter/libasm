#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

ssize_t ft_write(int fd, const char *s, size_t i);
size_t	ft_strlen(const char *s);
ssize_t	ft_read(int fd, void *s, size_t count);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

int main(void)
{
	char	buf[10];
	char	*s;
	char	*ret_dest;
	int		cmp;
	
	printf("____________ft_write test________________\n");
	printf("Bad fd: ft_ret = %ld\n", ft_write(122, "21", 2));
	perror("Bad fd error");
	printf("Bad string: ft_ret = %ld\n", ft_write(1, 0, 2));
	perror("Bad string error");
	errno = 0;
	printf("Good params: ret = %ld\n", ft_write(1, "Good params\n", 12));
	perror("Success?");

	printf("____________ft_strlen test_______________\n");
	printf("len of \"123456789\" is: %ld\n", ft_strlen("123456789"));
	printf("len of \"1\"         is: %ld\n", ft_strlen("1"));
	printf("len of \"\"          is: %ld\n", ft_strlen(""));
	
	printf("____________ft_read   test_______________\n");
	printf("Bad fd: ft_read = %ld\n", ft_read(42, buf, 9));
	perror("Bad fd");
	printf("Bad buf: ft_read = %ld\n", ft_read(0, 0, 9));
	perror("Bad buf");
	errno = 0;
	printf("Good params: ft_read = %ld\n", ft_read(0, buf, 9));
	buf[9] = 0;
	printf("Good buf: \"%s\"\n", buf);
	perror("Success?");
	
	printf("___________ft_strcpy test________________\n");
	errno = 0;
	ft_strcpy(buf, "123456");
	printf("buf with \"123456\" = >%s<\n", buf);
	ft_strcpy(buf, "");
	printf("buf with \"\" = >%s<\n", buf);
	s = (char*)malloc(sizeof(char) * 10);
	ret_dest = ft_strcpy(s, "123123");
	if (ret_dest == s)
		printf("ret_strlen == dest (:\n");
	
	printf("__________ft_strcmp test_________________\n");
	printf("ft = %d std = %d\n", ft_strcmp("123", "123"), strcmp("123", "123"));
	printf("ft = %d std = %d\n", ft_strcmp("123", "122"), strcmp("123", "122"));
	printf("ft = %d std = %d\n", ft_strcmp("123", "124"), strcmp("123", "124"));
	printf("ft = %d std = %d\n", ft_strcmp("123", "12"), strcmp("123", "12"));
	printf("ft = %d std = %d\n", ft_strcmp("12", "123"), strcmp("12", "123"));
	printf("ft = %d std = %d\n", ft_strcmp("\0123", "\200123"), strcmp("\0123", "\200123"));

	printf("__________ft_strdup test_________________\n");
	printf("str = \"%s\"\n", ft_strdup("dupping string"));
	printf("str = \"%s\"\n", ft_strdup(""));
	return (0);
}
