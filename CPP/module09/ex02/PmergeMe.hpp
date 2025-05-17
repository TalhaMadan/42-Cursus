#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <vector>
#include <deque>
#include <ctime>
#include <sstream>
#include <iostream>
#include <cstdlib>

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();

        int start (int ac, char *av[]);
        void sort1(std::vector<int> & bar);
        void mergeSort1(std::vector<int>& left, std::vector<int>& right, std::vector<int>& bars);
        void sort2 (std::deque<int>& bar);
        void mergeSort2(std::deque<int>& left, std::deque<int>& right, std::deque<int> & bars);
        void process();
        void print_values();
    
    
    private:
        std::deque<int> _deque;
        std::vector<int> _vector;
};

#endif