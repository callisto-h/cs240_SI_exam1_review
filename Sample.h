#include <string>
#include <iostream>

class Sample{
public:

    int variable;
    /**
     * QUESTIONS:
     * 1. This pointer will point to data on the heap.
     *    What is the rule of 3?
     * ANSWERS:
     * 1. A class which uses dynamic memory must:
     *      a. implement a copy constructor
     *      b. implement an assignment operator
     *      c. implement a destructor
     */
    int *pointer_to_variable;

    Sample()
    {
        std::cout << "DEFAULT CONSTRUCTOR CALLED" << std::endl;
        pointer_to_variable = nullptr;
    }

    Sample(int var1, int var2)
    {
        std::cout << "VALUE CONSTRUCTOR CALLED" << std::endl;
        variable = var1;
        pointer_to_variable = new int(var2);
    }

    Sample(Sample const &s)
    {
        std::cout << "COPY CONSTRUCTOR CALLED" << std::endl;
        variable = s.variable;
        if (s.pointer_to_variable == nullptr)
        {
            pointer_to_variable = nullptr;
            return;
        }
        pointer_to_variable = new int(*(s.pointer_to_variable));
    }

    Sample &operator=(Sample const &s)
    {
        std::cout << "ASSIGNMENT OPERATOR CALLED" << std::endl;
        if (this == &s)
        {
            return *this;
        }

        variable = s.variable;

        if (s.pointer_to_variable == nullptr)
        {
            pointer_to_variable = nullptr;
            return *this;
        }

        pointer_to_variable = new int(*(s.pointer_to_variable));
        return *this;
    }

    void pass_by_val(std::string arg)
    {
        arg = "something";
        std::cout << arg << std::endl;
    }

    void pass_by_ref(std::string &arg)
    {
        arg = "else";
        std::cout << arg << std::endl;
    }

    Sample constructors_in_action(Sample s)
    {
        Sample another_s = s;
        return another_s;
    }

    int big_O_1(int arg)
    {
        int count = 0;
        for (int i = 0; i < arg; ++i)
        {
            for (int j = 0; j < arg; ++j)
            {
                count++;
            }
        }
        return count;
    }

    int big_O_2(int arg)
    {
        int sum = 0;
        char arr[arg]; // random data
        for (char &c : arr)
        {
            sum += c;
        }
        return sum;
    }

    int big_O_3(int arg)
    {
        int i = 0;
        while (i < 100)
        {
            ++i;
        };
        return i;
    }

    int big_O_4(int arg)
    {
        int count = 0;
        while (arg > 1)
        {
            arg = arg / 2;
            count++;
        }
        return count;
    }

    int big_O_5(int arg)
    {
        int count = 0;
        for (int i = 0; i < 327; ++i)
        {
            for (int j = 0; j < arg; ++j)
            {
                count++;
            }
        }
        return count;
    }

    /**
     * Pretend that this function performs a
     * binary search on an array of 'arg' elements
     */
    void binary_search(int arg)
    {
        return;
    }

    /**
     * Pretend that this function performs a
     * merge sort on an array of 'arg' elements
     */
    void merge_sort(int arg)
    {
        return;
    }

    /**
     * Pretend that this function performs a
     * quick sort on an array of 'arg' elements
     */
    void quick_sort(int arg)
    {
        return;
    }

    /**
     * Pretend that this function performs a
     * bubble sort on an array of 'arg' elements
     */
    void bubble_sort(int arg)
    {
        return;
    }

    int recursive_factorial(int arg)
    {
        if (arg == 0)
        {
            return 1;
        }
        return arg * recursive_factorial(arg - 1);
    }

    int recursive_fibonnaci(int nth_element)
    {

        if (nth_element == 0 or nth_element == 1)
        {
            return nth_element;
        }

        return recursive_fibonnaci(nth_element - 1) + recursive_fibonnaci(nth_element - 2);
    }

    /**
     * QUESTIONS:
     * 1. Why do we need this function?
     * 2. What does each line do, and why?
     * 3. When does this function get called?
     * ANSWERS:
     * 1. Since we could use heap memory, we have to de-allocate
     *    the space to prevent a memory leak.
     * 2. The 'delete' line "gets rid of" the data that
     *    'pointer_to_variable' points to. After that line
     *    finishes, the 'pointer_to_variable' pointer still
     *    points to that location, even if we aren't using the
     *    space, so we set it to 'nullptr'.
     * 3. When we use 'delete' or if a variable's lifetime expires.
     *    For example, if a local variable is declared in a function,
     *    the destructor is automatically called at the end of the
     *    function.
     */
    ~Sample()
    {
        delete pointer_to_variable;
        pointer_to_variable = nullptr;
        // We don't NEED this line as the pointer is
        // going away forever, but I always set unused pointers
        // to 'nullptr' 100% of the time as a habit.
    }

    friend std::ostream& operator<<(std::ostream &out, Sample const &s)
    {
        out << "variable            : " << s.variable << std::endl;
        out << "pointer_to_variable : ";

            if (s.pointer_to_variable == nullptr)
        {
            out << "nullptr" << std::endl;
            return out;
        }

        out << s.pointer_to_variable << std::endl;

        out << "*pointer_to_variable : ";
        out << *(s.pointer_to_variable) << std::endl;

        return out;
    }
};
