#include <stdio.h>
#include <stdlib.h>

void main(int argc, char * argv[]){
    //correct number of arguments?
    if(argc!=3){
        //no
        printf("Please provide the input and output text file names as %s name1 name2\n", argv[0]);
        return;
    }
    //yes
    
    //let there be FILE pointers!
    FILE *in;
    FILE *out;

    //open the files
    in=fopen(argv[1], "r");
    out=fopen(argv[2], "w");

    //did the files open?
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

    //int pointer
    int * np = (int *) malloc(sizeof(int));

    //read the file
    int card=1;
    if(!feof(in)){
            fscanf(in,"%d",&np[0]);
        }
    while(!feof(in)){
        if(!feof(in)){
            np = realloc(np, sizeof(int)*(card+1));
            fscanf(in,"%d",&np[card]);
            card++;
        }
    }

    int i=0;
    //sort the array
    for (i=0; i<card-1; i++){
        int min = i;
        for (int j=i+1; j<card; j++){
            if(np[j]<np[min]){
                min=j;
            }
        }
        int temp = np[i];
        np[i]=np[min];
        np[min]=temp;
    }

    //print the array to the file and the console
    if (card>1)
        fprintf(out, "%d", np[0]);
        printf("%d", np[0]);
        for (i = 1; i<card; i++){
            fprintf(out, " %d", np[i]);
            printf(" %d", np[i]);
        }
        printf("\n");

    //close both files and dynamic memory
    free(np);
    fclose(in);
    fclose(out);
}