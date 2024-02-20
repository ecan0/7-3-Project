# Corner Grocer Item-Tracker

## Summary

The Corner Grocery item-tracker is a C++ program to count produce items (apples, broccoli, etc.) purchased from a grocery store. The program will read a list from a grocery store's main purchases for the day in the form of a text file. The user will then have menu options to search for items in the list, print the number of times each produce item occurs in the list both numerically and in histogram format. The counts of each item in the list will also be backed up to `frequency.dat` for data storage.

## What was done well?

I believe my code has strong modularity in the form of separating class functions between the main grocery list, I/O manager, and main method. By encapsulating each programatic element into separate classes each with their own functions, constructors, and fields, we are able to reduce coupling while maintaining tight cohesion once they are all initialized in the main method.

## What could be enhanced?

There is always room to improve in adherence of OOP principles if it applies to the project. In my code, applying more `private` access modifiers to backing fields would enhance data-hiding accross the multiple class instances and prevent unnecessary or erroneous modification of data between classes. I think my code manages this well already by separating class duties into different instances altogether, but some experimentation with changing access levels from private/protected/public wouldn't hurt.

## Challenges, Overcomings, and Future Tools

The most challenging code to write was, in my opinion, the enumerations in the `GroceryCart` class under the `generateItemCount()`, `printItemFrequency()`, and `printItemHistogram()`functions. I overcame this by seeking new implementations of code I've never wrote in C++ before, but have implemented in different languages like C#. Using enumerations to search my lists with `find()` was crucial to implementing efficient searches of sorted data. Resources like StackOverflow or C++ documentation are a classic example of what makes do-it-yourself programming and research such a satisfying process when you have a wide array of resoruces and help to choose from.

## Transferrable Project Skills

Directly transferrable skills from this project to another are the use of source-control tools like Git and online collaboration tools such as GitHub. Being able to write code and have it tracked, documented, and published instantenously as well as enable collaboration features for other programmers to review,edit,and source your code is infinitely valuable to any programmer on any project in today's age.

## Maintainability, Readability, Adaptability

The program is maintainable, readable, and adaptable by having strong documentation and modularity. Developers can read this code based on the ample amount of in-line comments and the document provided in the 7-3 project upload and understand the logical data flow and use of variables,functions,and class implementations with relative ease. Since the class implementations adhere to object-oriented design, developers can add their own classes or modify existing ones in order to update the code to implement new technologies or write their own code to perform functions as they see fit.