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
#include<math.h>
typedef struct complex{
	float a,b;
}complex;
complex conju(complex a1){
	a1.b = -a1.b;
	return a1;
	}
float mod(complex a1){
	float a;
	a =sqrt((a1.a*a1.a)+(a1.b*a1.b));
	return a;
}
complex add(complex a1,complex a2){
	complex a3;
	a3.a = a1.a + a2.a;
	a3.b = a1.b + a2.b;
	return a3;
	}
complex sub(complex a1,complex a2){
	complex a3;
	a3.a =a1.a - a2.a;
	a3.b =a1.b - a2.b;
	return a3;
	}
complex multiply(complex a1,complex a2){
	complex a3;	
	a3.a = (((a1.a)*(a2.a)) - ((a1.b)*(a2.b)));
	a3.b = (((a1.a)*(a2.b)) + ((a2.a)*(a1.b)));
	return a3;
	}
complex divc(complex a1,complex a2){
	complex a3,a4;
	//a3=a1/a2;
	if(a2.a != 0 && a2.b != 0){
	a4 = conju(a2);
	a3 = multiply(a1,a4);
	a3.a = a3.a / mod(a2);
	a3.b = a3.b / mod(a2);
	return a3;
	}
	}  
complex inverse(complex a1){
	complex a2;
	a2 = conju(a1);
	a2.a = a2.a / mod(a1);
	a2.b = a2.b / mod(a1);
	return a2;	
	}
void printc(complex a1){
	if (a1.b>0){
		printf(" %f + %f i\n",a1.a,a1.b);
		}
	else if (a1.b < 0){
		printf(" %f - %f i \n",a1.a,-a1.b);
		}
	else if(a1.b == 0)
		 printf("%f\n ",a1.a);
	}	

