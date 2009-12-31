    #include <algorithm>
    #include <iostream>
    #include <functional>
    #include <iterator>

    void show(int *ia, char const *header)
    {
        std::cout << header << ":\n";
        std::copy(ia, ia + 20, std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }

    using namespace std;

    int main()
    {
        int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                    11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

        make_heap(ia, ia + 20);
        show(ia, "The values 1-20 in a max-heap");

        pop_heap(ia, ia + 20);
        show(ia, "Removing the first element (now at the end)");

        push_heap(ia, ia + 20);
        show(ia, "Adding 20 (at the end) to the heap again");

        sort_heap(ia, ia + 20);
        show(ia, "Sorting the elements in the heap");


        make_heap(ia, ia + 20, greater<int>());
        show(ia, "The values 1-20 in a heap, using > (and beyond too)");

        pop_heap(ia, ia + 20, greater<int>());
        show(ia, "Removing the first element (now at the end)");

        push_heap(ia, ia + 20, greater<int>());
        show(ia, "Re-adding the removed element");

        sort_heap(ia, ia + 20, greater<int>());
        show(ia, "Sorting the elements in the heap");

        return 0;
    }
    /*
        Displays:

        The values 1-20 in a max-heap:
        20 19 15 18 11 13 14 17 9 10 2 12 6 3 7 16 8 4 1 5
        Removing the first element (now at the end):
        19 18 15 17 11 13 14 16 9 10 2 12 6 3 7 5 8 4 1 20
        Adding 20 (at the end) to the heap again:
        20 19 15 17 18 13 14 16 9 11 2 12 6 3 7 5 8 4 1 10
        Sorting the elements in the heap:
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
        The values 1-20 in a heap, using > (and beyond too):
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
        Removing the first element (now at the end):
        2 4 3 8 5 6 7 16 9 10 11 12 13 14 15 20 17 18 19 1
        Re-adding the removed element:
        1 2 3 8 4 6 7 16 9 5 11 12 13 14 15 20 17 18 19 10
        Sorting the elements in the heap:
        20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
    */
