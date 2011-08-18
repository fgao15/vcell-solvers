/**
 * @file   TestRunner.cs
 * @brief  Test Runner for C# test files.
 * @author Frank Bergmann (fbergman@u.washington.edu)
 *
 * $Id: TestRunner.cs 13067 2011-02-28 00:45:47Z fbergmann $
 * $URL: http://sbml.svn.sourceforge.net/svnroot/sbml/trunk/libsbml/src/bindings/csharp/TestRunner.cs $
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2011 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *--------------------------------------------------------------------------->*/

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Reflection;

namespace LibSBMLCSTestRunner
{
    /// <summary>
    /// <para>This test Programm takes a directory of C# files, compiles them and 
    /// then runs all test methods found. </para>
    /// 
    /// <para>- currently no support for test data</para>
    /// 
    /// <para>To use it simply invoke it with three arguments, for example: 
    /// 
    /// <c>LibSBMLCSTestRunner \\libsbml\\src\\sbml\\test \\libsbml\\src\\sbml\\test-data libsbmlCS.dll</c>
    /// </para>
    /// 
    /// author: Frank Bergmann (fbergman@u.washington.edu)
    /// 
    /// </summary>
    class TestRunner
    {
        private static void PrintUsageAndExit()
        {
            Console.WriteLine("Need three arguments:");
            Console.WriteLine("\t- Directory containing generated test files");
            Console.WriteLine("\t- Directory containing test-data");
            Console.WriteLine("\t- Full path to libsbml C# bindings to be used");
            Environment.Exit(-1);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("LibSBML C# Testrunner");
            Console.WriteLine("=====================");

            if (args.Length == 1)
            {
                RunTestsInNamespace(args);
            }
            else
            {
                CompileAndRunTests(args);
            }

        }

        /// <summary>
        /// This runs all tests in the 'LibSBMLCSTest' namespace, which 
        /// presumably are included in this assembly. 
        /// </summary>
        /// <param name="args">command line arguments</param>
        private static void RunTestsInNamespace(string[] args)
        {

            string sData = args[0];

            if (!Directory.Exists(sData))
            {
                Console.WriteLine("Data Directory does not exist" + Environment.NewLine);
                Environment.Exit(-1);
            }


            // all seems well so let us run through the tests:
            Console.WriteLine("Running the tests with: ");
            Console.WriteLine("\tData Directory:   " + sData);
            Console.WriteLine();

            RunTestsInAssembly(Assembly.GetExecutingAssembly(), sData);

            Console.WriteLine(Environment.NewLine);
            Console.WriteLine(String.Format("Total Number of Tests {0}, failures {1}",
                                 nTestFunc, nFailureSum));
            if (nFailureSum == 0)
            {
                Console.WriteLine("\nAll tests passed." + Environment.NewLine);
                Environment.Exit(0);
            }

            PrintErrors();
            Environment.Exit(1); 

        }

        /// <summary>
        /// This runs the tests by recompiling all tests in the specified
        /// source directory.
        /// </summary>
        /// <param name="args">command line arguments</param>
        private static void CompileAndRunTests(string[] args)
        {
            if (args.Length != 3)
            {
                PrintUsageAndExit();
            }

            string sSource = args[0];
            string sData = args[1];
            string sLibrary = args[2];

            if (!Directory.Exists(sSource))
            {
                Console.WriteLine("Source Directory does not exist" + Environment.NewLine);
                PrintUsageAndExit();
            }

            if (!Directory.Exists(sData))
            {
                Console.WriteLine("Data Directory does not exist" + Environment.NewLine);
                PrintUsageAndExit();
            }

            if (!File.Exists(sLibrary))
            {
                Console.WriteLine("libsbml C# binding assembly does not exist." + Environment.NewLine);
                PrintUsageAndExit();
            }

            // all seems well so let us run through the tests:
            Console.WriteLine("Running the tests with: ");
            Console.WriteLine("\tSource Directory: " + sSource);
            Console.WriteLine("\tData Directory:   " + sData);
            Console.WriteLine("\tC# binding:       " + sLibrary);
            Console.WriteLine();

            RunTests(sLibrary, sSource, sData);
        }
        private static void RunTests(string sLibrary, string sSource, string sData)
        {
            // add reference library to the compiler so that it will be referenced
            // by the test files
            Compiler.addAssembly(sLibrary);

            int testFileNum = 0;

            nCompileErrors = 0;
            nSuccessSum    = 0;
            nFailureSum    = 0;
            nTestFunc      = 0;

            string[] testDirs = Directory.GetDirectories(sSource);            
            foreach (string testDir in testDirs )
            {
                // then compile and run all C# files
                string[] testFiles = Directory.GetFiles(testDir, "*.cs");            

                testFileNum += testFiles.Length;

                foreach (string testFile in testFiles)
                {
                    RunTestFile(testFile, testDir, sData);
                }
            }
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine(String.Format("Encountered {0} compile errors (invalid tests)", nCompileErrors));
            Console.WriteLine(String.Format("Total Number of Test files {0}, Tests {1}, failures {2}", 
                                             testFileNum, nTestFunc, nFailureSum));
            if (nFailureSum == 0 && nCompileErrors == 0 )
            {
              Console.WriteLine("\nAll tests passed.");
              Environment.Exit(0); 
            }
            
            PrintErrors();
            Environment.Exit(1); 
        }

