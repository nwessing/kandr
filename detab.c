#include <stdio.h>

int main()
{
	int c, i_line;

	i_line = 0;
	c = getchar();
	while(c != EOF) {
		if (c == '\t') {
			int rem_spaces = (4 - (i_line % 4));
			for (int i = 0; i < rem_spaces; ++i) {
				putchar(' ');
			}
			i_line += rem_spaces - 1;
		} else {
			putchar(c);
		}

		++i_line;
		if (c == '\n') {
			i_line = 0;
		}
		c = getchar();
	}

	return 0;
}