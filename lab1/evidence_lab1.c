#include <stdlib.h>
#include <stdio.h>
#include "lab1.h"

/* evidence_expt: test expt */
void evidence_expt()
{
    printf("*** testing expt\n");
    printf("- expecting 1: %lld\n", expt(2,0));
    printf("- expecting 8: %lld\n", expt(2,3));
    printf("- expecting 8: %lld\n", expt(8,1));
    printf("- expecting 32: %lld\n", expt(2,5));
    printf("- expecting 100: %lld\n", expt(10,2));
}

/* evidence_ss: test ss */
void evidence_ss()
{
    printf("*** testing ss\n");
    printf("- expecting 1: %lld\n", ss(2,0));
    printf("- expecting 8: %lld\n", ss(2,3));
    printf("- expecting 8: %lld\n", ss(8,1));
    printf("- expecting 32: %lld\n", ss(2,5));
    printf("- expecting 100: %lld\n", ss(10,2));
}

/* evidence_ssm: test ssm */
void evidence_ssm()
{
    printf("*** testing ssm\n");
    printf("- expecting 24: %d\n", ssm(2,10,1000)); 
    printf("- expecting 0: %d\n", ssm(2,8,2));
    printf("- expecting 7: %d\n", ssm(3,3,20));
    printf("- expecting 16: %d\n", ssm(3,1000,17));
    printf("- expecting 1: %d\n", ssm(81,81,8));
    
    
    
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_expt();
    evidence_ss();
    evidence_ssm(); 
    return 0;
}