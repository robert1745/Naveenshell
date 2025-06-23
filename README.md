# NaveenShell - A Custom Unix Shell

NaveenShell is a minimal Unix-like shell built from scratch in C. It is designed to provide a deep, low-level understanding of how command-line shells work at the OS and system-call level — without relying heavily on standard libraries.

---

## ✅ Features Implemented (Stage 1)

- Custom shell prompt (`naveenshell> `)
- Read user input using `read()` (no `fgets` or `getline`)
- Parse input into command and arguments using `strtok`
- Execute external commands using `fork()` and `execvp()`
- Wait for command execution using `wait()`
- Exit the shell using `exit` command

---

## 🧠 Architecture & Concepts

NaveenShell relies on the following Unix principles:

1. **Process Creation**: Every command is run in a child process created by `fork()`.
2. **Process Replacement**: The child process replaces itself with a new program using `execvp()`.
3. **Parent Synchronization**: The parent (the shell) waits for the child to complete using `wait()`.
4. **Parsing**: Input is parsed using `strtok()` into an argument array `argv[]` that `execvp()` requires.

---

## 🛠 How to Build

```bash
1. Command : make
2. Type ./naveenshell 

Boom ! you are ready to go!!
```

## Commands you can use in first iteration
ls
pwd
echo hello
exit

