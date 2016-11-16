# Summer-2015-Pivot-Algorithm
Implementation of the Pivot Algorithm on small length 2D walks

Current State: Needs Debugging

Self Avoiding Polygons have been studied by people for over 50 years now.
My attempt was to create simulations of 12 and 14 edged Self Avoiding polygon and
write a code that randomly generates various polygons(uniquely) using the pivot algorithm.

I started this in Summer 2015, and it seemed to be working fine, before I wanted to do more
complicated stuff and messed it all up.
The 115 times file should tell you what I had produced before I messed it up.



FOR POTENTIAL RECRUITERS:

Because of my much busier schedule, I cannot find the time to fix this code. I worked on this project after having taken only one computer science course in university, when I focussed on resuts than readability of the code. I admit that this code is one of the worst managed projects that I have done as a beginner, which is why I have debated deleting the project from my Git account. However, I do want to keep this repository on here, because it shows me how much I have improved and how much I have grown from my frist year (which was only two years ago). 

If given a chance and the time to do this project over, this is how I would approach it:

1. Use Version Control
During my first year, I didn't know about version control, which I wish I did because it could have been significantly useful to me in this project. I first succeeded in computationally generating all 124 12-edged self-avoiding polygons. Although I saved different variations of the file, going back to them and finding the one I want is hard. I also might have altered the successful 12edged algorithm file to make it more robust with 14 edges as well, and messed it up. 


2. Use better nomenclature
Over the past few months of being a CS student, I have realized that naming variables and functions is as important as commenting, if not more. I admit that this project's variables are not very informative and to be honest, if I look at someone's code which looks like this, I would be pulling my hair out. Variables names should be informative. Function names should accurately tell what the function is about.

3. Use better comments
In this project, I have mostly used comments as separators, which is nice, but when I went back to see what the code is about, they were not very helpful. I wish I had a detailed header with comments that follows a specific format, such as the one below:

  // function name
  // Brief explanation of what it does.
  // Precondition:\r
  // Returns:\n
  // Postcondition:\n


4. Tests
I wish I had created unit tests for for each of the major functions do. Directly aiming for getting the entire system to work is a bad idea. There should be unit tests as well as integration tests.


These points are definitely something which I now consider to be important. Although Steve McConnell, the author of Code Complete 2, beleives that the most important part of a software construction is coding and deubgging, which I completely agree with, I think that the quality of a code is as important as the code itself. It is always highly likely that one has to go back to code to change it, and not knowing what is going on and the time invested in figuring that out could potentially be the same as redoing it.

Now that I have had quite a bit of experience (from failing and improving), I have learned to pay attention to how I am articulating my ideas through my code.
