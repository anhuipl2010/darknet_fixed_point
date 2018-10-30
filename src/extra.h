#include <stdio.h>
#include <stdio.h>

struct distributed{
    float count;
    float min;
    float max;
    float ave;
    float varaince;
    float stddev;
};

void initial_dist(struct distributed *d ){
   d->count   =0;
   d->min     =0;
   d->max     =0;
   d->ave     =0;
   d->varaince=0;
   d->stddev  =0;
}

struct distributed cal_distribution(float *data, int length){
    struct distributed dis;
    initial_dist(&dis);

    int   i=0;
    float sum=0,max=0,min=0;

    dis.count = length;
    
    max=data[0];
    min=data[0];

    for(i=0; i<length;i++){
        sum += data[i];
        if(max < data[i]) max=data[i];
        if(min > data[i]) min=data[i];
    }
    dis.ave = sum/(float)length;
    dis.min = min;
    dis.max = max;

    for(i=0;i<length;i++)
        dis.varaince += pow((data[i] - dis.ave), 2);

    dis.stddev= dis.varaince/(float)length;

return dis;
}


void gen_weight(float *bias,int len_b ,float *weight,int len_w,float *outmap ,int len_f ,int layer){
        FILE *ft = fopen( "./conv_weights.txt", "a+");
        int i;
        fprintf(ft, "\nweight: %d\n",layer );
        for(i=0; i<len_w; i++)  fprintf(ft, "%f ", weight[i] );
        fprintf(ft, "\nbias: \n" );
        for(i=0; i<len_b; i++)  fprintf(ft, "%f ", bias[i]  );
        fprintf(ft, "\nfeaturemap: \n" );
        for(i=0; i<len_f; i++)  fprintf(ft, "%f ", outmap[i]  );

        fclose(ft);

}
