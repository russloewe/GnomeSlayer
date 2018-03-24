## Git

we are going to be doing our individual work on our own branches. 

#### Step 1
First thing to do is pick a part of the project to work on. A good place to start is 
by picking a task from the projects issue tracker: https://github.com/russloewe/GnomeSlayer/issues

#### Step 2
Second, go the the project's folder on the PCC server or you're local machine and update your master branch:

      git pull origin master
 
 #### Step 3
Third, before work starts, create a new branch and give it a fitting name, for example lets work on the AI module:

    git checkout -b AI

#### Step 4
Fourth, do your work. Make changes to the files, periodically, compile or run tests to make sure things are working

#### Step 5
Fifth, when you are at a point you want to save the code to the repo commit it by adding and commiting.
you can make multiple commits without pushing to github, so break up your commits into logical sections. For 
example say you added a new function (modified file1.c and file1.h) and added a test for it (test_file1.c), then you can 
group the commits like this:

    git add file1.c file1.h
    git commit -m "added function to file1.c"
    git add test_file1.c
    git commit -m "added test for file1"
    
make sure to write concise informative messages on the commits so wveryone can see what you did.

* you can repeat step 4 and 5 over and over as you work on your current task.
* you can use "git statues" to get a list of files that have been modfied to make sure you don't forget to commit anything.

#### Step 6
Sixth, when you finish the task you are working on, push the code to github:

    git push origin AI
    
#### Step 7    
Seven, go to github and make a pull request by cliking on the green pull request button, make sure to give a good description of what is different in the branch you are merging. 

more about pull requests:
https://help.github.com/articles/creating-a-pull-request/

#### Step 8
Eighth, after the pull request has been merged, you are done. make sure you pull the fresh code with 

    git checkout master
    git pull origin master

## Tests

#### Step 1
First open up the right test suit for the module you are working on. The test suits are named

      test_module.c
      
 For example, grpahics and input test suits are called
 
      test_graphics.c
      test_input.c
      
 respectivly.
 
 #### Step 2
 Second, add a test case to the test suit. Go to the buttom of the test file and add a new funciton. Give it a unique 
 name or just call it test<number>.c . All the test functions have the prototype:
      
       int test(void);
       
  #### Step 3
  Before writing the test, write a comment to tell other coders what the test function does:
  
      int test5(){
      /* this test checks the move() function by calling move() 
      * then checking that the item posistion has uopdated correctly
      */
  
  Then below the comment, write a print statement to tell inform the user what's going on when the test runner is running.
  To keep with the current output format, include the name function that is being tested and the source file that
  function is in. Don not put "\n" at the end of the first print statement.
     
     printf("Testing gameobject.c->move() ");
     
   #### Step 4
   Next, write the test. Most test s will require that you setup a few variables first, then call the function that 
   you want to test, then check the result:
   
      gamepiece * test_piece;
      test_piece = create_piece(<arguments>);  //set up 
      
      move(test_piece, <direction>);          //run function to test
      
  When checking the result, on a pass print "pass \n" to the terminal and return 1 for success. On failer print "fail \n" 
  and return -1 for failer.
  
      if( (test_piece->x == <correct value>) && (test_piece.y == <correct value>) ){
           printf("Pass \n");
           return 1;
       }else{
           printf("Fail \n");
           return -1;
       }
       
  This is the basic format. Remember to test edge and corner casses. You can also do something that you 
  know will make the function fail and check that the function fails in the way you expect it too.
  For example if the move() function fails because you gave it a game piece without a defined position, you 
  don't want it to cause the whole game to crash.
  
  #### Step 4
  Next, add a prototype for your function to the top of the source file with the other test prototypes. Then add the 
  function name to the array of functions that are called when the test is ran. Make sure you don't put it at the 
  very end of the list. so this:
  
      int (*test_suit[])() = {test1, test2, 
                            test3, test4, 
                             cleantest};  
  
  becomes this.
  
       int (*test_suit[])() = {test1, test2, 
                            test3, test4, 
                            test5, cleantest};  
                            
  The cleantest() function returns 0, which tells the test runner the tests are done. Without it the test runner
  will try to call some random memeory address and probably crash the program. Also if there is a function after
  cleantest(), it won't get called.
  
  *note, there are no () in the array of test functions above
                            
  #### Step 5
  Lastly, compile the test suit and run the new test:
  
      make test_graphics
      ./test_graphics
