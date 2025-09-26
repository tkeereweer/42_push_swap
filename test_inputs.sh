#! bin/bash

echo "--- Non integer arg ---"
./push_swap 12 11 ab 13 15
echo "--- Max int ---"
./push_swap 12 11 14 2147483647 15
echo "--- Min int ---"
./push_swap 12 11 14 -2147483648 15
echo "--- Out of int limits ---"
./push_swap 12 11 14 21474836490 15
echo "--- Out of int limits ---"
./push_swap 12 11 14 -21474836450 15
echo "--- Duplicate values ---"
./push_swap 12 11 14 11 15
echo "--- Valid values ---"
./push_swap 12 11 -14 13 15
