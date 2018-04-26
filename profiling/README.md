# Profiling

This directory will contain various tools for profiling garbage collectors. We currently plan to use Boehm-Demers-Weiser's GC as a baseline.


### Metrics/Conditions
None of these have been implemented but they are possible directions to explore.
* Allocation time, how does it scale with number of allocated objects?
* Cache locality?
* Fragmentation
* Runtime
* Objects
  * Size (small/big)
  * Longevity (short/long-lived)
* Program length: ie as the program runs longer, does the pain become exponential or constant?
* Cyclic objects?
* Amount of reference updates
* Nested references
* Memory usage efficiency -- how often does this affect runtime?
* What does a GC's runtime scale with?
  * Reference counting: amount of reference updates
  * Mark and sweep: Size of heap
  * Copying: amount of relevant objects

### Todo:
* Decide on API
  * gc_new()
  * gc_malloc

### File Explanation
* GCBench.cpp: Measures overall execution time, the benchmark reports times required to allocate and drop complete binary trees of various sizes. All reported times are for similar amounts of allocation, and maintain some more permanent live data structures. Generational collectors generally exhibit much better performance for the smaller tree sizes, where nongenerational collectors tend to have a flatter performance profile. Taken from: http://www.hboehm.info/gc/gc_bench.html
  * requires -lgc to work, this gc is BDW's GC
