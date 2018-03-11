#include <stdio.h>
#include <stdlib.h>


int run_checker_tests();
int run_graph_tests();
int run_obj_tests();
int run_input_tests();


int main(){
    if(system("clear") == 0 ){}

    run_checker_tests();
    run_graph_tests();
    run_obj_tests();
    run_input_tests();
    
    return 0;
}
