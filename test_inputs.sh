#! bin/bash

echo "--- Non integer arg ---"
valgrind ./push_swap 12 11 ab 13 15
echo "--- Max int ---"
valgrind ./push_swap 12 11 14 2147483647 15
echo "--- Min int ---"
valgrind ./push_swap 12 11 14 -2147483648 15
echo "--- Out of max int limits ---"
valgrind ./push_swap 12 11 14 2147483648 15
echo "--- Out of min int limits ---"
valgrind ./push_swap 12 11 14 -2147483649 15
echo "--- Duplicate values ---"
valgrind ./push_swap 12 11 14 11 15
# echo "--- Valid values ---"
# ./push_swap 12 11 -14 13 15
