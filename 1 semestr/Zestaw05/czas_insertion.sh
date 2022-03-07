for VALUE in {0..1000000..5000}
do
    printf "%s " "$VALUE" >> insertion_sort_time.txt
    ./Generator.x $VALUE 1000000 | ./InsertionSort.x >> insertion_sort_time.txt
done