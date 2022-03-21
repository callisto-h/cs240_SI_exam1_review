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
     * ANSWERS:
     * 1. s1 is on the stack. The pointer, s2, is also on the
     *    stack. s2 points to data on the heap.
     * 2. The variables of an object are in the same memory
     *    location as that object. In the case of s1, its
     *    'pointer_to_variable' is on the stack but may point
     *    to data on the heap.
     * 3. In the defualt constructor, we set 'pointer_to_variable'
     *    equal to 'nullptr'. However, 'variable' is uninitialzed.
     *    Local variables and member variables will be RANDOM data.
     *    Global variables are initialized to 0.
     */
    Sample s1;
    Sample *s2 = new Sample();

    /**
     * QUESTIONS:
     * 1. How are these functions different from each other?
     * 2. How does 'sample_string' get changed by them?
     * ANSWERS:
     * 1. The first makes a copy of 'sample_string' for the
     *    function to operate on, where the second directly
     *    operates on the 'sample_string' that exists in this
     *    function.
     * 2. The first function does not change sample_string.
     *    The second function sets 'sample_string' to "something".
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
     * ANSWERS:
     * 1. In order:
     *    a. Value constructor
     *    b. Default constructor; assignment operator
     *    c. Copy constructor
     *    d. assignment operator
     *    e. Multiple calls:
     *          1. Copy constructor when c4 is passed by value
     *             to the function to create 's'
     *          2. Copy constructor inside the function when
     *             we create 'Sample another_s' from 's'
     *          3. Copy constructor when we return a Sample
     *             by value from the function
     *          4. Copy constructor when we create c5 from
     *             the Sample returned by the function
     * 2. We need to implement our own copy constructor because
     *    the Sample class uses dyanmic/heap memory by assigning
     *    'pointer_to_variable' with 'new'. Therefore we need a
     *    "deep copy" constructor. If we did not use any
     *    dynamic memory allocation, we could use the compiler
     *    generated "shallow copy" constructor.
     *
     */
    Sample c1(0, 1); // a
    Sample c2;
    c2 = c1;                                   // b
    Sample c3(c1);                             // c
    Sample c4 = c2;                            // d
    Sample c5 = c2.constructors_in_action(c4); // e

    /**
     * QUESTIONS:
     * 1. What mechanism allows for these '<<' operators
     *    to be chained?
     * 2. Why do we define the operator as a 'friend'?
     * ANSWERS:
     * 1. Since the '<<' operator returns an ostream, and each
     *    call to '<<' requires an ostream and a Sample, we can
     *    chain the calls together.
     * 2. 'Friend' functions can access private member variables
     *    but are not member functions. Since the '<<' operator
     *    is *really* being called on the 'cout' ostream, it can't
     *    belong to the Sample class.
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
     * ANSWERS:
     * Note: The numbers passed into these functions have NOTHING
     *       to do with their time complexity. big-O notation is
     *       measuring the rate at which the operation slows as
     *       the input size increases, not the input size itself
     * 1. Runtimes:
     *    Check out https://www.bigocheatsheet.com/
     *    and https://visualgo.net/en/sorting
     *      a.       big_O_1: O(N^2)
     *      b.       big_O_2: O(N)
     *      c.       big_O_3: O(1)
     *      d.       big_O_4: O(logN)
     *      e.       big_O_5: O(N)    [327N is just really N]
     *      f. binary_search: O(logN)
     *      g.    merge_sort: O(NlogN)
     *      h.    quick_sort: O(N^2)
     *      i.   bubble_sort: O(N^2)
     * 2. From slowest growing to fastest:
     *      a. O(1)
     *      b. O(logN)
     *      c. O(N)
     *      d. O(NlogN)
     *      e. O(N^2)
     *      f. O(N!)
     * 3. See the links above for comprehensive visualizations
     * 4. Simple explanations:
     *      a. Partition selects an element from the array and
     *         moves elements smaller than it to the left, and
     *         elements larger than it to the right. Then it
     *         splits the left and right into seperate arrays.
     *      b. Merge considers two small sorted arrays and
     *         combines them into a larger sorted array.
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
     * ANSWERS:
     * 1. Base cases:
     *      a. factorial: 'if arg == 0'
     *      b. fibonnaci: 'if(nth_element == 0 or nth_element == 1)'
     *      We need a base case to effectively "end" the recursive
     *      call stack. It is typically the smallest problem that
     *      the function/procedure could encounter; the trivial case.
     * 2. They are direct recursion, as they call themselves. If they
     *    called a caller function, it would be indirect recursion.
     * 3. They are not tail recursive. Tail recursion occurs when the last
     *    line in a function is just a recursive call.
     * 4. TAILRECURSION: When a function is called, it maintains local
     *    variables/an activation record. If that function calls another function,
     *    those local variables stick around until the other function finishes.
     *    If we passed those variables TO the next function, we wouldn't need
     *    to maintain every local variable in the call stack. Therefore, tail
     *    recursion frees up space by not maintaining every activation record.
     * 5. Both functions could be made tail recursive. The factorial function
     *    could be made to utilize memoization.
     * 6. MEMOIZATION: Store a record of results for given inputs so that
     *    the function/procedure doesn't need to calculate them again.
     */
    s1.recursive_factorial(10);
    s1.recursive_fibonnaci(5);
}
