#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<iostream>
#define maximum 10
#define minvalue 0.000000001

using namespace std;

void main()
{
 float augmentedmatrix[maximum][maximum] ;  
        /* 2D array declared to store augmented co-efficient matrix */
 float temporary, r ;
 float solutions[maximum] ;  
                              /* 1D array declared to store solutions of the simultaneous equations */

 int i,j,k, noofequations, temp, minus=0;             /* declaring counter variables */

 //clrscr();

 printf("\n===============================================");
 printf("\n        GAUSS-JORDAN  ELIMINATION  METHOD");
 printf("\n===============================================");

 printf("\n Enter the number of total equations to be provided as input : \n");
 scanf("%d",&noofequations);

 /* storing augmented co-efficient matrix as a matrix of dimension (noofequations)x(noofequations+1) in 2D array */

 printf("\n Enter the augmented co-efficient matrix : \n");
 for(i=0; i<noofequations; i++)
  for(j=0; j<=noofequations; j++)
            scanf("%f",&augmentedmatrix[i][j]) ;


 /* converting augmented matrix into matrix of diagonal form */
 cout << "entering loop\n";
 for(j=0; j<noofequations; j++)
 {
	  temp=j;

	 /* finding maximum coefficient of Xj in last (noofequations-j) equations */

	  for(i=j+1; i<noofequations; i++)
				if(augmentedmatrix[i][j]>augmentedmatrix[temp][j]) temp=i;

		  if(fabs(augmentedmatrix[temp][j])<minvalue)
			{
				  printf("\n Coefficients are too small to deal with !!!");
				  goto end;
			}

	 /* swapping row which has maximum coefficient of Xj */

	  if(temp!=j)
	  {
			minus++;
				for(k=0; k<=noofequations; k++)
				{
				temporary=augmentedmatrix[j][k] ;
				augmentedmatrix[j][k]=augmentedmatrix[temp][k] ;
				augmentedmatrix[temp][k]=temporary ;
				}
				cout << "after swapping\n";
	  }

	/* performing row operations to form required diagonal matrix */

	  for(i=0; i<noofequations; i++)
				if(i!=j)
				{
				r=augmentedmatrix[i][j];
				for(k=0; k<=noofequations; k++)
				  augmentedmatrix[i][k]-=(augmentedmatrix[j][k]/augmentedmatrix[j][j])*r ;
				}	
 }
 
 /* Display augmented coefficient matrix */

 printf("\n After diagonalization of entered augmented coefficient matrix : \n\n") ;
 for(i=0; i<noofequations; i++)
 {
  for(j=0; j<=noofequations; j++)
            printf("  %4.2f",augmentedmatrix[i][j]) ;
  printf("\n");
 }

 /* finding and displaying determinant of coefficient matrix */
 /*
 temporary=1.0 ;
 for(i=0; i<noofequations; i++)
            temporary*=augmentedmatrix[i][i] ;        /* multiplying diagonal elements only */
 /*
 if(minus%2==0)
    printf("\n Determinant of coefficient matrix = %.2f", temporary) ;
 else
    printf("\n Determinant of coefficient matrix = %.2f", -temporary) ;


  /* storing solutions */
 /*
 for(i=0;i<noofequations; i++)
  solutions[i]=augmentedmatrix[i][noofequations]/augmentedmatrix[i][i] ;

 /* printing solutions */
 /*
 printf("\n\n\n");

 for(i=0; i<noofequations; i++)
  printf("  X%d  =  %4.2f \n", i, solutions[i]) ;
 */
 end: getch() ;

 }