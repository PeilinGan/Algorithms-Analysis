# Algorithms-Analysis

Design, implementation, execution, and analysis of algorithms for problems such as sorting, searching, data compression, and Network models. Time-space-structure trade-offs.

# Objective

This project aims to design, implement and analyze three different fields of algorithms.

# Analysis

The performance of different algorithm was plotted on a log-log scale to empirically determine the algorithm's asymptotic running time for each typle of distribution. The result and analysis can be found in report.pdf under each directory

# Sorting Algorithms

All algorithms are analyzed based on runtime experiments on random permutations, with multiple runs for each problem size. Specifically, each algorithm is experimented with Uniformly Distributed Permutations and Almost-sorted Permutations.

The algorithms to be analyzed includes

- Bubble-sort
- Insertion-sort
- Spin-the-bottl sort
- Shell-sort
- Annealing-sort

# Bin Packing Algorithms

All algorithms are analyzed based on runtime experiments on lists of items of lengh n, as n gorws, where the n items in the lists are floating point numbers between - and 1 generately uniformly at random. Each algorithm is defined to operate with bins of size 1. The goal of these experiments is to determine an estimate for the waste, W(A), for each of the above bin-packing algorithms, A, as a function of n, as n grows, where W(A) is defined as follows:

- The waste, W(A), of a bin-packing algorithm, A, for any given list of items, is the number of bins used by the algorithm A minus the total size (i.e., the sum) of all the items in the list.

The algorithms to be analyzed includes

- Next Fit
- First Fit
- Best Fit
- First Fit Decreasing
- Best Fit Decreasing

# Network Algorithms

Experiments with network algorithms involves testing various graph algorithms experimentally to determine properties of models of real-world networks.

The algorithms to be analyzed includes

- Diameter Algorithm
- Clustering-coefficient Algorithm
- Degree-distribution Algorithm
