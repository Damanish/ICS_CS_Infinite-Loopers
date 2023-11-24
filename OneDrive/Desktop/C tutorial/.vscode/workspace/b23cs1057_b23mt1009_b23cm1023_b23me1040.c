#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct account
{
  int cpin;
  int cbalance;
  int transaction1;
  int transaction2;
  int transaction3;
} account;
void checkpin (int *, int);
void checkbalance (FILE *);
void deposit (FILE *, char[]);
void withdraw (FILE *, char[]);
void changepin (FILE *, char[], int);
void viewlast (FILE *, char[]);
int
main (void)
{
  char username[20];
  FILE *fptr;
  int *pin = (int *) malloc (1 * sizeof (int));
  int correctpin;
  printf ("Enter your username\n");
  scanf ("%s", username);
  fptr = fopen (username, "r+");
  if (fptr == NULL)
    {
      printf ("No account found\n");
      char c;
      printf ("Do you want to create a new account??\n");
      printf ("Enter Y if yes\n");
      printf ("Enter N if no\n");
      scanf ("%s", &c);
      if (c == 'Y')
	{
	  char newusername[20];
	  printf ("Enter your new username\n");
	  scanf ("%s", newusername);
	  FILE *fp;
	  fp = fopen (newusername, "w");
	  int newpin;
	  printf ("Enter new pin\n");
	  scanf ("%d", &newpin);
	  fprintf (fp, "%d\n", newpin);
	  int newbalance;
	  printf ("Deposit money\n");
	  scanf ("%d", &newbalance);
	  fprintf (fp, "%d\n", newbalance);
	  fprintf (fp, "%d\n%d\n%d\n", newbalance, 00, 00);
	  printf ("You account has been created!!\n");
	  printf ("Try logging in.\n");
	  fclose (fp);
	  main ();
	}
      else if (c == 'N')
	{
	  main ();
	}
      else
	{
	  printf ("Invalid Input\n");
	  main ();
	}
    }
  printf ("Enter your pin\n");
  scanf ("%d", pin);
  fscanf (fptr, "%d", &correctpin);
  checkpin (pin, correctpin);
  int option;
  while (1)
    {
      printf ("Welcome to main menu!!\n");
      printf ("Press 1 to check balance\n");
      printf ("Press 2 to deposit money\n");
      printf ("Press 3 to withdraw money\n");
      printf ("Press 4 to change pin\n");
      printf ("Press 5 to view last 3 transactions\n");
      printf ("Press 6 to exit\n");
      scanf ("%d", &option);
      if(option!=1&&option!=2&&option!=3&&option!=4&&option!=5&&option!=6)
      {
          printf("Choose a valid input.\n");
        
      }
      else
      {
      switch (option)
	{
	case 1:
	  checkbalance (fptr);
	  break;
	case 2:
	  deposit (fptr, username);
	  fptr = fopen (username, "r+");
	  break;
	case 3:
	  withdraw (fptr, username);
	  fptr = fopen (username, "r+");
	  break;
	case 4:
	  changepin (fptr, username, correctpin);
	  fptr = fopen (username, "r+");
	  break;
	case 5:
	  viewlast (fptr, username);
	  fptr = fopen (username, "r+");
	  break;
	case 6:
	  free (pin);
	  printf("THANK YOU!!\n");
	  main ();
	}
      }

    }
  free (pin);
  return 0;
}


void
checkpin (int *pin, int correctpin)
{
  if (*pin != correctpin)
    {
      printf ("Wrong pin\n");
      main ();
    }
}

void
checkbalance (FILE * fptr)
{
  int balance;
  fscanf (fptr, "%d", &balance);
  printf ("%d\n", balance);
}

