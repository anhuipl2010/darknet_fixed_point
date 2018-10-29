#include <stdio.h>
#include <stdio.h>

void gen_weight(float *bias ,float *weight,int len,float *outmap ,int f_len ,int layer){
    printf("<<<\n");
        FILE *ft = fopen( "./conv_weights.txt", "a+");
        int i;
        fprintf(ft, "\nweight: %d\n",layer );
        for(i=0; i<len; i++)  fprintf(ft, "%f ", weight[i] );
        fprintf(ft, "\nbias: \n" );
        for(i=0; i<len; i++)  fprintf(ft, "%f ", bias[i]  );
        fprintf(ft, "\nfeaturemap: \n" );
        for(i=0; i<f_len; i++)  fprintf(ft, "%f ", outmap[i]  );

        fclose(ft);

}
