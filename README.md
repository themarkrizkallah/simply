# simply
 Linear algebra modules that manipulate vectors and matrices.

## Getting Started

The following instructions will get you a copy of simply up and running on your local machine for development and testing purposes.

### Prerequisites

You must have [GCC](https://gcc.gnu.org/) installed on your local machine.

### Installing

Clone the repository in a directory of your choice:

```
$ git clone https://github.com/themarkrizkallah/simply.git
```

Once that is done, go into your directory and run:

```
$ mkdir bin
$ make
```

*simply* is now compiled and ready to run.

If for some reason you wish to clear the object files and executable, run:

```
$ make clean
```

## Running simply

In order to run *simply*, either `cd` into the bin directory and run:

```
$ ./simply
```

Or run the following command from the project directory:

```
$ ./bin/simply
```

### Options

Once the linear programming modules are complete, there will be more options; however, as of now, the only supported flag is `-linalg`.

Example on how to use:

```
$ ./simply -linalg
```

This will run the linear algebra module.

**Note:** You do not have to use the flag in order to run the linear algebra module.

## How to use

#### The Linear Algebra Module
Once you are in the linear algebra module, there are several commands you can run. The following is a comprehensive list:

- `help` 
   - This prints out a list of all the commands in the shell
- `make (vector|matrix)` 
   - Typing make followed by either `vector` or `matrix` will allow you to create either a *vector* or a *matrix*
   - Once you enter the type of object you want to create, you will be prompted to enter a name, and its appropriate dimensions
   - Then you have to enter the elements of the vector or matrix
        - If you're creating a vector, you will just enter the values 1 by 1 seperated by whitespace
        - If you're creating a matrix, you will be entering elements row by row
        - For example, if you want to create a 3x3 matrix you will enter the values as:
            ```
            1 2 3
            4 5 6
            7 8 9
            ```
        - Alternatively, you could also enter the values as:
            ```
            1 2 3 4 5 6 7 8 9
            ```
            and that would create the exact same 3x3 matrix.
- `transpose $name`
    - Typing `transpose` followed by the object name will transposed said object
    -  Similar logic follows for the rest of the commands
- `print $name` 
    - Prints the object
- `add $name1 $name2`
    - Adds the two named objects
    - Can only add vectors together and matrices together
- `subtract $name1 $name2`
    - Subtracts the two named objects
    - Can only add vectors together and matrices together
- `multiply $name1 $name2`
    - Supports vector-vector multiplication, matrix-matrix multiplication, and matrix-vector multiplication
        - In the case of matrix-vector multiplication, the name of the matrix must come before the name of the vector
- `negate $name`
    - Negates the object


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
