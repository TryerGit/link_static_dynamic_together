Here, I am going to create a single solution that attempts to create a static library and dynamic library and consume them in a client project. So, there will be 3 different projects in the same solution file.

First, create library by using walkthrough available here: https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-170

Key points. Choose windows desktop wizard. Choose OverAll for Solution name and StaticLibrary for project name. Choose static library and empty project.

After adding .cpp and .h file and building, there seem to be two build folders. One under OverAll and one under StaticLibrary. The one under overall has the StaticLibrary.lib file.

Now, create the .dll project. Use Windows desktop wizard. Name project DLL. Choose add to solution instead of creating new solution. The location of the project should be under /OverAll. Choose empty project and export symbols.

Ensure in DLL header file, you have PROJECTNAME_ other defines. Build it. As before, this adds to Debug folder in OverAll/ and also creates a new Debug folder in Overall/DLL/

So, now, the Overall/Debug folder should have DLL.dll, DLL.exp, DLL.lib, DLL.pdb, StaticLibrary.idb, StaticLibrary.lib, StaticLibrary.pdb (Note, DLL.dll is already here.)

Now, to create the client app.

Add a new project named client add to the same solution.

Then, provide additional include libraries.

Include DLL.lib and StaticLibrary.lib in the additional dependency.

Seems to run perfectly fine!!!

When all three projects are open, initially, you may get a bad error when the order in which the projects are built is off. But once it is built, next time, you should be able to step through the client code just fine.