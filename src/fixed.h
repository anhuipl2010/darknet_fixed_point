#include<stdio.h>
#include<stdlib.h>


float float_to_fixed(float input,int integer,int fractional ){
    int tmp_fixed;
    int max_int =((1<<(integer-1))-1 ) ;
    int sign=1;

    if(input<0) input*=-1,sign=-1;

    tmp_fixed = (double)(round(input * (1 <<( fractional))));
    if( (tmp_fixed>>fractional) > max_int )
        tmp_fixed = (max_int <<fractional) +  (tmp_fixed&(  (1<<(fractional+1))-1  ) ) ;

    double out=((double)tmp_fixed / (double)(1 << fractional));

    out*=sign;
    return  out;
}



void array2fixed(float *X,int length){
    //double *output = malloc(length*sizeof(double));// new double [length];

    int i_part=4,f_part=12,i;
    for(i=0 ; i<length ; i++)   
        X[i] = float_to_fixed(X[i],i_part,f_part);
        //output[i] = float_to_fixed(X[i],i_part,f_part);

        //    return X;//output;
}
