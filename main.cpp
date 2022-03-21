#include "Sample.h"
#include <string>

/**
 * Hello!
 *
 * I hope that you had a nice Spring break. I know we typically
 * end up doing homework the *entire* time, which sucks, but at
 * least you may have gotten to catch up on sleep.
 *
 * Anyways, I've designed this collection of questions/exercises
 * to serve as a refresher to many (but not all) of the topics
 * that Professor Lewis will examine.
 *
 * That being said, his exam/quiz questions are typically
 * much more difficult than these -- my goal is to reintroduce
 * you to many of these topics, not necessarily to give you a
 * complete breakdown of everything.
 *
 * INSTRUCTIONS: I recommend reading through the header file
 * first, just to familiarize yourself with the class and
 * functions. There are a couple of questions in the header
 * files, but most are here. Read through the questions
 * and see how well you can answer them by describing your
 * answers to your group members.
 *
 * - Callisto
 */

int main()
{

    /**
     * QUESTIONS:
     * 1. Where in memory do the 'Sample' objects reside?
     * 2. Where in memory are their member variables?
     * 3. What are the values of their member variables?
     */
    Sample s1;
    Sample *s2 = new Sample();

    /**
     * QUESTIONS:
     * 1. How are these functions different from each other?
     * 2. How does 'sample_string' get changed by them?
     */
    std::string sample_string = "string";
    s1.pass_by_val(sample_string);
    s1.pass_by_ref(sample_string);
    std::cout << "sample_string: " << sample_string << std::endl;

    /**
     * QUESTIONS:
     * 1. What constructors/functions are called on each line?
     * 2. Do we need to implement our own copy constructor for
     *    the Sample class, or can we use the one provided by
     *    the compiler? Why or why not?
     */
    Sample c1(0, 1); // a
    Sample c2; c2 = c1;                        // b
    Sample c3(c1);                             // c
    Sample c4 = c2;                            // d
    Sample c5 = c2.constructors_in_action(c4); // e

    /**
     * QUESTIONS:
     * 1. What mechanism allows for these '<<' operators
     *    to be chained?
     * 2. Why do we define the operator as a 'friend'?
     */
    std::cout << c1 << c2 << c3 << c4 << c5 << std::endl;

    /**
     * QUESTIONS:
     * 1. What are the big-O runtimes of the following functions?
     * 2. Can you sort them from slowest to fastest growing?
     * 3. Can you describe how each of the sorts operates?
     * 4. Explain how the following works:
     *      a. the partition procedure in quicksort
     *      b. the merge function in merge sort
     */
    s1.big_O_1(100);
    s1.big_O_2(15);
    s1.big_O_3(31);
    s1.big_O_4(8);
    s1.big_O_5(10);
    s1.binary_search(64);
    s1.merge_sort(10000000);
    s1.quick_sort(8);
    s1.bubble_sort(14);

    /**
     * QUESTIONS:
     * 1. Identify the base case(s) in the following functions.
     *    Why do we need a base case?
     * 2. Are these functions direct or indirect recursion?
     * 3. Are these functions tail-recursive?
     * 4. Why is tail recursion beneficial?
     * 5. What could be done to improve these functions?
     * 6. What is memoization?
     */
    s1.recursive_factorial(10);
    s1.recursive_fibonnaci(5);
}
