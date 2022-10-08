#include<stdio.h>
#include<string.h>
int main()
{
	char a[30];
	int i,d=0,sc=0,v=0,c=0;
	gets(a);
	puts(a);
	for(i=0;a[i]!='\0';i++)
	{
	    if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))
	    {
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
		v++;
		else c++;
	    }
	    else if(a[i]>='0'&&a[i]<='9')
	    d++;
	    else sc++;

}
printf("%d %d %d %d",v,c,sc,d);
return 0;
}