void
deposit (FILE * fptr, char username[])
{
  int deposit1;
  printf ("Enter amount of money to deposit:");
  account copy;
  fseek (fptr, 0, SEEK_SET);
  fscanf (fptr, "%d", &copy.cpin);
  fscanf (fptr, "%d", &copy.cbalance);
  fscanf (fptr, "%d", &copy.transaction1);
  fscanf (fptr, "%d", &copy.transaction2);
  fscanf (fptr, "%d", &copy.transaction3);

  fclose (fptr);
  scanf ("%d", &deposit1);
  if (deposit1 > 0)
    {
      copy.cbalance += deposit1;
    }
  else
    printf ("Enter valid Amount");
  printf ("New balance: %d\n", copy.cbalance);
  copy.transaction3 = copy.transaction2;
  copy.transaction2 = copy.transaction1;
  copy.transaction1 = +deposit1;
  fptr = fopen (username, "r+");
  fprintf (fptr, "%d\n%d\n%d\n%d\n%d", copy.cpin, copy.cbalance,
	   copy.transaction1, copy.transaction2, copy.transaction3);

  fclose (fptr);

}

void
withdraw (FILE * fptr, char username[])
{
  int withdraw1;
  printf ("Enter amount of money to withdraw:");
  account copy;
  fseek (fptr, 0, SEEK_SET);
  fscanf (fptr, "%d", &copy.cpin);
  fscanf (fptr, "%d", &copy.cbalance);
  fscanf (fptr, "%d", &copy.transaction1);
  fscanf (fptr, "%d", &copy.transaction2);
  fscanf (fptr, "%d", &copy.transaction3);

  fclose (fptr);
  scanf ("%d", &withdraw1);
  int done = 0;
  if (withdraw1 > 0 && withdraw1 <= copy.cbalance)
    {
      copy.cbalance -= withdraw1;
      done++;
    }
  else
    printf ("Insufficient Balance\n");
  printf ("New balance: %d\n", copy.cbalance);
  if (done > 0)
    {
      copy.transaction3 = copy.transaction2;
      copy.transaction2 = copy.transaction1;
      copy.transaction1 = -withdraw1;
    }
  fptr = fopen (username, "w");
  fprintf (fptr, "%d\n%d\n%d\n%d\n%d", copy.cpin, copy.cbalance,
	   copy.transaction1, copy.transaction2, copy.transaction3);

  fclose (fptr);

}

void
changepin (FILE * fptr, char username[], int correctpin)
{
  int pin1;
  printf ("Enter new pin:");
  account copy;
  fseek (fptr, 0, SEEK_SET);
  fscanf (fptr, "%d", &copy.cpin);
  fscanf (fptr, "%d", &copy.cbalance);
  fscanf (fptr, "%d", &copy.transaction1);
  fscanf (fptr, "%d", &copy.transaction2);
  fscanf (fptr, "%d", &copy.transaction3);

  fclose (fptr);
  scanf ("%d", &pin1);
  if (pin1 > 999 && pin1 < 10000 && pin1 != correctpin)
    {
      copy.cpin += pin1;
      printf ("Pin changed successfully\n");
    }
  else if (pin1 == correctpin)
    {
      printf ("New pin can't be same as previous pin!!\n");
    }
  else
    printf ("Enter valid pin\n");

  fptr = fopen (username, "w");
  fprintf (fptr, "%d\n%d\n%d\n%d\n%d", copy.cpin, copy.cbalance,
	   copy.transaction1, copy.transaction2, copy.transaction3);

  fclose (fptr);
}

void
viewlast (FILE * fptr, char username[])
{

  account copy;
  fseek (fptr, 0, SEEK_SET);
  fscanf (fptr, "%d", &copy.cpin);
  fscanf (fptr, "%d", &copy.cbalance);
  fscanf (fptr, "%d", &copy.transaction1);
  fscanf (fptr, "%d", &copy.transaction2);
  fscanf (fptr, "%d", &copy.transaction3);

  fclose (fptr);
  printf ("Your last three transactions are:\n");
  if(copy.transaction1>=0)
  {
      printf("%c%d\n",'+',copy.transaction1);
  }
  else printf("%d\n",copy.transaction1);
  if(copy.transaction2>=0)
  {
      printf("%c%d\n",'+',copy.transaction2);
  }
  else printf("%d\n",copy.transaction2);
  if(copy.transaction3>=0)
  {
      printf("%c%d\n",'+',copy.transaction3);
  }
  else printf("%d\n",copy.transaction3);
  fptr = fopen (username, "w");
  fprintf (fptr, "%d\n%d\n%d\n%d\n%d", copy.cpin, copy.cbalance,
	   copy.transaction1, copy.transaction2, copy.transaction3);

  fclose (fptr);

}