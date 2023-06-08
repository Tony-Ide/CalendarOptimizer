[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10950611&assignment_repo_type=AssignmentRepo)

# Schedule Optimizer
 
 > Authors: \<[SeungPyo Lee](https://github.com/qwemelon3619)\>,\<[Joshua Jeong](https://github.com/JoshuaJJeong)\>,\<[Tony Ide](https://github.com/Tony-Ide)\>,\<[Michael Zheng](https://github.com/ahupq)\>

## Project Description
Our project will be to create a schedule optimizer that allows users to plan and schedule events and tasks while also having the option to optimize a schedule automatically to most efficiently complete tasks.

The user will be able to input events and tasks, a list of dates and times that they are able to complete them, the duration of the event or task, and whether or not the task may be broken down into multiple sessions, and priority level. Then the optimizer will be able to take all the information inputted by the user in order to return a schedule for the user that completes the tasks as quickly as possible while simultaneously avoiding potentially blocked out times of day for necessary events such as meals.

A schedule optimizer can be a very helpful tool in order to plan, keep track, and save time completing tasks throughout the weeks. This can save immense amounts of time for any student, worker, or everyday user that has a number of different task/events and options for when to complete them. Instead of spending time working out a schedule for the day/week/month, the user can input all the information into the optimizer and get a schedule that meets all of their requirements so that they can spend their time more efficiently.

In order to implement this program, we will be taking advantage of these languages/tools/technologies:
  * C++
  * VSCode
  * Github

The input of our program will consist of:
  * Event name
  * Duration of event
  * Available Days/Dates
  * Available start times for the event (at least 1, up to 3)

The output of our program will give the user a schedule of all the events they inputted such that their are no overlapping tasks and that all the tasks will be completed as early as possible.

Some features that will be included into our program in addition to the main function are:
  * The ability to add or remove events/tasks and recalibrate the schedule.
  * The ability to edit existing events/tasks and recalibrate the schedule.
  * The ability to set recurring events/tasks that take place at the same time each day/week.
  * The ability to manually resolve any time conflicts that are unresolvable by the algorithm.
  * The ability to set blackout times (times the user does not want any events scheduled).
  * The ability to set a priority level on events/tasks (low, medium, high).
  * The ability to set an event/task as multi-session for tasks that do not have to completed in one sitting.

## User Interface Specification

### Navigation Diagram and Screen Layouts
> The Navigation Diagram and the Screen Layouts can be found [here](https://docs.google.com/document/d/1cz8a8vcMeWhP3Ak7lRTANpxjZ2O_7oP-SqNYGQ6tbC4/edit?usp=sharing).

![12323](https://github.com/cs100/final-project-hzhen066-tide001-slee809-jjeon050/assets/47466245/df577792-ba0b-40e5-8819-c9242d6f8f23)
## Class Diagram
 > The UML Class Diagram can be found [here](https://docs.google.com/document/d/1LUfIhlml08uEGgsR8kQS1oFNR3Uno8UR6IYEfOQ_8rE/edit).
 
 ![CS100_Project_UML-Page-1 drawio(1)](https://github.com/cs100/final-project-hzhen066-tide001-slee809-jjeon050/assets/47466245/d86307aa-a3b3-4450-804c-e6ce06ace88d)

**Scheduler**

The scheduler class consists of 3 private member variables: a list of todos, a list of organized todos, and a list of blackout times. It also comes with 4 member functions, add task which adds a new task to the list of todos, remove tasks which removes a specified task from the list, and edit task which replaces an existing task in the list with an edited version of the task. Finally the organize function will take the list of todos and organize them so that there are no time conflicts in order of priority.

**Date**

The Date class is indicating the date of the month and date. Class consists of 3 private member variables: integer of month and integer of date of the Todo. They have getters to return each value and constructor to set the value.

**Todo**

Todo class is indicating the one task in the scheduler. Todo show The Todo class comes with 5 private member variables: Date, name, priority, time and duration. Todo has a constructor of 5 values to set a value. Todo class stores the month and day of the Todo, a string name which stores the name of the task, priority which stores an integer of 1-3, time which stores an integer from 0 to 2349, and duration time which stores an integer that represents hours. Also, each variable has getters to return each value.

**MainMenu**

MainMenu class is a class for printing the screens to use a scheduler. MainMenu class has Scheduler to point to the schedule object. MainMenue has a constructor to set a scheduler variable. MainMenu class has a function to print TaskLists, schedule of week and schedule of one day. MainMenu class has a menu for add, edit and remove the todo to use the scheduler.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 


 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 