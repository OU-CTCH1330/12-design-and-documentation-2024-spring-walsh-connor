[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/9_rsoaAs)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=14884784)
# 12 Design and documentation

## Assignment spec

(10 points) Please create technical documentation for LMS app with a class diagram approximately describing current code. You can use the present file for it. 

## Steps

- Please accept assignment `12` from *BlackBoard* as usual. Visit generated repo `OU-CTCH1330/12-design-documentation-yourGitHubId` on GitHub
<br /><span style='color: yellow'>Warning:</span> From acceptance page please don't go to Codespace straight, instead please first open repo with a link. Repo takes few second to initialize. Please check commits list (red highlight below). As new commits stop appearing for about 10 seconds or so, repo has been initialized. Exact number of commits will vary depending on nature of the assignment and version of classroom bot. If Codespace is opened prematurely some commits will be missed and this will create sync conflicts later between Codespace which was launched short of few commits and repo which got those commits after Codespace launch. 
- Please take a moment to go over classes in `data/`, `domain/` and `ui/` folders, pay attention to inheritance chain between them. 
- Please take a moment to go over [markdown](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax) syntax and [mermaid](https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/creating-diagrams) syntax. Follow further link to mermaid [docs](https://mermaid.js.org/intro/) and check `Class Diagram` section there. 
- For class diagrams feel free to use a different tool than mermaid. For instance [draw.io](https://www.diagrams.net/) is another choice, there are both web-based and desktop versions. You can draw there, export `jpg/png`, add image file to Git and insert that image in markdown documentation. 
- Please write down a design document of what would be your description of LMS app. Please use present `README.md` for it, you can append your writing to the bottom of present text instructions. You can include some wishful thinking of what app is expected to do, but also stay relevant to current code and class design. Please make sure your documentation has:
  - some use of markdown headers, give your document a some structure
  - at least one `inline` or 
  ``` 
  block 
  ``` 
  code
  - at least one [link](https://www.google.com/)
  - at least one table

  | table | description |
  | -- | -- | 
  | item1 | description 1| 
  - at least one numbered or bullet point list
  - at least a fragment of class diagram, with some inheritance chain in it
  - (2 point bonus) have image embedded in your documentation. 
- Remember, VS Code has `Preview` side-by-side mode, where you can see markdown rendered as you type.
- Stage, commit and sync your code. Please make sure your `README.md` is properly rendered by going to your GitHub repo. This assignment is graded manually, please upload your repo url to BlackBoard once done.


## General tips 

These tips are general, not specific to current assignment.

- If something goes wrong, please reach out early on, <span style='color: #8ae234'>**DO NOT STRUGGLE**</span>. 
- Use GitHub PR, BlackBoard Discussions, MS Teams, email, or any other means for reaching out for instructor's help. Also feel free to collaborate with fellow students, especially now that sprint project has fostered an excellent teamwork. 
- Please remember, instructor can't see your code until sync'd with GitHub repo. Further, if you want to let fellow students examine your code your repo needs to be [made public](https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/managing-repository-settings/setting-repository-visibility#changing-a-repositorys-visibility) (it's private at creation). Peer collaboration is highly encouraged, as long as it's genuine learning as opposed to mechanical copy/paste (see policies in the syllabus at BlackBoard > CTCH1330 > Docs).
- Syncing incremental progress milestones is recommended. Autograder doesn't care about repeated failures, only final success matters. 
- GitHub PR is an excellent place for code-centric discussions. This is also a standard in industry.
- Each assignment/repo expects a dedicated Codespace
- Please try not to spam Codespaces. If you've already created an instance for given repo, it's available at  [https://github.com/codespaces](https://github.com/codespaces) and they load faster (than a cold start of a fresh Codespace). Having multiple instances will fragment your work, as each Codespace has its individual local file system and one doesn't see changes in others, unless obviously synced through GitHub repo, to which they are all linked. Multiple instances may also create conflicts between different code edits, you will be unable to commit/sync (please reach out if that has happened).
- Consider cleaning up CodeSpaces for past assignments. They can be deleted (if running, stopped and deleted) by clicking `...` next to them. This is optional, as old Codespaces are discarded anyway after a period of inactivity.  

<br /><br /><br />

## Learning Management System Documentation (By Connor Walsh)

The learning management system (LMS) was built to enhance the day to day operations for instructors everywhere:
- Setting up semesters, courses, or classes
- Gives faculty the ability to add, delete or edit students within their classes
- This app is setup for desktop use and does not have a remote server, therefore it is not expected to be used by multiple people

| Function | Description |
| -------| ----------- |
| Add Student | Allows the instructor to add a new student to the Database |
| Update Student | This function allows the instructor to change any current information for a student already in the Database |
| Search by ID | Allows instructors to search for students based off of their Student ID's
| Search by Name | Instructors are also able to search for a student using their name |
| See class size | This function is running at all times and allows the instructor to see the curremt size of their classroom |
| Reset | Allows instructors to reset a class roster instead of having to manually delete and update contents |

You can learn more about Learning Management Systems and their benefits here: [link](https://wahoolearning.com/blog/learning-management-systems/benefits-customised-lms/) 


``` 
Class Diagram
```
```mermaid
---
title: Learning Management System
---
classDiagram
    Student --|> Students  
    Student --|> Course
    Course Repository --|> Course
    Repository --|> Course
    Instructor --|> Human
    Course Repository : +GetCourseById()
    Course Repository : +GetStudentsForCourse()
    Repository: +GetConnection()
    Repository: +CloseConnection()
    class Student{
       +void inactivate
       +void activate
       +bool IsActive
       +bool IsEligibleForEnrollment
       +int AddCredits
       +string QuickInformation
    }
    class Students{
        +int AddStudent
        +bool UpdateStudent
        +bool GetStudentById
        +vector SearchStudentByName
        +int GetStudentBodySize
    }
    class Instructor{
        +QuickInformation
    }
    class Human{
        +int id
        +String first_name()
        +String last_name()
    }
    class Course{
        +GetPage
        +CourseName
        +SemesterId
        +Credits
        +PageSize
    }
```

This is an example of a more sophisticated LMS Class Diagram: ![Example](https://www.researchgate.net/profile/Dennise-Adrianto/publication/320211937/figure/fig4/AS:545893431431169@1507162544813/Class-Diagram-of-Online-Learning-System.png)
