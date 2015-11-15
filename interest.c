#include<stdio.h>
#include<math.h>
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
sinter a;
cinter b;
typedef enum tofind{
	principal = 0,
	noofyears,
	rate,
	interest,
	amount
	}tofind;
float scalculate(sinter a,int i){
	float j,k;
	switch(i){
		case 0: a.p = (a.si*100) / (a.n * a.r);
			return a.p;
			break;
		case 1: j = (a.si*100) / (a.p * a.r);
			k = (int)j;
			if (j-k < 0.5){
				a.n = k;
				return a.n;
				}
			else 
				a.n = k+1;
				return a.n;
			break;
		case 2: a.r = (a.si *100) / (a.p * a.r);
			return a.r;
			break;
		case 3: a.si = a.p * a.n * a.r / 100;
			return a.si;
			break;
		default : return 0;
			  break;
		}
}
float ccalculate(cinter b, int i){
	float j,k;
	switch (i){
		case 0:if(b.ci!=0 && b.a !=0){
				b.p = b.a - b.ci;
				return b.p;
				break;
			}
			else
				j = 1+((b.r)/100/(b.n));
				k = pow(j,(b.n*b.t));
				b.p = b.a / k;
				return b.p;
				break;
		case 1:if (b.n != 0){
				j = log(1+(b.r/100/b.n));
				k = log(b.a/b.p);
				b.t = j/(b.n*k);
				return b.t;
				break;
				}
			else return -1;
				break;
		case 2:if (b.n != 0 && b.t != 0){
			j = pow((b.a/b.p),(1/(b.n*b.t)));
			k = j-1;
			b.r = b.n * k;
			return b.r;
			break;
			}
			else return -1;
				break;
		case 3:if (b.a!=0 && b.p != 0){
				b.ci = b.a - b.p;
				}
			else 	
				j = 1+(b.r/b.n);
				k = pow(j,b.n * b.t); 
				b.a = b.p*k;
				return b.a-b.p;
				break;
		case 4:if (b.ci != 0 && b.p != 0){
				return b.ci+b.p;
				break;
			}
			else 	j = 1+(b.r/b.n);
				k = pow(j,(b.n*b.t));
				b.a = b.p * k;
				return b.a;
				break;
		 default : 
				return 0;
				break;
			}
			return 0;
		}
					
				    		 
