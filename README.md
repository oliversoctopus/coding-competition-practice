# Coding Competition Practice

My solutions to competitive programming problems, written while training for USACO from Bronze through Gold. Most problems come from USACO, with practice problems from other judges such as CSES, Codeforces, and AtCoder. About 100 solutions are in C++ and about 100 in Python.

All solutions are my own unless a file is marked otherwise.

## Folders

| Folder | Level | Contents |
| --- | --- | --- |
| `USACO Silver class/Bronze` | Bronze | Early Python solutions: simulation, brute force, and complete search |
| `USACO Silver class`, `USACO Silver class summer`, `USACO Silver fall 2025` | Silver | Class problems organized by course unit |
| `C++/Bronze`, `C++/Silver` | Bronze–Silver | Additional C++ practice problems, one folder per problem |
| `C++/class` | n/a | Classic algorithm implementations (merge sort, partitioning) |
| `usaco_gold_dp` | Gold | Dynamic programming, organized into six modules |
| `usaco_jan_2026` | n/a | My solutions to the January 2026 USACO contest problems |
| `usaco_meetings` | Silver–Gold | Problems from practice meetings |

## Highlights: Gold dynamic programming

Many of these files begin with a comment giving the DP state and recurrence.

| Problem | Folder | Technique |
| --- | --- | --- |
| Coin | `module 1/coin` | Counting DP over coin values |
| Highway Billboards | `module 1/highway-billboards` | 1D DP with the last compatible index |
| Stamp Painting | `module 1/stamp-painting` | Counting DP with complementary counting |
| Teamwork | `module 1/teamwork` | 1D DP over the last group; includes a random test generator |
| Radio Contact | `module 2/radio` | 2D DP over both paths' positions |
| 248 | `module 3/248` | Interval DP over subarrays |
| Inversion Pairs | `module 3/inversion_pair` | Interval DP via inclusion–exclusion |
| Cow Poetry | `module 4/cow_poetry` | Knapsack-style counting DP with modular exponentiation |
| Talent Show | `module 4/talent_show` | Binary search on the answer with a knapsack feasibility check |
| Delegation | `module 5/delegation` | Tree DP with a feasibility check for each path length |
| Cow Dance Show | `module 6/cow_dance_show` | DP over shows sorted by end time |
| Cutting Sticks | `module 6/cutting_stick` | Interval DP over cut positions |

## Running a solution

C++ (most files read from `<problem>.in` and write to `<problem>.out`, following USACO's file I/O format):

```
g++ -std=c++17 -O2 solution.cpp -o solution
./solution
```

Python:

```
python3 solution.py
```

Some folders also contain Visual Studio project files from my local setup. They are not needed to compile the solutions.
