#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element.h"
element new_element()
{
	int num;
	scanf_s("%d", &num);
	return num;
}
char outbuf[20];
char *to_string(element e)
{
	sprintf_s(outbuf, 20, "%d", e);
	return outbuf;
}
void free_element(element e)
{
}