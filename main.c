/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrock <bbrock@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:10:18 by bbrock            #+#    #+#             */
/*   Updated: 2020/11/20 16:25:41 by bbrock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libasm.h"

void test_ft_strdup()
{
	printf("\x1b[32mft_strdup :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup("toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("0123456789"));
}

void test_ft_read()
{
	int fd;
	char buffer[100];
	char show[100];
	ssize_t ret;

	printf("\x1b[32mft_read:\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '0'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'open(\"Makefile\", O_RDONLY)' '' '50'\x1b[0m\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, buffer, 50);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '10'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d - %s - %d\n", ret, strncpy(show, buffer, 10), errno);
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d - %s - %d\n", ret, strncpy(show, buffer, 10), errno);
	close(fd);
}

void test_ft_write()
{
	int fd;
	char buffer[100];

	printf("\x1b[32mft_write :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'1' '' '0'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d\n", write(1, "", 0));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_write(1, "", 0));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d\n", write(1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_write(1, "toto", 4));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'1' 'toto' '2'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d\n", write(1, "toto", 2));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_write(1, "toto", 2));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'1' 'toto' '40'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d\n", write(1, "toto", 40));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_write(1, "toto", 40));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'1' 'NULL' '6'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d - %d\n", write(1, NULL, 6), errno);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d - %d\n", ft_write(1, NULL, 6), errno);
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d\n", write(0, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_write(0, "toto", 4));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'42' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d - %d\n", write(42, "toto", 4), errno);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d - %d\n", ft_write(42, "toto", 4), errno);
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'-1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %d - %d\n", write(-1, "toto", 4), errno);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d - %d\n", ft_write(-1, "toto", 4), errno);
}

void test_ft_strcmp()
{
	printf("\x1b[32mft_strcmp :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("", ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("", ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'toto' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", ""));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("", "toto"));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'tototest' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("tototest", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("tototest", "toto"));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'bbbonjour' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("bbbonjour", "bbonjour"));
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("bbbonjour", "bbonjour"));
}

void test_ft_strcpy()
{
	char dst[100];

	printf("\x1b[32mft_strcpy :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "0123456789"));
}

void test_ft_strlen()
{
	printf("\x1b[32mft_strlen :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("    "));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("    "));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("0123456789"));
}

int main(int argc, char *argv[])
{
	if (argc == 1 || !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen();
	if (argc == 1 || !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy();
	if (argc == 1 || !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp();
	if (argc == 1 || !strcmp(argv[1], "ft_write"))
		test_ft_write();
	if (argc == 1 || !strcmp(argv[1], "ft_read"))
		test_ft_read();
	if (argc == 1 || !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup();
}
