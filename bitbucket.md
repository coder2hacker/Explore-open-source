### Get rid of hacky workarounds and speed up your work with Bitbucket 

mproving developers’ quality of life, one update at a time.

PUBLISHED JUNE 10, 2019 IN
BITBUCKET
Maggie Roney
MAGGIE RONEY
Product Marketer

Meetings, context switching, and scope creep aren’t the only nuisances that can slow developers down; lack of visibility is often the root cause for numerous workarounds, slowdowns, and sometimes a complete loss of work. The new features we’ve introduced in Bitbucket 6.3 are focused on improving developers’ quality of life, eliminating those annoying workarounds and making work easier.

## Say goodbye to merge conflicts with Git LFS file locking

Due to the decentralized nature of Git, concurrent edits are commonplace, often leading to merge conflicts. And when you’re working with large binary files, such as audio, 3D models, videos, or graphics, these conflicts are impossible to resolve.

The introduction of Git LFS file locking surfaces this visibility by allowing individual team members to lock a file, preventing anyone else from pushing changes until the file is unlocked. With Git LFS file locking, developers no longer need to worry about wasting time identifying and resolving conflicts or implementing workarounds. Instead, they can easily identify that a file is being worked on and remain confident that each team member’s work is protected. Here’s how it works:

Each file can only be locked by one person at a time.
Locked files can only be unlocked by the person who locked them.
If your “push” contains locked files that you didn’t lock, it will be rejected.
If your “merge” contains locked files that you didn’t lock, it will be blocked.

Here are the commands you need to know:
To lock a Git LFS file
Change to the repository directory and run the command:

git lfs lock <filename>
To view all locked files
Change to the repository directory and run the command:

$ git lfs locks
To unlock a Git LFS file that you locked
Change to the repository directory and run the command:

git lfs unlock <filename>
In case of emergency, use the force unlock command
Change to the repository directory and run the command:

$ git lfs unlock images/foo.jpg --force
