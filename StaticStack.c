#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
struct stack
{
  int s[size];
  int top;
} st;

int stfull ()
{
  if (st.top >= size - 1)
	return 1;
  else
	return 0;
}

void push (int item)
{
  st.top++;
  st.s[st.top] = item;
}

int stempty ()
{
  if (st.top == -1)
	return 1;
  else
	return 0;
}

int pop ()
{
  int item;
  item = st.s[st.top];
  st.top--;
  return item;
}

void display ()
{
  int i;
  if (stempty ())
	printf ("\nStack is Empty");
  else
	for (i = st.top; i >= 0; i--)
	  printf ("\n%d", st.s[i]);
}

int main ()
{
  int item, choice;
  char ans;
  st.top = -1;
  printf ("\n\t\tImplementation of Stack");
  do
	{
	  printf ("\n Main Menu");
	  printf ("\n 1.Push\n2.pop\n3.Display\n4.exit");
	  printf ("\n Enter your choice ");
	  scanf ("%d", &choice);
	  switch (choice)
		{
		case 1:
		  printf ("\n\n Enter the item to be pushed ");
		  scanf ("%d", &item);
		  if (stfull ())
			printf ("\nStack is Full");
		  else
			push (item);
		  break;
		case 2:
		  if (stempty ())
			printf ("\n Empty Stack!Underflow");
		  else
			{
			  item = pop ();
			  printf ("\n\n The popped item is %d", item);
			}
		  break;
		case 3:
		  display ();
		  break;
		case 4:
		  exit (0);
		}
	  printf ("\n Do you want to continue? ");
	  ans = getche ();
	}
  while (ans == 'Y' || ans == 'y');
  return 0;
}
