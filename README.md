# philosopher

# Dining philosophers problem
In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm
design to illustrate synchronization issues and techniques for resolving them.

# Problems
The problem was designed to illustrate the challenges of avoiding deadlock, a system state in which no progress is possible.
To see that a proper solution to this problem is not obvious,
consider a proposal in which each philosopher is instructed to behave as follows:
- think until the left fork is available; when it is, pick it up;
- think until the right fork is available; when it is, pick it up;
- when both forks are held, eat for a fixed amount of time;
- then, put the right fork down;
- then, put the left fork down;
- sleep;
- think;
- repeat from the beginning.