        static int nCompileErrors;
        static int nSuccessSum;
        static int nFailureSum;
        static int nTestFunc;

        static List<ErrorDetails> _errors = new List<ErrorDetails>();

        /// <summary>
        /// Prints all errors that occured
        /// </summary>
        private static void PrintErrors()
        {
            if (_errors == null || _errors.Count == 0) return;

            foreach (ErrorDetails item in _errors)
            {
                Console.WriteLine();
                Console.WriteLine();

                Console.WriteLine(item.Message);
                Console.WriteLine(new string('=', 20));
                Console.WriteLine(item.Exception.Message);
                Console.WriteLine(item.Exception.StackTrace);
            }

            Console.WriteLine();
            Console.WriteLine();
        }

        private static void RunTestFile(string testFile, string testDir, string sData)
        {
#if DEBUG
            Console.WriteLine("Runing test file: '" + new FileInfo(testFile).Name + "' in " + testDir);
            Console.WriteLine("----------------------------------------------------------------");
#endif
            // read C# code
            StreamReader oReader = new StreamReader(testFile);
            string source = oReader.ReadToEnd(); oReader.Close();
            Assembly oTestClass = null;

            // compile the test file and create an assembly
            oTestClass = Compiler.GetAssembly(source);            

            if (oTestClass == null)
            {
                Console.WriteLine("Error compiling the test class (details on std::error) ");
                Console.Error.WriteLine(Compiler.getLastErrors());
                nCompileErrors++;
                Console.WriteLine();
                return;
            }

            // test compiled so now we can run the tests
            RunTestsInAssembly(oTestClass, sData);
#if DEBUG
            Console.WriteLine(); 
            Console.WriteLine();
#endif
        }

        private static void RunTestsInAssembly(Assembly oTestClass, string sData)
        {
            // get all classes, we know that all test-classes begin with Test
            Type[] types = oTestClass.GetExportedTypes();
            foreach (Type type in types)
            {
                if (type.Name.StartsWith("Test"))
                {
                    // we have a test class: 
                    RunTestsInType(oTestClass, type, sData);
                }
            }            
        }

        private static void RunTestsInType(Assembly oTestClass, Type type, string sData)
        {
            // counting successes and failures
            int nSuccess = 0;
            int nFailure = 0;

            try
            {
                // get all methods
                MemberInfo[] members = type.GetMembers();

                foreach (MemberInfo member in members)
                {
                    
                    // test methods begin with test_
                    if (member.Name.StartsWith("test_"))
                    {
                        ++nTestFunc;
                        // set up the class
                        object testClass = SetupTestClass(oTestClass, type);

                        // run the test
                        try
                        {
                            type.InvokeMember(member.Name, BindingFlags.InvokeMethod |
                                        BindingFlags.Default, null, testClass, null);
                        }
                        catch (TargetInvocationException ex)
                        {
                            Console.Write("E");
                            _errors.Add(new ErrorDetails(
                                "Error in '" + member.Name + "': ", 
                                ex.InnerException));
                            nFailure++;
                            continue;
                        }
                        catch (Exception ex)
                        {
                            Console.Write("E");
                            _errors.Add(new ErrorDetails(
                                "Error in '" + member.Name + "': ",
                                ex));
                            nFailure++;
                            continue;
                        }

                        // if we are still here the test was successful
#if DEBUG
                        Console.WriteLine("Calling '" + member.Name + "'");
#else
                        Console.Write(".");
#endif
                        nSuccess++;

                    }
                }
            }
            catch (Exception ex)
            {
                Console.Write("E");
                _errors.Add(new ErrorDetails(
                    "Error running tests for " + type.Name + ": ",
                    ex));
                return;
            }

#if DEBUG
            Console.WriteLine();
            Console.WriteLine(
                String.Format("Testing completed: Pass:{0}, Fail:{1} (Total:{2})",
                              nSuccess, nFailure, nSuccess+nFailure));
#else
            Console.Write(".");
#endif
            nSuccessSum += nSuccess;
            nFailureSum += nFailure;

        }

        private static object SetupTestClass(Assembly oTestClass, Type type)
        {

            object oClass = Activator.CreateInstance(type);
            try
            {
                type.InvokeMember("setUp",
                                  BindingFlags.InvokeMethod | BindingFlags.Default,
                                  null, oClass, null);
            }
            catch (Exception)
            {
              // 2010-07-22 <mhucka@caltech.edu> Some just don't have a
              // setup class.  It's confusing to see these errors.  

              // Console.WriteLine("Could not run setUp class ... ");
            }
            return oClass;
        }
    }

    class ErrorDetails
    {
        private Exception _Exception;
        public Exception Exception
        {
            get { return _Exception; }
            set { _Exception = value; }
        }

        private string _Message;
        public string Message
        {
            get { return _Message; }
            set
            {
                _Message = value;
            }
        }

        /// <summary>
        /// Initializes a new instance of the ErrorDetails class.
        /// </summary>
        /// <param name="message">Mesage to print</param>
        /// <param name="exception">exception object</param>
        public ErrorDetails(string message, Exception exception)
        {
            _Exception = exception;
            _Message = message;
        }
    }
}
