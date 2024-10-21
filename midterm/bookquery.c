#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, n;
	char c;
	struct book record;
	if(argc <2){
		fprintf(stderr,"How to use: %sfile\n",argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}
	do{
		printf("--bookquery--\n 
				0: list of all books, 1: list of available books");
		if(scanf("%d", &n) == 1){
			lseek(fd,(n=START_ID)*sizeof(record),SEEK_SET);
			if((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0))
				printf("%-8s %-8s  %-4s %-4s %-4s %-4s", "id","bookname","author","year","numofborrow","borrow");
			


		}
	}
close(fd);
exit(0);

