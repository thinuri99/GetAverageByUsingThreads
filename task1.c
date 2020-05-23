//ID Number: IT19022666
//Name:P.T.D.Thissera
//Y2S1- SOS Assignment 
//Task_01 

#include <stdio.h>//Header file for standard input/output
#include <stdlib.h>//To include functions, Involving memory alocation, Process control, Conversions and others  
#include <pthread.h>//To create multiple threads for concurrent process flow
#include <string.h>//Various memory handling function

struct task1//Create structure called 'task1'
{
//******* Declaring_Variables **********

	int a1[150];
	int a2[150];
	int l1;
	int l2;
	int c1[150];
	int v;
	float a3[150];
	char l3;
}t1;//The variable t1 is declared with 'task1'


//******** Functions_Created *******
int read_n();
int read_l();
int cal_avg(int x);
int write_avg();

int main()//The begining of the 'main' function
{
	int checking;
//****** calling_funtion ******
	read_n();
	read_l();

	pthread_t id[t1.l1];//Create and used to identify a thread

	for (t1.v = 1; (t1.v<=t1.l1-1); ++t1.v)
	 {
		 checking = pthread_create(&id[t1.v],NULL, (void *)cal_avg, (void *)t1.a2[t1.v]);//Create thread using different attributes

		 if (checking == 0)//Checking the thread
		 {
			 printf("Creating tread_%d status: OK\n",t1.v);//Checking signals
		 }
		 pthread_join(id[t1.v],NULL);//To wait for the threads to complete
	 }
	write_avg();//Funtion calling

	return 0;
}//Ends of the function main

int read_n()//This function is created by reading the numbers in the dataset.file
{
	struct t1;
	t1.a1[0] = 0;
	int tot, t = 0;
	char chr[BUFSIZ];
	int c2;

	FILE *cfPtr;//File pointer
	cfPtr = fopen("dataset.txt","r");//Open a text file called 'dataset.txt' to read data

	if (cfPtr == NULL)//Check if the 'dataset.txt' is open properly
	{
		printf("Wrong!!\n");
		return -1;
	}

	int i;
	while (fgets(chr,sizeof chr,cfPtr) != NULL)//Reading the 'dataset.txt' file
	{
		int x;
		int y = 0;
		char *chr2 = chr;
		int c2 = 0;
		t++;
		while (sscanf(chr2,"%d%n",&x,&y) == 1)
		{
			chr2 += y;
			c2++;
			tot = tot + x;//calculatin the summation of the each of line numbers 
		}
		++i;

		t1.a1[i] = tot;
		t1.a2[i] = t1.a1[i] - t1.a1[i - 1];//Equl the summation of each lines to struct variable
		t1.c1[i] = c2;//Equal count of numbers in each lines
	}
	fclose(cfPtr);//Close file pointer
}

int read_l()//This function is created to read the data line-by-line in dataset.txt file  
{
	FILE *cfPtr;//File pointer
	cfPtr = fopen("dataset.txt","r");//Open a text file called 'dataset.txt' to read data

	if(cfPtr == NULL)//Check if the file 'dataset.txt' is open properly
	{
		printf("Wrong!!\n");
		return -1;
	}

	int i;
	t1.l3 = getc(cfPtr);//Equl to the numbers

	while(t1.l3 != EOF)//Count how many lines are in the file
	{
		if(t1.l3 == '\n')
		{
			++i;
			t1.l1 = t1.l1 + 1;//The falg 
		}
		t1.l3 = getc(cfPtr);
	}
	fclose(cfPtr);//Close file pointer
}

int cal_avg(int x)//This function is created to calculate the average of the dataset.txt file, line-by-line
{
	t1.a3[t1.v] = (x / (t1.c1[t1.v]));

	printf("%d Line sum is: %d\n", ++t1.l2, x);
	printf("%d Line Average is: %.2f\n", t1.l2, t1.a3[t1.v]);

}

int write_avg()//This function will write the calculated average to a file called 'average.txt'
{
	FILE *cfPtr;//File pointer
	cfPtr = fopen("average.txt","w");//Open a text file called 'average.txt' to write/store data
	
	if(cfPtr == NULL)//chck if the file 'average.txt' is open properly
	{
		printf("Error!!\n");
		return -1;
	}

	for(int i = 1; (i <= t1.v - 1); ++i)
	{
		//The values corresponding to the output are written in the file called 'average.txt'
		fprintf(cfPtr,"%d Line Sum is: %d\n",i,t1.a2[i]);
		fprintf(cfPtr,"%d Line Average is : %.2f\n",i,t1.a3[i]);
	}
fclose(cfPtr);//Close file pointer
}

//Reference:
//https://www.programiz.com/c-programming
//https://www.tutorialspoint.com/cprogramming/index.htm
//https://www.tutorialspoint.com/c_standard_library/string_h.htm
//https://www.w3schools.in/c-tutorial/c-header-files/
//Labsheet4,6

  
