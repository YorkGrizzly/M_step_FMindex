#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include "fm_index.h"
#include <iostream>
#include <fstream>

#define DEBUG 0

void calculate_num_suffixes(std::ifstream &list_of_suffix_files, uint32_t &num_suffixes)
{
    while (!list_of_suffix_files.eof())
    {
        std::string F_suffix;
        uint32_t F_count;
        list_of_suffix_files >> F_suffix;
        list_of_suffix_files >> F_count;
        num_suffixes += F_count;
    }
}

int main(int argc, char *args[])
{
    std::ifstream list_of_suffix_files("../suffixes.sorted.meta");

    //Integer value of global counts encountered from 0 to (d_major*i-1)th stored in occ_major[i]
    int d_major = 1000;

    MStepFMIndex fm_index;
    uint32_t num_suffixes = 0;
    // calculate the total number of suffixes
    calculate_num_suffixes(list_of_suffix_files, num_suffixes);
    printf("Total number of suffixes: %d\n", num_suffixes);
    list_of_suffix_files.clear();
    list_of_suffix_files.seekg(0);
    //Initializes fm_index class variables
    init_M_step_fm_index(&fm_index, num_suffixes, d_major);

    //Creates fm_index from the sorted suffixes
    calculate_M_step_fm_index(&fm_index, list_of_suffix_files);

    list_of_suffix_files.close();
    //kmer to be searched in the fm_index
    // char *kmer = "GCAT$AATC";
    // char *kmer = "GAATTTCAATTAAGTGACACAGTAGCTAAGTAAAATAAAT";
    char *query_array[16] =
        {
            "AAACTACAAGTTTTTATTTATTTTACTTAGCTACTGTGTC",
            "GAATTTCAATTAAGTGACACAGTAGCTAAGTAAAATAAAT",
            "AACTACAAGTTTTTATTTATTTTACTTAGCTACTGTGTCA",
            "AGAATTTCAATTAAGTGACACAGTAGCTAAGTAAAATAAA",
            "ACTACAAGTTTTTATTTATTTTACTTAGCTACTGTGTCAC",
            "AAAAGTTGTAAAATTAGTGTCGGCAGGGCCATGTCCTTCT",
            "CTTCCTTAGAACCTCAGAAGGACATGGCCCTGCCGACACT",
            "AAAGTTGTAAAATTAGTGTCGGCAGGGCCATGTCCTTCTG",
            "TCTTCCTTAGAACCTCAGAAGGACATGGCCCTGCCGACAC",
            "AAGTTGTAAAATTAGTGTCGGCAGGGCCATGTCCTTCTGA",
            "TTCTTCCTTAGAACCTCAGAAGGACATGGCCCTGCCGACA",
            "AGTTGTAAAATTAGTGTCGGCAGGGCCATGTCCTTCTGAG",
            "ATTCTTCCTTAGAACCTCAGAAGGACATGGCCCTGCCGAC",
            "GTTGTAAAATTAGTGTCGGCAGGGCCATGTCCTTCTGAGG",
            "GATTCTTCCTTAGAACCTCAGAAGGACATGGCCCTGCCGA",
            "TTGTAAAATTAGTGTCGGCAGGGCCATGTCCTTCTGAGGT"};

    for (size_t i = 0; i < 16; ++i)
    {
        char *kmer = query_array[i];
        //Length of the kmer to be searched
        int kmer_length = 40;
        //result_start_interval'th to result_end_result'th suffixes in sorted suffixes list are match results of kmer in fm_index
        int result_start_interval = 0, result_end_result = 0;

#ifdef DEBUG

        printf("Querying for ");
        // for (uint32_t i = 0; i < kmer_length; ++i)
        //     printf("%c", kmer[i]);
        // printf("\n");
        printf("%s\n", query_array[i]);
#endif

        //Perform query for kmer in fm_index
        query_Mstep_fm_index(&fm_index, kmer, kmer_length, &result_start_interval, &result_end_result);

        printf("Result limits : %d to %d\n", result_start_interval, result_end_result);
    }
    return 0;
}
