#!/bin/bash
cd cat
chmod +x test.sh
./test.sh 
CODE_CAT=$?

cd ../grep
chmod +x test.sh
./test.sh
CODE_GREP=$?

echo "Test for cat script returned: $CODE_CAT"
echo "Test for grep script returned: $CODE_GREP"

if [ $CODE_CAT -ne 0 ] || [ $CODE_GREP -ne 0 ]; then
  exit 1
fi