#include <stdio.h>
#include <stdlib.h>


int run_checker_tests();
int run_graph_tests();
int run_obj_tests();
int run_input_tests();
int run_maps_tests();


int main(){
    if(system("clear") == 0 ){}
    
    int success = 0;
    int failure = 0;
    int result = 0;

    result += run_checker_tests();
    result += run_graph_tests();
    result += run_obj_tests();
    result += run_input_tests();
    result += run_maps_tests();
    
    if(result > 0){
        success = result / 1000;
        failure = result % 1000;
    }
    
    printf("\nTest Totales: \n");
    printf("                  Success: %d\n", success);
    printf("                  Failure: %d\n", failure);
    printf("**********************************************\n");
    
    return 0;
}
