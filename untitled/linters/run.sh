#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
if [ "${1}" == "--local" ]; then
	CPPCHECK="cppcheck"
else
	CPPCHECK="./linters/cppcheck/cppcheck"
fi
${CPPCHECK} project --enable=all --error-exitcode=1 -I project/include --suppress=missingIncludeSystem -i project/tests # --check-config

print_header "RUN cpplint.py"
python2.7 ./linters/cpplint/cpplint.py --extensions=c --filter=-build/header_guard,-runtime/printf,-runtime/arrays project/src/* lib/utils/* lib/parallel/* lib/sequential/*

print_header "SUCCESS"
