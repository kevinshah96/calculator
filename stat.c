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
typedef struct node{	
	float q;
	int c ;
	}node;
float mean(float *p,int count);
float sort(float *p,int count){
	int c,d;
	float t;
	for (c = 1 ; c <= count - 1; c++) {
		d = c;
 
	    while ( d > 0 && p[d] < p[d-1]) {
      			t  = p[d];
      			p[d]   = p[d-1];
      			p[d-1] = t;
			d--;
		}
	}
 return *p;
}
float median(float *p, int count){
	float x[count];
	float median;
	x[0] = sort(p,count);
	if(count % 2 == 1){
		median = x[(count+1)/2];
	}
	else if(count % 2 == 0){
		median =( x[count/2] +x[count/2 +1])/2;
	}
	return median;
	}

float mode(float *p,int count){
	node a[count];
	int d,i;
	for(i = 0; i< count;i++){
		a[i].c = 0;
	}//putting all elements in a[i].c=0
	/*compare the elements in node and array 
	if same c++; if not there c=1;*/
	for(d=0;d < count;d++){
		i=0;
		for(i=0;i <count;i++ ){
			if(p[d] == a[i].q){
				(a[i].c)++;
			}
		  	else{
				a[i].q = p[d];
				a[i].c=1;
			}
		}
	}
	for(i=1;i<count;++i) 
    {
       if(a[0].c<a[i].c) 
           a[0].c=a[i].c;
    }
	return a[0].c;
}
float firstquartile(float* p ,int count){
/*aim is to find the median of 1st half of array*/
	float q[count/2] , a;
	int c;
	*p = sort(p,count);
	for(c=0 ;c<count/2;c++){
		q[c] = p[c];
	}
	a = median (q,count/2);
	return a;
	}
float thirdquartile(float* p ,int count){
/*aim is to find the median of 1st half of array*/
	float q[count/2] , a;
	int c;
	*p = sort(p,count);
	for(c=count ;c > count/2;c--){
		q[c] = p[c];
	}
	a = median (q,count/2);
	return a;
}
float quartilerange(float *p,int count){
	float a,b,range;
	a = firstquartile(p,count);
	b = thirdquartile(p,count);
	range = b-a;
	return range;
}
float findmax(float *p,int count){
        int c;
        float max,temp;
        max = p[0];
        for(c = 1; c < count;c++){
                if(p[c] > max){
                        temp = max;
                        max = p[c];
                        p[c]= temp;
                }
        }
        return max;
        }
float findmin(float *p,int count){
        int c;
        float min,temp;
        min =p[0];
        for(c = 1; c < count;c++){
                if(p[c] < min){
                        temp = min;
                        min = p[c];
                        p[c]= temp;
                }
        }
        return min;
        }



float findrange(float *p,int count){
	float mi,ma;
	mi = findmin(p,count);
	ma = findmax(p,count);
	return ma-mi;
	}
float standarddeviation(float *p, int count){
	int c;
	float m,sum=0,r;
	m = mean(p,count);
	for(c = 0;c < count;c++){
		sum = sum + (p[c]-m);
	}
	r = sqrt(sum/count);
	return sqrt(r);
}
float variance(float *p, int count){
	float sd;
	sd = standarddeviation(p,count);
	return pow(sd,2);
	}
float skewness(float *p,int count){
	float mea,med,sd,s;
	mea = mean(p,count);
	med =median(p,count);
	sd = standarddeviation(p,count);
	s = (3*(mea-med))/sd;
	return s;
	}
float kurtosis(float *p,int count){
	float sd,sum=0,mea,k;
	int i;
	mea = mean(p,count);
	for(i=0;i<count;i++){
		sum=sum+pow((p[i]-mea),4);
	}
	sd = standarddeviation(p,count);
	k = sum/(pow(sd,4)*count-1);
	return k;
	}
float mean(float *p,int count){
	float sum=0;
	float mean = 0;
	int i;
	for(i = 0;i < count;i++);
		sum = sum+p[i];
	mean = sum/(count);
	return mean; 
}

