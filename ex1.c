int main(void) {
  //initialize and open files
  FILE *input;
  input = fopen("input.txt", "r");
  FILE *output;
  output = fopen("output.txt", "w");
  int m=0;
  //ask user for number of recourses 
  printf("Enter number of resouces:");
  scanf("%d", &m);
  //acreate vectors for availible and total recourses
  int E[m];
  int A[m];
  for (int i=0; i<m; i++){
   fscanf(input,"%d", &E[i]);
  }
  for (int i=0; i<m; i++){
    fscanf(input,"%d", &A[i]);
  }
  int n=0;
  printf("Enter number of processes:");
  scanf("%d", &n);
  int C[n][m];
  //scan Current allocation matrix
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      fscanf(input,"%d", &C[i][j]);
    }
  }
  //scan Request matrix
  int R[n][m];
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      fscanf(input,"%d", &R[i][j]);
    }
  }
  //keep this list to track whether recourse has finished
  int process[n];
  for (int i=0; i<n; i++){
    process[i]=1;
  }
  
for (int i=0; i<n; i++){
    for (int k=0; k<n; k++){
      //if process is still not processes
    if (process[k]==1){
    int ok=0;
    //calculate if all requested resources can be given 
    for (int j=0; j<m;j++){
      if (R[k][j]<=A[j] ){
        ok++;
      }
    }
    //if yes then execute process, release the recourses 
    if (ok==m){
      for (int j=0; j<m;j++){
        A[j]+=C[k][j];
        
      }
      //set process as terminated
      process[k]=0;
    }
    }
    }
  }
  // after terminating all possible processes
  int deadlock=0;
  for (int i=0; i<n; i++){
    //if process is still not process it is in a deadlock
      if(process[i]==1){
      deadlock=1;
      fprintf(output,"Process %d is in a deadlock\n",i+1);
      }
  }
 // else there is no deadlock
 if(deadlock==0){
   fprintf(output,"No deadlock is detected");
 }
 //close files
 fclose(input);
 fclose(output);

  return 0;
}
