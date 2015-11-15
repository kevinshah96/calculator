
/*  Calculator with twist.
 *  Copyright (C) 2015 kevinshahcool@gmail.com Kevin shah.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include<stdio.h>
#include"myqueue.h"
#include<stdlib.h>
#include<math.h>
#define max 128
typedef struct complex{
	float a,b;
}complex;
typedef struct sinterest{
	float p;
	float r;
	int n;	
	float si;
	}sinter;
typedef struct cinterest{
	float p ;
	float r ;
	int n ;	
	float ci;
	float a ;
	int t;
	}cinter;
float mean(float *p,int count);
float mode(float *p,int count);
float median(float *p,int count);
float firstquartile(float *p,int count);
float thirdquartile(float *p,int count);
float quartilerange(float *p,int count);
float standarddeviation(float *p,int count);
float variance(float *p,int count);
float skewness(float *p,int count);
float kurtosis(float *p,int count);
float findrange(float *p,int count);
float scalculate(sinter a,int i);
float ccalculate(cinter b, int i);
typedef enum tofind{
	principal = 0,
	noofyears,
	rate,
	interest,
	amount
	}tofind;
void print0(){
	printf("enter your choice\n");
	printf("1.Bodmas calculator\n");
	printf("2.Statistical calculator\n");
	printf("3.Interest calaculator\n");
	printf("4.Complex calculator\n");
	printf("5.Exit\n");
	}
void print1(){
	printf("enter the string\n");
	}
void print2(){
	printf("enter the nos.\n");
	}
void print3(){
	printf("What do you want to find?\n");
	printf("1.Simple Interest\n");
	printf("2.Compound Interest\n");
	printf("3.Comparison");
	}
void print31(){
	printf("What do you want to find?");
	printf("1.Principal\n");
	printf("2.Time\n");
	printf("3.Rate\n");
	printf("4.S.Interest\n");
	}
void print32(){
	printf("What do you want to find?");
	printf("1.Principal\n");
	printf("2.Time\n");
	printf("3.Rate\n");
	printf("4.C.Interest\n");
	printf("5.Amount\n");
	}	
void print4(){
	printf("Enter the type of operation oncomplex no.\n");
	printf("1.Unary\n");
	printf("2.Binary\n");
	}	
int main(){
	int i,j,k,count;
	char str[max];
	float no[max];
	float *p;
	sinter a;
	cinter b;
	float temp;
	float temp1;
	int tem;
	complex a1,a2;
	float mod(complex a1);
	print0();
	scanf("%d", &i);
	while(1){
	switch(i){
		case 1:
			print1();
			//scanf("%[^\n]", str);
			scanf("%s", str);
			printf("your answer is %d\n",infixeval(str[max]));
			print0();
			scanf("%d",&i);
			break;
		case 2:
			print2();
			/*j = 0;
			while(scanf("%f",&no[j])){
				j++;
			}
			count = j;
			*p = no[0];*/
			printf("enter the no of elements :");
			scanf("%d",&count);
			for(j = 0;j< count;j++){	
				scanf("%f",&no[j]);
				}
			p = no;
			printf("statistical analysis:::\n");
			printf("mean is %f \n",mean(p,count));
			printf("median is %f\n",median(p,count));
			printf("mode is %f\n",mode(p,count));
			printf("firstquartile is %f\n",firstquartile(p,count));
			printf("thirdquartile is %f\n",thirdquartile(p,count));
			printf("quartile range is %f\n",quartilerange(p,count));
			printf("range is %f\n ",findrange(p,count));
			printf("variance is %f\n ",variance(p,count));
			printf("standard deviation is %f\n ",mean(p,count));
			printf("skewness is %f\n",skewness(p,count));
			printf("kurtosis is %f\n",kurtosis(p,count));
			print0();
			scanf("%d",&i);
			break;
		case 3 :
			print3();
			scanf("%d",&j);						
			switch(j){
				case 1 :
					print31();
					scanf("%d",&k);
					switch(k){
						case 1:	printf("Simple interest:?\n");
							scanf("%f",&a.si);
							printf("Rateoi:?\n");
							scanf("%f",&a.r);
							printf("Time period in years:?\n");
							scanf("%d",&a.n);
							temp = scalculate(a,0);
							printf("%f is principal\n",temp);
							break;
						case 2:	printf("Simple interest:?\n");
							scanf("%f",&a.si);
							printf("Principal\n");
							scanf("%f",&a.p);
							printf("Rateoi:?\n");
							scanf("%f",&a.r);
							tem = scalculate(a,1);
							printf("%d is no of years\n",tem);
							break;
						case 3:printf("Simple interest:?\n");
							scanf("%f",&a.si);
							printf("Principal\n");
							scanf("%f",&a.p);
							printf("Time period in years:?\n");
							scanf("%d",&a.n);
							temp = scalculate(a,2);
							printf("%f is rate of interest\n",temp);
							break;
						case 4:	printf("Principal:?\n");
							scanf("%f",&a.p);
							printf("Rateoi:?\n");
							scanf("%f",&a.r);
							printf("Time period in years:?\n");
							scanf("%d",&a.n);
							temp = scalculate(a,3);
							printf("%f is principal\n",temp);
							break;
						default :
							break;
						}
					print0();
					scanf("%d",&i);
					break;
				case 2 :
					print32();
					scanf("%d",&k);
					printf("If you dont know any quantity then give it a 0\n");
					switch(k){
						case 1:	printf("C. interest:?\n");
							scanf("%f",&b.ci);
							printf("Rateoi:?\n");
							scanf("%f",&b.r);
							printf("Time period in years:?\n");
							scanf("%d",&b.t);
							printf("how many times is interest compounded?\n");
							scanf("%d",&b.n);
							printf("Amount:?\n");
							scanf("%f\n",&b.a);
							temp = ccalculate(b,0);
							printf("%f is principal\n",temp);
							break;
						case 2:printf("C. interest:?\n");
							scanf("%f",&b.ci);
							printf("Rateoi:?\n");
							scanf("%f",&b.r);
							printf("Principal\n");
							scanf("%f",&b.p);
							printf("how many times is interest compounded?\n");
							scanf("%d",&b.n);
							printf("Amount:?\n");
							scanf("%f\n",&b.a);
							tem = ccalculate(b,1);
							printf("%d is time period\n",tem);
							break;
						case 3:printf("C. interest:?\n");
							scanf("%f",&b.ci);
							printf("Principal:?\n");
							scanf("%f",&b.r);
							printf("Time period in years:?\n");
							scanf("%d",&b.t);
							printf("How many times is interest compounded?\n");
							scanf("%d",&b.n);
							printf("Amount:?\n");
							scanf("%f\n",&b.a);
							temp = ccalculate(b,2);
							printf("%f is Rate of interest\n",temp);
							break;
						case 4:printf("Principal:?\n");
							scanf("%f",&b.p);
							printf("Rateoi:?\n");
							scanf("%f",&b.r);
							printf("Time period in years:?\n");
							scanf("%d",&b.t);
							printf("how many times is interest compounded?\n");
							scanf("%d",&b.n);
							printf("Amount:?\n");
							scanf("%f\n",&b.a);
							temp = ccalculate(b,3);
							printf("%f is C.interest\n",temp);
							break;
						case 5:printf("C. interest:?\n");
							scanf("%f",&b.ci);
							printf("Rateoi:?\n");
							scanf("%f",&b.r);
							printf("Time period in years:?\n");
							scanf("%d",&b.t);
							printf("how many times is interest compounded?\n");
							scanf("%d",&b.n);
							printf("Principal?\n");
							scanf("%f\n",&b.a);
							temp = ccalculate(b,0);
							printf("%f is Amount\n",temp);
							break;
						default:printf("Mistake!\n"); 
							break;

					}
					print0();
					scanf("%d",&i);
					case 3:
						printf("Enter the principal,rate of i.,timeperiod ");
						scanf("%f,%f,%d",&a.p,&a.r,&a.n);
						b.p = a.p;
						b.r = a.r;
						b.t = a.n;
						b.n = 1;
						b.a = 0;
						temp = scalculate(a,3);
						temp1 = ccalculate(b,3);
						if (temp > temp1)
							printf("S.interest is better");
						else printf("C.interest is better");
						break;
					
					print0();
					scanf("%d",&i);
					}
		case 4: print4();
			scanf("%d",&j);
				switch(j){
					case 1:
						printf("Enter the Real part\n");
						scanf("%f",&a1.a);
						printf("Enter the Imaginary part\n");
						scanf("%f",&a1.b);
						printc(a1);
						printf("mod of no. is %f\n",mod(a1));
						printf("Conjugate of no is:");
						printc(conju(a1));
						printf("Inverse of no is:");
						printc((inverse(a1)));
						break;
					case 2 :
						printf("Enter the Real part of no.1\n");
						scanf("%f",&a1.a);
						printf("Enter the Imaginary part of no.1\n");
						scanf("%f",&a1.b);
						printf("Enter the Real part of no.2\n");
						scanf("%f",&a2.a);
						printf("Enter the Imaginary part of no.2\n");
						scanf("%f",&a2.b);
						printf("Addition is :");
						printc((add(a1,a2)));
						printf("Subtraction is :");
						printc((sub(a1,a2)));
						printf("Division is :");
						printc((divc(a1,a2)));
						printf("Multiplication is :");
						printc((multiply(a1,a2)));
						break;
					default :break;
					}
				print0();
				scanf("%d",&i);
			case 5:return 0;
				break;				
			}			
			}
			return 0;		
			}			
						
						
						
						
						
						
						
						
						
