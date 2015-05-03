# coinflip_combinations
Counts the number of 50-50 coin flips before a set sequence of heads appears in a row. 
This is from over a year ago. It's one of my first c++ programs, and is pretty sloppy. 

For example, if the search term is 5, the program will flip coins until a sequence of 5 
heads appears. It will output the number of trials to get the sequence - including the final 5 - 
and then count again. The output is a list of different trials to get the same sequence. 

An example output might look like: 
    Enter your search term: 9

    371 2112 1034 867 154 93 1017 953 707 431
    403 550 1675 197 1126 360 701 39 1238 

    This implies that a sequence of 9 flips was found after 371 flips. 
    The counter was reset, and it took another 2112 flips to find another sequence of 9. 

This program was used for a combinatorics assignment. I needed a lot of data, so instead of returning one result per query,
I chose to flip the coin a set number of times (15,000 for large ints) to get bigger sets of data. 

NOTE: an issue might be that this is only checking for one of the two possibilities - heads. It does not count sequences of tails. One can assume that over a large enough data set, the number of tails sequences is equal to the number of heads sequences that emerged. 

It's also important to note that the counter resets with each trial. If, for example, 10 sequences emerge on the first trial, the 11th sequence (the first of the second trial) will be artificially low. It should include all remaining flips from the 10th sequence to the end of the array + the number of flips from the new trial. I discarded these manually.
