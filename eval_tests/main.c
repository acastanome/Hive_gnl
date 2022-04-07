#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char *file0 = NULL;
/*	char *file1 = NULL;
	char *file2 = NULL;
	char *bible = NULL;*/
	int fd0 = open(file0 = "file_test0", O_RDONLY);
/*	int fd1 = open(file1 = "file_test1", O_RDONLY);
	int fd2 = open(file2 = "file_test2", O_RDONLY);
	int fd3 = open(bible = "bible.txt", O_RDONLY);*/
	FILE *f;
	char s;
	int i;


	get_next_line(fd0, &file0);
	printf("%s\n\n", file0);

//	get_next_line(fd1, &file1);
//	printf("%s\n\n", file1);

	get_next_line(fd0, &file0);
	printf("%s\n\n", file0);

	get_next_line(fd0, &file0);
	printf("%s\n\n", file0);

	get_next_line(fd0, &file0);
	printf("%s\n\n", file0);

//	get_next_line(fd2, &file2);
//	printf("%s\n\n", file2);

//	get_next_line(fd2, &file2);
//	printf("%s\n\n", file2);

	get_next_line(fd0, &file0);
	printf("%s\n\n", file0);

	printf("If this is 0, we have stopped reading: %d\n\n", get_next_line(fd0, &file0));

	i = 0;
/*	while (get_next_line(fd3, &bible) == 1)
	{
		i++;
		printf("BIBLE LINES READ: %d\n\n", i);
	}
	printf("BIBLE LINES READ: %d / 100182\n\n", i);*/
	close(fd0);
//	close(fd1);
//	close(fd2);

	f = fopen("file_test0","r");
	while((s=fgetc(f))!=EOF)
		printf("%c",s);
	fclose(f);
	printf("\n");

	return (0);
}
