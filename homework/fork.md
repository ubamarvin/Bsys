1. Run./fork.py-s 10 and see which actions are taken. Canyou predict what the process tree looks like at each step? Use the-c f lag to check your answers. Try some different random seeds (-s) or add more actions (-a) to get the hang of it.




2. Onecontrolthesimulator gives youis thefork percentage,controlled by the-f flag. The higher it is, the more likely the next action is a fork; the lower it is, the more likely the action is an exit. Run the simulator with a large number of actions (e.g.,-a 100) andvarythefork percentagefrom0.1to0.9. Whatdoyou think the resulting final process trees will look like as the percentage changes? Check your answer with-c.

>>Higher fork percentages result in more edges
>>50 percent would endeup with only the root statistically, but it doesnt?


3. Now, switch the output by using the-t flag (e.g., run ./fork.py-t). Given a set of process trees, can you tell which actions were taken?
>> yes



4. One interesting thing to note is what happens when a child exits; what happens to its children in the process tree? To study this, let’s create a specificexample: ./fork.py-A a+b,b+c,c+d,c+e,c-. This example has process ’a’ create ’b’, which in turn creates ’c’, which then creates ’d’ and ’e’. However, then, ’c’ exits. What do you think the process tree should like after the exit? What if you use the-R flag? Learn more about what happens to orphaned processes on your own to add more context.

>>I assume grandparent adopts grandchildren. b adopts d and e. Ok that doesnt happen. a adopts the children. So if a child with children dies, all its children and grandchildren will become direct children of root.


5. One last flag to explore is the-F flag, which skips intermediate steps and only asks to fill in the final process tree. Run ./fork.py-F and see if you can write down the final tree by looking at the series of actions generated. Use different random seeds to try this a few times. 

6. Finally, use both-t and-F together. This shows the final process tree, but then asks you to fill in the actions that took place. By looking at the tree, can you determine the exact actions that took place? In which cases can you tell? In which can’t you tell? Try some different random seeds to delve into this question.

>> if a tree has height 2 there is no way telling if a forked b,c,d,.. or if those where once grandchildren which got adopted. So when a child jumps a letter, it could be that it once was a grandchild whose parent exited, like in the case of f
>> If a tree doesnt miss any letters you can tell how they spawned

 Final Process Tree:
                               a
                               ├── b
                               │   └── g
                               ├── d
                               │   └── h
                               └── f
                                   └── i
                                   Possible actions.
                                   a+b, a+c, c exits(unclear when),
                                   a+d, a+e, (e exits), a+f, b+g, d+h,
                                   f+i

                                   Action: a forks b
                                   Action: a forks c
                                   Action: c EXITS
                                   Action: a forks d
                                   Action: a forks e
                                   Action: e forks f
                                   Action: e EXITS
                                   Action: b forks g
                                   Action: d forks h
                                   Action: f forks i

  Final Process Tree:
                               a
                               ├── d
                               │   └── e
                               ├── f
                               │   └── g
                               └── h
                                   └── i
                                    Possible actions.
                                    a+b,b+c,c+d
                                    b exits, c exits
                                    Or
                                    a+b, a+c, a+d
                                    d+e
                                    b exits, c exits/
                                    Or
                                    a+b, b+c
                                    a+d......


                                    d+e

                                    a+f, f+g

                                    a+h, h+i

