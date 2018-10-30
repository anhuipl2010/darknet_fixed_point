#include <stdio.h>
#include <stdio.h>

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
