#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main()
{
	printf("My Realistic User ID: %d(%s)\n",getuid(), getpwuid(getuid())->pw_name);
	printf("My valid User ID: %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
	printf("My Realistic Group ID: %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
	printf("My valid Group ID: %d(%s)\n", getgid(), getgrgid(getgid())->gr_name);
}

