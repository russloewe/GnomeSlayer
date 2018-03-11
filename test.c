#include <stdio.h>
#include <stdlib.h>

int run_checker_tests();
int run_graph_tests();
int run_obj_tests();


int main(){
    system("clear");
    run_checker_tests();
    run_graph_tests();
    run_obj_tests();
    
    return 0;
}
