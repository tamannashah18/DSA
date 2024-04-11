#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,r,c,*p,i,ch=0,j,temp,cnt=0,pos,val;

	printf("ENTER 1 for 1D array\n");
	printf("ENTER 2 for 2D array\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("ENTER ARRAY SIZE:\n");
		scanf("%d",&n);
		int a[n];
		ch=0;

		while(1)
		{
			printf("\nENTER 1 TO INSERT");
			printf("\nENTER 2 TO DISPLAY");
			printf("\nENTER 3 TO SORT");
			printf("\nENTER 4 TO SEARCH");
			printf("\nENTER 5 TO DELETE");
			printf("\nENTER 6 TO UPDATE");
			printf("\nENTER 7 TO EXIT");
			scanf("%d",&ch);

			switch(ch)
			{
				case 1:
					p=a;
					for(i=0;i<n;i++)
					{
						printf("ENTER ELEMENT");
						scanf("%d",p++);
					}
					printf("INSERTION SUCCESSFULL\n");
					break;
				case 2:
					printf("ARRAY ELEMENTS\n");
					p=a;
					for(i=0;i<n;i++)
					{
						printf("%d\t",*p++);
					}
					break;
				case 3:
					p=a;
					for(i=0;i<n-1;i++)
					{
						for(j=0;j<n-i-1;j++)
						{
							if(*(p+j)>*(p+j+1))
							{
								temp=*(p+j);
								*(p+j)=*(p+j+1);
								*(p+j+1)=temp;
							}
							p++;
						}
					}
					printf("SORTED ARRAY ELEMENTS\n");
					p=a;
					for(i=0;i<n;i++)
					{
						printf("%d\t",*p++);
					}
					break;
				case 4:
					printf("ENTER VALUE TO BE SEARCHED");
					scanf("%d",&temp);
					p=a;
					for(i=0;i<n;i++)
					{
						if(temp==*(p+i))
						{
							printf("%d value is at the INDEX %d",*(p+i),i);
							cnt++;
						}
					}
					if(cnt==0)
						printf("no such element exists\n");
				break;
				case 5:
					printf("ARRAY ELEMENTS BEFORE DELETION\n");
					p=a;
					for(i=0;i<n;i++)
					{
						printf("%d\t",*p++);
					}
					printf("ENTER POSIITON TO BE DELETED(0 to %d)",n);
					scanf("%d",&pos);

					if(pos<0 || pos>n)
						printf("INAVLID INPUT");
					else
					{
						p=a;
						for(i=pos;i<n;i++)
						{
							*(p+i)=*(p+i+1);
						}
						p=a;
						n-=1;
						printf("\nARRAY ELEMENTS AFTER DELETION\n");
						for(i=0;i<n;i++)
						{
							printf("%d\t",*p++);
						}
					}
					break;
				case 6:
					printf("ENTER POSIITON TO BE UPDATED(0 to %d)",n);
					scanf("%d",&pos);
					if(pos<0 || pos>n)
						printf("INAVLID INPUT");
					else
					{
						printf("ENTER VALUE TO BE UPDATED");
						scanf("%d",&temp);
						*(p+pos)=temp;
						printf("\nARRAY ELEMENTS AFTER UPDATION\n");
						for(i=0;i<n;i++)
						{
							printf("%d\t",*p++);
						}
					}
					break;
				case 7:
					exit(0);
					break;
			}
		}
	}
	else if(ch==2)
	{
		printf("ENTER ARRAY SIZE ROWS AND COLUMNS:\n");
		scanf("%d%d",&r,&c);
		n=r*c;
		int a[r][c];
		ch=0;
		while(1)
		{
			printf("\nENTER 1 TO INSERT");
			printf("\nENTER 2 TO DISPLAY");
			printf("\nENTER 3 TO SORT");
			printf("\nENTER 4 TO SEARCH");
			printf("\nENTER 5 TO DELETE");
			printf("\nENTER 6 TO UPDATE");
			printf("\nENTER 7 TO EXIT");
			scanf("%d",&ch);

			switch(ch)
			{
				case 1:
					p=a;
					for(i=0;i<n;i++)
					{
						printf("ENTER ELEMENT");
						scanf("%d",p++);
					}
					printf("INSERTION SUCCESSFULL\n");
					break;
				case 2:
					printf("ARRAY ELEMENTS\n");
					p=a;
					for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						{
							printf("%d\t",*p++);
						}
						printf("\n");
					}
					break;
				case 3:
					p=a;
					for(i=0;i<n;i++)
					{
						for(j=0;j<n-i-1;j++)
						{
							if(*((p+i)+j)>*((p+i)+j+1))
							{
								temp=*((p+i)+j);
								*((p+i)+j)=*((p+i)+j+1);
								*((p+i)+j+1)=temp;
							}
						}
					}
					for(i=0;i<n;i++)
					{
						for(j=0;j<n-i-1;j++)
						{
							if(*((p+j)+i)>*((p+j)+i+1))
							{
								temp=*((p+j)+i);
								*((p+j)+i)=*((p+j)+i+1);
								*((p+j)+i+1)=temp;
							}
						}
					}
					printf("SORTED ARRAY ELEMENTS\n");
					p=a;
					for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						{
							printf("%d\t",*p++);
						}
						printf("\n");
					}
					break;
				case 4:
					printf("ENTER VALUE TO BE SEARCHED");
					scanf("%d",&temp);
					for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						{
							if(temp==*((p+i)+j))
							{
								printf("%d value is at the INDEX [%d][%d]",*((p+i)+j),i,j);
								cnt++;
							}
						}
					}
					if(cnt==0)
						printf("no such element exists\n");
				break;
				case 5:
					printf("ARRAY ELEMENTS BEFORE DELETION\n");
					p=a;
					for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						{
							printf("%d\t",*p++);
						}
						printf("\n");
					}
					printf("ENTER VALUE TO BE DELETED");
					scanf("%d",&val);
						p=a;
						cnt=0;
						for(i=0;i<n;i++)
						{
							if(*(p+i)==val)
							{
								cnt++;
								for(j=i;j<n-1;j++)
								{
									*(p+j)=*(p+j+1);
								}
								continue;
							}
						}
						p=a;
						n-=cnt;
						printf("\nARRAY ELEMENTS AFTER DELETION\n");

						for(i=0;i<n;i++)
						{
							printf("%d\t",*p++);
							if((i+1)%c==0)
							printf("\n");
						}
					break;
				case 6:
					printf("ARRAY ELEMENTS BEFORE UPDATION\n");
					p=a;
					for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						{
							printf("%d\t",*p++);
						}
						printf("\n");
					}
					printf("ENTER POSIITON TO BE UPDATED(rows(0 to %d),columns(0 to %d))",r-1,c-1);
					scanf("%d%d",&pos,&temp);

					if((pos<0 || pos>r) && (temp<0 || temp>c))
					printf("INAVLID INPUT");
					else
					{
						printf("ENTER VALUE TO BE UPDATED");
						scanf("%d",&val);
						p=a;
						*(p+r*pos+temp)=val;

						printf("ARRAY ELEMENTS AFTER UPDATION\n");
						p=a;
						for(i=0;i<r;i++)
						{
							for(j=0;j<c;j++)
							{
								printf("%d\t",*p++);
							}
							printf("\n");
						}
					}
					break;
				case 7:
					exit(0);
					break;
				}
			}
		}
	else
	{
		printf("invalid input");
		exit(0);
	}

}
