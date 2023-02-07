#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "wb_lists.h"
#include "prefix_sum.h"

TEST_CASE("--------testing--------") {
    SUBCASE("Testing array generator") {
        int * array  = generator(0);
        CHECK(array==nullptr);
        delete[] array;

        array = generator(2);
        for (int i=0; i<2; i++) {
            CHECK(array[i] == 1);
        }
        for (int i=0; i<2; i++) {
            CHECK(array[i+2] == -1);
        }
        delete[] array;
    }

    SUBCASE("Testing fisher-yates shuffle") {
        int array[] = {1, 2, 3, 4, 5, 6};
        int array_copy[] = {1, 2, 3, 4, 5, 6};
        int length = sizeof(array_copy)/sizeof(array_copy[0]);
        
        fisher_yates_shuffle(array, length);

        CHECK(sizeof(array_copy) == sizeof(array));

        std::cout << "shuffled array: ";
        for (int i=0; i<length; i++) {
            std::cout << array[i] << " ";
            bool element_found = false;
            for (int j=0; j<length; j++) {
                if (array_copy[i] == array[j]) {
                    element_found = true;
                    break;
                }
            }
            CHECK(element_found);
        }
        std::cout << std::endl;

        int array_2[] = {1, 2, 3, 4, 5, 6};
        length = sizeof(array_2)/sizeof(array_2[0]);
        
        fisher_yates_shuffle(array_2, length);
        std::cout << "shuffled array 2: ";
        for (int i=0; i<length; i++) {
            std::cout << array_2[i] << " ";
        }
        std::cout << std::endl;

        int array_3[] = {1, 2, 3, 4, 5, 6};
        length = sizeof(array_3)/sizeof(array_3[0]);

        fisher_yates_shuffle(array_3, length);
        std::cout << "shuffled array 3: ";
        for (int i=0; i<length; i++) {
            std::cout << array_3[i] << " ";
        }
        std::cout << std::endl;
    }

    SUBCASE("Testing counter") {
        int n = 11;
        int * array = generator(n);
        int count = 0;
        do {
            count++;
            fisher_yates_shuffle(array, 2*n);
        } while (!non_negative_sum(array, 2*n) && !non_positive_sum(array, 2*n));

        for (int i=0; i<2*n; i++) {
            if (array[i] == 1) std::cout << "( ";
            else std::cout<<") ";
        }
        std::cout<< std::endl;
        delete[] array;

        count = 0;
        int runs = 1000;
        n = 50;
        for (int i=0; i<runs; i++) {
            count += counter(n);
        }
        std::cout 
        <<"size of list: " << n*2 << std::endl
        <<"average number of iterations : " << (double)count/runs << std::endl; 
    }
}
