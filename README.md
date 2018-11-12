# ecs36c-hw4

### Setup git on gitbash
- [x] Download gitbash [link](https://git-scm.com/downloads)
- [x] Clone remote repository and put into subfolder "hw4git" (the clone command will create the subfolder)
      - Laura@DESKTOP-0CDD3JF MINGW64 ~/Code/ecs36c
      - $ git clone https://github.com/loelsner/ecs36c-hw4.git hw4git/
### Branches
1. git pull
      - sync with master
2. git checkout -b feature/\<feature-name\>
      - let's name each branch feature/<feature-name>, yah?
3. do work
4. git status
      - check which files are modified, un/tracked, un/staged
      - if needed, also do: git add <file> <file>
5. git commit -a -m "\<commit message\>"
      - -a will add all unstaged (but tracked) files to the commit
      - -m specifies that the following is a commit message
