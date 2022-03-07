for VALUE in {0..1000000..5000}
do
    printf "%s " "$VALUE" >> couting_sort_time.txt
    ./Generator.x $VALUE 1000000 | ./CountingSort.x >> couting_sort_time.txt
done