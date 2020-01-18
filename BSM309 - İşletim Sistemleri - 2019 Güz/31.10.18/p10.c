
 // export OMP_NUM_THREADS=5   //OPENMP 
//  gcc -o hello -fopenmp hello.c  //openmp derleme

#include <omp.h> 
  
#include <stdio.h> 
#include <stdlib.h> 
  
int main(int argc, char* argv[]) 
{ 
  
    // Beginning of parallel region 
    #pragma omp parallel 
    { 
  
        printf("Hello World... from thread = %d\n", 
               omp_get_thread_num()); 
    } 
    // Ending of parallel region 
} 

