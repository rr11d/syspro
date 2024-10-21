#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "book.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	struct book record;
	if(argc !=  2){
		fprintf(stderr," How to use: %s file\n", argv[0]);
		exit(1);
	}
	fp = fopen(argv[1],"wb");
	printf("%-9s %-8s %-8s %-8s %-4s %-5s\n", "id", "bookname", "name", "year", "numofborrow", "borrow");
	while(scanf("%d %s %s %d %d %s", &record.id, &record.bookname, &record.author, &record.year, &record.numofborrow, &record.borrow) == 6)
		fwrite(&record, sizeof(record),1,fp);

	fclose(fp);
	exit(0);
}

