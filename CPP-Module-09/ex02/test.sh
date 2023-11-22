#!/bin/bash

for i in {2..20} ; do
    for j in {1..10} ; do
        ./PmergeMe `shuf -i 1-$i -n $i | tr "\n" " " ` > test.txt
        ./testing
        echo ""
    done
done

for i in {1..10} ; do
    ./PmergeMe `shuf -i 1-1000 -n 1000 | tr "\n" " " ` > test.txt
    ./testing < test.txt
    echo ""
done

for i in {1..10} ; do
    ./PmergeMe `shuf -i 1-3000 -n 3000 | tr "\n" " " ` > test.txt
    ./testing < test.txt
    echo ""
done


# Testing leaks (Takes a while)

# for i in {2..21} ; do
#     for j in {1..3} ; do
#         valgrind ./PmergeMe `shuf -i 0-$i -n $i | tr "\n" " " ` >> leaks.txt 2>&1
#         echo ""
#     done
# done

# for i in {1..3} ; do
#     valgrind ./PmergeMe `shuf -i 1-1000 -n 1000 | tr "\n" " " ` >> leaks.txt 2>&1
#     echo ""
# done

# for i in {1..3} ; do
#     valgrind ./PmergeMe `shuf -i 1-3000 -n 3000 | tr "\n" " " ` >> leaks.txt 2>&1
#     echo ""
# done

# cat leaks.txt | grep "definitely lost" | cut -d" " -f4 | tr -d "," | awk '{s+=$1} END {print s}'
# cat leaks.txt | grep "indirectly lost" | cut -d" " -f4 | tr -d "," | awk '{s+=$1} END {print s}'
# cat leaks.txt | grep "possibly lost" | cut -d" " -f4 | tr -d "," | awk '{s+=$1} END {print s}'
# cat leaks.txt | grep "still reachable" | cut -d" " -f4 | tr -d "," | awk '{s+=$1} END {print s}'
# cat leaks.txt | grep "errors" | cut -d" " -f4 | tr -d "," | awk '{s+=$1} END {print s}'