#include <stdio.h>
#include <stdlib.h>

void main(int argc, char * argv[]){

    if(argc!=3){
        printf("Please provide the input and output text file names as %s name1 name2\n", argv[0]);
        return;
    }

    FILE *in;
    FILE *out;

    if((in==NULL)&&(in==NULL)){
        printf("Input file %s and output file %s cannot be opened.\n", argv[1], argv[2]);
        return;
    }
    if(in==NULL){
        printf("Input file %s cannot be opened.\n", argv[1]);
        return;
    }
    if(out==NULL){
        printf("Output file %s cannot be opened.\n", argv[2]);
        return;
    }

    in=fopen(argv[1], "r");
    out=fopen(argv[2], "w");

    int * next;
    next = (int *) malloc(sizeof(int));
    if(!feof(in)){
            fscanf(in,"%d",next);
            fprintf(out, "%d", *next);
    }
    while(!feof(in)){
        if(fscanf(in,"%d",next)!=EOF){
            fprintf(out, " %d", *next);
        }
    }
    free(next);
    fprintf(out, "\n");
    fclose(in);
    fclose(out);
}


