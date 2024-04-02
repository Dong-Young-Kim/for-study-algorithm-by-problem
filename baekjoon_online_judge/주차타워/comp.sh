#!/bin/bash

cnt=0
for ((i=1; i<=113; i++)); do
    
    # number formatting
    filenum=$(printf "%02d" $i)

    # input/output file path
    input_file="./parking-tower/${filenum}.in.txt"
    output_file="./parking-tower/${filenum}.out.txt"

    # run python script
    output=$(python3 boj_25404_slwin.py < $input_file)
    expected_output=$(< $output_file)


    # check if the output is correct
    # if [ "$output" = "$expected_output" ]; then
    #     echo "Test case $filenum: 성공"
    # else
    #     echo "Test case $fulenum: 실패"
    # fi
    if [ "$output" != "$expected_output" ]; then
        echo "-----------------------------------"
        echo "[FAILED] : Test case = $filenum"
        echo "Expected : $expected_output"
        echo "Output   : $output"
        cnt=$((cnt+1))
    fi

done

echo "-----------------------------------"
if [ $cnt -eq 0 ]; then
    echo "All test cases PASSED."
else
    echo "$cnt test cases FAILED."
fi
