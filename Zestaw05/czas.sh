for VALUE in {0..300001..10000}
do
    printf "%s " "$VALUE" >> bubble_sort_time.txt
    ./Generator.x $VALUE 1000000 | ./BubbleSort.x >> bubble_sort_time.txt
done

for VALUE in {0..1000001..10000}
do
    printf "%s " "$VALUE" >> insertion_sort_time.txt
    ./Generator.x $VALUE 1000000 | ./InsertionSort.x >> insertion_sort_time.txt
done

for VALUE in {0..700001..10000}
do
    printf "%s " "$VALUE" >> selection_sort_time.txt
    ./Generator.x $VALUE 1000000 | ./SelectionSort.x >> selection_sort_time.txt
done

for VALUE in {0..1000001..10000}
do
    printf "%s " "$VALUE" >> couting_sort_time.txt
    ./GeneratorCS.x $VALUE 1000000 | ./CountingSort.x >> couting_sort_time.txt
done