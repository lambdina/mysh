# mysh

## Table of content
* [Introduction](https://www.github.com/NaadiQmmr/mysh#Introduction)
* [Features](https://www.github.com/NaadiQmmr/mysh#Features)
* [How to run it](https://www.github.com/NaadiQmmr/mysh#How%20to%20run%20it)
* [Going further](https://www.github.com/NaadiQmmr/mysh#Going%20further)
* [Contributors](https://www.github.com/NaadiQmmr/mysh#Contributors)

## Introduction
The mysh project is a school project we had to do in our first year. Short description, it aims at acting like tcsh shell.

## Features
* Basic command execution
* Redirections `>` and pipes `|`
* Some builtins `echo ; which ; where ; env ; exit ; setenv ; unsetenv ; source ; cd`
* Also supports the `alias` builtin
* Supports parenthesis syntax and quotes

## How to run it
```shell
$ make ; ./mysh
> 
```
Then the infinite loop begins, prompting you a command to execute !

## Going further
It was our first year and we weren't as familiar as we are now with clean code convention like you have to write one header per `.c`.
Also we were using a lot of `malloc()` where a simple static allocation would have been enough.
I choose to keep it in my github anyway because it was a great project though.

## Contributors
* [Adina C.](https://www.github.com/NaadiQmmr)
* [Bogdan G.](https://www.github.com/bogdzn)
* Guillaume D.
* Iaroslav S.
* [Yuhui x.](https://github.com/claraxuxu)
