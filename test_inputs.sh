#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo "Testing push_swap input validation..."
echo ""

# Test function
test_case() {
	local name=$1
	shift
	echo -n "Testing: $name ... "

	output=$(./push_swap "$@" 2>&1)
	exitcode=$?

	if [ $exitcode -eq 1 ]; then
		echo -e "${GREEN}PASS${NC}"
	else
		echo -e "${RED}FAIL${NC} (expected error but got exit code $exitcode)"
	fi
}

# Invalid input tests (should error)
test_case "Non-integer argument" 12 11 ab 13 15
test_case "Max int overflow" 12 11 14 2147483648 15
test_case "Min int overflow" 12 11 14 -2147483649 15
test_case "Duplicate values" 12 11 14 11 15

# Valid input test (should succeed)
echo -n "Testing: Valid input ... "
output=$(./push_swap 12 11 -14 13 15 2>&1)
exitcode=$?
if [ $exitcode -eq 0 ]; then
	echo -e "${GREEN}PASS${NC}"
else
	echo -e "${RED}FAIL${NC} (expected success but got exit code $exitcode)"
fi

# Test max and min int boundaries (should succeed)
echo -n "Testing: Max int boundary ... "
output=$(./push_swap 12 11 14 2147483647 15 2>&1)
exitcode=$?
if [ $exitcode -eq 0 ]; then
	echo -e "${GREEN}PASS${NC}"
else
	echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing: Min int boundary ... "
output=$(./push_swap 12 11 14 -2147483648 15 2>&1)
exitcode=$?
if [ $exitcode -eq 0 ]; then
	echo -e "${GREEN}PASS${NC}"
else
	echo -e "${RED}FAIL${NC}"
fi

echo ""
