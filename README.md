### Distributed Operator Splitting Engine (DOSE)
Distributed Operator Splitting Engine (DOSE) is a shared library provide a mathematical
optimization solver to solve Linear and Logistic Regression problems with static cardinality
constraint. DOSE is the core numerical Engine used in SysCopt project. 

Compilation:

```commandline
cd /path/to/project
mkdir build
cmake -S . -B build
cmake --build build
```

Now the library file, ``libDOSE.so`` file is generated in the build folder. To use the 
library functionality, the ``DistEngine.h`` file should be used.

assuming ``main.cpp`` is going to be the application executable file, the following
command compiles and create MPI executable file, ``run``.

```commandline
 mpic++ main.cpp -O2 -march=native  -lDOSE -L./build -o run
```
in order to run the executable file, first ``libDOSE.so`` must be appended to the 
``LD_LIBRARY_PATH`` env as follows,
```commandline
 export LD_LIBRARY_PATH="{$LD_LIBRARY_PATH}":"path/to/build"

```