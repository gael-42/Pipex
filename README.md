Pipex is a program replicating the pipe | shell command, and a 42 school project.
The goal of the project is to learn how to use forks and pipes to run two shell commands at the same time, 
redirecting the output of the first command to the input of the second command.

To run the program:
- use make
- execute ./pipex infile cmd1 cmd2 outfile

The output of the commands will be written to the outfile.
If the outfile does not exists the program will create it.

Commands with flags need to be written inside quotes, for example:
./pipex infile ls "wc -l" outfile 
