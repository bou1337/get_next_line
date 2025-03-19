# get_next_line

get_next_line is a function that reads a line from a file descriptor, developed as part of the 42 curriculum. It efficiently retrieves lines of any length, handling file descriptors and standard input.

## Features
- Reads a single line from a file descriptor at a time
- Works with any file descriptor, including standard input
- Handles multiple file descriptors simultaneously
- Efficient memory usage with a configurable buffer size

## Installation
### Clone the repository
```sh
git clone https://github.com/bou133/get_next_line.git
cd get_next_line
```

### Build the library
```sh
make
```
This will generate `get_next_line.a`, which can be linked to your projects.

## Usage
Include `get_next_line.h` in your source file:
```c
#include "get_next_line.h"
```
Compile your program with `get_next_line.a`:
```sh
gcc myprogram.c -L. -lgnl -o myprogram
```

Example usage:
```c
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)))
{
    printf("%s\n", line);
    free(line);
}
close(fd);
```

## Configuration
The buffer size for reading can be adjusted by defining `BUFFER_SIZE` during compilation:
```sh
gcc -D BUFFER_SIZE=42 myprogram.c get_next_line.a -o myprogram
```

## Resources
- [42's get_next_line Subject](https://cdn.intra.42.fr/pdf/pdf/28535/en.subject.pdf) - Official project specifications.
- [get_next_line Repository](https://github.com/bou1337/get_next_line) - Repository with implementation and documentation.

## License
This project is for educational purposes and follows 42's academic policies.

---

Feel free to contribute or reach out if you have any questions!
