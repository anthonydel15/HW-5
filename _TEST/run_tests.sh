#!/bin/bash

echo '\033[0;33m'"###################################################################" '\033[m'
echo '\033[0;33m'"The following should produce the correct output" '\033[m'
echo '\033[0;33m'"###################################################################" '\033[m'
echo _TEST/pizza-log.txt | _TEST/a.out
echo
echo '\033[0;33m'"###################################################################" '\033[m'
echo '\033[0;33m'"The following should produce errors" '\033[m'
echo '\033[0;33m'"###################################################################" '\033[m'
echo doesNotExist.txt | _TEST/a.out

echo


