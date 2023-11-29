# Simple Shell

This project involves building a simple shell program that mimics basic functionalities of the Unix shell.

## Table of Contents

- [Introduction](#introduction)
- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Compilation](#compilation)
- [Testing](#testing)
- [Contributing](#contributing)
- [Authors](#authors)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Introduction

The Simple Shell project is designed to create a minimalistic shell program resembling some behaviors of the Unix shell. It is developed with the aim of understanding core concepts related to shell operation and process execution in Unix-based systems.

## Learning Objectives

By working on this project, participants are expected to comprehend the following concepts without external assistance:

### Origins of Unix and Key Contributors

Understanding the historical context of Unix is crucial. Participants will delve into the origins of Unix, exploring the contributions of visionaries like Dennis Ritchie, Ken Thompson, Brian Kernighan, and other lesser-known but equally influential figures. This includes recognizing the collaborative efforts that led to the birth of Unix and its early iterations, understanding the pivotal role played by Bell Labs, and how Unix's development paved the way for modern operating systems.

### Development History: Unix Shell, B Programming Language, and C

Delving into Unix's developmental history offers profound insights into the evolution of programming languages and shell architectures. Participants will explore the initial Unix shell and its evolution, tracing the lineage from the Thompson shell to the Bourne shell. Understanding the significance of the B programming language as a precursor to C is pivotal. This includes grasping how the transition from B to C significantly enhanced the capabilities of Unix, making it more accessible and portable across different hardware platforms.

### Understanding Ken Thompson's Role in Unix's Development

Ken Thompson's pivotal role in Unix's creation warrants extensive exploration. Participants will gain a nuanced understanding of Thompson's contributions beyond the creation of the first Unix shell. This includes studying his work on the development of the filesystem, utilities, and his impact on the overall architecture of Unix. Understanding Thompson's philosophy and innovative approaches to solving complex problems in operating systems will be a cornerstone of this exploration.

### Basics of Shell Operation and Process Management

A fundamental grasp of shell operations, process IDs (pid), and parent process IDs (ppid) is vital. Participants will study in detail how shells manage processes, handle input/output redirection, implement piping, and manage process hierarchies. This involves understanding the underlying mechanisms of process creation, forking, and execution, as well as process termination and signal handling within the shell.

### Environment Manipulation and System Calls

Understanding environment manipulation within a process, including managing environment variables, is key. Participants will distinguish between functions and system calls, comprehending when and how to utilize system calls effectively for process execution and environment manipulation. This involves studying the role of the kernel in interacting with system calls, managing file descriptors, and handling errors effectively. Furthermore, participants will explore how environment variables influence program execution and how the shell interacts with the system environment.

## Requirements

To meet project standards and ensure successful completion, adhere to the following requirements:

- Utilize editors such as vi, vim, or emacs for code editing
- Compile code on Ubuntu 20.04 LTS using `gcc` with specific options (`-Wall -Werror -Wextra -pedantic -std=gnu89`)
- Include a `README.md` file at the project's root
- Adhere to the Betty style for code formatting to maintain consistency and readability
- Ensure the shell does not have any memory leaks
- Limit functions to a maximum of 5 per file to encourage modularity and readability
- Employ header file inclusion guards to prevent multiple inclusions of the same file
- Use system calls only when necessary, understanding the impact and efficiency of system calls
- Create an `AUTHORS` file listing all contributors to acknowledge the project's collaborative effort
- Maintain consistency in output and error messages with `/bin/sh` for compatibility

## Installation

To set up the Simple Shell, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/simple_shell.git
    cd simple_shell
    ```

2. Compile the shell:

    ```bash
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
    ```

## Usage

Once the Simple Shell is compiled, you can use it as follows:

1. Run the shell interactively:

    ```bash
    ./hsh
    ```

2. Execute commands:

    ```bash
    $ /bin/ls
    hsh main.c shell.c
    $ exit
    ```

## Compilation

To compile the shell after making changes, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing

The shell should function in both interactive and non-interactive modes. For example:

### Interactive mode:

```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
```

### Non-interactive mode:

```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
```

## Contributing

Contributions to the Simple Shell project are welcome! Please follow the guidelines in the CONTRIBUTING.md file to contribute effectively.


## Authors

The individuals contributing to this project are listed in the AUTHORS file to recognize their valuable input and collaboration.


## License

This project is licensed under the [License Name]. Refer to the LICENSE file for detailed information about the license terms and conditions.


## Acknowledgements

We express our gratitude to the open-source community for their valuable resources and support that contributed to the development of this Simple Shell project.
