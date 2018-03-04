we are going to be doing our individual work on our own branches. 

#### Step 1
First thing to do is pick a part of the project to work on. A good place to start is 
by picking a task from the projects issue tracker: https://github.com/githubuser476/cs133u-project/issues

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
