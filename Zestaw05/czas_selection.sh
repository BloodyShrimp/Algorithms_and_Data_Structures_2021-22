for VALUE in {0..700000..5000}
do
    printf "%s " "$VALUE" >> selection_sort_time.txt
    ./Generator.x $VALUE 1000000 | ./SelectionSort.x >> selection_sort_time.txt
done